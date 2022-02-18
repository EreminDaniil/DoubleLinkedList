#pragma once

typedef int Elem;

struct FNode
{
    FNode* Next;
    FNode* Prev;
    FNode* Value;
    Elem Data;
};

class UDoublyLinkedList
{
public:
    class UIterator
    {
    public:
        Elem& operator*(); // reference to the element
        bool operator==(const UIterator& p) const; // compare positions
        bool operator!=(const UIterator& p) const;
        UIterator& operator++(); // move to next position
        UIterator& operator−−(); // move to previous position
    };
public:
    UDoublyLinkedList();
    ~UDoublyLinkedList();
    UDoublyLinkedList(const UDoublyLinkedList& other); // copy ctor
    UDoublyLinkedList& operator=(const UDoublyLinkedList& other); // copy assignment
    size_t Count() const; // number of elements in list
    bool IsEmpty() const; // is list empty
    UIterator Begin() const; // beginning position
    UIterator End() const; // past the end position
    void InsertFront(const Elem& Value); // add to front of the list
    void InsertBack(const Elem& Value); // add to the back of the list
    void Insert(const UIterator& idx, const Elem& Value); // insert e before p
    void EraseFront(); // remove front element
    void EraseEnd(); // remove last element
    void Erase(const UIterator& idx); // erase Elem at p

private:
    Elem* Head;
    Elem* Tail;
    int Count;
};