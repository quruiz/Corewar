/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:13:28 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 22:16:46 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		read_more(t_asm *env, char **line, char *cmd, int len)
{
	char	*tmp;
	int		size[3];

	size[0] = ft_strlen(*line);
	size[2] = ft_strlen(ft_strchr(*line, '"'));
	while (get_next_line(env->input_fd, &tmp))
	{
		env->line_nb++;
		size[1] = ft_strlen(tmp);
		*line = ft_conncat(*line, "\n", size[0]++, 1);
		*line = ft_conncat(*line, tmp, size[0], size[1]);
		size[0] += size[1];
		size[2] += size[1];
		free(tmp);
		if (size[2] > len)
			break ;
		if (ft_strchr((*line + (size[0] - size[1])), '"'))
			return (1);
	}
	ft_strdel(line);
	return (err_code(SIZE_ERROR, cmd, env));
}

int		parse_name(t_asm *env, char *line, char *dest)
{
	char	*start;
	char	*end;
	char	*str;

	if (!(start = ft_strstr(line, NAME_CMD_STRING)))
		return (err_code(SYNTAX_ERROR, NAME_CMD_STRING, env));
	start += ft_strlen(NAME_CMD_STRING);
	while (!ft_isprint(*start))
		start++;
	if (*start != '"')
		return (err_code(SYNTAX_ERROR, NAME_CMD_STRING, env));
	if (!(end = ft_strchr(start + 1, '"')))
	{
		if (!read_more(env, &line, NAME_CMD_STRING, PROG_NAME_LENGTH))
			return (0);
		return (parse_name(env, line, dest));
	}
	else if (!ft_str_is_empty(end + 1))
		return (err_code(SYNTAX_ERROR, NAME_CMD_STRING, env));
	str = ft_strsub(start, 1, end - (start + 1));
	if (ft_strlen(str) > PROG_NAME_LENGTH)
		err_code(SIZE_ERROR, NAME_CMD_STRING, env);
	else
		ft_strcpy(dest, str);
	free(str);
	free(line);
	return (ft_str_is_empty(dest) ? 0 : 1);
}

int		parse_comment(t_asm *env, char *line, char *dest)
{
	char	*start;
	char	*end;
	char	*str;

	if (!(start = ft_strstr(line, COMMENT_CMD_STRING)))
		return (err_code(SYNTAX_ERROR, COMMENT_CMD_STRING, env));
	start += ft_strlen(COMMENT_CMD_STRING);
	while (!ft_isprint(*start))
		start++;
	if (*start != '"')
		return (err_code(SYNTAX_ERROR, COMMENT_CMD_STRING, env));
	if (!(end = ft_strchr(start + 1, '"')))
	{
		if (!read_more(env, &line, COMMENT_CMD_STRING, COMMENT_LENGTH))
			return (0);
		return (parse_comment(env, line, dest));
	}
	else if (!ft_str_is_empty(end + 1))
		return (err_code(SYNTAX_ERROR, COMMENT_CMD_STRING, env));
	str = ft_strsub(start, 1, end - (start + 1));
	if (ft_strlen(str) > COMMENT_LENGTH)
		err_code(SIZE_ERROR, COMMENT_CMD_STRING, env);
	else
		ft_strcpy(dest, str);
	free(str);
	free(line);
	return (ft_str_is_empty(dest) ? 0 : 1);
}

int		get_header(t_asm *env)
{
	char	*line;

	if (!(env->header = ft_memalloc(sizeof(t_header))))
		return (err_code(MEM_ERROR, NULL, env));
	env->header->magic = COREWAR_EXEC_MAGIC;
	read_file(env, &line);
	if (!parse_name(env, line, PROG_NAME))
		return (0);
	read_file(env, &line);
	if (!parse_comment(env, line, COMMENT))
		return (0);
	dprintf(1, "NAME: %s\nCOMMENT: %s\n", env->header->prog_name, env->header->comment);
	return (1);
}
