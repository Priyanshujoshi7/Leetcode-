
struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next == NULL)
        {
            return head;
        }
        stack<int> st;
        ListNode* temp =head;
        //pushing into the stack
        while(temp!= NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        //comparing
        while(temp!= NULL){
            if(temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};