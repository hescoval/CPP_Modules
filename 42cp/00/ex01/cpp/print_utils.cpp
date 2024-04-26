#include "../headers/general.h"
#include "../headers/Contact.h"
#include <iomanip>

void print_stuff(options option);

void print_contact(Contact data)
{
	print_stuff(HEADER);

	cout << "You are looking at " << data.get_first() << "'s information\n" << std::endl;

	cout << "First Name: " << data.get_first();
	cout << "\nLast Name: " <<  data.get_last();
	cout << "\nNick Name: " << data.get_nick();
	cout << "\nPhone Number: " << data.get_phone();
	cout << "\nDarkest Secret: " << data.get_darkest() << std::endl;

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
	system("clear");
    std::cout << " _____                                         ___              _       _ \n"
                 "/  ___|                                       / _ \\            (_)     | |\n"
                 "\\ `--.  ___  ___      _   _  ___  _   _      / /_\\ \\ __ _  __ _ _ _ __ | |\n"
                 " `--. \\/ _ \\/ _ \\    | | | |/ _ \\| | | |     |  _  |/ _` |/ _` | | '_ \\| |\n"
                 "/\\__/ /  __/  __/    | |_| | (_) | |_| |     | | | | (_| | (_| | | | | |_|\n"
                 "\\____/ \\___|\\___|     \\__, |\\___/ \\__,_|     \\_| |_/\\__, |\\__,_|_|_| |_(_)\n"
                 "                       __/ |                         __/ |                \n"
                 "                      |___/                         |___/                 " << std::endl;
    sleep(2);
	system("clear");
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