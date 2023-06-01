#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Zodiac {
    string surname;
    string name;
    string zodiacSign;
    int birthday[3];
    Zodiac* next;
};

Zodiac* createNode() 
{
    Zodiac* newNode = new Zodiac;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Zodiac*& head) 
{
    Zodiac* newNode = createNode();

    cout << "Enter surname: ";
    cin >> newNode->surname;
    cout << "Enter name: ";
    cin >> newNode->name;
    cout << "Enter zodiac sign: ";
    cin >> newNode->zodiacSign;
    cout << "Enter birthday (day month year): ";
    cin >> newNode->birthday[0] >> newNode->birthday[1] >> newNode->birthday[2];

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Zodiac* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Data inserted successfully.\n";
}

void displayList(Zodiac* head)
{
    if (head == nullptr) {
        cout << "List is empty.\n";
    }
    else {
        cout << "List of Zodiac records:\n";
        cout << "Surname\t\tName\t\tZodiac Sign\t\tBirthday\n";
        cout << "------------------------------------------------------\n";
        Zodiac* temp = head;
        while (temp != nullptr) {
            cout << temp->surname << "\t\t" << temp->name << "\t\t" << temp->zodiacSign << "\t\t\t"
                << temp->birthday[0] << "-" << temp->birthday[1] << "-" << temp->birthday[2] << "\n";
            temp = temp->next;
        }
    }
}

void sortList(Zodiac*& head) 
{
    if (head == nullptr || head->next == nullptr) {
        return;  // No need to sort empty or single-element list
    }

    bool swapped;
    do {
        swapped = false;
        Zodiac* prevNode = nullptr;
        Zodiac* currentNode = head;
        Zodiac* nextNode = currentNode->next;

        while (nextNode != nullptr) {
            if (currentNode->birthday[2] > nextNode->birthday[2] ||  // Sort by year
                (currentNode->birthday[2] == nextNode->birthday[2] && currentNode->birthday[1] > nextNode->birthday[1]) ||  // Sort by month
                (currentNode->birthday[2] == nextNode->birthday[2] && currentNode->birthday[1] == nextNode->birthday[1] && currentNode->birthday[0] > nextNode->birthday[0]))  // Sort by day
            {
                // Swap nodes
                if (prevNode == nullptr) {
                    head = nextNode;
                }
                else {
                    prevNode->next = nextNode;
                }
                currentNode->next = nextNode->next;
                nextNode->next = currentNode;
                prevNode = nextNode;
                nextNode = currentNode->next;
                swapped = true;
            }
            else {
                prevNode = currentNode;
                currentNode = nextNode;
                nextNode = nextNode->next;
            }
        }
    } while (swapped);
}

void searchRecord(Zodiac* head, const string& surname) 
{
    if (head == nullptr) {
        cout << "List is empty.\n";
    }
    else {
        Zodiac* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->surname == surname) {
                cout << "Record found:\n";
                cout << "Surname\t\tName\t\tZodiac Sign\t\tBirthday\n";
                cout << "------------------------------------------------------\n";
                cout << temp->surname << "\t\t" << temp->name << "\t\t" << temp->zodiacSign << "\t\t\t"
                    << temp->birthday[0] << "-" << temp->birthday[1] << "-" << temp->birthday[2] << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Record not found.\n";
        }
    }
}

int main() {
    Zodiac* head = nullptr;
    int choice;
    string searchSurname;

    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Insert a record\n";
        cout << "2. Display all records\n";
        cout << "3. Sort records by birthday\n";
        cout << "4. Search for a record by surname\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertNode(head);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            sortList(head);
            cout << "Records sorted by birthday.\n";
            break;
        case 4:
            cout << "Enter surname to search: ";
            cin >> searchSurname;
            searchRecord(head, searchSurname);
            break;
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
