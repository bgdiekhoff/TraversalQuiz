#include "Tree.h"

/**********************************************************************
clear()
Parameters: Node*&
Complexity: O(n)

Private method to recursively delete every node from the tree.
Complexity is O(n) because it has to remove every node
***********************************************************************/
void Tree::clear(Node*& r) {
	if (r != nullptr) { //If the node exists
		clear(r->left); //clear the left subtree
		clear(r->right);//clear the right subtree
		delete r;		//delete the current node
		r = nullptr;	//remove dangling points
	}
}

/**********************************************************************
insertAux()
Parameters: Node*&, int
Complexity: O(n)

Private method that uses recursion to insert an int into the tree.
It's passed a pointer to a node and an int to be inserted.
Complexity is O(n) because the tree may not be balanced.
***********************************************************************/
void Tree::insertAux(Node*& r, int v) {
	if (r == nullptr)	//If the passed node doesn't exist
		r = new Node(v); //make a new one from the heap containing the 
	//passed int

	else {				// If the passed node does exist
		r->size++;		// increment the size value of this node

		if (v < r->val)				// If the passed int is less than the 
			insertAux(r->left, v);	// value of this node, go to the left 
									//subtree

		else						// if the passed int is greater than or
			insertAux(r->right, v);	// equal to the value of this node, go
	}								// to the left subtre			
}

/**********************************************************************
removeAux()
Parameters: Node*&, int
Complexity: O(n)

Private method that uses recursion to remove a node from the tree.
It's passed a pointer to a node and an int to be removed.
Complexity is O(n) because the tree may not be balanced.
***********************************************************************/
void Tree::removeAux(Node*& r, int v) {
	// Case 1: Node isn't found or tree doesn't exist
	if (r == nullptr) {
		return; //nothing to be done, the node doesn't exist in our tree
	}

	// We have determined we have a tree, now we can search for the node
	else {
		if (v < r->val) {			// If v is less than the value of the node,
			r->size--;				// decrment the size of nodes along the
			removeAux(r->left, v);	// path and go to the left subtree.
		}
		else
			if (v > r->val) {			// If v is less than the value of the 
				r->size--;				// node, decrement size and go to the right subtree.
				removeAux(r->right, v);
			}

			else //The node to be removed has been found and r points to it.
	// Case 2: The node has two children

				if (r->left != nullptr && r->right != nullptr) {
					// Find the successor by going right and all the way left
					Node* temp = r->right;  // temp points to node to the right
					Node* back = r->right;	// back points to node to the right

					while (temp->left != nullptr) {   // go all the way left
						back = temp;         // back points to previous node
						temp = temp->left; // temp points to node to the left
					}
					//when left is nullptr, temp points to successor node, copy
					//the successor node's value and size to its replacement
					r->val = temp->val;
					r->size = temp->size;

					// If we did not go left at all just splice temp node out
					if (r->right == temp) {
						r->right = temp->right;
						delete temp;
					}
					else {//we did go left so splice out temp here
						back->left = temp->right;
						delete temp;
					}
				}
	//  Case 3: Node has less than two children.
				else {
					if (r->left != nullptr) { // If node has a left subtree
						Node* t = r;// new r is sent back thru ref parameter
						r = r->left;
						delete t;
					}
					else {// r->right is not null or it is (remember 0 is less than two children)
						Node* t = r; //t points to node to be deleted
						r = r->right;	// r either points to right subnode
										// or nullptr
		// new r is sent back thru ref parameter
						delete t;
					}
				}

	}
	return;
}

/**********************************************************************
displayInOrder()
Parameters: Node*&
Complexity: O(n)

Private method that uses recursion to print the value of every node int the
tree in ascending order.
It's passed a pointer to a node and an ostream type that determines how it
outputs the information.
Complexity is O(n) because it has to go to and print every node in the
tree.
***********************************************************************/
void Tree::displayInOrder(Node*& r)const {
	if (r != nullptr) {
		displayInOrder(r->left);// print left sub tree
		cout << r->val << " ";
		displayInOrder(r->right);//print right sub tree
	}

}

/**********************************************************************
displayNumNodes()
Parameters: Node*&
Complexity: O(n)

Private method that uses recursion to return the total number of nodes in the
tree.
It's passed a pointer to a node.
Complexity is O(n) because the method has to go to and count every node in
the tree.
***********************************************************************/
int Tree::displayNumNodes(Node*& r)const {
	if (r == nullptr)
		return 0;
	else
		return 1 + displayNumNodes(r->left) + displayNumNodes(r->right);
}


/**********************************************************************
searchAux()
Parameters: Node*&, int
Complexity: O(n)

Private method that uses recursion to search for a node in the tree and return
true or false depending on whether it's found.
It's passed a pointer to a node and an int to be searched for.
Complexity is O(n) because the tree may not be balanced.
***********************************************************************/
bool Tree::search(Node*& r, int v)const {
	if (r == nullptr) {				//v is not found
		return false;
	}

	if (v < r->val)
		search(r->left, v);		//go left

	else if (v > r->val)
		search(r->right, v);		//go right
	else                            // v is found
		return true;

}