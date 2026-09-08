class Twitter {
public:
    int tweetnumber=0;

    struct triplet {
        int tn;
        int tid;
        int uid;

        bool operator<(const triplet& other) const {
            return tn < other.tn;
            } //this is basically to tell pq to compare by using tn 
    };

    priority_queue <triplet> pq;
    unordered_map<int, unordered_set<int>> followMap;


    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetnumber++;
        triplet tweet = {tweetnumber, tweetId, userId};
        pq.push(tweet);

    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> result;
        auto temp = pq; //dont destroy tweets

        while(result.size()<10 && !temp.empty()){
            triplet t = temp.top();
            if((t.uid==userId) || following(t.uid, userId)){
                result.push_back(t.tid);
            }
            temp.pop();}
        return result;        
    }
    
    void follow(int followerId, int followeeId) {
        //hashmap: for each userId , store its followers
        //userId = followeeid

        int userId = followeeId;

        followMap[userId].insert(followerId);

    }
    
    void unfollow(int followerId, int followeeId) {
        int userId = followeeId;
        followMap[userId].erase(followerId);
    }

    bool following( int friendId, int userId){
        return followMap[friendId].count(userId); //if friend has userId as one of its followers
    }
};
