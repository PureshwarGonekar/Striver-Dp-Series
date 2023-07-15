using namespace std;


// Adjacency Matrix of Graph
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n) Space Complexity - O(N x N)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // cin>>wt;
        adj[u][v] = 1; // assign wt in case of weighted graph
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}


//Adjacency List 
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1]; //Space Complexity : O(N)
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for directed this statement will be removed T.C= O(E)
    }
    return 0;
}


//Storing Weighted Graph in Adjacency list
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector< pair<int,int> > adj[n+1]; //Space Complexity : O(N)
    for(int i = 0; i < m; i++)
    {
        int u, v,wt;
        cin >> u >> v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt}); // for directed this statement will be removed T.C= O(E)
    }
    return 0;
}