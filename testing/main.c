#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/asm.h"

int		main()
{
	// system("rm test");
	// int		fd = open("test", O_WRONLY | O_CREAT, 0600);

	// intmax_t		p1 = -32;
	// t_header		header;

	// ft_bzero(&header, sizeof(header));
	// header.magic = ft_bswap_int32(COREWAR_EXEC_MAGIC);
	// ft_strncpy(header.prog_name, "42", sizeof(header.prog_name));
	// header.prog_size = ft_bswap_int32(16);
	// ft_strncpy(header.comment, "Just a basic Winner Program", sizeof(header.comment));
	// // unsigned int i = 0x00ea83f3;
	// // int j = (int)i;

	// // unsigned short si = 65263;
	// // short sj = (short)si;

	// // p1 = ft_bswap_int16((short)p1);
	// printf("%lu\n", sizeof(header.prog_name));
	// write(fd, &header, sizeof(t_header));

	int i = 0;
	while (i < 4)
	{
		printf("%d\n", ft_recursive_power(4, i));
		i++;
	}
	// write(fd, "Bonjour", 7);
	// lseek(fd, 121, SEEK_CUR);
	// write(fd, &j, 4);
	// lseek(fd, 5, SEEK_SET);
	// write(fd, "a", 1);
	// sj = swap_int16(sj);
	// write(fd, &sj, 2);

	/* 8 - (PROG_NAME_LENGTH % 8) */

}
