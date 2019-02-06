/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_op.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 20:59:46 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 19:12:18 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op	g_op_tab[17];

int			get_op(t_asm *env, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (isalpha(line[i]))
		i++;
	while (j < 16)
	{
		if (ft_strnequ(line, g_op_tab[j].name, i))
			break;
		j++;
	}
	if (j == 16)
		return (err_code(SYNTAX_ERROR, NULL, env));
	free(line);
	return (1);
}