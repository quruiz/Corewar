/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_cmd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 21:00:16 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 17:45:45 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_cmd(t_asm *env)
{
	char	*line;
	char	*trim;

	while (read_file(env, &line))
	{
		if (ft_str_is_empty(line))
			return (1);
		trim = ft_strtrim(line);
		if (!(trim = get_label(env, trim)))		/* detecte si il y a un label et retourne trim pointant juste apres le label */
			return (0);
		if (ft_str_is_empty(trim))
			;
		else if (!get_op(env, trim)) 					/* recupere l'instruction si presente et encode si pas de label et retourne 1 ou 0 en cas d'erreur */
			return (0);
		free(line);
	}
	return (err_code(NEW_LINE, NULL, env));
}
