#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;

class Zombie
{
	private:
		string name;
	public:
		Zombie(string new_name);
		~Zombie();
		void announce();
		string get_name();
};

void randomChump( string name );
Zombie* newZombie( string name );