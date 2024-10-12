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

        ListNode * sum = new ListNode();

        //printList(l1);
        //printList(l2);

        normalize(l1, l2);

        printList(l1);
        printList(l2);

        //ListNode * l1_rev = reverseList(l1);
        //ListNode * l2_rev = reverseList(l2);

        //printList(l1_rev);
        //printList(l2_rev);

        addListNodes(l1, l2, sum);

        printList(sum);

        //ListNode num1 = listNode2int(l1);
        //ListNode num2 = listNode2int(l2);
                
        //sum = num1 + num2;
        //std::cout << num1 << num2<< std::endl;
        
        //return int2listNode(sum);
        return sum->next;
    }

    void addListNodes(ListNode * l1, ListNode * l2, ListNode *& sum){

        //ListNode * sum = new ListNode(0);
        ListNode * aux = sum;
        ListNode * aux1 = l1;
        ListNode * aux2 = l2;

        std::cout << "l1: " << l1->val << std::endl;
        std::cout << "l2: " << l2->val << std::endl;

        int carry = 0;
        int x = 0;
        int y = 0;
        int s = 0;

        while(l1 != nullptr || l2 != nullptr){
            x = (l1 != nullptr) ? l1->val : 0;  //si el l1/2 es diferente de nullptr, entonces x = lx>val, sino x = 0
            y = (l2 != nullptr) ? l2->val : 0;
            s = x + y + carry;
            carry = s / 10;
            aux->next = new ListNode(s % 10);
            aux = aux->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        //return sum->next;       
    }

    void normalize(ListNode *& l1, ListNode *& l2){

        int diff = abs(countNodes(l1) - countNodes(l2));

        if(countNodes(l1) > countNodes(l2)){
            //std::cout << "l1 > l2" << std::endl;
            for(int i = 0; i < diff; i++){
                l2 = new ListNode(0, l2);
            }
        }
        else{
            //std::cout << "l1 < l2" << std::endl;
            for(int i = 0; i < diff; i++){
                l1 = new ListNode(0, l1);
            }
        }

        //printList(l1);

    }

    int countNodes(ListNode * l){
        int count = 0;
        while(l != nullptr){
            count++;
            l = l->next;
        }

        return count;
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

    long listNode2int(ListNode * l){
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
            std::cout << l->val;;
            l = l->next;
        }
        std::cout << std::endl;
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


