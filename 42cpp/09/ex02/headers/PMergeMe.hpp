#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "general.hpp"
# include <vector>
# include <sstream>
# include <list>
# include <algorithm>
# include <ctime>


typedef unsigned int ui;
typedef std::pair<ui, ui> ui_pair; // pair<unsigned int, unsigned int>
typedef std::vector<ui_pair> pair_vec; // vector<unsigned int>
typedef std::vector<ui> u_vec; // vector<pair<unsigned int, unsigned int>>
typedef std::deque<ui_pair> pair_dq; // deque<unsigned int>
typedef std::deque<ui> u_dq; // deque<pair<unsigned int, unsigned int>>

#define MAX_NUMBERS 8

class PMergeMe
{
	bool			odd;
	pair_vec	 	_pairVec;
	u_vec			_sortedVec;
	pair_dq			_pairDq;
	u_dq			_sortedDq;
	ui				_oddnumber;

	u_vec			rawinput;

	public:
	
		PMergeMe();
		PMergeMe( PMergeMe const & src );
		virtual 			~PMergeMe();

		void				Sort(std::string input);
		PMergeMe &			operator=( PMergeMe const & rhs );

	private:

		unsigned int		check_overflow(std::string &str);
		int					getJacobNum	(int n);
		
		void				process_sort(int dqtime, int vectime);

		template <typename T>
		void 				print_vec(string print, T container);

		template <typename T>
		bool 				isSorted(T container);

		//Vector
		void 				SortVector();
		void 				SortPairsVec(size_t index);
		void 				PushLargestsVec();
		void 				vecFinalSort();
		int					vecBinarySearch(unsigned int fit, unsigned int largePair);

		//Dq
		void 				SortDq();
		void 				SortPairsDq(size_t index);
		void 				PushLargests();
		void 				dqFinalSort();
		int					dqBinarySearch(unsigned int fit, unsigned int largePair) ;
		
		template <typename T>
		void 	ProcessInputToContainer(const std::string &input, T &container);
};

#endif /* ******************************************************** PMERGEME_H */