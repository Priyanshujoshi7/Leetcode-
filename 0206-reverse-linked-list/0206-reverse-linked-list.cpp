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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* temp;
        if(head && head->next){
            while(current){
                temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }
            return prev;      
        } else{
            return head;
        }        
        
        
    }
};