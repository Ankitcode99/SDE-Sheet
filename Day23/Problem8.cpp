//Bipartite check using DFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>colors(V, -1);
        for(int i = 0; i < V; i++) {
            if(colors[i] == -1) {
            	colors[i] = 0;
                if(!dfs(i, colors, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node, vector<int>&colors, vector<vector<int>>&graph) {
        cout<<node<<endl;
        for(auto it : graph[node]) {
            if(colors[it] == -1) {
                colors[it] = 1 - colors[node];
                if(!dfs(it, colors, graph)) {
                    return false;
                }    
            } else {
                if(colors[it] == colors[node]) {
                    return false;
                }
            }
        }
        return true;
    }
};