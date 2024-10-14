#include <list>
#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, ListNode *&sum)
    {

        //ListNode *sum = nullptr;
        //ListNode *l1_rev = reverseList(l1);
        //ListNode *l2_rev = reverseList(l2);
        // normalize(l1_rev, l2_rev);

        //printList(l1_rev);
        //printList(l2_rev);

        addListNodes(l1, l2, sum);

        ListNode *sum_rev = reverseList(sum);
        // printList(sum);
        return sum_rev;
    }

    void addListNodes(ListNode *l1, ListNode *l2, ListNode *&sum)
    {
        int x = 0;
        int y = 0;
        int suma = 0;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {   
            x = (l1 != nullptr) ? l1->val : 0;
            y = (l2 != nullptr) ? l2->val : 0;

            suma = x + y + carry;
            sum = new ListNode(suma % 10, sum);
            carry = (suma >= 10) ? suma / 10 : 0;
            

            //printList(sum);    
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        } 
        if (carry > 0)
            {
                sum = new ListNode(carry, sum);
            }
    }

    ListNode *reverseList(ListNode *l)
    {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (l != nullptr)
        {
            next = l->next;
            l->next = prev;
            prev = l;
            l = next;
        }
        return prev;
    }

    void printList(ListNode *l)
    {
        while (l != nullptr)
        {
            std::cout << l->val;
            ;
            l = l->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Solution sol;

    ListNode *l1 = new ListNode(9, new ListNode(4, new ListNode(3, new ListNode(9))));
    ListNode *l2 = new ListNode(9, new ListNode(6, new ListNode(9)));

    ListNode *solu = nullptr;

    solu = sol.addTwoNumbers(l1, l2, solu);

    ListNode *solu_rev = sol.reverseList(solu);

    sol.printList(solu_rev);

    return 0;
}
