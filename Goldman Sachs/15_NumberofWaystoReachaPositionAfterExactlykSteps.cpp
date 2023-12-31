class Solution {
public:
    int mod = 1e9+7;
    int dp[3005][1001];
    int findWays(int start, int end, int k) {
        if (k == 0 ) {
            if (start == end)
                return 1;
            else 
                return 0;
        }
        if (dp[start+1000][k] != -1) return dp[start+1000][k]; 
        int left = findWays(start-1,end,k-1);
        int right = findWays(start+1,end,k-1);

        return dp[start+1000][k] = (left+right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return findWays(startPos,endPos,k);
    }
};
