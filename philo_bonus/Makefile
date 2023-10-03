NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CHECKER = checker
SRC_FILES = main.c \
			ft_process.c \
			ft_living.c \
			ft_error.c

INCLUDE = philo_bonus.h

CLR_RMV	:= \033[0m
GREEN	:= \033[1;32m
define  ART
$(GREEN)
 +-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+
 |P|h|i|l|o|s|o|p|h|e|r|s| |B|o|n|u|s|
 +-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+            
 $(CLR_RMV)
endef
export  ART

OBJS = $(SRC_FILES:.c=.o)

all: lib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS)  $^

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$$ART"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib