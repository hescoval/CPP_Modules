#include "PhoneBook.h"

class ContactMaker
{
	private:
		PhoneBook user_pb;
		string get_input(string field, string error);

	public:
		void make_contact();
		void search();
		void	list_contacts();
};