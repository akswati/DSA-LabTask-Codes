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
    // Constructor
    Person(int id = 0, string name = "", int age = 0) : per_id(id), per_name(name), per_age(age) {}

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

// LinkedList class
class LinkedList
{
private:
    Node *head;

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

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

    // Function to insert a new person at the head of the linked list
    void insertHead(const Person &person)
    {
        Node *newNode = new Node(person);
        newNode->next = head;
        head = newNode;
    }

    // Function to display all nodes in the linked list
    void display() const
    {
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

    for (int i = 0; i < n; ++i)
    {
        cout << "\nPerson " << i + 1 << ":" << endl;
        Person p;
        p.input();
        list.insertHead(p);
    }

    cout << "\nDisplaying all people in the list:" << endl;
    list.display();

    return 0;
}
