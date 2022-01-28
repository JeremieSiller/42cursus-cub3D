CC = gcc
CFLAGS = -Wall -Werror -Wextra -L $(LIB_PATH) -lft  -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

NAME = cub3D
LIB_PATH = ./libft
MLX_PATH = ./mlx
LIBFT_NAME = ./libft/libft.a
MLX = ./mlx/libmlx.a
		
SOURCES =	main.c																\
			imgs/imgs.c imgs/resize.c imgs/rotate.c imgs/interpolate.c			\
			window.c															\
			validate/validate.c													\
			validate/validate_utils.c											\
			validate/validate_infoblock.c										\
			validate/validate_infoblock_utils.c									\
			validate/map_handler.c												\
			validate/map_legit.c												\
			hooks/hooks.c														\
			render/render.c														\
			render/render_utils.c												\
			render/math.c														\
			render/draw.c														\
			render/main_screen.c												\
			render/render_utils_utils.c											\
			render/color.c														\
			sprite/sprite.c														\
			map/map.c															\
			main_utils.c
#COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	@$(CC) -Wall -Werror -Wextra -o $@ -c $<

all: $(NAME)
	@printf $(G)"                                               \n";
	@printf $(G)" ,-----.,--. ,--.,-----.  ,----. ,------.      \n";
	@echo $(G)"'  .--./|  | |  ||  |) /_ '.-.  ||  .-.  \     ";
	@echo $(G)"|  |    |  | |  ||  .-.  \  .' < |  |  \  :    ";
	@echo $(G)"'  '--'\'  '-'  '|  '--' //'-'  ||  '--'  /    ";
	@echo $(G)" \`-----' \`-----' \`------' \`----' \`-------'";
	@echo $(B)"                       by @nschumac & @jsiller ";

$(NAME): $(OBJECTS) $(MLX) $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@


$(MLX):
	@echo $(Y)Compiling $(B)minilibx $(Y)...
	@make -C $(MLX_PATH)
	@echo $(G)mlx compiled
	@sleep 0.2

$(LIBFT_NAME):
	@echo $(Y)Compiling $(B)libft $(Y)...
	@make -C $(LIB_PATH)
	@echo $(G)libft compiled
	@sleep 0.2

clean:
	@echo $(Y)removing object-files...
	@sleep 0.3
	@rm -f $(OBJECTS)
	@echo $(Y)cleaning libft...
	@sleep 0.3
	@make clean -C $(LIB_PATH)
	@echo $(G)done removing object-fies


fclean:
	@echo $(Y)cleaning all binary files
	@sleep 0.2
	@make clean
	@sleep 0.2
	@echo $(Y)removing executable
	@rm -f $(NAME)
	@sleep 0.2
	@echo $(G)executable removed
	@echo $(Y)cleaning libft
	@make fclean -C $(LIB_PATH)
	@sleep 0.2
	@echo $(G)libft cleaned
	@sleep 0.2
	@echo $(Y)cleaning mlx
	@make clean -C $(MLX_PATH)
	@sleep 0.2
	@echo $(G)fclean done

git:
	git add .
	git commit -m "$(msg)"
	git push
	git push GitHub

re: fclean all

val:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; gcc -o main main.c validate/*.c libft/*/*.c && valgrind --leak-check=full ./main x.cub; rm -f main"
