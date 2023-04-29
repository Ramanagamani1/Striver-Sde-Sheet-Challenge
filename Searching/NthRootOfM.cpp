#include <bits/stdc++.h> 
double multiply(double n,int m) {

	double ans = 1;
	for(int i=0;i<m;i++){
		ans = ans*n;
	}
	return ans;
}
double findNthRootOfM(int n, int m) {
	
	double low = 0, high = m;
	double eps = 1e-7;

	while((high-low)>eps) {

		double mid = (low+high)/2.0;

		double ans = multiply(mid,n);

		if(ans < m) {
			low = mid;
		} else {
			high = mid;
		}
	}
	return low;
}