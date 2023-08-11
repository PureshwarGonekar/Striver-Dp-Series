//Problem - https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops


class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Creating Adjacenct List
        vector<pair<int, int>> adj[n + 1];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        /* priority_queue<pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>>
        pq;
        // Don't require pq because it unncessary takes extra time for storing in a heap (logn) and also giving wrong ans in some test cases like 
            5 5
            0 1 1
            0 2 5
            1 2 1
            2 3 1
            3 4 1
            0
            4
            2
        */
    
        queue<pair<int, pair<int, int>> > q;
    
        vector<int> Mincost(n, 1e9);
        Mincost[src] = 0;
        q.push({src, {0, -1}}); // node price stop
    
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int price = it.second.first;
            int stops = it.second.second;
    
            
            for (auto it: adj[node] )
            {
                int adjNode = it.first;
                int actPrice = it.second;

                int tprice = price + actPrice;
                int tstops= stops+1;

                if (tstops <= K && Mincost[adjNode]> tprice)
                {
                    Mincost[adjNode]=tprice ;
                    q.push({adjNode,{tprice,tstops}});
                }
            }
        }
        if(Mincost[dst] != 1e9) return Mincost[dst];
        return -1;  // if unreachable
    }
};