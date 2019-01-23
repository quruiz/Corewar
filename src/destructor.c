/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destructor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 19:25:08 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 18:46:44 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

void    free_all(t_asm *env)
{
	if (env->header)
		free(env->header);
	if (env->err)
	{
		free(env->err->token);
		free(env->err);
	}
	free(env->name);
	free(env);
}
