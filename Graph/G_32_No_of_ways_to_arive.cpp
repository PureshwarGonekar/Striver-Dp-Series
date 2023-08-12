//Problem - https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long, int>,
                       vector<pair<long, int>>, greater<pair<long, int>>> pq;

        vector<long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while (!pq.empty())
        {
            long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};