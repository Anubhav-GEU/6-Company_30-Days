class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans = "";
        stack<int> st;
        int num = 1;
        
        for (int i=0; i<S.length(); i++) {
            if (S[i] == 'D') {
                st.push(num);
            }
            else {
                st.push(num);
                
                while (!st.empty()) {
                    ans += to_string(st.top());
                    
                    st.pop();
                }
            }
            num++;
        }
        st.push(num);
        
        while (!st.empty()) {
            ans+=to_string(st.top());
            st.pop();
        }
        
        return ans;
    }
};
