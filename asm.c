/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/28 20:21:08 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm_struct.h"

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
	// if (!read_file(&env, argv))
	// 	return (1);
	/*
	**	Parsing
	*/
	// ft_putsplit(env->file);
	int i;
	int j;

	i = 0;
	while (i < 16)
	{
		j = 0;
		dprintf(1, "%s =\t", g_op_tab[i].name);
		while (j < g_op_tab[i].nb_param)
		{
			ft_putnbr((int)g_op_tab[i].param[j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}