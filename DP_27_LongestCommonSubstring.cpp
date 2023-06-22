// Problem - https://www.codingninjas.com/studio/problems/longest-common-substring_1235207


// Tabulation
int lcs(string &s, string &t)
{	int m=s.size(), n=t.size();

	vector<vector<int>> dp(m+1,vector<int>(n+1));
	int ans=0;
	for(int ind1=0; ind1<=m; ind1++){
		for(int ind2=0; ind2<=n; ind2++){

			if(ind1==0 || ind2==0) 
				dp[ind1][ind2] =0;
			else if(s[ind1-1]==t[ind2-1]) {
				dp[ind1][ind2]= 1 + dp[ind1-1][ind2-1];
				ans = max(ans,dp[ind1][ind2]);
			}
			else		
				dp[ind1][ind2] = 0;
		}
	}
	return ans;
}

// Space Optimization  T.C. = O(M x N) S.C. = O(N)
int lcs(string s, string t)
{	int m=s.size(), n=t.size();

	vector<int> prev(n+1);
	vector<int> cur(n+1);

	int ans=0;
	for(int ind1=0; ind1<=m; ind1++){
		for(int ind2=0; ind2<=n; ind2++){

			if(ind1==0 || ind2==0) 
				cur[ind2] =0;
			else if(s[ind1-1]==t[ind2-1]) {
				cur[ind2]= 1 + prev[ind2-1];
				ans = max(ans,cur[ind2]);
			}
			else
				cur[ind2] = 0;
		}
		prev = cur;
	}
	return ans;
}