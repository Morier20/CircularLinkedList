# Circular Doubly Linked List

## Description
This project implements a circular doubly linked list in C++. A circular doubly linked list is a data structure where each node contains data and pointers to both previous and next nodes, with the last node connected to the first one, forming a circle.

## Features
- Add elements to the end of the list (`addNodeEnd`)
- Add elements to the beginning of the list (`addNodeStart`)
- Add elements at arbitrary positions (`addNodePos`)
- Delete elements from the beginning of the list (`deleteNodeStart`)
- Delete elements from the end of the list (`deleteNodeEnd`)
- Display all list elements (`display`)

## Project Structure
- `LinkedList.cpp` - main file with the circular doubly linked list implementation
- `node` - structure representing a list node
- `linkedListCirc` - class implementing methods for working with the list

## Technical Details
- Language: C++
- Development Environment: Microsoft Visual Studio
- Platform: Windows

## Usage
```cpp
// Create a list instance
linkedListCirc list;

// Add elements to the end of the list
list.addNodeEnd(1);
list.addNodeEnd(2);

// Add elements to the beginning of the list
list.addNodeStart(0);

// Add an element at a specific position
list.addNodePos(2, 99);

// Display all list elements
list.display();

// Delete elements
list.deleteNodeStart();
list.deleteNodeEnd();
```

## Implementation Details
The list is implemented as circular and doubly linked, allowing efficient traversal in both forward and backward directions. The list size is tracked to optimize certain operations. When adding an element at an arbitrary position, the optimal traversal path is chosen (from the beginning or from the end).

## Limitations and Known Issues
The current implementation does not support deleting elements at arbitrary positions.Methods for searching and replacing elements are missing.

## Possible Improvements
- Add a method for deleting an element by position
- Implement methods for searching elements by value
- Add iterator support for more convenient list traversal
- Add proper error handling and exception mechanisms
