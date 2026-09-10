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
    int cnt=0;

    pair<int, int> helper(TreeNode* root){
        if(root == nullptr) return {0, 0};

        auto[lsum, lcnt] = helper(root->left);
        auto [rsum, rcnt] = helper(root->right);

        int currSum = root->val + lsum + rsum;
        int currCnt = 1 + lcnt + rcnt;

        if(currSum/currCnt == root->val) cnt++;

        return {currSum, currCnt};
    }

    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return cnt;
    }
};