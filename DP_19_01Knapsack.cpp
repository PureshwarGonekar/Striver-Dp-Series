// Problem - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 

// Recusion T.C. = O(2^n) S.C. = O(N) //--> Auxiliary Space Complexity
int f(int ind,vector<int> weight, vector<int> value,int maxWeight){
	if(ind==0){
		if(weight[0]<= maxWeight) return value[0];
		else return 0;
	}
	int notTake= f(ind-1,weight,value,maxWeight);
	int Take=0;
	if(weight[ind] <= maxWeight){
		Take= f(ind-1,weight,value,maxWeight- weight[ind]) + value[ind];
	}
	return max(notTake,Take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,weight,value,maxWeight);
}


//Memorization T.C = O(N x (W+1)) S.C = O(N x (W+1)) + O(N)
int f(int ind,vector<int> weight, vector<int> value,int maxWeight,vector<vector<int>> &dp){
	if(ind==0){
		if(weight[0]<= maxWeight) return value[0];
		else return 0;
	}

	if(dp[ind][maxWeight] !=-1) return dp[ind][maxWeight];
	int notTake= f(ind-1,weight,value,maxWeight,dp);
	int Take=0;
	if(weight[ind] <= maxWeight){
		Take= f(ind-1,weight,value,maxWeight- weight[ind],dp) + value[ind];
	}
	return dp[ind][maxWeight]=max(notTake,Take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,weight,value,maxWeight,dp);
}


// Tabulation T.C = O(N x (W+1)) S.C = O(N x (W+1))
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

    for(int w=weight[0]; w<= maxWeight ; w++) dp[0][w] = value[0];

    for(int i=1 ; i<n ;i++){
        for(int w=0 ; w<=maxWeight ; w++){
            int notTake= dp[i-1][w];	
            int Take=INT_MIN;
            if(weight[i] <= w){
                Take= dp[i-1][w - weight[i] ] + value[i];
            }
            dp[i][w]=max(notTake,Take);
        }
    }
	return dp[n-1][maxWeight];
}

//Space Optimization T.C = O(N x (W+1)) S.C = O(W+1)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1);
	vector<int> cur(maxWeight+1);

    for(int w=weight[0]; w<= maxWeight ; w++) prev[w] = value[0];

    for(int i=1 ; i<n ;i++){
        for(int w=0 ; w<=maxWeight ; w++){
            int notTake= prev[w];	
            int Take=INT_MIN;
            if(weight[i] <= w){
                Take= prev[w - weight[i] ] + value[i];
            }
            cur[w]=max(notTake,Take);
        }
        prev= cur;
    }
	return prev[maxWeight];
}


//More Space Optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1);

    for(int w=weight[0]; w<= maxWeight ; w++) prev[w] = value[0];

    for(int i=1 ; i<n ;i++){
        for(int w=maxWeight ; w>=0 ; w--){  // fill right to left into prev so that no overwriting have been done
            int notTake= prev[w];	
            int Take=INT_MIN;
            if(weight[i] <= w){
                Take= prev[w - weight[i] ] + value[i];
            }
            prev[w]=max(notTake,Take);
        }
    }
	return prev[maxWeight];
}
