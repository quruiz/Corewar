/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 16:01:20 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "error.h"
# include "../libft/libft/libft.h"

# define PROG_NAME	env->header->prog_name
# define COMMENT	env->header->comment

typedef struct		s_asm
{
	char			*name;
	int				input_fd;
	int				output_fd;
	int				line_nb;
	struct s_header	*header;
	struct s_code	*code;
}					t_asm;

typedef struct		s_code
{
	int				type;
	int				line_nb;
	char			*token;
	off_t			cursor;
	char			**params;
	unsigned char	*code;
	struct s_code	*next;
}					t_code;

int					err_code(int code, char *token, t_asm *env);
int					read_file(t_asm *env, char **line);
int					check_file(t_asm **env, char **arg);
int					get_header(t_asm *env);
void	   			free_all(t_asm *env);

#endif