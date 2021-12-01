/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    if(!root->left && !root->right)
        return root;
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->right);
    invertTree(root->left);
    return root;
}