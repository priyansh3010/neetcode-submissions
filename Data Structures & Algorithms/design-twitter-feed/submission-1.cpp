class Twitter {
public:

    struct CompareInternalId {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Places larger tweetId at the top
        }
    };

    Twitter() {
        
    }

    // have a hashMap for all tweets made by a user
    unordered_map<int, vector<vector<int>>> tweets; // {userId : [[tweet1, 1], [tweet2, 2], ...]}
    
    // have a hashmap with the key being userid and value being a set of userIds to see who the user follows
    unordered_map<int, unordered_set<int>> followerTracker;
    int internalId = 1;

    void postTweet(int userId, int tweetId) {
        vector<int> tweet = {tweetId, internalId};
        internalId++;
        tweets[userId].push_back(tweet);

        if (tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>, vector<vector<int>>, CompareInternalId> recentTweets;
        vector<int> newsFeed;

        // add user's most recent tweet
        if (tweets.find(userId) != tweets.end()) {
            int index = tweets[userId].size() - 1;
            vector<int> tweet = tweets[userId][index]; // last index
            tweet.push_back(userId);
            tweet.push_back(index);

            recentTweets.push(tweet);
        }

        // add user's followings most recent tweets
        for (auto fId : followerTracker[userId]) {
            if (tweets.find(fId) != tweets.end()) {
                int index = tweets[fId].size() - 1;
                vector<int> tweet = tweets[fId][index]; // last index
                tweet.push_back(fId);
                tweet.push_back(index);

                recentTweets.push(tweet);
            }
        }

        while (!recentTweets.empty() && newsFeed.size() < 10) {
            vector<int> tweet = recentTweets.top();
            recentTweets.pop();

            newsFeed.push_back(tweet[0]); // tweetId
            int nextIndex = tweet[3] - 1;
            if (nextIndex >= 0) {
                int fId = tweet[2];
                tweet = tweets[fId][nextIndex];
                tweet.push_back(fId);
                tweet.push_back(nextIndex);

                recentTweets.push(tweet);
            }
        }
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        followerTracker[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        followerTracker[followerId].erase(followeeId);
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