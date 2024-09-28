#include "general.hpp"

class FileManager
{
	public:
		FileManager();
		~FileManager();
		FileManager( FileManager const & src );
		void	close_files();
		void 	pseudo_copy(string from, string to);
		void	read_from(string file_name);
		void	write_to(string file_name);
		std::ifstream infile;
		std::ofstream outfile;

	private:
		void	find_and_replace(string &text, string find, const string replace);
	
};