// Problem - https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

#include <bits/stdc++.h> 
 

//Recursion
int f(int ind, int w, vector<int> &p, vector<int> &wt){
    if(ind==0){
        if(wt[0] <= w) return w/wt[0] * p[0];
        else return 0;
    }

    int notTake = f(ind-1,w,p,wt);
    int Take = INT_MIN;
    if(wt[ind]<=w)
        Take = p[ind] + f(ind,w-wt[ind],p,wt);
    return max(notTake,Take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return f(n-1,w,profit,weight);
}

 

 
// Memorization
int f(int ind, int w, vector<int> &p, vector<int> &wt,vector<vector<int>> &dp){
    if(ind==0){
        if(wt[0] <= w) return w/wt[0] * p[0];
        else return 0;
    }

    if(dp[ind][w] !=-1) return dp[ind][w];

    int notTake = f(ind-1,w,p,wt,dp);
    int Take = INT_MIN;
    if(wt[ind]<=w)
        Take = p[ind] + f(ind,w-wt[ind],p,wt,dp);

    return dp[ind][w]=max(notTake,Take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

 

 
// Tabulation
int unboundedKnapsack(int n, int w, vector<int> &p, vector<int> &wt)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));

    for(int wi=0 ;wi<=w;wi++){
        if(wt[0] <= wi) dp[0][wi] = wi/wt[0] * p[0];
    }

    for(int ind=1; ind<n; ind++){
        for(int wi=0; wi<=w; wi++){

            int notTake = dp[ind-1][wi];
            int Take = INT_MIN;
            if(wt[ind]<=wi)
                Take = p[ind] + dp[ind][wi-wt[ind]];

            dp[ind][wi]=max(notTake,Take);
        }
    }
    return dp[n-1][w];
}
 


// Space Optimization
int unboundedKnapsack(int n, int w, vector<int> &p, vector<int> &wt)
{
    // Write Your Code Here.
    vector<int> prev(w+1,0);
    vector<int> cur(w+1,0);

    for(int wi=0 ;wi<=w;wi++){
        if(wt[0] <= wi) prev[wi] = wi/wt[0] * p[0];
    }

    for(int ind=1; ind<n; ind++){
        for(int wi=0; wi<=w; wi++){

            int notTake = prev[wi];
            int Take = INT_MIN;
            if(wt[ind]<=wi)
                Take = p[ind] + cur[wi-wt[ind]];

            cur[wi]=max(notTake,Take);
        }
        prev = cur;
    }
    return prev[w];
}

 

// More Space Optimization  
int unboundedKnapsack(int n, int w, vector<int> &p, vector<int> &wt)
{
    // Write Your Code Here.
    vector<int> prev(w+1,0);
    for(int wi=0 ;wi<=w;wi++){
        if(wt[0] <= wi) prev[wi] = wi/wt[0] * p[0];
    }

    for(int ind=1; ind<n; ind++){
        for(int wi=0; wi<=w; wi++){

            int notTake = prev[wi];
            int Take = INT_MIN;
            if(wt[ind]<=wi)
                Take = p[ind] + prev[wi-wt[ind]];

            prev[wi]=max(notTake,Take);
        }
    }
    return prev[w];
}

 