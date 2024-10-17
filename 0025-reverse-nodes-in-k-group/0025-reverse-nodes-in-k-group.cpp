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

    ListNode* reverseLinkedList(ListNode* head, int k) {
        int count = 0;
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(count < k) {
            ListNode* temp = current -> next;
            current->next = prev;
            prev = current;
            current = temp;
            count++;
        }
        head->next = current;
        return prev;
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current= head;
        int count = 0;
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
        while(current){
            count++;
            current =current->next;
        }

        int numOfReversals = count/k;
        current = head;
        ListNode* prev = nullptr;
        while(numOfReversals > 0){
            ListNode* newHead = reverseLinkedList(current, k);

            if(prev==nullptr) {
                head = newHead;
            } else {
                prev->next = newHead;
            }

            prev=current;
            current = prev->next;

            numOfReversals--;
        }
        return head;
    }
};