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

void FileManager::close_files()
{
	infile.close();
	outfile.close();
}

void FileManager::write_to(string file_name)
{
	outfile.open(file_name.c_str());	
	if(outfile.fail())
	{
		outfile.close();
		throw std::runtime_error("Target file can't be opened or created.");
	}
}

void FileManager::read_from(string file_name)
{
	string target_file = file_name;

	infile.open(target_file.c_str());
	if(infile.fail())
	{
		infile.close();
		throw std::runtime_error("Origin file can't be opened or doesnt exist.");
	}
}

FileManager::~FileManager()
{
	cout << "Destructing the FileManager and closing files" << std::endl;

	infile.close();
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