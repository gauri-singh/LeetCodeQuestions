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

//Iterative approach
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;  ListNode* curr=head;
//         while(curr){
//             ListNode* temp=curr->next;
//             curr->next=prev;
//             prev= curr;
//             curr= temp;
//         }
//         return prev;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* newHead =head; //current node
        if(head->next){
            //head has a next which isnt a null ptr 
            //there is still nodes left to reverse

            newHead = reverseList(head->next);
            head->next->next=head; // reversing the link
        }
        head->next =nullptr; //for each "subproblem" head is the first in list and therefore its next should be set to null in reversed case

        return newHead;
    }
};
