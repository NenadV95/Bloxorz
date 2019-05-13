#include "callbacks.h"

int counter=0,animation_active=0;
int k=0;


void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    case 'w':
    case 'W':if(!animation_active){
                counter=0;
                glutTimerFunc(1, on_timer, TIMER_ID_UP);
                animation_active = 1;
            }
            break;

    case 'a':
    case 'A':if(!animation_active){
                counter=0;
                glutTimerFunc(1, on_timer, TIMER_ID_LEFT);
                animation_active = 1;
            }
            break;

    case 's':
    case 'S':if(!animation_active){
                counter=0;
                glutTimerFunc(1, on_timer, TIMER_ID_DOWN);
                animation_active = 1;
            }
            break;

    case 'd':
    case 'D':if(!animation_active){
                counter=0;
                glutTimerFunc(1, on_timer, TIMER_ID_RIGHT);
                animation_active = 1;
            }
            break;

    }
}


void on_timer(int value)
{


    if (value == TIMER_ID_UP){

        moveUp();
    }



    if (value == TIMER_ID_DOWN){

        moveDown();
    }

    if (value == TIMER_ID_LEFT){

        moveLeft();
    }

     if (value == TIMER_ID_RIGHT){

        moveRight();
     }
}



void on_display(){

    /* Postavljamo osvetljenje*/
    initialize_light();

    glClearColor(0.9, 0.9, 0.9, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 5, 25);

    /* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-2.5, 7, 11, 0, 0, 0, 0, 1, 0);



    if(k==0){
        s=loadSurface();

        y=1;
        z=-7+s.current_position[1];
        x=-7+s.current_position[0];
    }

    drawSurface();
    k=1;

    /* Iscrtavamo kvadar*/
    drawCuboid();

    /* Saljemo novu sliku na ekran*/
    glutSwapBuffers();
}





void on_reshape(int width, int height)
{
    /* Pamtimo sirinu i visinu prozora. */
    window_width = width;
    window_height = height;
}
