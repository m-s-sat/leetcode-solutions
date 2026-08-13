class Solution {
public:
    struct Node {
        int len, pref, suf, best;
        char leftCh, rightCh;
    };

    vector<Node> tree;
    string str;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.len = L.len + R.len;
        res.leftCh = L.leftCh;
        res.rightCh = R.rightCh;
        res.pref = L.pref;
        res.suf = R.suf;
        res.best = max(L.best, R.best);
        if (L.rightCh == R.leftCh) {
            if (L.pref == L.len) res.pref = L.len + R.pref;
            if (R.suf == R.len) res.suf = R.len + L.suf;
            res.best = max(res.best, L.suf + R.pref);
        }
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, str[l], str[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, ch, ch};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, ch);
        else update(2*node+1, mid+1, r, idx, ch);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
        vector<int> ans;
        int q = queryCharacters.size();
        ans.reserve(q);
        for (int i = 0; i < q; i++) {
            str[queryIndices[i]] = queryCharacters[i];
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};