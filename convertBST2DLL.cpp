struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
private:
    pair<TreeNode*, TreeNode*> convertBSTToDLLHelper(TreeNode*root, TreeNode* prev, TreeNode* next){
    if(root == nullptr) return make_pair(nullptr, nullptr);
    
    pair<TreeNode*, TreeNode*> left = convertBSTToDLLHelper(root->left, nullptr, root);
    pair<TreeNode*, TreeNode*> right = convertBSTToDLLHelper(root->right, root, next);
    
    root->left = (left.second == nullptr) ? prev : left.second;
    root->right = (right.first == nullptr) ? next : right.first;
    return make_pair((left.first == nullptr) ? root : left.first, (right.second == nullptr) ? root : right.second);
    }
public:
    TreeNode* convertBSTToDLL(TreeNode* root){
        return convertBSTToDLLHelper(root, nullptr, nullptr).first;
    }
/* tuple version
    tuple<TreeNode*, TreeNode*> convertBSTToDLLHelper(TreeNode*root, TreeNode* prev, TreeNode* next){
        if(root == nullptr) return make_tuple(nullptr, nullptr);
        TreeNode *leftL, *leftR, *rightL, *rightR;
        tie(leftL, leftR) = convertBSTToDLLHelper(root->left, nullptr, root);
        tie(rightL, rightR) = convertBSTToDLLHelper(root->right, root, next);
        
        root->left = (leftR == nullptr) ? prev : leftR;
        root->right = (rightL == nullptr) ? next : rightL;
        return make_tuple((leftL == nullptr) ? root : leftL, (rightR == nullptr) ? root : rightR);
    }
    TreeNode* convertBSTToDLL(TreeNode* root){
        return get<0>(convertBSTToDLLHelper(root, nullptr, nullptr));
    }
*/
};
