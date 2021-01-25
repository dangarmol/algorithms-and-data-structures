class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> neededSet; // Value, index
        for (size_t i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];
            if (neededSet.find(nums[i]) != neededSet.end()) {
                vector<int> result;
                result.push_back(neededSet[needed]);
                result.push_back(i);
                return result;
            } else {
                neededSet.insert(make_pair(target - nums[i], i));
            }
        }
    
        return nums; // There should always be a solution
    }
};