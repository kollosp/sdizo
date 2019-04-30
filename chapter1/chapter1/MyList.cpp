#include "MyList.h"

MyList::MyList()
{
    head = nullptr;
}

MyList::MyList(const MyList &obj)
{

    head = nullptr;
    if(obj.head){
        head = new MyListItem(obj.head->data);

    }
    else return;

    MyListItem* buf = obj.head->next;
    MyListItem* localBuf = head;

    while(buf != nullptr){

        localBuf->next = new MyListItem(buf->data);
        localBuf = localBuf->next;
        buf = buf->next;
    }
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
    MyListItem* item = findIndex(index-1);

    if(item == nullptr) head = new MyListItem(value);
    else {
        MyListItem* newItem = new MyListItem(value);
        newItem->next = item->next;
        item->next = newItem;
    }
}

void MyList::remove(int index)
{
    if(head == nullptr) return;

    MyListItem* item = head;
    MyListItem* beforeitem = nullptr;

    int i=0;

    while(item->next != nullptr && i<index){
        beforeitem = item;
        item = item->next;
        ++i;
    }

    MyListItem* next = item->next;

    delete item;

    if(beforeitem != nullptr)
       beforeitem->next = next;
    else head = next;
}

void MyList::pop_back()
{
    if(head == nullptr) return;

    MyListItem* item = head;
    MyListItem* beforeitem = nullptr;

    while(item->next != nullptr){
        beforeitem = item;
        item = item->next;
    }


    delete item;

    if(beforeitem != nullptr)
       beforeitem->next = nullptr;
    else head = nullptr;
}

void MyList::pop_front()
{
    if(head == nullptr) return;

    MyListItem* second = head->next;
    delete head;
    head = second;
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

int MyList::length() const
{

    if(head == nullptr) return 0;

    MyListItem* buf = head;

    int len = 0;
    while(buf->next != nullptr){
        buf = buf->next;
        ++len;
    }

    return len;

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

    str<<"[";
    while(buf != nullptr){
        str<<buf->data<<" -> ";
        buf = buf->next;
    }
    str<<"]";

    return str;
}
