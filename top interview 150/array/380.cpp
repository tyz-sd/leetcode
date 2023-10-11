class RandomizedSet {
public:
    vector<int> v;
    map<int, int> index_v;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(index_v.find(val) != index_v.end()) return false;

        v.push_back(val);
        index_v.insert(make_pair(val, v.size()-1));
        return true;
    }
    
    bool remove(int val) {
        if(index_v.find(val) == index_v.end()) return false;
        
        index_v[v[v.size()-1]] = index_v[val];
        v[index_v[val]] = v[v.size()-1];
        v.pop_back();
        index_v.erase(val);
        return true;
    }
    
    int getRandom() {
        int a = rand() % v.size();
        return v[a];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */