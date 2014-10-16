// Binary Tree Level Order Traversal II 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {        
        vector<vector<int> > result, ret;
        if (!root)
            return result;
        queue<TreeNode*> parentQueue;
        parentQueue.push(root);
        do
        {
            queue<TreeNode* > childQueue;
            vector<int> curList;
            while(!parentQueue.empty())
            {
                TreeNode* node = parentQueue.front();
                parentQueue.pop();
                curList.push_back(node->val);
                if (node->left)
                    childQueue.push(node->left);
                if (node->right)
                    childQueue.push(node->right);
            }
            result.push_back(curList);
            parentQueue = childQueue;
        }while(!parentQueue.empty());
        for (int i = result.size() - 1; i >= 0; --i)
        {
            ret.push_back(result[i]);
        }        
        return ret;
    }
};