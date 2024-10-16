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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        // Initialize two pointers to traverse the two lists
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        // Traverse both lists, switching to the other list when reaching the end
        while (ptrA != ptrB) {
            ptrA = (ptrA == NULL) ? headB : ptrA->next;
            ptrB = (ptrB == NULL) ? headA : ptrB->next;
        }
        
        // Return the intersection point or NULL if there's no intersection
        return ptrA;
    }
};