class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> count;
        if(s.size() != t.size()){
            return false;
        }
        for(char c : s){
            count[c]+=1;
        }
        for(char c : t){
            if(count[c]<=0){
                return false;
            }else{
                count[c]-=1;
            }
        }
    return true;
    }
};
