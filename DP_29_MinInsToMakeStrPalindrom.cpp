//Problem - https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293

// Recursive Approch
int f(int start, int end, string &str){
    //Base case
    if(start>=end) return 0;

    if(str[start]== str[end]) return f(start+1,end-1,str);
    else{
        int leftIns = 1 + f(start,end-1,str);
        int rightIns = 1 + f(start+1,end,str);
        return min(leftIns,rightIns);
    }
}
int minInsertion(string &str)
{
    return f(0,str.size()-1,str);
}

 

 
// Memorization
int f(int start, int end, string &str,vector<vector<int>> &dp){
    //Base case
    if(start>=end) return 0;

    if(dp[start][end]!=-1) return dp[start][end];

    if(str[start]== str[end]) return dp[start][end]=f(start+1,end-1,str,dp);
    else{
        int leftIns = 1 + f(start,end-1,str,dp);
        int rightIns = 1 + f(start+1,end,str,dp);
        return dp[start][end]=min(leftIns,rightIns);
    }
}
int minInsertion(string &str)
{
    int n= str.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,n-1,str,dp);
}
 

 
// Tabulation  // giving wrong ans
int minInsertion(string &str)
{
    int n= str.size();
    vector<vector<int>> dp(n,vector<int>(n));

    for(int start=0; start<n; start++){
        for(int end= n-1; end>=0; end--){

            if(start>=end) 
                dp[start][end]=0;

            else if(str[start]== str[end]) 
                dp[start][end]= dp[start+1][end-1];
            else{
                int leftIns = 1 + dp[start][end-1];
                int rightIns = 1 + dp[start+1][end];

                dp[start][end]=min(leftIns,rightIns);
            }
        }
    }

    return dp[0][n-1];
}

 

// Longest subsequence approch 
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

int lps(string s){ // Longest Palindromic Subsequence 
    string t = s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
}
int minInsertion(string &str){
    int len = str.length();
    return len - lps(str);
}
