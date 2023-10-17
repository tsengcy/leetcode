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
        ListNode* nodeReturn = l1;
        bool carry = false;
        if(l1==NULL)
        {
            l1 = l2;
            l2 = NULL;
        }
        while(l1!=NULL)
        {
            int val = 0;
            if(l2 != NULL){val = l1->val + l2->val + carry;}
            else{val = l1->val + carry;}
            
            if(val >= 10){carry = true;}
            else{carry = false;}
            l1->val = val%10;

            if(l1->next==NULL && l2==NULL)
            {
                if(carry)
                {
                    l1->next = new ListNode(1);
                    l1 = l1->next;
                }
                break;
            }
            if(l1->next==NULL && l2->next==NULL)
            {
                if(carry)
                {
                    l1->next = new ListNode(1);
                    l1 = l1->next;
                }
                break;
            }
            if(l1->next==NULL)
            {
                l1->next = l2->next;
                l1 = l1->next;
                l2 = NULL;
            }
            else
            {
                l1 = l1->next;
                if(l2!=NULL){l2 = l2->next;}
            }
        }
        return nodeReturn;
    }
};