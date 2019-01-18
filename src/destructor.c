/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destructor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 19:25:08 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 15:11:56 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

void    free_all(t_asm *env)
{
	// if (env->code)
	// 	free_code(env);
	if (env->header)
		free(env->header);
	free(env->name);
	free(env);
}
