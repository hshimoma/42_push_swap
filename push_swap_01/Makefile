#コンパイラ
CC = cc

#コンパイラオプション
CFLAGS = -Wall -Wextra -Werror

#実行ファイル名
NAME = push_swap.a

#コンパイル対象のソースコード
SRCS = pa_pb.c ra_rb_rr.c sa_sb_ss.c #rra_rrb_rrr.c 

#オブジェクトファイル名
OBJS = $(SRCS:.c=.o)

#'make all'でmake cleanとmakeを同時に実行
all: $(NAME)

#.aファイル作成
$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

#オブジェクトファイル作成
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

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

#todo 動かない