/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 18:07:47 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		err_code(int code, char *msg)
{
	if (code == 0)
		printf("Error malloc\n");
	if (code == 1)
		printf("Usage: %s <file>.s\n", msg);
	if (code == 2)
		printf("Can't read source file %s\n", msg);
	if (code == 3)
		printf("Empty source file %s\n", msg);
	return (0);
}

extern t_op		g_op_tab[17];

int		main(int argc, char *argv[])
{
	t_asm	*env;
	char	*file;

	if (argc != 2)
		return (err_code(1, argv[0]));
	if (!read_file(&env, argv))
		return (1);
	if (!get_header(env))
	{
		/* free(env) et tout le reste; */
		return (1);
	}
	/*
	**	Parsing
	*/
	// ft_putsplit(env->file);
	printf("NAME = %s\nCOMMENT = %s", env->header->prog_name, env->header->comment);
}