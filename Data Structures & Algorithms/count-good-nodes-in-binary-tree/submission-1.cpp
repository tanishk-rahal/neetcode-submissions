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
    void solve(TreeNode* root , vector<int>&ans , int maxSofar){
        if(root==nullptr){
            return ;
        }
        if( root->val >= maxSofar){
            ans.push_back(root->val);
            maxSofar = root->val;
        }
       
        solve(root->right , ans , maxSofar);
        solve(root->left , ans , maxSofar);
    }
    int goodNodes(TreeNode* root) {
        vector<int>ans;
        int maxSofar = root->val;
        solve(root , ans , maxSofar);
        return ans.size() ;
    }
};
