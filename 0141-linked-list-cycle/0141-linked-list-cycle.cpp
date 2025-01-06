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

// class Solution {
// public:
//  //hashset approach
//     bool hasCycle(ListNode* head) {
       
//         unordered_set<ListNode*> nodeset;
//         while(head){
//             if(nodeset.count(head)){
//                 return true;
//             }
//             nodeset.insert(head);
//             head=head->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                //cycle detected
                return true;
            }
        }
        return false;
    }
};