/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   encode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 14:38:51 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 21:26:35 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		handle_params(t_code *tmp)
{
	int		i;

	while (i < 3)
	{
		if (tmp->raw_params[i][0] == 'r')
		{
			if (handle_reg(tmp, i))
				return (0);
		}
		else if (tmp->raw_params[i][0] == DIRECT_CHAR || tmp->raw_params[i][0] == LABEL_CHAR)
		{
			if (tmp->raw_params[i][1] != LABEL_CHAR)
			{
				if (!handle_direct(tmp, i))
					return (0);
			}
			else if (!handle_label(tmp, i))
				return (0);
		}
		else if (ft_isdigit(tmp->raw_params[i][0]))
		{
			if (!handle_indirect(tmp, i))
				return (0);
		}
		i++;
	}
	return (1);
}

int		encode_asm(t_asm *env)
{
	t_code	*tmp;

	tmp = env->code;
	while ((tmp = tmp->next))
	{
		if (handle_params(tmp))
			return (0);
	}
	return (1);
}