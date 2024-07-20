#include <iostream>
#include <string>

using std::string;

class Contact
{
	private:
		string first_name;
		string last_name;
		string nick_name;
		string phone;
		string darkest_secret;
	public:
		string get_first();
		string get_last();
		string get_nick();
		string get_phone();
		string get_darkest();
		void	set_first(string input);
		void	set_last(string input);
		void	set_nick(string input);
		void	set_phone(string input);
		void	set_darkest(string input);
};