#コンパイラ
CC = cc

#コンパイラオプション
CFLAGS = -Wall -Wextra -Werror

#実行ファイル名
NAME = push_swap

#コンパイル対象のソースコード
SRCS = push_swap.c libft_second.c libft.c min_sort.c operation_function.c push_swap_utils.c validation.c

#オブジェクトファイル名
OBJS = $(SRCS:.c=.o)

#'make all'でmake cleanとmakeを同時に実行
all: $(NAME)

# オブジェクトファイル作成
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

#中間ファイルを削除
clean:
	rm -f $(OBJS)

#全部消す
fclean: clean
	rm -f $(NAME)

#fclean,all
re: fclean all

#規則の追加
.PHONY: all clean fclean re

