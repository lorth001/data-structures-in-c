# Binary Search Tree (BST)

Implements a BST and tests the following operations on it:

| Operation| Time Complexity |
|--|--|
| Insert | O(n) |
| Search | O(n) |
| Delete | O(n) |
| Delete the tree | O(n) |

> **Note**:  My implementation only allows for *integer* values to be stored in the BST.


## How to Build

If you haven't cloned the **data-structures-in-c** repo yet, do that first:

    git clone https://github.com/lorth001/data-structures-in-c.git

**cd** into the **data-structures-in-c/binary_search_tree** directory:

    cd data-structures-in-c/binary_search_tree

Issue the **make** command:

    make

And you're done.  The executable is named *main* and it is located in the **bin** directory.

>**Note**:  You can also issue the command **make valgrind** to build the program and immediately have it run with Valgrind.  This will display additional memory usage on exit.

## How to Use

Just run the **main** executable in the **data-structures-in-c/binary_search_tree/bin** directory:

    bin/main

A menu should display, prompting you to either initialize a new BST from the command line or from a file.

If you wish to initialize from a file, please see the **example_file.txt** file for an example of the expected format.  Keep in mind that when the program prompts you for a filename, it is expecting a relative filepath from the directory you started from.
