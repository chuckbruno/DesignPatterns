
#include "singleton.h"
#include <cstdlib>
#include <iostream>


int main()
{
	{
		Tea tea{ 1, 2, 3 };
		Manager::Get()->Add(tea);
	
	}

	auto tealist = Manager::Get()->GetTeaList();
	int count = 1;
	for (const auto& t : tealist)
	{
		std::cout << t.cost << ", " << t.length << ", " << t.quantity << std::endl;
	}


	return EXIT_SUCCESS;
}