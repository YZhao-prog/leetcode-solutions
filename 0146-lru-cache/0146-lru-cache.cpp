class LRUCache {
private:
    list<pair<int, int>> cache_list;
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;
    int max_sz;
public:
    LRUCache(int capacity): max_sz(capacity) {}
    
    int get(int key) {
        if (cache_map.count(key) == 0) {
            return -1;
        }
        auto it = cache_map[key];
        int val = it->second;
        cache_list.erase(it);
        cache_list.push_front({key, val});
        cache_map[key] = cache_list.begin();
        return val;
    }
    
    void put(int key, int value) {
        if (cache_map.count(key) != 0) {
            auto it = cache_map[key];
            cache_list.erase(it);
            cache_list.push_front({key, value});
            cache_map[key] = cache_list.begin();
            return;
        }
        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
        if (cache_map.size() > max_sz) {
            int eraseKey = cache_list.back().first;
            cache_map.erase(eraseKey);
            cache_list.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */