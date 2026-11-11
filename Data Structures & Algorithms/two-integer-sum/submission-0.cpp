class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        std::unordered_map<int,int> remainders;
        for(int i = 0; i < nums.size(); i++){
            auto j = remainders.find(nums[i]);
            if(j != remainders.end()){
                return {(*j).second,i};
            }
            remainders[target-nums[i]] = i;
        }
        return {0,0};    
    }
};
