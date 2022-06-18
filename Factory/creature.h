#pragma once

class Creature
{
public:
	virtual ~Creature() {};
	virtual Creature* Clone() { return nullptr; }
	int getHP() { return HitPoint; }
	int getSpeed() { return Speed; }
	int getAttack() { return Attack; }

protected:
	int HitPoint = 0;
	int Speed = 0;
	int Attack = 0;
};


#include <iostream>

class Dog : public Creature
{
public:
	Dog() { HitPoint = 3; Speed = 3; Attack = 3; }
	void Bark() { std::cout << "Bark" << std::endl; }

};


class Cat : public Creature
{
public:
	Cat() { HitPoint = 2; Speed = 2; Attack = 2; }
	void Meow() { std::cout << "Meow" << std::endl; }
};


class Mouse : public Creature
{
public:
	Mouse() { HitPoint = 1; Speed = 1; Attack = 1; }
	void Squeak() { std::cout << "Squeak" << std::endl; }
};


class Lizard :public Creature
{
public:
	Lizard(int hp, int speed, int attack)
	{
		HitPoint = hp;
		Speed = speed;
		Attack = attack;
	}

	Creature* Clone() {
		return new Lizard(HitPoint, Speed, Attack);
	}

	void Hiss() {
		std::cout << "Hiss" << std::endl;
	}
};