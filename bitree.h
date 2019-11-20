//
// Created by Asus on 2019/11/6.
//
#include <iostream>

using namespace std;

#ifndef ERCHASHU_BITREE_H
#define ERCHASHU_BITREE_H

struct node {
//    状态码
//若为1则表示已赋值为空
//若为2表示已赋值不为空
//若为0表示未赋值
    int lstate;
    int rstate;
    node *lchild;
    node *rchild;
    char content;
    node *parent;
};

class bitree {
public:
    bitree();


//    对树进行建立
    node *create_tree();

//    先序遍历---------------------------------------------------------

//    对数进行遍历
    int ergodic_first(node *p);

//      遍历左子树
    int first_visit_left(node *&p, int &i);

//    返回根节点
    int first_visit_back(node *&p, int &i);

    //遍历右子树
    int first_visit_right(node *&p, int &i);

//    ---------------------------------------------------------------------------

//中序遍历-----------------------------------------------------------------
    //    对数进行遍历
    int ergodic_middle(node *p);

//      遍历左子树
    int middle_visit_left(node *&p, int &i);

//    返回根节点
    int middle_visit_back(node *&p, int &i);

    //遍历右子树
    int middle_visit_right(node *&p, int &i);

//-----------------------------------------------------------------------

//后序遍历-----------------------------------------------------------------

    //    对数进行遍历
    int ergodic_after(node *p);

//      遍历左子树
    int after_visit_left(node *&p, int &i);

//    返回根节点
    int after_visit_back(node *&p, int &i);

    //遍历右子树
    int after_visit_right(node *&p, int &i);

//-----------------------------------------------------------------------

//按中序次序输出二叉树中各结点的值及其所对应的层次数
    int set_middle_layer(node *p);

//      遍历左子树
    int middle_layer_left(node *&p, int &i);

//    返回根节点
    int middle_layer_back(node *&p, int &i);

    //遍历右子树
    int middle_layer_right(node *&p, int &i);

//------------------------------------------------------------

//二叉树的高度-------------------------------------------
    //    对数进行遍历
    int bitree_height(node *p);

//      遍历左子树
    int height_visit_left(node *&p, int &i, int &height);

//    返回根节点
    int height_visit_back(node *&p, int &i, int &height);

    //遍历右子树
    int height_visit_right(node *&p, int &i, int &height);

//--------------------------------------------------------------

//获取二叉树的节点数--------------------------------------

    int get_node_number(node *p);

//      遍历左子树
    int node_number_left(node *&p, int &i);

//    返回根节点
    int node_number_back(node *&p, int &i);

    //遍历右子树
    int node_number_right(node *&p, int &i);

//-----------------------------------------------------

//----------获取二叉树的叶子节点数----------------------

    int get_leaves_number(node *p);

//      遍历左子树
    int leaves_number_left(node *&p, int &i);

//    返回根节点
    int leaves_number_back(node *&p, int &i);

    //遍历右子树
    int leaves_number_right(node *&p, int &i);

//-----------------------------------------------------

//----------获取二叉树度为二的节点数----------------------

    int get_twochild_number(node *p);

//      遍历左子树
    int twochild_number_left(node *&p, int &i);

//    返回根节点
    int twochild_number_back(node *&p, int &i);

    //遍历右子树
    int twochild_number_right(node *&p, int &i);

//-----------------------------------------------------

//----------获取输入元素的父节点兄弟节点子节点的值----------------------

    int get_relative_node(node *p, char value);

//      遍历左子树
    int relative_node_left(node *&p, int &i, char value);

//    返回根节点
    int relative_node_back(node *&p, int &i, char value);

    //遍历右子树
    int relative_node_right(node *&p, int &i, char value);

//-----------------------------------------------------

//------------获取输入元素的层次信息----------------------------------

    int get_cin_node(node *p, char value);

//      遍历左子树
    int cin_node_left(node *&p, int &i, char value);

//    返回根节点
    int cin_node_back(node *&p, int &i, char value);

    //遍历右子树
    int cin_node_right(node *&p, int &i, char value);

//-------------------------------------------------------

//------------通过输入二叉树的顺序序列对二叉树进行建立-----------------------

    node *build_bitree_order();

//------------------------------------------------------------------

//    交换左右子树的位置---------------------------------------------------------

//    对数进行遍历
    int node_exchange(node *p);

//      遍历左子树
    int first_exchange_left(node *&p, int &i);

//    返回根节点
    int first_exchange_back(node *&p, int &i);

    //遍历右子树
    int first_exchange_right(node *&p, int &i);

//    ---------------------------------------------------------------------------

private:
    node *head;
};


#endif //ERCHASHU_BITREE_H
