#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/asm.h"

// int		main()
// {
// 	int		fd = open("42.cor", O_RDONLY);

// 	unsigned char	buf[1];
// 	char			*str;	
// 	while (read(fd, buf, 1))
// 	{
// 		printf("%x", buf[0]);
// 	}
// 	// unsigned int i = 0x00ea83f3;
// 	// int j = (int)i;

// 	// unsigned short si = 65263;
// 	// short sj = (short)si;

// 	// j = swap_int32(j);
// 	// write(fd, &j, 4);
// 	// write(fd, "Bonjour", 7);
// 	// lseek(fd, 121, SEEK_CUR);
// 	// write(fd, &j, 4);
// 	// lseek(fd, 5, SEEK_SET);
// 	// write(fd, "a", 1);
// 	// sj = swap_int16(sj);
// 	// write(fd, &sj, 2);

// 	/* 8 - (PROG_NAME_LENGTH % 8) */

// }

int		main(int ac, char **av)
{
	char	*line;
	int		fd = open(av[1], O_RDONLY);
	int		ret;

	while ((ret = get_next_line(fd, &line)))
		printf("RET = %d ----> %s\n", ret, line);
	return (0);
}