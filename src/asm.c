/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 19:57:44 by quruiz      ###    #+. /#+    ###.fr     */
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
	if (code == 5)
		printf("Name too long\n");
	if (code == 6)
		printf("Comment too long\n");

/*
**	a la moindre erreur de syntaxe
**	printf("Syntax error at [%3.d:%3.d] "%s"", line, col, token);
**
**	Parametre invalide
**	printf("Invalid parameter %d type %s for instruction %s [%3.d:%3.d]", param_nb, param_type, op_name, line, col);
**
*/	

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
	free_all(env);
	// ft_putstr(env->header->prog_name);
	// ft_putstr(env->header->comment);
}