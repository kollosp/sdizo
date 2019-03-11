#include "MyList.h"

MyList::MyList()
{
    head = nullptr;
}

MyList::~MyList()
{
    MyListItem* buf = head;

    while(buf != nullptr){

        MyListItem* toDel = buf;
        buf = buf->next;
        delete buf;
    }
}

void MyList::push_back(int value)
{
    MyListItem* last = findIndex(-1);

    if(last == nullptr) head = new MyListItem(value);
    else last->next = new MyListItem(value);
}

void MyList::push_front(int value)
{
    MyListItem* newItem = new MyListItem(value);
    newItem->next = head;
    head = newItem;
}

void MyList::insert(int value, int index)
{
    MyListItem* item = findIndex(index);

    if(item == nullptr) head = new MyListItem(value);
    else {
        MyListItem* newItem = new MyListItem(value);
        newItem->next = item->next;
        item->next = newItem;
    }
}

const MyListItem *MyList::getHead() const
{
    return head;
}

const bool MyList::isEmpty() const
{
    return head == nullptr;
}

const int MyList::contains(int item) const
{
    if(head == nullptr) return -1;

    MyListItem* buf = head;
    int i=0;

    while(buf->next != nullptr){
        if(buf->data == item)
            return i;

        buf = buf->next;
        ++i;
    }

    return -1;

}

MyListItem *MyList::findIndex(int index)
{
    if(head == nullptr) return nullptr;

    MyListItem* buf = head;
    int i=0;

    while(buf->next != nullptr && index != i){
        buf = buf->next;
        ++i;
    }

    return buf;
}

std::ostream &operator<<(std::ostream &str, const MyList &list)
{
    const MyListItem* buf = list.getHead();

    str<<"List: [";
    while(buf != nullptr){
        str<<buf->data<<", ";
        buf = buf->next;
    }
    str<<"]";

    return str;
}
