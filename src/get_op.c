/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_op.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 20:59:46 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 20:02:25 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op	g_op_tab[17];

t_code		*create_struct_op(t_asm *env, char **p, short byte, int op)
{
	t_code	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_code))))
		return (err_code(MEM_ERROR, NULL, env) ? 0 : NULL);
	tmp->type = 2;
	tmp->line_nb = env->line_nb;
	tmp->token = ft_strdup(g_op_tab[op].name);
	tmp->params = p;
	tmp->byte = byte;
	// tmp->size = size;
	tmp->next = NULL;
	return (tmp);
}

t_code		*detect_param(t_asm *env, char **param, int op)
{
	int		i;
	short	val;
	short	byte;
	// int		size;
	

	i = 0;
	val = 64;
	// size = (g_op_tab[op].byte_param) + 1;
	while (i < g_op_tab[op].nb_param)
	{
		if (param[i][0] == 'r' && (g_op_tab[op].param[i] & T_REG))
			byte += byte + val;
			// size += 1;
		else if (param[i][0] == DIRECT_CHAR && (g_op_tab[op].param[i] & T_DIR))
			byte += byte + (val * 3);
			// size += (g_op_tab[op].dir_size ? 2 : 4);
		else if ((ft_isdigit(param[i][0]) || param[i][0] == LABEL_CHAR) &&
			(g_op_tab[op].param[i] & T_IND))
			byte += byte + (val * 2);
			// size += 2;
		else
		{
			ft_freesplit(param);
			return (err_code(INVALID_PARAM, g_op_tab[op].name, env) ? 0 : NULL);
		}
		val *= 4;
		i++;
	}
	return (create_struct_op(env, param, byte, op));
}

int			parse_op(t_asm *env, char *line, int cursor, int op_code)
{
	char	**param;
	t_code	*code;
	int		i;
	int		size;

	i = 0;
	while (!isprint(line[cursor]))
		cursor++;
	param = ft_strsplit_trim(line + cursor, SEPARATOR_CHAR);
	while (i < g_op_tab[op_code].nb_param)
	{
		if (param[i] && !ft_str_is_empty(param[i]))
			i++;
		else
		{
			ft_freesplit(param);
			return (err_code(INVALID_PARAM, g_op_tab[op_code].name, env));
		}
	}
	if (!(code = detect_param(env, param, op_code)))
		return (0);
	add_to_list(env, code);
	return (1);
}

int			get_op(t_asm *env, char *line)
{
	int cursor;
	int op;

	cursor = 0;
	op = 0;
	while (isalpha(line[cursor]))
		cursor++;
	while (op < 16)
	{
		if (ft_strnequ(line, g_op_tab[op].name, cursor))
			break ;
		op++;
	}
	if (op == 16)
		return (err_code(SYNTAX_ERROR, NULL, env));
	if (!parse_op(env, line, cursor, op))
		return (ft_free_line(&line, 0));
	return (ft_free_line(&line, 1));
}
