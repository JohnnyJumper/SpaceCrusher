/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:04:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/30 23:41:19 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <unistd.h>
#include "Ship.hpp"
#include "Bullet.hpp"
#include <iostream>

#define DELAY 30000

void bulletsRoutine(ABullet *bullets[maxBullets], int num) {
	for (int i = 0; i < num; i++) {
		bullets[i]->update();
		bullets[i]->draw();
	}
}

int main(void)
{
	unsigned int choice = 0; //Users choice
	AShip		user('A'); //User ship
	ABullet 	*bullets[maxBullets];
	int 		numOfBullets = 0;

	initscr();
	curs_set(false); // "Kill" cursor
	keypad(stdscr, true);
	noecho();
	nodelay(stdscr, true);
	
	while (true)
	{
		choice = getch();
		clear();
		user.draw();
		bulletsRoutine(bullets, numOfBullets);
		
		switch (choice)
		{
			clear();
			
			case KEY_LEFT:
			{
				user.moveLeft();
				break;
			}
			case KEY_RIGHT:
			{
				user.moveRight();
				break;
			}
			case ' ':
			{
				bullets[numOfBullets++] = user.shoot();
				break;
			}
		}
		usleep(DELAY);
	}
	refresh();
	endwin();
	return 0;
}