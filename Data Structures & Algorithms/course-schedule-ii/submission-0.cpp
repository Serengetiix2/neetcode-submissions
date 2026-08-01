class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        deque<int> courses;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < prerequisites.size(); ++i){
            auto a = prerequisites[i][0];
            auto b = prerequisites[i][1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        for(int i = 0; i < indegree.size(); ++i){
            if (indegree[i] == 0){
                courses.push_back(i);
            }
        }
        while(!courses.empty()){
            auto cCourse = courses.front();
            courses.pop_front();
            result.push_back(cCourse);
            for(auto n : adj[cCourse]){
                --indegree[n];
                if(indegree[n] == 0) courses.push_back(n);
            }
        }

        
        if(result.size() < numCourses){
            return {};
        }else{
            return result;
        }

    }
};