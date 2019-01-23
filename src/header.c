/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:13:28 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 14:51:07 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

char	*read_more(t_asm *env, char *line, int len)
{
	char	*tmp;
	int		size[3];

	size[0] = ft_strlen(line);
	size[2] = ft_strlen(ft_strchr(line, '"'));
	while (get_next_line(env->input_fd, &tmp))
	{
		env->error_line++;
		size[1] = ft_strlen(tmp);
		line = ft_conncat(line, "\n", size[0]++, 1);
		line = ft_conncat(line, tmp, size[0], size[1]);
		size[0] += size[1];
		size[2] += size[1];
		free(tmp);
		if (size[2] > len)
			break ;
		if (ft_strchr((line + (size[0] - size[1])), '"'))
			return (line);
	}
	free(line);
	return (NULL);
}

char	*read_header(t_asm *env, char *line, char *cmd, int len)
{
	char	*start;
	char	*end;
	char	*str;

	if (!(start = ft_strstr(line, cmd)))
		return (NULL);
	if (!(start = ft_strchr(start, '"')))
		return (NULL);
	if (!(end = ft_strchr(start + 1, '"')))
	{
		if (!(line = read_more(env, line, len)))
			return (NULL);
		return (read_header(env, line, cmd, len));
	}
	else if (end[1] != '\0')
		return (NULL);
	str = ft_strsub(start, 1, end - (start + 1));
	if (ft_strlen(str) > len)
		ft_strdel(&str);
	free(line);
	return (str);
}

int		get_header(t_asm *env, char *line)
{
	char	*res;

	if (!(env->header = ft_memalloc(sizeof(t_header))))
		return (err_code(0, env));
	env->header->magic = COREWAR_EXEC_MAGIC;
	//
	if (*line != '.')
		return (err_code(4, env));
	//
	if (!(res = read_header(env, line, NAME_CMD_STRING, PROG_NAME_LENGTH)))
		return (err_code(4, env));
	ft_strcpy(env->header->prog_name, res);
	free(res);
	//
	while (get_next_line(env->input_fd, &line))
	{
		env->error_line++;
		if (!(ft_str_is_empty(line) || *line == COMMENT_CHAR))
			break ;
		free(line);
	}
	//
	if (!(res = read_header(env, line, COMMENT_CMD_STRING, COMMENT_LENGTH)))
		return (err_code(4, env));
	ft_strcpy(env->header->comment, res);
	free(res);
	//
	dprintf(1, "NAME: %s\nCOMMENT: %s\n", env->header->prog_name, env->header->comment);
	//
	return (1);
}
