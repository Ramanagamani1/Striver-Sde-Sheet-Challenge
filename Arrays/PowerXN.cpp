#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    
    if (n==0)
        return 1;
    long long int temp = modularExponentiation(x,n/2,m)%m;
    temp = ((temp%m) * (temp%m))%m;
    if (n%2==0) {
        return temp%m;
    } else
        return (temp%m * x%m)%m;
}