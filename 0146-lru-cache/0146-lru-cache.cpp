class LRUCache {
public:
    list<pair<int,int>> li;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        auto exists=mp.find(key);
        if(exists==mp.end())
            return -1;
        li.splice(li.begin(),li,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){
            mp[key]->second=value;
            return;
        }
        if(mp.size()==capacity){
            int delKey=li.back().first;
            li.pop_back();
            mp.erase(delKey);
        }
        li.push_front({key,value});
        mp[key]=li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */