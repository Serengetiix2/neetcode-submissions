class Twitter {
public:
    //tuple time, tweetid, userid, usertweetindex
    
    int timestamp = 0;
    unordered_map<int ,vector<pair<int, int>>>userTweets; //timestamp, tweet id
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, unordered_set<int>> followers;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(timestamp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<pair<int,int>,int,int>> userfeed;
        vector<int> result;
        for(int followeeId : following[userId]){
            if(!userTweets[followeeId].empty() && userId != followeeId){
                pair<int, int> mostRecent = userTweets[followeeId].back();
                int idx = userTweets[followeeId].size() -1;
                userfeed.push({mostRecent, followeeId, idx});
            }
        }
        if(!userTweets[userId].empty()){
                pair<int, int> mostRecent = userTweets[userId].back();
                int idx = userTweets[userId].size() -1;
                userfeed.push({mostRecent, userId, idx});
        }
        while(result.size() < 10 && !userfeed.empty()){
                auto[tweet, srcId, idx] = userfeed.top();
                result.push_back(tweet.second);
                userfeed.pop();
                if(!userTweets[srcId].empty() && idx - 1 >= 0){
                    pair<int, int> mostRecent = userTweets[srcId][idx - 1];
                    userfeed.push({mostRecent, srcId, idx -1});
                }
            }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        followers[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        followers[followeeId].erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */