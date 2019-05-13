#include"init.h"


void initialize_callbacks(void){

	glutDisplayFunc(*on_display);
	glutReshapeFunc(&on_reshape);
	glutKeyboardFunc(on_keyboard);
}


void initialize_glut(int *argc, char **argv){

    /* Inicijalizujemo GLUT. */
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* Kreiramo prozor. */
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bloxorz");

    /* Obavljamo OpenGL inicijalizaciju. */
    /*glClearColor(0.9, 0.9, 0.9, 0);*/
    glEnable(GL_DEPTH_TEST);



}



void initialize_light(){


    /* Pozicija svetla  */
    GLfloat light_position[] = { 5, 1, 5, 0 };

    /* Ambijentalna boja svetla. */
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };

    /* Difuzna boja svetla. */
    GLfloat light_diffuse[] = { 0.4, 0.4, 0.4, 1 };

    /* Spekularna boja svetla. */
    GLfloat light_specular[] = { 1, 1, 1, 1 };

    /* Pozicija drugog svetla  */
    GLfloat light_position1[] = { -5, 0.1, 5, 1 };


    /*Omogucujemo osvetljenje i postavljamo parametre svetala*/
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);


    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
}



