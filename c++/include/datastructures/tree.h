#ifndef __TREE_H__
#define __TREE_H__

struct TreeNode
{
    int m_data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data);
    ~TreeNode();
    void add(TreeNode* parent, int data);
    void add(int data);
    TreeNode* remove(TreeNode* root, int value,bool isRlestSucc=true);
    void remove(int data);
    void preorder(TreeNode* node);
    void preorder();
    void sumCmp(int &evenSum, int &oddSum);
    void sumCmp(TreeNode* node, int level, int &evenSum, int &oddSum);
};
#endif //__TREE_H__