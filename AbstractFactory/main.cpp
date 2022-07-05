#include <cstdlib>
#include "characterfactory.h"
#include <iostream>

int main()
{
	PlayerCharacter* Bob_The_Rogue = CharacterFactory::create("Rogue");
	if (Bob_The_Rogue)
	{
		std::cout << "classname: " << Bob_The_Rogue->getClass() << std::endl;
		std::cout << "hp: " << Bob_The_Rogue->getHP() << std::endl;
		std::cout << "armor: " << Bob_The_Rogue->getArmor() << std::endl;
		std::cout << "weapon: " << Bob_The_Rogue->getWeapon() << std::endl;
	}

	delete Bob_The_Rogue;
	PlayerCharacter* Chet_The_Warrior = CharacterFactory::create("Warrior");
	if (Chet_The_Warrior)
	{
		std::cout << "classname: " << Chet_The_Warrior->getClass() << std::endl;
		std::cout << "hp: " << Chet_The_Warrior->getHP() << std::endl;
		std::cout << "armor: " << Chet_The_Warrior->getArmor() << std::endl;
		std::cout << "weapon: " << Chet_The_Warrior->getWeapon() << std::endl;
	}
	delete Chet_The_Warrior;

	return EXIT_SUCCESS;
}