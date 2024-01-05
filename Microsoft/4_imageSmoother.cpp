class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for (int l = 0; l < n; l++) {
            for (int k = 0; k < m; k++) {
                int sum = 0, count = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int nx = l + i;
                        int ny = k + j;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        sum += img[nx][ny];
                        count++;
                    }
                }
                ans[l][k] = floor(sum / count);
            }
        }
        return ans;
    }

};
