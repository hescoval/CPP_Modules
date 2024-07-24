#include "headers/Character.hpp"
#include "headers/Ice.hpp"
#include "headers/MateriaSource.hpp"
#include "headers/Cure.hpp"
#include <cstdlib>
#include <limits>

void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

void Deep_Copy_Full_Inventory_Check()
{
	Character *me = new Character();
	Character *copy;


	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *ice3 = new Ice();
	AMateria *ice4 = new Ice();
	AMateria *ice5 = new Ice();

	me->equip(ice);
	me->equip(cure);
	me->equip(ice3);
	me->equip(ice4);

	// Test full inventory equips and delete unused ice
	me->equip(ice5);
	delete ice5;

	enter_to_continue();

	copy = new Character(*me);
	Character equal_copy = *me;

	cout << endl;
	//Deep copy check
	for(int i = 0; i < MAX_SLOTS; i++)
	{
		AMateria* orig = me->inventory_peek(i);
		AMateria* copy_m = copy->inventory_peek(i);
		AMateria* equal_copy_m = equal_copy.inventory_peek(i);

		if(orig)
			cout << "Orig's address == \t" << orig << " Orig type == " << orig->getType() << endl;
		if(copy_m)
			cout << "Copy's address == \t" << copy_m << " Copy type == " << copy_m->getType() << endl;
		if(equal_copy_m)
			cout << "Equal Copy's address == " << equal_copy_m << " Equal Copy type == " << equal_copy_m->getType() << endl;
		cout << endl;
	}

	delete copy;
	delete me;
}

void MateriaSourceTester()
{
	MateriaSource* src = new MateriaSource();

	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter *me = new Character();

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("random"));
	me->use(0, *me);


	enter_to_continue();
	delete src;
	delete me;
}

void official_main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void unequip_test()
{
	AMateria *ground[250];
	Character *me = new Character();

	for(int i = 0; i < 50; i++)
	{
		me->equip(new Ice());
		ground[i] = me->inventory_peek(i % MAX_SLOTS);
		me->unequip(i % MAX_SLOTS);
	}

	for(int i = 0; i < 50; i++)
	{
		delete ground[i];
	}
	delete me;
}

int main()
{
	Deep_Copy_Full_Inventory_Check();

	enter_to_continue();

	MateriaSourceTester();

	enter_to_continue();

	official_main();

	enter_to_continue();

	unequip_test();
}