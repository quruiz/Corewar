/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 17:21:02 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/16 19:12:36 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		err_code(int code, char *token, t_asm *env)
{
	if (code == MEM_ERROR)
		printf("Malloc error\n");
	else if (code == BAD_FILENAME)
		printf("Usage: ./asm <file>.s\n");
	else if (code == ERROR_FILE)
		printf("Can't read or create file\n");
	else if (code == EMPTY_FILE)
		printf("Empty source file\n");
	else if (code == SIZE_ERROR)
		printf("%s too long\n", token);
	else if (code == SYNTAX_ERROR)
		printf("Lexical error at line %.3d\n", env->line_nb);
	else if (code == INVALID_PARAM)
		printf("Invalid parameter for %s at line %.3d\n", token, env->line_nb);
	else if (code == NO_TOKEN)
		printf("Can't find token \"%s\" at line %.3d\n", token, env->line_nb);
	else if (code == NEW_LINE)
		printf("File must end with a empty line\n");
	else
		printf("Unknown error\n");
	if (env)
		free_all(env);
	return (0);
}
