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
    void reorderList(ListNode* head) {
        //find midway point
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr; // so that the second list starts from null
        ListNode* curr=slow->next;
       
        //reverse the second list
        while(curr){
            ListNode* temp =curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        //ending the first list from head till end of slow
        slow->next=nullptr;
        ListNode* first= head;
        ListNode* second= prev;
        //merge two lists
        while(second){
            //cause second would be left in the end so running loop till second
           ListNode* tempf =first->next;
           ListNode* temps =second->next; 
           first->next=second;
           second->next =tempf;
           first=tempf;
           second=temps;
        }

    }
};