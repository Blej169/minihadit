C_NAME = client
S_NAME = server
CB_NAME = client_bonus
SB_NAME = server_bonus
NAME = placeholder
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER_FILE = src/minitalk.h
PRINTF = printf/libftprintf.a
C_SRC = src/client.c
S_SRC = src/server.c
CB_SRC = src/client_bonus.c
SB_SRC = src/server_bonus.c

.PHONY: all re clean fclean bonus $(NAME) $(NAME_B)

all: $(NAME)

bonus: $(CB_NAME) $(SB_NAME)

$(NAME): client server

$(NAME_B): client_bonus server_bonus

client: $(C_SRC) $(HEADER_FILE)
	@make -C printf
	$(CC) $(CFLAGS) $(C_SRC) printf/libftprintf.a -o client

server: $(S_SRC) $(HEADER_FILE)
	$(CC) $(CFLAGS) $(S_SRC) printf/libftprintf.a -o server

client_bonus: $(CB_SRC) $(HEADER_FILE)
	@make -C printf
	$(CC) $(CFLAGS) $(CB_SRC) printf/libftprintf.a -o client_bonus

server_bonus: $(SB_SRC) $(HEADER_FILE)
	$(CC) $(CFLAGS) $(SB_SRC) printf/libftprintf.a -o server_bonus

clean:
	@make clean -C printf
	rm -f *.o

fclean: clean
	@make fclean -C printf
	rm -f client server
	rm -f client_bonus server_bonus

re: fclean all