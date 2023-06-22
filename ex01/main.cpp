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

int	main()
{
	PhoneBook	awesome_phonebook;
	std::string	user_input;

	while (true)
	{
		awesome_phonebook.prompt();
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
