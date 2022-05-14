# Singly Linked List

A little program that builds singly linked lists and performs the following operations on them:

| Operation| Time Complexity |
|--|--|
| Insert at the beginning | O(1) |
| Insert at the end | O(n) |
| Insert after an element | O(1) on its own, but O(n) with the required search |
| Search | O(n) |
| Delete | O(1) on its own, but O(n) with the required search |
| Delete the list | O(n) |

> **Note**:  This linked list implementation only allows for *integer* values to be stored in the list.


## How to Build

If you haven't cloned the **data-structures-in-c** repo yet, do that first:

    git clone https://github.com/lorth001/data-structures-in-c.git

Then **cd** into the **data-structures-in-c/singly_linked_list** directory:

    cd data-structures-in-c/singly_linked_list

Now issue the **make** command:

    make

Done!  The executable is named *main* and it is located in the **bin** directory.

>**Note**:  You can also issue the command **make valgrind** to build the program and immediately have it run with Valgrind.  This will display additional memory stats upon exiting the program.

## How to Use

To run the program (assuming it's built and you're in the **singly_linked_list** directory), enter:

    bin/main

A menu should display, prompting you to either initialize a new list from the command line or from a file.  Enter the number for the option you want.

If you wish to initialize from a file, please see the **example_list.txt** file for an example of the expected format.  Keep in mind that when the program prompts you for a filename, it is expecting a relative filepath from the directory you are currently in.
