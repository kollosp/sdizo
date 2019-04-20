#include "MyRedBlackTree.h"




void MyRedBlackTree::removeTree(Item* item)
{
    if(item){
        if(item->left)
            removeTree(item->left);
        if(item->right)
            removeTree(item->right);
        delete item;
    }
}

void MyRedBlackTree::pushRec(MyRedBlackTree::Item *item, int pushValue)
{
    if(item){
        if(pushValue > item->data){
            if(item->right)
                pushRec(item->right, pushValue);
            else{
                item->right = new Item(pushValue, item);
                checkAndFixColors(item->right);
            }
        }
        else{
            if(item->left)
                pushRec(item->left, pushValue);
            else{
                item->left = new Item(pushValue, item);
                checkAndFixColors(item->left);
            }
        }
    }
}

void MyRedBlackTree::checkAndFixColors(Item *item)
{

    //set root color to black
    if(item->parent == nullptr){
        item->color = BLACK;
        return;
    }

    //everything correct
    if(item->parent->color == BLACK) return;

    Item *parent = item->parent;
    Item *grandParent = parent->parent;
    Item *uncle = grandParent->left == parent ? grandParent->right : grandParent->left;

    //check if the parent is right or left grandparent child
    Direction d = grandParent->childDirection(parent);


    //1)
    //father and uncle are red
    if(nodeColor(uncle) == RED){
        parent->color = BLACK;
        uncle->color = BLACK;
        grandParent->color = RED;

        checkAndFixColors(grandParent);
    }
    //2)
    //uncle is black, father is red
    else if(nodeColor(uncle) == BLACK){

        //if parent is left child then rotate left if right then
        //rotate right
        Item* afterRotate = rotate(parent, d);
        //std::cout<<"before:\n"<<*this<<std::endl;
        //std::cout<<(afterRotate != parent)<<std::endl;

        if(afterRotate != parent){
            grandParent->swapChild(parent, afterRotate);
            std::swap(item, parent);
            grandParent = parent->parent;
        }

        //3)

        if(grandParent->parent == nullptr){
            tree = rotateOposit(grandParent, d);
        }
        else{
            Item* b = grandParent->parent;
            b->swapChild(grandParent, rotateOposit(grandParent, d));
        }

        grandParent->repaintOpposit();
        parent->repaintOpposit();
    }

}

MyRedBlackTree::Color MyRedBlackTree::nodeColor(Item *node)
{
    if(node == nullptr) return BLACK;
    else return node->color;
}

MyRedBlackTree::Item *MyRedBlackTree::rotateLeft(MyRedBlackTree::Item *actParent)
{
    if(actParent->right == nullptr) return actParent;

    Item* right = actParent->right;
    Item* rightLeft = actParent->right->left;

    actParent->right = rightLeft;
    if(rightLeft) rightLeft->parent = actParent;

    right->parent = actParent->parent;
    right->left = actParent;
    actParent->parent = right;

    return right;
}

MyRedBlackTree::Item *MyRedBlackTree::rotateRight(MyRedBlackTree::Item *actParent)
{
    if(actParent->left == nullptr) return actParent;

    Item* left = actParent->left;
    Item* leftRight = actParent->left->right;

    actParent->left = leftRight;
    if(leftRight) leftRight->parent = actParent;

    left->parent = actParent->parent;
    left->right= actParent;
    actParent->parent = left;

    return left;
}

MyRedBlackTree::Item *MyRedBlackTree::rotate(MyRedBlackTree::Item *actParent, MyRedBlackTree::Direction d)
{
    if(d == RIGHT)
        return rotateRight(actParent);
    else if(d == LEFT)
        return rotateLeft(actParent);
}

MyRedBlackTree::Item *MyRedBlackTree::rotateOposit(MyRedBlackTree::Item *actParent, MyRedBlackTree::Direction d)
{
    if(d == LEFT)
        return rotateRight(actParent);
    else if(d == RIGHT)
        return rotateLeft(actParent);
}

MyRedBlackTree::Item *MyRedBlackTree::searchChild(MyRedBlackTree::Item *node, int value)
{
    if(node == nullptr) return node;

    if(node->data == value) return node;
    else if(node->data > value) return searchChild(node->left, value);
    else if(node->data < value) return searchChild(node->right, value);
}

MyRedBlackTree::MyRedBlackTree()
{
    tree = nullptr;
}

MyRedBlackTree::~MyRedBlackTree()
{
    removeTree(tree);
}

void MyRedBlackTree::push(int value)
{
    //create first element
    if(tree == nullptr){
        tree = new Item(value);
        tree->color = BLACK;
        return;
    }

    pushRec(tree, value);
}

void MyRedBlackTree::pop(int value)
{
    Item* removedItem = search(value);

    if(removedItem == nullptr) return;

    Item* parent = removedItem->parent;

    //1)
    //no sons
    if(removedItem->left == removedItem->right && removedItem->left == nullptr){
        removedItem->parent->swapChild(removedItem, nullptr);
        delete removedItem;
    }
    //only one son exists (right)
    else if(removedItem->left == nullptr){
        Item* buf = removedItem->right;
        buf->parent = parent;
        if(parent == nullptr) tree = buf;
        else{
            parent->swapChild(removedItem,buf);

            if(parent->color == RED && buf->color == RED)
                buf->color = BLACK;
        }
    }
    //only one son exists (left)
    else if(removedItem->right == nullptr){
        Item* buf = removedItem->left;
        buf->parent = parent;
        if(parent == nullptr) tree = buf;
        else{
            parent->swapChild(removedItem,buf);

            if(parent->color == RED && buf->color == RED)
                buf->color = BLACK;
        }
    }
    //both sons exists
    else{

    }
}

void MyRedBlackTree::headRotateLeft()
{
    tree = rotateLeft(tree);
}

void MyRedBlackTree::headRotateRight()
{
    tree = rotateRight(tree);
}

MyRedBlackTree::Item *MyRedBlackTree::search(int value)
{
    searchChild(tree, value);
}

std::ostream &operator<<(std::ostream &str, const MyRedBlackTree &tree)
{
    MyRedBlackTree::displayText(std::cout, tree.tree,0);
    str<<std::endl;
    MyRedBlackTree::displayGraph(std::cout, tree.tree,0);
    return str;
}


void MyRedBlackTree::displayText(std::ostream &str, Item* node, int indent){
    if(node){
        str<<node->data<<":"<<(node->color == 1 ? "B": "R")<<": [";
        displayText(str, node->left,0);
        str<<", ";
        displayText(str, node->right,0);
        str<<"]";
    }
}

void MyRedBlackTree::displayGraph(std::ostream &str, Item* node, int indent){
    if(node){
        if(node->right) displayGraph(str, node->right, indent+4);

        if (indent) {
            str<< std::setw(indent) << ' ';
        }

        if(node->right) str<<" /\n" << std::setw(indent) << ' ';
        str<< node->data<<":"<<(node->color == 1 ? "B": "R")<< "\n ";

        if(node->left) {
            str << std::setw(indent) << ' ' <<" \\\n";
            displayGraph(str, node->left, indent+4);
        }

    }
}

void MyRedBlackTree::Item::swapChild(MyRedBlackTree::Item *oldItem, MyRedBlackTree::Item *newItem)
{
    if(right == oldItem) right = newItem;
    else if(left == oldItem) left = newItem;
}

MyRedBlackTree::Direction MyRedBlackTree::Item::childDirection(MyRedBlackTree::Item *child)
{
    if(right == child) return RIGHT;
    else if(left== child) return LEFT;
    else return NONE;
}

void MyRedBlackTree::Item::repaintOpposit()
{
    if(color == RED) color = BLACK;
    else color = RED;
}
