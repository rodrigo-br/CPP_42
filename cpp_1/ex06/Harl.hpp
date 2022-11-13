#pragma once
#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>
# include <cstdlib>

class Harl
{
	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:

		Harl();
		~Harl();

		std::string		map[4];
		void 	complain( std::string level );
};

#endif