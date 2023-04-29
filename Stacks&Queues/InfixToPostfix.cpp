//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char x) {
        
        if(x=='^')
          return 3;
        else if(x=='*' || x=='/')
           return 2;
        else if(x=='+' || x=='-')
          return 1;
        else
          return -1;
    }
    bool isOperand(char c) {
        
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')) {
            return true;
        }
        
        return false;
    }
    
    string infixToPostfix(string s) {
        stack<char> st;
        
        string res="";
        
        for(int i=0;i<s.size();i++) {
            
            if(isOperand(s[i])) {
                res = res+s[i];
            }
            else if(s[i]=='(') {
                st.push(s[i]);
            }
            else if(s[i]==')') {
                
                while(st.top()!='(') {
                    res = res+st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                    
                    while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                        
                        res = res+st.top();
                        st.pop();
                    }
                
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            
            res=res+st.top();
            st.pop();
        }
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends