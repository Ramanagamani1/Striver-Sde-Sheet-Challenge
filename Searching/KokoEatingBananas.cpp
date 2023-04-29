//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int>& piles,int N,int speed, int H) {
        
        int time = 0;
        
        for(int i=0;i<N;i++) {
            
            if(piles[i]%speed == 0) {
                
                time += piles[i]/speed;
            } else {
                
                time += piles[i]/speed + 1;
            }
        }
        if (time<=H) {
            return true;
        }
        return false;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        
        int res = 1;
        
        while(low<=high) {
            
            int mid = low+ (high-low)/2;
            
            if(isPossible(piles,N,mid,H)) {
                
                res = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends