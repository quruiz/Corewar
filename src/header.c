/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:13:28 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:16:58 by quruiz      ###    #+. /#+    ###.fr     */
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

int		get_header(t_asm *env, char *line)
{
	if (!(env->header = ft_memalloc(sizeof(t_header))))
		return (err_code(0, env));
	env->header->magic = COREWAR_EXEC_MAGIC;
    printf("bite: %s -> %zu\n", line, ft_strlen(line));
    if (*line != '.')
        return (err_code(4, env));
    /* lis tout le reste du header */
	return (1);
}