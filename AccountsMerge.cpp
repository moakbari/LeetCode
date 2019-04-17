class Solution {
    using GraphType = unordered_map<string, unordered_set<string>>;
    
    void dfs(const string& email, GraphType& graph, set<string>& curList, unordered_set<string>& visitedEmails){
        if (curList.count(email)){
            return;
        }
        
        curList.emplace(email);
        for (unordered_set<string>::const_iterator iter = graph[email].begin(); iter != graph[email].end(); iter++){
            dfs(*iter, graph, curList, visitedEmails);
        }
        
        visitedEmails.emplace(email);
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        GraphType emailGraph;
        unordered_map<string, string> emailToNameMap;
        
        for(int i = 0; i < accounts.size(); i++){
            string name = accounts[i][0];
            for(int j = 1; j < accounts[i].size();j++){
                string email = accounts[i][j];
                emailToNameMap.emplace(email, name);
                if (j == 1){
                    if(emailGraph.count(email)){
                        continue;
                    }else{
                        emailGraph.emplace(email, unordered_set<string>());
                    }
                }else{
                    string prevEmail = accounts[i][j-1];
                    emailGraph[email].emplace(prevEmail);
                    emailGraph[prevEmail].emplace(email);
                }
            }
        }
        
        vector<set<string>> emailLists;
        unordered_set<string> visitedEmails;
        for(GraphType::const_iterator iter = emailGraph.begin(); iter != emailGraph.end(); iter++){
            set<string> curList;
            if (visitedEmails.count(iter->first) == 0){
                dfs(iter->first, emailGraph, curList, visitedEmails);
            }
            
            if (!curList.empty()){
                emailLists.push_back(curList);
            }
        }
        
        vector<vector<string>> result;
        for(int i = 0; i < emailLists.size(); i++){
            if (!emailLists[i].empty()){
                set<string>::const_iterator iter = emailLists[i].begin();
                vector<string> mergeAccount;
                mergeAccount.push_back(emailToNameMap[*iter]);
                for(;iter != emailLists[i].end(); iter++){
                    mergeAccount.push_back(*iter);
                }
                result.push_back(mergeAccount);
            }
        }
        
        return result;
    }
};
