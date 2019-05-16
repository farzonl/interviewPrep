#include "tree.h"
#include <iostream>

    TreeNode::TreeNode(int data) : 
    m_data(data), 
    left(nullptr), 
    right(nullptr) {}
    
    void TreeNode::add(TreeNode* parent, int data)
    {
        if(parent == nullptr)
        {
            return;
        }

        if(parent->m_data > data)
        {
            if(parent->left == nullptr)
            {
                parent->left = new TreeNode(data);
                return;
            }
            else
            {
                add(parent->left, data);
            }
        }
        else
        {
            if(parent->right == nullptr)
            {
                parent->right = new TreeNode(data);
                return;
            }
            else
            {
                add(parent->right, data);
            }
        }
    }

    void TreeNode::add(int data)
    {
        add(this, data);
    }
    void TreeNode::remove(int data)
    {

    }

void TreeNode::preorder()
{
    preorder(this);
}
void TreeNode::preorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    std::cout << node->m_data << std::endl;
    preorder(node->left);
    preorder(node->right);
}