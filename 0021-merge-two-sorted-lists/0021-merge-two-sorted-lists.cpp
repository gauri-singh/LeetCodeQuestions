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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0,nullptr); // anchor for inserting and having the head, is a non pointer type;
        ListNode* node =dummy; // our iterator , pointing at start right now
        while(list1 && list2){
            if(list1->val <list2->val){
                node->next=list1; //point to the list1's current node
                list1=list1->next; //move current pointer of list1 to next
            }else{
                  node->next=list2; //point to the list2's current node
                list2=list2->next; //move current pointer of list2 to next
            }
            node=node->next; // i++;
        }
        if(list1){
            node->next=list1;
        }else if(list2){
            node->next=list2;
        }
        return dummy->next; // return anchor and since it is non pointer, we have to do it like this
    }
};