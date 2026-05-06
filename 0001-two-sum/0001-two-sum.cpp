#include <unordered_map> 
#include <algorithm>
using std::string;
using std::find;
using std::distance;

using std::unordered_map;
class Solution {


public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> result(2,0);
        int index=0;
        int number=0;
        std::vector<int>::iterator nums_it;
        //ashmap[0] = nums[0];
        
        for(int i =0; i < nums.size(); i++){
            
            nums_it = find(nums.begin(), nums.end(), target- nums[i]);
            
            if(nums_it != nums.end()){
                index = distance(nums.begin(), nums_it);
                number = *nums_it;
                hashmap[number] = index;
                result[0] = hashmap[number];
                result[1] = i; 

                if (index != i){
                    break;
                }    
            }
                   
        }

        return  result;
    }
}; 