// Method :
// we keep a stack of numbers
// whenever we come across a operator then we pop the top 2 numbers
// and apply the operator
// 

class Solution {
public:
    
    bool isOperator(string &s){
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    
    int eval(int a, int b, string &op){
        if(op=="+")return a+b;
        else if(op=="-")return a-b;
        else if(op=="*")return a*b;
        else if(op=="/")return a/b;
        else return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
 
        for(int i=0; i<tokens.size(); i++){
            if(!isOperator(tokens[i])){
                st.push(stoi(tokens[i]));
            }
            else {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                
                st.push( eval(n2, n1, tokens[i]) );
            }
        }
        
        return st.top();
    }
};
