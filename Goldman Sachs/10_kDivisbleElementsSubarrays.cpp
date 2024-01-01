class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;

        int n = nums.size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            vector<int> temp;
            int totalDiv = 0;
            for (int j=i; j<n; j++) {
                if (nums[j]%p == 0) totalDiv++;
                temp.push_back(nums[j]);
                if (totalDiv <= k) {
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};

//isme mai first subarrays dekh ke 2 pointer approach laga rha tha --> but some test cases are failed
//so jb iski constraints dekhi to array ki size bhot kam thi --> i went to do it through brute force approach O(n^2).
