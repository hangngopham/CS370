#ifndef BTree_H
#define BTree_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int DATA;
typedef struct BinaryTree* Tree;

Tree LeafTree(DATA d);
Tree BTree(DATA d, Tree l, Tree r);
bool isLeaf(Tree root);
DATA getData(Tree root);
Tree getLeft(Tree root);
Tree getRight(Tree root);
void in_order_traversal(Tree t);
void post_order_traversal(Tree t);
int eval(Tree t);


#endif
