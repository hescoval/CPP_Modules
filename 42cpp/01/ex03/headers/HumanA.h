#include "general.h"
#include "Weapon.h"

class HumanA
{
	private:
			Weapon& Armed_With;
			string name;
	public:
			HumanA(string new_name, Weapon& Wielding);
			void	attack();
			void	setWeapon(Weapon new_weapon);
};