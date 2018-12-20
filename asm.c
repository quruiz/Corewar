/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 12:43:48 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "asm_struct.h"

int		err_code(int code, char *msg)
{
	if (code == 1)
		printf("Usage: %s <file>.s\n", msg);
	if (code == 2)
		printf("Can't read source file %s\n", msg);
	if (code == 3)
		printf("Empty source file %s\n", msg);
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

int		main(int argc, char *argv[])
{
	int fd;
	char *file;

	if (argc != 2 /* || Check extension */)
		return (err_code(1, argv[0]));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (err_code(2, argv[1]));
	file = read_asm(fd, lseek(fd, 0, SEEK_END));
	if (file)
		printf("%s", file);
	else
		return(err_code(3, argv[1]));
    return (0);
}