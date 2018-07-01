/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:11:03 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/30 21:42:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"
#include <curses.h>
#include <iostream>

/*
** -------------------------------- FUNCTIONS ----------------------------------
*/
void	AShip::draw(void)
{
	mvprintw(this->_y, this->_x, "A");
	this->_represent = 'x';
}

void	AShip::moveLeft(void)
{
	this->_x = std::max(0, this->_x - 1);
}

void	AShip::moveRight(void)
{
	this->_x++;
}

/*
** -------------------------------- CANONICAL ----------------------------------
*/
AShip::AShip(char rep): _represent(rep)
{
	this->_x = rand() % 10; // 10 = mapsize
	this->_y = 20;
	this->_hp = 100;
}