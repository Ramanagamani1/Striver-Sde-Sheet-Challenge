bool isValidParenthesis(string x)
{
    stack<int> s;
         
         for(int i=0;i<x.size();i++) {
             
             if(x[i]=='{' || x[i]=='[' || x[i]=='('){
                 s.push(x[i]);
             } else {
                 
                 if(s.empty()){
                     return false;
                 }
                 
                 char ch = s.top(); 
                 s.pop();
                 
                 if(x[i]=='}' && ch!='{'){
                   
                     return false;
                     
                 } else if(x[i]==')' && ch!='(') {
            
                     return false;
                     
                 } else if(x[i]==']' && ch!='['){
                     
                     return false;
                 }
             }
         }
         if(s.empty())
           return true;
         
         else
           return false;
}