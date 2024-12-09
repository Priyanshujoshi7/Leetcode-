class Solution {
public:
    int solve(TreeNode* root, int &count, int prev) {
        if (root == NULL) {
            return count;
        }
        
        if (root->val >= prev) {
            count++;
        }
        
        // Update prev based on the current node's value
        prev = max(prev, root->val);
        
        solve(root->left, count, prev);
        solve(root->right, count, prev);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0, prev = root->val; // Initialize prev with the root's value.
        return solve(root, count, prev);
    }
};
