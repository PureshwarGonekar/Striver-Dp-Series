// interviewbit - https://www.interviewbit.com/problems/cycle-in-directed-graph/discussion/p/c-2-solutions-bfs-dfs-detailed-explanation-kahns-algorithm-for-bfs/296498/1871/


bool dfs(vector<int> adj[] , int sv , vector<bool> &visited , vector<bool> &rec_call_stack)
{
    visited[sv]=true;
    rec_call_stack[sv]=true;
   
    for(int i=0;i<adj[sv].size();i++)
    {
        int x=adj[sv][i];
        if(visited[x]==false && dfs(adj , x , visited , rec_call_stack)==true)
        {
           return true;
        }
        else
        {
            if(rec_call_stack[x]==true)
            {
                return true;
            }
        }
    }
    rec_call_stack[sv]=false;
    return false;
}

int Solution::solve(int n, vector<vector<int> > &edges) {
   
    vector<int> adj[n];
   
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0]-1;
        int v=edges[i][1]-1;
       
        if(v!=u)
        {
            adj[u].push_back(v);
        }
    }
   
    vector<bool> visited(n , false);
    vector<bool> rec_call_stack(n , false);
   
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false )
        {
           if(dfs(adj , i , visited , rec_call_stack)==true)
            return true;
        }
    }
   
    return false;
   
}


// GFG = https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
			}
		}
		return false;
	}
};