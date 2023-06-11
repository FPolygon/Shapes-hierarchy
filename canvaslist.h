/*The provided header file, "CanvasList.h," contains the definition of two classes: "ShapeNode" and "CanvasList." The "ShapeNode" class represents a node in a linked list and contains a pointer to a "Shape" object and a pointer to the next node. The "CanvasList" class represents the linked list itself and provides a range of member functions to manipulate the list. These functions include inserting a shape at a specified index, adding shapes to the front or back of the list, removing shapes at a given index or from the front or back of the list, and accessing information about the list such as its size and the shape at a particular index. The "CanvasList" class also includes functions to draw the shapes on a canvas and print the memory addresses of the shapes and nodes in the list. Overall, this header file provides a flexible and efficient implementation of a linked list data structure specifically designed to store and manage shapes in a canvas-like environment.*/

#pragma once

#include "shape.h"  // include the header file for Shape class
#include <iostream>

using namespace std;

class ShapeNode
{
public:
    Shape *value;  // a pointer to a Shape object
    ShapeNode *next;  // a pointer to the next node in the list
};

class CanvasList
{
private:
    int listSize;  // the size of the list
    ShapeNode *listFront;  // a pointer to the first node in the list
    
public:
    // Constructors
    CanvasList();  // default constructor
    CanvasList(const CanvasList &);  // copy constructor
    CanvasList operator=(const CanvasList &);  // assignment operator
    
    // Destructor
    virtual ~CanvasList();  // destructor
    void clear();  // function to delete all nodes in the list
    
    // Mutators
    void insertAfter(int, Shape *);  // function to insert a Shape after a given index
    void push_front(Shape *);  // function to add a Shape to the front of the list
    void push_back(Shape *);  // function to add a Shape to the back of the list
    
    void removeAt(int);  // function to remove a Shape at a given index
    Shape* pop_front();  // function to remove and return the Shape at the front of the list
    Shape* pop_back();  // function to remove and return the Shape at the back of the list
    
    // Accessors
    ShapeNode* front() const;  // function to return a pointer to the first node in the list
    bool isempty() const;  // function to check if the list is empty
    int size() const;  // function to return the size of the list
    
    int find(int, int) const;  // function to find the index of a Shape at a given (x,y) coordinate
    Shape* shapeAt(int) const;  // function to return the Shape at a given index
    
    void draw() const;  // function to draw all Shapes in the list
    void printAddresses() const;  // function to print the addresses of all Shapes in the list
};

// Default constructor
inline CanvasList::CanvasList() {
    listSize = 0;
    listFront = nullptr;
}

// Copy constructor
inline CanvasList::CanvasList(const CanvasList& other) {
    listSize = 0;
    listFront = nullptr;

    // iterate over other list and copy each Shape
    ShapeNode* otherNode = other.listFront;
    while (otherNode != nullptr) {
        Shape* shapeCopy = otherNode->value->copy();  // make a copy of the Shape
        push_back(shapeCopy);  // add the copy to the new list
        otherNode = otherNode->next;
    }
}

// Assignment operator
inline CanvasList CanvasList::operator=(const CanvasList& other) {
    if (this != &other) {   // check for self-assignment
        clear();            // clear the current list

        // iterate over other list and copy each Shape
        ShapeNode* otherNode = other.listFront;
        while (otherNode != nullptr) {
            Shape* shapeCopy = otherNode->value->copy();  // make a copy of the Shape
            push_back(shapeCopy);  // add the copy to the new list
            otherNode = otherNode->next;
        }
    }
    return *this;
}

// Destructor
CanvasList::~CanvasList() {
    clear();
}

// Function to delete all nodes in the list
void CanvasList::clear()
{
    // set a pointer to the front of the list
    ShapeNode* current = listFront;
    // iterate through the list and delete each node
    while (current != nullptr) {
        ShapeNode* next = current->next;
        delete current->value;  // delete the shape object
        delete current;  // delete the node object
        current = next;  // move on to the next node
    }
    // set the front of the list to null and reset the size counter
    listFront = nullptr;
    listSize = 0;
}

// Function inserts a new node with a given shape after the node at a specified index
void CanvasList::insertAfter(int index, Shape* shape) {
    // check if the shape pointer is nullptr and throw an exception if it is
    if (shape == nullptr) {
        throw std::invalid_argument("Shape pointer cannot be nullptr");
    }

    // check if the index is out of range and throw an exception if it is
    if (index < 0 || index > listSize) {
        throw std::out_of_range("Index out of range");
    }

    // set a pointer to the node at the index before the insertion point
    ShapeNode* current = listFront;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    // create a new node and insert it after the current node
    ShapeNode* newNode = new ShapeNode();
    newNode->value = shape;
    newNode->next = current->next;
    current->next = newNode;
    listSize++;
}


// Function inserts a new node with a given shape at the front of the list
void CanvasList::push_front(Shape* shape) {
    // create a new node with the given shape and insert it at the front of the list
    ShapeNode* newNode = new ShapeNode();
    newNode->value = shape;
    newNode->next = listFront;
    listFront = newNode;
    listSize++;
}

// Function inserts a new node with a given shape at the end of the list
inline void CanvasList::push_back(Shape* shape) {
    // create a new node with the given shape and insert it at the end of the list
    ShapeNode* newNode = new ShapeNode();
    newNode->value = shape;
    newNode->next = nullptr;

    // if the list is empty, set the front of the list to the new node
    if (isempty()) {
        listFront = newNode;
    } else {
        // otherwise, find the last node in the list and set its next pointer to the new node
        ShapeNode* currNode = listFront;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    listSize++;
}

// Function to remove a Shape at a given index
void CanvasList::removeAt(int index) {
    if (index < 0 || index >= listSize) {
        return;
    }

    if (index == 0) {
        ShapeNode* nodeToRemove = listFront;
        listFront = nodeToRemove->next;
        delete nodeToRemove;
        listSize--;
        return;
    }

    ShapeNode* prevNode = nullptr;
    ShapeNode* currNode = listFront;
    for (int i = 0; i < index; i++) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == nullptr) {
        return; // This index does not exist
    }

    prevNode->next = currNode->next;
    delete currNode;
    listSize--;
}


// Function to remove and return the Shape at the front of the list
Shape* CanvasList::pop_front() {
    // Check if the list is empty
    if (listSize == 0) {
        return nullptr; // If empty, return nullptr
    }

    ShapeNode* nodeToRemove = listFront;
    listFront = nodeToRemove->next; // Set the front to the next node
    Shape* shapeToReturn = nodeToRemove->value; // Get the value of the node to remove
    delete nodeToRemove; // Delete the node to remove
    listSize--; // Decrement the size of the list

    return shapeToReturn; // Return the value of the node removed
}

// Function to remove and return the Shape at the back of the list
Shape* CanvasList::pop_back() {
    // Check if the list is empty
    if (listSize == 0) {
        return nullptr; // If empty, return nullptr
    }

    ShapeNode* nodeToRemove = nullptr;
    if (listSize == 1) { // If the list only has one node
        nodeToRemove = listFront;
        listFront = nullptr; // Set the front to null
    } else { // If the list has more than one node
        ShapeNode* prevNode = listFront;
        for (int i = 0; i < listSize - 2; i++) { // Traverse the list until the last node is reached
            prevNode = prevNode->next;
        }
        nodeToRemove = prevNode->next;
        prevNode->next = nullptr; // Set the previous node's next pointer to null
    }

    Shape* shapeToReturn = nodeToRemove->value; // Get the value of the node to remove
    delete nodeToRemove; // Delete the node to remove
    listSize--; // Decrement the size of the list

    return shapeToReturn; // Return the value of the node removed
}

ShapeNode* CanvasList::front() const {
    return listFront; // Return the front node
}

bool CanvasList::isempty() const {
    return listFront == nullptr; // Check if the list is empty
}

// Function to return the size of the list
int CanvasList::size() const {
    int count = 0;
    ShapeNode* current = listFront;
    while (current != nullptr) { // Traverse the list and count the number of nodes
        count++;
        current = current->next;
    }
    return count; // Return the size of the list
}

// Function searches the list for a Shape object with the specified x and y coordinates
int CanvasList::find(int x, int y) const {
    int index = 0;
    ShapeNode* current = listFront;
    while (current != nullptr) {
        if (current->value->getX() == x && current->value->getY() == y) {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;  // indicates not found
}

// Function returns the Shape object at the specified index in the list
Shape* CanvasList::shapeAt(int index) const {
    if (index < 0 || index >= listSize) {
        return nullptr;
    }
    ShapeNode* current = listFront;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

// Function prints out the type of each Shape object in the list using the printShape() method of the Shape class
void CanvasList::draw() const {
    for (ShapeNode* current = listFront; current != nullptr; current = current->next) {
        cout << "It's a ";
        current->value->printShape();
    }
}

// Function prints out the memory addresses of each Shape object and its corresponding ShapeNode object in the list
void CanvasList::printAddresses() const {
    ShapeNode* current = listFront;
    while (current != nullptr) {
        cout << "Node Address: " << current << "\tShape Address: " << current->value << "\n";
        current = current->next;
    }
}
