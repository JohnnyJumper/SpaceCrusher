/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:10:56 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/30 23:39:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
# define SHIP_HPP
# include "Bullet.hpp"

class	AShip
{
	private:
		int		_x, _y;			//coordinates
		int		_hp;
		char	_represent;

	public:
		AShip(char rep);

		void	draw(void);
		void	moveLeft(void);
		void	moveRight(void);

		ABullet	*shoot(void);
};

class	ShipNormal : public AShip
{

	
};


class	ShipBoss : public AShip
{	
	
};


#endif
