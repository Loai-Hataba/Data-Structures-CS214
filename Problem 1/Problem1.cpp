#include <iostream>
using namespace std;
// Class that represents the Guest  :

class Guest
{
    // Attributes :
    string name;       // name of the guest
    string contact;    // the phone or email
    string iftar_date; // the date they're invited to the iftar

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

    bool operator>(const Guest &guest) const
    {
        if (this->iftar_date == guest.iftar_date)
        {
            return this->name > guest.name; // If same date, sort by name
        }
        return this->iftar_date > guest.iftar_date; // Primary sorting by date
    }
};

// Class that represents an Iftar manger :
class IftarManger
{
    // attributes :
    Guest *guest_list;
    int no_guests;
    int capacity;
    // function to resize the list when the capacity equals to the size (for adding new guests)
    void resize(const int &new_cap)
    {
        auto *temp = new Guest[new_cap];
        for (size_t i = 0; i < no_guests; i++)
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
        this->no_guests = 0;
        this->capacity = 4;
        guest_list = new Guest[this->capacity];
    }
    // function to add a new guest
    void add_guest(const Guest &guest)
    {
        if (no_guests == capacity)
        {
            resize(capacity + 10);
        }
        guest_list[no_guests] = guest;
        ++no_guests;
    }
    void remove_guest(const string &name)
    {
        for (size_t i = 0; i < no_guests; i++)
        {
            Guest guest = guest_list[i];
            if (guest.getGuestName() == name)
            {
                // shifting the elements to the left
                for (size_t j = i; j < no_guests; j++)
                {
                    guest_list[j] = guest_list[j + 1];
                }
                no_guests--;
                break;
            }
        }
    }

    // Display the guests list
    void display_all_guests()
    {
        for (size_t i = 0; i < no_guests; i++)
        {
            // using the display method in the guest class
            guest_list[i].display_guest();
        }
    }
    // Function to update a guest information
    void update_guest_invitation(const string &name, const string &new_date)
    {
        for (size_t i = 0; i < no_guests; i++)
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
        cout << "Sending reminders..." << endl;
        for (int i = 0; i < this->no_guests; i++)
        {
            Guest guest = guest_list[i];
            if (guest.getGuestDate() == date)
            {
                cout << "Reminder sent to " << guest.getGuestName() << ": Your Iftar invitation is on "
                    << guest.getGuestDate() << endl;
            }
        }
    }
    // Function to sort the guest list by invitation date
    void sort_guest_list()
    {
        Guest key;
        for (int i = 1; i < no_guests; i++)
        {
            key = guest_list[i];
            int j = i - 1;
            while (j >= 0 && ( guest_list[j] > key ) )
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
    
    manager.add_guest(guest1);
    manager.add_guest(guest2);
    manager.add_guest(guest3);

    // Display guest list
    manager.display_all_guests();

    // Update invitation date for Omar
    manager.update_guest_invitation("Omar", "2025-03-15");
    // Display updated guest lis
    manager.display_all_guests();

    manager.send_reminder("2025-03-15");
    return 0;
}