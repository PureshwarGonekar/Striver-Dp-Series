// Problem - https://www.codingninjas.com/codestudio/problems/can-you-make_4244510

#include <bits/stdc++.h> 

int lcs(string s, string t) // Longest Common Subsequence
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
  
int canYouMake(string &str, string &ptr)
{
    /* n x m
    Insertions = n- len(lcs)
    Deletions = m - len(lcs)

    Total = m+n - 2*len(lcs)
    */
    return str.size() + ptr.size() - 2* lcs(str,ptr);
}