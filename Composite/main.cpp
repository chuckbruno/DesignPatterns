
//#include "composite.h"
//#include <iostream>
//
//int main()
//{
//	Folder f1;
//	MediaFile mf1;
//	MediaFile mf2;
//
//	mf1.SetParent(&f1);
//	f1.Add(&mf1);
//	f1.Add(&mf2);
//
//	std::cout << sizeof(mf1) << std::endl;
//
//	for (auto item : f1.GetChildren())
//	{
//		std::cout << item << std::endl;
//	}
//
//
//	return 0;
//}


// #include <iostream>
// #include <vector>
// using namespace std;

// class PageObject {
// public:
// 	virtual void addItem(PageObject a) { }
// 	virtual void removeItem() { }
// 	virtual void deleteItem(PageObject a) { }
// };

// class Page : public PageObject {
// public:
// 	void addItem(PageObject a) {
// 		cout << "Item added into the page" << endl;
// 	}
// 	void removeItem() {
// 		cout << "Item Removed from page" << endl;
// 	}
// 	void deleteItem(PageObject a) {
// 		cout << "Item Deleted from Page" << endl;
// 	}
// };

// class Copy : public PageObject {
// 	vector<PageObject> copyPages;
// public:
// 	void AddElement(PageObject a) {
// 		copyPages.push_back(a);
// 	}
// 	void addItem(PageObject a) {
// 		cout << "Item added to the copy" << endl;
// 	}
// 	void removeItem() {
// 		cout << "Item removed from the copy" << endl;
// 	}
// 	void deleteItem(PageObject a) {
// 		cout << "Item deleted from the copy";
// 	}
// };

// int main() {
// 	Page p1;
// 	Page p2;

// 	std::cout << sizeof(p1) << std::endl;
// 	Copy myCopy;
// 	myCopy.AddElement(p1);
// 	myCopy.AddElement(p2);
// 	myCopy.addItem(p1);
// 	p1.addItem(p2);
// 	myCopy.removeItem();
// 	p2.removeItem();

#include "composite.h"

int main()
{
	Component* simple = new Leaf;
	std::cout << "Client: I've got a simple component:\n";
	ClientCode(simple);
	std::cout << "\n\n";

	Component* tree = new Composite;
	Component* branch1 = new Composite;

	Component* leaf_1 = new Leaf;
	Component* leaf_2 = new Leaf;
	Component* leaf_3 = new Leaf;
	branch1->Add(leaf_1);
	branch1->Add(leaf_2);

	Component* branch2 = new Composite;
	branch2->Add(leaf_3);
	tree->Add(branch1);
	tree->Add(branch2);

	std::cout << "Client: Now I've got a composite tree:\n";
	ClientCode(tree);
	std::cout << "\n\n";

	std::cout << "Client: I don't need to check the components classes even when managing the tree.\n";
	ClientCode2(tree, simple);
	std::cout << "\n";

	delete simple;
	delete tree;
	delete branch1;
	delete branch2;
	delete leaf_1;
	delete leaf_2;
	delete leaf_3;

	return 0;

>>>>>>> 7048a4c (feat: update codes)
}