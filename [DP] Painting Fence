/*
 Recursive relation : p(n) = (k-1)*(p(n-1) + (k-1)*(p(n-2) ;
*/

#include <bits/stdc++.h> 
#define MOD 1000000007

// int solveRec(int n , int k){

//     if(n == 1) return k;
//     if(n == 2) return k*k;
    
//     int res = ((k-1)*(solveRec(n-1,k) + solveRec(n-2,k))) % MOD;
               
//     return res;
// }

int addHelper(int a , int b){
    return (a % MOD + b % MOD) % MOD;
}

int mulHelper(int a , int b){
    return ((a % MOD) * 1LL * (b % MOD) ) % MOD;
}

// int solveMem(int n , int k ,vector<int> &dp){
//     if(n==1) return k;
//     if(n==2) return mulHelper(k ,k) ;
//     if(dp[n] != -1) return dp[n];
    
//     dp[n] = addHelper(mulHelper(k-1,solveMem(n-1,k,dp)) , mulHelper(k-1,solveMem(n-2,k,dp)));
    
//     return dp[n];
// }

// int solveTab(int n , int k ,vector<int> &dp){
//     dp[1] = k;
//     dp[2] = mulHelper(k , k) ;
    
//     for(int i = 3 ; i<= n; i++){
//         dp[i] =addHelper( mulHelper(k-1,dp[i-1]) , mulHelper(k-1,dp[i-2]) );
//     }
    
//     return dp[n];
// }

int solveOp(int n , int k ){
    int prev2 = k;
    int prev1 = mulHelper(k , k) ;
    
    for(int i = 3 ; i<= n; i++){
        int curr  = addHelper( mulHelper(k-1,prev1) , mulHelper(k-1,prev2) );
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int numberOfWays(int n, int k) {
   
     //Recursive approach
//     int ans = solveRec(n,k);
    
    // Recursive + Memoization (Top-down approach)
//     vector<int> dp(n+1,-1);
//     int ans = solveMem(n,k,dp);

    // Tabulation ( Bottom-Up approach)
//     vector<int> dp(n+1,-1);
//     int ans = solveTab(n,k,dp);
    
    //Space Optimization O(1) space
    int ans = solveOp(n,k);
    
    
    return ans;
    
}
