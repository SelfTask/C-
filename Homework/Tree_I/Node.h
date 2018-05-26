/* Filename: Node.h
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Tree I
 * Purpose: Create an m-arry Tree
 * Date: 21 May 2018
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;


class BinaryTree{
    private:
        struct Node{
            Node *left;
            Node *right;
            int data;
        };

        Node *root; //Points to the first node
        
        //prints the different traverses
        void prntPst(Node*);
        void prntIn(Node*);
        void prntPre(Node*);
        void prntLvl(Node *);

    public:
        //Constructor
        BinaryTree();

        //Insert values onto tree
        void insert(int);

        //Display the printed orders
        void showPre();
        void showIn();
        void showPst();
        void showLvl();
};

#endif /* NODE_H */

