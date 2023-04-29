class Solution {
public:
    int orangesRotting(vector<vector<int>>& A) {
    queue<pair<int,int>> q;
    int time=0;
    int orange=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==1){
                orange+=1;
            }
            if(A[i][j]==2){
                q.push({i,j});
            }
        }
    }
    int n=A.size();
    int m=A[0].size();
    vector<int> rows={0,1,-1,0};
    vector<int> cols={1,0,0,-1};
    while(orange!=0 && !q.empty()) {
        int size=q.size();
        for(int i=0;i<size;i++){
              int x=q.front().first;
              int y=q.front().second;
              q.pop();
              for(int i=0;i<4;i++){
                   int rowx=x+rows[i];
                   int coly=y+cols[i];
                   if(rowx>=0 && coly>=0 && rowx<n && coly<m && A[rowx][coly]==1){
                         A[rowx][coly]=2;
                         orange-=1;
                         q.push({rowx,coly});
                   }
              }
        }
        time=time+1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(A[i][j]==1)
              return -1;
        }
    }
    return time;
    }
};