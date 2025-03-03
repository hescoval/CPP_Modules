#include "../headers/PMergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PMergeMe::PMergeMe(){}

PMergeMe::PMergeMe( const PMergeMe & src ){(void)src;}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PMergeMe::~PMergeMe(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PMergeMe &				PMergeMe::operator=( PMergeMe const & rhs )
{
	(void)rhs;
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

unsigned int PMergeMe::check_overflow(string &str)
{
	long double large = strtold(str.c_str(), NULL);

	if(large > std::numeric_limits<unsigned int>::max() || large < std::numeric_limits<unsigned int>::min())
		throw std::runtime_error("Over/Under Flow at Number -> " + str);
	else
		return (unsigned int)large;
		
}


template <typename T>
bool 		PMergeMe::isSorted(T container)
{
	for(size_t i = 0; i < container.size() - 1; i++)
		if(container[i] > container[i + 1])
			return false;
	return true;
}

template <typename T>
void PMergeMe::ProcessInputToContainer(const std::string &input, T &container) 
{
    std::istringstream iss(input);
    std::string number;

	rawinput.clear();

    while (iss >> number) 
	{
		unsigned int to_push = check_overflow(number);

		if(std::find(rawinput.begin(), rawinput.end(), to_push) != rawinput.end())
			throw std::runtime_error("Duplicate number found -> " + number);

		rawinput.push_back(to_push);
    }
	
	if(isSorted(rawinput))
		throw std::runtime_error("Numbers are already sorted");

	for(size_t i = 0; i < rawinput.size() - 1; i++)
	{
		if(i % 2 == 0)
			container.push_back(std::make_pair(rawinput[i], rawinput[i + 1]));
	}

	if(rawinput.size() % 2 != 0)
	{
		odd = true;
		_oddnumber = rawinput[rawinput.size() - 1];
	}
}

template <typename T>
void PMergeMe::print_vec(string print, T container)
{
	std::cout << print;
	for(size_t i = 0; i < container.size(); i++)
	{
		if(i == MAX_NUMBERS)
		{
			cout << "[...]" << endl;
			return;
		}
		std::cout << container[i] << " ";
	}
	std::cout <<endl;
}

void PMergeMe::process_sort(int dqtime, int vectime)
{
	print_vec("Before:  ", rawinput);
	print_vec("After:   ", _sortedDq);
	size_t size = _sortedDq.size();

	std::cout << "Time taken to process a range of " << size << " elements with std::deque :  " << static_cast<double>(dqtime) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	std::cout << "Time taken to process a range of " << size << " elements with std::vector :  " << static_cast<double>(vectime) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}

void PMergeMe::Sort(std::string input)
{
	int time = std::clock();
	ProcessInputToContainer(input, _pairDq);
	SortDq();
	int dqtime = std::clock() - time;

	time = std::clock();
	ProcessInputToContainer(input, _pairVec);
	SortVector();
	process_sort(dqtime, std::clock() - time);
}


/*------------------DQ----------------- */
void PMergeMe::SortDq()
{
	SortPairsDq(0);
	std::sort(_pairDq.begin(), _pairDq.end());
	PushLargests();
	dqFinalSort();

	if(!isSorted(_sortedDq))
		throw std::runtime_error("std::deque failed to sort the numbers.");
}

void PMergeMe::SortPairsDq(size_t index)
{
    // Base case: if index is out of bounds, return
    if (index >= _pairDq.size())
        return;

    // Ensure the first number in the pair is the larger one
    if (_pairDq[index].first < _pairDq[index].second)
	{
        int tmp = _pairDq[index].first;
        _pairDq[index].first = _pairDq[index].second;
        _pairDq[index].second = tmp;
    }

    // Recursive call for the next index
    SortPairsDq(index + 1);
}

void PMergeMe::PushLargests()
{
	for (size_t i = 0; i < _pairDq.size(); i++) 
		_sortedDq.push_back(_pairDq[i].first);

	_sortedDq.push_front(_pairDq[0].second);
	_pairDq.erase(_pairDq.begin());
}

void PMergeMe::dqFinalSort()
{
	for(int jacobNum = 3; _pairDq.size() > 0; jacobNum++)
	{
		size_t grouping = getJacobNum(jacobNum) - getJacobNum(jacobNum - 1);
		if(grouping > _pairDq.size())
			grouping =  _pairDq.size();

		for(int i = static_cast<int>(grouping) - 1; i >= 0; i--)
		{
			int next_push = dqBinarySearch(_pairDq[i].second, _pairDq[i].first);
			if(next_push == 0)
				_sortedDq.push_front(_pairDq[i].second);
			else
				_sortedDq.insert(_sortedDq.begin() + next_push, _pairDq[i].second);
		}

		for(size_t i = 0; i < grouping; i++)
			_pairDq.erase(_pairDq.begin());
	}

	if(odd)
	{
		if(_oddnumber > _sortedDq.back())
			_sortedDq.push_back(_oddnumber);
		else
		{
			int next_push = dqBinarySearch(_oddnumber, _sortedDq.back());
			if(next_push == 0)
				_sortedDq.push_front(_oddnumber);
			else
				_sortedDq.insert(_sortedDq.begin() + next_push, _oddnumber);
		}
	}
}

int	PMergeMe::dqBinarySearch(unsigned int fit, unsigned int largePair) 
{
	int	high = 0;
	int	low = 0;

	while ((size_t)high < _sortedDq.size() && _sortedDq[high] != largePair)
		high++;

	while (low != high) {
		int mid = (low + high) / 2;
		if (fit < _sortedDq[mid])
			high = mid;
		else if (fit > _sortedDq[mid])
			low = mid + 1;
	}
	return (high);
}



/*------------------VECTOR----------------- */
void PMergeMe::SortVector()
{
	SortPairsVec(0);
	std::sort(_pairVec.begin(), _pairVec.end());
	PushLargestsVec();
	vecFinalSort();

	if(!isSorted(_sortedVec))
		throw std::runtime_error("std::vector failed to sort the numbers.");
}

void PMergeMe::SortPairsVec(size_t index)
{
    // Base case: if index is out of bounds, return
    if (index >= _pairVec.size()) {
        return;
    }
    // Ensure the first number in the pair is the larger one
    if (_pairVec[index].first < _pairVec[index].second)
	{
        int tmp = _pairVec[index].first;
        _pairVec[index].first = _pairVec[index].second;
        _pairVec[index].second = tmp;
    }

    // Recursive call for the next index
    SortPairsVec(index + 1);
}

void PMergeMe::PushLargestsVec()
{
	for (size_t i = 0; i < _pairVec.size(); i++) 
		_sortedVec.push_back(_pairVec[i].first);

	_sortedVec.insert(_sortedVec.begin(), _pairVec[0].second);
	_pairVec.erase(_pairVec.begin());
}

void PMergeMe::vecFinalSort()
{
	for(int jacobNum = 3; _pairVec.size() > 0; jacobNum++)
	{
		size_t grouping = getJacobNum(jacobNum) - getJacobNum(jacobNum - 1);
		if(grouping > _pairVec.size())
			grouping =  _pairVec.size();

		for(int i = static_cast<int>(grouping) - 1; i >= 0; i--)
		{
			int next_push = vecBinarySearch(_pairVec[i].second, _pairVec[i].first);
			_sortedVec.insert(_sortedVec.begin() + next_push, _pairVec[i].second);
		}

		for(size_t i = 0; i < grouping; i++)
			_pairVec.erase(_pairVec.begin());
	}

	if(odd)
	{
		if(_oddnumber > _sortedVec.back())
			_sortedVec.push_back(_oddnumber);
		else
		{
			int next_push = vecBinarySearch(_oddnumber, _sortedVec.back());
			_sortedVec.insert(_sortedVec.begin() + next_push, _oddnumber);
		}
	}
}

int	PMergeMe::vecBinarySearch(unsigned int fit, unsigned int largePair) 
{
	int	high = 0;
	int	low = 0;

	while ((size_t)high < _sortedVec.size() && _sortedVec[high] != largePair)
		high++;

	while (low != high) {
		int mid = (low + high) / 2;
		if (fit < _sortedVec[mid])
			high = mid;
		else if (fit > _sortedVec[mid])
			low = mid + 1;
	}
	return (high);
}


int	PMergeMe::getJacobNum(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/	


/* ************************************************************************** */