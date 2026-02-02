/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:43:39 by dteruya           #+#    #+#             */
/*   Updated: 2026/02/02 15:10:26 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}
Serializer::Serializer(const Serializer& other)
{
	(void)other;
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}
Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
	if (DEBUG)
		std::cout << "Default destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	if (DEBUG)
		std::cout << "serialize() called" << std::endl;
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	if (DEBUG)
		std::cout << "deserialize() called" << std::endl;
	Data* ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}
