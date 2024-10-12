#include <list>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        long long sum;

        printList(l1);
        printList(l2);    

        long long num1 = listNode2int(l1);
        long long num2 = listNode2int(l2);
                
        sum = num1 + num2;
        std::cout << num1 << num2<< std::endl;
        
        return int2listNode(sum);

    }

    ListNode * reverseList(ListNode * l){
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        while(l != nullptr){
            next = l->next;
            l->next = prev;
            prev = l;
            l = next;
        }
        return prev;
    }

    long long listNode2int(ListNode * l){
        long long num = 0;
        long long factor = 1;
        while(l != nullptr){
            num += (l->val * factor);
            factor *= 10;
            l = l->next;
        }
        return num;
    }

    ListNode* int2listNode(long long sum){
        ListNode * l = new ListNode(0);
        ListNode * aux = l;

        if(sum == 0){
            return l;
        }

        while(sum > 0){
            aux->next = new ListNode(sum % 10);
            aux = aux->next;
            sum /= 10;
        }
        return l->next;
    }

    void printList(ListNode * l){
        while(l != nullptr){
            std::cout << l->val << std::endl;
            l = l->next;
        }
    }
};


int main(){
    Solution sol;

    ListNode*  l1 = new ListNode(2, new ListNode(4, new ListNode(9))); 
    ListNode*  l2 = new ListNode(5, new ListNode(2, new ListNode(1, new ListNode(2))));

    ListNode *solu;

    solu = sol.addTwoNumbers(l1, l2);

    ListNode * solu_rev = sol.reverseList(solu);
    
    sol.printList(solu_rev);

    return 0;
}

