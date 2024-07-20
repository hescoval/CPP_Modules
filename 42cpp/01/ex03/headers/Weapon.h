#include "general.h"

# ifndef WEAPON_H
#	define WEAPON_H

class Weapon
{
	private:
			string type;

	public:
			Weapon(string new_Type);
			const string& getType();
			void	setType(string new_type);
};

# endif