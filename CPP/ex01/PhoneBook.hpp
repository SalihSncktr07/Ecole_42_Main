/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:11:04 by spirnaz           #+#    #+#             */
/*   Updated: 2023/07/18 12:11:04 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void);
	void printContact(int index);
	int getContactCount(void);
	std::string getFormattedField(std::string field);
};
#endif
