/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:58:43 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/31 11:58:44 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(); 	//default constructor
		Point(float const x, float const y); //parametrized constructor
		Point(Point const &other); //copy constructor
		Point &operator = (const Point &other); //copy assignment operator
	 	~Point();

	Fixed const &getX() const;
	Fixed const &getY() const;
};

bool bsp (Point const a, Point const b, Point const c, Point const point);

#endif
