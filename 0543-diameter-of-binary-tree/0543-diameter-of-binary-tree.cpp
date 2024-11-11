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
    int diameter(TreeNode* root, int &dm){
        if(!root) return 0;
        int lt = diameter(root->left,dm);
        int rt = diameter(root->right,dm);
        dm = max(dm,lt+rt);
        return 1+max(lt,rt);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dm =0;
        diameter(root, dm);
        return dm;
        
    }

};