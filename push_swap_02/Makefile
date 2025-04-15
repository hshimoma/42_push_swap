#コンパイラ
CC = cc

#コンパイラオプション
CFLAGS = -Wall -Wextra -Werror

#実行ファイル名
NAME = push_swap

#コンパイル対象のソースコード
SRCS = push_swap.c

#オブジェクトファイル名
OBJS = $(SRCS:.c=.o)

#libftの追加
LIBFT = libft/libft.a

$(LIBFT):
	$(MAKE) -C libft

push_swap: push_swap.o
	cc -o push_swap push_swap.o -Llibft -llibft

push_swap.o: push_swap.c
	cc -Wall -Wextra -Werror -c push_swap.c

#'make all'でmake cleanとmakeを同時に実行
all: $(NAME)


#.aファイル作成
# $(NAME): $(OBJS)
# 	ar -r $(NAME) $(OBJS)

#オブジェクトファイル作成
# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS) $(LIBFT)

#中間ファイルを削除
clean:
	rm -f $(OBJS)

#全部消す
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

#fclean,all
re: fclean all

#規則の追加
.PHONY: all clean fclean re

#todo
#makeしてa.outができない、make reがエラーになる