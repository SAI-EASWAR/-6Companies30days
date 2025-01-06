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
    int result = INT_MAX;

public:
    int time(TreeNode* root, int start){
        if(!root)
        return 0;

        int r = time(root->left,start);
        int l = time(root->right,start);

        if(root->val == start){
            result = max(r,l);
            return -1;
        }
        else if(r >= 0 and l >= 0){
            return max(r,l) + 1;
        }
        else{
            result = max(result,abs(r) + abs(l) );
            return min(r,l) - 1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        time(root,start);
        return result;
    }
};