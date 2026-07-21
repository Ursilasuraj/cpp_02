/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:25:18 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/21 17:45:32 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{ 
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << "\tis a at start\n" << std::endl;
	std::cout << ++a << "\t is a at ++a\n" << std::endl;
	std::cout << a << "\tis a after ++a\n" << std::endl;
	std::cout << a++ << "\tis a at a++\n" << std::endl;
	std::cout << a << "\tis a at a++\n" << std::endl;
	std::cout << b << "\tvalue of b\n" << std::endl;
	std::cout << Fixed::max( a, b ) << "\t the max of a and b\n" << std::endl;
	
	return 0; 
}