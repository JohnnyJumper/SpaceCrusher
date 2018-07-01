/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 02:24:10 by jtahirov          #+#    #+#             */
/*   Updated: 2018/07/01 15:44:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>

#define DELAY 30000
#define debug(x, z) (mvprintw(10, 10, x, z)) // x is format and z is the wvlue only one undortunately .


Game::Game(){
	// initialize ncurses window and creating player + some initial variables. wave corresponds to initial level
	initscr();
	curs_set(false);
	keypad(stdscr, true);
	cbreak();
	noecho();
	nodelay(stdscr, true);
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	getmaxyx(stdscr, this->_maxY, this->_maxX);
	srand(time(NULL));
	this->player = new ShipNormal('A', (this->_maxX / 2), (this->_maxY - 10), 100, 1);
	this->_numberBullets = 0;
	this->_numberEnemies = 0;
	this->_wave = 5;
}
Game::~Game(){
	//Trying to delete each bullet that left then delete player. also need to delete enemies.
	for (int i = 0; i < this->_numberBullets; i++)
		if (this->bullets[i])
			delete this->bullets[i];
	delete this->player;
}

void		Game::checkCollision()
{
	char	*tty = "/dev/ttys002";
	int		fd = open(tty, O_WRONLY);

	//this part checks player-enemy collision
	for (int i = 0; i < _numberEnemies; i++)
	{
		if (this->enemy[i] && this->enemy[i]->getX() == this->player->getX() &&
			this->enemy[i]->getY() == this->player->getY())
		{
				mvprintw(this->_maxY / 2, this->_maxX / 2 - 5, "GAME OVER :(");
				refresh(); 
				dprintf(fd, "you sucker they hit you, game over\n");
				sleep(3);
				this->end();
				exit(1);
		}
	}
	
	//this part checks bullet-enemy collision
	for (int i = 0; i < _numberBullets; i++)
	{
		if (!this->bullets[i])
			continue;
			
		for (int j = 0; j < _numberEnemies; j++)
		{
			if (this->enemy[j] && this->enemy[j]->getX() == this->bullets[i]->getX() &&
				this->enemy[j]->getY() == this->bullets[i]->getY())
			{
					delete this->enemy[j];
					this->enemy[j] = NULL;
					for (int x = j; x < this->_numberEnemies && enemy[x]; x++)
						enemy[x] = enemy[x + 1];
					this->_numberEnemies--;
			}
		}
	}

}
	
//Game::bulletsRoutine handles all logic regarding bullets
void Game::bulletsRoutine(){
	for (int i = this->_numberBullets; i >= 0; i--)
	{
		// Check if this bullet still exists
		if (!bullets[i])
			continue;
		// Get bullet's coordinate y  they are moving in y direction only
		int y = bullets[i]->getY();

		// Check if the bullet managed to get away delete it  and shift array of bullets to the left 
		// not efficient but hey someone has to do this ugly job :D
		// also keeps eye on number of bullets just because.
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
		// Same stuff as wit ships. updates their coordinates and then draws.
		bullets[i]->update();
		bullets[i]->draw();
	}
}

// Game::userHandle handles all user inputs part of Game's infinity while loop for reference.
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
		this->enemy[i] = new ShipNormal(this->_maxX, level); // Create Enemy ship that is the normal 
																//ship but with this specificly overloaded constructo
	}
	this->_numberEnemies = level; // Number of Enemies  = current level. 
}

void Game::enemyRoutine(void) {

	if (this->_numberEnemies < 5) // If no enemies create new wave of enemies!
		this->spawnEnemies(this->_wave++);
	for (int i = 0; i < this->_numberEnemies; i++) {
		// check if this enemy is not dead
		if (!this->enemy[i])
			continue ;
		// get his coordinates, yes i am lazy to write all of it...
		int tempx = this->enemy[i]->getX();
		int tempy = this->enemy[i]->getY();
		// check if enemy managed to get outside of the board
		// and if so kill it. After make enemy[i] == NULL and decrease amount of Enemies;
		// Start loop over.
		if (tempx > this->_maxX || tempy > this->_maxY) { //<-- this just removes random ships
			delete this->enemy[i];
			this->enemy[i] = NULL;
			for (int x = i; x < this->_numberEnemies && enemy[x]; x++)
				enemy[x] = enemy[x + 1];
			this->_numberEnemies--;
			continue ;
		}
		// These function corresponds to logic of each enemy.
		// update changes it's coordinate randomly
		// draw draws them on the board
		this->enemy[i]->update();
		this->enemy[i]->draw();
		// End of routine. :) 
	}
}



void Game::start()  // Main Loop of the game
{
	while (true)
	{
		clear(); // Clear... really... just clear...
		
		box(stdscr, 0, 0); // Draw a box around terminal
		this->enemyRoutine(); // All logic for enemies
		this->bulletsRoutine(); // All logic for bullets

		/*  Need some function that will check whether any of the ships collided with bullets or vice versa.
			When bullet hits something it should destroy that object and fix coresponding array (if it was enemy)
			in case if bullet hit player well i don't know substract 1 life make it blink for 3 secs and put it in the origin
			or something like this up to you...
		*/
		attron(COLOR_PAIR(1));
		this->player->draw(); // Drawing player
		attroff(COLOR_PAIR(1));
		this->userHandle(); // Getting input and changing players position correspondigly
		this->checkCollision(); //Checking if a shit hit a player
		refresh(); // I have no fucking idea whether we need to refresh after clear or not.
		usleep(DELAY); // HOW THIS WORKS? O_O 
		
	}
}

void Game::end()  // Main Loop of the game
{
	refresh();
	endwin();
	system("reset");
	this->~Game();
}