
#include <iostream>
#include "adapter.h"

int main()
{

	HamburgerMaker hbmaker;
	CheeseburgerMaker cbmaker(&hbmaker);
	Cheeseburger default_c_burger = cbmaker.MakeBurger();
	std::cout << "Cheeseburger has cheese: ";
	std::cout << std::boolalpha << default_c_burger.hasCheese;
	std::cout << std::endl;

	return 0;
}