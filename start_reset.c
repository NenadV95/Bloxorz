#include"start_reset.h"

void reset1(){

        k=0;
        dim_x=1;
        dim_y=2;
        dim_z=1;
        angle_x-=sign*360;
        on1=0;
        on2=0;
        glutPostRedisplay();
        animation_active=0;

}

void reset2(){

        k=0;
        dim_x=1;
        dim_y=2;
        dim_z=1;
        angle_x+=sign*360;
        on1=0;
        on2=0;
        glutPostRedisplay();
        animation_active=0;

}

void reset3(){

        k=0;
        dim_x=1;
        dim_y=2;
        dim_z=1;
        angle_z-=sign*360;
        on1=0;
        on2=0;
        glutPostRedisplay();
        animation_active=0;

}

void reset4(){

        k=0;
        dim_x=1;
        dim_y=2;
        dim_z=1;
        angle_z+=sign*360;
        on1=0;
        on2=0;
        glutPostRedisplay();
        animation_active=0;

}
