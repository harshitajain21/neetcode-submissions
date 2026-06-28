class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        int n = s.size();

        if(n%2!=0){
            return false;
        }
        else{
            //[()]{}

            for(auto c:s){
                if(c=='[' or c=='(' or c=='{'){
                  st.push(c);  
                }
                else{
                    if(st.empty()){
                        return false;}
                    if(c == ')' && st.top() != '(') {
                        return false;}
                    if(c == '}' && st.top() != '{') {
                        return false;}
                    if(c == ']' && st.top() != '[') {
                        return false;}
                    st.pop();}
               }
            return st.empty();}
}};