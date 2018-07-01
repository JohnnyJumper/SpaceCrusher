/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 02:01:02 by jtahirov          #+#    #+#             */
/*   Updated: 2018/07/01 03:59:49 by jtahirov         ###   ########.fr       */
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
# define maxBullets 30

class Game {
	
	private:
		ShipNormal 	*player;
		ShipNormal 	*enemy[maxShip];
		ABullet		*bullets[maxBullets];
		int 		_numberBullets;
		int 		_numberEnemies;
		int 		_maxY, _maxX;
		int 		_wave;
		
		void 		bulletsRoutine();
		void 		enemyRoutine();
		void 		userHandle();
		void 		spawnEnemies(int level);



	public:
		Game();
		~Game();

		void 	start();




};

#endif