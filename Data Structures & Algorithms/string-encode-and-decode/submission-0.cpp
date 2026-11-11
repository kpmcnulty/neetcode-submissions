class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string s : strs){
            encoded_string += std::to_string(s.size());
            encoded_string += "|";
            encoded_string += s;

        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        string lengthstr = "";
        int length;
        string current = "";
        vector<string> strs;
        bool onword = false;
        for(char c : s){
            if(!onword){
                if(c != '|'){
                    lengthstr+=c;
                }else{
                    length = std::stoi(lengthstr);
                    if(length==0){
                        strs.push_back("");
                        lengthstr="";

                    }else{
                        onword=true;
                    }
                }
            }else{
                //onword
                    current+=c;
                    if(current.size() >= length){
                        //finished word
                        onword = false;
                        strs.push_back(current);
                        current = "";
                        lengthstr = ""; 
                    }
                    
                }
            }
        
        return strs;
    }
};
