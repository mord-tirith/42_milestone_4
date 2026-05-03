/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:51:18 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 15:04:03 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*  Constructors and Destructors  */

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap(void) constructor called" << std::endl;
	this->name = "";
	this->attackDamage = 0;
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(const std::string& name) {
	std::cout << "ClapTrap(string '" << name << "') constructor called" << std::endl;
	this->name = name;
	this->attackDamage = 0;
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap& that) {
	std::cout << "ClapTrap(ClapTrap) constructor called" << std::endl;
	*this = that;
}

ClapTrap::~ClapTrap(void) {
	bool		unnamed = this->name.empty();
	std::string	msg = unnamed ? "a nameless Claptrap" : this->name;
	std::cout << "~ClapTrap destructor called on " << msg << std::endl;
}

/*  Operators Overloads  */
ClapTrap&	ClapTrap::operator=(const ClapTrap& that) {
	std::cout << "ClapTrap = overload called" << std::endl;
	this->name = that.name;
	this->attackDamage = that.attackDamage;
	this->hitPoints = that.hitPoints;
	this->energyPoints = that.energyPoints;
	return *this;
}

/*  Getters and Setters  */

int	ClapTrap::getAttackDamage(void) const {
	return this->attackDamage;
}

int	ClapTrap::getEnergyPoints(void) const {
	return this->energyPoints;
}

int	ClapTrap::getHitPoints(void) const {
	return this->energyPoints;
}

std::string	ClapTrap::getName(void) const {
	return this->name;
}

void	ClapTrap::setHitPoints(int newHitPoints) {
	this->hitPoints = newHitPoints;
}

void	ClapTrap::setAttackDamage(int newAttackDamage) {
	this->attackDamage = newAttackDamage;
}

void	ClapTrap::setEnergyPoints(int newEnergyPoints) {
	this->energyPoints = newEnergyPoints;
}

/*  Member Functions  */

void ClapTrap::attack(const std::string& target) {
	std::string msg = this->name.empty() ? "without name" : this->name;
	
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::string which;
		if (this->energyPoints <= 0 && this->hitPoints <= 0)
			which = "Hit Points and Energy Points!";
		else if (this->energyPoints <= 0)
			which = "Energy Points!";
		else
			which = "Hit Points!";

		std::cout << "ClapTrap " << msg << " can't attack: out of " << which << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << msg << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::string msg = this->name.empty() ? "without name" : this->name;

	if (this->hitPoints <= 0)
	{
		std::cout << "Stop, stop, stop! ClapTrap " << msg << " is already dead!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << msg << " took " << amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::string msg = this->name.empty() ? "without name" : this->name;
	
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::string which;
		if (this->energyPoints <= 0 && this->hitPoints <= 0)
			which = "Hit Points and Energy Points!";
		else if (this->energyPoints <= 0)
			which = "Energy Points!";
		else
			which = "Hit Points!";

		std::cout << "ClapTrap " << msg << " can't repair: out of " << which << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << msg << " repairs itself for " << amount << " Hit Points!" << std::endl;
	this->hitPoints += amount;
	std::cout << "New health: " << this->hitPoints << std::endl;

	this->energyPoints--;
}

