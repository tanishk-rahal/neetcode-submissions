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
//we will use inorder traversal here as we have bst .
//inorder traversal automatically gives us sorted binary tree .
//so we will have a count , we will fist explore left side , then increment count , if count = k then that if our answer .
//then we will explore right side .
    int solve(TreeNode* root , int k , int& count , int& ans){
        if(root == nullptr){
            return 0;
        }
        solve(root->left , k , count , ans);
        count++;
        if(count == k){
            ans = root->val;
        }
        solve(root->right , k , count ,ans);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
       return solve(root , k , count , ans);

    }
};
