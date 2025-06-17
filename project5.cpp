#include <iostream>
#include <cmath> // for M_PI

using namespace std;

// Circle class definition
class Circle {
private:
    double radius;

public:
    Circle() : radius(0.0) {}

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

// Node structure for singly linked list
struct Node {
    Circle data;
    Node* next;
};

// Function to insert a Circle at the end of the list
void insert(Node*& head, double radius) {
    Circle c;
    c.setRadius(radius);

    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Traversal function to display all elements
void DisplayAllElements(Node* head) {
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        cout << "Position: " << position
             << " | Radius: " << current->data.getRadius()
             << " | Area: " << current->data.calculateArea() << endl;
        current = current->next;
        position++;
    }
}

// Cleanup function to deallocate memory
void freeList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
}

// Main program
int main() {
    Node* head = nullptr;
    int numCircles;
    double radius;

    cout << "How many circles would you like to enter? ";
    cin >> numCircles;

    for (int i = 0; i < numCircles; ++i) {
        cout << "Enter radius for circle " << (i + 1) << ": ";
        cin >> radius;
        insert(head, radius);
    }

    cout << "\nDisplaying all Circle elements:\n";
    DisplayAllElements(head);

    freeList(head);
    return 0;
}
