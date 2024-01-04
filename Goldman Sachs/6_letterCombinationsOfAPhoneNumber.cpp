class Solution {
public:
    vector<string> ans;
    void solve(int idx, string& digits, vector<string>& letter, string& temp) {
        if (idx == digits.length()) {
            ans.push_back(temp);
            return;
        }

        char phone_number = digits[idx];
        string words = letter[phone_number-'0'];

        for (int i=0; i<words.length(); i++){
            temp.push_back(words[i]);
            solve(idx+1,digits,letter,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) return {};
        vector<string> letter({"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
        string temp = "";
        solve(0,digits,letter,temp);
        return ans;
    }
};
