/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:03 by mwagner           #+#    #+#             */
/*   Updated: 2023/06/20 13:59:04 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

static void	fill_phonebook(PhoneBook *book);

int	main()
{
	PhoneBook	awesome_phonebook;
	std::string	user_input;

	fill_phonebook(&awesome_phonebook);
	while (true)
	{
		PhoneBook::prompt();
		std::getline(std::cin, user_input);

		if (user_input == "ADD")
			awesome_phonebook.add();
		else if (user_input == "SEARCH")
			awesome_phonebook.search();
		else if (user_input == "EXIT")
			break ;
		else
			std::cout << "Wrong input\n";
	}
	return (0);
}

static void	fill_phonebook(PhoneBook *book)
{
	book->add_contact("John", "Smith", "Hannibal", "0001-CALL-A-TEAM", "Leader of the A-Team");
	book->add_contact("Arthur Templeton", "Peck", "Faceman", "0002-CALL-A-TEAM", "Con man and scrounger");
	book->add_contact("H.M.", "Murdock", "Howling Mad", "0003-CALL-A-TEAM", "Best chopper pilot");
	book->add_contact("Bosco Albert", "Baracus", "B.A.", "0004-CALL-A-TEAM", "Nickname stands for Bad Attitude");
	book->add_contact("Maximilian", "Wagner", "loserkid", "0000-look-at-intra", "Likes cookies");
}
