/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:11:29 by psprawka          #+#    #+#             */
/*   Updated: 2018/07/01 15:56:26 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bullet.hpp"
#include <curses.h>

ABullet::ABullet(char rep, int x, int y, int dir, int speed) :  _x(x), _y(y), _speed(speed), _represent(rep), _dir(dir) {}
ABullet::~ABullet(void) {}

int 	ABullet::getSpeed() { return this->_speed; }
int 	ABullet::getX() { return this->_x; }
int 	ABullet::getY() { return this->_y; }
int 	ABullet::getDir() { return this->_dir; }
int 	ABullet::getRepresent() { return this->_represent; }

void 	ABullet::setSpeed(int speed) {  this->_speed = speed; }
void 	ABullet::setX(int x) {  this->_x = x; }
void 	ABullet::setY(int y) {  this->_y = y; }
void 	ABullet::setDir(int dir ) {  this->_dir = dir; }

void 	ABullet::update() 
{
	this->_y += this->_dir * this->_speed;
}

void 	ABullet::draw() {
	mvprintw(this->_y, this->_x, &this->_represent);
}

/*
** ----------------------------- Default Bullet -------------------
*/

DefaultBullet::DefaultBullet(int x, int y, int dir) : ABullet('|', x, y, dir, 1) {}
DefaultBullet::~DefaultBullet(void) {}
DefaultBullet::DefaultBullet(int x, int y, bool enemy) : ABullet('|', x, y, 1, 1) { (void) enemy; }