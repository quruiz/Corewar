#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		byte_swap_int32(int val)
{
	int tmp;

	tmp = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
	return (tmp << 16) | ((tmp >> 16) & 0xFFFF);
}

short	byte_swap_int16(short val) 
{
	return (val << 8) | ((val >> 8) & 0xFF);
}

int		main()
{
	int		fd = open("test", O_WRONLY);
	unsigned int i = 0xdeadbeef;
	int j = (int)i;
	unsigned short si = 0xfede;
	short sj = (short)si;

//	j = swap_int32(j);
//	write(fd, &j, 4);

	sj = swap_int16(sj);
	write(fd, &sj, 2);
}
