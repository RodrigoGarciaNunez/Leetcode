#include <list>
#include <iostream>
#include <vector>


class Solution {
public:
    std::list<int>* addTwoNumbers(std::list<int>* l1, std::list<int>* l2) {

        int sum;

        int num1 = list2int_reverse(l1);
        int num2 = list2int_reverse(l2);
        
        sum = num1 + num2;

        return int2list(&sum);

    }

    int list2int_reverse(std::list<int> * l){
        int num = 0;
        int factor = 1;
        for(auto i = l->begin(); i!=l->end(); i++){
            num += (*i * factor);
            factor *= 10;
        }
        return num;
    }

    std::list<int>* int2list(int * sum){
        std::list<int> * l = new std::list<int>;
        while(*sum > 0){
            l->push_back(*sum % 10);
            *sum /= 10;
        }
        return l;
    }

};

int main(){
    Solution sol;

    std::list<int>  l1 = {2,4,3};
    std::list<int>  l2 = {5,6,4};

    std::list<int> solu;

    solu = *sol.addTwoNumbers(&l1, &l2);
    
    for (auto i: solu){
        std::cout << i << std::endl;

    }

    return 0;
}


