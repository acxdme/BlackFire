 // long long int solveRec(int faces , int dice , int total ){
    //     if(dice == 0 ){
    //         if(total == 0 ) return 1;
    //         return 0;
    //     }
        
    //   long long int ans = 0;
    //   for(int face =1 ; face <= faces; face++){
    //       ans += solveRec(faces,dice-1,total-face);
    //   }
       
    //   return ans;
        
    // }
    
    // long long int solveMem(int faces , int dice , int total ,vector<vector<long long int>> &dp){
    //     if(total < 0 ) return 0;
    //     if(dice == 0 ){
    //         if(total == 0 ) return 1;
    //         return 0;
    //     } 
    //     if(total == 0 && dice != 0) return 0;
    //     if(dp[dice][total] != -1 ) return dp[dice][total];
        
    //   long long int ans = 0;
    //   for(int face =1 ; face <= faces; face++){
    //       ans += solveMem(faces,dice-1,total-face,dp);
    //   }
       
    //   dp[dice][total] = ans;
       
    //   return  dp[dice][total];
        
    // }
    
    // long long int solveTab(int faces , int dice , int total){
    //     vector<vector<long long int>> dp(dice+1,vector<long long int>(total+1,0));
    //     if(total < 0 ) return 0;
    //     dp[0][0] = 1;
 
        
       
    //   for(int d = 1 ; d <= dice ; d++){
    //       for(int t = 1 ; t <= total ; t++){
    //           long long int ans = 0;
    //           for(int face =1 ; face <= faces; face++){
    //               if( t - face >= 0  )
    //                  ans += dp[d-1][t-face];
    //           }
               
    //           dp[d][t] = ans;
    //       }
           
    //   }

    // //   for(auto v : dp){
    // //       for(auto it : v){
    // //           cout<<it<<" ";
    // //       }cout<<endl;
    // //   }
       
    //   return  dp[dice][total];
        
    // }
    
    // long long int solveSO(int faces , int dice , int total){

    //     vector<long long int> curr(total+1,0);
    //     vector<long long int> prev (total+1,0);
        
    //     prev[0] = 1;
 
        
       
    //   for(int d = 1 ; d <= dice ; d++){
    //       for(int t = 1 ; t <= total ; t++){
    //           long long int ans = 0;
    //           for(int face =1 ; face <= faces; face++){
    //               if( t - face >= 0  )
    //                  ans += prev[t-face];
    //           }
               
    //           curr[t] = ans;
    //       }
    //       prev = curr;
           
    //   }

    //   return  prev[total];
        
    // }
    
    long long int solveSO2(int faces , int dice , int total){
        

        vector<long long int> curr(total+1,0);
        curr[0] = 1;
 
        
       
      for(int d = 1 ; d <= dice ; d++){
          for(int t = total ; t >= 0 ; t--){
              long long int ans = 0;
              for(int face =1 ; face <= faces; face++){
                  if( t - face >= 0  )
                     ans += curr[t-face];
              }
               
              curr[t] = ans;
          } 
      }

      return  curr[total];
        
    }
    
    
    long long noOfWays(int M , int N , int X) {
        
        // Recursive approach
        // long long int res = solveRec(M,N,X);
        
        // Recursion + Memoization (Top-down) approach
        // vector<vector<long long int>> dp(N+1,vector<long long int>(X+1,-1));
        // long long int res = solveMem(M,N,X,dp);
        
        // Tabulation (bottom-up) approach
        // long long int res = solveTab(M,N,X);
        
        // Space-Optimized approach O(2*N) space complexity 
        //   long long int res = solveSO(M,N,X);
        
        // Space-Optimized approch O(N) space complexity
          long long int res = solveSO2(M,N,X);
        
        
        return res;
    }
