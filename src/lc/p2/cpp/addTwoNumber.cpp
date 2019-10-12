#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ret = new ListNode(0);
        ListNode * p = ret;
        int e1, e2, carry(0), s;

        while(l1 != NULL || l2 != NULL || carry>0){
            p -> next = new ListNode(0);
            p = p -> next;

            e1 = (l1 == NULL)? 0 : l1 -> val;
            e2 = (l2 == NULL)? 0 : l2 -> val;
            s = e1 + e2 + carry;
            p->val = s%10;
            carry = (int)(s/10);

            l1 = (l1 == NULL)? NULL: l1 -> next;
            l2 = (l2 == NULL)? NULL: l2 -> next;
        }

        p = ret;
        ret = ret -> next;
        delete p;
        return ret;
    }
};