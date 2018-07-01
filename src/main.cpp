/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:04:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/07/01 13:49:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <unistd.h>
#include "Ship.hpp"
#include "Bullet.hpp"
#include "Game.hpp"
#include <iostream>

int 	main(void)
{
	Game 	*game = new Game();

	srand (time(NULL));
	game->start();
	game->end();
	delete game;
	return (0);
}