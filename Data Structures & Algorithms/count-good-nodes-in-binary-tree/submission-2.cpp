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
    //no of good nodes in tree find karna hai , if curent node se root node ke beech mai jitne bhi node hai unse or root node se current node ki value badi hai then vo wali node select karenge .
    // we will declare a maxSofar and apdate it on every recursive iteration for left anf right of current node .
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
        int maxSofar = root->val;// max value So far seen ki value root ki value set kar rahe hai kyoki root ki value negative bhi given ho sakti hai to 0 set karenge to problem hogi
        solve(root , ans , maxSofar);
        return ans.size() ;
    }
};
