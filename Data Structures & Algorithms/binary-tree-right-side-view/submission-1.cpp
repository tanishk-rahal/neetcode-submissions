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
    //we will apply level order sort ;
    // in the inner loop in which we are running loop till size of queue , if we have the size size -1th element ,means last element of that level of tree, so we add last element of that level to our ans array 
    //as it will be the lement which can be seen from last size , if right side does not have any elemnt , the left side element will be out last element of the array 
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left ) q.push(node->left);
                if(node->right ) q.push(node->right);
                if(i==size-1){
                    ans.push_back(node->val);
                }
                
            }
        }
        return ans;
    }
};
