/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:54:09 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/30 16:42:30 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
//constructor
Fixed::Fixed(): _rawBits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
//destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//overloaded operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	
	return *this;
}

int Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member Function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw ) 
{
	std::cout << "setRawBits member Function called" << std::endl;
	this->_rawBits = raw;
}

