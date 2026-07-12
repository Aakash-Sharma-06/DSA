class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";

        auto &vec = mp[key];

        int l = 0;
        int h = vec.size() - 1;

        string ans="";

        while(l<=h){
            int mid=l+(h-l)/2;

            if(vec[mid].first<=timestamp){
                ans=vec[mid].second;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */