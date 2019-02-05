/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_cmd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 21:00:16 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:22:43 by quruiz      ###    #+. /#+    ###.fr     */
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
			return (ft_free_line(&line, 1));
		trim = ft_strtrim(line);
		if (!(trim = get_label(env, trim)))
			return (ft_free_line(&line, 0));
		if (ft_str_is_empty(trim))
			free(trim);
		else if (!get_op(env, trim))
			return (ft_free_line(&line, 0));
		free(line);
	}
	return (err_code(NEW_LINE, NULL, env));
}
