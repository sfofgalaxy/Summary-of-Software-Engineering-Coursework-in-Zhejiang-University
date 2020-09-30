#ifndef _FUN_H
#define _FUN_H

void produce_maze(int **maze,int **best,int length,int width,int flag);

void best_maze(int **best,int length,int width,int flag); 

void move(int **maze,int **best,int x,int y,int exit_x,int exit_y,int length,int width,int flag);

#endif
