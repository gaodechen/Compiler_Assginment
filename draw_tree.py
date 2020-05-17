'''
@Author: Gao Dechen
@LastEditors: Gao Dechen
@Description: Display ASTree
@LastEditTime: 2020-05-17 18:15:42
@Date: 2020-05-17 12:07:30
'''

from nltk.tree import Tree

str_tree = "(process(const)(var)(procedure(process(var)(statement(begin(statement(assign(expression(factor(term)))))(statement(assign(expression(factor(term)))))(statement(while(condition(expression(factor(term)))(expression(factor(term))))(statement(begin(statement(if(condition(expression(factor(term)(term)(term)))(expression(factor(term))))(statement(begin(statement(assign(expression(factor(term)))))(statement(assign(expression(factor(term)))))))))(statement(assign(expression(factor(term))(factor(term)))))))))))))(procedure(process(statement(begin(statement(assign(expression(factor(term)))))(statement(while(condition(expression(factor(term)))(expression(factor(term))))(statement(begin(statement(call))(statement(if(condition(expression(factor(term)))(expression(factor(term))))(statement(write(expression(factor(term)))))))(statement(assign(expression(factor(term))(factor(term)))))))))))))(statement(call)))"
Tree.fromstring(str_tree).draw()