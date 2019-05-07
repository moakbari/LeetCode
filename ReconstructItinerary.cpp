class Solution {
    using RouteType = unordered_map<string, multiset<string>>; 
    void findItineraryRecursive(const string& src, vector<string>& itinery, RouteType& routes){
        while(!routes[src].empty()){
            multiset<string>::iterator iter = routes[src].begin();
            string dest = *iter;
            routes[src].erase(iter);
            findItineraryRecursive(dest, itinery, routes);
        }
        
        itinery.push_back(src);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> itinery;
        
        if(tickets.size() == 0){
            return itinery;
        }
        
        RouteType routes;
        for_each(tickets.begin(), tickets.end(), [&routes](vector<string>& p){
            routes[p.front()].emplace(p.back());
        });
        
        string src = "JFK";
        findItineraryRecursive(src, itinery, routes);
        
        reverse(itinery.begin(), itinery.end());
        return itinery;
    }
};
