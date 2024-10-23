#include <iostream>
#include <string>
#include <unordered_map>



class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {  //using sliding window technique
        int count=0;
        int max = count;
        int inicio=0;  //start of the window
        std::unordered_map<char, int> map;
        for(size_t i=0; i < s.size(); i++){     //loop will 
            auto it =  map.find(s[i]);
            
            // if the character is already in the map and the index is greater than the start of the window
            // means that the character is in the current window

            if(it != map.end() && map[s[i]] >= inicio){ 
                inicio = map[s[i]] + 1; // moves the start of the window to the next character of the repeated one
            }

            map[s[i]] = i; //updates the character index
            count = i - inicio + 1; //we add 1 because the index starts at 0
            if (count > max) max = count;
        }
        return max;
    }
};

int main(){
    Solution sol;
    std::cout << sol.lengthOfLongestSubstring("pwwkew") << std::endl;
    return 0;
}