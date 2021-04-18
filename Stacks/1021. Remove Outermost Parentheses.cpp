class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char> st;
        string ans = "";
        
        for(char c:s){
            
            if(st.empty()){
                st.push(c);
            }
            else {

                if(st.top() == '(' && c == ')'){
                    st.pop();
                }
                else {
                    st.push(c);
                }
                
                if(!st.empty()){
                    ans+=c;
                }
            }
        }
        return ans;
    }
};
