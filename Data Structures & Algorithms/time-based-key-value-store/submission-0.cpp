class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(tMap.find(key) != tMap.end() && !(tMap[key].empty())){
            auto& set = tMap[key];
            int left = 0;
            int right = set.size() - 1;
            int result = -1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(set[mid].first <= timestamp){
                    result = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return result == -1 ? "" : set[result].second;
            
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */