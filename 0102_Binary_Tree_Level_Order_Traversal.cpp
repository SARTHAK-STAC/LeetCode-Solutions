#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/*
LeetCode 102 - Binary Tree Level Order Traversal

Approach:
- Use Breadth-First Search (BFS) with a queue.
- Process one level at a time.
- Store each level in a separate vector.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};

int main() {

    // Creating the tree:
    //        3
    //       / \
    //      9   20
    //         /  \
    //        15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);

    for (auto level : ans) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}