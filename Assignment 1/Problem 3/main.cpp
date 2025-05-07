#include <iostream>
using namespace  std ;


// Node class for linked list
class Node {
public :
    int data ;
    Node * next ;
    Node (int val ) ; // constructor
};

Node::Node(int val) {
    this -> data = val ;
    this -> next =  NULL;
}


// Sorted Linked List class
class SortedLinkedList {

private:
    Node * head;
public:
    SortedLinkedList() ; // Constructor
    void insert(int val) ; // Insert a value while keeping the list sorted
    void  remove (int index ) ; // Delete node at given index
    // overloaded operators
    friend ostream & operator << (ostream & os, const SortedLinkedList &list) ;
    int operator [](int index ) ;
    ~SortedLinkedList() ; //Destructor to free memory
};

ostream & operator<<(ostream &os, const SortedLinkedList &list) {
    Node * curr = list.head ;
    os<< "[" ;
    while (curr != NULL) {
        if(curr -> next == NULL) {
            os << curr -> data ;

        }
        else os << curr -> data << ", " ;
        curr = curr -> next ;
    }
    os << "] \n" ;
    return os ;
}

SortedLinkedList::SortedLinkedList() {
    head = NULL;
}

void SortedLinkedList::insert(int val) {
    Node * newNode = new Node(val) ;
    // case 1 : empty list or the value must be at the beginning
    if(head == NULL || head -> data > val  ){
        newNode -> next = head ;
        head = newNode ;
        cout << "You inserted " << val << " at the beginning " << endl ;
        return ;
    }
    // case 2 : traverse to find the appropriate  pos
        Node * curr = head ;
        while (curr->next != NULL && curr->next->data < val) {
            curr = curr->next ; // increment the curr
        }
        //  insert after curr
        newNode -> next = curr->next ;
        curr -> next = newNode ;

}

void SortedLinkedList::remove(int index) {
    // list is empty
    if(head == NULL ) {
        return ;
    }
    //removing the 0 index
    if(index == 0 ) {
        Node * temp = head ;
        head = head -> next ;
        delete temp ;
        return ;
    }
    Node * curr = head ;
    int count  = 0 ;

    while(curr ->next != NULL && count < index - 1 ) {
        curr = curr->next ;
        count ++ ;
    }
    // out of bounds
    if(curr == NULL || curr -> next == NULL ) {
        cout << "Wrong index" << endl ;
        return ;
    }
  Node * temp = curr->next ;
    curr -> next = temp -> next ;
    delete temp ;
}

int SortedLinkedList::operator[](int index) {
    Node * curr = head ;
    int count  = 0 ;
    while(curr!= NULL && count < index) {
        curr = curr->next ;
        count ++ ;
    }
    if(curr == NULL ) {
        cout << "out of range" << endl ;
        return -1 ;
    };
    return curr->data ;
}

SortedLinkedList::~SortedLinkedList() {
    Node * curr = head ;
    while(curr != NULL) {
        Node * temp = curr->next ;
        delete curr ;
        curr = temp ;
    }
}


int main() {

    SortedLinkedList L ;
    //Test Case 1: Inserting Elements into the Sorted Linked List
    L.insert(5) ;
    L.insert(6) ;
    L.insert(6) ;
    L.insert(7) ;
    L.insert(8) ;
    cout << L << endl ;
    //Test Case 2: Accessing Elements Using Index Operator
    cout << L[2] <<endl;
    cout << L[10] << endl ;
    //Test Case 3: Deleting Elements from the Linked List
    cout << L << endl ;
    L.remove(0) ;
    cout << L  <<endl;

    L.remove(100) ;
    cout << L <<endl;

    L.remove(2) ;
    cout << L <<endl; ;

    L.remove(2) ;
    cout << L <<endl;

    return 0;
}
