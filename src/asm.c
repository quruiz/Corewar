/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 19:37:30 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		err_code(int code, t_asm *env)
{
	if (code == 0)
		printf("Error malloc\n");
	if (code == 1)
		printf("Usage: ./asm <file>.s\n");
	if (code == 2)
		printf("Can't read source file\n");
	if (code == 3)
		printf("Empty source file\n");
	if (code == 4)
		printf("Error at line %d\n", env->error_line);
	if (env)
		free_all(env);
	return (0);
}

extern t_op		g_op_tab[17];

int		main(int argc, char *argv[])
{
	t_asm	*env;
	char	*file;

	if (argc != 2)
		return (err_code(1, NULL));
	if (!init_read(&env, argv))
		return (1);
	// ft_putstr(env->header->prog_name);
	// ft_putstr(env->header->comment);
}