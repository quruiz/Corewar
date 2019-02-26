/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   encode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 14:38:51 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 18:47:24 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		handle_params(t_asm *env, t_code *tmp)
{
	int		i;

	i = 0;
	while (i < tmp->op.nb_param)
	{
		if (tmp->params[1][i] == T_REG)
		{
			if (!handle_reg(env, tmp, i))
				return (0);
		}
		else if (tmp->params[1][i] == T_DIR)
		{
			if (!handle_direct(env, tmp, i))
				return (0);
		}
		else if (tmp->params[1][i] == T_IND)
		{
			if (!handle_indirect(env, tmp, i))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int		encode_asm(t_asm *env)
{
	t_code	*tmp;

	tmp = env->code;
	while (tmp)
	{
		env->line_nb = tmp->line_nb;
		if (tmp->type == 2)
		{
			if (!handle_params(env, tmp))
				return (err_code(INVALID_PARAM, tmp->token, env));
		}
		tmp = tmp->next;
	}
	return (1);
}
