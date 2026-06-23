
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == s.size() || numRows == 1) return s;
        
        string::iterator s_it = s.begin();

        vector<string> string_per_row(numRows,"");

        size_t current_row = 0;
        bool up_down = false;

        while(s_it < s.end()){
            
            string_per_row[current_row] += *s_it; 
            ++s_it;

            up_down = (current_row == numRows-1 || current_row == 0 )? !up_down : up_down;
            current_row = (up_down) ? current_row+1: current_row-1;
        }

        string result = "";

        for(auto &s : string_per_row){
            result += s;
        }   

        return result;   
    }


};

/*
    string result = "";
        
        size_t max_delta = (numRows >= 3) ? numRows+floor(numRows/2) : numRows;

        size_t delta = (numRows > 3) ? max_delta : 2;

        int current_row = 0;

        while(current_row <= numRows-1 && column < s.end()){

            result += *column;
            column = (current_row == 0 || current_row == numRows-1) ? column+max_delta: column+delta;


            if ((column) >= s.end()){
                ++row;
                column = row;
                ++current_row;

            }

            if(numRows <= 3) continue;

            delta = (delta == numRows-(current_row-1)) ? floor(numRows/2) : numRows-(current_row-1);

        
        }   

        return result;
*/


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna