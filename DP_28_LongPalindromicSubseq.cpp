//Problem - https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787

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

int lps(string s){
    string t = s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
}