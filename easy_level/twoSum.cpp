#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> map_index;        
        std::vector<int> indicies;
        int sum=0;
        for (int i=0; i<nums.size(); i++){
            sum = target - nums[i];
            if(map_index.find(sum) != map_index.end()){
                indicies.push_back(map_index[sum]);
                indicies.push_back(i);
                return indicies;
            }

            map_index[nums[i]] = i;
        }
        return indicies;
    } 
};


int main(){
    Solution sol;
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    auto index = sol.twoSum(nums, target);
    for (auto i : index){
        std::cout << i << std::endl;
    }
    
}