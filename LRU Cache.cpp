/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: 
get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.
The cache is initialized with a positive capacity.
Follow up:
Could you do both operations in O(1) time complexity?
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class LRUCache {
public:
    unordered_map<int,pair<int,int> > cache;
    int capacity = 0;
    int counter = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->counter = 0;
    }
    
    int get(int key) {
        _fast_;
        if(cache.find(key)!=cache.end())
        {
            cache[key].second = counter; counter+=1;
            return cache[key].first;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        _fast_;
        int minCounter = INT_MAX;
        auto it1 = 0;
        if(cache.size()<capacity)
        {
            cache[key] = make_pair(value,counter);
            counter+=1;
        }
        else
        {
        for(auto it : cache)
        {
            if(it.first==key)
            {
                cache[key].first = value;
                cache[key].second = counter; counter+=1; return;
            }
            else if(it.second.second < minCounter)
            {
                minCounter = it.second.second;
                it1 = it.first;
            }
        }
        cache.erase(it1);
        cache[key] = make_pair(value,counter); counter+=1;
        }
    }
};
