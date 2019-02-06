/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 21:29:23 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 20:39:35 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		read_file(t_asm *env, char **line)
{
	int		nl;

	nl = 0;
	while (get_next_line(env->input_fd, line))
	{
		nl = 0;
		env->line_nb++;
		if (!(ft_str_is_empty(*line) || **line == COMMENT_CHAR))
			return (1);
		else if (**line != COMMENT_CHAR)
			nl = 1;
		ft_strdel(line);
	}
	return (0);
}

int		check_extension(char *file)
{
	int		len;
	int		start;

	len = ft_strlen(file);
	if (!(file[len - 1] == 's' && file[len - 2] == '.'))
		return (0);
	return (1);
}

int		check_file(t_asm **env, char **arg)
{
	t_op	*op_tab;

	
	if (!check_extension(arg[1]))
		return (err_code(BAD_FILENAME, NULL, NULL));
	if (!(*env = ft_memalloc(sizeof(t_asm))))
		return (err_code(MEM_ERROR, NULL, NULL));
	(*env)->name = ft_strsub(arg[1], 0, (ft_strlen(arg[1]) - 1));
	(*env)->name = ft_conncat((*env)->name, "cor", ft_strlen((*env)->name), 3);
	(*env)->input_fd = open(arg[1], O_RDONLY);
	(*env)->line_nb = 0;
	if ((*env)->input_fd == -1)
		return (err_code(ERROR_FILE, NULL, *env));
	if (lseek((*env)->input_fd, 0, SEEK_END) == 0)
		return (err_code(EMPTY_FILE, NULL, *env));
	lseek((*env)->input_fd, 0, SEEK_SET);
	return (SUCCESS);
}