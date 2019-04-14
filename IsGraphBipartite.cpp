class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> coloredNodes;
        for(int i = 0; i < graph.size(); i++){
            if (coloredNodes.count(i) == 0){ // mean not colored
                coloredNodes[i] = 0;
                stack<int> dfsStack;
                dfsStack.push(i);
                while(!dfsStack.empty()){
                    int node = dfsStack.top();
                    dfsStack.pop();
                    
                    for(int j = 0; j < graph[node].size(); j++){
                        int neighbor = graph[node][j];
                        if (coloredNodes.count(neighbor)){
                            if (coloredNodes[neighbor] == coloredNodes[node]){
                                return false;
                            }
                        }else{
                            coloredNodes[neighbor] = coloredNodes[node] == 0 ? 1 : 0;
                            dfsStack.push(neighbor);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
