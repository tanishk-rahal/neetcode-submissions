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
    bool isValid(TreeNode* root , int minValue , int maxValue){
        if(root == nullptr){
            return true;
        }
        if(root->val <= minValue || root->val >= maxValue ){
            return false ;
        }
        return isValid(root->left , minValue , root->val )&&
               isValid(root->right , root->val , maxValue );
        
    }
    bool isValidBST(TreeNode* root) {
        return  isValid(root , INT_MIN , INT_MAX);
        
    }
};
