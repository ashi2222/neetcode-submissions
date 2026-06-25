class Twitter {
    int timestamp = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;  // userId -> [(time, tweetId)]
    unordered_map<int, unordered_set<int>> following;  // userId -> set of followeeIds

public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Max-heap: (timestamp, tweetId)
        priority_queue<pair<int,int>> pq;
        following[userId].insert(userId); // always see own tweets
        for (int fid : following[userId]) {
            for (auto& [t, tid] : tweets[fid]) {
                pq.push({t, tid});
            }
        }
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};