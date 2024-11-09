#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median=0;
        map<int, int> mapa;  //valor, veces (clave, valor)

        int lim = max(nums1.size(), nums2.size());
        int size = nums1.size() + nums2.size();
        //int i=0;
        for(int i=0; i<lim; i++){
            if(i<nums1.size()) mapa[nums1[i]]++;
            if(i<nums2.size()) mapa[nums2[i]]++;
        }

         for(auto it = mapa.begin(); it != mapa.end(); it++){
            cout << it->first << " " << it->second << endl;
        }

        //int size = mapa.size();
        if(size%2 == 0){
            auto it = mapa.begin();
            //double extra = 0;
            for(int i=0; i<size/2; i++){
                //cout << it->first <<" " << i << endl;
                if(it->second>1) {
                    it->second--;
                    //i--;
                }
                else it++;
            }
            auto itaux = it;
            auto it2 = (it->second > 1 )?it:--itaux;
            cout << it->first << " " << it2->first << endl;
            median = (it->first + it2->first)/2.0;
        }
        else{
            auto it = mapa.begin();
            for(int i=0; i<size/2; i++){
                if(it->second>1) {
                    it->second--;
                    //i--;
                }
                else it++;
            }
            median = it->first;
        }

        //cout << "Median: " << median << endl;
        // for(auto it = mapa.begin(); it != mapa.end(); it++){
        //     cout << it->first << " " << it->second << endl;
        // }

        return median;      
    }
};

int main(){

    Solution sol;
    vector<int> nums1 = {2,2,4,4};
    vector<int> nums2 = {2,2,4,4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}