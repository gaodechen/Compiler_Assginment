/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Abstract Syntax Tree
 * @LastEditTime: 2020-04-28 21:14:53
 * @Date: 2020-04-28 09:10:18
 */

#include "../parser/astree.h"

ASTreeNode::ASTreeNode()
{
    m_childs_size = 0;
}

ASTreeNode::ASTreeNode(LexItem value)
{
    m_value = value;
    m_childs_size = 0;
}

// Add child nodes
ASTreeNode* ASTreeNode::Append(LexItem child_value)
{
    ASTreeNode *child = new ASTreeNode(child_value);
    child->m_parent = this;
    m_childs[m_childs_size++] = child;
    return child;
}

void ASTreeNode::Display()
{
    std::cout << m_value;
}

ASTree::ASTree()
{
    m_root = new ASTreeNode();
    m_root->m_parent = m_root;
    m_cur_node = m_root;
}

void ASTree::Forward(LexItem value)
{
    m_cur_node = m_cur_node->Append(value);
}

void ASTree::Backward()
{
    m_cur_node = m_cur_node->m_parent;
}

void ASTree::DFS(ASTreeNode *cur_node)
{
    cur_node->Display();
    for (int i = 0; i < (cur_node->m_childs_size); i++)
    {
        DFS(cur_node->m_childs[i]);
    }
}

void ASTree::Display()
{
    DFS(m_root);
}