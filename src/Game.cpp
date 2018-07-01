/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 02:24:10 by jtahirov          #+#    #+#             */
/*   Updated: 2018/07/01 04:56:11 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <unistd.h>
#include <ncurses.h>

#define DELAY 60000
#define debug(x, z) (mvprintw(10, 10, x, z))


Game::Game(){
	initscr();
	curs_set(false);
	keypad(stdscr, true);
	cbreak();
	noecho();
	nodelay(stdscr, true);
	getmaxyx(stdscr, this->_maxY, this->_maxX);
	srand(time(NULL));
	this->player = new ShipNormal('A', (this->_maxX / 2), (this->_maxY - 10), 100, 1);
	this->_numberBullets = 0;
	this->_numberEnemies = 0;
	this->_wave = 5;
}
Game::~Game(){
	for (int i = 0; i < this->_numberBullets; i++)
		if (this->bullets[i])
			delete this->bullets[i];
	delete this->player;
}

void Game::bulletsRoutine(){
	for (int i = this->_numberBullets; i >= 0; i--)
	{

		if (!bullets[i])
			continue;
		int y = bullets[i]->getY();

		if (y >= this->_maxY || y < 0)
		{
			delete bullets[i];
			bullets[i] = NULL;
			for (int j = i; j < this->_numberBullets && bullets[i]; j++)
			{
				bullets[j] = bullets[j + 1];
			}
			this->_numberBullets--;
			continue;
		}
		bullets[i]->update();
		bullets[i]->draw();
	}
}

void Game::userHandle(void) {
	unsigned int choice;

	switch (choice = getch())
	{
		case KEY_LEFT:
		{
			this->player->moveLeft();
			break;
		}
		case KEY_RIGHT:
		{
			this->player->moveRight();
			break;
		}
		case KEY_UP:
		{
			this->player->moveUp();
			break;
		}
		case KEY_DOWN:
		{
			this->player->moveDown();
			break;
		}
		case ' ':
		{
			this->bullets[this->_numberBullets++] = this->player->shoot();
			break;
		}
	}
}

void Game::spawnEnemies(int level) {
	if (level > maxShip - 1)
	 	return ; // WE JUST WON THE GAME!
	for (int i = 0; i < level && i < maxShip; i++) {
		this->enemy[i] = new ShipNormal(this->_maxX, level);
	}
	this->_numberEnemies = level;
}

void Game::enemyRoutine(void) {

	if (this->_numberEnemies == 0)
		this->spawnEnemies(this->_wave++);
	for (int i = 0; i < this->_numberEnemies; i++) {
		
		if (!this->enemy[i])
			continue ;
		
		int tempx = this->enemy[i]->getX();
		int tempy = this->enemy[i]->getY();

		if (tempx > this->_maxX || tempy > this->_maxY) {
			delete this->enemy[i];
			this->enemy[i] = NULL;
			this->_numberEnemies--;
			continue ;
		}	
		this->enemy[i]->update();
		this->enemy[i]->draw();
	}
}

void Game::start()
{
	while (true)
	{
		clear();
		refresh();
		box(stdscr, 0, 0);
		this->enemyRoutine();
		this->bulletsRoutine();
		this->player->draw();
		// mvprintw(0, 0, "%d and %d", this->_maxX, this->_maxY);
		this->userHandle();
		usleep(DELAY);
	}
}