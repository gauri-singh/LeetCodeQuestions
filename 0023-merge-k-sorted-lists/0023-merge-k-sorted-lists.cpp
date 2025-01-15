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
//  //heap soultion
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size()<=0){
//             return nullptr;
//         }
//         auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
//         priority_queue<ListNode*, vector<ListNode*>, decltype (cmp)> minheap(cmp);
//         //adding all first pointers to minheap
//         for(auto list: lists){
//             if(list!=nullptr)
//                 minheap.push(list);
//         }
//         ListNode* dummy = new ListNode(0);
//         ListNode* head = dummy;
//         while(!minheap.empty()){
//             ListNode* curr = minheap.top();
//             minheap.pop();
//             head->next=curr;
//             if(curr && curr->next)
//                 minheap.push(curr->next);
//             head= head->next;
//         }
//         return dummy->next;
//     }
// };
 //divide and conquer soultion
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<=0){
            return nullptr;
        }
        while(lists.size()>1){
            //since linked lists are getting merged and then replaced in the lists vector
            vector<ListNode*> merged;
            for(int i=0;i<lists.size();i=i+2){
                //taking 2 lists at a time
                ListNode* l1= lists[i];
                ListNode* l2=  (i+1<lists.size()) ?lists[i+1]:nullptr;
                merged.push_back(mergeLists(l1,l2));
            }
            lists=merged;
        }
        return lists[0];
    }
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                head->next=l1;
                l1=l1->next;
            }else{
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        if(l1){
            head->next=l1;
        }else if(l2){
            head->next=l2;
        }
        return dummy->next;
    }
};