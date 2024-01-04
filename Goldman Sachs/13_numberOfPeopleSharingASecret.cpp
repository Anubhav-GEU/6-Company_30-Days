class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        long long numberOfPeopleSharingSecret = 0;
        dp[1] = 1;
        for (int i=2; i<=n; i++) {
            long long newPeopleSharingSecret = dp[max(0,i-delay)];
            long long peopleWhoForgot = dp[max(0,i-forget)];

            numberOfPeopleSharingSecret = numberOfPeopleSharingSecret+newPeopleSharingSecret-peopleWhoForgot;
            dp[i] = numberOfPeopleSharingSecret%mod;
        }
        int ans = 0;

        for (int i=n-forget+1; i<=n; i++) {
            ans = (ans+dp[i])%mod;
        }
        return ans%mod;
    }
};
