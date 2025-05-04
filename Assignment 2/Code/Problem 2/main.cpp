#include <iostream>

using namespace std ;
struct Info {
    string name ;
    string phone ;
    string email ;
    // default constructor
    Info () {
       this-> name =this-> phone =this-> email = "" ;
    }
    Info (string const & name , string const & phone , string const & email) {
        this->name = name ;
        this->phone = phone ;
        this->email = email ;
    }

};
// Making the Node struct
struct Node {
    int id ;
    Info info ;
    Node * right ;
    Node * left  ;
    // parametrized constructor
    Node (const int & id , const Info & info ) {
        this->id = id ;
        this->info = info ;
        left = right = NULL ;
    }
};

// AVL Class
class AVL {
    // var for the root of the tree
    Node * root ;
    /// the private functions that we will be recursive
    // function insert a node
       Node * insert (Node * root , const int id , const Info &  info) ;
    // function to delete a node
       Node * remove (Node * root , const int &id) ;
    // function to search a node
       Node * search (Node * root , const int & id) ;
    // function to rotate left
    Node *  rotateLeft (Node *  &root )  ;
    // function to rotate right
    Node  rotateRight (Node * & root) ;
    // function to rotate right left
    Node rotateRL (Node * & root) ;
    // function to rotate left right
    Node  rotateLR (Node * & root) ;
    //helper function to balance the tree after inserting or deletion
    void balanceTree () ;
    // function to delete all the nodes in the tree
    void deleteAllNodes (Node * r ) {
        if (r == nullptr) return ;
        deleteAllNodes (r->left ) ;
        deleteAllNodes (r->right) ;
        delete r ;
    }
public :
    // the constructor
    AVL() {
    root = NULL ;
}
    /// the functions that must use the recursive functions
    // function to add new node
    void insertContact (const int & id , const string & name , const string & phone , const string & email);
    //function to remove a node
    void deleteContact (const int & id ) ;
    // function for finding  a certain node
    void searchContact(const  int & id  ) ;
    // function to display the current data in the tree
    void listAllContacts () ;
    // function to display the tree structure
    void displayTreeStructure() ;
    // the destructor
    ~AVL () {
        // delete all the nodes using (deleteAllNodes function )
        deleteAllNodes (root ) ;
    }
};
int main() {
    // getting the input from file
    // the menu
    return 0;
}