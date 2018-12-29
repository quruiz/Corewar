#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../libft/libft/libft.h"

int		swap_int32(int val)
{
	int tmp;

	tmp = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
	return (tmp << 16) | ((tmp >> 16) & 0xFFFF);
}

short	swap_int16(short val) 
{
	return (val << 8) | ((val >> 8) & 0xFF);
}

int		main()
{
	system("rm test");
	system("touch test");
	int		fd = open("test", O_WRONLY);

	unsigned char	str[] = {0x06, 0x64, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01};
	write(fd, str, 8);
	// unsigned int i = 0x00ea83f3;
	// int j = (int)i;

	// unsigned short si = 65263;
	// short sj = (short)si;

	// j = swap_int32(j);
	// write(fd, &j, 4);
	// write(fd, "Bonjour", 7);
	// lseek(fd, 121, SEEK_CUR);
	// write(fd, &j, 4);
	// lseek(fd, 5, SEEK_SET);
	// write(fd, "a", 1);
	// sj = swap_int16(sj);
	// write(fd, &sj, 2);

	/* 8 - (PROG_NAME_LENGTH % 8) */

}
