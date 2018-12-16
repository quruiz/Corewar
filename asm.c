/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 20:12:43 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		err_code(int code)
{
	if (code == 1)
		printf("Usage: ./asm <file>.s\n");
	return (1);
}

int		main(int argc, char const *argv[])
{
	int fd;
	off_t size;

	if (argc != 2)
		return (err_code(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (err_code(1));
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	char file[size];
	read(fd, file, (size_t)size);
	printf("%s", file);
    return (0);
}