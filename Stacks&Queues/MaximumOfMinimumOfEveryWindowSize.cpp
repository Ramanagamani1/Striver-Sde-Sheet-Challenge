//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n+1,0);
        
        vector<int> left(n+1,-1);
        vector<int> right(n+1,n);
        
        stack<int> s;
        
        //previous smaller element
        
        for(int i=0;i<n;i++) {
            
            while(!s.empty() && arr[s.top()]>=arr[i]) {
                s.pop();
            }
            
            if(!s.empty()) {
                left[i] = s.top();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
          s.pop();
          
        //next smaller element
        
        for(int i=n-1;i>=0;i--) {
            
            while(!s.empty() && arr[s.top()]>=arr[i]) {
                s.pop();
            }
            
            if(!s.empty()) {
                right[i] = s.top();
            }
            
            s.push(i);
        }
        
        for(int i=0;i<n;i++) {
            int window = right[i]-left[i]-1;
            ans[window] = max(ans[window],arr[i]);
        }
        
        for(int i=n-1;i>=1;i--) {
            ans[i] = max(ans[i],ans[i+1]);
        }
        
        vector<int> res(n,0);
        
        for(int i=1;i<=n;i++) {
            res[i-1] = ans[i];
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends