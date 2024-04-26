#include "../headers/FileManager.hpp"

void FileManager::find_and_replace(string &text, string find, const string replace)
{
	size_t index = 0;

	while((index = text.find(find, 0)) != string::npos)
	{
		text.erase(index, find.length());
		text.insert(index, replace);
	}
}

void FileManager::open_files()
{
	string target_file = file_name;
	
	if(infile.is_open())
		infile.close();
	if(outfile.is_open())
		outfile.close();

	infile.open(target_file.c_str());
	if(infile.fail())
	{
		infile.close();
		throw std::runtime_error("Origin file can't be opened or doesnt exist.");
	}
	outfile.open((target_file += ".replace").c_str());
	if(outfile.fail())
	{
		infile.close();
		outfile.close();
		throw std::runtime_error("Target file can't be opened or created.");
	}
}

void FileManager:: set_filename(string name)
{
	file_name = name;
}

FileManager::~FileManager()
{
	cout << "Destructing the FileManager and closing files (if open)" << std::endl;
	if(infile.is_open())
		infile.close();
	if(outfile.is_open())
		outfile.close();
}

void FileManager::pseudo_copy(string from, string to)
{
		string buffer;
		while(std::getline(infile, buffer))
		{
			find_and_replace(buffer, from, to);
			outfile << buffer;

			if(!infile.eof())
				outfile << '\n';
		}
}