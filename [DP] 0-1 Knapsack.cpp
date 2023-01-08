/*
A classic problem.
*/
#include <bits/stdc++.h> 
using namespace std;

// int solveRec(vector<int> &weight, vector<int> &value, int index, int maxWeight)
// {
//     if(index == 0 ){
//         if(weight[index] <= maxWeight)
//             return value[index];
//         else
//             return 0;
//     }
    
//     int inclusive = 0;
//     if(weight[index] <= maxWeight)
//         inclusive = value[index] + solveRec(weight,value,index-1,maxWeight-weight[index]);
    
//     int exclusive = 0 + solveRec(weight,value,index-1,maxWeight);
    
//     return max(inclusive,exclusive);   
// }

// int solveMem(vector<int> &weight, vector<int> &value, int index, int maxWeight,vector<vector<int> >& dp)
// {
//     if(index == 0 ){
//         if(weight[index] <= maxWeight)
//             return value[index];
//         else
//             return 0;
//     }
//     if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
    
//     int inclusive = 0;
//     if(weight[index] <= maxWeight)
//         inclusive = value[index] + solveMem(weight,value,index-1,maxWeight-weight[index],dp);
    
//     int exclusive = 0 + solveMem(weight,value,index-1,maxWeight,dp);
    
//     return dp[index][maxWeight] = max(inclusive,exclusive);   
// }

// int solveTab(vector<int> &weight, vector<int> &value, int index, int maxWeight,vector<vector<int> >& dp)
// {
//     //base case
//     for(int i= 1 ;i<= maxWeight;i++){
//       if( weight[0] <= i  )
//           dp[0][i] = value[0];
//     }
    
//     int n = weight.size();
//     for(int row = 1 ;row < n;row ++){
//         for(int w = 1; w <= maxWeight;w++){
//             int inclusive = 0;
//             if(weight[row] <= w )
//                 inclusive = value[row] + dp[row-1][w-weight[row]];
//             int exclusive = 0 + dp[row-1][w];
//                 dp[row][w] = max(inclusive,exclusive); 
//         }
//     }
//     return dp[n-1][maxWeight];
// }

    //Space optimization with O(2*N) space complexity
// int solveSO(vector<int> &weight, vector<int> &value, int index, int maxWeight)
// {
//     vector<int> curr(maxWeight+1,0);
//     vector<int> prev(maxWeight+1,0);
//     //base case
//     for(int i= 1 ;i<= maxWeight;i++){
//       if( weight[0] <= i  )
//           prev[i] = value[0];
//     }
    
//     int n = weight.size();
//     for(int row = 1 ;row < n;row ++){
//         for(int w = 1; w <= maxWeight;w++){
//             int inclusive = 0;
//             if(weight[row] <= w )
//                 inclusive = value[row] + prev[w-weight[row]];
//             int exclusive = 0 + prev[w];
//                 curr[w] = max(inclusive,exclusive); 
//         }
//         prev = curr;
//     }
//     return prev[maxWeight];
// }

  //space optimization with O(N) time complexity
int solveSO2(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    vector<int> curr(maxWeight+1,0);

    //base case
    for(int i= 1 ;i<= maxWeight;i++){
      if( weight[0] <= i  )
          curr[i] = value[0];
    }
    
    int n = weight.size();
    for(int row = 1 ;row < n;row ++){
        for(int w = maxWeight ; w >= 0 ; w--){
            int inclusive = 0;
            if(weight[row] <= w )
                inclusive = value[row] + curr[w-weight[row]];
            int exclusive = 0 + curr[w];
                curr[w] = max(inclusive,exclusive); 
        }
    }
    return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    //Recursive approach
//     int ans = solveRec(weight,value,n-1 ,maxWeight);
    
    //Recursive + Memorization(top-down approach)
//     vector<int> dp(maxWeight+1,-1);  ----galat , do variables changes ho rahe hai
//     vector< vector<int> > dp(n,vector<int>(maxWeight + 1,-1));
//     int ans = solveMem(weight,value,n-1,maxWeight,dp); 
    
    // Tabular method (bottom-up )
//         vector< vector<int>> dp(n,vector<int>(maxWeight+1,0));
//         int ans = solveTab(weight,value,n-1,maxWeight,dp);
    
    //Space Optimization (O(2*N) space optimization)
//      int ans = solveSO(weight,value,n,maxWeight);
    
    //Space Optimization (O(N) space optimization)
     int ans = solveSO2(weight,value,n,maxWeight);
    
    return ans;  
}
