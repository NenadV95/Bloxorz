#ifndef DRAW_CUBOID_H
#define DRAW_CUBOID_H

#include <GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Definicija strukture koja sadrzi podatke o povrsi za igru*/
typedef struct Surface{
    int surface[15][15];
    int current_position[4];
}surface;


surface s;
int switchingFields1[5][2],switchingFields2[5][2];
extern int angle_x,angle_z;
extern double x,y,z,x1,z1;
extern int dim_x,dim_y,dim_z;
extern int level;
extern int on1,on2;

/* Deklaracija funkcije koja ucitava podatke o povrsi iz .txt fajla*/
surface loadSurface();

void drawSurface();

void drawCuboid();

#endif
