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
    void preorder(TreeNode* root, vector<int> &result){
        if(root!=NULL){
            result.push_back(root->val);
            preorder(root->left,result);
            preorder(root->right,result);
        }
    }

    void flatten(TreeNode* root) {
        if(!root) return ;
        vector<int> result;
        preorder(root,result);

        TreeNode* curr = root;
        curr->left = NULL;
        for(int i=1;i<result.size();i++){
            TreeNode* temp = new TreeNode(result[i]);
            curr->right = temp;
            curr = temp;
        }
        
        
    }
};