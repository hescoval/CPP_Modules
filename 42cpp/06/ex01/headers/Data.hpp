#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{

	public:

		Data();
		Data( Data const & src );
		~Data();

		Data &		operator=( Data const & rhs );

		std::string 	name;
		int				age;
};

#endif /* ************************************************************ DATA_H */