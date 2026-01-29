/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:43:26 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/29 15:04:28 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	ScalarConverter::convert(std::string s)
{
	int type;
	type = detectType(s);
}

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

static Type detectType(std::string s)
{
	if (isPseudo(s))
		return PSEUDO;
	if (isChar(s))
		return CHAR;
	if (isInt(s))
		return INT;
	if (isFloat(s))
		return FLOAT;
	if (isDouble(s))
		return DOUBLE;
	return INVALID;
}

static bool isChar(std::string s)
{
	if (s.empty())
		return false;
	if (s.length() != 1 || isdigit(s[0]))
		return false;
	if (!(isascii(s[0]) && isprint(s[0])) || s[0] == 32)
		return false;
	return true;
}

static bool isInt(std::string s)
{
	int i = 0;

	if (s.empty())
		return false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while(s[i])
	{
		if (isdigit(s[i]))
			i++;
		else
			return false;
	}
	if (s.length() > 11)
	return true;
}