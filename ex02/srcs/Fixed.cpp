/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:24:14 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/21 18:20:13 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawbits(0) {}

Fixed::Fixed(const int n) : _rawbits(n << fractional_bits) {}

Fixed::Fixed(const float f)
{
    float offset = 0.5f;
    if (f < 0)
        offset = -0.5f;

    _rawbits = static_cast<int>(f * (1 << fractional_bits) + offset);
}

Fixed::Fixed(const Fixed &other) : _rawbits(other._rawbits) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
	this->_rawbits = other._rawbits;
	return *this;
}

bool Fixed::operator>(const Fixed &other) const { return this->_rawbits > other._rawbits; }
bool Fixed::operator<(const Fixed& other) const { return this->_rawbits < other._rawbits; }
bool Fixed::operator>=(const Fixed& other) const { return this->_rawbits >= other._rawbits; }
bool Fixed::operator<=(const Fixed& other) const { return this->_rawbits <= other._rawbits; }
bool Fixed::operator==(const Fixed& other) const { return this->_rawbits == other._rawbits; }
bool Fixed::operator!=(const Fixed& other) const { return this->_rawbits != other._rawbits; }

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result._rawbits = this->_rawbits + other._rawbits;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result._rawbits = this->_rawbits - other._rawbits;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result._rawbits = (this->_rawbits * other._rawbits) / (1 << fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result._rawbits = (this->_rawbits * (1 << fractional_bits)) / other._rawbits;
	return result;
}

Fixed &Fixed::operator++() {
	this->_rawbits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_rawbits++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_rawbits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_rawbits--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const {
	return this->_rawbits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawbits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_rawbits) / (1 << fractional_bits);
}

int Fixed::toInt(void) const {
	return this->_rawbits >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
return out;
}

