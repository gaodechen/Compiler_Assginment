/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Abstract Syntax Tree
 * @LastEditTime: 2020-05-17 12:43:55
 * @Date: 2020-04-28 09:10:20
 */

#define INC_ASTREE

#include <vector>
#include <iostream>

#ifndef INC_LEX_ITEM
#include "../lexer/lex_item.h"
#endif

class ASTree;

class ASTreeNode
{
private:
    static const int CHILDS_SIZE = 50;
    ASTreeNode *m_parent;
    ASTreeNode *m_childs[CHILDS_SIZE];
    LexItem m_value;
    int m_childs_size;
public:
    ASTreeNode();
    ASTreeNode(LexItem value);
    ASTreeNode* Append(LexItem child_value);
    void Display();
    friend ASTree;
};

class ASTree
{
private:
    ASTreeNode *m_root;
    ASTreeNode *m_cur_node;
    std::string m_str_tree;
public:
    ASTree();
    void Forward(LexItem value);
    void Forward(std::string value);
    void Backward();
    void Display();
    void DFS(ASTreeNode *cur_node);
};