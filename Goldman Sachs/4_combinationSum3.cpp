class Solution {
public:
    void findComb(int idx, int k, int target, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            if (k == 0) {
                ans.push_back(ds);
            }
            return;
        }

        for (int j = idx; j<=9; j++) {
            if (j > target) {
                break;
            }
            ds.push_back(j);
            findComb(j+1,k-1,target-j,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        findComb(1,k,n,ans,ds);
        return ans;
    }
};
