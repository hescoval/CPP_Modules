#include "Contact.h"
#include "general.h"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int c_num;
		int existing_contacts;

	public:
		int	get_n_contacts();
		PhoneBook();
		Contact get_contact(int i);
		void	add_contact(Contact add);
		Contact*	fetch_contacts();
};