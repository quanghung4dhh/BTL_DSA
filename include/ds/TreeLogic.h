// File: include/ds/n_ary_tree.h
#ifndef N_ARY_TREE_H
#define N_ARY_TREE_H

#include <string>
#include "core/common_types.h" 

// Khai báo hàm (Prototypes) - Không có phần thân {}
Node* createNode(std::string name, std::string value);
void addChild(Node* parent, Node* child);
Node* findChildByName(Node* parent, std::string name);
void freeTree(Node* root);
bool removeChild(Node* parent, std::string childName);

#endif