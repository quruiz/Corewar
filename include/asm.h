/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 17:20:19 by quruiz      ###    #+. /#+    ###.fr     */
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

typedef struct		s_code
{
	int				type;
	int				line_nb;
	char			*token;
	struct s_op		op;
	unsigned char	byte;
	char			**raw_params;
	intmax_t		params[2][4];
	int				size;
	struct s_code	*next;
}					t_code;

typedef struct		s_asm
{
	char			*name;
	int				input_fd;
	int				output_fd;
	int				line_nb;
	t_op			*op_tab;
	t_header		*header;
	t_code			*code;
}					t_asm;

/*
**	Parsing
*/

int					check_file(t_asm **env, char **arg);
int					read_file(t_asm *env, char **line);
int					get_header(t_asm *env);
int					get_cmd(t_asm *env);
char				*get_label(t_asm *env, char *line);
int					get_op(t_asm *env, char *line);

/*
**	Compilation
*/

int					handle_reg(t_asm *env, t_code *code, int i);
int					handle_direct(t_asm *env, t_code *code, int i);
int					handle_indirect(t_asm *env, t_code *code, int i);
int					init_output(t_asm *env);

/*
**	Tools
*/

void				add_to_list(t_asm *env, t_code *n);

/*
**	Errors and Malloc
*/

void				free_all(t_asm *env);
int					err_code(int code, char *token, t_asm *env);

#endif
