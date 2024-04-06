#include "../headers/general.h"
#include "../headers/Contact.h"
#include <iomanip>

void print_stuff(options option);

void print_contact(Contact data)
{
	print_stuff(HEADER);

	cout << "You are looking at " << data.first_name << "'s information\n" << std::endl;

	cout << "First Name: " << data.first_name << "\nLast Name :" << data.last_name << "\nNick Name: " << data.nick_name << "\nPhone Number: " << data.phone << std::endl;

	cout << "\nPress ENTER when you're ready to go back!" << std::endl;

	std::cin.get();
}

void print_options()
{
	cout << "What Would you like to do?\n\n1. Add\n\n2. Search\n\n3. Exit\n" << std::endl;
}

void print_table_header()
{
	cout << "____________________________________________\n"
			"|          |          |          |          |\n"
			"|     Index|First Name| Last Name| Nick Name|\n"
			"|__________|__________|__________|__________|\n";
}

void print_end()
{
	return;
}

void print_ws()
{
	cout << "|          |          |          |          |\n";
}

void print_bpad()
{
	cout << "|__________|__________|__________|__________|\n";
}

void print_header()
{
std::cout << "   ______                  _         ______ _                     ______             _    \n"
			 "  /  ____)                | |        | ___ \\ |                    | ___ \\           | |   \n"
			 "  \\ `--. _ _ __ ___  _ __ | | ___    | |_/ / |__   ___  _ __   ___| |_/ / ___   ___ | | __\n"
			 "   `--. \\ | '_ ` _ \\| '_ \\| |/ _ \\   |  __/| '_ \\ / _ \\| '_ \\ / _ \\ ___ \\/ _ \\ / _ \\| |/ /\n"
			 "  /\\__/ / | | | | | | |_) | |  __/   | |   | | | | (_) | | | |  __/ |_/ / (_) | (_) |   < \n"
			 "  \\____/|_|_| |_| |_| .__/|_|\\___|   \\_|   |_| |_|\\___/|_| |_|\\___\\____/ \\___/ \\___/|_|\\_\\\n"
			 "                    | |                                                                   \n"
			 "                    |_|                                                                   \n"
			 " ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n"
			 "|______|______|______|______|______|______|______|______|______|______|______|______|______|\n\n\n";
}

void print_field(string data)
{
	int ws_needed = 10 - data.length();
	string print;
	if(ws_needed < 0)
		print = data.substr(0, 9) += '.';
	else
		print = data;
	
	std::cout << std::setw(10);
	std::cout << data << "|";
}

void print_stuff(options option)
{
	system("clear");
	print_header();

	if(option == OPTIONS || option == OPT_ERROR)
		print_options();
	if(option == OPT_ERROR)
		cout << "Please pick one of the options above." << std::endl;
	if(option == TABLE)
		print_table_header();
}