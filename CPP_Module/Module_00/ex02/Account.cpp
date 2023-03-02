/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 Account.cpp										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ykuo <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/02/28 04:59:46 by ykuo			   #+#	  #+#			  */
/*	 Updated: 2023/02/28 09:20:29 by ykuo			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

using namespace std;

Account::Account(int initial_deposit) {
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_displayTimestamp();
    cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "created" << endl;
}

Account::~Account( void ) {
    _nbAccounts--;
    this->_displayTimestamp();
    cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "closed" << endl;
}

void Account::_displayTimestamp(){
    time_t result = time(NULL);

    cout << setfill('0') <<"[" << 1900 + localtime(&result)->tm_year
		<< setw(2) << 1 + localtime(&result)->tm_mon
		<<  setw(2) << localtime(&result)->tm_mday
		<<  "_"
		<<  setw(2) << localtime(&result)->tm_hour
		<<  setw(2) << localtime(&result)->tm_min
		<<  setw(2) << localtime(&result)->tm_sec 
		<< "] " << flush;
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << endl;
}

void	Account::makeDeposit(int deposit) {
	int p_amount = _amount;	
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
    _displayTimestamp();
	cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << checkAmount() << ";"
			<< "nb_deposits:" << _nbDeposits
			<< endl;
	
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int p_amount = checkAmount();

	if (withdrawal > p_amount)
	{
    	_displayTimestamp();
		cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "withdrawal:refused" << endl;
		return (false);
	}
	_displayTimestamp();
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << checkAmount() << ";"
			<< "nb_withdrawals:" << _nbWithdrawals
			<< endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
	cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< endl;
}
