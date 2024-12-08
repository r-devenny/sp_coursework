# Systems Programming Assessed Exercise 1

Robert De Venny (2892269d)

## Search
The search method uses the binary search tree's property (left child values are smaller, right child values are larger) to recursively traverse the tree in search of the target value.

- If the current node is `NULL`, it means the target value is not present in the tree, and the function returns `NULL`.
- If the current node's value matches the target value, the function returns the current node.
- Otherwise, the algorithm determines whether to traverse the left or right subtree based on whether the target value is smaller or larger than the current node's value. It then recursively calls itself with the appropriate child node.

## Generation
### Creation
- The create tree method initialises a new instance of the `node_t` struct and assignes it some memory.
- It then assigns the value attribute to the argument `firstElem` and sets the child pointers to `NULL` values.
- Returns the created node/root.

### Destroying
- The destroy tree method makes use of a post-order recursive algorithm in order to delete/free nodes from 'the bottom up'. 
- This approach ensures that there are no dangling pointers or orphanded child nodes as it always removes children before their parents.
It removes the nodes by freeing their space in memory.

## Maintenance
### Insertion
- The insertion method uses a while true loop to loop(traverse) through the tree until a `NULL` node or a node with a duplicate value to the one trying to be inserted. If a `NULL` node is found the `createTree` method is called to create a new node and set it to the left or right child of the current node.
- If the value of the new node continues to be less than the current node it traverses the left subtree otherwise it traverses the right subtree until a `NULL` node is found.
- It identifies a duplicate when the value of the new node is not higher or lower than the value of the current node in the traversal.

### Deletion

The delete method removes a specified value from the binary search tree while maintaining its structural integrity.
- It begins by searching for the target node and tracking its parent.
  - If the node is not found, the function exits without making any changes.
- If the node to be deleted is a leaf node:
  - The function simply removes it by updating the parent’s pointer and freeing the memory associated with the node.
- If the node has one child:
  - The function replaces the node with its single child by updating the parent’s pointer to bypass the current node.
  - The memory allocated to the deleted node is then freed.
- If the node has two children:
  - The method finds the node's in-order successor (the smallest node in the right subtree).
  - The in-order successor’s value replaces the current node's value, effectively moving the successor’s value into the position being deleted.
  - The successor node is then recursively deleted, ensuring it is properly removed from the tree.

This approach ensures that the binary search tree properties are preserved after any deletion.

## Memory Management

- My code is memory safe as free calls are used in the deletion and destroy methods. This frees memory that was previously allocated in the `createTree` method. 
- This ensures no memory leaks as there are no pointers pointing to empty memory.