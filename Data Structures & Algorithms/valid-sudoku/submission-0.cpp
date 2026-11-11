class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool seen_rows[9][9]={};
        bool seen_cols[9][9]={};
        bool seen_boxes[9][9]={};
        //how to get from r,c to box index? 
        //0,1,2
        //3,4,5
        //6,7,8 
        //row 8,col 5 -> 2
        //row0, col 0 = 0
        //row 5, col 5 = 4
        //(row//3) * 3 + (col//3)
        for(int r = 0; r<9;r++){
            for(int c = 0; c<9; c++){
                if(board[r][c]!='.'){
                    int num = board[r][c] - '0';
                    
                    bool& seen_in_row = seen_rows[r][num-1];
                    bool& seen_in_col = seen_cols[c][num-1];
                    int box_id = (r/3)*3 + (c/3);
                    bool& seen_in_box = seen_boxes[box_id][num-1];
                    if(seen_in_row || seen_in_col || seen_in_box){
                        return false;
                    }else{
                        seen_in_row = true;
                        seen_in_col = true;
                        seen_in_box = true;
                    }
                }
            }
        }
        return true;

    }
};
