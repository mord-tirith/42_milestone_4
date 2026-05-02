/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:27:36 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 00:32:48 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);

int	main(void)
{
	Point	a(45, 15);
	Point	b(65, 45);
	Point	c(15, 65);
	Point	p1(42, 42);
	Point	p2;

	std::cout << "point a = " << a << std::endl;
	std::cout << "point b = " << b << std::endl;
	std::cout << "point c = " << c << std::endl;
	std::cout << "point p1 = " << p1 << std::endl;
	std::cout << "point p2 = " << p2 << std::endl;
	std::cout << "is point p1 inside the triangle? >>>" << (bsp(a,b,c,p1) ? "Yes<<<" : "No<<<<") << std::endl;
	std::cout << "is point p2 inside the triangle? >>>" << (bsp(a,b,c,p2) ? "Yes<<<" : "No<<<<") << std::endl;

	return (0);
}
