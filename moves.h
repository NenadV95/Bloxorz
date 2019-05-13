#ifndef MOVES_H
#define MOVES_H

#include<GL/glut.h>
#include<math.h>
#include"draw_cuboid.h"
#include"callbacks.h"
#include"start_reset.h"


extern int counter,animation_active;
int i,j,m,n;
int direction,sign;
extern int t;
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
void lieUpDown();
void standUpDown();
void rollUpDown();
void lieLeftRight();
void standLeftRight();
void rollLeftRight();

#endif
