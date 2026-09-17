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
    bool isSameTree(TreeNode* p, TreeNode* q){
          if(p==nullptr && q == nullptr){
            return true;//check if both null
        }
        else if(p == nullptr || q == nullptr){
            return false ;//check if one null and not other 
        }
        if(p->val != q ->val){
            return false ;//check there value at that node
        }
        return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);//pass same function for left and right subtree , of both the tree simultaneously 
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == nullptr){//if root = null , i.e we have reached the end while searching and same value subroot not found
            return false ;
        }
         else if( subroot == nullptr){//if subroot = null that can we a subroot of any tree 
            return true ;
        }
        

         if(root->val == subroot->val){
            if(isSameTree(root , subroot)){
                return true;
            }
         }
         bool left = isSubtree(root->left , subroot);
         bool right = isSubtree(root->right , subroot);
       return left || right;
    }
};
