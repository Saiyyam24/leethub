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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        {
            return nullptr;
        }
        if(key<root->val)
        {
            root->left = deleteNode(root->left,key); 
        }
        else if(key>root->val)
        {
            root->right = deleteNode(root->right,key);
        }
        else
        {
            if(root->left==nullptr && root->right==nullptr)
            {
                delete root;
                return NULL;
            }
            if(root->left==nullptr || root->right==nullptr)
            {

                return (root->left?root->left:root->right);
            }
            TreeNode* temp = root->right;
            while(temp->left)
            {
                temp=temp->left;
                
            }
            root->val=temp->val;
            root->right = deleteNode(root->right,temp->val);

        }
        return root;
    }
};
