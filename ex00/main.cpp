/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:53:38 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/30 16:57:58 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error! Invalid argument count!" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
