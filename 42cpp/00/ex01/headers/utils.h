#include <string>
#include <iostream>

class Contact;
using std::string;

void print_end();
void print_field(string data);
void print_table_header();
void print_stuff(options option);
void trim(string &test);
bool empty_string(string s);
void print_contact(Contact cnt);
void make_uppercase(string &test);
void tidy(string &s);
void print_ws();
void print_bpad();
bool fully_numeric(string s);

string i_to_s(int num);