 #include<bits/stdc++.h>
 

 int largestRectangle(vector < int > & heights) {
     stack<int> s;
     int maxArea = 0;
     int n = heights.size();
     vector<int> leftsmaller(n,0), rightsmaller(n,0);

     for(int i=0;i<n;i++) {

          while(!s.empty() && heights[s.top()]>=heights[i]) {
              s.pop();
          }

          int pse = s.empty() ? 0 : s.top()+1;
          leftsmaller[i]=pse;

          s.push(i);
     }

     while(!s.empty())
        s.pop();

     for(int i=n-1;i>=0;i--) {

         while(!s.empty() &&  heights[s.top()]>=heights[i]) {
              s.pop();
          }

          int nse = s.empty() ? n-1: s.top()-1;
          rightsmaller[i] = nse;
          s.push(i);
     }

     for(int i=0;i<n;i++) {
         maxArea = max(maxArea, heights[i]*(rightsmaller[i]-leftsmaller[i]+1));
     }

     return maxArea;
 }
