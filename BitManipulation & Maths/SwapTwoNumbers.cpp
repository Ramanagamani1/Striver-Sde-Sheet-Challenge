  pair<int, int> get(int a, int b){
        //complete the function here
        a = a+b;
        b = a-b;
        a = a-b;
        return {a,b};
        
        /* 
           int x = 10, y = 5;
    // Code to swap 'x' (1010) and 'y' (0101)
    x = x ^ y; // x now becomes 15 (1111)
    y = x ^ y; // y becomes 10 (1010)
    x = x ^ y; // x becomes 5 (0101)
        
        */
        
    }
