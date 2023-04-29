 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
       
       stack<int> s;
       int maxArea = 0;

       int n = heights.size();

       for(int i=0;i<=n;i++) {

          while(!s.empty() && (i==n || heights[s.top()]>=heights[i])) {

               int height = heights[s.top()];
               s.pop();
               int width;

               if(s.empty())
                 width = i;
               else {
                  width = i-s.top()-1;
               }

               maxArea = max(maxArea, height*width);
          }

          s.push(i);
       }

       return maxArea;
 }