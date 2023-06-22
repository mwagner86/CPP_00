/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:00 by mwagner           #+#    #+#             */
/*   Updated: 2023/06/20 13:59:01 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <string>

class Contact {

public:

	Contact(void);

	Contact(std::string FirstName,
			std::string LastName,
			std::string NickName,
			std::string PhoneNumber,
			std::string DarkestSecret);
	~Contact(void);

	// Setter and Getter Functions definitions
	void			setContact(std::string FirstName,
							   std::string LastName,
							   std::string NickName,
							   std::string PhoneNumber,
							   std::string DarkestSecret);
	// it's typical to define public "getter and setter" functions to manage
	// access to private member variables
	void			setFirstName(std::string name);
	std::string		getFirstName(void) const;
	void			setLastName(std::string name);
	std::string		getLastName(void) const;
	void			setNickName(std::string name);
	std::string		getNickName(void) const;
	void			setPhoneNumber(std::string p_no);
	std::string		getPhoneNumber(void) const;
	void			setDarkestSecret(std::string secret);
	std::string		getDarkestSecret(void) const;

private:

	std::string	_firstName;
	std::string _lastName;
	std::string _nickName;
	std::string	_phoneNumber;
	std::string _darkestSecret;

};

#endif