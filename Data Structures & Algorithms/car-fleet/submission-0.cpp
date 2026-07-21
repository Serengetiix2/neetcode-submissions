class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleetCount = 1;
        vector<pair<int,int>> cars;
        stack<double> fleet;

        for(int i = 0; i < position.size(); ++i){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first > b.first;});

        for(int i = 0; i < cars.size(); ++i){
            auto time = ((target - cars[i].first) / double(cars[i].second));
            if(!fleet.empty()){
                if(time > fleet.top()){
                    ++fleetCount;
                }else if(time <= fleet.top()){
                    continue;
                }
                
            }
            fleet.push(time);

        }
        
    return fleetCount;
    }
};
