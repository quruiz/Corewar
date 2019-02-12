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

extern t_op	g_op_tab[17];

int		main(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (i < 16)
	{
		j = 0;
		printf("%s\t", g_op_tab[i].name);
		while (j < 3)
		{
			printf("%d", (int)g_op_tab[i].param[j]);
			j++;
		}
		printf("\n");
		i++;
	}

	if (g_op_tab[2].param[0] == (T_REG))
		printf("1\n");
	else
		printf("0\n");
	return (0);
}