
#include <iostream>
#include "adapter.h"

//int main()
//{
//
//	HamburgerMaker hbmaker;
//	CheeseburgerMaker cbmaker(&hbmaker);
//	Cheeseburger default_c_burger = cbmaker.MakeBurger();
//	std::cout << "Cheeseburger has cheese: ";
//	std::cout << std::boolalpha << default_c_burger.hasCheese;
//	std::cout << std::endl;
//
//	return 0;
//}

int main()
{
	Cheeseburger cheeseburger;
	Hamberger& cc = cheeseburger;
	Hamberger* hp = new Cheeseburger;
	Cheeseburger cburger = static_cast<Cheeseburger&>(cc);
	Cheeseburger* chp = static_cast<Cheeseburger*>(hp);
	std::cout << chp->hasCheese << std::endl;
	std::cout << cburger.hasCheese << std::endl;
}
