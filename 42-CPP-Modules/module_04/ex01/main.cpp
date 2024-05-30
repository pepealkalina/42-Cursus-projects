/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:47:55 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/09 18:35:13 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 10

int main( void )
{
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak

	delete i;
	}
	{
	const Animal* array[SIZE];

	for (int i = 0; i < SIZE / 2 ; i++)
		array[i] = new Dog();

	for (int i = SIZE / 2; i < SIZE; i ++)
		array[i] = new Cat();
    std::cout << "\n-- Animals type checher --\n" << std::endl;
	for (int i = 0; i < SIZE; i++)
		std::cout << "Animal " << i << " type: "<< array[i]->getType() << std::endl;
    std::cout << "\n-- Animals type checher end --\n" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete array[i];
	}
	const Cat*	cat1;
	const Cat*	cat2;

	cat1 = new Cat();
	cat2 = new Cat(*cat1);

	delete cat1;
	delete cat2;

	return 0;
}
