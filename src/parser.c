/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 17:11:43 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 18:43:20 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		parse_file(t_asm *env)
{
	if (!get_header(env))
		return (0);
}

char	*remove_comment(char *line)
{
	char	*comment;
	char	*tmp;

	if ((comment = ft_strchr(line, COMMENT_CHAR)))
	{
		tmp = ft_strsub(line, 0, comment - line);
		free(line);
		line = tmp;
	}
	if ((comment = ft_strchr(line, SECOND_COMMENT_CHAR)))
	{
		tmp = ft_strsub(line, 0, comment - line);
		free(line);
		line = tmp;
	}
	return (line);
}

int		read_file(t_asm *env, char **line)
{
	char	*tmp;
	int		ret;

	ret = get_next_line(env->input_fd, line);
	if (ret)
	{
		env->line_nb++;
		if (ft_str_is_empty(*line) || **line == COMMENT_CHAR || **line == SECOND_COMMENT_CHAR)
		{
			ft_strdel(line);
			return (read_file(env, line));
		}
		*line = remove_comment(*line);
		tmp = ft_strtrim(*line);
		free(*line);
		*line = tmp;
		return (1);
	}
	if (ft_str_is_empty(*line) || **line == COMMENT_CHAR || **line == SECOND_COMMENT_CHAR)
		ft_strdel(line);
	return (0);
}

int		get_cmd(t_asm *env)
{
	char	*line;

	while (read_file(env, &line))
	{
		if (!(line = get_label(env, line)))
			return (ft_free_line(&line, 0));
		if (ft_str_is_empty(line) || *line == COMMENT_CHAR)
			free(line);
		else if (!get_op(env, line))
			return (ft_free_line(&line, 0));
	}
	if (!line)
		return (1);
	return (err_code(NEW_LINE, NULL, env));
}
