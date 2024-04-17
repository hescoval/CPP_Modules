#include "Contact.h"
#include "general.h"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int c_num;

	public:
		int existing_contacts;
		PhoneBook();
		Contact get_contact(int i);
		void	add_contact(Contact add);
		Contact*	fetch_contacts();
};