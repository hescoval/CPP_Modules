#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

using std::cout;


int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
	// Want = [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	cout << "index:" << _nbAccounts;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	
	cout << ";amount:" << initial_deposit << ";created" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus() const
{
	/*
		index:0;amount:42;deposits:0;withdrawals:0
	*/

	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	/*
		[19920104_091532]
	*/

	std::time_t t = std::time(nullptr);
	std::tm* tm = std::localtime(&t);
	std::cout << std::put_time(tm, "[%Y%m%d_%H%M%S] ");
}

bool	Account::makeWithdrawal( int withdrawal )
{
	/*
		[19920104_091532] index:0;p_amount:47;withdrawal:refused
		[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	*/

	int new_amount;

	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";

	if(withdrawal > _amount)
	{
		cout << "refused" << std::endl;
		return false;
	}

	_totalNbWithdrawals++;
	new_amount = _amount - withdrawal;
	cout << withdrawal << ";amount:" << new_amount << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_amount = new_amount;

	return true;
}

void	Account::makeDeposit( int deposit )
{
	/*
		[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	*/

	int new_amount;

	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:";


	_totalNbDeposits++;
	_totalAmount += deposit;
	new_amount = _amount + deposit;
	cout << deposit << ";amount:" << new_amount << ";nb_deposits:" << ++_nbDeposits<< std::endl;
	_amount = new_amount;
}

void	Account::displayAccountsInfos( void )
{
	/*
		accounts:8;total:21524;deposits:8;withdrawals:0
	*/

	_displayTimestamp();
	
	cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
} 

Account::~Account( void )
{
	/*
		[19920104_091532] index:0;amount:47;closed
		[19920104_091532] index:1;amount:785;closed
	*/
	
	_displayTimestamp();

	cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}