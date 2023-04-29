int posOfRightMostDiffBit(int m, int n)
    {
          if (m==n)
            return -1;
        
          int x = m^n;
          int count = 0;
          while (x>0) {
              count+=1;
              if (x & 1 == 1)
                return count;
              x = x>>1;
          }
        
    }



/*
int posOfRightMostDiffBit(int m, int n)
    {
          if (m==n)
            return -1;
        return ffs(m^n);
    }
};


*/