class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string window = "";
        int n = s.length();
        if (n < 10) return {};

        for (int i=0; i<10; i++) {
            window += s[i];
        }
        vector<string> ans;
        unordered_map<string,int> mp;
        mp[window]++;

        for (int i=10; i<n; i++) {
            window = window.substr(1);
            window += s[i];
            mp[window]++;
        }
        for (auto& i:mp) {
            if (i.second>1) ans.push_back(i.first);
        }
        return ans;
        // return {""};
    }
};
