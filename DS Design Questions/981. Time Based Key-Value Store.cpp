class TimeMap {
public:
    /** Initialize your data structure here. */
    
    //hash table
    
    //unordered_map<key, ordered_map<timestamp, value>>;
    //here o(logn) for getting and O(logn) for setting 
    
    //but if we see we only need to return value and not the timestamp
    // and here we have a notion of time i.e it will only come in increasing order
    //here we can do binary search to find largest element which is less equal than this
    
    // unordered_map< key, vector<pair<timestamp, value>> >
    // in this O(logn) for getting and O(1) for setting
    
    
    unordered_map<string, vector<pair<int, string>>> mp;
    
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
        
    }
    
    string get(string key, int timestamp) {
        //binary search on v for largest <=timestamp
        
        vector<pair<int, string>> v = mp[key]; 
        
        int low=0, high=v.size()-1;
        int mid;
        while(low<high){
            mid= low + (high-low+1)/2;
            
            if(v[mid].first > timestamp){
                high=mid-1;
            }
            else {
                low = mid;
            }
        }
        //sanity check
        if(v[low].first <= timestamp){
            return v[low].second;
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
