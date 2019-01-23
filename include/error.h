/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 18:33:17 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 18:57:21 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define SUCCESS		1
# define MEM_ERROR		2
# define BAD_FILENAME	3
# define ERROR_FILE		4
# define EMPTY_FILE		5
# define SIZE_ERROR		6
# define SYNTAX_ERROR	7
# define INVALID_PARAM	8
# define NO_LABEL		9

# define TICKET     	env->err
# define TOKEN  		env->err->token
# define LINE   		env->err->line
# define COL    		env->err->col

typedef struct		s_err
{
	int				code;
	int				line;
	int				col;
	char			*token;
}					t_err;

# endif