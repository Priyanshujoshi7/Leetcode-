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
    int height(TreeNode* root){
        if(!root) return 0;
        int ltHeight = height(root->left);
        if(ltHeight==-1) return -1;
        int rtHeight = height(root->right);
        if(rtHeight==-1) return -1;
        if (abs(ltHeight-rtHeight)>1){
            return -1;
        }
        return max(ltHeight,rtHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
   
    }
    
};