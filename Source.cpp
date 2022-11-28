#include <iostream>
#include <iomanip>
#include "Tree.h"
using namespace std;

int main() {

	Tree t;
	t.insert(8);
	t.insert(6);
	t.insert(7);
	t.insert(5);
	t.insert(3);
	t.insert(0);
	t.insert(9);
	t.showInOrder();
	cout << endl << t.search(5) << endl;
	cout << "There are " << t.showNumNodes() << " nodes.\n";
	return 0;
}