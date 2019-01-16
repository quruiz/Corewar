/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 15:28:18 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 19:37:18 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		check_extension(char *file)
{
	int		len;
	int		start;

	len = ft_strlen(file);
	if (!(file[len - 1] == 's' && file[len - 2] == '.'))
		return (0);
	return (1);
}

int		read_file(t_asm *env)
{
	char	*line;

	while (get_next_line(env->input_fd, &line) > 0)
	{
		if (*line == '#' || ft_str_is_empty(line))
			free(line);
		else if (!env->header)
		{
			if (!get_header(env, line))
				return (0);
		}
		env->error_line++;
	}
	return (1);
}

int		init_read(t_asm **env, char **arg)
{
	if (!check_extension(arg[1]))
		return (err_code(1, NULL));
	if (!(*env = ft_memalloc(sizeof(t_asm))))
		return (err_code(0, NULL));
	(*env)->name = ft_strsub(arg[1], 0, (ft_strlen(arg[1]) - 1));
	(*env)->name = ft_conncat((*env)->name, "cor", ft_strlen((*env)->name), 3);
	(*env)->input_fd = open(arg[1], O_RDONLY);
	(*env)->error_line = 1;
	if ((*env)->input_fd == -1)
		return (err_code(2, *env));
	if (!read_file(*env))
		return (0);
	return (1);
}
