#include "PhoneBook.h"

class ContactMaker
{
	private:
		PhoneBook user_pb;
		string  get_input(string field);

	public:
		void make_contact();
		void search();
};