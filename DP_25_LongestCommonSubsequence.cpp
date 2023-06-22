// Problem - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879

#include <bits/stdc++.h> 
 
//Recusion T.C = O(2^(m+n))
int f(int ind1,int ind2, string s, string t){
	if(ind1<0 || ind2<0) return 0;
	if(s[ind1]==t[ind2]) return 1 + f(ind1-1,ind2-1,s,t);
	return max(  f(ind1-1,ind2,s,t), f(ind1,ind2-1,s,t)  );
}
int lcs(string s, string t)
{
	return f(s.size()-1, t.size()-1,s,t);
}
  


 
// Memorization T.C. = O(M x N) S.C. = O(M x N) + O(M + N)
int f(int ind1,int ind2, string s, string t, vector<vector<int>> &dp){
	//Base case
	if(ind1<0 || ind2<0) return 0;

	//memorization
	if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

	// Explore the path
	if(s[ind1]==t[ind2]) 
		return dp[ind1][ind2]= 1 + f(ind1-1,ind2-1,s,t,dp);
	else
		return dp[ind1][ind2] = max(  f(ind1-1,ind2,s,t,dp), f(ind1,ind2-1,s,t,dp)  );
}
int lcs(string s, string t)
{	int m=s.size(), n=t.size();

	vector<vector<int>> dp(m,vector<int>(n,0));

	
	return f(m-1, n-1,s,t,dp);
}



// Shifting of Index In Memorization
int f(int ind1,int ind2, string s, string t, vector<vector<int>> &dp){
	//Base case
	if(ind1==0 || ind2==0) return 0;

	//memorization
	if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

	// Explore the path
	if(s[ind1-1]==t[ind2-1]) 
		return dp[ind1][ind2]= 1 + f(ind1-1,ind2-1,s,t,dp);
	else
		return dp[ind1][ind2] = max(  f(ind1-1,ind2,s,t,dp), f(ind1,ind2-1,s,t,dp)  );
}
int lcs(string s, string t)
{	int m=s.size(), n=t.size();

	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	
	return f(m, n,s,t,dp);
}
  

 
// Tabulation T.C. = O(M x N) S.C. = O(M x N)
int lcs(string s, string t)
{	int m=s.size(), n=t.size();

	vector<vector<int>> dp(m+1,vector<int>(n+1));

	for(int ind1=0; ind1<=m; ind1++){
		for(int ind2=0; ind2<=n; ind2++){

			if(ind1==0 || ind2==0) 
				dp[ind1][ind2] =0;
			else if(s[ind1-1]==t[ind2-1]) 
				dp[ind1][ind2]= 1 + dp[ind1-1][ind2-1];
			else
				dp[ind1][ind2] = max(  dp[ind1-1][ind2] , dp[ind1][ind2-1] );
		}
	}
	return dp[m][n];
}
  

// Space Optimization  T.C. = O(M x N) S.C. = O(N)
int lcs(string s, string t)
{	int m=s.size(), n=t.size();

	vector<int> prev(n+1);
	vector<int> cur(n+1);

	for(int ind1=0; ind1<=m; ind1++){
		for(int ind2=0; ind2<=n; ind2++){

			if(ind1==0 || ind2==0) 
				cur[ind2] =0;
			else if(s[ind1-1]==t[ind2-1]) 
				cur[ind2]= 1 + prev[ind2-1];
			else
				cur[ind2] = max(  prev[ind2] , cur[ind2-1] );
		}
		prev = cur;
	}
	return prev[n];
}
