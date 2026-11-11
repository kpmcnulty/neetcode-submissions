class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parens;
        std::vector charlistopen = {'(','{', '['};
        //std::vector charlistclose = {')','}',']'};
        std::unordered_map<char,char> closetoopen= {{')','('},{']','['},{'}','{'}};
        for(char c : s){
            if(closetoopen.count(c)){
                //close bracket
                if(!parens.empty()){
                    if(parens.top() != closetoopen[c]){
                        return false;
                    }else{
                        parens.pop();
                    }
                    }else return false;
            }else  parens.push(c);
        }
            
        
        if(parens.size() == 0)
        return true;
        return false;
    }
};
