#include<bits/stdc++.h>
double median(vector<int> nums1, vector<int> nums2)
{
    // Write your code here.
        if(nums2.size()<nums1.size()) {
            return median(nums2,nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0, high = n1;

        while(low<=high) {

            int cut1 = low+(high-low)/2;

            int cut2 = (n1+n2+1)/2 - cut1;

            int max1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int max2 = cut2==0 ? INT_MIN : nums2[cut2-1];

            int min1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int min2 = cut2==n2 ? INT_MAX : nums2[cut2];

            if(max1<=min2 && max2<=min1) {

                if((n1+n2)%2 == 0) {

                    return ((double)max(max1, max2) + min(min1, min2)) / 2;
                } 
                else {

                    return (double)(max(max1,max2));
                }
            } else if(max1 > min2) {

                high = cut1-1;
            } else {

                low = cut1+1;
            }
        }
        return 0.0;
}
