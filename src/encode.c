/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   encode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 14:38:51 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 20:04:06 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int     init_output(t_asm *env)
{
	int		fd;

	fd = open(env->name, (O_WRONLY | O_CREAT));
	if (fd == -1)
		return (err_code(ERROR_FILE, NULL, env));
	env->output_fd = fd;
	return (1);
}

int		encode_asm(t_asm *env)
{
	t_code	*tmp;

	tmp = env->code;
	/*
	**	Traite les infos et les stockes
	**	puis rappel la fonction avec l'elemet suivant
	**
	**	encode_asm(tmp->next);
	**
	**	une fois fini, ecrit tout d'un coup
	*/
}