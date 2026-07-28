/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:08:07 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/28 16:18:45 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Cross product of vectors AB and AC
static Fixed cross(Point const a, Point const b, Point const c)
{
	Fixed bx = b.getX() - a.getX();   // AB.x
	Fixed by = b.getY() - a.getY();   // AB.y
	Fixed cx = c.getX() - a.getX();   // AC.x
	Fixed cy = c.getY() - a.getY();   // AC.y

	return (bx * cy) - (by * cx);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross1 = cross(a, b, point);
	Fixed cross2 = cross(b, c, point);
	Fixed cross3 = cross(c, a, point);

	// If point lies exactly on an edge → treat as outside
	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
		return false;

	bool pos1 = cross1 > 0;
	bool pos2 = cross2 > 0;
	bool pos3 = cross3 > 0;

	// Inside only if all cross products have the same sign
	return (pos1 == pos2) && (pos2 == pos3);
}
