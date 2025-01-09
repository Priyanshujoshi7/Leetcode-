class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr; 

        ListNode* temp = head; 
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                // Skip the duplicate node
                temp->next = temp->next->next;
            } else {
                // Move to the next distinct node
                temp = temp->next;
            }
        }
        return head;
    }
};
