# cub3d

## Table of contents

1. [About](#about)
2. [Description](#description)
4. [minilibX](#minilibx)
5. [libft](#libft)


## About
cub3d is a project of the 42 core curriculum with the purpose of learning about graphics, windows, events, colours and more.
The task is to write a 3D game similar to [Wolfenstein 3D] using a raycasting algorithm.
The school provides a small library to use which only contains some really basic functions. 

<img width="1280" alt="Screen Shot 2022-02-21 at 5 27 20 PM" src="https://user-images.githubusercontent.com/83188617/154994520-509f68c9-8e98-4c28-96c5-98167b7b2758.png">

**how to use:**

Clone the repository:
```bash
git clone --recursive https://github.com/JeremieSiller/cub3d/
```
run make to compile the programm 
```bash
make
```
execute the programm with a .ber file
```bash
./cub3D map.cub
```
to start the game the config file needs to follow some rules else it will just return an error. (For more information look into [Description](#description))


## Description
**how to play:**
- use W A S D to move
- use the mouse to turn
- press ESC to get to the pause menu
- press ESC again to quit or return to continue the game

**a valid config file...**
- ends on .cub
- contains a ceiling and floor colour (C/F) in a format: "R,B,G"
- contains a path to a texture for each wall and direction (NO/SO/WE/EA) (texture has to be a valid xpm file)
- contains at the bottom of the file a valid map

**a valid map...**
- is sorrounded by walls (1)
- contains exactly one player with its looking direction (N/W/E/S)
- can contain some coins (C) and some empty space (0)

You can find an example config in the directory called "map.cub"

## miniLibX
the project uses miniLibx a basic window mangement library.
You can find it here:
https://github.com/42Paris/minilibx-linux

## libft
the project uses the submodule libft which is an earlier project of the 42 core curriculum.
You can find mine here: https://github.com/ayeCaptainJack/libft

[Wolfenstein 3D]: https://en.wikipedia.org/wiki/Wolfenstein_3D
