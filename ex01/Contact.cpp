/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:58:58 by mwagner           #+#    #+#             */
/*   Updated: 2023/06/20 13:58:59 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	// Constructor body (empty)
	// std::cout << "Empty Contact Constructor called" << std::endl;
}

Contact::~Contact() {
	// Destructor body (empty)
	// std::cout << "Contact Destructor called" << std::endl;
}

void	Contact::setContact(std::string FirstName,
							std::string LastName,
							std::string NickName,
							std::string PhoneNumber,
							std::string DarkestSecret) {
	this->_firstName = FirstName;
	this->_lastName = LastName;
	this->_nickName = NickName;
	this->_phoneNumber = PhoneNumber;
	this->_darkestSecret = DarkestSecret;
}

// Setter and Getter Functions definitions
// it's typical to define public "getter and setter" functions to manage
// access to private member variables

void	Contact::setFirstName(std::string name) {
	this->_firstName = name;
}

std::string Contact::getFirstName() const {
	return (this->_firstName);
}

void	Contact::setLastName(std::string name) {
	this->_lastName = name;
}

std::string Contact::getLastName() const {
	return (this->_lastName);
}

void	Contact::setNickName(std::string name) {
	this->_nickName = name;
}

std::string Contact::getNickName() const {
	return (this->_nickName);
}

void	Contact::setPhoneNumber(std::string p_no) {
	this->_phoneNumber = p_no;
}

std::string Contact::getPhoneNumber() const {
	return (this->_phoneNumber);
}

void	Contact::setDarkestSecret(std::string secret) {
	this->_darkestSecret = secret;
}

std::string Contact::getDarkestSecret() const {
	return (this->_darkestSecret);
}
