/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 02:01:02 by jtahirov          #+#    #+#             */
/*   Updated: 2018/07/01 18:04:33 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include "Bullet.hpp"
#include "Ship.hpp"

# define maxShip 25
# define maxBullets 300

class Game {
	
	private:
		ShipNormal 	*player;
		ShipNormal 	*enemy[maxShip];
		ABullet		*bullets[maxBullets];
		int 		_numberBullets;
		int 		_numberEnemies;
		int 		_numberEnemiesFixed;
		int 		_maxY, _maxX;
		int 		_wave;
		int 		_playerScore;
		
		void 		bulletsRoutine();
		void 		enemyRoutine();
		void 		userHandle();
		void 		spawnEnemies(int level);
		void		checkCollision();
		void 		drawGameInfo();

	public:
		Game();
		~Game();

		void 	start();
		void	end();
};

#endif
