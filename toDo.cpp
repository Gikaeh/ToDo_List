template <typename ItemType>
ToDo<ItemType>::ToDo() {
    itemCount = 0;
    headPtr = nullptr;
}

template <typename ItemType>
ToDo<ItemType>::ToDo(const ItemType& rhs) {
    itemCount = rhs.itemCount;

    if(itemCount > 0) {
        Node<ItemType>* curPtr = rhs.headPtr;
        Node<ItemType>* newNodePtr = new Node<ItemType>(); //creates node saving it address

        headPtr = newNodePtr; //makes the headPtr point to the newly created node
        newNodePtr->setItem(curPtr->getItem()); //sets item to copy ptr with the curPtr  
        
        Node<ItemType>* newCurPtr = nullptr;
        for(int j = 2; j <= itemCount; j++) {
            curPtr = curPtr->getNext(); //sets curPtr to the next nodePtr
            newCurPtr = newNodePtr; //makes the newCurPtr into the newNodePtr

            newNodePtr = new Node<ItemType>(); //set the newNodePtr to a newly instantiated node
            newCurPtr->setNext(newNodePtr); //sets newCurPtr next node to the newNodePtr
            newNodePtr->setItem(curPtr->getItem()); //sets newNodePtr item to the same as the oldCurPtr next item
        }
    } else{
        headPtr = nullptr;
    }
}

template <typename ItemType>
bool ToDo<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template <typename ItemType>
int ToDo<ItemType>::getLength() const {
    return itemCount;
}

template <typename ItemType>
void ToDo<ItemType>::showAll() {
    for(int i = 1; i < itemCount; i++) {
        ItemType item = getEntry(i);
        cout << i << ": " << item << endl;
    }
}

template <typename ItemType>
void ToDo<ItemType>::setItemCount(int itemCount) {
    this->itemCount = itemCount;
}

template <typename ItemType>
int ToDo<ItemType>::getItemCount() {
    return itemCount;
}

template <typename ItemType>
bool ToDo<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    bool canInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if(canInsert && newPosition == 1) {
        Node<ItemType>* newNodePtr = new Node<ItemType>(); //creates newNodePtr

        newNodePtr->setItem(newEntry); //sets item of new node with inputted item
        newNodePtr->setNext(headPtr); //sets next pointer to the headPtr

        headPtr = newNodePtr; //sets headPtr to the new nodePtr
        itemCount++;
    } else if(canInsert && newPosition > 1){
        Node<ItemType>* curPtr = getNodeAt(newPosition-1); //creates a temp node holding the newPosition previous node
        Node<ItemType>* newNodePtr = new Node<ItemType>();
        
        newNodePtr->setNext(curPtr->getNext()); //sets new node next point to the node after the temp node
        newNodePtr->setItem(newEntry);

        curPtr->setNext(newNodePtr); //sets temp nodePtr to the new node
        itemCount++;
    } else{
        cout << "God your stupid there's not that many items." << endl;
    }
    return canInsert;
}

template <typename ItemType>
bool ToDo<ItemType>::remove(int position) {
    bool canDelete = (position >= 1) && (position <= itemCount);
    Node<ItemType>* curPtr = headPtr; //sets a temp ptr to the headPtr
    if(canDelete && position == 1) {
        Node<ItemType>* deletePtr = headPtr;
        headPtr = headPtr->getNext();

        deletePtr->setNext(nullptr);
        delete deletePtr;
        deletePtr = nullptr;

        itemCount--;
    } else if(canDelete && position > 1) {
        curPtr = getNodeAt(position-1);
        Node<ItemType>* deletePtr = curPtr->getNext();
        curPtr->setNext(deletePtr->getNext());

        deletePtr->setNext(nullptr);
        delete deletePtr;
        deletePtr = nullptr;

        itemCount--;
    } else{
        cout << "God your stupid there's not that many items." << endl;
    }
    return canDelete;
}

template <typename ItemType>
void ToDo<ItemType>::clear() {
    Node<ItemType>* deletePtr = headPtr;
    while(deletePtr != nullptr) {
        headPtr = headPtr->getNext();

        deletePtr->setNext(nullptr);
        delete deletePtr;
        deletePtr = headPtr;
    }
    itemCount = 0;
}

template <typename ItemType>
ItemType ToDo<ItemType>::getEntry(int position) const {
    bool canGrab = (position >= 1) && (position <= itemCount);
    if(canGrab) {
        Node<ItemType>* curPtr = getNodeAt(position);
        return curPtr->getItem();
    }
    throw "Item not found";
}

template <typename ItemType>
ItemType ToDo<ItemType>::replace(int position, const ItemType& newEntry) {
    bool canReplace = (position >= 1) && (position <= itemCount);
    if(canReplace) {
        Node<ItemType>* curPtr = getNodeAt(position);
        ItemType oldEntry = curPtr->getItem();
        curPtr->setItem(newEntry);
        return oldEntry;
    }
    throw "Item not found";
}

template <typename ItemType>
Node<ItemType>* ToDo<ItemType>::getNodeAt(int position) const{
    if((position >= 1) && (position <= itemCount)) {
        Node<ItemType>* curPtr = headPtr;
        for(int i = 1; i < position; i++) {
            curPtr = curPtr->getNext();
        }
        return curPtr;
    }
    return nullptr;
}

template <typename ItemType>
ToDo<ItemType>::~ToDo() { 
    clear();
} 