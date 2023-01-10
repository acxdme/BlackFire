    // int solveRec(int index,int arr[],int target){
    //     if(index < 0 ) return 0;
    //     if(target == 0 ) return 1;
        
    //     int inclusive = solveRec(index-1,arr,target - arr[index]);
    //     int exclusive = solveRec(index-1,arr,target);
        
    //     return (inclusive || exclusive) ;
        
    // }
    
    // int solveMem(int index,int arr[],int target , vector<vector<int>> &dp){
    //     if(index < 0 or target < 0 ) return 0;
    //     if(target == 0 ) return 1;
    //     if(dp[index][target] != -1 ) return dp[index][target];
        
    //     int inclusive = solveMem(index-1,arr,target - arr[index],dp);
    //     int exclusive = solveMem(index-1,arr,target,dp);
        
        
    //     return dp[index][target] = (inclusive || exclusive) ;
        
    // }
    
    // int solveTab(int size,int arr[],int target){ // 0 -> n-1 && 0 -> x
        
    //     vector<vector<int>> dp (size,vector<int>(target+1,0));
    //     for(int i = 0 ;i < size ;i++){
    //         dp[i][0] = 1;
    //     }
        //// ye wali row chod rahe ho tuh tumhe calculate karni padegi
    //     if(arr[0] <= target) dp[0][arr[0]] = 1; 

    //     for(int index = 1 ;index <= size-1 ;index++ ){
    //         for(int t= 1 ; t<=target ;t++ ){  
    //             int inclusive = 0;
    //             if(t - arr[index] >= 0)
    //               inclusive = dp[index-1][t - arr[index]];
    //             int exclusive = dp[index-1][t];
    //             dp[index][t] = (inclusive || exclusive);
    //         }
    //     }
        

    //     // for(auto v : dp){
    //     //     for (auto it : v){
    //     //         cout<<it<<" ";
    //     //     }cout<<endl;
    //     // }
        
    //     return dp[size-1][target] ;
        
    // }
    
    // int solveSO1(int size,int arr[],int target){ // 0 -> n-1 && 0 -> x
        
    //     vector<vector<int>> dp (size,vector<int>(target+1,0));
        
    //     vector<int> curr (target+1,0);
    //     vector<int> prev (target+1,0);
    //     prev[0]= 0;
    //     if(arr[0] <= target) prev[arr[0]] = 1;

    //     for(int index = 1 ;index <= size-1 ;index++ ){
    //         for(int t= 1 ; t<=target ;t++ ){  
    //             int inclusive = 0;
    //             if(t - arr[index] >= 0)
    //               inclusive = prev[t - arr[index]];
    //             int exclusive = prev[t];
    //             curr[t] = (inclusive || exclusive);
    //         }
    //         prev = curr;
    //     }
    //     return prev[target] ;
        
    // }
    
    int solveSO2(int size,int arr[],int target){
        
        vector<vector<int>> dp (size,vector<int>(target+1,0));
        
        // vector<int> curr (target+1,0);
        vector<int> prev (target+1,0);
        prev[0]= 0;
        if(arr[0] <= target) prev[arr[0]] = 1;

        for(int index = 1 ;index <= size-1 ;index++ ){
            for(int t= target ; t>=1 ;t-- ){  
                int inclusive = 0;
                if(t - arr[index] >= 0)
                  inclusive = prev[t - arr[index]];
                int exclusive = prev[t];
                prev[t] = (inclusive || exclusive);
            }
        }
        return prev[target] ;
        
    }
    
    
    
    
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i =0 ;i<N;i++){
            total +=arr[i];
        }
        
        
        int res = 0;
        
        // Recursive approach
        // if(total % 2 == 0)
        //  res = solveRec(N-1,arr,total/2);
        
        // Recursion + Memoization (Top-down) approach
        // if(total % 2 == 0){
        //     vector<vector<int>>dp(N,vector<int>(total/2 + 1 ,-1));
        //     res = solveMem(N-1,arr,total/2,dp);
        // }
        
        //Tabulation(Bottom-up) approach
        // if(total % 2 == 0){
        //     res = solveTab(N,arr,total/2);
        // }
        
        //Space optimization O(2*N) space complexity 
        // if(total % 2 == 0){
        //     res = solveSO1(N,arr,total/2);
        // }
        
        //Space optimization O(N) space complexity
        if(total % 2 == 0){
            res = solveSO2(N,arr,total/2);
        }
         
        return res;
    }
