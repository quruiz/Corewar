/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:13:28 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 18:19:42 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

static int	get_name_header(t_asm *env)
{
	char	*start;
	char	*end;
	char	*name;

	start = ft_strstr(env->raw_file, NAME_CMD_STRING);
	if (start)
		start = ft_strchr(start, '"');
	else
		return (0);
	if (start)
		end = ft_strchr(start + 1, '"');
	else
		return (0);
	if (!end)
		return (0);
	else
	{
		name = ft_strsub(start, 1, end - (start + 1));
		if (ft_strlen(name) > PROG_NAME_LENGTH)
			return (0/* erreur */);
		ft_strcat(env->header->prog_name, name);
		free(name);
	}
	return (1);
}

static int	get_comment_header(t_asm *env)
{
	char	*start;
	char	*end;
	char	*comment;

	start = ft_strstr(env->raw_file, COMMENT_CMD_STRING);
	if (start)
		start = ft_strchr(start, '"');
	else
		return (0);
	if (start)
		end = ft_strchr(start + 1, '"');
	else
		return (0);
	if (!end)
		return (0);
	else
	{
		comment = ft_strsub(start, 1, end - (start + 1));
		if (ft_strlen(comment) > COMMENT_LENGTH)
			return (0/* erreur */);
		ft_strcat(env->header->comment, comment);
		free(comment);
	}
	return (1);
}

int		get_header(t_asm *env)
{
	if (!(env->header = ft_memalloc(sizeof(t_header))))
		return (err_code(0, NULL));
	env->header->magic = COREWAR_EXEC_MAGIC;
	
	/* TEST */
	if (!get_name_header(env))
	{
		printf("name a pete\n");
		return (0);
	}
	if (!get_comment_header(env))
	{
		printf("comment a pete\n");
		return (0);
	}
	/* TEST */

	return (1);
}