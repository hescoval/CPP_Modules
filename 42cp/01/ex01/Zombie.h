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
		Zombie();
		Zombie(string new_name);
		~Zombie();
		void announce();
		void set_name(string new_name);
		string get_name();
};

void randomChump( string name );
Zombie* newZombie( string name );
Zombie* zombieHorde( int N, std::string name );