#include"moves.h"

int i=0,j=0,m=0,n=0;
int t=0;

void moveUp(){

        if(s.current_position[2]==-1){

            sign=1;
            lieUpDown();

        }
        else if(s.current_position[1]==s.current_position[3]-1){

            sign=1;
            standUpDown();

        }
        else if(s.current_position[0]==s.current_position[2]-1){

            sign=1;
            rollUpDown();

        }

        if (animation_active){

            glutTimerFunc(1, on_timer, TIMER_ID_UP);

        }

}

void moveDown(){


        if(s.current_position[2]==-1){

            sign=-1;
            lieUpDown();

        }

        else if(s.current_position[1]==s.current_position[3]-1){

            sign=-1;
            standUpDown();

        }
        else if(s.current_position[0]==s.current_position[2]-1 ){

            sign=-1;
            rollUpDown();

        }

        if (animation_active){

            glutTimerFunc(1, on_timer, TIMER_ID_DOWN);

        }


}

void moveLeft(){


        if(s.current_position[2]==-1){

            sign=1;
            lieLeftRight();

        }
        else if(s.current_position[0]==s.current_position[2]-1){

            sign=1;
            standLeftRight();

        }
        else if(s.current_position[1]==s.current_position[3]-1){

            sign=1;
            rollLeftRight();


        }
        if (animation_active){

            glutTimerFunc(1, on_timer, TIMER_ID_LEFT);

        }


}

void moveRight(){

        if(s.current_position[2]==-1){

            sign=-1;
            lieLeftRight();

        }
        else if(s.current_position[0]==s.current_position[2]-1){

            sign=-1;
            standLeftRight();

        }
        else if(s.current_position[1]==s.current_position[3]-1){

            sign=-1;
            rollLeftRight();


        }
        if (animation_active){

            glutTimerFunc(1, on_timer, TIMER_ID_RIGHT);

        }


}

void lieUpDown(){

            if(counter<90){

                if(counter==0){

                    z1=z-sign*0.5;
                }

                counter+=3;
                angle_x-=sign*3;

                if(sign==1){

                    z=z1+cos(M_PI/180*counter+asin(1/sqrt(1.25)))*sqrt(1.25);
                }else{

                    z=z1+cos(M_PI-M_PI/180*counter-asin(1/sqrt(1.25)))*sqrt(1.25);
                }

                y=sin(M_PI/180*counter+asin(1/sqrt(1.25)))*sqrt(1.25);
                glutPostRedisplay();

            }else{

                if(sign==1){
                    i=s.current_position[0];
                    j=s.current_position[1]-2;
                    m=s.current_position[0];
                    n=s.current_position[1]-1;
                }
                else{

                    i=s.current_position[0];
                    j=s.current_position[1]+1;
                    m=s.current_position[0];
                    n=s.current_position[1]+2;
                }
                    if(s.surface[j][i]!=0 && s.surface[n][m]!=0){

                        if(s.surface[j][i]==3 || s.surface[n][m]==3){

                            if(on1==0){

                                t=0;
                                on1=1;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=1;
                                    t++;

                                }
                            }else{

                                t=0;
                                on1=0;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=0;
                                    t++;
                                }

                            }
                        }


                        s.current_position[0]=i;
                        s.current_position[1]=j;
                        s.current_position[2]=m;
                        s.current_position[3]=n;
                        angle_x=angle_x+sign*90;
                        dim_x=1;
                        dim_y=1;
                        dim_z=2;
                        glutPostRedisplay();

                        animation_active=0;

                    }else{

                        if(counter==90){

                            angle_x+=sign*90;
                            dim_x=1;
                            dim_y=1;
                            dim_z=2;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            z=z-sign*0.01;
                            y=y-0.02;
                            counter+=3;
                            angle_x-=sign*3;
                            glutPostRedisplay();

                        }else{

                            reset1();

                        }

                    }

            }



}


void standUpDown(){

            if(counter<90){

                if(counter==0){

                    z1=z-sign*1;
                }

                counter+=3;
                angle_x-=sign*3;
                if(sign==1){

                    z=z1+cos(M_PI/180*counter+asin(1/sqrt(5)))*sqrt(1.25);
                }else{

                    z=z1+cos(M_PI-M_PI/180*counter-asin(1/sqrt(5)))*sqrt(1.25);
                }

                y=sin(M_PI/180*counter+asin(1/sqrt(5)))*sqrt(1.25);

                glutPostRedisplay();

            }else{
                if(sign==1){

                    i=s.current_position[0];
                    j=s.current_position[1]-1;
                }else{

                    i=s.current_position[0];
                    j=s.current_position[1]+2;
                }
                    if(s.surface[j][i]!=0){

                        if(s.surface[j][i]==2){

                            if(counter==90){

                                angle_x=angle_x+sign*90;
                                dim_x=1;
                                dim_y=2;
                                dim_z=1;
                                glutPostRedisplay();

                            }

                            if(counter<190){

                                counter++;
                                y=y-0.06;
                                glutPostRedisplay();

                            }else{

                                level++;
                                k=0;
                                on1=0;
                                on2=0;

                                for(t=0;t<5;t++){

                                    switchingFields2[t][0]=0;
                                    switchingFields2[t][1]=0;

                                }

                                glutPostRedisplay();
                                animation_active=0;

                            }

                        }else{

                            if(s.surface[j][i]==5){

                                if(on2==0){

                                    t=0;
                                    on2=1;

                                    while(switchingFields2[t][0]!=0){

                                        s.surface[switchingFields2[t][0]][switchingFields2[t][1]]=1;
                                        t++;

                                    }
                                }else{

                                    t=0;
                                    on2=0;

                                    while(switchingFields2[t][0]!=0){

                                        s.surface[switchingFields2[t][0]][switchingFields2[t][1]]=0;
                                        t++;
                                    }

                                }
                            }
                            else if(s.surface[j][i]==3){

                                if(on1==0){

                                    t=0;
                                    on1=1;

                                    while(switchingFields1[t][0]!=0){

                                        s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=1;
                                        t++;

                                    }
                                }else{

                                    t=0;
                                    on1=0;

                                    while(switchingFields1[t][0]!=0){

                                        s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=0;
                                        t++;
                                    }

                                }
                            }
                            angle_x=angle_x+sign*90;
                            dim_x=1;
                            dim_y=2;
                            dim_z=1;
                            s.current_position[0]=i;
                            s.current_position[1]=j;
                            s.current_position[2]=-1;
                            s.current_position[3]=-1;
                            glutPostRedisplay();

                            animation_active=0;
                        }

                    }else{

                        if(counter==90){

                            angle_x+=sign*90;
                            dim_x=1;
                            dim_y=2;
                            dim_z=1;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            z=z-sign*0.01;
                            y=y-0.02;
                            counter+=3;
                            angle_x-=sign*3;
                            glutPostRedisplay();

                        }else{

                            reset1();

                        }

                    }

            }



}

void rollUpDown(){

            if(counter<90){

                if(counter==0){

                    z1=z-sign*0.5;
                }

                counter+=3;
                angle_x-=sign*3;
                if(sign==1){

                    z=z1+cos(M_PI/180*counter+M_PI/4)*sqrt(0.5);
                }else{

                    z=z1+cos(3*M_PI/4-M_PI/180*counter)*sqrt(0.5);
                }

                y=sin(M_PI/180*counter+M_PI/4)*sqrt(0.5);

                glutPostRedisplay();

            }else{

                    i=s.current_position[0];
                    j=s.current_position[1]-sign*1;
                    m=s.current_position[2];
                    n=s.current_position[3]-sign*1;

                    if(s.surface[j][i]!=0 && s.surface[n][m]!=0){

                        if(s.surface[j][i]==3 || s.surface[n][m]==3){

                            if(on1==0){

                                t=0;
                                on1=1;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=1;
                                    t++;

                                }
                            }else{

                                t=0;
                                on1=0;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=0;
                                    t++;
                                }

                            }
                        }

                        s.current_position[0]=i;
                        s.current_position[1]=j;
                        s.current_position[2]=m;
                        s.current_position[3]=n;
                        angle_x=angle_x+sign*90;
                        dim_x=2;
                        dim_y=1;
                        dim_z=1;
                        glutPostRedisplay();
                        animation_active=0;

                    }else if(s.surface[j][i]==0 && s.surface[n][m]!=0){


                        if(i<m){

                            direction=-1*sign;
                        }
                        else{

                            direction=sign;
                        }

                        if(counter==90){

                            angle_x=angle_x+sign*90;
                            dim_x=2;
                            dim_y=1;
                            dim_z=1;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            x=x+sign*direction*0.015;
                            y=y-0.02;
                            counter+=3;
                            angle_z-=sign*direction*3;
                            glutPostRedisplay();

                        }else{

                            reset4();

                        }

                    }
                    else if(s.surface[j][i]!=0 && s.surface[n][m]==0){


                        if(i<m){

                            direction=-1*sign;
                        }
                        else{

                            direction=sign;
                        }

                        if(counter==90){

                            angle_x=angle_x+sign*90;
                            dim_x=2;
                            dim_y=1;
                            dim_z=1;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            x=x-sign*direction*0.015;
                            y=y-0.02;
                            counter+=3;
                            angle_z+=sign*direction*3;
                            glutPostRedisplay();

                        }else{

                            reset3();

                        }

                    }else{

                        if(counter==90){

                            angle_x+=sign*90;
                            dim_x=2;
                            dim_y=1;
                            dim_z=1;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            z=z-sign*0.015;
                            y=y-0.02;
                            counter+=3;
                            angle_x-=sign*3;
                            glutPostRedisplay();

                        }else{

                            reset2();

                        }

                    }

            }


}



void lieLeftRight(){

            if(counter<90){

                if(counter==0){

                    x1=x-sign*0.5;
                }

                counter+=3;
                angle_z+=sign*3;
                if(sign==1){

                    x=x1+cos(M_PI/180*counter+asin(1/sqrt(1.25)))*sqrt(1.25);
                }else{

                    x=x1+cos(M_PI-M_PI/180*counter-asin(1/sqrt(1.25)))*sqrt(1.25);
                }

                y=sin(M_PI/180*counter+asin(1/sqrt(1.25)))*sqrt(1.25);

                glutPostRedisplay();

            }else{
                    if(sign==1){
                        i=s.current_position[0]-2;
                        j=s.current_position[1];
                        m=s.current_position[0]-1;
                        n=s.current_position[1];
                    }else{

                        i=s.current_position[0]+1;
                        j=s.current_position[1];
                        m=s.current_position[0]+2;
                        n=s.current_position[1];

                    }
                    if(s.surface[j][i]!=0 && s.surface[n][m]!=0){

                        if(s.surface[j][i]==3 || s.surface[n][m]==3){

                            if(on1==0){

                                t=0;
                                on1=1;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=1;
                                    t++;

                                }
                            }else{

                                t=0;
                                on1=0;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=0;
                                    t++;
                                }

                            }
                        }


                        s.current_position[0]=i;
                        s.current_position[1]=j;
                        s.current_position[2]=m;
                        s.current_position[3]=n;
                        angle_z=angle_z-sign*90;
                        dim_x=2;
                        dim_y=1;
                        dim_z=1;
                        glutPostRedisplay();

                        animation_active=0;

                    }else{

                        if(counter==90){

                            angle_z-=sign*90;
                            dim_x=2;
                            dim_y=1;
                            dim_z=1;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            x=x-sign*0.01;
                            y=y-0.02;
                            counter+=3;
                            angle_z+=sign*3;
                            glutPostRedisplay();

                        }else{

                            reset3();

                        }

                    }

            }

}


void standLeftRight(){

        if(counter<90){

            if(counter==0){

                    x1=x-sign*1;
                }

                counter+=3;
                angle_z+=sign*3;

                if(sign==1){

                    x=x1+cos(M_PI/180*counter+asin(1/sqrt(5)))*sqrt(1.25);
                }else{

                    x=x1+cos(M_PI-M_PI/180*counter-asin(1/sqrt(5)))*sqrt(1.25);
                }

                y=sin(M_PI/180*counter+asin(1/sqrt(5)))*sqrt(1.25);

                glutPostRedisplay();

            }else{
                    if(sign==1){

                        i=s.current_position[0]-1;
                        j=s.current_position[1];

                    }else{

                        i=s.current_position[0]+2;
                        j=s.current_position[1];

                    }
                    if(s.surface[j][i]!=0){

                        if(s.surface[j][i]==2){

                            if(counter==90){

                                angle_z=angle_z-sign*90;
                                dim_x=1;
                                dim_y=2;
                                dim_z=1;
                                glutPostRedisplay();

                            }
                            if(counter<190){

                                counter++;
                                y=y-0.06;
                                glutPostRedisplay();

                            }else{

                                level++;
                                k=0;
                                on1=0;
                                on2=0;

                                for(t=0;t<5;t++){

                                    switchingFields2[t][0]=0;
                                    switchingFields2[t][1]=0;

                                }

                                glutPostRedisplay();
                                animation_active=0;

                                animation_active=0;
                                glutPostRedisplay();

                            }

                        }
                        else{

                            if(s.surface[j][i]==5){

                                if(on2==0){

                                    t=0;
                                    on2=1;

                                    while(switchingFields2[t][0]!=0){

                                        s.surface[switchingFields2[t][0]][switchingFields2[t][1]]=1;
                                        t++;
                                    }

                                }else{

                                    t=0;
                                    on2=0;

                                    while(switchingFields2[t][0]!=0){

                                        s.surface[switchingFields2[t][0]][switchingFields2[t][1]]=0;
                                        t++;
                                    }

                                }
                            }else if(s.surface[j][i]==3){

                                if(on1==0){

                                    t=0;
                                    on1=1;

                                    while(switchingFields1[t][0]!=0){

                                        s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=1;
                                        t++;

                                    }
                                }else{

                                    t=0;
                                    on1=0;

                                    while(switchingFields1[t][0]!=0){

                                        s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=0;
                                        t++;
                                    }

                                }
                            }


                            angle_z=angle_z-sign*90;
                            dim_x=1;
                            dim_y=2;
                            dim_z=1;
                            s.current_position[0]=i;
                            s.current_position[1]=j;
                            s.current_position[2]=-1;
                            s.current_position[3]=-1;
                            glutPostRedisplay();

                            animation_active=0;

                        }

                    }else{

                        if(counter==90){

                            angle_z-=sign*90;
                            dim_x=1;
                            dim_y=2;
                            dim_z=1;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            x=x-sign*0.01;
                            y=y-0.02;
                            counter+=3;
                            angle_z+=sign*3;
                            glutPostRedisplay();

                        }else{

                            reset3();

                        }

                    }

            }


}


void rollLeftRight(){

            if(counter<90){

                if(counter==0){

                    x1=x-sign*0.5;
                }

                counter+=3;
                angle_z+=sign*3;

                if(sign==1){

                    x=x1+cos(M_PI/180*counter+M_PI/4)*sqrt(0.5);
                }else{

                    x=x1+cos(3*M_PI/4-M_PI/180*counter)*sqrt(0.5);
                }

                y=sin(M_PI/180*counter+M_PI/4)*sqrt(0.5);

                glutPostRedisplay();

            }else{

                    i=s.current_position[0]-sign*1;
                    j=s.current_position[1];
                    m=s.current_position[2]-sign*1;
                    n=s.current_position[3];

                    if(s.surface[j][i]!=0 && s.surface[n][m]!=0){

                        if(s.surface[j][i]==3 || s.surface[n][m]==3){

                            if(on1==0){

                                t=0;
                                on1=1;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=1;
                                    t++;

                                }
                            }else{

                                t=0;
                                on1=0;

                                while(switchingFields1[t][0]!=0){

                                    s.surface[switchingFields1[t][0]][switchingFields1[t][1]]=0;
                                    t++;
                                }

                            }
                        }

                        s.current_position[0]=i;
                        s.current_position[1]=j;
                        s.current_position[2]=m;
                        s.current_position[3]=n;
                        angle_z=angle_z-sign*90;
                        dim_x=1;
                        dim_y=1;
                        dim_z=2;
                        glutPostRedisplay();
                        animation_active=0;

                    }else if(s.surface[j][i]==0 && s.surface[n][m]!=0){


                        if(j<n){

                            direction=sign;
                        }
                        else{

                            direction=-sign;
                        }

                        if(counter==90){

                            angle_z-=sign*90;
                            dim_x=1;
                            dim_y=1;
                            dim_z=2;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            z=z-sign*direction*0.015;
                            y=y-0.02;
                            counter+=3;
                            angle_x-=sign*direction*3;
                            glutPostRedisplay();

                        }else{

                            reset2();

                        }

                    }else if(s.surface[j][i]!=0 && s.surface[n][m]==0){


                        if(j<n){

                            direction=sign;
                        }
                        else{

                            direction=-sign;
                        }

                        if(counter==90){

                            angle_z-=sign*90;
                            dim_x=1;
                            dim_y=1;
                            dim_z=2;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            z=z+sign*direction*0.015;
                            y=y-0.02;
                            counter+=3;
                            angle_x+=sign*direction*3;
                            glutPostRedisplay();

                        }else{

                            reset1();

                        }

                    }else{

                        if(counter==90){

                            angle_z-=sign*90;
                            dim_x=1;
                            dim_y=1;
                            dim_z=2;
                            glutPostRedisplay();
                        }

                        if(counter<450){

                            x=x-sign*0.01;
                            y=y-0.02;
                            counter+=3;
                            angle_z+=sign*3;
                            glutPostRedisplay();

                        }else{

                            reset3();

                        }

                    }

            }

}



