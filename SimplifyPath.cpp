class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> pathStack;
        string canonicalPath;
        string token;
        while(getline(ss, token, '/')){
            if (!token.empty() && token != "."){
                if (token == ".."){
                    if(!pathStack.empty()){
                        pathStack.pop_back();
                    }
                }else{
                    pathStack.push_back(token);
                }
            }
        }
        
        if (pathStack.empty()){
            return "/";
        }
        
        for(int i = 0 ; i < pathStack.size(); i++){
            canonicalPath += ("/" + pathStack[i]);
        }
        
        return canonicalPath;
    }
};
