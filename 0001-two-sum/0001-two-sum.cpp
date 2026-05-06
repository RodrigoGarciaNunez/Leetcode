#include <unordered_map> 
#include <algorithm>
#include <iterator>
#include <vector>

using std::find;
using std::unordered_map;
using std::vector;
class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        vector<int> result(2,0);
        int second_argument = 0;
        unordered_map<int, int>::iterator iterator_nums_map;
        size_t iterator_current_index;
        
        
        for(int i =0; i < nums.size(); i++){
            
            second_argument = target - nums[i];
            
            iterator_nums_map = nums_map.find(second_argument);            

            if(iterator_nums_map != nums_map.end()){
                result[0] = i;
                result[1] = iterator_nums_map->second ;
                return result;  

            }

            nums_map[nums[i]] = i;  
        }
        return  result;
    }
}; 