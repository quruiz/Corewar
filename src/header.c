/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:13:28 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 19:49:25 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

char	*read_more(t_asm *env, char **line, char *cmd, int len)
{
	char	*tmp;
	int		size[3];

	size[0] = ft_strlen(*line);
	size[2] = ft_strlen(ft_strchr(*line, '"') + 1);
	while (get_next_line(env->input_fd, &tmp))
	{
		env->line_nb++;
		size[1] = ft_strlen(tmp);
		*line = ft_conncat(*line, "\n", size[0], 1);
		*line = ft_conncat(*line, tmp, size[0] + 1, size[1]);
		size[1] += ((!ft_strchr((*line + (size[0] - size[1])), '"')) ? 1 : 0);
		size[0] += size[1];
		size[2] += size[1];
		free(tmp);
		if (size[2] > len)
		{
			free(*line);
			return (err_code(SIZE_ERROR, cmd, env) ? NULL : NULL);
		}
		if (ft_strchr((*line + (size[0] - size[1])), '"'))
			return (*line);
	}
	free(*line);
	return (err_code(SYNTAX_ERROR, cmd, env) ? NULL : NULL);
}

int		parse_name(t_asm *env, char **line, char *dest)
{
	char	*start;
	char	*end;
	int		cmd_size;

	cmd_size = ft_strlen(NAME_CMD_STRING);
	if (!(start = ft_strnstr(*line, NAME_CMD_STRING, cmd_size)))
		return (err_code(NO_TOKEN, NAME_CMD_STRING, env));
	start += cmd_size;
	while (!ft_isprint(*start))
		start++;
	if (*start != '"')
		return (err_code(SYNTAX_ERROR, NAME_CMD_STRING, env));
	if (!(end = ft_strchr(start + 1, '"')))
	{
		if (!(*line = read_more(env, line, NAME_CMD_STRING, PROG_NAME_LENGTH)))
			return (0);
		return (parse_name(env, line, dest));
	}
	else if (!ft_str_is_empty(end + 1))
		return (err_code(SYNTAX_ERROR, NAME_CMD_STRING, env));
	if ((end - (start + 1)) > PROG_NAME_LENGTH)
		return (err_code(SIZE_ERROR, NAME_CMD_STRING, env));
	ft_strncpy(dest, (start + 1), end - (start + 1));
	return (1);
}

int		parse_comment(t_asm *env, char **line, char *dest)
{
	char	*start;
	char	*end;
	int		cmd_size;

	cmd_size = ft_strlen(COMMENT_CMD_STRING);
	if (!(start = ft_strnstr(*line, COMMENT_CMD_STRING, cmd_size)))
		return (err_code(NO_TOKEN, COMMENT_CMD_STRING, env));
	start += cmd_size;
	while (!ft_isprint(*start))
		start++;
	if (*start != '"')
		return (err_code(SYNTAX_ERROR, COMMENT_CMD_STRING, env));
	if (!(end = ft_strchr(start + 1, '"')))
	{
		if (!(*line = read_more(env, line, COMMENT_CMD_STRING, COMMENT_LENGTH)))
			return (0);
		return (parse_comment(env, line, dest));
	}
	else if (!ft_str_is_empty(end + 1))
		return (err_code(SYNTAX_ERROR, COMMENT_CMD_STRING, env));
	if ((end - (start + 1)) > COMMENT_LENGTH)
		return (err_code(SIZE_ERROR, COMMENT_CMD_STRING, env));
	ft_strncpy(dest, (start + 1), end - (start + 1));
	return (1);
}

int		get_header(t_asm *env)
{
	char	*line;

	if (!(env->header = ft_memalloc(sizeof(t_header))))
		return (err_code(MEM_ERROR, NULL, env));
	env->header->magic = COREWAR_EXEC_MAGIC;
	read_file(env, &line);
	if (!parse_name(env, &line, PROG_NAME))
		return (ft_free_line(&line, 0));
	ft_strdel(&line);
	read_file(env, &line);
	if (!parse_comment(env, &line, COMMENT))
		return (ft_free_line(&line, 0));
	ft_strdel(&line);
	return (1);
}
