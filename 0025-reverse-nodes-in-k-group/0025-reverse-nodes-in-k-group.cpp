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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Create a dummy node that points to the head. 
        // This makes it easier to handle cases where the head might change during reversal.
        ListNode* dummy = new ListNode(0, head);

        // 'groupPrev' will always point to the node *before* the start of the current group.
        // Initially, this is 'dummy', meaning the first group starts right at 'head'.
        ListNode* groupPrev = dummy; //groupPrev->next is always start of the group

        while (true) {
            // Find the k-th node from 'groupPrev'. This will be the end of the current group.
            // If we can't find k nodes, 'kth' will be nullptr, meaning there aren't enough nodes left for another full group.
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) {
                // Not enough nodes to form a complete group, so we're done.
                break;
            }

            // 'groupNext' is the node immediately after the k-th node. 
            // This is where we'll reconnect after reversing the current group.
            ListNode* groupNext = kth->next;

            // Reverse the nodes from 'groupPrev->next' up to 'kth' (inclusive).
            // We’ll use the pointer 'prev' to eventually point to the new head of the reversed segment.
            // Setting 'prev' initially to 'groupNext' allows the reversed group to link correctly  to the rest of the list after reversal.
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            // Perform the standard linked-list reversal, but stop once 'curr' hits 'groupNext'.
            while (curr != groupNext) {
                ListNode* temp = curr->next;  // temporarily store the next node
                curr->next = prev;            // reverse the pointer
                prev = curr;                  // move 'prev' forward
                curr = temp;                  // move 'curr' forward
            }

            // Now 'prev' is the first node of the reversed group (which used to be 'kth').
            // The node that was previously 'groupPrev->next' is now the last node of this reversed segment.

            // 'temp' will be used to update 'groupPrev' to the last node in the reversed group
            // (which was originally 'groupPrev->next').
            ListNode* temp = groupPrev->next;

            // Connect 'groupPrev' to the new head of the reversed segment ('kth', now pointed to by 'prev').
            groupPrev->next = kth;

            // Move 'groupPrev' to 'temp', which is now the last node of the reversed group.
            // This sets us up for the next group.
            groupPrev = temp;
        }

        // 'dummy->next' now points to the head of the fully processed list.
        return dummy->next;
    }

private:
    // Returns the k-th node starting from 'curr->next' (because 'curr' is the node 
    // *before* the group). If fewer than k nodes remain, returns nullptr.
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;  // either valid k-th node or nullptr if we ran out of nodes
    }
};
