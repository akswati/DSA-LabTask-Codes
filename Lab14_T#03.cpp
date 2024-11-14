#include <iostream>
#include <string>
using namespace std;

// Person class
class Person
{
private:
    int per_id;
    string per_name;
    int per_age;

public:
    // Constructor to initialize Person object
    Person(int id = 0, string name =" ", int age = 0) : per_id(id), per_name(name), per_age(age) {}

    // Input function to set values for the person
    void input()
    {
        cout << "Enter ID: ";
        cin >> per_id;
        cout << "Enter Name: ";
        cin.ignore(); // To ignore any leftover newline character
        getline(cin, per_name);
        cout << "Enter Age: ";
        cin >> per_age;
    }

    // Output function to display the person's information
    void output() const
    {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

// Node structure to represent each node in the linked list
struct Node
{
    Person person;
    Node *next;

    // Constructor to initialize a new node
    Node(const Person &p) : person(p), next(nullptr) {}
};

// LinkedList class to manage the list
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up memory
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert a new person at the tail of the linked list
    void insertTail(const Person &person)
    {
        Node *newNode = new Node(person);
        if (tail == nullptr)
        {
            head = tail = newNode; // If list is empty, head and tail are the same
        }
        else
        {
            tail->next = newNode;
            tail = newNode; // Move the tail to the new node
        }
    }

    // Function to display all nodes in the linked list
    void display() const
    {
        if (head == nullptr)
        {
            cout << "The list is empty!" << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            current->person.output();
            current = current->next;
        }
    }
};

// Main function to test the implementation
int main()
{
    LinkedList list;
    int n;
    cout << "Enter the number of people to add to the list: ";
    cin >> n;

    // Insert people into the linked list
    for (int i = 0; i < n; ++i)
    {
        cout << "\nPerson " << i + 1 << ":" << endl;
        Person p;
        p.input();
        list.insertTail(p);
    }

    // Display all people in the list
    cout << "\nDisplaying all people in the list:" << endl;
    list.display();

    return 0;
}
