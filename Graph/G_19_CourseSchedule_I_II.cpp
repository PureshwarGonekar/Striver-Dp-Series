// GFG - https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    int V=N;
	    int indegree[V] = {0};
	    
	    vector<int> adj[V];
	    
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
    
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree
    
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == N) return true;
        return false;
	}
};

//GFG - https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        int V=n;
        int indegree[V] = {0};
        
        vector<int> adj[V];
	    
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
    
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree
    
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        return topo;
    }
};



/**********************************************Leetcode******************************************************************/
//https://leetcode.com/problems/course-schedule-ii/submissions/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;
        vector<int> topo, indegree(V);
        
        vector<int> adj[V];
	    
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
	    }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree
    
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size()!=V) return {};
        return topo;
    }
};