int setBit(int N)
    {
        // Write Your Code here
        int a = N;
        int k = 0;
        while(N>0) {
            if (N%2 == 0) {
                 a = a | (1<<k);
                 break;
            }
            k++;
            N = N/2;
        }
        return a;
    }