/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:58:01 by dteruya           #+#    #+#             */
/*   Updated: 2026/02/02 15:13:15 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data* back = Serializer::deserialize(raw);

	std::cout << "Original address: " << &data << std::endl;
	std::cout << "Serialized: " << raw << std::endl;
	std::cout << "Deserialized address: " << back << std::endl;
	std::cout << "Value: " << back->value << std::endl;
}
