/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:11:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/07/01 15:47:42 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

class ABullet {
	private: 
		int 	_x, _y; // Coordinates
		int 	_speed; // Speed of a bullet
		char 	_represent;
		int 	_dir; // positive for down and negative for up
	
	public:
		ABullet(char rep, int x, int y, int dir, int speed);
		~ABullet(void);

		void 	update();
		void 	draw();


/*
** ----------------------------- Getters / Setters -----------------
*/
		int 	getSpeed(void);
		int 	getX(void);
		int 	getY(void);
		int 	getDir(void);
		int 	getRepresent(void);

		void 	setSpeed(int amount);
		void 	setDir(int dir);
		void 	setX(int x);
		void 	setY(int y);
		void 	setRepresent(char rep);

};


class DefaultBullet : public ABullet {

	public:
		DefaultBullet(int x, int y, int dir);
		DefaultBullet(int x, int y, bool enemy);
		~DefaultBullet(void);
		

};


#endif
