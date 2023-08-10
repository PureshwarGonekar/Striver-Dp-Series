//Problem- https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort

//Time Complexity: O( 4*N*M * log( N*M) ) {log(N*M) for insertion-deletion operations in a priority queue}
//Space Complexity: O( N*M ) 

int MinimumEffort(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>>
        pq;

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};


    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return diff;
        
        for (int i = 0; i < 4; i++)
        {
            int newr = row + dr[i];
            int newc = col + dc[i];

 
            if (newr >= 0 && newc >= 0 && newr < n && newc < m)
            {
                // Effort can be calculated as the max value of differences 
                // between the heights of the node and its adjacent nodes.
                int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                // If the calculated effort is less than the prev value
                // we update as we need the min effort.
                if (newEffort < dist[newr][newc])
                {
                    dist[newr][newc] = newEffort;
                    pq.push({newEffort, {newr, newc}});
                }
            }
        }
    }
    return 0;  // if unreachable
}