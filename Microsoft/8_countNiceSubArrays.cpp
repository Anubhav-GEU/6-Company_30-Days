class Solution {
public:
    int helper(vector<int>& nums, int k){
        int left = 0;
        int count = 0;

        int oddC = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            oddC += (nums[i]%2 != 0) ? 1:0;

            while (oddC > k && left <= i){
                oddC -= (nums[left] %2 != 0) ? 1:0;
                left++; 
            }   

            count+=i-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};
