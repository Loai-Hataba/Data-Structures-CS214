#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

//! First we need to make the stack data structure
class Stack
{
private:
    struct Node
    {
        string data;
        Node *next; // Pointer to the next node
        // Constructor to initialize the node
        Node() : data(""), next(nullptr) {}
    };

    Node *top;

public:

    // Constructor to initialize the stack
    Stack()
    {
        top = nullptr;
    }

    // Destructor to free the memory
    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push a new element onto the stack
    // The function takes a string as an argument and creates a new node with that string
    void push(const string &item)
    {

        Node *newElement = new Node;
        newElement->data = item;
        newElement->next = top;
        top = newElement;
    }

    // Pop the top element from the stack
    // The function returns the string data of the popped node
    string pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        else
        {
            string item = top->data; // Get the data from top node
            Node *temp = top;        // Store the top node to delete it
            top = top->next;         // Move top to next node
            delete temp;             // Free the memory
            return item;
        }
    }
   
    // function to check if the stack is empty
    // The function returns true if the stack is empty, false otherwise
    bool isEmpty() const
    {
        return (top == nullptr);
    }
    // function to get the top element of the stack
    // The function returns the string data of the top node
    void printStack()
    {
        Node *current = top;
        cout << "[";
        while (current != nullptr)
        {
            cout << "\"" << current->data << "\" , ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};
// Now the BrowserHistory class
class BrowserHistory
{
private:
    // Two stacks to keep track of the back and forward history
    // The back stack stores the URLs visited before the current URL
    // The forward stack stores the URLs visited after the current URL
    Stack backStack;
    Stack forwardStack;
    string currentUrl;

public:

    // Constructor to initialize the browser history 
    BrowserHistory()
    {
        currentUrl = "";
    }

    // The visit function takes a URL as an argument and pushes the current URL onto the back stack
    // and clears the forward stack
    void visit(string url)
    {
        if (!currentUrl.empty()) {  // Only push if currentUrl is not empty
            backStack.push(currentUrl);
        }
        currentUrl = url;
        while (!forwardStack.isEmpty())
        {
            forwardStack.pop();
        }
    }

    // The goBack function pops the top URL from the back stack and pushes the current URL onto the forward stack
    // The function returns the previous URL if available, otherwise it returns the current URL
    string goBack()
    {
        if (backStack.isEmpty())
        {
            cout << "No previous URL" << endl;
            return currentUrl;
        }
        if (currentUrl == "")
        {
           cout << "No current URL" << endl;
            return "";
        }
        string previousUrl = backStack.pop();
        forwardStack.push(currentUrl);
        currentUrl = previousUrl;
        return currentUrl;
    }

    // The goForward function pops the top URL from the forward stack and pushes the current URL onto the back stack
    // The function returns the next URL if available, otherwise it returns the current URL
    string goForward()
    {
        if (forwardStack.isEmpty())
        {
            cout << "No forward URL" << endl;
            return "";
        }
        if (currentUrl == "")
        {
            cout << "No current URL" << endl;
            return "";
        }
        
        string nextUrl = forwardStack.pop();
        backStack.push(currentUrl);
        currentUrl = nextUrl;
        return currentUrl;
    }

    // The printHistory function prints the back and forward stacks
    // and the current URL
    // The function uses the printStack function of the Stack class to print the stacks
    void printHistory()
    {
        cout << "Back Stack: ";
        backStack.printStack();
        cout << "Forward Stack: ";
        forwardStack.printStack();
        cout << "Current URL: " << currentUrl << endl
             << endl;
    }
};
int main()
{

    while (true)
    {
        string fileName;
        cout << "Please enter the file name (without extension): ";
        cin >> fileName;
        fileName += ".txt";
        try
        {
            ifstream fileInput(fileName);
            if (!fileInput.is_open())
            {
                throw R"(Error: Could not open the file.)";
            }
            BrowserHistory browser ;
            string line;
            while (getline(fileInput, line))
            {
                if (line.empty())
                    continue;
                istringstream iss(line);
                int choice;
                if (!(iss >> choice))
                    continue;
                switch (choice)
                {
                case 1:
                {
                    string url;
                    if (!(iss >> url))
                        continue;
                    browser.visit(url);
                    cout << "Visited: " << url << endl;
                    break;
                }
                case 2:
                {
                    string url = browser.goBack();
                    if (!url.empty())
                        cout << "Went back to: " << url << endl;
                    break;
                }
                case 3:
                {
                    string url = browser.goForward();
                    if (!url.empty())
                        cout << "Went forward to: " << url << endl;
                    break;
                }
                case 4:
                {
                    browser.printHistory();
                    break;
                }
                default:
                    cout << "Invalid choice found in the file " << endl;
                    break;
                }
            }

           fileInput.close(); 
           // Ask the user if they want to continue with another file
            int continueOption;
            cout << "Do you want to test another file? (1) Yes / (2) No: ";
            // validate the input choice & if not valid throw exception
            if (!(cin >> continueOption))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw R"(Error: Invalid input.)";
            }
            // The user choose to stop
            if (continueOption == 2)
            {
                cout << "Exiting..." << endl;
                return 0;
            }
            // getting another file input
            cout << "\n--- Restarting with another file ---\n\n";
        }
        catch (const char *error)
        {
           cout << error << endl;
            cout << "Retrying...\n\n";
        }
    }

    return 0;
}


