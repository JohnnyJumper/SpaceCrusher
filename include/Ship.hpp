/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:10:56 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/30 21:41:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
# define SHIP_HPP

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
};

class	ShipNormal : public AShip
{

	
};


class	ShipBoss : public AShip
{	
	
};


#endif
