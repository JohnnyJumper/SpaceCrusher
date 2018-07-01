/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:11:29 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/30 22:57:09 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bullet.hpp"

ABullet::ABullet(char rep, int x, int y) : _represent(rep),x(x), y(y) {}
ABullet::~ABullet(void) {}

int 	ABullet::getSpeed() { return this->_speed; }
int 	ABullet::getX() { return this->_x; }
int 	ABullet::getY() { return this->_y; }
int 	ABullet::getDir() { return this->_dir; }
int 	ABullet::getRepresent() { return this->_represent; }

void 	ABullet::setSpeed(int speed) {  this->_speed = speed }
void 	ABullet::setX(int x) {  this->_x = x }
void 	ABullet::setY(int y) {  this->_y = y }
void 	ABullet::setDir(int dir ) {  this->_dir = dir }



void 	ABullet::update() 
{
	this->_y += this->_dir * this->speed;
}


void 	ABullet::draw() {
	mvprintw(this->_y, this->_x, this->_represent);
}

