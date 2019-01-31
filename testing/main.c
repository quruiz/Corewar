#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strcat(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j])
	{
		str1[i] = str2[j];
		j++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_union(char **av)
{
	int		i;
	int		j;
	char	tab[ft_strlen(av[1]) + ft_strlen(av[2])];

	i = 0;
	j = 0;
	tab[0] = '\0';
	ft_strcat(tab, av[1]);
	ft_strcat(tab, av[2]);
	while (tab[j] != '\0' && tab[i] != '\0')
	{
		if (tab[i] == tab[j] && i != j)
		{
			i = 0;
			j++;
		}
		else if (tab[i] == tab[j] && i == j)
		{
			ft_putchar(tab[j]);
			i = 0;
			j++;
		}
		else
			i++;
	}
}

int		main(int ac, char **av)
{
	if ((ac == 3) && (av[1] != '\0' && av[2] != '\0'))
		ft_union(av);
	ft_putchar('\n');
	return (0);
}