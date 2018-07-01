/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:04:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/30 21:41:59 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <unistd.h>
#include "Ship.hpp"

#define DELAY 30000

int main(void)
{
	unsigned int choice = 0; //Users choice
	AShip		user('A'); //User ship
	
	initscr();
	curs_set(false); // "Kill" cursor
	keypad(stdscr, true);
	noecho();
	
	while (true)
	{
		choice = getch();
		clear();
		user.draw();
		
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
				//shooting
				break;
			}
		}
		usleep(DELAY);
	}
	refresh();
	endwin();
	return 0;
}