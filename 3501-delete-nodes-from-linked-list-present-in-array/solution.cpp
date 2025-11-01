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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Build a hash set of values to remove for O(1) lookup
        unordered_set<int> toDelete(nums.begin(), nums.end());

        // Use a stack-allocated dummy node to simplify removals (no need to delete it)
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = &dummy;

        // Traverse and unlink nodes whose value is in toDelete.
        // IMPORTANT: do NOT call delete on the removed nodes here — the caller/harness manages that memory.
        while (cur->next != nullptr) {
            if (toDelete.count(cur->next->val)) {
                // unlink the node by skipping it
                cur->next = cur->next->next;
                // DO NOT delete the removed node here
            } else {
                cur = cur->next;
            }
        }

        // Return the new head (dummy.next). Do not delete dummy.
        return dummy.next;
    }
};

