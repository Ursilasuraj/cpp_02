/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:40:50 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/28 16:41:12 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : _raw(0) {}

Fixed::Fixed(int const n)
{
  _raw = n << _fb;
}

Fixed::Fixed(float const f)
{
 _raw = static_cast<int>(roundf(f * (1 << _fb)));
}

Fixed::Fixed(Fixed const &other)
{
 _raw = other._raw;
}

// Destructor
Fixed::~Fixed() {}

// Assignment operator
Fixed &Fixed::operator=(Fixed const &other)
{
	if (this != &other)
					_raw = other._raw;
	return *this;
}

// Getters / setters
int Fixed::getRawBits(void) const
{
 return _raw;
}

void Fixed::setRawBits(int raw)
{
  _raw = raw;
}

// Conversions
float Fixed::toFloat(void) const
{
 return static_cast<float>(_raw) / (1 << _fb);
}

int Fixed::toInt(void) const
{
 return _raw >> _fb;
}

// Comparison operators
bool Fixed::operator>(Fixed const &other) const { return _raw > other._raw; }
bool Fixed::operator<(Fixed const &other) const { return _raw < other._raw; }
bool Fixed::operator>=(Fixed const &other) const { return _raw >= other._raw; }
bool Fixed::operator<=(Fixed const &other) const { return _raw <= other._raw; }
bool Fixed::operator==(Fixed const &other) const { return _raw == other._raw; }
bool Fixed::operator!=(Fixed const &other) const { return _raw != other._raw; }

// Arithmetic operators
Fixed Fixed::operator+(Fixed const &other) const
{
 return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const
{
 return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
 return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
 return Fixed(this->toFloat() / other.toFloat());
}

// Increment / decrement
Fixed &Fixed::operator++()
{
	_raw++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_raw++;
	return temp;
}

Fixed &Fixed::operator--()
{
		_raw--;
		return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_raw--;
	return temp;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._raw > b._raw)
		return (a);
	else
		return (b);
}
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._raw < b._raw)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._raw < b._raw)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._raw > b._raw)
		return (a);
	else
		return (b);
}
