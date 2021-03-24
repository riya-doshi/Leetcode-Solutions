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
