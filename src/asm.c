/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 20:08:32 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op		g_op_tab[17];

int		main(int argc, char *argv[])
{
	t_asm	*env;

	if (argc != 2)
		return (err_code(BAD_FILENAME, NULL, NULL));
	if (check_file(&env, argv) != SUCCESS)
		return (1);
	if (!get_header(env) || !get_cmd(env))
		return (1);

	int i;
	t_code	*tmp;

	tmp = env->code;
	while (tmp)
	{
		if (tmp->type == 1)
		{
			dprintf(1, "%s", "LABEL  ");
			dprintf(1, " = %s\n", tmp->token);
		}
		else if (tmp->type == 2)
		{
			i = 0;
			dprintf(1, "%s", "OP_CODE");
			dprintf(1, " = %s\t-> size = %d\t", tmp->token, tmp->size);
			ft_putsplit(tmp->params);
		}
		tmp = tmp->next;
	}
	free_all(env);
}
