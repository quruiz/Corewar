/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_cor.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 17:47:14 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 17:00:00 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

void	get_prog_size(t_asm *env)
{
	t_code			*tmp;
	unsigned int	size;

	tmp = env->code;
	size = 0;
	while (tmp)
	{
		if (tmp->type == 2)
			size += tmp->size;
		tmp = tmp->next;
	}
	env->header.prog_size = ft_bswap_int32(size);
}

void	put_op(t_asm *env, t_code *op)
{
	int		i;
	int		val;

	i = 0;
	write(env->output_fd, &op->op.op_code, 1);
	op->op.byte_param ? write(env->output_fd, &op->byte, 1) : 0;
	while (i < op->op.nb_param)
	{
		val = ft_recursive_power(4, i);
		if (op->byte & (64 / val))
			write(env->output_fd, &op->params[i], 1);
		else if (op->byte & ((128 / val) + (64 / val)))
			write(env->output_fd, &op->params[i], 2);
		else if (op->byte & (128 / val))
			write(env->output_fd, &op->params[i], op->op.dir_size ? 2 : 4);
		i++;
	}
}

int		write_cor(t_asm *env)
{
	t_code	*tmp;

	tmp = env->code;
	get_prog_size(env);
	init_output(env);
	write(env->output_fd, &env->header, sizeof(t_header));
	while (tmp)
	{
		if (tmp->type == 2)
		{
			put_op(env, tmp);
		}
		tmp = tmp->next;
	}
	return (1);
}
