/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:37:06 by dteruya           #+#    #+#             */
/*   Updated: 2026/02/03 14:14:54 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// protótipos
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test " << i + 1 << ":\n";

		Base* ptr = generate();

		std::cout << "Pointer: ";
		identify(ptr);

		std::cout << "Ref: ";
		identify(*ptr);

		std::cout << "-----------------\n";

		delete ptr;
	}

	return 0;
}
