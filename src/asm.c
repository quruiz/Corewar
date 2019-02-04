/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:58:11 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 20:21:53 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

int		main(int argc, char *argv[])
{
	t_asm	*env;
	char	*file;

	if (argc != 2)
		return (err_code(ERROR_FILE, NULL, NULL));
	if (check_file(&env, argv) != SUCCESS)
		return (1);
	if (!get_header(env))
		return (1);
	dprintf(1, "NAME: %s\nCOMMENT: %s\n", PROG_NAME, COMMENT);
	free_all(env);
}
