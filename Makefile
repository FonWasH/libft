
INC_DIR		= ./includes/
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
SRCS		= $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS		= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRCS:.c=.o))

CC			= cc
CFLAGS		= -O3 -Wall -Wextra -Werror -MMD -MP
IFLAGS		= -I. -I$(INC_DIR)
AR			= ar rc
ID			= ranlib
RM			= rm -rf

NAME		= libft.a


all:			$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@ $(IFLAGS)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)
				$(ID) $(NAME)

clean: 
				$(RM) $(OBJ_DIR) $(NAME)

re:				fclean all

-include 		$(OBJS:.o=.d)
.PHONY:			all clean re
