class Solution {
public:
    bool isPresent(vector<string>& times) {
        sort(times.begin(),times.end());
        for (int i=2; i<times.size(); i++) {
            int prevPrev = stoi(times[i-2]);
            int curr = stoi(times[i]);
            if (prevPrev+99 >= curr) {
                return true;
            } 
        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(),access_times.end());
        int counter = 1;
        vector<string> ans;
        int n = access_times.size();
        // need to store the oldest time
        unordered_map<string,vector<string>> mp;
        for (int i=0; i<n; i++) {
            mp[access_times[i][0]].push_back(access_times[i][1]);
        }

        for (auto& i : mp) {
            if (i.second.size() < 3) continue;
            if (isPresent(i.second)) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
