/* Problem Statement
You have been given two integers ‘N’ and ‘K’. Your task is to find the K-th permutation sequence of numbers from 1 to ‘N’. The K-th permutation is the K-th permutation in the set of all sorted permutations of string 1 to ‘N’.
For Example :
If ‘N’ = 3 and ‘K’ = 4. Then all permutations for ‘N’ = 3 are “123”, “132”, “213”, “231”, “312”, “321”. So the 4-th permutation is “231”.
Input Format:
The first line of input contains an integer ‘T’ which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two single space-separated integers ‘N’ and ‘K’, respectively.
Output Format:
The only line of output contains a string of K-th permutation sequence of numbers from 1 to ‘N’.

Print the output of each test case in a separate line.
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 <= ‘T’ <= 100
1 <= ‘N’ <= 9
1 <= ‘K’ <= N!

Time Limit: 1 sec 
Sample Input 1:
2
2 1
3 6
Sample Output 1:
12
321 */

string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> nums;
    int fact=1;
    for(int i=1;i<n;i++){
        fact=fact*i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k=k-1;
    string ans="";
    while(true){
        ans=ans+to_string(nums[k/fact]);
        nums.erase(nums.begin()+k/fact);
        if(nums.size()==0)
            break;
        k=k%fact;
        fact=fact/nums.size();
    }
    return ans;
}
