/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:13:28 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 18:48:45 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

// static int	get_comment_header(t_asm *env)
// {
// 	char	*start;
// 	char	*end;
// 	char	*comment;

// 	start = ft_strstr(env->raw_file, COMMENT_CMD_STRING);
// 	if (start)
// 		start = ft_strchr(start, '"');
// 	else
// 		return (0);
// 	if (start)
// 		end = ft_strchr(start + 1, '"');
// 	else
// 		return (0);
// 	if (!end || end[1] != '\n')
// 		return (0);
// 	else
// 	{
// 		comment = ft_strsub(start, 1, end - (start + 1));
// 		if (ft_strlen(comment) > COMMENT_LENGTH)
// 			return (ft_free_line(&comment, 0));
// 		ft_strcpy(env->header->comment, comment);
// 		free(comment);
// 	}
// 	env->file = clean_split(ft_strsplit(ft_strchr(end, '\n'), '\n'));
// 	return (1);
// }

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
		line = ft_conncat(line, tmp, size[0], size[1]);
		if (ft_strchr(tmp, '"'))
			return (line);
		size[0] += size[1];
		size[2] += size[1];
		if (size[2] > len)
			break ;
	}
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
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int		get_header(t_asm *env, char *line)
{
	char	*res;

	if (!(env->header = ft_memalloc(sizeof(t_header))))
		return (err_code(0, env));
	env->header->magic = COREWAR_EXEC_MAGIC;
    if (*line != '.')
        return (err_code(4, env));
	if (!(res = read_header(env, line, NAME_CMD_STRING, PROG_NAME_LENGTH)))
		return (err_code(4, env));
	ft_strcpy(env->header->prog_name, res);
	free(res);

	get_next_line(env->input_fd, &line);
	env->error_line++;						/* need better read */

	if (!(res = read_header(env, line, COMMENT_CMD_STRING, COMMENT_LENGTH)))
		return (err_code(4, env));
	ft_strcpy(env->header->comment, res);
	free(res);
    dprintf(1, "NAME: %s\nCOMMENT: %s\n", env->header->prog_name, env->header->comment);
	return (1);
}