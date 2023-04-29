//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int> &stations, int n,int K, double dis) {
        
        int sum = 0;
        for(int i=1;i<n;i++) {
            
            int diff = (stations[i]-stations[i-1]);
            double v = (double) (diff/dis);
            sum += (int)v;
        }
        return sum<=K;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
      
         int n=stations.size();
         
         double low = 0, high = stations[n-1]-stations[0];
         
         double res = -1;
         
         while((high-low)>=1e-6) {
             
             double mid = low + (high-low)/2.0;
             
             if(isPossible(stations,n,K,mid)) {
                   res = mid;
                   high = mid;
                   
             } else {
                 
                 low = mid;
             }
         }
         return res;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends