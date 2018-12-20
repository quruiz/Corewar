/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 17:59:26 by quruiz      ###    #+. /#+    ###.fr     */
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
	if (code == 0)
		printf("Error malloc\n");
	if (code == 1)
		printf("Usage: %s <file>.s\n", msg);
	if (code == 2)
		printf("Can't read source file %s\n", msg);
	if (code == 3)
		printf("Empty source file %s\n", msg);
	return (0);
}



int		main(int argc, char *argv[])
{
	t_asm	*env;
	char	*file;

	if (argc != 2)
		return (err_code(1, argv[0]));
	if (!read_file(&env, argv))
		return (1);
	/*
	**	Parsing
	*/
	printf("%s", env->raw_file);
}