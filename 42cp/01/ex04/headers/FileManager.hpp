#include "includes.hpp"

class FileManager
{
	private:
		string file_name;
		std::ifstream infile;
		std::ofstream outfile;
		void	find_and_replace(string &text, string find, const string replace);
	
	public:
		void 		pseudo_copy(string from, string to);
		void	set_filename(string name);
		void	open_files();
		~FileManager();
};