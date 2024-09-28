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
		throw std::runtime_error("File \"" + file_name + "\" can't be opened or doesn't exist.");
	}
}

void FileManager::read_from(string file_name)
{
	infile.open(file_name.c_str());
	if(infile.fail())
	{
		infile.close();
		throw std::runtime_error("File \"" + file_name + "\" can't be opened or doesn't exist.");
	}
}

FileManager::FileManager(){}

FileManager::~FileManager()
{
	infile.close();
	outfile.close();
}

FileManager::FileManager( FileManager const & src ){(void)src;}

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