#include <unordered_map>
#include <string>
#include <iterator>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_size=1;
        int size=1;
        const char * left = s.c_str();
        
        if(*left == '\0'){
            return 0;
        }

        const char * right = left+1; 

        unordered_map<char, const char *> letters_map;
        
        letters_map[*left] = left;


        while(*left != '\0' && *right != '\0'){
            
            
            if(letters_map.find(*right) == letters_map.end()){
                letters_map[*right] = right;
                ++size;
                ++right;
                
            }
            
            else{
                ++left;
                right = left+1;
                size=1;
                
                letters_map.clear();
                letters_map[*left] = left;
            }

            longest_size = (size >= longest_size) ? size : longest_size;
        }

        return longest_size;
    }
};