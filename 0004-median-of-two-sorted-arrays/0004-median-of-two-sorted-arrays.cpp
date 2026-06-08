class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

       
        size_t total_size = nums1.size() + nums2.size();
        int middle = (total_size % 2 !=0 ) ? std::floor(total_size/2): (total_size/2) -1;

        std::cerr << "middle: "<< middle << std::endl;
        
        if(nums1.size()== 0 || nums2.size()==0){
            double result=0;
            if(total_size <= 1){
                result = static_cast<double>(nums1.size()>0) ? nums1[0]: nums2[0];
                return result;
            }

            vector<int> * aux = (nums1.size()== 0 ) ? &nums2: &nums1; 

            if(total_size%2 != 0){
                result= static_cast<double>((*aux)[middle]);  
                return result;
            }
            else{
                result = static_cast<double>((*aux)[middle] + (*aux)[middle+1])/2; 
                return result;
            }

        }

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();


        std::pair<size_t, double> overall_index={0,0};
        
        int it1_value = 0;
        int it2_value = 0;

        while(it1 != nums1.end() || it2 != nums2.end()){

            it1_value = (it1 == nums1.end()) ? *it2+1: *it1;
            it2_value = (it2== nums2.end()) ? *it1+1: *it2;
            std::cerr << "it1: " << it1_value << " it2: "<< it2_value <<  "\n";

            if (it1 != nums1.end() && it1_value < it2_value){
                std::cerr << *it1 << "\n";
                overall_index.second=*it1;
                it1 = (it1 == nums1.end()) ? it1: ++it1;
            }
            else if(it2 != nums2.end()){
                std::cerr << *it2 << "\n";
                overall_index.second=*it2;
                it2 = (it2 == nums2.end()) ? it2: ++it2;
            }

            if(overall_index.first == middle){
                
                if(total_size%2 != 0){ 
                    std::cerr << "imparpar" << std::endl;
                    return static_cast<double>(overall_index.second);
                }
                else{
                    /*
                    std::cerr << "par" << std::endl;
                    if(it1 == nums1.end()){
                        std::cerr << "par t1" << std::endl;
                        return static_cast<double>((overall_index.second + *it2)/2); 
                    }
                    else{
                        std::cerr << "par t2" << std::endl;
                        return static_cast<double>((overall_index.second + *it1)/2); 
                    }
                    */  

                    it1_value = (it1 == nums1.end()) ? *it2+1: *it1;
                    it2_value = (it2== nums2.end()) ? *it1+1: *it2;

                    std::cerr << "par normal" << std::endl;
                    std::cerr << "it1: " << it1_value << " it2: "<< it2_value <<  "\n";
                    int second_mid = (it1_value < it2_value) ? it1_value : it2_value;
                    return static_cast<double>((overall_index.second + second_mid)/2);
                }
            }
            ++(overall_index.first);

        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna