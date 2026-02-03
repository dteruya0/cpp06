/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:43:26 by dteruya           #+#    #+#             */
/*   Updated: 2026/02/02 12:34:29 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string s)
{
	Type type = detectType(s);

	switch (type)
	{
		case CHAR:
			convertFromChar(s);
			break;
		case INT:
			convertFromInt(s);
			break;
		case FLOAT:
			convertFromFloat(s);
			break;
		case DOUBLE:
			convertFromDouble(s);
			break;
		case PSEUDO:
			printPseudo(s);
			break;
		default:
			printImpossible();
	}
}


Type ScalarConverter::detectType(std::string s)
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

bool ScalarConverter::isChar(std::string s)
{
	if (s.empty())
		return false;
	if (s.length() != 1 || isdigit(s[0]))
		return false;
	if (!(isascii(s[0]) && isprint(s[0])) || s[0] == 32)
		return false;
	return true;
}

bool ScalarConverter::isInt(std::string s)
{
	int i = 0;
	long int nbr = 0;
	if (s.empty())
		return false;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s.length() == 1)
			return false;
		i++;
	}
	while(s[i])
	{
		if (isdigit(s[i]))
			i++;
		else
			return false;
	}
	errno = 0;
	nbr = std::strtol(s.c_str(), NULL, 10);
	if (errno == ERANGE)
	{
		if (DEBUG)
			printDebug("overflow detected");
		return false;
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		if (DEBUG)
			printDebug("out of 'int' ranges");
		return false;
	}
	return true;
}

bool ScalarConverter::isDouble(std::string s)
{
	bool hasDigit = false;
	bool hasDot = false;
	int i = 0;
	
	if (s.empty())
		return false;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s.length() == 1)
			return false; 
		i++;
	}
	while(s[i])
	{
		if (isdigit(s[i]))
			hasDigit = true;
		else if (s[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else
			return false;
		i++;
	}
	if (!hasDigit || !hasDot)
		return false;
	errno = 0;
	std::strtod(s.c_str(), NULL);
	if (errno == ERANGE)
		return false;
	return true;
}

bool ScalarConverter::isFloat(std::string s)
{
	if (s.empty())
		return false;

	if (s[s.length() - 1] != 'f')
		return false;

	std::string noF = s.substr(0, s.length() - 1);

	if (noF.empty())
		return false;

	if (!isDouble(noF))
		return false;

	errno = 0;
	std::strtof(s.c_str(), NULL);
	if (errno == ERANGE)
		return false;

	return true;
}

bool ScalarConverter::isPseudo(std::string s)
{
	return (
		s == "nan"  ||
		s == "+inf" ||
		s == "-inf" ||
		s == "nanf" ||
		s == "+inff"||
		s == "-inff"
	);
}

void ScalarConverter::printDebug(std::string s)
{
	std::cout << s << std::endl;
}

void ScalarConverter::printPseudo(std::string s)
{
	if (DEBUG)
		printDebug("handlePseudo() called");

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (s == "+inff" || s == "inff" || s == "-inff")
	{
		std::cout << "float: " << s << std::endl;
		std::cout << "double: " << s.substr(0, s.size() - 1) << std::endl;
	}
	else if (s == "+inf" || s == "inf" || s == "-inf")
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << s << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::convertFromChar(std::string s)
{
	if (DEBUG)
		printDebug("convertFromChar called");

	std::cout << "char: '" << s << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(s[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(s[0]) << ".0" << std::endl;
}


void ScalarConverter::convertFromInt(std::string s)
{
	if (DEBUG)
		printDebug("convertFromInt called");

	int value = std::atoi(s.c_str());

	if (value < 0 || value > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(value))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";

	std::cout << "int: " << value << "\n";
	std::cout << "float: " << static_cast<float>(value) << ".0f\n";
	std::cout << "double: " << static_cast<double>(value) << ".0\n";
}

void ScalarConverter::convertFromFloat(std::string to_convert)
{
	float value = atof(to_convert.c_str());

	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<unsigned char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if(value < std::numeric_limits<int>::max() && value > std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "float: " << value << ".0f\n";
	else
		std::cout << "float: " << value << "f\n";
	if (value == static_cast<int>(value))
		std::cout << "double: " << static_cast<double>(value) << ".0\n";
	else
		std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::convertFromDouble(std::string to_convert)
{
	double value = std::atof(to_convert.c_str());

	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible\n";
	else if (isprint(static_cast<unsigned char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(value) << "\n";
	else
		std::cout << "int: impossible\n";
	if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
	{
		if (value == static_cast<int>(value))
			std::cout << "float: " << static_cast<float>(value) << ".0f\n";
		else
			std::cout << "float: " << static_cast<float>(value) << "f\n";
	}
	else
		std::cout << "float: impossible\n";
	if (value == static_cast<int>(value))
		std::cout << "double: " << value << ".0\n";
	else
		std::cout << "double: " << value << "\n";
}


void ScalarConverter::printImpossible(void)
{
	if (DEBUG)
		printDebug("handle_impossible() called");

	printDebug("char: impossible");
	printDebug("int: impossible");
	printDebug("float: impossible");
	printDebug("double: impossible");
}

ScalarConverter::ScalarConverter()
{
	if (DEBUG)
		printDebug("Default constructor called");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	if (DEBUG)
		printDebug("Copy constructor called");
	(void)other;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	if (DEBUG)
		printDebug("Default destructor called");
}