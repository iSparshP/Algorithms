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
    TreeNode* reverseOddLevels(TreeNode* root) {
        DFSwithReverse(root->left, root->right, 1);
        return root;
    }
private:
    void DFSwithReverse(TreeNode* leftNode, TreeNode* rightNode, int level) {
        if (leftNode == nullptr || rightNode == nullptr) {
            return;
        }
        if (level % 2 != 0) {  
            int temp = leftNode->val; 
            leftNode->val = rightNode->val; 
            rightNode->val = temp;
        }
        DFSwithReverse(leftNode->left, rightNode->right, level + 1);
        DFSwithReverse(leftNode->right, rightNode->left, level + 1);
    }
};