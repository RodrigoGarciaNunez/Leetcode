/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ** current_node_l1 = &l1;  // apuntan al apuntador de cada lista
        ListNode ** current_node_l2 = &l2;  
        ListNode * result_list_head = nullptr;
        ListNode ** result_list_it = &result_list_head;


        int sum = 0;
        int carry = 0;
        int arg1=0;
        int arg2=0;
        int i = 0;

        //mientras que el nodo al que apuntan (por eso se desreferencia) no sea nullptr y ya no haya más acarreo

        while((*current_node_l1) != nullptr || (*current_node_l2) != nullptr || carry){
                    
                    arg1 = ((*current_node_l1) != nullptr) ? (*current_node_l1)->val : 0;
                    arg2 = ((*current_node_l2) != nullptr) ? (*current_node_l2)->val : 0;
                    
                    sum = arg1 + arg2 + carry;
                    carry = 0;
                    
                    if (sum > 9){
                        sum %= 10;
                        carry = 1;
                    }

                    *result_list_it = new ListNode(sum);
                    result_list_it = &((*result_list_it)->next);
                    
                    current_node_l1 = ((*current_node_l1) != nullptr) ? &((*current_node_l1)->next) : current_node_l1; 
                    current_node_l2 = ((*current_node_l2) != nullptr) ? &((*current_node_l2)->next) : current_node_l2; 
        }
        
        return result_list_head;      
    }
};