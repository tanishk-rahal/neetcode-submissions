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
//here we will check tht all values of left subtree must be less than node value and right subtree must be greater than node value ;
// here we ill set a range for each node , initially for root the range is -infinity to +infinity , 
// for each node we pass a range value , its leat possible value can be till minVlaue with is -infinity initially , and its highest value can be till maxValue (for left subtree it can be parent node value)

    bool isValid(TreeNode* root , int minValue , int maxValue){
        if(root == nullptr){
            return true;
        }
        if(root->val <= minValue || root->val >= maxValue ){//we check for condition if our current node value does not lie in correct range than we will return false
            return false ;
        }
        //if both return true function return true ;
        
        return isValid(root->left , minValue , root->val )&&
               isValid(root->right , root->val , maxValue );
        
    }
    bool isValidBST(TreeNode* root) {
        return  isValid(root , INT_MIN , INT_MAX);
        
    }
};
