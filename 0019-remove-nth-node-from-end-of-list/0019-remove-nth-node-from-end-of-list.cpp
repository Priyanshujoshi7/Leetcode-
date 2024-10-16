class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* temp;

        while (current) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;  // Return new head after reversing
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Reverse the list first
        ListNode* reversedHead = reverse(head);
        
        // If we need to remove the head node after reverse (nth node from end)
        if (n == 1) {
            ListNode* newHead = reversedHead->next;
            delete reversedHead;
            // Reverse again to restore the original order
            return reverse(newHead);
        }
        
        // Traverse to the nth node and remove it
        ListNode* temp = reversedHead;
        for (int i = 1; i < n - 1; ++i) {
            temp = temp->next;
        }

        // Remove the nth node by skipping it
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        // Reverse the list back to its original order
        return reverse(reversedHead);
    }
};
