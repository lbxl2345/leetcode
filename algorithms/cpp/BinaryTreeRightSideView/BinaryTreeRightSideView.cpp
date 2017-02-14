/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> answer;
    int count = 0;
    int depth = 0;
    vector<int> rightSideView(TreeNode* root) {
            depth++;
            if(!root)
                return answer;
            if(depth > count){
                answer.push_back(root->val);
                count++;
            }
            if(root->right)
                rightSideView(root->right);
            if(root->left)
                rightSideView(root->left);
            depth--;
            return answer;
    }
};
