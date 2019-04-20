#ifndef MYREDBLACKTREE_H
#define MYREDBLACKTREE_H

#include <iostream>
#include <iomanip>

class MyRedBlackTree
{
public:
    //enumarate for colors
    enum Color{
        RED = 0,
        BLACK = 1
    };

    enum Direction{
        RIGHT = 0,
        LEFT = 1,
        NONE = 2
    };

    //this class is a struct and it is private for MyRedBlackTree, so
    //all fileds could be public. They will be used only by MyRedBlackTree
    class Item{
    public:

        Item* parent;
        Item* left;
        Item* right;
        int data;
        Color color;

        Item(int data=0, Item *parent=nullptr) :
            parent(parent), left(nullptr), right(nullptr), data(data), color(RED) {}

        //function swap (left or right it depends on old (must be equal to swapped item) with new.
        void swapChild(Item* oldItem, Item* newItem);
        Direction childDirection(Item* child);
        void repaintOpposit();
    };

    Item* tree;

    //function removes item and all childs of it
    void removeTree(Item* item);
    void pushRec(Item* item, int pushValue);

    //function checks whether the conditions are met
    void checkAndFixColors(Item* item);
    Color nodeColor(Item* node);

    //functions rotates and returns new parent (after rotation
    //left or right child becames parent)
    Item* rotateLeft(Item* actParent);
    Item* rotateRight(Item* actParent);
    //function rotate in d direction
    Item* rotate(Item* actParent, Direction d);

    //function rotate in not d direction (logic not means opposite side)
    Item* rotateOposit(Item* actParent, Direction d);


    Item* searchChild(Item* node, int value);

public:
    MyRedBlackTree();
    ~MyRedBlackTree();

    void push(int value);
    void pop(int value);

    void headRotateLeft();
    void headRotateRight();

    friend std::ostream& operator<<(std::ostream& str, const MyRedBlackTree& tree);

    Item* search(int value);

    static void displayText(std::ostream& str, Item* node, int indent=0);
    static void displayGraph(std::ostream &str, Item* node, int indent);
};



std::ostream& operator<<(std::ostream& str, const MyRedBlackTree& tree);

#endif // MYREDBLACKTREE_H
