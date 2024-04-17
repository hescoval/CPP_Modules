#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <fstream>
#include <filesystem>

using std::string;
using std::cout;

void	find_and_replace(string &text, string find, const string replace)
{
	size_t index = 0;

	while((index = text.find(find, 0)) != string::npos)
	{
		text.erase(index, find.length());
		text.insert(index, replace);
	}
}

int main(int ac, char **av)
{

	if(ac != 4)
	{
		cout << "Correct Usage:\n\n ./(program name) (file name) (to_replace) (replace_with)" << std::endl;
		return 1;
	}

	string file_name(av[1]);
	std::ifstream infile(file_name.c_str());

	if(infile.fail())
	{
		cout << "Origin file can't be opened or doesnt exist." << std::endl;
		infile.close();
		return 1;
	}

	std::ofstream outfile((file_name += ".replace").c_str());
	
	if(outfile.fail())
	{
		cout << "Target file can't be opened or created." << std::endl;
		infile.close();
		outfile.close();
		return 1;
	}

	string line;
	while(std::getline(infile, line))
	{
		find_and_replace(line, string(av[2]), string(av[3]));
		outfile << line;

		if(!infile.eof())
			outfile << '\n';
	}

	outfile.close();
	infile.close();

	return 0;
}