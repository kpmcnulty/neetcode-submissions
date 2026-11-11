class Solution {
public:

    bool hasDuplicate(vector<int>& nums) {
        std:unordered_map<int,bool> seen;
        for(auto& n : nums){
            if(!seen[n]){
                seen[n]=true;
            }else{
                return true;
            }
        }    
        return false;
    }
};