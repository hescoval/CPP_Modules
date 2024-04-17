#include "general.h"
#include "Weapon.h"

class HumanA
{
	Weapon& Armed_With;
	string name;
	private:

	public:
			HumanA(string new_name, Weapon& Wielding);
			void	attack();
			void	setWeapon(Weapon new_weapon);
};