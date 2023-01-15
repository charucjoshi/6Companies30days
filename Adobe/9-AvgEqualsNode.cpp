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
    int count;
    pair<int,int> inorder(TreeNode *root){
        if(root == NULL)
            return {0,0};
        pair<int,int> left = inorder(root->left);
        pair<int,int> right = inorder(root->right);

        if((root->val + left.first+right.first)/(left.second+right.second+1) == root->val)
            count++;
        return {left.first + right.first + root->val, left.second + right.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        pair<int,int> p = inorder(root);
        return count;
    }
};