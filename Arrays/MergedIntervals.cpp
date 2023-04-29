/*
Problem Statement
You are given N number of intervals, where each interval contains two integers denoting the start time and the end time for the interval.
The task is to merge all the overlapping intervals and return the list of merged intervals sorted by increasing order of their start time.
Two intervals [A,B] and [C,D] are said to be overlapping with each other if there is at least one integer that is covered by both of them.
For example:
For the given 5 intervals - [1, 4], [3, 5], [6, 8], [10, 12], [8, 9].

Since intervals [1, 4] and [3, 5] overlap with each other, we will merge them into a single interval as [1, 5].

Similarly, [6, 8] and [8, 9] overlap, merge them into [6,9].

Interval [10, 12] does not overlap with any interval.

Final List after merging overlapping intervals: [1, 5], [6, 9], [10, 12].
Input Format:
The first line of input contains an integer N, the number of intervals.

The second line of input contains N integers, i.e. all the start times of the N intervals.

The third line of input contains N integers, i.e. all the end times of the N intervals.
Output Format:
Print S lines, each contains two single space-separated integers A, and B, where S is the size of the merged array of intervals, 'A' is the start time of an interval and 'B' is the end time of the same interval.
Note
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= N <= 10^5 
0 <= START, FINISH <= 10^9

Time Limit: 1sec
Sample Input 1:
2
1 3
3 5
Sample Output 1:
1 5  
Explanation For Sample Input 1
Since these two intervals overlap at point 3 so we merge them and the new interval becomes (1,5).
Sample Input 2:
5
1 3 6 8 10
4 5 8 9 12
Sample Output 2:
1 5
6 9
10 12 */

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> arr;
    int j=1;
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    
    if(n==1){
        return intervals;
    }
    pair<int,int> temp = {intervals[0][0],intervals[0][1]};
    while(j<n) {
        while(j<n && temp.second>=intervals[j][0]){
               temp.second = max(intervals[j][1],temp.second);
               j+=1;
        }
        arr.push_back({temp.first,temp.second});
        if(j<n) {
            temp.first= intervals[j][0];
            temp.second = intervals[j][1];
        }
        j+=1;
    }
    if(temp.second!=arr[arr.size()-1][1]){
         arr.push_back({temp.first,temp.second});
    }
    return arr;
}


/*
 #include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>> ans;
	int n = arr.size();

	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++) {

		if(ans.empty() || ans.back()[1] < arr[i][0]) {
			ans.push_back(arr[i]);
		}
		else {
			ans.back()[1] = max(ans.back()[1],arr[i][1]);
		}
	}

	return ans;
}
*/