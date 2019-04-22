/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:37:01 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 19:46:13 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/corewar.h"

void		del_list(t_list2 *l)
{
	t_node *current;
	t_node *next;

	current = l->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	l->head = NULL;
	l->tail = NULL;
	free(l);
}

void		free_vm(t_vm **vm)
{
	int i;

	if (!vm || !(*vm))
		return ;
	(*vm)->area ? free((*vm)->area) : 0;
	i = -1;
	while (++i < (*vm)->nb_player)
		free((*vm)->player[i]);
	free(*vm);
	*vm = NULL;
}

void		free_cor(t_cor **c)
{
	int i;

	if (!c || !(*c))
		return ;
	i = -1;
	while (++i < (*c)->vm->nb_player)
	{
		if ((*c)->chmp[i])
		{
			(*c)->chmp[i]->name ? free((*c)->chmp[i]->name) : 0;
			(*c)->chmp[i]->comment ? free((*c)->chmp[i]->comment) : 0;
			(*c)->chmp[i]->infos ? free((*c)->chmp[i]->infos) : 0;
			(*c)->chmp[i] ? free((*c)->chmp[i]) : 0;
		}
	}
	free_vm(&(*c)->vm);
	del_list((*c)->proc);
	free(*c);
	*c = NULL;
}

static void	ft_exit_next(int error, char *s)
{
	if (error == 4)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(
		" has a code size that differ from what its header says\n", 2);
	}
	if (error == 5)
		ft_putstr_fd(
		"Error: Flag -d doit etre suivi d'une valeur positive\n", 2);
	if (error == 6)
		ft_putstr_fd("Too many champions\n", 2);
	if (error == 7)
	{
		ft_putstr_fd("Can't read source file ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("\n", 2);
	}
	if (error == 8)
		ft_putstr_fd("Error malloc\n", 2);
	if (error == 9)
		ft_putstr_fd("Error: File chmps is too small to be a champion\n", 2);
}

void		ft_exit(t_logs *logs, int error, char *s, t_cor *c)
{
	dump_logs(logs);
	if (error == 0)
		ft_putstr_fd(
		"Usage: ./corewar [-d N -v | -n N] <champion1.cor> <...>\n", 2);
	if (error == 1)
		ft_putstr_fd("Error parsing !\n", 2);
	if (error == 2)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(" has an invalid header\n", 2);
	}
	if (error == 3)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(" has too large a code (> 682 bytes)\n", 2);
	}
	ft_exit_next(error, s);
	free_cor(&c);
	exit(1);
}
