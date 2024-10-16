
// struct Node {
//     int val;
//     Node *next;
//     Node() : val(0), next(nullptr) {}
//     Node(int x) : val(x), next(nullptr) {}
//     Node(int x, Node *next) : val(x), next(next) {}
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next == NULL)
        {
            return head;
        }
        ListNode* slow =head;
        ListNode* fast = head;
        
        //making slow reach middle element
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reversing second part
        ListNode* current = slow;
        ListNode* prev = nullptr;
        ListNode* temp;
        while(current!= nullptr){
            temp = current->next;
            current->next= prev;
            prev= current;
            current = temp;
        }
        //checking palindrome
        ListNode* first = head;
        ListNode* second = prev;
        while(second != nullptr){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;  
    }
};