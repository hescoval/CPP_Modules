#include "general.h"
#include "Weapon.h"

class HumanB
{
	Weapon* Armed_With;
	string name;
	private:

	public:
			HumanB(string new_name);
			void	attack();
			void	setWeapon(Weapon& new_weapon);
};