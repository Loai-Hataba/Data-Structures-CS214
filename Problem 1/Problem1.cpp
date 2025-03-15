#include <iostream>
using namespace std;
// Class that represents the Guest  :

class Guest
{
    // Attributes :
    string name;       // name of the guest
    string contact;    // the phone or email
    string iftar_date; // the date they're invited

    

public:
    // Methods :
    // Empty constructor ( for the list of  guests actually )
    Guest()
    {
        this->name = "";
        this->contact = "";
        this->iftar_date = "";
    }
    // Parametrized constructor
    Guest(const string &name, const string &contact, const string &iftar_date)
    {
        this->name = name;
        this->contact = contact;
        this->iftar_date = iftar_date;
    }
    // function to display the guest information
    void display_guest()
    {
        cout << "Guest : " << this->name << ","
             << "Contact : " << this->contact << ","
             << "Iftar date : " << this->iftar_date << endl;
    }
    // function to update the guest invitation date
    void update_invitation(const string &new_date)
    {
        this->iftar_date = new_date;
    }
    // Getter for the name
    string getGuestName()
    {
        return this->name;
    }
    // getter for the date
    string getGuestDate()
    {
        return this->iftar_date;
    }

    bool operator > (const Guest & guest ){

    }
};

// Class that represents an Iftar manger :
class IftarManger
{
    // attributes :
    Guest *guest_list;
    int size;
    int capacity;
    // function to resize the list when the capacity equals to the size (for adding new guests)
    void resize(const int &new_cap)
    {
        auto *temp = new Guest[new_cap];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = guest_list[i];
        }
        delete[] guest_list;
        capacity = new_cap;
        guest_list = temp;
    }

public:
    // empty constructor
    IftarManger()
    {
        this->size = 0;
        this->capacity = 4;
        guest_list = new Guest[this->capacity];
    }
    // function to add a new guest
    void add_guest(const Guest &guest)
    {
        if (size == capacity)
        { 
            resize(capacity + 2 );
        }
        guest_list[size] = guest;
        size++;
    }
    // Display the guests list
    void display_all_guests()
    {
        for (size_t i = 0; i < size; i++)
        {
            // using the display method in the guest class 
            guest_list[i].display_guest();
        }
    }
    // Function to update a guest information
    void update_guest_invitation(const string &name, const string &new_date)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (guest_list[i].getGuestName() == name)
            {
                cout << endl
                     << "Updating invitation for " << guest_list[i].getGuestName() << "..." << endl
                     << endl;
                guest_list[i].update_invitation(new_date);
                break;
            }
        }
    }
    // function to send a notification (Sends a reminder message to all guests on a specific dateby email.)
    void send_reminder(const string &date)
    {
    }
    // Function to sort the guest list by invitation date
    void sort_guest_list()
    {
        for (int i = 1; i < size; i++)
        {
            Guest key = guest_list[i];
            int j = i - 1;

            // Move elements of guest_list[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && guest_list[j].getGuestDate() > key.getGuestDate())
            {
                guest_list[j + 1] = guest_list[j];
                j = j - 1;
            }
            guest_list[j + 1] = key;
        }
    }
};

int main()
{
    IftarManger manager;
    // Add Guests :
    Guest guest1("Aisha", "aisha@example.com", "2025-03-15");
    Guest guest2("Omar", "omar@example.com", "2025-03-18");
    Guest guest3("Zainab", "zainab@example.com", "2025-03-20");
    // cout << "This great : " << (guest3 > guest2) << endl;
    manager.add_guest(guest1);
    manager.add_guest(guest2);
    manager.add_guest(guest3);
    // Display guest list
    manager.display_all_guests();
    // Update invitation date for Omar
    manager.update_guest_invitation("Omar", "2025-03-15");
    // Display updated guest lis
    manager.display_all_guests();
    manager.sort_guest_list();
    // Send reminders
    // manager.send_reminders("");
    return 0;
}

/**
 * The Guest Class :
 * 1- attributes :
 * a- name  , b-contact , c- iftar_date ==>> all are strings
 *
 * 2- Methods :
 * a- display_guest() void      , b-update_invitation (new_date) void
 * c- getter for date , getter for name
 *
 * 2 - iftar manager class:
 *
 * 1- attribuites :
 *
 * a- guest_list (list) , b - add_guest (guest) void , c- display_all_guests()void ,
 * d -update_guest_invitation (name , new_date ) , e- send_reminder (date)==>> sends a reminder message to all guests on specific date by email
 * f- sort_guest_list() void
 */