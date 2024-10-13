/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // next node ki value node mein daali
        node->val = node->next->val;
        // node ko next to next element ki traf point krwaya
        node->next = node->next->next;
        
    }
    
};