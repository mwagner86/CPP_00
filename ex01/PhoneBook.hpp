/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:58:56 by mwagner           #+#    #+#             */
/*   Updated: 2023/06/20 13:58:57 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "Contact.hpp"
# define COLOR_DEFAULT "\033[0m"
# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	prompt(void) const;
	void	search(void) const;
	void	add(void);
	void	add_contact(std::string FirstName,
						std::string LastName,
						std::string NickName,
						std::string PhoneNumber,
						std::string DarkestSecret);

private:

	Contact				_contact[8];
	void				_show_contact(int index) const;
	int 				_index;
	void				_check_index(void);
	int					_i;
	void				_input(std::string msg, void (Contact::*f)(std::string));
	std::string 		_trim(std::string input) const;
	static int const 	_WIDTH = 10;

};

#endif