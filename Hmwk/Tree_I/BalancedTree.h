/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedTree.h
 * Author: DangerousPirate
 *
 * Created on May 26, 2018, 5:44 PM
 */

#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H
class BalancedBT{
private:
    struct Node{
        int data;
        Node *left;
        Node *right;
};
    Node *root;
    Node *newNode;
    Node *temp;

    void formatTree(Node **, int[], int, int);
    void print_PreOrder(Node *);
    void print_InOrder(Node *);
    void print_Level(Node *);
public:
    void runformatTree(int[], int, int);
    void show_PreOrder();
    void show_InOrder();
    void show_LevelOrder();
    void deleteNode(Node*, int);
};


#endif /* BALANCEDTREE_H */

