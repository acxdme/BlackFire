// Method-1 : Recursive approach
/*
Time complexity : 
Space complexity :
Recursive Releation used : f(s) = f(s+1) + f(s+2) 
where f(s) is the total number of ways to reach the nth stairs from s.
[ Ex : f(0) = f(1) + f(2) ]
*/

#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007

int findWays(int curr, int nstairs){
    if(curr == nstairs) return 1;
    if(curr > nstairs){
        return 0;
    }
  
    return ( findWays(curr+1,nstairs) + findWays(curr+2,nstairs)) % MOD;
}
int countDistinctWays(int nStairs) {
    
    int res;
    res = findWays(0,nStairs);
    
    return res;
   
}
------------------------------------------------------------
//Method-2 (Top-Down approach aka Recursion+Memoization)
/*
Time Complexity :
Space Complexity :
Recursive relation used : f(s) = f(s+1) + f(s+2)
To Change the wind from pure recursive function to Top-Down Approach  use the algorithm below:
a) initialize the dp array . Ex : dp(n+1,-1);
b) store the result in the dp array
c) Use the value of the dp array to get results for the sub-problem if it exists.
*/

#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007

int findWays(int curr, int nstairs,vector<int> & dp){
    if(curr == nstairs) return 1;
    if(curr > nstairs){
        return 0;
    }
    if(dp[curr] != -1) return dp[curr];
  
    return  dp[curr] = (( findWays(curr+1,nstairs,dp) + findWays(curr+2,nstairs,dp)) % MOD);
}
int countDistinctWays(int nStairs) {
    
    int res;
    vector<int> dp(nStairs + 1 ,-1);
    res = findWays(0,nStairs,dp);
    
    return res;
   
}
------------------------------------------------------------

