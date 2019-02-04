/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_label.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 20:59:29 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 17:29:02 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

char	*get_label(t_asm *env, char *line)
{
    char	*tmp;
	t_code	*code;

    if (!check_label_chars(line))
		return (line);
	tmp = ft_strchr(line, LABEL_CHAR);
	if (!(code = ft_memalloc(sizeof(t_code))))
	{
		free(line);
		return (err_code(MEM_ERROR, NULL, env) ? NULL : NULL);
	}
	code->type = 1;
	code->line_nb = env->line_nb;
	code->token = ft_strsub(line, 0, (tmp - line));
	code->cursor = 0; /* faire une fonction qui note l'emplacement de chaque labels */
	code->next = NULL;
	/* Ajoute le nouvel element a la liste */
	free(line);
	return (tmp);
}