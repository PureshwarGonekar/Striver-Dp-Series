//Problem - https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include <bits/stdc++.h> 

//Recusion 
int f(int ind,int T,vector<int> &num){
    if(ind==0){
        if(T % num[0]==0) return T/ num[0];
        else return 1e9;
    }
    int notTake= f(ind-1,T,num);
    int Take = INT_MAX;
    if(num[ind] <= T) 
        Take = 1 + f(ind,T-num[ind],num);
    return min(notTake,Take);
}

int minimumElements(vector<int> &num, int x){
    return f(num.size()-1,x,num);
}


//Memorization
int f(int ind,int T,vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(T % num[0]==0) return T/ num[0];
        else return 1e9;
    }
    if(dp[ind][T]!= -1) return dp[ind][T];

    int notTake= f(ind-1,T,num);
    int Take = INT_MAX;
    if(num[ind] <= T) 
        Take = 1 + f(ind,T-num[ind],num);
    return dp[ind][T]=min(notTake,Take);
}

int minimumElements(vector<int> &num, int x){
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    return f(num.size()-1,x,num,dp);
}

// Tabulation
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));

    for(int T=0 ; T<=x; T++){
        if(T%num[0]==0){
            dp[0][T]= T/num[0];
        }
        else dp[0][T] = 1e9;
    }

    for(int ind=1 ; ind<n ; ind++){
        for(int T=0; T<=x ; T++){
            int notTake = dp[ind-1][T];
            int Take= 1e9;
            if(num[ind] <=T){
                Take = 1 + dp[ind][T-num[ind]];
            }
            dp[ind][T]= min(notTake,Take);
        }
    }
    int ans= dp[n-1][x];
    if(ans>= 1e9) return -1;
    return ans;
}

//Space Optimization

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x+1);
    vector<int> cur(x+1);

    for(int T=0 ; T<=x; T++){
        if(T%num[0]==0){
            prev[T]= T/num[0];
        }
        else prev[T] = 1e9;
    }

    for(int ind=1 ; ind<n ; ind++){
        for(int T=0; T<=x ; T++){
            int notTake = prev[T];
            int Take= 1e9;
            if(num[ind] <=T){
                Take = 1 + cur[T-num[ind]];
            }
            cur[T]= min(notTake,Take);
        }
        prev=cur;
    }
    int ans= prev[x];
    if(ans>= 1e9) return -1;
    return ans;
}