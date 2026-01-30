/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:43:17 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/30 17:05:16 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>  // std::string
#include <cctype>  // isdigit
#include <cstdlib> // std::strtol
#include <cerrno>  // errno, ERANGE
#include <climits> // INT_MAX, INT_MIN
#include <limits>
#include <limits.h>
#include <iomanip>
#define DEBUG false

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static Type detectType(std::string s);

		static bool isChar(std::string s);
		static bool isInt(std::string s);
		static bool isFloat(std::string s);
		static bool isDouble(std::string s);
		static bool isPseudo(std::string s);
		
		static void convertFromChar(std::string s);
		static void convertFromInt(std::string s);
		static void convertFromFloat(std::string s);
		static void convertFromDouble(std::string s);
		static void printImpossible(void);
		static void printPseudo(std::string s);
		static void printDebug(std::string debug_message);

	public:
		static void convert(std::string input);
};


#endif