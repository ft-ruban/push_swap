# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/03/10 09:05:47 by ldevoude         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#####################################################
##				 								   ##					
##                    VARIABLES                    ##
##												   ##
#####################################################

#####################################################
#				 PROGRAM + AUTHOR					#
#####################################################
AUTHOR 		   =   ldevoude
NAME		   =   push_swap
#####################################################
#					COMPILING						#
#####################################################
CC             =   cc
#####################################################
#					FLAGS							#
#####################################################
CFLAGS         =   -Wall -Wextra -Werror -g3 -g -O3 #dl -g before push
#####################################################
#					ARCHIVES						#
#####################################################
AR 			=   ar rcs
LIBLIBFTX 	=   $(DIR_LIBFTX)/libftx.a

#####################################################
#					DIRECTORY						#
#####################################################
DIR_PUSH_SWAP  =   .
DIR_PRINTF     =   ./libftx/printf
DIR_GNL        =   ./libftx/get_next_line
DIR_LIBFTX     =   ./libftx
OBJ_DIR        =   obj_push_swap


#####################################################
#					HEADER  						#
#####################################################
HEADER_PUSH_SWAP =   $(DIR_PUSH_SWAP)/push_swap.h					
HEADER_PRINTF  =   $(DIR_PRINTF)/printf.h
HEADER_GNL 	   =   $(DIR_GNL)/get_next_line.h
HEADER_LIBFTX  =   $(DIR_LIBFTX)/libft.h

#####################################################
#					 MISC     						#
#####################################################
LIGHTPURPLE    =   \033[1;35m
GREEN		   =   \033[1;32m
RED            =   \033[1;31m

#####################################################
#					VARIABLES SOURCES				#
#####################################################
PUSH_SWAP_SRC    =   $(addsuffix .c, \
						main \
						algorithm \
						error \
						moves_between_arrays \
						moves_push \
						swap_functions \
						utils)

LIBFTX_SRC     =   $(addsuffix .c, \
						ft_argv_to_int_array\
						ft_atoi \
						ft_atop \
						ft_bzero \
						ft_calloc \
						ft_isalnum \
						ft_isalpha \
						ft_isascii \
						ft_isdigit \
						ft_isintsized \
						ft_isprint \
						ft_itoa \
						ft_itoa_hexx\
						ft_memchr \
						ft_memcmp	\
						ft_memcpy	\
						ft_memmove \
						ft_memset \
						ft_putchar_fd \
						ft_putnbr_fd \
						ft_putendl_fd \
						ft_putstr_fd \
						ft_split \
						ft_strchr \
						ft_strcmp \
						ft_strdup \
						ft_striteri \
						ft_strjoin \
						ft_strlcat \
						ft_strlcpy \
						ft_strlen \
						ft_strmapi \
						ft_strncmp \
						ft_strnstr \
						ft_strrchr \
						ft_strtoupper \
						ft_strtrim \
						ft_substr \
						ft_tolower \
						ft_toupper \
						ft_utoa)

GNL_SRC        =   $(addsuffix .c, \
						get_next_line)
					
PRINTF_SRC 	   =   $(addsuffix .c, \
						ft_printf_cases \
						ft_printf\
						ft_printfd_cases\
						ft_printfd)
#####################################################
#					VARIABLES_OBJ				    #
#####################################################

PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR)/, $(PUSH_SWAP_SRC:.c=.o))
LIBFTX_OBJ    = $(addprefix $(OBJ_DIR)/, $(LIBFTX_SRC:.c=.o))
GNL_OBJ       = $(addprefix $(OBJ_DIR)/, $(GNL_SRC:.c=.o))
PRINTF_OBJ    = $(addprefix $(OBJ_DIR)/, $(PRINTF_SRC:.c=.o))

DEPENDANCY_FILES =   $(PUSH_SWAP_OBJ:.o=.d) #to create dep

#####################################################
#					TARGETS						#
#####################################################

all             :    $(NAME)

clean           :	
								@rm -rf $(OBJ_DIR) $(PUSH_SWAP_OBJ) $(LIBFTX_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
								@rm -f $(DIR_GNL)*.d 
								@rm -f $(DIR_PRINTF)*.d
								@echo "$(GREEN)Cleaning of .o and .d files completed successfully! ／人◕ ‿‿ ◕人＼"
fclean          :    clean
								@rm -f $(NAME)
								@echo "$(GREEN)Deleting $(NAME) completed successfully! ／人◕ ‿‿ ◕人＼ "
								@echo "$(RED)"
								@echo "┌──────────────────────────────────────────────────────────┐"
								@echo "│      Deletion finished successfully! ( ◔ ω ◔) ノシ         │"
								@echo "└──────────────────────────────────────────────────────────┘"
								
								@echo "                           ╱|、"
								@echo "                         (˚ˎ 。7"
								@echo "                          |、˜|"
								@echo "                         じしˍ,)ノ"
								@echo "$(RESET)"

	
debug           :   
					@echo "Current directory: $(shell pwd)"
					@echo "Checking push_swap files\:"
					@ls -l $(DIR_PUSH_SWAP)
					@echo "Checking libftx files\:"
					@ls -l $(DIR_LIBFTX)
					@echo "Checking gnl files\:"
					@ls -l $(DIR_GNL)
					@echo "Checking printf files\:"
					@ls -l $(DIR_PRINTF)
					@echo $(shell -e) "${LIGHTPURPLE}I never thought I'd see a Resonance Cascade, let alone create one!"

re               :	fclean all	

#####################################################
#					COMMANDS						#
#####################################################

$(NAME): $(OBJ_DIR) $(PUSH_SWAP_OBJ) $(LIBFTX_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
		 $(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJ) $(LIBFTX_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
		@echo "$(GREEN) $(NAME) is now ready to run ／人◕ ‿‿ ◕人＼ "

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	   : $(DIR_PUSH_SWAP)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_PUSH_SWAP) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_LIBFTX)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_LIBFTX) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_GNL)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_GNL) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_PRINTF)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_PRINTF) -o $@ -c $<

$(DIR_PUSH_SWAP)/%.o  :      $(DIR_PUSH_SWAP)/%.c $(HEADER_PUSH_SWAP)
											$(CC) $(CFLAGS) -c $< -o $@

$(DIR_LIBFTX)/%.o   :      $(DIR_LIBFTX)/%.c  $(HEADER_PUSH_SWAP)
											$(CC) $(CFLAGS) -c $< -o $@

$(DIR_GNL)/%.o 		:	   $(DIR_GNL)/%.c  	  $(HEADER_GNL)
											$(CC) $(CFLAGS) -c $< -o $@

$(DIR_PRINTF)/%.o   :      $(DIR_PRINTF)/%.c  $(HEADER_PRINTF)
											$(CC) $(CFLAGS) -c $< -o $@

											
$(OBJ_DIR)          :		
							mkdir -p $(OBJ_DIR)

-include $(DEPENDANCY_FILES)

.PHONY :   					all bonus clean fclean re
