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
        ListNode* dummy = new ListNode(0);
        ListNode* curr =dummy;
        int v1,v2,val,sum,carry=0;
        while(l1 || l2 || carry!=0){
            v1 = (l1!=nullptr)? l1->val : 0;
            v2 = (l2!=nullptr)? l2->val : 0;
            sum = v1+v2+carry;
            carry=sum/10;
            val=sum%10;
            curr->next = new ListNode(val);
            curr= curr->next; // iterating result pointer

            l1 = (l1!=nullptr)?l1->next:nullptr;
            l2 = (l2!=nullptr)?l2->next:nullptr; // iterating the original list pointers

        }
        return dummy->next;
    }
};