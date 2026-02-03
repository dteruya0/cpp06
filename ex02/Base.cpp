/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:41:15 by dteruya           #+#    #+#             */
/*   Updated: 2026/02/03 14:11:53 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base() {}

Base* generate()
{
	int r = std::rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (!p)
		return; 
	if (dynamic_cast<A*>(p))
		std::cout << "é o A" << std::endl; 
	else if (dynamic_cast<B*>(p))
		std::cout << "é o B" << std::endl; 
	else if (dynamic_cast<C*>(p))
		std::cout << "é o C" << std::endl; 
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "é o A\n";
		return;
	} catch (std::exception&) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "é o B\n";
		return;
	} catch (std::exception&) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "é o C\n";
		return;
	} catch (std::exception&) {}
}
