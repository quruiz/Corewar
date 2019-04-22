/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 17:21:02 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 16:51:13 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		err_code(int code, char *tkn, t_asm *env)
{
	if (code == MEM_ERROR)
		ft_dprintf(2, "Malloc error\n");
	else if (code == BAD_FILENAME)
		ft_dprintf(2, "Usage: ./asm <file>.s\n");
	else if (code == ERROR_FILE)
		ft_dprintf(2, "Can't read or create file\n");
	else if (code == SIZE_ERROR)
		ft_dprintf(2, "%s too long\n", tkn);
	else if (code == SYNTAX_ERROR)
		ft_dprintf(2, "Syntax error at line %.3d\n", LNB);
	else if (code == INVALID_OP)
		ft_dprintf(2, "Invalid instruction at line %.3d\n", LNB);
	else if (code == INVALID_PARAM)
		ft_dprintf(2, "Invalid parameter for %s at line %.3d\n", tkn, LNB);
	else if (code == NO_TOKEN)
		ft_dprintf(2, "Can't find token \"%s\" at line %.3d\n", tkn, LNB);
	else if (code == LEXICAL_ERROR)
		ft_dprintf(2, "Lexical error at line %.3d\n", LNB);
	else if (code == NEW_LINE)
		ft_dprintf(2, "File must end with a empty line\n");
	if (env)
		free_all(env);
	return (0);
}
