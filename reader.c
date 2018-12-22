/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 15:28:18 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/22 18:12:14 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm_struct.h"

int		check_extension(char *file)
{
	char	*dot;
	int		fd;

	dot = ft_strrchr(file, '.');
	if (!dot)
		return (1);
	if (dot[1] == 's' && !dot[2])
		return (0);
	return (1);
}

char	*read_asm(int fd, off_t size)
{
	char	file[size + 1];

	if (size)
	{
		lseek(fd, 0, SEEK_SET);
		read(fd, file, (size_t)size);
		return (ft_strdup(file));
	}
	return (NULL);
}

char	**clean_split(char **split)
{
	char	*tmp;
	int		i;

	i = 0;
	while (split[i])
	{
		tmp = split[i];
		split[i] = ft_strtrim(tmp);
		free(tmp);
		i++;
	}
	return (split);
}

int		read_file(t_asm **env, char **arg)
{
	int		fd;
	char	*file;

	if (check_extension(arg[1]))					// Verifie l'extension *.s
		return (err_code(1, arg[0]));
	fd = open(arg[1], O_RDONLY);
	if (fd == -1)									// Check si le fichier a bien ete ouvert
		return (err_code(2, arg[1]));
	file = read_asm(fd, lseek(fd, 0, SEEK_END));	// Lis le ficher, lseek pour connaitre la taille
	if (!file)										// Verifie si le fichier est vide
		return (err_code(3, arg[1]));
	else
	{
		if (!(*env = ft_memalloc(sizeof(t_asm))))	// malloc de la structure principale
		{
			free(file);
			return (err_code(0, NULL));
		}
	}
	(*env)->raw_file = file;						// stock le fichier lu dans la structure
	(*env)->file = ft_strsplit(file, '\n');
	return (1);
}
