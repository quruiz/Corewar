/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_cor.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 17:47:14 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 21:19:42 by quruiz      ###    #+. /#+    ###.fr     */
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
			size += (size + tmp->size);
		tmp = tmp->next;
	}
	env->header.prog_size = ft_bswap_int32(size);
}

int		write_cor(t_asm *env)
{
	t_code	*tmp;
	int		i;

	tmp = env->code;
	get_prog_size(env);
	init_output(env);
	put_header(env->header);
	while (tmp)
	{
		if (tmp->type == 2)
		{
			i = 0;
			write(env->output_fd, &tmp->op.op_code, 1);
			tmp->op.byte_param ? write(env->output_fd, &tmp->byte, 1) : 0;
			while (i < tmp->op.nb_param)
			{
				if (tmp->params[1][i] == T_REG)
					write(env->output_fd, &tmp->params[0][i], 1);
				else if (tmp->params[1][i] == T_IND)
					write(env->output_fd, &tmp->params[0][i], 2);
				else if (tmp->params[1][i] == T_DIR)
					write(env->output_fd, &tmp->params[0][i], tmp->op.dir_size ? 2 : 4);
				i++;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
