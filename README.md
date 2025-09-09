📋 Description

This C library provides a complete implementation of a singly linked list structure with integer values. It includes functions for creation, manipulation, connection, and memory management of cell nodes, demonstrating fundamental data structure concepts.
✨ Features

    Cell Creation & Management: Create, set, and get cell values

    List Operations: Connect, disconnect, and traverse linked lists

    Memory Management: Proper allocation and deallocation of cells

    Advanced Manipulation: Push, pop, and back operations

    Debugging Support: Built-in testing and visualization functions

📚 API Reference
Core Functions

    int_new_Cell(int value) - Creates a new cell with given value

    int_Cell_set(ref_int_Cell cell, int value) - Sets cell value

    int_Cell_get(ref_int_Cell cell) - Retrieves cell value

    int_Cell_print(ref_int_Cell cell) - Prints entire list

Connection Operations

    int_Cell_connect(ref_int_Cell this, ref_int_Cell other) - Connects two cells

    int_Cell_disconnect(ref_int_Cell this, ref_int_Cell other) - Disconnects cells

Advanced Operations

    int_Cell_get_back(ref_int_Cell cell) - Returns reference to last cell

    int_Cell_get_before_back(ref_int_Cell cell) - Returns reference to second-to-last cell

    int_Cell_push_back(ref_int_Cell this, ref_int_Cell other) - Appends cell to end

    int_Cell_pop_back(ref_int_Cell this) - Removes last cell

Testing

    int_Cell_test() - Comprehensive test function demonstrating all features
    
🛠️ Compilation
bash

gcc -Wall -Wextra -std=c99 -o cell_demo cell_library.c main.c

💡 Key Features

    Null Safety: Proper handling of null pointers

    Memory Safety: Manual memory management with error checking

    Educational Value: Demonstrates linked list concepts

    Comprehensive Testing: Built-in test suite

    Efficient Traversal: Optimized cell navigation

⚠️ Important Notes

    Always free allocated memory after use

    Check for null returns from allocation functions

    The library uses global variable global_tests for operation counting

    Cells must be properly disconnected before freeing

📋 Requirements

    C99 compatible compiler

    Standard C library

This library is perfect for educational purposes, data structure implementation, or as a foundation for more complex linked list applications.
