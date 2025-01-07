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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if we have the L pointer at 0th dummy node and right pointer at nth node from starting, then the offset would always be of 'n'
        //therefore when the R pointer is at end of list, L would be at n-1 position(added dummy so we are not at nth node instead) , and we can use it to remove the nth node from back.
        ListNode* dummy = new ListNode(0,head); // value =0, and dummy->next = head
        ListNode* L=dummy;
        ListNode* R = head;
        //setting R at nth node from start
        while(n>0){
            R=R->next;
            n--;
        }
        while(R){
            L=L->next;
            R=R->next;
        }
        //our nth node is L->next therefore lets cut the link
        L->next=L->next->next;
        return dummy->next; // doing this instead of head, because in case of a single element, head would still hold that value
    }
};