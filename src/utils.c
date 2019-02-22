/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 21:29:23 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 17:19:24 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		read_file(t_asm *env, char **line)
{
	while (get_next_line(env->input_fd, line))
	{
		env->line_nb++;
		if (ft_str_is_empty(*line) || **line == COMMENT_CHAR)
			ft_strdel(line);
		else
			return (1);
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

int		init_output(t_asm *env)
{
	int		fd;

	fd = open(env->name, O_WRONLY | O_CREAT, 0600);
	if (fd == -1)
		return (err_code(ERROR_FILE, NULL, env));
	env->output_fd = fd;
	return (1);
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
