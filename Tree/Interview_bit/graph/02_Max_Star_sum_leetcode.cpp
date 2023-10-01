class Solution {
public:
    void bfs(int src, vector <int> adj[], vector<int>& vis,vector<int>& vals,int k,int &ans){
        vis[src] = 1; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 

            int sum= vals[node];
            vector<int> temp = adj[node];
            vector<int> Arr;
            for(int i=0;i<temp.size(); i++){
                Arr.push_back(vals[temp[i]]);
            }
            sort(Arr.begin(),Arr.end(),greater<int>());
            int K=0;

            for(int i=0; i<Arr.size(); i++){
                if(K==k) break;
                if(sum < Arr[i]+sum){
                    sum+= Arr[i];
                    K++;
                } 
                
            }
            ans = max(ans, sum);
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector <int> adj[n];
        for(int i=0; i< edges.size(); i++){
            int u= edges[i][0], v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);

        int ans= INT_MIN;
        for(int V=0; V<n; V++){
            if(!vis[V]){
                bfs(V,adj,vis,vals,k,ans);
            }
        }
        
        return ans; 

    }
};


//without using queue
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(k==0){
            int maxi=INT_MIN;
            for(int n:vals)maxi=max(maxi,n);
            return maxi;
        }
        int n=vals.size();
        map<int,vector<pair<int,int>> > adj;
        for(auto p:edges){
            adj[p[0]].push_back({vals[p[1]], p[1]});
            adj[p[1]].push_back({vals[p[0]], p[0],});
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sort(adj[i].rbegin(),adj[i].rend());
            int kk=k;
            int sum=vals[i];
            maxi=max(maxi,sum);
            for(auto p:adj[i]){
                sum+=p.first;
                kk--;
                maxi=max(maxi,sum);
                if(kk==0 || p.first<0)break;
            }
        }
        return maxi;
    }
};