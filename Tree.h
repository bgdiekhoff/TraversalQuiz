#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Tree {
private:
	struct Node {
		int val;
		int size;
		Node* left;
		Node* right;
		Node(int v, Node* l = nullptr, Node* r = nullptr) : // colon in the constructor indicates an intialization list
			val(v), size(1), left(l), right(r) {}; // not necessary, but a cool thing to know

	};

	Node* root;

public:
	Tree() :root(nullptr) {}; //another initialization list for our Tree constructor
	~Tree() { //destructor
		clear(root);
	}
	void insert(int v) {
		insertAux(root, v);
	}
	void remove(int v) {
		if (search(root, v) == true) {
			removeAux(root, v);
		}
	}
	void showInOrder() {
		displayInOrder(root);
	}
	//void showPreOrder() {
	//	displayPreOrder(root);
	//}
	//void showPostOrder() {
	//	displayPostOrder(root);
	//}
	int showNumNodes() {
		return displayNumNodes(root);
	}
	bool search(int v) {
		return search(root, v); //overloaded signature!! 

	}
private:
	void clear(Node*& r);
	void insertAux(Node*&, int);
	void removeAux(Node*&, int);
	void displayInOrder(Node*&)const;
	int displayNumNodes(Node*&) const;
	bool search(Node*&, int)const;
};