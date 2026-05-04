/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:07:31 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/04 16:38:58 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

/*  Constructors and Destructors  */

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap('" << name << "') constructor called." << std::endl;
	this->setHitPoints(HP);
	this->setAttackDamage(AD);
	this->setEnergyPoints(EP);
	this->hasHighFive = false;
	this->highFiveTurns = 0;
}

FragTrap::FragTrap(const FragTrap& that)
	: ClapTrap(that), highFiveTurns(that.highFiveTurns), hasHighFive(that.hasHighFive) {
	std::cout << "FragTrap(FragTrap) constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "~FragTrap destructor called on " << this->getName() << std::endl;
}

/*  Operators Overloads  */

FragTrap&	FragTrap::operator=(const FragTrap& that) {
	std::cout << "FragTrap = overload called" << std::endl;

	if (this != &that)
	{
		ClapTrap::operator=(that);
		this->hasHighFive = that.hasHighFive;
		this->highFiveTurns = that.highFiveTurns;
	}
	return *this;
}

/*  Member Functions  */

void	FragTrap::attack(const std::string& target) {
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

	std::cout << " absolutely brutalizes " << target << " for " << this->getAttackDamage();
	std::cout << " points of damage." << std::endl;

	if (this->hasHighFive)
		std::cout << " High Five Damage Bonus!" << std::endl;

	this->tickHighFive();

	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	FragTrap::tickHighFive(void) {
	if (!this->hasHighFive)
		return ;

	this->highFiveTurns--;

	if (this->highFiveTurns <= 0)
	{
		this->highFiveTurns = 0;
		this->hasHighFive = false;
		this->setAttackDamage(AD);
	}
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName();

	if (this->getEnergyPoints() <= 0 && this->getHitPoints() <= 0) {
		std::cout << " is dead and out of power, no way it can high five anyone!" << std::endl;
		return ;
	}
	if (this->getHitPoints() <= 0) {
		std::cout << " won't be requesting high fives, on account of it being dead." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0) {
		std::cout << " can't raise its hand for a high five, out of Energy Points." << std::endl;
		return ;
	}

	std::cout << " has requested a nice high five!" << std::endl;
	this->hasHighFive = true;
	this->highFiveTurns = HF;
	this->setAttackDamage((int)(AD * 1.5f));
}

void	FragTrap::takeDamage(unsigned int amount) {
	std::string msg = this->getName();

	if (this->getHitPoints() <= 0)
	{
		std::cout << "Why, dude? FragTrap " << msg << " is already dead!" << std::endl;
		return ;
	}

	std::cout << "FragTrap " << msg << " took " << amount << " points of damage!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void	FragTrap::beRepaired(unsigned int amount) {
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

		std::cout << "FragTrap " << msg << " can't repair: out of " << which << std::endl;
		return ;
	}
	std::cout << "FragTrap " << msg << " repairs itself for " << amount << " Hit Points!" << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << "New health: " << this->getHitPoints() << std::endl;

	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	FragTrap::special(void) {
	this->highFivesGuys();
}

