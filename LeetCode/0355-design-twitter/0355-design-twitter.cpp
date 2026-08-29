class Twitter {
public:

    struct Tweet {
        int time;
        int tweetId;
    };

    struct Compare {
        bool operator()(const Tweet& a, const Tweet& b) {
            return a.time < b.time;
        }
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int timer = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<Tweet, vector<Tweet>, Compare> pq;

        // User's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Tweets of people user follows
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().tweetId);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};