#ifndef _FUN_H
#define _FUN_H

void produce_maze(int **a,int **best,int length,int width);

void best_maze(int **best,int length,int width); 

void move(int **a,int **best,int x,int y,int exit_x,int exit_y,int length,int width);

#endif
