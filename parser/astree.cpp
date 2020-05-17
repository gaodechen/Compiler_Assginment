/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Abstract Syntax Tree
 * @LastEditTime: 2020-05-17 13:13:42
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
    m_str_tree = "";
}

void ASTree::Forward(LexItem value)
{
    m_cur_node = m_cur_node->Append(value);
    m_str_tree += '(' + value.GetStrType() + "-" + value.GetToken();
}

void ASTree::Forward(std::string value)
{
    m_cur_node = m_cur_node->Append(LexItem());
    m_str_tree += '(' + value;
}

void ASTree::Backward()
{
    m_cur_node = m_cur_node->m_parent;
    m_str_tree += ')';
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
    // DFS(m_root);
    std::cout << m_str_tree << std::endl;
}