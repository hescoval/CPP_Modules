# include <iostream>
# include <cctype>
# include <string>
# include <cstdlib>


/*
	Using keyword is only forbidden if you use it for entire namespaces
	eg: using namespace std;

	Using keyword is allowed if you use it for specific elements of a namespace
	eg: using std::string;
	eg: using std::cout;

	Rule is likely in place to prevent namespace pollution and to make sure you know
	where the things you are using come from.
*/

using std::string;
using std::cout;