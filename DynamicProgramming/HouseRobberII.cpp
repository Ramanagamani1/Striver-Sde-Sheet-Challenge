long long int maxNonAdjacentSum(vector<long long int> &nums) {
	long long int n= nums.size();
	long long int prev = nums[0];
	long long int prev2 =0;
	for(long long int i=1;i<n;i++) {
		  long long int take = nums[i];
		  if (i>1)
			  take += prev2;
		   long long int nottake =  prev;
		 long long int curi = max(take,nottake);
		prev2=prev;
		prev=curi;
	}
	return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
	long long int n=valueInHouse.size();
	if (n==1)
		return valueInHouse[0];
	vector<long long int> temp2,temp1;
	for(long long int i=0;i<n;i++) {
		if (i!=0) temp1.push_back(valueInHouse[i]);
		if (i!=n-1) temp2.push_back(valueInHouse[i]);
	}
	long long int ans1 = maxNonAdjacentSum(temp1);
	long long int ans2 = maxNonAdjacentSum(temp2);
	return max(ans1,ans2);
}