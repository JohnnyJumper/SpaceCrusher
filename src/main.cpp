/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:04:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/07/01 03:06:23 by jtahirov         ###   ########.fr       */
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

	game->start();
	refresh();
	endwin();
	delete game;
	return (0);
}