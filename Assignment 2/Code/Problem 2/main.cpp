#include <iostream>

using namespace std ;
// AVL Class
class AVL {
    // Making the Node struct
    struct Node {
        int id ;
        Node * right ;
        Node * left  ;
        // the values
        // default constructor
        Node () {
            left = right = NULL ;
            id = 0 ;
        }
        // parametrized constructor
        Node ( int id ) {
            this->id = id ;
            left = right = NULL ;
        }
    };
    // var for the root of the tree
    Node * root ;
public :
    // the constructor
    AVL() {
    root = NULL ;
}
    // function to add new node
    void insertNode (const int & id , const string & name , const string & phone , const string & email);
    //function to remove a node
    void removeNode (const int & id ) ;
    //helper function to balance the tree after inserting or deletion
    void balanceTree () ;
    // function to rotate left
    void rotateLeft () ;
    // function to rotate right
    void rotateRight () ;
    // function to rotate right left
    void rotateRL () ;
    // function to rotate left right
    void rotateLR () ;
    // function for finding  a certain node
    void search(const  int & id  ) ;
    // function to display the current data in the tree
    void listAllContacts () ;
    // function to display the tree structure
    void displayCurrentTree() ;
    // the destructor
    ~AVL () {
        // delete all the nodes

    }
};
int main() {
    // getting the input from file
    // the menu
    return 0;
}