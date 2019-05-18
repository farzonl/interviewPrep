struct TreeNode
{
    int m_data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data);
    ~TreeNode();
    void add(TreeNode* parent, int data);
    void add(int data);
    void remove(int data);
    void preorder(TreeNode* node);
    void preorder();
};