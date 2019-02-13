/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_label.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 20:59:29 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:39:10 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

char	*get_label(t_asm *env, char *line)
{
	char	*tmp;
	t_code	*new;

	if (!check_label_chars(line))
		return (line);
	tmp = ft_strchr(line, LABEL_CHAR);
	if (!(new = ft_memalloc(sizeof(t_code))))
	{
		free(line);
		return (err_code(MEM_ERROR, NULL, env) ? NULL : NULL);
	}
	new->type = 1;
	new->line_nb = env->line_nb;
	new->token = ft_strsub(line, 0, (tmp - line));
	new->cursor = 0;
	new->next = NULL;
	add_to_list(env, new);
	tmp = ft_strtrim(tmp + 1);
	free(line);
	return (tmp);
}
