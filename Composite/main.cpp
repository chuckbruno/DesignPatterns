
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


#include <iostream>
#include <vector>
using namespace std;

class PageObject {
public:
	virtual void addItem(PageObject a) { }
	virtual void removeItem() { }
	virtual void deleteItem(PageObject a) { }
};

class Page : public PageObject {
public:
	void addItem(PageObject a) {
		cout << "Item added into the page" << endl;
	}
	void removeItem() {
		cout << "Item Removed from page" << endl;
	}
	void deleteItem(PageObject a) {
		cout << "Item Deleted from Page" << endl;
	}
};

class Copy : public PageObject {
	vector<PageObject> copyPages;
public:
	void AddElement(PageObject a) {
		copyPages.push_back(a);
	}
	void addItem(PageObject a) {
		cout << "Item added to the copy" << endl;
	}
	void removeItem() {
		cout << "Item removed from the copy" << endl;
	}
	void deleteItem(PageObject a) {
		cout << "Item deleted from the copy";
	}
};

int main() {
	Page p1;
	Page p2;

	std::cout << sizeof(p1) << std::endl;
	Copy myCopy;
	myCopy.AddElement(p1);
	myCopy.AddElement(p2);
	myCopy.addItem(p1);
	p1.addItem(p2);
	myCopy.removeItem();
	p2.removeItem();
}