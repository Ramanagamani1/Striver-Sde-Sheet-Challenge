int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	     int i=0,j=M-1;
	     
	     while(i<N && M>=0) {
	         if(mat[i][j]==X)
	           return 1;
	         else if(mat[i][j]>X)
	             j-=1;
	         else
	           i+=1;
	     }
	     return 0;
	}