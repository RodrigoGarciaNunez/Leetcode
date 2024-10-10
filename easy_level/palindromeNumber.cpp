#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string digits;
        digits += std::to_string(x);
        std::string pali;
        
        for(int i=digits.size()-1; i >= 0; i--){
            pali += digits[i];
        }

        if(digits == pali){
            return true;
        }

        return false;
    }
};


int main(){
    Solution s;
    
    std::cout << s.isPalindrome(2222222) << std::endl;
}

