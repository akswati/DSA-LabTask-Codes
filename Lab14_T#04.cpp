#include <iostream>
using namespace std;

// Define the Node structure to represent each node in the linked list
struct Node {
    int data;
    string position; // To store where the node was inserted ("Head" or "Tail")
    Node* next;

    // Constructor to initialize a new node
    Node(int value, const string& pos) : data(value), position(pos), next(nullptr) {}
};

// LinkedList class to manage the list
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the head of the linked list
    void insertHead(int value) {
        Node* newNode = new Node(value, "Head");
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = head;  // If the list was empty, head and tail should be the same
        }

        cout << "Node " << value << " inserted from Head." << endl;
    }

    // Function to insert a new node at the tail of the linked list
    void insertTail(int value) {
        Node* newNode = new Node(value, "Tail");

        if (tail == nullptr) {
            head = tail = newNode;  // If the list is empty, head and tail are the same
        } else {
            tail->next = newNode;
            tail = newNode;  // Move the tail to the new node
        }

        cout << "Node " << value << " inserted from Tail." << endl;
    }

    // Function to display all nodes in the linked list along with their positions
    void display() const {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        Node* current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " (" << current->position << ") ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to insert nodes alternately from head and tail
    void insertAlternately(int n) {
        bool insertFromHead = true; // To toggle between head and tail
        for (int i = 1; i <= n; ++i) {
            cout << "\nEnter value for Node " << i << ": ";
            int value;
            cin >> value;

            if (insertFromHead) {
                insertHead(value);
            } else {
                insertTail(value);
            }

            insertFromHead = !insertFromHead; // Toggle the insertion point (head <-> tail)
        }
    }

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int n;

    // Ask for the number of nodes to insert
    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    // Insert nodes alternately from head and tail
    list.insertAlternately(n);

    // Display the final linked list
    cout << "\nDisplaying the linked list:\n";
    list.display();

    return 0;
}
