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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> one, two;
        inorder(root1,one);
        inorder(root2,two);
        int i = 0; 
        int j = 0;
        vector<int> ans;
        while(i < one.size() && j < two.size())
        {
            if(one[i] < two[j])
            {
                ans.push_back(one[i]);
                i++;
            }
            else{
                ans.push_back(two[j]);
                j++;
            }
        }

        while(i < one.size())
        {
            ans.push_back(one[i]);
            i++;
        }

        while(j < two.size())
        {
            ans.push_back(two[j]);
            j++;
        }
        return ans;
    }
};