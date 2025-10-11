class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n==1){
            return 1;
        }
        
        //n-1 discs from to aux (using to as helper)
        int moves1=towerOfHanoi(n-1,from,aux,to); 
        
        //largest disc move from to to
        int moves2=1;
        
        //remaining discs
        int moves3=towerOfHanoi(n-1,aux,to,from);
        return moves1+moves2+moves3;
    }
};