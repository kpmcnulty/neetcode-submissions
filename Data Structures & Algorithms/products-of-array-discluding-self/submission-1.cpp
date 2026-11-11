class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productLeft(nums.size(),1);
        vector<int> productRight(nums.size(),1);
        vector<int> ans;
        productLeft[0] = 1;
        productRight[nums.size()-1] = 1;

        
        for(int i = nums.size()-1; i>0; i--){
            productRight[i-1] = nums[i] * productRight[i];
         }
        for(int i = 0; i<nums.size(); i++){
            if(i<nums.size()-1){
                productLeft[i+1] = nums[i] * productLeft[i];
            }
            ans.push_back(productLeft[i] * productRight[i]);
        }
        
        return ans;

    }
};
