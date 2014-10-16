// Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root)
            return result;
        TreeNode* curNode = root;
        stack<TreeNode*> nodeList;
        while (curNode)
        {
            nodeList.push(curNode);
            curNode = curNode->left;
        }
        while (!nodeList.empty())
        {
            TreeNode* curNode = nodeList.top();
            while (curNode->right && !isHaveSearch(curNode))
            {
                insertSearch(curNode);
                curNode = curNode->right;
                while(curNode)
                {
                    nodeList.push(curNode);
                    curNode = curNode->left;
                }
                curNode = nodeList.top();
            }
            curNode = nodeList.top();
            nodeList.pop();
            result.push_back(curNode->val);
        }
        _searchList.clear();
        return result;
    }
    private:
    inline bool isHaveSearch(TreeNode* node){return _searchList.find(node) != _searchList.end();}
    inline void insertSearch(TreeNode* node){_searchList.insert(node);}
    set<TreeNode*> _searchList;
};