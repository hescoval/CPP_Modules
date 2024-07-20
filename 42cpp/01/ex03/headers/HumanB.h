#include "general.h"
#include "Weapon.h"

class HumanB
{
	private:
			Weapon* Armed_With;
			string name;
	public:
			HumanB(string new_name);
			void	attack();
			void	setWeapon(Weapon& new_weapon);
};