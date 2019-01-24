/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 22:08:43 by quruiz      ###    #+. /#+    ###.fr     */
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
	int				line_nbr;
	void			*info;
	struct s_code	*next;
}					t_code;

typedef struct		s_label
{
	char			*label_name;
	off_t			cursor;
}					t_label;

typedef struct		s_cmd
{
	struct s_op		*op_tab;
	int				done;
	int				size;
	char			**params;
	unsigned char	*code;
}					t_cmd;

int					err_code(int code, char *token, t_asm *env);
void				read_file(t_asm *env, char **line);
int					check_file(t_asm **env, char **arg);
int					get_header(t_asm *env);
void	   			free_all(t_asm *env);

#endif