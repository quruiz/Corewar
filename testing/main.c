#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/asm.h"

int		main()
{
	system("rm test");
	int		fd = open("test", O_RDWR | O_CREAT);

	intmax_t		p1 = 999999999999;


	// unsigned int i = 0x00ea83f3;
	// int j = (int)i;

	// unsigned short si = 65263;
	// short sj = (short)si;

	p1 = ft_bswap_int16((short)p1);
	write(fd, &p1, 2);
	// write(fd, "Bonjour", 7);
	// lseek(fd, 121, SEEK_CUR);
	// write(fd, &j, 4);
	// lseek(fd, 5, SEEK_SET);
	// write(fd, "a", 1);
	// sj = swap_int16(sj);
	// write(fd, &sj, 2);

	/* 8 - (PROG_NAME_LENGTH % 8) */

}
