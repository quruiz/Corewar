# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/07 17:49:02 by quruiz       #+#   ##    ##    #+#        #
#    Updated: 2019/04/04 12:02:51 by gzanarel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = GOD

ASM = 		./asm/
COREWAR = 	./vm/

all: $(NAME)

$(NAME):
		@make -C $(ASM)
		@make -C $(COREWAR)

clean:
	@make clean -C $(ASM)
	@make clean -C $(COREWAR)

fclean: clean
	@make fclean -C $(ASM)
	@make fclean -C $(COREWAR)

re: fclean all

# Regle ASM
asm_c: 
	@make -C $(ASM)

a_clean:
	@make clean -C $(ASM)
			

a_fclean: a_clean
	@make fclean -C $(ASM)

# Regle VM
vm_c: 
	@make -C $(COREWAR)

v_clean:
	@make clean -C $(COREWAR)

v_fclean: v_clean
	@make fclean -C $(COREWAR)
