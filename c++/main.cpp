#include "linkedList.hpp"
//#include <iostream>
#include "tree.h"

int main() {
    TreeNode* tree = new TreeNode(10);
    tree->add(6);
    tree->add(8);
    tree->add(4);
    tree->add(15);
    tree->add(13);
    tree->add(17);
    tree->preorder();
}