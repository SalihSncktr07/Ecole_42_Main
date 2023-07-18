/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:57 by spirnaz           #+#    #+#             */
/*   Updated: 2023/07/18 12:10:57 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contactCount = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(void)
{
	int index = this->contactCount % 8;
	Contact contact;
	std::string input;

	while (1)
	{
		std::cout << "First Name : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (input.empty())
		{
			std::cout << "First Name cannot be empty." << std::endl;
			continue;
		}
		if (input.find_first_not_of(' ') == std::string::npos)
		{
			std::cout << "First Name cannot be equal to a space." << std::endl;
			continue;
		}
		contact.setFirstName(input);
		break;
	}

	while (1)
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (input.empty())
		{
			std::cout << "Last Name cannot be empty." << std::endl;
			continue;
		}
		if (input.find_first_not_of(' ') == std::string::npos)
		{
			std::cout << "Last Name cannot be equal to a space." << std::endl;
			continue;
		}
		contact.setLastName(input);
		break;
	}

	while (1)
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (input.empty())
		{
			std::cout << "Nickname cannot be empty." << std::endl;
			continue;
		}
		if (input.find_first_not_of(' ') == std::string::npos)
		{
			std::cout << "Nickname cannot be equal to a space." << std::endl;
			continue;
		}
		contact.setNickname(input);
		break;
	}

	while (1)
	{
		std::cout << "Phone Number : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (input.empty())
		{
			std::cout << "Phone Number cannot be empty." << std::endl;
			continue;
		}
		if (input.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Phone Number must be fully composed by numbers." << std::endl;
			continue;
		}
		contact.setPhoneNumber(input);
		break;
	}

	while (1)
	{
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (input.empty())
		{
			std::cout << "Darkest Secret cannot be empty." << std::endl;
			continue;
		}
		if (input.find_first_not_of(' ') == std::string::npos)
		{
			std::cout << "Darkest Secret cannot be equal to a space." << std::endl;
			continue;
		}
		contact.setDarkestSecret(input);
		break;
	}

	contacts[index] = contact;
	contactCount++;

	std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::searchContact(void)
{
	int contactCount = getContactCount();

	if (contactCount == 0)
	{
		std::cout << "There are no contacts to display" << std::endl;
		return;
	}

	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getFirstName()) << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}

	std::string searched_index;
	int index;
	while (1)
	{
		std::cout << "Enter the index of the contact you want to search: ";
		std::getline(std::cin, searched_index);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (searched_index.empty())
		{
			std::cout << "Index cannot be empty." << std::endl;
			continue;
		}
		if (searched_index.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Index must be number." << std::endl;
			continue;
		}
		index = atoi(searched_index.c_str());
		if (index < 0 || index >= contactCount)
		{
			std::cout << "Index must be one of the index values in the table." << std::endl;
			continue;
		}
		break;
	}
	printContact(index);
}

void PhoneBook::printContact(int index)
{
	std::cout << "First name : " + PhoneBook::contacts[index].getFirstName() << std::endl;
	std::cout << "Last name : " + PhoneBook::contacts[index].getLastName() << std::endl;
	std::cout << "Nickname : " + PhoneBook::contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number : " + PhoneBook::contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " + PhoneBook::contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount(void)
{
	if (contactCount < 8)
		return contactCount;
		
	return 8;
}

std::string PhoneBook::getFormattedField(std::string field)
{
	if (field.length() <= 10)
		return field;

	return field.substr(0, 9) + ".";
}
