/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:07:31 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 17:15:16 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

/*  Constructors and Destructors  */

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap('" << name << "') constructor called." << std::endl;
	this->setHitPoints(HP);
	this->setAttackDamage(AD);
	this->setEnergyPoints(EP);
	this->guardMode = false;
}

ScavTrap::ScavTrap(const ScavTrap& that) : ClapTrap(that), guardMode(that.guardMode) {
	std::cout << "ScavTrap(ScavTrap) constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "~ScavTrap destructor called on " << this->getName() << std::endl;
}

/*  Operators Overloads  */

ScavTrap&	ScavTrap::operator=(const ScavTrap& that) {
	std::cout << "ScavTrap = overload called" << std::endl;

	if (this != &that)
	{
		ClapTrap::operator=(that);
		this->guardMode = that.guardMode;
	}
	return *this;
}

/*  Getters and Setters  */

bool	ScavTrap::getStatus(void) const {
	return this->guardMode;
}

/*  Member Functions  */

void	ScavTrap::attack(const std::string& target) {
	std::cout << this->getName();

	if (this->getEnergyPoints() <= 0 && this->getHitPoints() <= 0)
	{
		std::cout << " is out of EP AND HP, give it a break!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << " has no more energy." << std::endl;
		return ;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << " is already dead, it can't attack!" << std::endl;
		return ;
	}

	std::cout << " DEMOLISHES " << target << " for " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate(void) {
	std::cout << this->getName();

	if (this->getEnergyPoints() <= 0 && this->getHitPoints() <= 0) {
		std::cout << " can't change stances: it's dead and exhausted!" << std::endl;
		return ;
	}
	if (this->getHitPoints() <= 0) {
		std::cout << " won't be changing stances, on account of it being dead." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0) {
		std::cout << " can't change stances because it's out of Energy Points." << std::endl;
		return ;
	}

	if (this->guardMode)
		std::cout << " is no longer in Gate Keeper Mode." << std::endl;
	else
		std::cout << " engaged Gate Keeper Mode." << std::endl;

	this->guardMode = !this->guardMode;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	std::string msg = this->getName();

	if (this->getHitPoints() <= 0)
	{
		std::cout << "Why, dude? ScavTrap " << msg << " is already dead!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << msg << " took " << amount << " points of damage!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void	ScavTrap::beRepaired(unsigned int amount) {
	std::string msg = this->getName();
	
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
	{
		std::string which;
		if (this->getEnergyPoints() <= 0 && this->getHitPoints() <= 0)
			which = "Hit Points and Energy Points!";
		else if (this->getEnergyPoints() <= 0)
			which = "Energy Points!";
		else
			which = "Hit Points!";

		std::cout << "ScavTrap " << msg << " can't repair: out of " << which << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << msg << " repairs itself for " << amount << " Hit Points!" << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << "New health: " << this->getHitPoints() << std::endl;

	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

