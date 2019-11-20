#include <iostream>

using namespace std;

#include "bitree.h"

int main() {

    int choice;
    cout << "请选择要进行的算法\n";
    bitree A;
    node *head = nullptr;
    do {
        cout << "\n\n";
        cout << "结束程序--------------------------------0\n";
        cout << "通过输入先序序列创建树-------------------1\n";
        cout << "输出树的先序排列------------------------2\n";
        cout << "输出中序序列---------------------------3\n";
        cout << "输出后序序列---------------------------4\n";
        cout << "输出中序序列和对应节点的层数-------------5\n";
        cout << "获取二叉树的高度-----------------------6\n";
        cout << "获取二叉树的节点数----------------------7\n";
        cout << "获取二叉树的叶子节点数------------------8\n";
        cout << "二叉树度为二的节点数--------------------9\n";
        cout << "获取一元素的兄弟元素父元素子元素的值------10\n";
        cout << "输出一元素的层次信息--------------------11\n";
        cout << "通过输入顺序序列的数组创建二叉树----------12\n";
        cout << "交换二叉树左右结点的值-------------------13\n";

        cin >> choice;
        if (choice == 0) {
            break;
        }

        switch (choice) {
            default:
                break;

            case 1: {
                head = A.create_tree();
            }
                break;

            case 2: {
                cout << "树的先序序列\n";
                A.ergodic_first(head);
            }
                break;

            case 3: {
                cout << "树的中序序列\n";
                A.ergodic_middle(head);
            }
                break;

            case 4 : {
                cout << "树的后序序列\n";
                A.ergodic_after(head);
            }
                break;

            case 5: {
                A.set_middle_layer(head);
            }
                break;

            case 6: {
                cout << "树的高度为" << A.bitree_height(head) << "\n";
            }
                break;

            case 7: {
                cout << "树的节点数为" << A.get_node_number(head) << "\n";
            }
                break;

            case 8: {
                cout << "树的叶子结点数为" << A.get_leaves_number(head) << "\n";
            }
                break;

            case 9: {
                cout << "树中度为二的节点数为" << A.get_twochild_number(head) << "\n";
            }

            case 10: {
                char value;
                cout << "请输入要查找的节点值\n";
                cin >> value;
                A.get_relative_node(head, value);
            }
                break;

            case 11: {
                char value;
                cout << "请输入要查找的节点值\n";
                cin >> value;
                A.get_cin_node(head, value);
            }
                break;

            case 12: {
                head = A.build_bitree_order();
            }
                break;

            case 13:{
                A.node_exchange(head);
            }
        }

    } while (true);


    return 0;
}