/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:54:38 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/21 18:12:26 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	private:
		int value;
		static const int fractional_bits;
		
	public:
		Fixed();  
		Fixed(const Fixed &copy);
		//Deconstructor
		~Fixed(); 
		//overloaded Operators
		Fixed &operator=(const Fixed &other);
		//public Methods
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif
