/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:23:12 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 23:54:55 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	
	float	d1 = crossProduct(a, b, point);
	float	d2 = crossProduct(b, c, point);
	float	d3 = crossProduct(c, a, point);

	bool	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	bool	has_zer = (d1 == 0) || (d3 == 0) || (d3 == 0);

	if (has_zer)
		return false;
	return !(has_neg && has_pos);
}
