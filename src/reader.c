/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 15:28:18 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 18:57:55 by quruiz      ###    #+. /#+    ###.fr     */
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

int		check_file(t_asm **env, char **arg)
{
	if (!check_extension(arg[1]))
		return (BAD_FILENAME);
	if (!(*env = ft_memalloc(sizeof(t_asm))))
		return (MEM_ERROR);
	(*env)->name = ft_strsub(arg[1], 0, (ft_strlen(arg[1]) - 1));
	(*env)->name = ft_conncat((*env)->name, "cor", ft_strlen((*env)->name), 3);
	(*env)->input_fd = open(arg[1], O_RDONLY);
	if ((*env)->input_fd == -1)
		return (ERROR_FILE);
	return (SUCCESS);
}
