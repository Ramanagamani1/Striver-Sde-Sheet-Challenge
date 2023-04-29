void helper(int open,int close,int n, string &temp,vector<string> &ans) {
        if(open==0 && close==0) {
            ans.push_back(temp);
            return;
        }
        if(open!=0) {
            string op1= temp;
            op1.push_back('(');
            helper(open-1,close,n,op1,ans);
        }
        
        if(close>open) {
            string op2 = temp;
            op2.push_back(')');
            helper(open,close-1,n,op2,ans);
        }
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string temp="";
        int close = n;
        int open = n;
        helper(open,close,n,temp,ans);
        return ans;
    }