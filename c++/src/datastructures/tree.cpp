#include "tree.h"
#include <iostream>

    TreeNode::TreeNode(int data) : 
    m_data(data), 
    left(nullptr), 
    right(nullptr) {}
    
    TreeNode::~TreeNode() {
        if (left) {
            delete left;
        }
        if(right) {
            delete right;
        }
    }

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
    TreeNode* rightLeftMost(TreeNode* node) {
        if(node == nullptr) {
            return nullptr;
        }
        TreeNode* curr = node->right; 

        /* loop down to find the leftmost leaf */
        while (curr && curr->left != nullptr) {
            curr = curr->left; 
        }
        return curr; 
    }
    TreeNode* leftRightMost(TreeNode* node) {
        if(node == nullptr) {
            return nullptr;
        }
        TreeNode* curr = node->left; 

        /* loop down to find the leftmost leaf */
        while (curr && curr->right != nullptr) {
            curr = curr->right; 
        }
        return curr; 
    } 

    TreeNode* TreeNode::remove(TreeNode* root, int value, bool isRlestSucc) {
        // base case 
        if (root == NULL) { return root; }
    
        // If the data to be deleted is smaller
        // then it lies in left subtree
        if (value < root->m_data) {
            root->left = remove(root->left, value); 
    
        // If the data to be deleted is greater
        // then it lies in right subtree 
        } else if (value > root->m_data) {
            root->right = remove(root->right, value); 
    
        // we found the data to delete
        } else { 
            // node with no children
            if (root->left == nullptr && root->right == nullptr) { 
                delete root;
                root = nullptr;
            // node with only one child on the right
            } else if (root->left == nullptr) { 
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            // node with only one child on the left
            } else if (root->right == nullptr) { 
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            // node with two children
            } else {
                if(isRlestSucc) {
                    TreeNode* temp = rightLeftMost(root); 
                    root->m_data = temp->m_data; 
                    root->right = remove(root->right, temp->m_data);
                } else {
                    // get the largest on the left subtree
                    TreeNode* temp = leftRightMost(root); 
                    root->m_data = temp->m_data; 
                    root->left = remove(root->left, temp->m_data);
                }
            }
        } 
        return root; 
    }
    void TreeNode::remove(int data)
    {
        remove(this, data);
    }

void TreeNode::preorder()
{
    preorder(this);
    std::cout << "\n";
}
void TreeNode::preorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    std::cout << node->m_data << " ";
    preorder(node->left);
    preorder(node->right);
}

void TreeNode::sumCmp(int &evenSum, int &oddSum) {
    sumCmp(this, 0, evenSum, oddSum);
}

void TreeNode::sumCmp(TreeNode* node, int level, int &evenSum, int &oddSum) {
    if(node == nullptr) {
        return;
    }
    if(level %2 == 0) {
        evenSum += node->m_data;
    } else {
        oddSum += node->m_data;
    }
    
    sumCmp(node->left,level+1, evenSum, oddSum);
    sumCmp(node->right,level+1,evenSum, oddSum);
}