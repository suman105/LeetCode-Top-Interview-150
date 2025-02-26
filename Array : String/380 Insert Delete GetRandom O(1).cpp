class RandomizedSet {
    private:
        vector<int> nums;
        unordered_map<int, int> indexMap;
    
    public:
        RandomizedSet() {}
    
        bool insert(int val) {
            if (indexMap.find(val) != indexMap.end()) 
                return false;
    
            nums.push_back(val);
            indexMap[val] = nums.size() - 1;
            return true;
        }
    
        bool remove(int val) {
            if (indexMap.find(val) == indexMap.end()) 
                return false;
            
            int lastElement = nums.back();
            int idx = indexMap[val];
    
            nums[idx] = lastElement;
            indexMap[lastElement] = idx;
    
            nums.pop_back();
            indexMap.erase(val); 
    
            return true;
        }
    
        int getRandom() {
            int randomIndex = rand() % nums.size();
            return nums[randomIndex];
        }
    };