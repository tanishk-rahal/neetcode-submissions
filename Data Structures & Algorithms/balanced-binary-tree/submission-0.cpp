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
    int isHeight(TreeNode* root){
         if(root == nullptr){
        return 0;
      }
        int left = isHeight(root->left);
        int right = isHeight(root->right);
        return max(left , right) +1;

    }
    bool isBalanced(TreeNode* root) {
      if(root == nullptr){
        return true;
      }
      int lf = isHeight(root->left);
      int rh = isHeight(root->right);
      if(abs(lf-rh) > 1){
         return false;
         }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
      if(!left || !right ) return false;

      return true ;
    }
};
