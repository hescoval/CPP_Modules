#include "headers/FileManager.hpp"

int main(int ac, char **av)
{
	if(ac != 4)
	{
		cout << "Correct Usage:\n\n ./(program name) (file name) (to_replace) (replace_with)" << std::endl;
		return 1;
	}

	FileManager FileSystem;
	try
	{
		FileSystem.read_from(string(av[1]));
		FileSystem.write_to(string(av[1]) + ".replace");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	FileSystem.pseudo_copy(string(av[2]), string(av[3]));
	return 0;
}