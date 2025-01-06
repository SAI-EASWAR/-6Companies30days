class Solution {
public:
    #define P pair<int,int>
    void dijkstra(int n, unordered_map<int,vector<P>>& adj, vector<int>& result,int S){

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0,S});
        fill(result.begin(), result.end(),INT_MAX);

        result[S] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& p : adj[node]){
                int adjNode = p.first;
                int dist = p.second;

                if(d + dist < result[adjNode]){
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }
    int getCityWithFewReachable(int n, const vector<vector<int>>& shortPathMatrix, int distanceThreshold){

        int ans = -1;
        int toReturn = INT_MAX;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(i !=j && shortPathMatrix[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= toReturn){
                toReturn = count;
                ans = i;
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<P>> adj;

        vector<vector<int>> shortPathMatrix(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            shortPathMatrix[i][i] = 0;
        }

        for(const auto& edge : edges){
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adj[start].push_back({end, weight});
            adj[end].push_back({start, weight});
        }
        for(int i=0;i<n;i++){
            dijkstra(n, adj, shortPathMatrix[i], i);
        }

        return getCityWithFewReachable(n, shortPathMatrix, distanceThreshold);
    }
};