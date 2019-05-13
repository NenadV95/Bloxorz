#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GL/glut.h>
#include <math.h>
#include"draw_cuboid.h"
#include"init.h"
#include"moves.h"

#define TIMER_ID_UP 1
#define TIMER_ID_DOWN 2
#define TIMER_ID_LEFT 3
#define TIMER_ID_RIGHT 4



/* Dimenzije prozora */
static int window_width, window_height;
extern int k;
void on_display();
void on_reshape(int width, int height);
void on_keyboard(unsigned char key, int x, int y);
void on_timer(int value);

#endif
