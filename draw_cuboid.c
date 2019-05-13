#include"draw_cuboid.h"

    int angle_x=0,angle_z=0;
    double x=0,y=0,z=0,x1=0,z1=0;
    int dim_x=1,dim_y=2,dim_z=1;
    int level=1;
    int on1=0,on2=0;


void drawCuboid(int start_position[]){


    /* Postavljamo koeficijente ambijentalne, difuzne i spekularne refleksije materijala, kao i glatkost materijala. */
    GLfloat material_ambient[] = { 0.7, 0.7, 0.7, 1 };

    GLfloat material_diffuse[] = { 1, 0, 0, 1 };

    GLfloat material_specular[] = { 1, 1, 1, 1 };

    GLfloat shininess[] = { 100 };


    /* Iscrtavamo kvadar na startnoj poziciji*/
    glPushMatrix();

        glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        glTranslatef(x,y,z);
        glRotatef(angle_z,0,0,1);
        glRotatef(angle_x,1,0,0);
        glScalef(dim_x,dim_y,dim_z);
        glutSolidCube(1);

    glPopMatrix();

}



surface loadSurface(){

    surface s;
    int i,j;
    FILE *f;
    int k=0;
    int l=0;
    char file_name[10];
    char lvl[10];
    char levels[8]="levels/";

    sprintf(lvl,"%d",level);
    strcpy(file_name,lvl);
    strcat(file_name,".txt");
    strcat(levels,file_name);
    strcpy(file_name,levels);
    /* Otvaramo .txt fajl u kome se nalaze podaci o povrs-1.5+i*/
    f=fopen(file_name,"r");
    if( f == NULL ){

        exit(0);
    }

    /* Ucitavamo podatke o povrsi u matricu. U fajlu se nalazi 16 redova,
     u prvih 15 redova brojevi mogu biti samo 0 ili 1. 0 oznacava
     da kvadrat na toj poziciji ne crtamo, a 1 da crtamo. U 16 redu su koordinate
     startne pozicije kao i koordinate rupe*/
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){

            fscanf(f,"%d",&s.surface[i][j]);
            if(s.surface[i][j]==4){

                switchingFields1[k][0]=i;
                switchingFields1[k][1]=j;
                s.surface[i][j]=0;
                k++;

            }
            if(s.surface[i][j]==6){

                switchingFields2[l][0]=i;
                switchingFields2[l][1]=j;
                s.surface[i][j]=0;
                l++;
            }




        }
    }

    fscanf(f,"%d %d",&s.current_position[0], &s.current_position[1]);
    s.current_position[2]=-1;
    s.current_position[3]=-1;

    fclose(f);

    return s;

}

void drawSurface()
{

    int i,j;

    /* Postavljamo koeficijente ambijentalne, difuzne i spekularne refleksije materijala, kao i glatkost materijala. */
    GLfloat material_ambient1[] = { 0.7, 0.7, 0.7, 1 };

    GLfloat material_diffuse1[] = { 1, 1, 1, 1 };

    GLfloat material_specular1[] = { 1, 1, 1, 1 };

    GLfloat material_ambient2[] = { 0.7, 0.7, 0.7, 1 };

    GLfloat material_diffuse2[] = { 0.9, 0.9, 0.9, 1 };

    GLfloat material_specular2[] = { 1, 1, 1, 1 };

    GLfloat material_diffuse3[] = { 0.3, 1, 0.3, 1 };

    GLfloat material_diffuse4[] = { 0.3, 0.3, 1, 1 };

    GLfloat shininess[] = { 100 };


    for( i=0; i<15;i++){
        for( j=0; j<15; j++){
            /*Crtamo kvadrate samo ako se u matrici na mestu koje mu odgovara nalazi 1*/
            if(s.surface[i][j]==1){
                /*Odredjujemo boju svakog kvadrata u odnosu na njegovu poziciju*/
                if(i%2==0){

                    if(j%2==0){

                        glPushMatrix();
                            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient1);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse1);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular1);
                            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
                            glTranslatef(-7+j, -0.2,-7+i);
                            glScalef(1,0.4,1);
                            glutSolidCube(1);
                        glPopMatrix();
                    }
                    else{

                        glPushMatrix();
                            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient2);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse2);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular2);
                            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
                            glTranslatef(-7+j, -0.2,-7+i);
                            glScalef(1,0.4,1);
                            glutSolidCube(1);
                        glPopMatrix();
                    }
                }

                else{

                    if(j%2==0){

                        glPushMatrix();
                            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient2);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse2);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular2);
                            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
                            glTranslatef(-7+j, -0.2,-7+i*1);
                            glScalef(1,0.4,1);
                            glutSolidCube(1);
                        glPopMatrix();
                        }
                    else{

                        glPushMatrix();
                            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient1);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse1);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular1);
                            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
                            glTranslatef(-7+j, -0.2,-7+i);
                            glScalef(1,0.4,1);
                            glutSolidCube(1);
                        glPopMatrix();
                    }
                }
            }
            else if(s.surface[i][j]==3){

                        glPushMatrix();
                            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient1);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse3);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular1);
                            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
                            glTranslatef(-7+j, -0.2,-7+i);
                            glScalef(1,0.4,1);
                            glutSolidCube(1);
                        glPopMatrix();

            }
            else if(s.surface[i][j]==5){

                        glPushMatrix();
                            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient1);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse4);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular1);
                            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
                            glTranslatef(-7+j, -0.2,-7+i);
                            glScalef(1,0.4,1);
                            glutSolidCube(1);
                        glPopMatrix();

            }

        }
    }



}
