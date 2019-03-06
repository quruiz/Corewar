/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/05 16:21:09 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op		g_op_tab[17];

int		get_cmd(t_asm *env)
{
	char	*line;
	char	*trim;

	while (read_file(env, &line))
	{
		trim = ft_strtrim(line);
		if (!(trim = get_label(env, trim)))
			return (ft_free_line(&line, 0));
		if (ft_str_is_empty(trim))
			free(trim);
		else if (!get_op(env, trim))
			return (ft_free_line(&line, 0));
		free(line);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_asm	*env;

	if (argc != 2)
		return (err_code(BAD_FILENAME, NULL, NULL));
	if (check_file(&env, argv) != SUCCESS)
		return (1);
	if (!parse_file(env))
		return (1);
	// if (!get_header(env) || !get_cmd(env))
		// return (1);
	if (!encode_asm(env))
		return (1);
	if (!write_cor(env))
		return (1);
	free_all(env);
}
