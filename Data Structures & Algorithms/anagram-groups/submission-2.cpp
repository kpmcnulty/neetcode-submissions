class Solution {
public:
    // bool isAnagram(string str, string str2){
    //     std::unordered_map<char,int> charbank;
    //     if(str.size() != str2.size()){
    //         return false;
    //     }
    //     for(char c : str){
    //         charbank[c]+=1;
    //     }
    //     for(char c : str2){
    //         if(charbank[c] > 0){
    //             charbank[c]-=1;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //need to make groups.
        std::unordered_map<string,int> group;
        vector<vector<string>> results;
        int groups_count = 0;
        for(int i = 0; i < strs.size(); i++){
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            if(!group.contains(sorted)){
                //new group
                group[sorted] = groups_count;
                results.push_back({});
                results[groups_count].push_back(strs[i]);
                groups_count++;
            }else{
                //add to group
                int index = group[sorted];
                results[index].push_back(strs[i]);
            }
        }
        return results;

    }
};
