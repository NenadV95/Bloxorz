#include <GL/glut.h>
#include "init.h"




int main(int argc, char **argv)
{
	initialize_glut(&argc, argv);

	initialize_callbacks();
	glutMainLoop();

	return 0;
}
