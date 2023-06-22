/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:58:54 by mwagner           #+#    #+#             */
/*   Updated: 2023/06/20 13:58:55 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
the keyword "this" is a pointer that refers to the current object instance
within a member function of a class.
It allows you to access the members (variables and functions) of the object
on which the member function is being called.
*/

PhoneBook::PhoneBook(void) {
	// Constructor body: initialized int vars of the current PB instance
	std::cout << "PhoneBook Constructor called" << std::endl;
	this->_index = -1;
	this->_i = 0;
}

PhoneBook::~PhoneBook() {
	// Destructor body (empty)
	std::cout << "PhoneBook Destructor called" << std::endl;
}

void	PhoneBook::prompt(void) const {
	std::cout 	<< "********* [ "<< COLOR_RED
				<< "My Awesome Phone Book" << COLOR_DEFAULT << " ] *********\n"
				<< "Chose Command:\n"
				<< "[" << COLOR_GREEN << "ADD" << COLOR_DEFAULT << "] | "
				<< "[" << COLOR_GREEN << "SEARCH" << COLOR_DEFAULT << "] | "
				<< "[" << COLOR_GREEN << "EXIT" << COLOR_DEFAULT << "]"
				<< std::endl;
}

std::string	PhoneBook::_trim(std::string input) const {
	if (input.length() > _WIDTH)
		return (input.substr(0, this->_WIDTH - 1) + ".");
	return (input);
}

void	PhoneBook::_check_index(void) {
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
	if (this->_i < 8)
		this->_i++;
}

void	PhoneBook::_input(std::string contact_field, void (Contact::*set)(std::string)) {
	std::string	input;

	while (true)
	{
		std::cout << "\nEnter " << contact_field << ": ";
		std::getline(std::cin, input);
		if (input.size() != 0)
			break ;
		std::cout << "Input needed\n";
	}
	(this->_contact[this->_index].*set)(input);
}

void	PhoneBook::add(void) {
	this->_check_index();
	PhoneBook::_input("first name", &Contact::setFirstName);
	PhoneBook::_input("last name", &Contact::setLastName);
	PhoneBook::_input("nickname", &Contact::setNickName);
	PhoneBook::_input("phone number", &Contact::setPhoneNumber);
	PhoneBook::_input("darkest secret", &Contact::setDarkestSecret);
}

void	PhoneBook::add_contact(std::string FirstName,
							   std::string LastName,
							   std::string NickName,
							   std::string PhoneNumber,
							   std::string DarkestSecret) {
	this->_check_index();
	this->_contact[this->_index].setContact(FirstName,
											LastName,
											NickName,
											PhoneNumber,
											DarkestSecret);
}

void	PhoneBook::search(void) const {
	std::string input;
	int 		index;

	std::cout.fill('*');
	std::cout << std::setw(this->_WIDTH * 4 + 5) << "\n";
	std::cout.fill(' ');
	std::cout << std::setw(this->_WIDTH) << "Index" << "|";
	std::cout << std::setw(this->_WIDTH) << "First name" << "|";
	std::cout << std::setw(this->_WIDTH) << "Last name" << "|";
	std::cout << std::setw(this->_WIDTH) << "Nickname" << std::endl;
	std::cout.fill('*');
	std::cout << std::setw(this->_WIDTH * 4 + 5) << "\n";
	std::cout.fill(' ');
	for (int i = 0; i < this->_i; i++) {
		std::cout.width(this->_WIDTH);
		std::cout << i + 1 << "|";
		std::cout.width(this->_WIDTH);
		std::cout << this->_trim(this->_contact[i].getFirstName()) << "|";
		std::cout.width(this->_WIDTH);
		std::cout << this->_trim(this->_contact[i].getLastName()) << "|";
		std::cout.width(this->_WIDTH);
		std::cout << this->_trim(this->_contact[i].getNickName()) << std::endl;
	}
	if (this->_i == 0)
		std::cout << "Phonebook is empty\n";
	else {
		std::cout << "\nSelect Index: ";
		std::getline(std::cin, input);
		index = atoi(input.c_str());
		if (index <= this->_i && index > 0)
			PhoneBook::_show_contact(index - 1);
		else
			std::cout << "Invalid Index!\n";
	}
}

void	PhoneBook::_show_contact(int index) const {
	std::cout << std::endl;
	std::cout << this->_contact[index].getFirstName() << std::endl;
	std::cout << this->_contact[index].getLastName() << std::endl;
	std::cout << this->_contact[index].getNickName() << std::endl;
	std::cout << this->_contact[index].getPhoneNumber() << std::endl;
	std::cout << this->_contact[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
