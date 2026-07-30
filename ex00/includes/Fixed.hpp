/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:54:38 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/30 15:44:18 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int _rawBits;
        static const int fractional_bits = 8;
        
    public:
        Fixed();  
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &other);
        ~Fixed(); 

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif 