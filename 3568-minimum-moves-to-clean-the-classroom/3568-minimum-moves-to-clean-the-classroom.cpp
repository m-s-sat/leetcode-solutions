class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(), m = classroom[0].size();
        int sr = -1, sc = -1, k = 0;
        vector<vector<int>> id(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') sr = i, sc = j;
                else if (classroom[i][j] == 'L') id[i][j] = k++;
            }

        int full = (1 << k) - 1;
        if (full == 0) return 0;

        vector<vector<vector<int>>> best(n,vector<vector<int>>(m, vector<int>(1 << k, -1)));
        best[sr][sc][0] = energy;
        queue<array<int,4>> q;       
        q.push({sr, sc, 0, energy});
        int dr[4] = {-1,0,1,0}, dc[4] = {0,1,0,-1};
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                if (e==0) continue;          
                for (int d=0;d<4;d++) {
                    int nr = r+dr[d], nc=c+dc[d];
                    if (nr<0 || nc<0 || nr>=n || nc>=m) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    int ne = e - 1, nmask = mask;
                    if (classroom[nr][nc] == 'R') ne = energy;
                    else if (classroom[nr][nc] == 'L') nmask |= (1 << id[nr][nc]);
                    if (nmask == full) return steps;
                    if (ne <= best[nr][nc][nmask]) continue;
                    best[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }
        }
        return -1;
    }
};