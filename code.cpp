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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>A;
        queue<TreeNode *>T;
        T.push(root);
        T.push(NULL);
        double sum=0;
        double node=0;
        while(!T.empty())
        {
            TreeNode *current=T.front();
            T.pop();
            if(current!=NULL){
                node++;
                sum=sum+current->val;
            }
            if(current==NULL && node!=0)
            {
                A.push_back(sum/node);
                T.push(NULL);
                sum=0;
                node=0;
           }
              if(current){  if(current->left) T.push(current->left);
                if(current->right) T.push(current->right);
                         }
        }
        return A;
    }
};
