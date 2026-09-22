class Solution {
public:
    struct Node{
        int prod;
        long long cnt[5][5];
        Node(){
            prod = 1;
            for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                    cnt[i][j] = 0;
                }
            }
        }
    };
    int n, K;
    vector<int> nums;
    vector<Node> seg;
    Node merge(Node &left, Node &right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;
        for(int startRem = 0; startRem < K; startRem++) {
            int midRem = (startRem * left.prod) % K;
            for(int x = 0; x < K; x++) {
                res.cnt[startRem][x] += left.cnt[startRem][x];
                res.cnt[startRem][x] += right.cnt[midRem][x];
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int p = nums[l] % K;
            seg[node].prod = p;
            for (int rem = 0; rem < K; rem++) {
                int newRem = (rem * p) % K;
                seg[node].cnt[rem][newRem] = 1;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            seg[node] = Node();
            int p = value % K;
            seg[node].prod = p;
            for (int rem = 0; rem < K; rem++) {
                int newRem = (rem * p) % K;
                seg[node].cnt[rem][newRem] = 1;
            }
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) {
            update(2 * node, l, mid, idx, value);
        }
        else{
            update(2 * node + 1, mid + 1, r, idx, value);
        }
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[node];
        }
        int mid = (l + r) / 2;
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        }
        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        }
        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    vector<int> resultArray(vector<int>& numsInput,int k,vector<vector<int>>& queries) {
        nums = numsInput;
        K = k;
        n = nums.size();
        seg.resize(4 * n + 5);
        build(1, 0, n - 1);
        vector<int> ans;
        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            nums[index] = value;
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[1%K][x]);
        }
        return ans;
    }
};