#include <bits/stdc++.h> 

// int solveRec(vector<int> &valueInHouse ,int start ,int end){
//     if(end < start ) return 0;
//     if(end == start) return valueInHouse[start];
    
//     int including = solveRec(valueInHouse,start,end-2) + valueInHouse[end];
//     int excluding = solveRec(valueInHouse,start,end-1) + 0;
    
//     int res = max(including,excluding);
    
//     return res;
// }


// int solveMem(vector<int> &valueInHouse ,long long int start ,long long int end ,vector< long long int>  &dp){
    
//     if(end < start ) return 0;
//     if(end == start) return valueInHouse[start];
//     if(dp[end] != -1) dp[end];
    
//     long long int including = solveMem(valueInHouse,start,end-2,dp) + valueInHouse[end];
//     long long int excluding = solveMem(valueInHouse,start,end-1,dp) + 0;
    
//     dp[end] = max(including,excluding);

    
//     return dp[end];
// }

long long int solveSpaceOp(vector<int> &nums){
    
    int n = nums.size();
    //base-case
     long long int prev2 = 0;
     long long int  prev1 = nums[0];
    
    for(int i =1 ; i<n ;i++){
      long long int including = prev2 + nums[i];
      long long int excluding = prev1 + 0;
      long long int current = max(including,excluding);
        prev2 = prev1;
        prev1 = current;
    }
    
    return  prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    //including-excluding principle approach , i/p array-> 1 3 2 1
    
     //Recursive approach (TLE)
//     int n = valueInHouse.size();
//     if(n == 1) return valueInHouse[0];
//     int ans ;
//     ans = max(solveRec(valueInHouse,0,n-2) ,solveRec(valueInHouse,1,n-1));
    
    // Memoization approach (TLE)
//     long long int n = valueInHouse.size();
//     if(n == 1) return valueInHouse[0];
//     vector< long long int> dp(n,-1);
//     long long int ans;
//     ans = max(solveMem(valueInHouse,0,n-2,dp) ,solveMem(valueInHouse,1,n-1,dp));
    
    //Space optimized approach 
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0]; //imp corner case
    vector<int> first,second;
    for(int i =0 ;i< n ;i++){
        if(i == n-1){
            second.push_back(valueInHouse[i]);
        }else if(i == 0){
            first.push_back(valueInHouse[i]);
        }else{
            first.push_back(valueInHouse[i]);
            second.push_back(valueInHouse[i]);
        }
    }
    long long int ans = max (solveSpaceOp(first),solveSpaceOp(second));
    
    return ans;
}
