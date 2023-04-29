#include <bits/stdc++.h> 
struct Job 
{ 
     // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool comparator(Job a, Job b) {
        return a.profit > b.profit;
}
int jobScheduling(vector<vector<int>> &jobs)
{
        int n = jobs.size();
        struct Job arr[n];
        for(int i=0;i<n;i++) {
            arr[i].dead = jobs[i][0];
            arr[i].profit = jobs[i][1];
        }
        sort(arr,arr+n,comparator);
        int maxi = 0;
        for(int i=0;i<n;i++){ 
          maxi = max(maxi,arr[i].dead);   
        }
        vector<int> slot(maxi+1,-1);
        int countjobs=0, profit = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=arr[i].dead;j>0;j--) {
                if(slot[j]==-1){
                    slot[j] = i;
                    countjobs+=1;
                    profit +=arr[i].profit;
                    break;
                }
            }
        }
        return profit;
}
