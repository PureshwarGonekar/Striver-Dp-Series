// Problem - https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

// General Recursion
int f(int ind,int n,vector<int> &price){

	if(ind ==0) return n * price[0];

	int notTake = f(ind-1,n,price);
	int Take = INT_MIN;

	int rodLength = ind+1;
	if(rodLength <=n){ // 
		Take = price[ind] + f(ind,n-rodLength,price);
	}

	return max(notTake,Take);
}

int cutRod(vector<int> &price, int n)
{
	return f(n-1,n,price);
}
 

 
// Memorization
int f(int ind,int n,vector<int> &price, vector<vector<int>> &dp){

	if(ind ==0) return n * price[0];

	if(dp[ind][n]!=-1) return dp[ind][n];

	int notTake = f(ind-1,n,price,dp);
	int Take = INT_MIN;
	int rodLength = ind+1;
	if(rodLength <=n){ // 
		Take = price[ind] + f(ind,n-rodLength,price,dp);
	}

	return dp[ind][n]=max(notTake,Take);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}
 

 

// Tabulation
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,0));

	for(int i=0;i<=n;i++){
		dp[0][i] = i* price[0];
	}

	for(int ind=1;ind< n; ind++){
		for(int N=0; N<=n; N++){
			int notTake = dp[ind-1][N];
			int Take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <=N){ // 
				Take = price[ind] + dp[ind][N-rodLength];
			}
			dp[ind][N]=max(notTake,Take);
		}
	}

	return dp[n-1][n];
}
 

 
// Space Optimization
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1);
	vector<int> cur(n+1);

	for(int i=0;i<=n;i++){
		prev[i] = i* price[0];
	}

	for(int ind=1;ind< n; ind++){
		for(int N=0; N<=n; N++){
			int notTake = prev[N];
			int Take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <=N){ // 
				Take = price[ind] + cur[N-rodLength];
			}
			cur[N]=max(notTake,Take);
		}
		prev=cur;
	}

	return prev[n];
}
 

// More Space Optimization
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1);

	for(int i=0;i<=n;i++){
		prev[i] = i* price[0];
	}

	for(int ind=1;ind< n; ind++){
		for(int N=0; N<=n; N++){

			int notTake = prev[N];
			int Take = INT_MIN;

			int rodLength = ind+1;
			if(rodLength <=N){ // 
				Take = price[ind] + prev[N-rodLength];
			}
			prev[N]=max(notTake,Take);
		}
	}

	return prev[n];
}
