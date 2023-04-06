# Data-structure
The program is designed to implement a directory structure for a file system using a binary search tree (BST) data structure. 
The program consists of several functions that implement the various operations supported by the directory structure. These functions include:
insert_node: Inserts a new directory into the BST. The function takes a directory name as input and creates a new node in the tree with the specified name.
delete_node: Deletes an existing directory from the BST. The function takes a directory name as input and removes the corresponding node from the tree. If the directory has subdirectories or files, they will be deleted recursively.
search_node: Searches for a directory in the BST by name. The function takes a directory name as input and returns a pointer to the corresponding node if it exists in the tree.
traverse: Traverses the BST in pre-order, in-order, or post-order. The function takes a traversal mode as input and prints the directory names in the specified order.
print_tree: Prints the directory structure in a formatted way, with each directory at the appropriate level and aligned. The function takes a pointer to the root node of the BST as input and recursively prints the subdirectories and files.
The program also includes a command-line interface that allows users to interact with the directory structure. The interface prompts the user for input and calls the appropriate function to perform the requested operation.
