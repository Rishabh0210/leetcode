//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3358/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    map<int, int> index_map;
    int size;
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index_map.find(val) != index_map.end())
            return false;
        v.push_back(val);
        index_map[val] = size;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index_map.find(val) == index_map.end())
            return false;
        int i = index_map[val];
        v[i] = v[size - 1];
        index_map[v[size - 1]] = i;
        
        v.pop_back();
        index_map.erase(val);
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand() % size;
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */