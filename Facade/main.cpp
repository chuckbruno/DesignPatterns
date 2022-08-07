#include "facade.h"
#include <iostream>

int main()
{
	ArmorBuilderFacade abf;

	std::cout << abf.GetHeavyArmor() << std::endl;
	std::cout << abf.GetMediumArmor() << std::endl;
	std::cout << abf.GetLightArmor() << std::endl;

	return 0;
}