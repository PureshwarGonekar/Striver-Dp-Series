//Problem - https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

//T.C. = O(N x M) + O(N x M x 4) ~ O(N x M)
//S.C. = O(N x M) 
class Solution{
public:
    bool check(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m ) return true;
        return false;
    }
    void dfs(int row,int col, int n, int m, vector<vector<char>> &mat, vector<vector<int>>& vis){
        
        vis[row][col] =1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow= row + dr[k];
            int ncol= col + dc[k];
            if(check(nrow,ncol,n,m) && mat[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,n,m,mat,vis);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( (i==0 || i==n-1|| j==0 || j==m-1) && mat[i][j]=='O'){
                    dfs(i,j,n,m,mat,vis);
                }
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(  mat[i][j]== 'O' && !vis[i][j]){
                    mat[i][j]= 'X';
                }
            }
        }
        
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends