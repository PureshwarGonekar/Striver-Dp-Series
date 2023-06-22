// Problem - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879

// From DP_25
// Tabulation T.C. = O(M x N) S.C. = O(M x N) 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_lcs(string s, string t)
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

    // BackTrack 
    // T.C. = O(m+n)
	int len= dp[m][n];
    string str="";
    for(int i=0;i<len;i++){
        str+="$";
    }
    int i=m, j=n;
    int index = len-1;
    while (i>0 && j >0){
        if(s[i-1] == t[j-1]){
            str[index] = s[i-1];
            index--;
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<"str : "<<str<<endl;

}

int main(){
    string s1 = "abcde", s2= "bdgek";
    print_lcs(s1, s2);  // Output = "bde"
    return 0;
}