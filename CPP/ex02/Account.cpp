/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:11:13 by spirnaz           #+#    #+#             */
/*   Updated: 2023/07/18 12:11:13 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

// Tüm Accountlar tarafından kullanılacak olan statik değişkenleri başlatıyoruz.

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Private olan statik değişkenelere erişmek için getter fonksiyonları.

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

// Account'un bilgilerini görmek için kullanılan fonksiyon.
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	// account'un indexini set et.
	_accountIndex = getNbAccounts();

	// account'un amount'unu set et;
	_amount = initial_deposit;

	// her account için total amount'u arttır.
	_totalAmount += _amount;

	// Direk index'i artırırsak bir işe yaramaz.
	// Her account kendi index'ine sahip olduğu için, hepsi 1 olur.
	// Static datayı arttırdığımız için hepsi bu dataya erişebilecek.
	_nbAccounts++;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	// account'un depozito sayısını arttırıyoruz.
	_nbDeposits++;

	// toplam depozito sayısını 1 arttırıyoruz.
	_totalNbDeposits++;

	// account'un amount'u depozito kadar artmalı.
	_amount += deposit;

	// toplam amount'u depozito kadar arttırıyoruz.
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount - deposit << ";" // işlemden önce ki amount
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	// para çekmek mümkün değilse
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout
			<< "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";" // işlemden önceki amount
			<< "withdrawal:"
			<< "refused" << std::endl;

		return false;
	}

	// account'un para çekme sayısını arttırıyoruz.
	_nbWithdrawals++;

	// tüm account'ların toplam para çekme sayısını 1 arttırıyoruz.
	_totalNbWithdrawals++;

	// account'un amount'u çekilen para kadar azalmalı.
	_amount -= withdrawal;

	// toplam amount'u çekilen para kadar azaltıyoruz.
	_totalAmount -= withdrawal;

	// başarılı olursa
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount + withdrawal << ";" // işlemden önceki amount
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";" // işlemden sonra ki yeni amount
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
}

// gereksiz, kullanılmasına gerek yok.
int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(NULL);
	tm *local = localtime(&now);

	std::cout
		<< "["
		<< local->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << local->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << local->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << local->tm_hour
		<< std::setw(2) << std::setfill('0') << local->tm_min
		<< std::setw(2) << std::setfill('0') << local->tm_sec
		<< "] ";
}
