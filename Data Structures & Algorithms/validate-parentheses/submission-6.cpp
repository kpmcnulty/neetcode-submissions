class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parens;
        std::vector charlistopen = {'(','{', '['};
        std::vector charlistclose = {')','}',']'};
        std::unordered_map<char,char> closetoopen= {{')','('},{']','['},{'}','{'}};
        for(char c : s){
            if(std::find(charlistopen.begin(),charlistopen.end(),c)!=charlistopen.end()){
                parens.push(c);
            }
            else if(std::find(charlistclose.begin(),charlistclose.end(),c)!=charlistclose.end()){
                if(!parens.empty()){
                    if(parens.top() != closetoopen[c]){
                        return false;
                    }else{
                        parens.pop();
                    }
                }else{return false;}
            }
            
        }
        if(parens.size() == 0)
        return true;
        else return false;
    }
};
