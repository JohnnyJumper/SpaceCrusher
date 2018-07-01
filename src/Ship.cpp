/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:11:03 by psprawka          #+#    #+#             */
/*   Updated: 2018/07/01 15:44:11 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"
#include <ncurses.h>
#include <iostream>
#include <fcntl.h>

#define debug(x, z) (mvprintw(10, 10, x, z))

/*
** -------------------------------- FUNCTIONS ----------------------------------
*/
void	AShip::draw(void) {
	
	mvaddch(this->_y, this->_x, this->_represent);
}

void	AShip::moveLeft(void) {
	this->_x = std::max(0, this->_x - 1);
}
void	AShip::moveRight(void) {
	this->_x += this->_speed;
}

void 	AShip::moveUp(void) {
	this->_y -= this->_speed;
}

void 	AShip::moveDown(void) {
	this->_y += this->_speed;
}

ABullet 	*AShip::shoot(void) {
	ABullet 	*bullet;

	bullet = new DefaultBullet(this->_x, this->_y - 1, -1);
	return bullet;
}

void 	AShip::update() {
	int 	randomNumber;
	int 	delay;

	randomNumber = rand() % 3;
	delay = rand() % 10;
	switch(randomNumber)
	{
		case 0: //Moving forward
		{
			if (delay == 0)
				this->_y -= this->_speed;
			break ;
		}
		case 1: // Moving right (?)
		{
			if (delay == 0)
				this->_x += this->_speed;
			break ;
		}
		case 2: // Moving left (?)
		{
			if (delay == 0)
				this->_x -= this->_speed;
			break ;
		}
	}
}


/*
** -------------------------------- CANONICAL ----------------------------------
*/
AShip::AShip(int rep, int x, int y, int hp, int speed): _x(x), _y(y), _hp(hp), _represent(rep), _speed(speed) {}
AShip::~AShip(void) {}


/*
** -------------------------------- Setters / Getters ----------------------------------
*/

	int AShip::getX() { return this->_x; }
	int AShip::getY() { return this->_y; }
	int AShip::getHP() { return this->_hp; }
	int AShip::getRep() { return this->_represent; }
	int AShip::getSpeed() { return this->_speed; }

	void AShip::setX(int x) {this->_x = x;}
	void AShip::setY(int y) {this->_y = y;}
	void AShip::setHP(int hp) {this->_hp = hp;}
	void AShip::setRep(int rep) {this->_represent = rep;}
	void AShip::setSpeed(int speed) {this->_speed = speed;}
	
/*
** -------------------------------- SHIP_NORMAL -------------------------------
*/

ShipNormal::ShipNormal(int rep) : AShip(rep, (50), (50), 3, 1) {}
ShipNormal::ShipNormal(int rep, int x, int y, int hp, int speed) : AShip(rep, x, y, hp, speed) {}
ShipNormal::~ShipNormal(void) {}


// Specific constructo use only and only with enemy ships !
ShipNormal::ShipNormal(int maxX, int level) : AShip('@',0,0,0,0) {
	int 	randomX;

	randomX = rand() % maxX;
	this->setRep('X');
	this->setX(randomX);
	this->setY(level);
	this->setHP(1);
	this->setSpeed(-1);	
}