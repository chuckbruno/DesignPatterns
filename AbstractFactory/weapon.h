#pragma once
#include <string>

class Weapon
{
protected:
	virtual void setWeapon() = 0;
public:
	std::string WeaponType{};
};

class MatialWeapon :public Weapon
{
	void setWeapon() override { WeaponType = "Martial"; }
public:
	MatialWeapon() { setWeapon(); }
};

class CommonWeapon :public Weapon
{
	void setWeapon() override { WeaponType = "Common"; }
public:
	CommonWeapon() { setWeapon(); }
};

class SimpleWeapon :public Weapon
{
	void setWeapon() override { WeaponType = "Simple"; }
public:
	SimpleWeapon() { setWeapon(); }
};