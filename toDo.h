#ifndef TODO_H 
#define TODO_H 

#include "listInterface.h"
#include "node.h"

using namespace std;

template<class ItemType> 
class ToDo: public ListInterface<ItemType> {
    Node<ItemType>* headPtr;
    int itemCount = 0; 
    Node<ItemType>* getNodeAt(int position) const;

    public:
        ToDo();
        ToDo(const ItemType& rhs);

        bool isEmpty() const; 
        int getLength() const;
        void showAll();
        void setItemCount(int itemCount);
        int getItemCount();

        bool insert(int newPosition, const ItemType& newEntry); 
        bool remove(int position); 
        void clear();

        ItemType getEntry(int position) const;
        ItemType replace(int position, const ItemType& newEntry);

        ~ToDo();
};
#include "toDo.cpp"  
#endif