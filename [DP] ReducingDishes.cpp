class Solution {
public:
    
    // int solveRec(vector<int> &satisfaction ,int index , int unit){

    //     if(index >= satisfaction.size()) return 0;
    //     int including = satisfaction[index] * (unit) + solveRec(satisfaction,index+1 ,unit+1);
    //     int excluding = 0 + solveRec(satisfaction,index+1,unit);

    //     int ans = max(including , excluding);
    //     return ans;
    // }

    // int solveMem(vector<int> &satisfaction ,int index , int unit ,vector<vector<int>> &dp){

    //     if(index >= satisfaction.size()) return 0;
    //     if(dp[index][unit]!= -1) return dp[index][unit];
    //     int including = satisfaction[index] * (unit) + solveMem(satisfaction,index+1 ,unit+1,dp);
    //     int excluding = 0 + solveMem(satisfaction,index+1,unit,dp);

    //     int ans = max(including , excluding);
    //     dp[index][unit]= ans;

    //     return ans;
    // }

    // int solveTab(vector<int> satisfaction ){ // O(N*N)
    //     int n = satisfaction.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //     dp[n][n] = 0 ;
    //     for(int r = n-1 ; r >=0 ;r--){
    //      for(int c = r; c >= 0 ; c--){
    //         int including = satisfaction[r] * (c+1) + dp[r+1][c+1];
    //         int excluding = 0 + dp[r+1][c];
    //         dp[r][c]= max(including , excluding);
    //         }
    //     }

    //     // for(auto v : dp){
    //     //     for(auto k : v) {
    //     //         cout<<k<<" ";
    //     //      }cout<<endl;
    //     //  }
    //     return dp[0][0];
    // }

    // int solveSO(vector<int> satisfaction ){  // O(2*N)
    //     int n = satisfaction.size();
    //     vector<int> prev(n+1,0);
    //     vector<int> curr(n+1,0);
        
    //     for(int r = n-1 ; r >=0 ;r--){
    //      for(int c = r; c >= 0 ; c--){
    //         int including = satisfaction[r] * (c+1) + prev[c+1];
    //         int excluding = 0 + prev[c];
    //         curr[c]= max(including , excluding);
    //         }
    //         prev = curr;
    //     }
    //     return curr[0];
    // }

    // int solveSO2(vector<int> satisfaction ){  // O(N)

    //     int n = satisfaction.size();
    //     vector<int> prev(n+1,0);
        
    //     for(int r = n-1 ; r >=0 ;r--){
    //      for(int c = 0; c <= r ; c++){
    //         int including = satisfaction[r] * (c+1) + prev[c+1];
    //         int excluding = 0 + prev[c];
    //         prev[c]= max(including , excluding);
    //         }
    //     }
    //     return prev[0];

    // }

    int solveGreedy(vector<int>& satisfaction){
        int res = 0;
        int n = satisfaction.size();
        if(satisfaction[n-1] <= 0 ) return res;
        for(int i =0 ;i<n;i++){
            int time = 1;
            int ans = 0;
            for(int k =i; k<n;k++){
                ans += satisfaction[k]*time;
                time++;
            }
            res = max(res,ans);
        }

        return res;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        
        // Recursive approach
        // sort(satisfaction.begin(),satisfaction.end());
        // int unit =1 ;
        // int res = solveRec(satisfaction,0,unit);

        // Recursion + Memoization (Top-down approach)
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // sort(satisfaction.begin(),satisfaction.end());
        // int res = solveMem(satisfaction,0,1,dp);

        // Tabulation (Bottom-up) approach
        //   sort(satisfaction.begin(),satisfaction.end());
        //   int res = solveTab(satisfaction);
        
        // space optimization
        //   sort(satisfaction.begin(),satisfaction.end());
        //   int res = solveSO(satisfaction);

        //space optimization2 
        //   sort(satisfaction.begin(),satisfaction.end());
        //   int res = solveSO2(satisfaction);

        //greedy approach
         sort(satisfaction.begin(),satisfaction.end());
         int res = solveGreedy(satisfaction);

        return res;
    }
};
