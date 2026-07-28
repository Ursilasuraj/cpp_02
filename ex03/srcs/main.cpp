/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:45:34 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/28 16:52:40 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void print_result(std::string const &label, bool result)
{
 std::cout << label << ": " << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main()
{
	// Triangle ABC
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A = (0, 0)" << std::endl;
	std::cout << "B = (10, 0)" << std::endl;
	std::cout << "C = (5, 10)\n" << std::endl;

	// 1. Inside
	{
		Point p(5.0f, 5.0f);
		print_result("Test 1 (inside)", bsp(a, b, c, p));
	}
	{
		Point p(-5.0f, 5.0f);
		print_result("Test 2 (outside left)", bsp(a, b, c, p));
	}
	{
		Point p(20.0f, 5.0f);
		print_result("Test 3 (outside right)", bsp(a, b, c, p));
	}
	{
		Point p(5.0f, -5.0f);
		print_result("Test 4 (outside below)", bsp(a, b, c, p));
	}
	{
		Point p(5.0f, 20.0f);
		print_result("Test 5 (outside above)", bsp(a, b, c, p));
	}
	{
		Point p(0.0f, 0.0f);
		print_result("Test 6 (vertex A)", bsp(a, b, c, p));
	}
	{
		Point p(10.0f, 0.0f);
		print_result("Test 7 (vertex B)", bsp(a, b, c, p));
	}
	{
		Point p(5.0f, 10.0f);
		print_result("Test 8 (vertex C)", bsp(a, b, c, p));
	}
	{
		Point p(5.0f, 0.0f);
		print_result("Test 9 (edge AB)", bsp(a, b, c, p));
	}
	{
		Point p(7.5f, 5.0f);
		print_result("Test 10 (edge BC)", bsp(a, b, c, p));
	}
	{
		Point p(2.5f, 5.0f);
		print_result("Test 11 (edge CA)", bsp(a, b, c, p));
	}
	return 0;
}











