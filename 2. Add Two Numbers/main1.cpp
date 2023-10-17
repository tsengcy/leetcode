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
        ListNode* nodeStart = new ListNode();
        ListNode* nodeCur = nodeStart;
        bool carry = false;

        while(l1 != NULL && l2 != NULL)
        {
            int val = l1->val + l2->val;
            if(carry) {val++;}
            nodeCur->val = (int)val%10;
            if(val >= 10) {carry = true;}
            else{carry = false;}

            l1 = l1->next;
            l2 = l2->next;
            if(l1 == NULL || l2 == NULL){break;}
            ListNode* newNode = new ListNode();
            nodeCur->next = newNode;
            nodeCur = newNode;
        }
        if(l1 != NULL || l2 != NULL)
        {
            ListNode* newNode = new ListNode();
            nodeCur->next = newNode;
            nodeCur = newNode;
            while(l1 != NULL)
            {
                int val = l1->val;
                if(carry){val++;}
                nodeCur->val = (int)val%10;
                if(val >= 10) {carry = true;}
                else{carry = false;}
                l1 = l1->next;
                if(l1 == NULL){break;}
                ListNode* newNode = new ListNode();
                nodeCur->next = newNode;
                nodeCur = newNode;
            }
            while(l2 != NULL)
            {
                int val = l2->val;
                if(carry){val++;}
                nodeCur->val = (int)val%10;
                if(val >= 10) {carry = true;}
                else{carry = false;}
                l2 = l2->next;
                if(l2 == NULL){break;}
                ListNode* newNode = new ListNode();
                nodeCur->next = newNode;
                nodeCur = newNode;
            }
        }
        if(carry)
        {
            ListNode* newNode = new ListNode(1);
            nodeCur->next = newNode;
        }   
        return nodeStart;
    }
};