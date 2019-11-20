//
// Created by Asus on 2019/11/6.
//

#include "bitree.h"

bitree::bitree() {
    head = nullptr;
}

node *bitree::create_tree() {
//    对字符串进行初始化
    char str[100];
    for (int i = 0; i < 99; i++) {
        str[i] = 0;
    }

//    对树进行输入
    cout << "请输入树的先序序列\n";
    cin >> str;

//     进行树建立
    int i = 0;
    node *p = head;
    do {
        if (p == nullptr) {
            head = new node;
            p = head;
            p->parent = nullptr;
            p->content = str[i];
            p->lstate = 0;
            p->rstate = 0;
            i++;
        } else {
//            若左子树为0
            if (p->lstate == 0) {
//                    如果值为/
                if (str[i] == '/') {
                    p->lstate = 1;
                    i++;
//                        如果值不为/
                } else {
                    node *q = new node;
                    p->lchild = q;
                    p->lstate = 2;
                    q->content = str[i];
                    q->lstate = 0;
                    q->rstate = 0;
                    q->parent = p;
                    p->lstate = 2;
                    p = q;
                    i++;
                }
            }

//            如果左子树赋值为1或2
            else if (p->lstate == 1 || p->lstate == 2) {
//                如果他的右子树为0
                if (p->rstate == 0) {
//                    如果值为/
                    if (str[i] == '/') {
                        p->rstate = 1;
                        i++;
//                        如果值不为/
                    } else {
                        node *q = new node;
                        p->rchild = q;
                        p->rstate = 2;
                        q->content = str[i];
                        q->lstate = 0;
                        q->rstate = 0;
                        q->parent = p;
                        p->rstate = 2;
                        p = q;
                        i++;
                    }
                }
//                如果右子树不为0
                if (p->rstate != 0) {
                    p = p->parent;
                }
            }
        }

    } while (str[i] != 0);

    return head;
}

//先序遍历----------------------------------------------------

int bitree::ergodic_first(node *p) {
    int i = 0;
    first_visit_left(p, i);

    return 0;
}

int bitree::first_visit_left(node *&p, int &i) {
    cout << p->content;
    if (p->lstate == 2) {
        p = p->lchild;
        first_visit_left(p, i);
    } else {
        if (p->rstate == 2) {
            first_visit_right(p, i);
        } else {
            first_visit_back(p, i);
        }
    }

    return 0;
}

int bitree::first_visit_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rstate != 2 || p->rchild == q) {
        first_visit_back(p, i);
    } else {
        first_visit_right(p, i);
    }
    return 0;
}

int bitree::first_visit_right(node *&p, int &i) {
    p = p->rchild;
    first_visit_left(p, i);

    return 0;
}
//---------------------------------------------------------

//中序遍历--------------------------------------------------

int bitree::ergodic_middle(node *p) {
    int i = 0;
    middle_visit_left(p, i);

    return 0;
}

int bitree::middle_visit_left(node *&p, int &i) {
    if (p->lstate == 2) {
        p = p->lchild;
        middle_visit_left(p, i);
    } else {
        cout << p->content;
        if (p->rstate == 2) {
            middle_visit_right(p, i);
        } else {
            middle_visit_back(p, i);
        }
    }

    return 0;
}

int bitree::middle_visit_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rchild != q) {
        cout << p->content;
    }
    if (p->rstate != 2 || p->rchild == q) {
        middle_visit_back(p, i);
    } else {
        middle_visit_right(p, i);
    }
    return 0;
}

int bitree::middle_visit_right(node *&p, int &i) {
    p = p->rchild;
    middle_visit_left(p, i);

    return 0;
}


//-----------------------------------------------------------

//后序遍历--------------------------------------------------

int bitree::ergodic_after(node *p) {
    int i = 0;
    after_visit_left(p, i);

    return 0;
}

int bitree::after_visit_left(node *&p, int &i) {
    if (p->lstate == 2) {
        p = p->lchild;
        after_visit_left(p, i);
    } else {
        if (p->rstate == 2) {
            after_visit_right(p, i);
        } else {
            cout << p->content;
            after_visit_back(p, i);
        }
    }

    return 0;
}

int bitree::after_visit_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        cout << p->content;
        return 0;
    }
    if (p->rchild == q) {
        cout << p->content;
    }
    if (p->rstate != 2) {
        cout << p->content;
    }
    if (p->rstate != 2 || p->rchild == q) {
        after_visit_back(p, i);
    } else {
        after_visit_right(p, i);
    }
    return 0;
}

int bitree::after_visit_right(node *&p, int &i) {
    p = p->rchild;
    after_visit_left(p, i);

    return 0;
}


//-----------------------------------------------------------

//按中序次序输出二叉树中各结点的值及其所对应的层次数-------------

int bitree::set_middle_layer(node *p) {
    int i = 1;
    middle_layer_left(p, i);

    return 0;
}

int bitree::middle_layer_left(node *&p, int &i) {
    if (p->lstate == 2) {
        p = p->lchild;
        i++;
        middle_layer_left(p, i);
    } else {
        cout << "该节点位于第" << i << "层，值为:" << p->content << "\n";
        if (p->rstate == 2) {
            middle_layer_right(p, i);
        } else {
            middle_layer_back(p, i);
        }
    }

    return 0;
}

int bitree::middle_layer_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
    i--;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rchild != q) {
        cout << "该节点位于第" << i << "层，值为:" << p->content << "\n";
    }
    if (p->rstate != 2 || p->rchild == q) {
        middle_layer_back(p, i);
    } else {
        middle_layer_right(p, i);
    }
    return 0;
}

int bitree::middle_layer_right(node *&p, int &i) {
    p = p->rchild;
    i++;
    middle_layer_left(p, i);

    return 0;
}

//----------------------------------------------------

//求二叉树的高度--------------------------------------------

int bitree::bitree_height(node *p) {
    int i = 1;
    int height = 1;
    height_visit_left(p, i, height);

    return height;
}

int bitree::height_visit_left(node *&p, int &i, int &height) {
    if (p->lstate == 2) {
        p = p->lchild;
        i++;
        if (i > height) {
            height = i;
        }
        height_visit_left(p, i, height);
    } else {
        if (p->rstate == 2) {
            height_visit_right(p, i, height);
        } else {
            height_visit_back(p, i, height);
        }
    }

    return 0;
}

int bitree::height_visit_back(node *&p, int &i, int &height) {
    node *q = p;
    p = p->parent;
    i--;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rstate != 2 || p->rchild == q) {
        height_visit_back(p, i, height);
    } else {
        height_visit_right(p, i, height);
    }
    return 0;
}

int bitree::height_visit_right(node *&p, int &i, int &height) {
    p = p->rchild;
    i++;
    if (i > height) {
        height = i;
    }
    height_visit_left(p, i, height);

    return 0;
}

//---------------------------------------------------

//获取二叉树节点数-----------------------------------------

int bitree::get_node_number(node *p) {
    int i = 0;
    node_number_left(p, i);

    return i;
}

int bitree::node_number_left(node *&p, int &i) {
    if (p->lstate == 2) {
        p = p->lchild;
        node_number_left(p, i);
    } else {
//        cout << "该节点位于第" << i << "层，值为:" << p->content << "\n";
        i++;
        if (p->rstate == 2) {
            node_number_right(p, i);
        } else {
            node_number_back(p, i);
        }
    }

    return 0;
}

int bitree::node_number_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rchild != q) {
//        cout << "该节点位于第" << i << "层，值为:" << p->content << "\n";
        i++;
    }
    if (p->rstate != 2 || p->rchild == q) {
        node_number_back(p, i);
    } else {
        node_number_right(p, i);
    }
    return 0;
}

int bitree::node_number_right(node *&p, int &i) {
    p = p->rchild;
    node_number_left(p, i);

    return 0;
}

//---------------------------------------------------------

//---获取二叉树的叶子节点数----------------------------------------

int bitree::get_leaves_number(node *p) {
    int i = 0;
    leaves_number_left(p, i);

    return i;
}

int bitree::leaves_number_left(node *&p, int &i) {
    if (p->lstate == 2) {
        p = p->lchild;
        leaves_number_left(p, i);
    } else {
//        cout << "该节点位于第" << i << "层，值为:" << p->content << "\n";
        if (p->rstate == 2) {
            leaves_number_right(p, i);
        } else {
            leaves_number_back(p, i);
            i++;
        }
    }

    return 0;
}

int bitree::leaves_number_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rstate != 2 || p->rchild == q) {
        leaves_number_back(p, i);
    } else {
        leaves_number_right(p, i);
    }
    return 0;
}

int bitree::leaves_number_right(node *&p, int &i) {
    p = p->rchild;
    leaves_number_left(p, i);

    return 0;
}

//---------------------------------------------------------------

//---获取二叉树度为二的节点数----------------------------------------

int bitree::get_twochild_number(node *p) {
    int i = 0;
    twochild_number_left(p, i);

    return i;
}

int bitree::twochild_number_left(node *&p, int &i) {
    if (p->lstate == 2) {
        p = p->lchild;
        twochild_number_left(p, i);
    } else {
//        cout << "该节点位于第" << i << "层，值为:" << p->content << "\n";
        if (p->rstate == 2) {
            twochild_number_right(p, i);
        } else {
            twochild_number_back(p, i);
        }
    }

    return 0;
}

int bitree::twochild_number_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
//    判断是否从左子树返回且含有右子树
    if (p->lchild == q && p->rstate == 2) {
        i++;
    }
    if (p->rstate != 2 || p->rchild == q) {
        twochild_number_back(p, i);
    } else {
        twochild_number_right(p, i);
    }
    return 0;
}

int bitree::twochild_number_right(node *&p, int &i) {
    p = p->rchild;
    twochild_number_left(p, i);

    return 0;
}

//---------------------------------------------------------------

//---获取输入元素相关的父节点兄弟节点子节点----------------------------------------

int bitree::get_relative_node(node *p, char value) {
    int i = 0;
    relative_node_left(p, i, value);

    return i;
}

int bitree::relative_node_left(node *&p, int &i, char value) {
    if (value == p->content) {

//        输出父节点的值
        if (p->parent == nullptr) {
            cout << "该节点不存在父元素\n";
        } else {
            cout << "该元素父节点的值为" << p->parent->content << "\n";
        }

//        输出子节点的值
        if (p->lstate == 2) {
            cout << "该节点的左子节点为" << p->lchild->content << "\n";
        } else {
            cout << "该元素不存在左子节点\n";
        }
        if (p->rstate == 2) {
            cout << "该节点的右子节点为" << p->rchild->content << "\n";
        } else {
            cout << "该元素不存在右子节点\n";
        }

        //    输出兄弟节点的值
        if (p->parent != nullptr) {
            node *temp = p->parent;

            if (temp->lchild == p) {
                if (temp->rstate == 2) {
                    cout << "该节点的右兄弟元素为" << temp->rchild->content << "\n";
                } else {
                    cout << "该节点没有兄弟元素";
                }
            }
            if (temp->rchild == p) {
                if (temp->lstate == 2) {
                    cout << "该节点的左兄弟元素为" << temp->lchild->content << "\n";
                } else {
                    cout << "该节点没有兄弟元素\n";
                }
            }
        }
    }


    if (p->lstate == 2) {
        p = p->lchild;
        relative_node_left(p, i, value);
    } else {
        if (p->rstate == 2) {
            relative_node_right(p, i, value);
        } else {
            relative_node_back(p, i, value);
        }
    }

    return 0;
}

int bitree::relative_node_back(node *&p, int &i, char value) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        cout << "树中不存在此元素\n";
        return 0;
    }
    if (p->rstate != 2 || p->rchild == q) {
        relative_node_back(p, i, value);
    } else {
        relative_node_right(p, i, value);
    }
    return 0;
}

int bitree::relative_node_right(node *&p, int &i, char value) {
    p = p->rchild;
    relative_node_left(p, i, value);

    return 0;
}

//---------------------------------------------------------------

//---获取输入元素的层次信息----------------------------------------

int bitree::get_cin_node(node *p, char value) {
    int i = 1;
    cin_node_left(p, i, value);

    return i;
}

int bitree::cin_node_left(node *&p, int &i, char value) {
    if (value == p->content) {
        cout << "此元素在书中的层次为：" << i << "\n";
        return 0;
    }


    if (p->lstate == 2) {
        p = p->lchild;
        i++;
        cin_node_left(p, i, value);
    } else {
        if (p->rstate == 2) {
            cin_node_right(p, i, value);
        } else {
            cin_node_back(p, i, value);
        }
    }

    return 0;
}

int bitree::cin_node_back(node *&p, int &i, char value) {
    node *q = p;
    p = p->parent;
    i--;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        cout << "树中不存在此元素\n";
        return 0;
    }
    if (p->rstate != 2 || p->rchild == q) {
        cin_node_back(p, i, value);
    } else {
        cin_node_right(p, i, value);
    }
    return 0;
}

int bitree::cin_node_right(node *&p, int &i, char value) {
    p = p->rchild;
    i++;
    cin_node_left(p, i, value);

    return 0;
}

//---------------------------------------------------------------

//------------通过输入二叉树的顺序序列对二叉树进行建立-----------------------

node *bitree::build_bitree_order() {
//    创建字符数组
    char str[100];

    cout << "请输入二叉树的顺序存储序列\n";
    cin >> (str + 1);
//    获取字符串数组长度
    int str_max = 1;
    while (true) {
        if (str[str_max] == 0) {
            str_max--;
            break;
        }
        str_max++;
    }

//    创建指针数组
    node *node_postion[100];
    for (int i = 0; i < 100; i++) {
        node_postion[i] = nullptr;
    }

    int postion = 1;
    while (true) {
//        判断该节点是否已经被创建(只可能是根节点)
        if (node_postion[postion] == head) {
            node_postion[postion] = new node;
            head = node_postion[postion];
            node_postion[postion]->content = str[postion];
            node_postion[postion]->lstate = 1;
            node_postion[postion]->rstate = 1;
            node_postion[postion]->parent = nullptr;
        }
        //        判断是否跳出循环
        if (postion * 2 > str_max) {
            break;
        } else if (str[postion] == '/') {
            postion++;
            continue;

//              创建子节点
        } else {
            //        给他的子节点赋值

            //        左子节点
            if (str[postion * 2] == '/') {
                node_postion[postion]->lstate = 1;
            } else {
                node_postion[postion * 2] = new node;
                node_postion[postion * 2]->content = str[postion * 2];
                node_postion[postion * 2]->parent = node_postion[postion];
                node_postion[postion]->lchild = node_postion[postion * 2];
                node_postion[postion * 2]->lstate = 1;
                node_postion[postion * 2]->rstate = 1;
                node_postion[postion]->lstate = 2;
            }

            //右子节点
            if (str[(postion * 2) + 1] == '/') {
                node_postion[postion]->rstate = 1;
            } else {
                node_postion[(postion * 2) + 1] = new node;
                node_postion[(postion * 2) + 1]->content = str[(postion * 2) + 1];
                node_postion[(postion * 2) + 1]->parent = node_postion[postion];
                node_postion[postion]->rchild = node_postion[(postion * 2) + 1];
                node_postion[(postion * 2) + 1]->lstate = 1;
                node_postion[(postion * 2) + 1]->rstate = 1;
                node_postion[postion]->rstate = 2;
            }
            postion++;
        }
    }


    return node_postion[1];
}

//------------------------------------------------------------------

//交换二叉树的左右节点----------------------------------------------------

int bitree::node_exchange(node *p) {
    int i = 0;
    first_exchange_left(p, i);

    return 0;
}

int bitree::first_exchange_left(node *&p, int &i) {
//交换左右子节点
    int my_temp;
    my_temp = p->lstate;
    p->lstate = p->rstate;
    p->rstate = my_temp;
    node * my_temp_node;
    my_temp_node=p->lchild;
    p->lchild=p->rchild;
    p->rchild=my_temp_node;

    if (p->lstate == 2) {
        p = p->lchild;
        first_exchange_left(p, i);
    } else {
        if (p->rstate == 2) {
            first_exchange_right(p, i);
        } else {
            first_exchange_back(p, i);
        }
    }

    return 0;
}

int bitree::first_exchange_back(node *&p, int &i) {
    node *q = p;
    p = p->parent;
//     判断是否是从右子树返回根节点
    if (p->rchild == q && p == head) {
        return 0;
    }
    if (p->rstate != 2 || p->rchild == q) {
        first_exchange_back(p, i);
    } else {
        first_exchange_right(p, i);
    }
    return 0;
}

int bitree::first_exchange_right(node *&p, int &i) {
    p = p->rchild;
    first_exchange_left(p, i);

    return 0;
}
//---------------------------------------------------------