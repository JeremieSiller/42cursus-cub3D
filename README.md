# cub3d

## Table of contents

1. [About](#about)
2. [Description](#description)
3. [Credits](#credits)
4. [minilibX](#minilibx)
5. [libft](#libft)


## About
so_long is a project at 42 with the goal to create a really simple game. It is about learning how to use windows, events, colours and more.
The school provides a small library to use which only contains some really basic functions. 

**how to use:**

Clone the repository:
```bash
git clone --recursive https://github.com/JeremieSiller/so_long/
```
run make to compile the programm 
```bash
make
```
execute the programm with a .ber file
```bash
./so_long map.ber
```
to start the game the map file needs to follow some rules else it will just return an error. (For more information look into [Description](#description))


## Description
**how to play:**
- use W A S D to move
- collect all coins before going to the spaceship
- if you try to fly away with the spaceship without collecting all coins you loose
- press ESC or click the red cross to exit the window and the program

**a valid map...**
- is sorrounded by walls (1)
- contains at least one exit (E)
- contains at least one coin (C)
- contains exactly one player (P)


## Credits

**links to the used xpm files:**
- exit.xpm : https://opengameart.org/content/64-x-64-animated-plane
- background.xpm : https://opengameart.org/content/all-textures-for-the-labyrinth-of-the-fertile-void
- collect.xpm : https://opengameart.org/content/gold-coin-0
- player.xpm : https://opengameart.org/content/gangster-0
- wall.xpm : https://opengameart.org/content/bricks-tiled-texture-64x64


## miniLibX
the project uses miniLibx a basic window mangement library.
You can find it here:
https://github.com/42Paris/minilibx-linux

## libft
the project uses the submodule libft which is an earlier project of the 42 core curriculum.
You can find mine here: https://github.com/ayeCaptainJack/libft
