/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxValue(TreeNode *root)
    {
        if (root == nullptr)
            return INT_MIN;
        return max({root->val,
                    maxValue(root->left),
                    maxValue(root->right)});
    }
    int minValue(TreeNode *root){
        if (root == nullptr)
            return INT_MAX;
        return min({root->val,
                    minValue(root->left),
                    minValue(root->right)});
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        if (root->left != nullptr && maxValue(root->left) >= root->val)
            return false;

        
        if (root->right != nullptr && minValue(root->right) <= root->val)
            return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }

};