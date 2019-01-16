# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 14:31:00 by tcherret          #+#    #+#              #
#    Updated: 2019/01/16 17:24:18 by tcherret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME0 = push_swap

NAME1 = checker

NAMELIB = ./libft/libftprintf.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

SRCS0 = srcs/push_swap/ft_idiot_sort.c\
		srcs/push_swap/ft_cut_sort.c\
		srcs/push_swap/ft_simple_sort.c\
		srcs/push_swap/ft_quick_sort.c\
		srcs/push_swap/op_push.c\
		srcs/push_swap/op_reverse_rotate.c\
		srcs/push_swap/op_rotate.c\
		srcs/push_swap/op_swap.c\
		srcs/push_swap/push_swap.c

SRCS1 = srcs/checker/checker.c\
		srcs/checker/create_stack_checker.c\
		srcs/checker/do_op.c\
		srcs/checker/do_op_push.c\
		srcs/checker/do_op_reverse_rotate.c\
		srcs/checker/do_op_rotate.c\
		srcs/checker/do_op_swap.c\
		srcs/checker/the_checker.c\

SRCSAUX = srcs/aux/check_arg.c\
		  srcs/aux/check_list.c\
		  srcs/aux/ft_checker.c\
		  srcs/aux/ft_lstdelete.c\
		  srcs/aux/ft_lstsize.c\
		  srcs/aux/ft_printer.c\
		  srcs/aux/get_last_elem.c\
		  srcs/aux/get_med.c\
		  srcs/aux/get_max.c\
		  srcs/aux/get_min.c\
		  srcs/aux/check_inf_med.c\

INCS = push_swap.h

LIBDIR = ./libft/
INCDIR = ./includes/

OBJ0 = $(SRCS0:.c=.o)
OBJ1 = $(SRCS1:.c=.o)
OBJAUX = $(SRCSAUX:.c=.o)

all : $(NAME0) $(NAME1)

$(NAME0) : $(OBJ0) $(OBJAUX)
	@make -C $(LIBDIR)
	@$(CC) $(CFLAGS) -o $(NAME0) $(OBJ0) $(OBJAUX) $(NAMELIB)
	@echo "$(NAME0) compiled ✔ ✔ ✔ ✔"

$(NAME1) : $(OBJ1) $(OBJAUX)
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(OBJAUX) $(NAMELIB)
	@echo "$(NAME1) compiled ✔ ✔ ✔ ✔"

clean :
	@rm -rf $(OBJ0)
	@rm -rf $(OBJ1)
	@rm -rf $(OBJAUX)
	@make -C $(LIBDIR) clean
	@echo "objects deleted ✕"

fclean : clean
	@rm -f $(NAME0)
	@rm -f $(NAME1)
	@make -C $(LIBDIR) fclean
	@echo "$(NAME0) and $(NAME1) deleted ✕"

re : fclean all

.PHONY : all clean fclean re
