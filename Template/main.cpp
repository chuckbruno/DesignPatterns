
#include <iostream>
#include "rand.h"


class IAbstractAI {
public:
	void BaseOperation()
	{
		ScanMap();
		MoveUnit();
		Attack();
	}

protected:
	void ScanMap()
	{
		Scanner();
	}

	void MoveUnit()
	{
		Mover();
	}

	void Attack()
	{
		SpecialAttack();
	}

	virtual void Scanner() = 0;
	virtual void Mover() = 0;
	virtual void SpecialAttack() = 0;

	virtual void Special1() {}
	virtual void Special2() {}
};


class RangedAlly :public IAbstractAI {
public:

protected:
	virtual void Scanner() override
	{
		std::cout << "RangedAlly SCANNER" << std::endl;
		EnemyInSight = (bool)ZOOR();
		if (EnemyInSight)
		{
			std::cout << " - Finds enemy in sight..." << std::endl;
		}
		else
		{
			std::cout << " - no enemy in sight..." << std::endl;
		}
	}

	virtual void Mover() override
	{
		if (EnemyInSight)
		{
			std::cout << " - moves to attack range" << std::endl;
			EnemyInRange = true;
		}
	}

	virtual void SpecialAttack() override
	{
		if (EnemyInSight && EnemyInRange)
		{
			std::cout << " - moves to attack range" << std::endl;
			Special1();
			Special2();
		}
	}

	virtual void Special1() override
	{
		if (amountcount < 1)
		{
			Reload();
		}
		else {
			auto roll = NTKR(1, 100);
			if (roll > 67)
			{
				std::cout << " - crits!" << std::endl;
			}
			else if(roll > 33){
				std::cout << " - hits!" << std::endl;
			}
			else {
				std::cout << " - misses!" << std::endl;
			}
		}
	}

private:
	bool EnemyInSight = false;
	bool EnemyInRange = false;
	int amountcount = 4;
	void Reload() {
		amountcount = 4;
	}
};


int main()
{
	RangedAlly ranged_ally;
	ranged_ally.BaseOperation();

	return 0;
}