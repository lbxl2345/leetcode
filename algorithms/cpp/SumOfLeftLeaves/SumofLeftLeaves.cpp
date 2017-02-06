//我的方法
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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        struct TreeNode *p = root;
        if(!p)
            return 0;
        if(p->left)
            sumOfLeft(p->left);
        if(p->right)
            sumOfRight(p->right);
        return sum;
    }
    int sumOfLeft(TreeNode* left){
        if(left->left)
            sumOfLeft(left->left);
        if(left->right)
            sumOfRight(left->right);
        if(!left->left && !left->right)
            sum += left->val;
        return sum;
    }
    int sumOfRight(TreeNode* right){
        if(right->left)
            sumOfLeft(right->left);
        if(right->right)
            sumOfRight(right->right);
        return sum;
    }
};
//更好的方法
//三句的递归
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
