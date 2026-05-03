class TimeMap {
private:
    string find(vector<pair<string,int>>& valStore, int currTimestamp){
        int start = 0;
        int end = valStore.size()-1;
        int ansIdx = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(valStore[mid].second == currTimestamp){
                return valStore[mid].first;
            }

            if(valStore[mid].second > currTimestamp){
                end = mid - 1;
            } else {
                ansIdx = mid;
                start = mid + 1;
            }
        }

        return ansIdx == -1 ? "" : valStore[ansIdx].first;
    }
public:
    unordered_map<string, vector<pair<string,int>>> store;

    TimeMap() {
        // []map[string]string

        // map[string][]pair(int, string)
        store.clear();
    } 
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }

        return find(store[key], timestamp);
    }
};
