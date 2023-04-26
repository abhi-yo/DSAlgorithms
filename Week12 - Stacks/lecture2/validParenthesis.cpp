// Leetcode question number 20.
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            //opening bracket
            if(ch=='('||ch=='{'||ch=='['){
                st.push(ch);
            }else{
                //closing bracket
                if(!st.empty()){
                    char topCh=st.top();
                    if(ch==')'&&topCh=='('){
                        st.pop(); // matching brackets
                    }else if(ch=='}'&&topCh=='{'){
                        st.pop();
                    }else if(ch==']'&&topCh=='['){
                        st.pop();
                    } else {
                        return false; // not matching
                    }
                }else{
                    return false; // not matching
                }
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};