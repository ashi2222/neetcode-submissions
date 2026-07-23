class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val] = vec.size();
            vec.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int ind = mp[val];
            int last = vec.back();
            mp[last]=ind;

            swap(vec[ind] , last);
            vec.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ind = rand()%vec.size();
        return vec[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */