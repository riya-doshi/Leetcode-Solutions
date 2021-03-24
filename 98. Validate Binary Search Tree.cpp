/*
Recursive solution

class Solution {
public:
    bool isValidBST(TreeNode* root, long long l=-1e10, long long h = 1e10) {
        if(root==nullptr) return true;
        return (root->val>l && root->val < h) && isValidBST(root->left, l, root->val)
            && isValidBST(root->right,root->val,h);
    }
};

*/

// Iterative solution
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // here we have to confirm if all elements in the left subtree are smaller than node and not just direct left element same holds for right subtree
        
        if(!root)return true;
        TreeNode* curr = root;
        stack<TreeNode*>s;
        TreeNode* prev = NULL;
        
        while(!s.empty() || curr){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();s.pop();
            if( prev && prev->val >= curr->val){
                return false;
            }
    
            prev = curr;

            curr = curr->right;
        }
        return true;
    }
};
