class Solution {
public:

    // int solveRec(int curr , int e , vector<int>& slices , int limit){
    //     if(curr > e || limit == 0) return 0;

    //     int inc = slices[curr] + solveRec(curr+2,e,slices,limit-1);
    //     int exc = 0 + solveRec(curr+1,e,slices,limit);

    //     return max(inc,exc);
    // }

    // int solveMem(int curr , int e , vector<int>& slices , int limit,vector<vector<int>> &dp){
    //     if( limit == 0 || curr > e) return 0;
    //     if(dp[curr][limit] != -1) return dp[curr][limit];

    //     int inc = slices[curr] + solveMem(curr+2,e,slices,limit-1,dp);
    //     int exc = 0 + solveMem(curr+1,e,slices,limit,dp);

    //     return dp[curr][limit] = max(inc,exc);
    // }

    // int solveTab( int start , int end, vector<int>& slices){

    //     int k = slices.size();
    //     vector<vector<int>> dp(k+2,vector<int>(k,0));
        
    //     for(int i = end ; i >= start ; i--){
    //         for(int j = 1 ; j <= k/3 ; j++){
    //             int inc = slices[i] + dp[i+2][j-1];
    //             int exc = 0 +  dp[i+1][j];

    //             dp[i][j] = max(inc,exc);
    //         }
    //     }

    //     return dp[start][k/3];
    // }

    int solveSO( int start , int end, vector<int>& slices){

       int k = slices.size();
       vector<int> curr(k,0);
       vector<int> next1(k,0);
       vector<int> next2(k,0);
        
        for(int i = end ; i >= start ; i--){
            for(int j = 1 ; j <= k/3 ; j++){
                int inc = slices[i] + next2[j-1];
                int exc = 0 +  next1[j];

                curr[j] = max(inc,exc);
            }
            next2 = next1;
            next1 = curr;

        }

        return next1[k/3];
    }

    int maxSizeSlices(vector<int>& slices) {

        //Recursive approach
        // int k = slices.size();
        // int res1 = solveRec(0,k-2,slices,k/3);
        // int res2 = solveRec(1,k-1,slices,k/3);

        // Recursion + Memoization (top-down approach)
        // int k = slices.size();
        // vector<vector<int>> dp1(k,vector<int>(k,-1));
        // vector<vector<int>> dp2(k,vector<int>(k,-1));
        // int res1 = solveMem(0,k-2,slices,k/3,dp1);
        // int res2 = solveMem(1,k-1,slices,k/3,dp2);

        //Tabulation (Bottom-up)
        //  int size = slices.size();
        //  int res1 = solveTab(0,size-2,slices);
        //  int res2 = solveTab(1,size-1,slices);

         //Space Optimization (O(3*N) space optimized approach)
        int size = slices.size();
        int res1 = solveSO(0,size-2,slices);
        int res2 = solveSO(1,size-1,slices);

        return max(res1,res2);
        
    }
};
