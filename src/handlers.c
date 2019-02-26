/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handlers.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 14:53:35 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 21:14:06 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

intmax_t	label_size(t_asm *env, t_code *label, t_code *op, int direction)
{
	intmax_t	len;
	t_code		*op_tmp;
	t_code		*label_tmp;

	len = 0;
	op_tmp = op;
	label_tmp = label;
	if (direction == 1)
	{
		while (label_tmp && label_tmp != op_tmp)
		{
			len -= label_tmp->size;
			label_tmp = label_tmp->next;
		}
	}
	else
	{
		while (op_tmp && op_tmp != label_tmp)
		{
			len += op_tmp->size;
			op_tmp = op_tmp->next;
		}
	}
	return (op->op.dir_size ? ft_bswap_int16(len) : ft_bswap_int32(len));
}

int			handle_label(t_asm *env, t_code *code, int i)
{
	char		*tmp;
	t_code		*list;
	int			len;

	tmp = ft_strchr(code->raw_params[i], LABEL_CHAR);
	list = env->code;
	len = 0;
	while (list)
	{
		if (list->type == 1)
		{
			if (ft_strequ((tmp + 1), list->token))
			{
				if (list->line_nb <= code->line_nb)
					code->params[0][i] = label_size(env, list, code, 1);
				else
					code->params[0][i] = label_size(env, list, code, -1);
				return (1);
			}
		}
		list = list->next;
	}
	return (0);
}

int			handle_direct(t_asm *env, t_code *code, int i)
{
	if (code->raw_params[i][1] == LABEL_CHAR)
		return (handle_label(env, code, i));
	if (ft_str_is_numeric(code->raw_params[i] + 1))
	{
		code->params[0][i] = ft_atoi(code->raw_params[i] + 1);
		if (code->op.dir_size)
			code->params[0][i] = ft_bswap_int16(code->params[0][i]);
		else
			code->params[0][i] = ft_bswap_int32(code->params[0][i]);
	}
	else
		return (0);
	return (1);
}

int			handle_indirect(t_asm *env, t_code *code, int i)
{
	if (code->raw_params[i][0] == LABEL_CHAR)
		return (handle_label(env, code, i));
	if (ft_str_is_numeric(code->raw_params[i]))
		code->params[0][i] = ft_bswap_int16(ft_atoi(code->raw_params[i]));
	else
		return (0);
	return (1);
}

int			handle_reg(t_asm *env, t_code *code, int i)
{
	if (ft_str_is_numeric(code->raw_params[i] + 1) &&
		ft_strlen(code->raw_params[i] + 1) < 3)
		code->params[0][i] = ft_atoi(code->raw_params[i] + 1);
	else
		return (0);
	return (1);
}
