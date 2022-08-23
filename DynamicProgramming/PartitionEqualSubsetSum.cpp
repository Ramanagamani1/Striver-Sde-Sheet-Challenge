bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        if(arr[0]<=k)
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                bool notTaken = dp[ind-1][target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];
            
                dp[ind][target]= notTaken||taken;
            }
        }
        
        return dp[n-1][k];

    } 
}


/* Memoization

bool f(int ind,int k,vector<int> &arr,vector<vector<int>> &dp){
	if(k==0)
		return 1;
	if(ind==0)
		return (arr[0]==k);
	if(dp[ind][k]!=-1)
		return dp[ind][k];
	bool pick=false;
	if(arr[ind]<=k)
	pick=f(ind-1,k-arr[ind],arr,dp);
	bool notpick=f(ind-1,k,arr,dp);
	return dp[ind][k]=pick | notpick;
	
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	if(sum%2!=0)
		return false;
	sum=sum/2;
	vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	return f(n-1,sum,arr,dp);
}

*/

/*
bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        int k=sum/2;
         vector<vector<bool>> dp(n,vector<bool>(k+1,0));
         vector<bool> prev(k+1,false);
         vector<bool> cur(k+1,false);
         prev[0]=true, cur[0]=true;
         if(nums[0]<=k) prev[nums[0]] = true;
         for(int i=1;i<n;i++){
             for(int target=1;target<=k;target++){
                 bool nottake=prev[target];
                 bool take=false;
                 if(nums[i]<=target)
                     take=prev[target-nums[i]];
                 cur[target]=take|nottake;
             }
             prev=cur;
         }
         return prev[k]; 
    }
*/
