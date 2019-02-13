/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 17:19:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:38:19 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		check_label_chars(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(LABEL_CHARS, str[i]))
			i++;
		else
			break ;
	}
	if (str[i] == LABEL_CHAR)
		return (1);
	return (0);
}

void	add_to_list(t_asm *env, t_code *n)
{
	t_code	*tmp;

	tmp = env->code;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = n;
			return ;
		}
		tmp = tmp->next;
	}
	env->code = n;
	return ;
}
