#include <string>
#include <iostream>

class Contact;
using std::string;

void print_field(string data);
void print_table_header();
void print_stuff(int option);
void trim(string &test);
bool check_empty(string &real);
void print_contact(Contact cnt);
void make_uppercase(std::string &test);

string i_to_s(int num);