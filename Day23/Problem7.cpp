//Bipartite Check using BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>colors(V, -1);
        for(int i = 0; i < V; i++) {
            if(colors[i] == -1) {
                if(!bfs(i, colors, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool bfs(int node, vector<int>&colors, vector<vector<int>>&graph) {
        queue<int>q;
        q.push(node);
        colors[node] = 0;
        while(!q.empty()) {
            node = q.front();
            int col = colors[node];
            q.pop();
            for(auto it : graph[node]) {
                if(colors[it] == -1) {
                    q.push(it);
                    colors[it] = !col;
                } else {
                    if(colors[it] == col) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};