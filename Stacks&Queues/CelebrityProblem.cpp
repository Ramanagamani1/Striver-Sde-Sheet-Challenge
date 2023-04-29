//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool knows(int a,int b,vector<vector<int> >& M) {
        return M[a][b];
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        for(int i=0;i<n;i++) {
            s.push(i);
        }
        
        while(s.size() > 1) {
            
            int A = s.top();
            s.pop();
            
            int B = s.top();
            s.pop();
            
            if(knows(A,B,M)) {
                s.push(B);
            }
            else {
                s.push(A);
            }
        }
        
        int C = s.top();
        s.pop();
        
        for(int i=0;i<n;i++) {
            
            if(i!=C && (knows(C,i,M) || !knows(i,C,M)) )
               return -1;
        }
        
        return C;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends