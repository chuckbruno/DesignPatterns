#pragma once
#include "../AbstractFactory/armor.h"

class ArmorBuilderFacade
{

public:
	ArmorBuilderFacade()
	{

		heavyarmor = new HeavyArmor();
		mediumarmor = new MediumArmor();
		lightarmor = new LightArmor();
	}

	~ArmorBuilderFacade()
	{
		delete heavyarmor;
		delete mediumarmor;
		delete lightarmor;
	}

	std::string GetHeavyArmor() { return heavyarmor->ArmorType; }
	std::string GetMediumArmor() { return mediumarmor->ArmorType; }
	std::string GetLightArmor() { return lightarmor->ArmorType; }

private:
	HeavyArmor* heavyarmor;
	MediumArmor* mediumarmor;
	LightArmor* lightarmor;

};