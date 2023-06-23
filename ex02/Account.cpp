/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:14:21 by mwagner           #+#    #+#             */
/*   Updated: 2023/06/23 14:14:24 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
}

Account::Account() {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
}

Account::~Account() {
	Account::_displayTimestamp();
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	if (this->_accountIndex < 7)
		std::cout << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal <= this->_amount)
	{
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused"  << std::endl;
	}
	return (false);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Timestamp format : [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp( void ) {
	std::time_t current_time = std::time(0);
	std::tm* time_info = std::localtime(&current_time);

	std::cout << "[" << time_info->tm_year + 1900
			  << std::setfill('0') << std::setw(2) << time_info->tm_mon + 1
			  << std::setfill('0') << std::setw(2) << time_info->tm_mday
			  << '_' << std::setw(2) << time_info->tm_hour
			  << std::setw(2) << time_info->tm_min
			  << std::setw(2) << time_info->tm_sec << "] ";
}
