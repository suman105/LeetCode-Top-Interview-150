class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        
        // Min-Heap storing {sum, index in nums1, index in nums2}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        
        // Step 1: Insert the first k elements from nums1 combined with nums2[0]
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }
        
        // Step 2: Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            
            // Add to result
            result.push_back({nums1[i], nums2[j]});
            
            // If there's another element in nums2 to pair with nums1[i], add it
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j+1], i, j+1);
            }
        }
        
        return result;
    }
};
