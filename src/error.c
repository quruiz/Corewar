/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 17:21:02 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 18:57:44 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"
#include "../include/error.h"

int		err_code(t_asm *env)
{
	if (TICKET->code == MEM_ERROR)
		printf("Malloc error\n");
	if (TICKET->code == BAD_FILENAME)
		printf("Usage: ./asm <file>.s\n");
	if (TICKET->code == ERROR_FILE)
		printf("Can't read source file\n");
	if (TICKET->code == EMPTY_FILE)
		printf("Empty source file\n");

	if (TICKET->code == SIZE_ERROR)
		printf("%s too long", TOKEN);
	if (TICKET->code == SYNTAX_ERROR)
		printf("Error at [%3.d:%3.d] \"%s\"", LINE, COL, TOKEN);
	if (TICKET->code == INVALID_PARAM)
		printf("Invalid parameter for %s [%3.d:%3.d]", TOKEN, LINE, COL);
	if (TICKET->code == NO_LABEL)
		printf("No such label [%3.d:%3.d] \"%s\"", LINE, COL, TOKEN);
	if (env)
		free_all(env);
	return (0);
}