// Leetcode
// 16-jan-2024
// Implement the RandomizedSet class:

//     RandomizedSet() Initializes the RandomizedSet object.
//     bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
//     bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
//     int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

// You must implement the functions of the class such that each function works in average O(1) time complexity.

class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> m;
public:
    RandomizedSet() {
        
    }

    bool search(int val){
        if(m.find(val) != m.end()){
            return true;
        }else{
            return false;
        }
    }
    
    bool insert(int val) {
        if(search(val)){
            return false;
        }

        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)){
            return false;
        }

        auto it = m.find(val);
        v[it->second] = v.back();
        v.pop_back();
        m[v[it->second]] = it->second;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */