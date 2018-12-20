/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm_struct.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 17:46:31 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_STRUCT_H
# define ASM_STRUCT_H

# include "op.h"
# include "libft/libft/libft.h"

enum				e_type
{
	OPCODE,
	LABEL,
	COMMENT
};

typedef struct		s_asm
{
	char			*raw_file;
	char			**file;
	int				input_fd;
	int				output_fd;
	struct s_code	*code;
}					t_asm;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_code
{
	enum e_type		type;
	short			size;
	int				num_line;
	char			*raw_line;
	off_t			cursor;
	struct s_code	*next;
}					t_code;

int					err_code(int code, char *msg);
int					read_file(t_asm **env, char **arg);

#endif