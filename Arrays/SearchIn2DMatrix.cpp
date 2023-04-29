// row and col both are sorted

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
	

// row sorted
int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (n*m)-1;
        int mid,i,j;

        while(low<=high) {
            mid = (low+high)/2;

            i = mid/m;
            j = mid%m;

            if(matrix[i][j]>target) {
                 high = mid-1;
            } else if(matrix[i][j]<target) {
                low = mid+1;
            } else {
                return true;
            }


        }
        return false;
