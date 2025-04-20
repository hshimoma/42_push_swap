# 1.コンパイラ
CC = cc

# 2.コンパイルオプション
CFLAGS = -Wall -Wextra -Werror

# 3.実行ファイル名 
NAME = libft.a

# 4.コンパイル対象のソースコード
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

#bonusのソースコード
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

# 5.オブジェクトファイル名
OBJS = $(SRCS:.c=.o)

#bonusのオブジェクトファイル名
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#ボーナスが呼ばれない時はOBJSのみ呼ばれた時はボーナルも含む
MAKE_OBJS = $(OBJS)
ifdef BONUS_FLG
MAKE_OBJS += $(OBJS_BONUS)
endif

# 11."make all"で make cleanと makeを同時に実施
all:	$(NAME)

# 9..aファイルを作成
$(NAME): $(MAKE_OBJS)
	ar -r $(NAME) $(MAKE_OBJS)

# 10.オブジェクトファイル生成
$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

# 12. 中間ファイル（.oファイル、.dファイルを削除）
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

#全部を消す　（.oファイル、.dファイル、.aファイル）
fclean: clean
	rm -f $(NAME)

#fclean,all
re: fclean all

#ボーナスも追加
bonus:
	make BONUS_FLG=1

#リナックスコマンドと被ってもこちらを優先するための規則を追加
.PHONY: all clean fclean re bonus
