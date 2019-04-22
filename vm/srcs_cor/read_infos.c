/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_infos.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:32:47 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 12:30:48 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/corewar.h"

/*
** Convertie le Big Endian - Little Endian
*/

int			little_endian(int value)
{
	return ((value & 0x000000FF) << 24 | (value & 0x0000FF00) << 8 |
	(value & 0xFF000000) >> 24 | (value & 0x00FF0000) >> 8);
}

static int	read_infos_next(int fd, t_cor *c, int i, t_header *h)
{
	c->chmp[i]->magic = little_endian(h->magic);
	c->chmp[i]->name = ft_strdup(h->prog_name);
	c->chmp[i]->comment = ft_strdup(h->comment);
	if ((c->chmp[i]->champ_size = little_endian(h->prog_size)) > 682)
		return (3);
	c->chmp[i]->infos = ft_strnew(c->chmp[i]->champ_size);
	read(fd, c->chmp[i]->infos, c->chmp[i]->champ_size);
	if (lseek(fd, 0, SEEK_END) > 2874)
		return (4);
	return (0);
}

void		read_infos(t_cor *c)
{
	t_header	*h;
	int			fd;
	int			i;
	int			error;

	i = -1;
	while (++i < c->vm->nb_player)
	{
		if (!(h = (t_header *)malloc(sizeof(t_header))))
			ft_exit(&(c->vm->logs), 8, c->chmp[i]->name, c);
		fd = open(c->vm->player[i], O_RDONLY);
		if (read(fd, h, sizeof(t_header)) <= 0)
			error = 9;
		else
			error = read_infos_next(fd, c, i, h);
		close(fd);
		free(h);
		if (error > 0)
			ft_exit(&(c->vm->logs), error, c->chmp[i]->name, c);
	}
}
