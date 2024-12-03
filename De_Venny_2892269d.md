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


## Memory Management
