#include <iostream>
using namespace std;
// Class that represents the Guest  :

class Guest
{
    // Attributes :
    string name;       // name of the guest
    string contact;    // the phone or email
    string iftar_date; // the date they'r invited
public:
    // Methods :
    Guest()
    {
        this->name = "";
        this->contact = "";
        this->iftar_date = "";
    }
    Guest(const string & name, const string & contact, const string & iftar_date)
    {
        this->name = name;
        this->contact = contact;
        this->iftar_date = iftar_date;
    }

    void display_guest()
    {
        cout << "Guest : " << this->name << ","
             << "Contact : " << this->contact << ","
             << "Iftar date : " << this->iftar_date << endl;
    }
    void update_invitation(const string & new_date)
    {
        this->iftar_date = new_date;
    }
    string getGuestName ( ) {
        return this->name ;
    }
    string getGuestDate () {
        return this->iftar_date ;
    }
};

// Class that represents an Iftar manger :
class IftarManger
{
    // attributes :
    Guest *guest_list;
    int size;
    int capacity;
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
    IftarManger () {
        this->size = 0;
        this->capacity = 2;
        guest_list = new Guest[this->capacity];

    }
    // function to add a new guest
    void add_guest(const Guest &guest)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        guest_list[size] = guest;
        size++;
    }
    // Display the guests list
    void display_all_guests()
    {
        for (size_t i = 0; i < size; i++)
        {
            guest_list[i].display_guest();
        }
    }
    // Function to update a guest information
    void update_guest_invitation(const string &name, const string &new_date)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (guest_list[i] . getGuestName() == name )
            {
                cout << endl<<"Updating invitation for " << guest_list[i].getGuestName() << "..."<< endl <<endl;
                guest_list[i].update_invitation(new_date);
                break ;
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
        // using insertion sort because it better for this type of lists
        string key  ;
        int j = 0 ;
        for (size_t i = 1; i < size  ; i++)
        {
            key = guest_list[i].getGuestDate();
            j = i - 1 ;

            while (j>=0 && key < guest_list[j].getGuestDate())
            {
                guest_list[j+1] = guest_list[j];
                j--;
            }
            // we have found the correct position for the key
            guest_list[j + 1].getGuestDate() =key ;
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

