class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> freq(n+1,0);
        
        for (int i=0; i<n; i++) {
            freq[arr[i]]++;
        }
        int missing = 0;
        int repeating = 0;
        for (int i=1; i<=n; i++) {
            if (freq[i] == 0) missing = i;
            if (freq[i] > 1) repeating = i;
        }
        return {repeating,missing};
    }
};
