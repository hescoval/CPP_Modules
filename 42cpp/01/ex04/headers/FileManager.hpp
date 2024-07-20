#include "includes.hpp"

class FileManager
{
	private:
		std::ifstream infile;
		std::ofstream outfile;
		void	find_and_replace(string &text, string find, const string replace);
	
	public:
		void	close_files();
		void 	pseudo_copy(string from, string to);
		void	read_from(string file_name);
		void	write_to(string file_name);
		~FileManager();
};