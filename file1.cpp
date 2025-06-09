#include <windows.h>
#include <GL/glut.h>
#include <math.h>
# define PI 3.14159265358979323846

//////////////////////////basic function
void circle(float a, float b, float r) {

    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x = a; GLfloat y = b; GLfloat radius = r;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }   glEnd();
}

void quad(float a, float b, float c, float d, float e, float f, float g, float h) {
    glBegin(GL_QUADS);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

void triangle(float a, float b, float c, float d, float e, float f) {
    glBegin(GL_TRIANGLES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glEnd();
}

void line(float a, float b, float c, float d) {
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glEnd();
}

void HalfCircle(float x, float y, float r) {
    int i;
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    for (i = 50; i <= lineAmount;i++)
    {
        glVertex2f(x + (r * cos(i * twicePi / lineAmount)), y + (r * sin(i * twicePi / lineAmount)));
    }
    glEnd();
}

///////////////////////////////////sound function







//////////////////////////////UPDATE FUNCTION

GLfloat rainP = 2.50f;
GLfloat rainSpeed = 0.0f;
void rainUp(int value) {

    if (rainP < -1.0)
        rainP = .50f;
    rainP -= rainSpeed;
    glutPostRedisplay();
    glutTimerFunc(100, rainUp, 0);

}



GLfloat cloudP = 2.0f;
GLfloat cloudS = 0.02f;
void cloudUp(int value) {
    if (cloudP < -2.0)
        cloudP = 2.0f;
    cloudP -= cloudS;
    glutPostRedisplay();
    glutTimerFunc(100, cloudUp, 0);
}


GLfloat treeP1 = 0.0;GLfloat treeP2 = 0.0;GLfloat treeP3 = 0.0;
GLfloat treeP4 = 0.0;GLfloat treeP5 = 0.0;
GLfloat treeS1 = 0.03;GLfloat treeS2 = 0.03;GLfloat treeS3 = 0.03;
GLfloat treeS4 = 0.03;GLfloat treeS5 = 0.03;
void treeUp(int value) {




    if (treeP1 < -1.0) {
        treeS1 = 0.0f;

        if (treeP2 < -1.0) {
            treeS2 = 0.0f;

            if (treeP3 < -1.0) {
                treeS3 = 0.0f;

                if (treeP4 < -1.0) {
                    treeS4 = 0.0f;

                    if (treeP5 < -1.20) {
                        treeS5 = 0.0f;



                    }
                    treeP5 -= treeS5;

                }
                treeP4 -= treeS4;

            }
            treeP3 -= treeS3;


        }
        treeP2 -= treeS2;
    }
    treeP1 -= treeS1;





    glutPostRedisplay();
    glutTimerFunc(100, treeUp, 0);

}



GLfloat flowerP = 0.0f;
GLfloat flowerS = 0.005f;
void flowerUp(int value) {
    if (flowerP < -1.0)
        flowerS = 0.0f;
    flowerP -= flowerS;
    glutPostRedisplay();
    glutTimerFunc(100, flowerUp, 0);
}



GLfloat sunP = 0.0f;
GLfloat sunS = 0.005f;
void sunUp(int value) {
    if (sunP > 1.5)
        sunS = 0.0f;
    sunP += sunS;
    glutPostRedisplay();
    glutTimerFunc(100, sunUp, 0);
}

GLfloat sunP2 = 0.0f;
GLfloat sunS2 = 0.005f;
void sunUp2(int value) {
    if (sunP2 > 1.5)
        sunS2 = 0.0f;
    sunP2 += sunS2;
    glutPostRedisplay();
    glutTimerFunc(100, sunUp2, 0);
}


GLfloat snowP = 3.0f;
GLfloat snowS = 0.0105f;
void snowUp(int value) {

    if (snowP < -1.50)
        snowP = 1.0f;
    snowP -= snowS;
    glutPostRedisplay();
    glutTimerFunc(100, snowUp, 0);
}


GLfloat RcloudP = 3.5f;
GLfloat RcloudS = 0.02f;
void RcloudUp(int value) {
    if (RcloudP < -0.0)
        RcloudP = 1.0f;
    RcloudP -= RcloudS;
    glutPostRedisplay();
    glutTimerFunc(100, RcloudUp, 0);
}


GLfloat wSpeed = 0.0f;
void windmill() {
    //pillar
    glColor3ub(230, 162, 80);
    quad(-.01, 0, -.03, -.35, .03, -.35, .01, 0);

    glPushMatrix();
    glRotatef(wSpeed, 0.0, 0.0, 0.1);
    //glColor3ub(247, 5, 5);
    glColor3ub(247, 203, 5);
    quad(0, 0, 0, .2, -.1, .2, 0, 0);
    quad(0, 0, 0, -.2, .1, -.2, 0, 0);
    quad(0, 0, .2, 0, .2, .1, 0, 0);
    quad(0, 0, -.2, 0, -.2, -.1, 0, 0);

    glPopMatrix();
    wSpeed -= 0.15f;
    //center
    glColor3ub(252, 252, 252);
    circle(0.0, 0.0, .015);
}

GLfloat boatP = -1.2f;
GLfloat boatS = 0.02f;
void boatUp(int value) {
    if (boatP > 1.5)
        boatP = 1.2f;
    boatP += boatS;
    glutPostRedisplay();
    glutTimerFunc(100, boatUp, 0);
}






//////////////////////object function

void sky() {

    glBegin(GL_QUADS);

    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);

    glEnd();
}
void thander() {
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0, .95);glVertex2f(.05, .85);
    glVertex2f(.05, .85);glVertex2f(.09, .89);
    glVertex2f(.09, .89);glVertex2f(.15, .76);
    glEnd();
}
void snowball() {
    circle(-1.5, .95, .01);
    circle(-.95, .75, .01);
    circle(-.65, 0.55, .01);
    circle(-.35, 0.46, .01);
    circle(-.05, 0.648, .01);
    circle(.25, .83, .01);
    circle(.55, 0.8, .01);
    circle(.75, 0.35, .01);
    circle(1., 0.26, .01);
    circle(-.45, 0.148, .01);

}
void mountain() {
    //right
    glColor3ub(61, 119, 135);
    triangle(.55, 0, 1.1, 0, .8, .22);
    glColor3ub(29, 78, 92);
    triangle(.55, 0, .65, 0, .8, .22);



    //main mountain
    glBegin(GL_QUADS);

    glColor3ub(75, 152, 173);
    glVertex2f(-.35, 0);
    glVertex2f(.75, 0);
    glVertex2f(.25, .45);
    glVertex2f(.1, .43);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);

    glVertex2f(.25, .45);
    glVertex2f(.1, .43);

    glVertex2f(-.039, .3);

    glVertex2f(.08, .35);
    glVertex2f(.06, .25);
    //left up 2
    glVertex2f(.17, .355);
    glVertex2f(.25, .27);
    //left up 1
    glVertex2f(.25, .38);
    //rightt dopwn
    glVertex2f(.42, .3);

    glEnd();





    glBegin(GL_TRIANGLES);
    glColor3ub(61, 119, 135);
    //left 1
    glVertex2f(-1.1, 0);
    glVertex2f(-.75, 0);
    glVertex2f(-.9, .12);
    glColor3ub(29, 78, 92);
    glVertex2f(-1.1, 0);
    glVertex2f(-.98, 0);
    glVertex2f(-.9, .12);




    //left2

    glColor3ub(61, 119, 135);
    glVertex2f(-.8, 0);
    glVertex2f(-.3, 0);
    glVertex2f(-.55, .15);
    glColor3ub(29, 78, 92);
    glVertex2f(-.8, 0);
    glVertex2f(-.7, 0);
    glVertex2f(-.55, .15);


    //left big

    glColor3ub(61, 119, 135);
    glVertex2f(-.45, 0);
    glVertex2f(.1, 0);
    glVertex2f(-.2, .23);
    glColor3ub(29, 78, 92);
    glVertex2f(-.45, 0);
    glVertex2f(-.35, 0);
    glVertex2f(-.2, .23);

    ////mid

    glColor3ub(61, 119, 135);
    glVertex2f(-.1, 0);
    glVertex2f(.3, 0);
    glVertex2f(.1, .12);
    glColor3ub(29, 78, 92);
    glVertex2f(-.1, 0);
    glVertex2f(0, 0);
    glVertex2f(.1, .12);

    glEnd();


}
void house() {

    ///// houseGrass
      //left
    circle(0.52, -.33, .04);
    circle(0.49, -.34, .03);

    glTranslated(.4, -.005, 0);
    //right
    circle(0.52, -.31, .045);
    circle(0.55, -.325, .03);
    glLoadIdentity();


    ///////////////////// house
    glScalef(1.2, 1.2, 0);
    glTranslated(.05, 0.0, 0);
    glBegin(GL_QUADS);
    glColor3ub(0, 1, 0);
    glVertex2f(.4, -.1);
    glVertex2f(.4, -.3);
    glVertex2f(.7, -.3);
    glVertex2f(.7, -.1);
    glEnd();
    //door
    glBegin(GL_QUADS);
    glColor3ub(242, 133, 31);
    glVertex2f(.52, -.2);
    glVertex2f(.52, -.3);
    glVertex2f(.58, -.3);
    glVertex2f(.58, -.2);

    glVertex2f(.43, -.21);
    glVertex2f(.43, -.26);
    glVertex2f(.49, -.26);
    glVertex2f(.49, -.21);

    glVertex2f(.61, -.21);
    glVertex2f(.61, -.26);
    glVertex2f(.67, -.26);
    glVertex2f(.67, -.21);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(245, 43, 32);
    glVertex2f(.39, -.05);
    glVertex2f(.37, -.18);
    glVertex2f(.73, -.18);
    glVertex2f(.71, -.05);
    glEnd();



    glBegin(GL_QUADS);
    //fairplace
   /*  glColor3ub(212, 205, 205);
    glVertex2f(.61,-.08);
    glVertex2f(.61,-.13);
    glVertex2f(.67,-.13);
    glVertex2f(.67,-.08);*/

    glColor3ub(204, 51, 0);
    glVertex2f(.39, -.29);
    glVertex2f(.39, -.31);
    glVertex2f(.71, -.31);
    glVertex2f(.71, -.29);
    glEnd();

    glLoadIdentity();
}
void downFlower() {
    //red
    glColor3ub(235, 29, 2);
    circle(-.78, -.9f, .02);
    circle(-.72, -.9f, .02);
    circle(-.75, -.87f, .02);
    circle(-.75f, -.93, .02);
    //   center
    glColor3ub(255, 242, 10);
    circle(-.75f, -.9, .015);


    //yellow
    glScalef(0.9, .9, 0);
    glTranslated(0, 0, 0);

    glColor3ub(250, 197, 40);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    //   center40
    glColor3ub(252, 23, 23);
    circle(-.75, -.9, .015); glLoadIdentity();


    glTranslated(.25, -.03, 0);
    glColor3ub(235, 29, 2);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    //   center40
    glColor3ub(255, 242, 10);
    circle(-.75, -.9, .015); glLoadIdentity();

    glTranslated(.42, -.0, 0);

    glColor3ub(250, 197, 40);
    circle(-.78, -.9, .02); circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);circle(-.75, -.93, .02);
    //   center
    glColor3ub(252, 23, 23);
    circle(-.75, -.9, .015);glLoadIdentity();

    glTranslated(.56, -.04, 0);
    glColor3ub(255, 186, 245);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    //   center
    glColor3ub(245, 24, 65);
    circle(-.75, -.9, .015);glLoadIdentity();

    glTranslated(.7, -.01, 0);
    glColor3ub(235, 29, 2);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    //   center
    glColor3ub(255, 242, 10);
    circle(-.75, -.9, .015);glLoadIdentity();


    glTranslated(.87, .07, 0);
    glColor3ub(255, 186, 245);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    glColor3ub(245, 24, 65);
    circle(-.75, -.9, .015);glLoadIdentity();

    glTranslated(.97, -.02, 0);
    glColor3ub(255, 186, 245);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    glColor3ub(245, 24, 65);
    circle(-.75, -.9, .015);glLoadIdentity();


    glTranslated(1.12, -.03, 0);
    glColor3ub(235, 29, 2);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    glColor3ub(255, 242, 10);
    circle(-.75, -.9, .015);glLoadIdentity();


    glTranslated(1.26, -.04, 0);
    glColor3ub(235, 29, 2);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    //   center
    glColor3ub(255, 242, 10);
    circle(-.75, -.9, .015);glLoadIdentity();


    glTranslated(1.5, .04, 0);
    glColor3ub(255, 186, 245);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    glColor3ub(245, 24, 65);
    circle(-.75, -.9, .015);glLoadIdentity();

    glTranslated(1.36, -.0, 0);

    glColor3ub(250, 197, 40);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    //   center
    glColor3ub(252, 23, 23);
    circle(-.75, -.9, .015);glLoadIdentity();
}
void downFlower3() {
    glColor3ub(235, 29, 2);
    circle(-.78, -.9f, .02);
    circle(-.72, -.9f, .02);
    circle(-.75, -.87f, .02);
    circle(-.75f, -.93, .02);
    //   center
    glColor3ub(255, 242, 10);
    circle(-.75f, -.9, .015);

    glTranslated(.42, -.0, 0);

    glColor3ub(250, 197, 40);
    circle(-.78, -.9, .02); circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);circle(-.75, -.93, .02);
    //   center
    glColor3ub(252, 23, 23);
    circle(-.75, -.9, .015);glLoadIdentity();

    glTranslated(1.0, -.03, 0);
    glColor3ub(235, 29, 2);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    glColor3ub(255, 242, 10);
    circle(-.75, -.9, .015);glLoadIdentity();
    glTranslated(1.5, .04, 0);
    glColor3ub(255, 186, 245);
    circle(-.78, -.9, .02);
    circle(-.72, -.9, .02);
    circle(-.75, -.87, .02);
    circle(-.75, -.93, .02);
    glColor3ub(245, 24, 65);
    circle(-.75, -.9, .015);glLoadIdentity();
}
void tree() {
    glBegin(GL_POLYGON);
    glColor3ub(69, 30, 14);
    glVertex2f(-.67, -.2);
    glVertex2f(-.84, -.85);
    glVertex2f(-.73, -.85);
    glVertex2f(-.6, -.2);
    glEnd();
    //right down
    quad(-.6, -.22, -.4, -.29, -.39, -.28, -.55, -.2);

    //right mid
    quad(-.63, -.18, -.65, -.28, -.4, -.1, -.33, -.09);

    //right up
    quad(-.6, -.18, -.55, -.18, -.55, -.01, -.56, -.02);
    //left
    //left up
    quad(-.75, -.16, -.68, -.18, -.78, .02, -.8, .03);





    quad(-.63, -.18, -.62, -.28, -.9, -.14, -.89, -.12);

    glBegin(GL_QUADS);
    //root
    glVertex2f(-.83, -.82);
    glVertex2f(-.95, -.88);
    glVertex2f(-.81, -.85);
    glVertex2f(-.81, -.82);
    glVertex2f(-.81, -.82);
    glVertex2f(-.83, -.84);
    glVertex2f(-.63, -.89);
    glVertex2f(-.73, -.82);

    glEnd();
}
void downGrass() {
    glColor3ub(30, 74, 15);
    circle(-.9, -.9, .2);

    glColor3ub(30, 74, 15);
    circle(-.33, -.93, .115);

    glColor3ub(63, 163, 20);
    circle(-.7, -.9, .15);

    glColor3ub(63, 163, 20);
    circle(-.5, -.95, .1);

    glColor3ub(63, 163, 20);
    circle(-.18, -.95, .08);

    glColor3ub(63, 163, 20);
    circle(-.03, -.95, .11);


    glTranslated(.87, .0, 0);
    glColor3ub(49, 128, 15);
    circle(-.7, -.9, .15);

    glColor3ub(49, 128, 15);
    circle(-.5, -.95, .1);
    glLoadIdentity();

    glColor3ub(63, 163, 20);
    circle(.52, -.95, .09);

    glColor3ub(30, 74, 15);
    circle(0.9, -.9, .19);

    glColor3ub(63, 163, 20);
    circle(.7, -.93, .13);
}
void whiteFlower() {
    /////////grass
    glColor3ub(68, 173, 47);
    triangle(-.5, -1.0, -.45, -1.0, -.35, -.65);


    triangle(-.5, -1.0, -.45, -1.0, -.6, -.65);

    triangle(-.2, -1.0, -.15, -1.0, -.35, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.0, -.65);

    triangle(-.45, -1.0, -.4, -1.0, -.2, -.65);

    triangle(.15, -1.0, .2, -1.0, .35, -.65);
    triangle(.15, -1.0, .2, -1.0, .05, -.65);

    triangle(.45, -1.0, .5, -1.0, .35, -.65);

    triangle(.55, -1.0, .6, -1.0, .55, -.65);
    triangle(.6, -1.0, .65, -1.0, .8, -.65);

    triangle(.85, -1.0, .9, -1.0, 1.0, -.65);

    glLineWidth(2);

    glColor3ub(68, 173, 47);
    line(-.5, -1.0, -.43, -.65);
    line(-.3, -1.0, -.25, -.65);
    line(-.15, -1.0, -.1, -.65);
    line(.0, -1.0, .1, -.65);

    line(.25, -1.0, .2, -.6);
    line(.28, -1.0, .32, -.65);
    line(.35, -1.0, .4, -.65);
    line(.45, -1.0, .58, -.62);
    line(.53, -1.0, .5, -.65);
    line(.6, -1.0, .7, -.65);
    line(.75, -1.0, .85, -.65);

    ///////////white flower

    glColor3ub(239, 245, 237);
    glTranslated(.032, .0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.45, -.7);
    glVertex2f(-.43, -.55);
    glEnd();


    glTranslated(.187, .02, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.45, -.7);
    glVertex2f(-.43, -.55);
    glEnd();

    glTranslated(.15, .0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.45, -.7);
    glVertex2f(-.45, -.55);
    glEnd();

    glTranslated(.2, .0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.486, -.73); glVertex2f(-.46, -.7);
    glVertex2f(-.44, -.55);
    glEnd();

    glTranslated(.12, .04, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.46, -.7);
    glVertex2f(-.52, -.55);
    glEnd();

    glTranslated(.11, .0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.46, -.7);
    glVertex2f(-.46, -.55);
    glEnd();

    glTranslated(.07, -.05, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.46, -.7);
    glVertex2f(-.46, -.58);
    glEnd();

    glTranslated(.115, .02, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.5, -.7); glVertex2f(-.48, -.73); glVertex2f(-.46, -.7);
    glVertex2f(-.5, -.58);
    glEnd();

    glTranslated(.058, .02, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.48, -.7); glVertex2f(-.48, -.73); glVertex2f(-.44, -.7);
    glVertex2f(-.4, -.55);
    glEnd();

    glTranslated(.132, .02, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.48, -.7); glVertex2f(-.48, -.73); glVertex2f(-.44, -.7);
    glVertex2f(-.4, -.57);
    glEnd();

    glTranslated(.148, .0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-.48, -.7); glVertex2f(-.48, -.73); glVertex2f(-.44, -.7);
    glVertex2f(-.4, -.55);
    glEnd();

    glLoadIdentity();
}
void river() {
    ///////////white   //Flower
    glScalef(0.25, .2, 0);
    glTranslated(2., .86, 0);
    whiteFlower();
    glLoadIdentity();


    glBegin(GL_QUADS);
    glColor3ub(150, 201, 38);
    glVertex2f(-1, -.00);
    glVertex2f(1, -.00);
    glVertex2f(1, -.01);
    glVertex2f(-1, -.01);
    glColor3ub(43, 155, 207);
    glVertex2f(-1, -.01);
    glVertex2f(1, -.01);
    glVertex2f(1, -.1);
    glVertex2f(-1, -.1);
    glEnd();

    glColor3ub(109, 170, 199);
    glLineWidth(.05);
    line(-0.85, -.06, -0.95, -.06);
    line(-0.5, -.035, -.56, -.035);
    line(0.0, -.06, -0.1, -.06);
    line(0.8, -.03, 0.9, -.03);


}
void longGrass() {
    /////////// long grass
    glScalef(0.24, .2, 0);
    glTranslated(0.8, .49, 0);
    glColor3ub(68, 173, 47);
    triangle(-.5, -1.0, -.45, -1.0, -.35, -.65);
    triangle(-.5, -1.0, -.45, -1.0, -.6, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.35, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.0, -.65);
    triangle(-.45, -1.0, -.4, -1.0, -.2, -.65);
    triangle(.15, -1.0, .2, -1.0, .35, -.65);
    triangle(.15, -1.0, .2, -1.0, .05, -.65);
    triangle(.45, -1.0, .5, -1.0, .35, -.65);
    triangle(.55, -1.0, .6, -1.0, .55, -.65);
    triangle(.6, -1.0, .65, -1.0, .8, -.65);
    triangle(.85, -1.0, .9, -1.0, 1.0, -.65);
    glLoadIdentity();
    glScalef(0.25, .2, 0);
    glTranslated(0.0, .49, 0);
    glColor3ub(68, 173, 47);
    triangle(-.5, -1.0, -.45, -1.0, -.35, -.65);
    triangle(-.5, -1.0, -.45, -1.0, -.6, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.35, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.0, -.65);
    triangle(-.45, -1.0, -.4, -1.0, -.2, -.65);
    triangle(.15, -1.0, .2, -1.0, .35, -.65);
    triangle(.15, -1.0, .2, -1.0, .05, -.65);
    triangle(.45, -1.0, .5, -1.0, .35, -.65);
    triangle(.55, -1.0, .6, -1.0, .55, -.65);
    triangle(.6, -1.0, .65, -1.0, .8, -.65);
    triangle(.85, -1.0, .9, -1.0, 1.0, -.65);
    glLoadIdentity();

    glScalef(0.25, .2, 0);
    glTranslated(-2.5, .49, 0);
    glColor3ub(68, 173, 47);
    triangle(-.5, -1.0, -.45, -1.0, -.35, -.65);
    triangle(-.5, -1.0, -.45, -1.0, -.6, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.35, -.65);
    triangle(-.2, -1.0, -.15, -1.0, -.0, -.65);
    triangle(-.45, -1.0, -.4, -1.0, -.2, -.65);
    triangle(.15, -1.0, .2, -1.0, .35, -.65);
    triangle(.15, -1.0, .2, -1.0, .05, -.65);
    triangle(.45, -1.0, .5, -1.0, .35, -.65);
    triangle(.55, -1.0, .6, -1.0, .55, -.65);
    triangle(.6, -1.0, .65, -1.0, .8, -.65);
    triangle(.85, -1.0, .9, -1.0, 1.0, -.65);
    glLoadIdentity();
}
void boat() {
    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3ub(145, 89, 58);
    glVertex2f(-.01, -.04);glVertex2f(-.01, .3);
    glVertex2f(-.1, -.04);glVertex2f(-.01, .28);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 25, 0);
    glVertex2f(-.01, .28);
    glVertex2f(-.01, -.0);
    glVertex2f(.14, -.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 185, 0);
    glVertex2f(-.12, -.03);
    glVertex2f(-.1, -.06);
    glVertex2f(.1, -.06);
    glVertex2f(.12, -.03);
    glEnd();

}
void cloud() {


    circle(.625, .58, .05);
    circle(.7, .6, .08);
    circle(.79, .582, .06);
    circle(.85, .58, .04);

    //CLOUD LEFT

    circle(-.425, .585, .04);
    circle(-.5, .6, .07);
    circle(-.59, .592, .05);
    circle(-.64, .58, .03);
}
void ground() {
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();
}
void field() {
    triangle(-.5, -.2, 1, -.4, 1, -.1);
    triangle(-1, -.4, -1, -.7, 0, -.5);
}
void treeLeaf() {
    //right big
    glColor3ub(41, 140, 42);
    circle(-0.36, -0.02, .22);

    //right small
    glColor3ub(95, 168, 47);
    circle(-0.4, -0.3f, .13);

    //left small
    glColor3ub(30, 74, 34);
    circle(-0.895, -0.13, .15);

    //left big
    glColor3ub(41, 140, 42);
    circle(-0.77, 0.07, .2);

    //mid
    glColor3ub(105, 184, 53);
    circle(-0.54, 0.1, .22);
}
void roadGrass() {
    //left
    circle(0.1, .005, .07);
    circle(0.2, .002, .04);
    //grass2 road right
    circle(0.8, .005, .035);
    circle(0.88, .005, .065);
}
void roadFlower() {
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.014, .025, .013);
    circle(0.0015, .005, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);

    glTranslated(.12, .03, 0);
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.0015, .005, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);

    glLoadIdentity();

    glTranslated(.87, .02, 0);
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.014, .025, .013);
    circle(0.0015, .005, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);
    glLoadIdentity();
}
void rainCloud() {

    circle(-2.03, .95, .1);

    circle(-1.84, .93, .15);
    circle(-1.54, .93, .18);
    circle(-1.28, .93, .15);
    circle(-1.0, .93, .17);

    circle(-.93, .95, .1);
    circle(-.72, .93, .15);
    circle(-.5, .93, .18);
    circle(-.28, .93, .15);
    circle(0.0, .95, .17);
    circle(.2, .93, .15);
    circle(.43, .93, .2);
    circle(.65, .93, .13);
    circle(.8, .95, .15);
    circle(.95, .95, .08);
}
void rain() {
    glBegin(GL_LINES);

    glVertex2f(-.85, 1.9);glVertex2f(-.8, 1.8);
    glVertex2f(-.55, 1.9);glVertex2f(-.5, 1.8);
    glVertex2f(-.25, 1.9);glVertex2f(-.2, 1.8);
    glVertex2f(.05, 1.9);glVertex2f(.1, 1.8);
    glVertex2f(.35, 1.9);glVertex2f(.4, 1.8);
    glVertex2f(.65, 1.9);glVertex2f(.7, 1.8);
    glVertex2f(.95, 1.9);glVertex2f(1.0, 1.8);

    glVertex2f(-1.0, 1.6);glVertex2f(-.95, 1.5);
    glVertex2f(-.7, 1.6);glVertex2f(-.65, 1.5);
    glVertex2f(-.4, 1.6);glVertex2f(-.35, 1.5);
    glVertex2f(-.1, 1.6);glVertex2f(-.05, 1.5);
    glVertex2f(.2, 1.6);glVertex2f(.25, 1.5);
    glVertex2f(.5, 1.6);glVertex2f(.55, 1.5);
    glVertex2f(.8, 1.6);glVertex2f(.85, 1.5);


    glVertex2f(-.85, 1.3);glVertex2f(-.8, 1.2);
    glVertex2f(-.55, 1.3);glVertex2f(-.5, 1.2);
    glVertex2f(-.25, 1.3);glVertex2f(-.2, 1.2);
    glVertex2f(.05, 1.3);glVertex2f(.1, 1.2);
    glVertex2f(.35, 1.3);glVertex2f(.4, 1.2);
    glVertex2f(.65, 1.3);glVertex2f(.7, 1.2);
    glVertex2f(.95, 1.3);glVertex2f(1.0, 1.2);

    glVertex2f(-1.0, 1.0);glVertex2f(-.95, .9);
    glVertex2f(-.7, 1.0);glVertex2f(-.65, 0.9);
    glVertex2f(-.4, 1.0);glVertex2f(-.35, 0.9);
    glVertex2f(-.1, 1.0);glVertex2f(-.05, 0.9);
    glVertex2f(.2, 1.0);glVertex2f(.25, .9);
    glVertex2f(.5, 1.0);glVertex2f(.55, 0.9);
    glVertex2f(.8, 1.0);glVertex2f(.85, 0.9);



    glVertex2f(-.85, .7);glVertex2f(-.8, .6);
    glVertex2f(-.55, .7);glVertex2f(-.5, 0.6);
    glVertex2f(-.25, .7);glVertex2f(-.2, 0.6);
    glVertex2f(.05, .7);glVertex2f(.1, .6);
    glVertex2f(.35, .7);glVertex2f(.4, .6);
    glVertex2f(.65, .7);glVertex2f(.7, .6);
    glVertex2f(.95, .7);glVertex2f(1.0, .6);

    glVertex2f(-1.0, .4);glVertex2f(-.95, .3);
    glVertex2f(-.7, .4);glVertex2f(-.65, 0.3);
    glVertex2f(-.4, .4);glVertex2f(-.35, 0.3);
    glVertex2f(-.1, .4);glVertex2f(-.05, 0.3);
    glVertex2f(.2, .4);glVertex2f(.25, .3);
    glVertex2f(.5, .4);glVertex2f(.55, 0.3);
    glVertex2f(.8, .40);glVertex2f(.85, 0.3);

    glVertex2f(-.85, .1);glVertex2f(-.8, 0.0);
    glVertex2f(-.55, .1);glVertex2f(-.5, 0.0);
    glVertex2f(-.25, .1);glVertex2f(-.2, 0.0);
    glVertex2f(.05, .1);glVertex2f(.1, .0);
    glVertex2f(.35, .1);glVertex2f(.4, .0);
    glVertex2f(.65, .1);glVertex2f(.7, .0);
    glVertex2f(.95, .1);glVertex2f(1.0, .0);


    glVertex2f(-1.0, -.2);glVertex2f(-.95, -.3);
    glVertex2f(-.7, -.2);glVertex2f(-.65, -0.3);
    glVertex2f(-.4, -.2);glVertex2f(-.35, -0.3);
    glVertex2f(-.1, -.2);glVertex2f(-.05, -0.3);
    glVertex2f(.2, -.2);glVertex2f(.25, -.3);
    glVertex2f(.5, -.2);glVertex2f(.55, -.3);
    glVertex2f(.8, -.2);glVertex2f(.85, -.3);

    glVertex2f(-.85, -.5);glVertex2f(-.8, -.6);
    glVertex2f(-.55, -.5);glVertex2f(-.5, -.6);
    glVertex2f(-.25, -.5);glVertex2f(-.2, -.6);
    glVertex2f(.05, -.5);glVertex2f(.1, -.6);
    glVertex2f(.35, -.5);glVertex2f(.4, -.6);
    glVertex2f(.65, -.5);glVertex2f(.7, -.6);
    glVertex2f(.95, -.5);glVertex2f(1.0, -.6);

    glVertex2f(-1.0, -.8);glVertex2f(-.95, -.9);
    glVertex2f(-.7, -.8);glVertex2f(-.65, -0.9);
    glVertex2f(-.4, -.8);glVertex2f(-.35, -0.9);
    glVertex2f(-.1, -.8);glVertex2f(-.05, -0.9);
    glVertex2f(.2, -.8);glVertex2f(.25, -.9);
    glVertex2f(.5, -.8);glVertex2f(.55, -.9);
    glVertex2f(.8, -.8);glVertex2f(.85, -.9);

    glVertex2f(-.85, -1.1);glVertex2f(-.8, -1.2);
    glVertex2f(-.55, -1.1);glVertex2f(-.5, -1.2);
    glVertex2f(-.25, -1.1);glVertex2f(-.2, -1.2);
    glVertex2f(.05, -1.1);glVertex2f(.1, -1.2);
    glVertex2f(.35, -1.1);glVertex2f(.4, -1.2);
    glVertex2f(.65, -1.1);glVertex2f(.7, -1.2);
    glVertex2f(.95, -1.1);glVertex2f(1.0, -1.2);

    glVertex2f(-1.0, -1.4);glVertex2f(-.95, -1.5);
    glVertex2f(-.7, -1.4);glVertex2f(-.65, -1.5);
    glVertex2f(-.4, -1.4);glVertex2f(-.35, -1.5);
    glVertex2f(-.1, -1.4);glVertex2f(-.05, -1.5);
    glVertex2f(.2, -1.4);glVertex2f(.25, -1.5);
    glVertex2f(.5, -1.4);glVertex2f(.55, -1.5);
    glVertex2f(.8, -1.4);glVertex2f(.85, -1.5);


    glEnd();
}
void springFlower() {
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.014, .025, .013);
    circle(0.0015, .005, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);
}









///////////////////////////////////DISPLY FUNCTION////////////////////
void summer();
void summer_rain();
void rainDay();
void rain_autumn();
void autumn();
void midAutumn();
void lateAutumn();
void earlyWinter();
void winter();
void winter_spring();
void spring();









void Idle()
{
    glutPostRedisplay();
}



void display_summer_rain(int b)
{
    glutDisplayFunc(summer_rain);


}

void display_rainyDay(int b)
{
    glutDisplayFunc(rainDay);

}

void display_rain_autumn(int b)
{
    glutDisplayFunc(rain_autumn);
}

void display_autumn(int b)
{
    glutDisplayFunc(autumn);
}

void display_midAutumn(int b)
{
    glutDisplayFunc(midAutumn);
}

void display_lateAutumn(int b)
{
    glutDisplayFunc(lateAutumn);
}

void display_earlyWinter(int b)
{
    glutDisplayFunc(earlyWinter);
}

void display_winter(int b)
{
    glutDisplayFunc(winter);
}

void display_winter_spring(int b)
{
    glutDisplayFunc(winter_spring);
}

void display_spring(int b)
{
    glutDisplayFunc(spring);
}


///////////////////////////////////////SUMMER/////////////////////////////////////////////////////
void summer() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




    ///////sky
    glColor3ub(148, 208, 242);
    sky();
    /////mountain
    mountain();

    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();


    ///////sun
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);


    /////////ground
    glColor3ub(150, 201, 38);
    ground();
    /////////field
    glColor3ub(178, 227, 79);
    field();




    ///////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();
    roadFlower();




    /////////river
    river();
    ////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);

    boat();
    glPopMatrix();
    glLoadIdentity();
    /////////long Grass///// downside river
    longGrass();

    ////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();

    //////// house
    glColor3ub(41, 140, 42);
    house();
    //////////tree leaf
    treeLeaf();
    /////////tree
    tree();
    /////////down garss
    downGrass();
    ////////flower down
    downFlower();


    glutTimerFunc(20000, display_summer_rain, 0);
    Idle();
    glFlush();
}



///////////////////////////////////////SUMMER_RAIN////////////////////////////////////////////////////////////
void summer_rain() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ////////sky
    glColor3ub(153, 197, 222);
    sky();
    ////////mountain
    mountain();

    ////////sun
    glPushMatrix();
    glTranslatef(0.0f, sunP, 0.0f);
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);
    glPopMatrix();
    glLoadIdentity();


    ///////Rain cloud
    glColor3ub(175, 182, 186);
    glPushMatrix();
    glTranslatef(RcloudP, 0.0f, 0.0f);
    rainCloud();
    glPopMatrix();
    glLoadIdentity();




    /////////ground
    glColor3ub(150, 201, 38);
    ground();
    /////////filed
    glColor3ub(178, 227, 79);
    field();
    //////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();
    roadFlower();
    //////////river
    river();
    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();

    /////////long Grass///// downside river
    longGrass();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();
    //////// house
    glColor3ub(47, 158, 68);
    house();


    ////////////////////tree leaf
    treeLeaf();
    tree();

    //////////////down garss
    downGrass();
    downFlower();


    glutTimerFunc(20000, display_rainyDay, 0);
    Idle();
    glFlush();


}



///////////////////////////////////////RAINY_DAY////////////////////////////////////////////////////////////
void rainDay() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ////////sky
    glColor3ub(147, 185, 201);
    sky();
    ////////mountain
    mountain();

    ///////Rain cloud
    glColor3ub(158, 161, 163);
    glPushMatrix();
    glTranslatef(RcloudP, 0.0f, 0.0f);
    rainCloud();
    glPopMatrix();
    glLoadIdentity();


    /////////ground
    glColor3ub(130, 179, 82);
    ground();
    /////////filed
    glColor3ub(162, 201, 83);
    field();
    //////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();
    roadFlower();
    //////////river
    river();
    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();

    /////////long Grass///// downside river
    longGrass();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();
    //////// house
    glColor3ub(47, 158, 68);
    house();


    ////////////////////tree leaf
    treeLeaf();
    tree();

    //////////////down garss
    downGrass();
    downFlower();



    ///////////////////rain();

    glPushMatrix();
    glTranslatef(0.0f, rainP, 0.0f);
    glColor3ub(210, 226, 247);
    glLineWidth(2);

    rain();
    glPopMatrix();
    glLoadIdentity();
    thander();


    glutTimerFunc(20000, display_rain_autumn, 0);
    Idle();
    glFlush();


}




///////////////////////////////////////RAIN_AUTUMN//////////////////////////////////////////////////////////
void rain_autumn() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    ////////sky
    glColor3ub(149, 199, 219);
    sky();
    ////////mountain
    mountain();

    //////cloud
    glColor3ub(228, 235, 230);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();

    /////////ground
    glColor3ub(142, 189, 38);
    ground();
    /////////filed
    glColor3ub(167, 214, 71);
    field();
    //////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();



    //////////river
    river();
    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();

    /////////long Grass///// downside river
    longGrass();

    /////////////whiteFlower
    glScalef(0.25, .2, 0);
    glTranslated(.75, .5, 0);
    whiteFlower();
    glLoadIdentity();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();
    //////// house
    glScalef(1.0, 1.5, 0);
    glTranslated(.2, -.130, 0);
    longGrass();
    glLoadIdentity();

    glColor3ub(47, 158, 68);
    house();


    ////////////////////tree leaf
    treeLeaf();
    tree();

    /////////flower
    whiteFlower();

    glLoadIdentity();



    ////////////////down garss
    downGrass();
    /////////// downFlower();
    downFlower3();


    glutTimerFunc(20000, display_autumn, 0);

    Idle();
    glFlush();

}




///////////////////////////////////////AUTUMN///////////////////////////////////////////////////////////
void autumn() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ////////sky
    glColor3ub(136, 190, 247);
    sky();
    ////////mountain
    mountain();

    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();


    /////////ground
    glColor3ub(150, 201, 38);
    ground();
    /////////filed
    glColor3ub(178, 227, 79);
    field();
    //////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();

    /////////////RIVER SIDE Flower

    glScalef(0.25, .2, 0);
    glTranslated(-.2, .85, 0);
    whiteFlower();
    glLoadIdentity();

    glScalef(0.25, .2, 0);
    glTranslated(.10, .85, 0);
    whiteFlower();
    glLoadIdentity();

    glScalef(0.25, .2, 0);
    glTranslated(.80, .85, 0);
    whiteFlower();
    glLoadIdentity();

    glScalef(0.25, .2, 0);
    glTranslated(2.5, .86, 0);
    whiteFlower();
    glLoadIdentity();

    glScalef(0.25, .2, 0);
    glTranslated(2.9, .86, 0);
    whiteFlower();
    glLoadIdentity();



    //////////river
    river();

    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();


    ///////////   //Flower
    glScalef(0.24, .2, 0);
    glTranslated(0.8, .49, 0);
    whiteFlower();
    glLoadIdentity();
    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();




    //////white flower
    glScalef(0.35, .35, 0);
    glTranslated(1.10, .00, 0);
    whiteFlower();
    glLoadIdentity();

    //////// house
    glColor3ub(47, 158, 68);
    house();



    ////////////////////tree leaf
    treeLeaf();
    tree();




    /////////////white flower
    glScalef(1.3, 1.0, 0);
    glTranslated(-.20, 0.1, 0);
    whiteFlower();
    glLoadIdentity();

    glScalef(1.20, 1., 0);
    glTranslated(.05, .08, 0);
    whiteFlower();
    glLoadIdentity();




    //////////////down garss
    downGrass();

    glutTimerFunc(20000, display_midAutumn, 0);
    glFlush();
    Idle();

}




////////////////////////////////////////MID_AUTUMN///////////////////////////////////////////////////////
void midAutumn() {



    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    ////////sky
    glColor3ub(121, 203, 247);
    sky();
    ////////mountain
    mountain();

    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();


    ///////sun
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);


    /////////ground
    glColor3ub(162, 194, 48);
    ground();
    /////////filed
    glColor3ub(202, 212, 74);
    field();
    //////////grass road
    glColor3ub(114, 176, 42);
    roadGrass();

    //////////river
    river();

    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();
    ///////////   //Flower
    glScalef(0.24, .2, 0);
    glTranslated(0.8, .49, 0);
    whiteFlower();
    glLoadIdentity();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();
    //////// house
    glColor3ub(114, 176, 42);
    house();



    ////////////////////tree leaf
    glColor3ub(138, 163, 54);
    circle(-0.36, -0.02, .18);
    glColor3ub(159, 173, 50);
    circle(-0.4, -0.3f, .08);
    glColor3ub(99, 112, 39);
    circle(-0.895, -0.13, .11);
    glColor3ub(138, 163, 54);
    circle(-0.77, 0.07, .16);
    glColor3ub(176, 191, 57);
    circle(-0.54, 0.1, .18);
    ///////////////////tree
    tree();


    ///////////////////down long grass

    /////////////white flower

    glPushMatrix();
    glTranslatef(0.0f, flowerP, 0.0f);
    glScalef(1.3, 1.0, 0);
    glTranslated(-.20, 0.1, 0);
    whiteFlower();
    glLoadIdentity();


    glPopMatrix();
    glLoadIdentity();


    ////////////////down garss
    downGrass();

    glutTimerFunc(20000, display_lateAutumn, 0);
    glFlush();
    Idle();

}




///////////////////////////////////////LATE_AUTUMN/////////////////////////////////////////////////////
void lateAutumn() {



    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    ////////sky
    glColor3ub(95, 237, 199);
    sky();
    ////////mountain
    mountain();

    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();


    ///////sun
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);



    /////////ground
    glColor3ub(192, 219, 39);
    ground();
    /////////filed
    glColor3ub(209, 237, 52);
    field();


    //////////grass road
    glColor3ub(141, 212, 59);
    roadGrass();

    //////////river
    river();

    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();


    //////// house
    glColor3ub(141, 212, 59);
    house();


    ////////////////////tree leaf
            //right big///4
    //1
    glPushMatrix();
    glTranslatef(0.0f, treeP3, 0.0f);
    glColor3ub(138, 163, 54);
    circle(-0.36, -0.05, .13);
    glPopMatrix();
    glLoadIdentity();


    //right small////1
    glPushMatrix();
    glTranslatef(0.0f, treeP2, 0.0f);
    glColor3ub(159, 173, 50);
    circle(-0.4, -0.3f, .08);
    glPopMatrix();
    glLoadIdentity();



    //left small///
    glPushMatrix();
    glTranslatef(0.0f, treeP1, 0.0f);
    glColor3ub(99, 112, 39);
    circle(-0.895, -0.13, .08);
    glPopMatrix();
    glLoadIdentity();

    //left big/////3
    glPushMatrix();
    glTranslatef(0.0f, treeP4, 0.0f);
    glColor3ub(138, 163, 54);

    circle(-0.77, 0.07, .15);
    glPopMatrix();
    glLoadIdentity();



    //mid////////2
    glPushMatrix();
    glTranslatef(0.0f, treeP5, 0.0f);
    glColor3ub(176, 191, 57);
    circle(-0.54, 0.1, .16);
    glPopMatrix();
    glLoadIdentity();



    ///////////////////tree
    tree();

    ////////////////down garss
    downGrass();


    glutTimerFunc(20000, display_earlyWinter, 0);
    glFlush();
    Idle();
}




//////////////////////////////////////////EARLY_WINTER///////////////////////////////////////////////////////
void earlyWinter() {



    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    ////////sky
    glColor3ub(147, 217, 215);
    sky();
    ////////mountain
    mountain();

    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();


    ////////sun
    glPushMatrix();
    glTranslatef(0.0f, sunP2, 0.0f);
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);
    glPopMatrix();
    glLoadIdentity();


    /////////ground
    glColor3ub(162, 194, 48);
    ground();
    /////////filed
    glColor3ub(202, 212, 74);
    field();
    //////////grass road
    glColor3ub(114, 176, 42);
    roadGrass();


    //////////river
    river();

    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();

    //////// house
    glColor3ub(114, 176, 42);
    house();

    ///////////////////tree
    tree();


    ////////////////down garss
    downGrass();

    ////////  snow
    glPushMatrix();
    glTranslated(0.0f, snowP, 0.0f);
    glColor3ub(255, 255, 255);

    snowball();
    glTranslated(0.2, -0.5, 0);snowball();
    glTranslated(-0.1, -0.45, 0);snowball();
    glTranslated(0.0, -0.5, 0);snowball();
    glTranslated(0.2, -0.5, 0);snowball();
    glTranslated(-0.1, -0.5, 0);snowball();

    glLoadIdentity();
    glPopMatrix();
    glLoadIdentity();



    glutTimerFunc(20000, display_winter, 0);
    glFlush();
    Idle();

}



/////////////////////////////////////////////WINTER///////////////////////////////////////////////////////////////////////
void winter() {




    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    ////////sky
    glColor3ub(202, 237, 236);
    sky();

    ////////mountain
    mountain();

    ///////mountain snow
    ////main
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.25, .45);
    glVertex2f(.1, .43);
    glVertex2f(-.142, .2);
    glVertex2f(.04, .28);
    glVertex2f(.07, .18);
    glVertex2f(.17, .28);
    glVertex2f(.28, .15);
    glVertex2f(.35, .26);
    glVertex2f(.585, .15);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.9, .12);
    glVertex2f(-1.0, .06);
    glVertex2f(-.95, .05);
    glVertex2f(-.89, .075);
    glVertex2f(-.82, .06);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.55, .15);
    glVertex2f(-.67, .08);
    glVertex2f(-.65, .05);
    glVertex2f(-.55, .08);
    glVertex2f(-.4, .06);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.2, .23);
    glVertex2f(-.356, .09);
    glVertex2f(-.3, .07);
    glVertex2f(-.2, .1);
    glVertex2f(-.1, .07);
    glVertex2f(-.03, .1);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.8, .22);
    glVertex2f(.68, .12);
    glVertex2f(.71, .085);
    glVertex2f(.78, .11);
    glVertex2f(.85, .08);
    glVertex2f(.9, .11);
    glVertex2f(.98, .09);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.1, .12);
    glVertex2f(.0, .06);
    glVertex2f(.05, .05);
    glVertex2f(.22, .05);
    glEnd();


    /////////ground
    glColor3ub(164, 199, 95);
    ground();
    /////////filed
    glColor3ub(209, 232, 172);
    field();
    //////////grass road
    glColor3ub(75, 166, 55);
    roadGrass();
    //////////flower
    glTranslated(.12, .03, 0);
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.0015, .005, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);
    glLoadIdentity();


    //river
    glBegin(GL_QUADS);
    glColor3ub(150, 201, 38);
    glVertex2f(-1, -.00);
    glVertex2f(1, -.00);
    glVertex2f(1, -.01);
    glVertex2f(-1, -.01);
    glColor3ub(177, 211, 227);
    glVertex2f(-1, -.01);
    glVertex2f(1, -.01);
    glVertex2f(1, -.1);
    glVertex2f(-1, -.1);
    glEnd();

    glColor3ub(211, 229, 237);
    glLineWidth(.05);
    line(-0.85, -.06, -0.95, -.06);
    line(-0.5, -.035, -.56, -.035);
    line(0.0, -.06, -0.1, -.06);
    line(0.8, -.03, 0.9, -.03);


    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();
    //////// house
    glColor3ub(75, 166, 55);
    house();


    ///////////////house snow
    glScalef(1.2, 1.2, 0);
    glTranslated(.05, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.39, -.05);
    glVertex2f(.375, -.13);
    glVertex2f(.43, -.14);
    glVertex2f(.46, -.17);
    glVertex2f(.5, -.1);
    glVertex2f(.53, -.13);
    glVertex2f(.725, -.13);
    glVertex2f(.71, -.05);

    glEnd();
    glLoadIdentity();

    ///////////////////tree

    tree();



    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.89, -.12);
    glVertex2f(-.895, -.125);
    glVertex2f(-.85, -.15);
    glVertex2f(-.785, -.14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);


    glVertex2f(-.78, .02);
    glVertex2f(-.8, .022);
    glVertex2f(-.75, -.08);
    glVertex2f(-.75, -.1);
    glVertex2f(-.695, -.145);
    glEnd();

    glTranslated(-.65, -.5, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.1, .49);
    glVertex2f(.087, .475);
    glVertex2f(.055, .35);
    glVertex2f(.1, .43);
    glEnd();
    glLoadIdentity();
    // glTranslated(-.65,-.5,0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.4, -.1);
    glVertex2f(-.34, -.09);
    glVertex2f(-.5, -.14);
    glVertex2f(-.45, -.15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.39, -.28);
    glVertex2f(-.48, -.235);
    glVertex2f(-.45, -.27);

    glEnd();
    glLoadIdentity();


    /////////////down garss
    downGrass();

    //  snow
    glPushMatrix();
    glTranslated(0.0f, snowP, 0.0f);
    glColor3ub(255, 255, 255);
    snowball();
    glTranslated(0.2, -0.5, 0);snowball();
    glTranslated(-0.1, -0.45, 0);snowball();
    glTranslated(0.0, -0.5, 0);snowball();
    glTranslated(0.2, -0.5, 0);snowball();
    glTranslated(-0.1, -0.5, 0);snowball();glLoadIdentity();
    glTranslated(0.2, 1.0, 0);snowball();
    glTranslated(0.2, .2, 0);snowball();
    glTranslated(-0.1, 0.3, 0);snowball();
    glTranslated(0.2, .4, 0);snowball();
    //glTranslated(-0.1,.1,0);snowball();
    glLoadIdentity();



    glPopMatrix();
    glLoadIdentity();




    glutTimerFunc(20000, display_winter_spring, 0);
    glFlush();
    Idle();
}




/////////////////////////////////////////////WINTER_SPRING///////////////////////////////////////////////////////////////////////
void winter_spring() {




    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    ////////sky
    glColor3ub(145, 213, 250);
    sky();


    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();


    ///////sun
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);



    ////////mountain
    mountain();
    ////////mountain snow
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.9, .12);
    glVertex2f(-0.95, .09);
    glVertex2f(-.93, .08);
    glVertex2f(-.89, .09);
    glVertex2f(-.86, .09);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.55, .15);
    glVertex2f(-.6, .12);
    glVertex2f(-.595, .11);
    glVertex2f(-.5, .12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.2, .23);
    glVertex2f(-.264, .18);
    glVertex2f(-.2395, .18);
    glVertex2f(-.145, .19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.8, .22);
    glVertex2f(.76, .19);
    glVertex2f(.78, .18);
    glVertex2f(.845, .19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.1, .12);
    glVertex2f(.05, .09);
    glVertex2f(.08, .08);
    glVertex2f(.15, .09);
    glEnd();


    /////////ground
    glColor3ub(139, 201, 77);
    ground();
    /////////filed
    glColor3ub(169, 217, 93);
    field();


    //////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();
    roadFlower();


    //////////river
    river();

    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();

    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();

    //////// house
    glColor3ub(75, 166, 55);
    house();

    ///////////////house snow
    glScalef(1.2, 1.2, 0);
    glTranslated(.05, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.39, -.05);
    glVertex2f(.385, -.07);
    glVertex2f(.43, -.07);
    glVertex2f(.46, -.09);
    glVertex2f(.5, -.07);
    glVertex2f(.53, -.07);
    glVertex2f(.715, -.07);
    glVertex2f(.71, -.05);

    glEnd();
    glLoadIdentity();



    ////////////////////tree leaf
            //right big
    glColor3ub(41, 140, 42);
    circle(-0.35, -0.1, .09);
    ////left big
    circle(-0.79, 0.04, .09);
    //right small
    glColor3ub(78, 186, 28);
    circle(-0.4, -0.28f, .06);
    //mid
    circle(-0.55, .02, .1);
    //left small
    glColor3ub(62, 186, 28);
    circle(-0.895, -0.13, .06);

    //////////tree
    tree();



    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.89, -.12);
    glVertex2f(-.895, -.125);
    glVertex2f(-.85, -.15);
    glVertex2f(-.785, -.14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);


    glVertex2f(-.78, .02);
    glVertex2f(-.8, .022);
    glVertex2f(-.75, -.08);
    glVertex2f(-.75, -.1);
    glVertex2f(-.695, -.145);
    glEnd();
    glTranslated(-.65, -.5, 0);


    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(.1, .49);
    glVertex2f(.087, .475);
    glVertex2f(.055, .35);
    glVertex2f(.1, .43);
    glEnd();
    glLoadIdentity();
    // glTranslated(-.65,-.5,0);

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.4, -.1);
    glVertex2f(-.34, -.09);
    glVertex2f(-.5, -.14);
    glVertex2f(-.45, -.15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-.39, -.28);
    glVertex2f(-.48, -.235);
    glVertex2f(-.45, -.27);

    glEnd();
    glLoadIdentity();


    ////////////////down garss
    downGrass();
    glLoadIdentity();

    //////////////flower
    downFlower();



    glutTimerFunc(20000, display_spring, 0);
    Idle();
    glFlush();

}




////////////////////////////////////////////////////////SPRING////////////////////////////////////////////////////////
void spring() {


    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    ////////sky
    glColor3ub(132, 209, 250);
    sky();

    ////////mountain
    mountain();

    //////cloud
    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();
    ///////sun
    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    ////sun cloud
    glColor3ub(242, 245, 243);
    circle(-.08, .7, .04);
    circle(-.00, .71, .07);
    circle(0.09, .71, .05);
    /////////ground
    glColor3ub(120, 201, 38);
    ground();
    /////////filed
    glColor3ub(161, 219, 70);
    field();
    //////////grass road
    glColor3ub(47, 158, 68);
    roadGrass();
    roadFlower();
    //////////river
    river();
    //////////boat
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    //////////long grass
    longGrass();
    ///////////////////////windmill
    glScalef(0.7, 0.7, 0);
    glTranslated(0.9, 0.2, 0);
    windmill();
    glLoadIdentity();
    //////// house
    glColor3ub(75, 166, 55);
    house();
    glLoadIdentity();

    ////////////////////tree leaf
            //right big
    glColor3ub(41, 140, 42);
    circle(-0.36, -0.05, .13);
    //left big
    circle(-0.77, 0.07, .15);
    //right small
    glColor3ub(78, 186, 28);
    circle(-0.4, -0.3f, .08);
    //mid
    circle(-0.54, 0.1, .16);
    //left small
    glColor3ub(62, 186, 28);
    circle(-0.895, -0.13, .08);

    ///////////////////tree
    tree();


    ///////////////spring flower
    glTranslated(-0.3, -0.05, 0.0);
    springFlower();
    glLoadIdentity();

    glTranslated(-0.34, -0.03, 0.0);
    springFlower();
    glLoadIdentity();


    glTranslated(-0.6, 0.15, 0.0);
    springFlower();
    glLoadIdentity();

    glTranslated(-0.56, 0.19, 0.0);
    springFlower();
    glLoadIdentity();

    glTranslated(-0.54, 0.13, 0.0);
    springFlower();
    glLoadIdentity();


    glTranslated(-0.85, 0.11, 0.0);
    springFlower();
    glLoadIdentity();

    glTranslated(-0.87, 0.07, 0.0);
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.0015, .005, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);
    glLoadIdentity();

    glTranslated(-0.37, -0.3, 0.0);
    glColor3ub(247, 183, 225);
    circle(0.025, .006, .013);
    circle(0.014, .025, .013);
    glColor3ub(255, 3, 3);
    circle(0.012, .012, .01);
    glLoadIdentity();




    ////////////////down garss
    downGrass();
    ///////////////flower down
    downFlower();

    //glutTimerFunc(20000,display_summer_rain,0);
    Idle();
    glFlush();

}








void SpecialInput(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_UP:

        break;
    case GLUT_KEY_DOWN:


        break;
    case GLUT_KEY_LEFT:
        boatS = 0.025f;

        break;
    case GLUT_KEY_RIGHT:
        boatS = 0.01f;


        break;
    }
    glutPostRedisplay();
}



void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {
        cloudS = 0.0f;
        RcloudS = 0.0f;

    }

    if (button == GLUT_RIGHT_BUTTON)
    {
        cloudS = 0.02f;
        RcloudS = 0.03f;
    }



    glutPostRedisplay();
}



int currentSeason = 0; // 0=summer, 1=summer_rain, 2=rainDay, 3=rain_autumn, 
// 4=autumn, 5=midAutumn, 6=lateAutumn, 7=earlyWinter, 
// 8=winter, 9=winter_spring, 10=spring
bool showInstructions = true;


void displayInstructions() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up orthographic projection for text rendering
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 700);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0, 0, 0);
   

    // Draw title and project information
    glColor3f(1, 1, 1);
    glRasterPos2f(150, 650);
    const char* title = "SEASON SIMULATION - COMPUTER GRAPHICS PROJECT";
    for (const char* c = title; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    // University information
    glColor3f(1, 1, 1);
    glRasterPos2f(250, 600);
    const char* project = "Thapar Institute of Engineering and Technology";
    for (const char* c = project; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }


    glColor3f(1, 1, 1); // White text
    glRasterPos2f(300, 550);
    const char* teamHeader = "TEAM MEMBERS";
    for (const char* c = teamHeader; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    // Team member names with student IDs 
    glRasterPos2f(120, 500);
    const char* member1 = "1. Riddhi [102203598]";
    for (const char* c = member1; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(120, 470);
    const char* member2 = "2. Kashika [102203492]";
    for (const char* c = member2; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(120, 440);
    const char* member3 = "3. Navreet [102203546]";
    for (const char* c = member3; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    // Submitted to section
    glColor3f(1, 1, 1); 
    glRasterPos2f(300, 400);
    const char* submittedTo = "Submitted to: Dr. Kuntal Chaudhry";
    for (const char* c = submittedTo; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    // Date section
    glColor3f(1, 1, 1);
    glRasterPos2f(300, 370);
    const char* date = "Date: [ 7th May 2025]";
    for (const char* c = date; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    // Draw instructions header with decorative line
    glColor3f(1, 1, 1); 
    glBegin(GL_LINES);
    glVertex2f(100, 340);
    glVertex2f(700, 340);
    glEnd();

    glRasterPos2f(300, 320);
    const char* instructionsHeader = "PROJECT CONTROLS";
    for (const char* c = instructionsHeader; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    // Draw instructions in a two-column format
    glColor3f(1, 1, 1); // White
    // Left column
    glRasterPos2f(120, 290);
    const char* line1 = "1-9, 0: Direct season selection";
    for (const char* c = line1; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(120, 260);
    const char* line2 = "N: Next season";
    for (const char* c = line2; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(120, 230);
    const char* line3 = "R: Toggle rain";
    for (const char* c = line3; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(120, 200);
    const char* line4 = "Left/Right: Boat speed";
    for (const char* c = line4; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    // Right column
    glRasterPos2f(420, 290);
    const char* line5 = "P: Previous season";
    for (const char* c = line5; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(420, 260);
    const char* line6 = "S: Stop rain";
    for (const char* c = line6; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(420, 230);
    const char* line7 = "Mouse: Cloud control";
    for (const char* c = line7; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(420, 200);
    const char* line8 = "I: Show instructions";
    for (const char* c = line8; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }


    glColor3f(1, 1, 1); // White text
    glRasterPos2f(120, 130);
    const char* desc1 = "This project simulates seasonal changes with dynamic weather,";
    for (const char* c = desc1; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    glRasterPos2f(120, 110);
    const char* desc2 = "vegetation transitions, and environmental effects using OpenGL.";
    for (const char* c = desc2; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }

    // Continue prompt with decoration
    glColor3f(1, 1, 1); 
    glBegin(GL_LINES);
    glVertex2f(200, 60);
    glVertex2f(600, 60);
    glEnd();

    glRasterPos2f(250, 40);
    const char* continuePrompt = "PRESS ANY KEY TO BEGIN THE SIMULATION";
    for (const char* c = continuePrompt; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    // Restore matrices
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glFlush();
}
void changeSeason(int season) {
    currentSeason = season;
    switch (season) {
    case 0: glutDisplayFunc(summer); break;
    case 1: glutDisplayFunc(summer_rain); break;
    case 2: glutDisplayFunc(rainDay); break;
    case 3: glutDisplayFunc(rain_autumn); break;
    case 4: glutDisplayFunc(autumn); break;
    case 5: glutDisplayFunc(midAutumn); break;
    case 6: glutDisplayFunc(lateAutumn); break;
    case 7: glutDisplayFunc(earlyWinter); break;
    case 8: glutDisplayFunc(winter); break;
    case 9: glutDisplayFunc(winter_spring); break;
    case 10: glutDisplayFunc(spring); break;
    }
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (showInstructions) {
        showInstructions = false;
        changeSeason(currentSeason);
        return;
    }

    switch (key) {
    case 'r':
        rainSpeed = 0.2f;
        break;
    case 's':
        rainP = 2.50f;
        rainSpeed = 0.0f;
        break;
    case 'n': // Next season
        currentSeason = (currentSeason + 1) % 11;
        changeSeason(currentSeason);
        break;
    case 'p': // Previous season
        currentSeason = (currentSeason - 1 + 11) % 11;
        changeSeason(currentSeason);
        break;
    case '1': changeSeason(0); break;
    case '2': changeSeason(1); break;
    case '3': changeSeason(2); break;
    case '4': changeSeason(3); break;
    case '5': changeSeason(4); break;
    case '6': changeSeason(5); break;
    case '7': changeSeason(6); break;
    case '8': changeSeason(7); break;
    case '9': changeSeason(8); break;
    case '0': changeSeason(9); break;
    case 'i': // Show instructions
        showInstructions = true;
        glutDisplayFunc(displayInstructions);
        glutPostRedisplay();
        break;
    }
}





// [Rest of your existing functions remain unchanged...]

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("Season Change Simulation");
    glutReshapeWindow(800, 700);

    // Set initial display function to show instructions
    glutDisplayFunc(displayInstructions);

    // Set up animation timers
    glutTimerFunc(100, cloudUp, 0);
    glutTimerFunc(20510, RcloudUp, 0);
    glutTimerFunc(100, rainUp, 0);
    glutTimerFunc(120005, treeUp, 0);
    glutTimerFunc(100100, flowerUp, 0);
    glutTimerFunc(140000, snowUp, 0);
    glutTimerFunc(10, boatUp, 0);
    glutTimerFunc(20000, sunUp, 0);
    glutTimerFunc(140000, sunUp2, 0);

    // Register callback functions
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    glutMouseFunc(handleMouse);
    glutIdleFunc(Idle);

    glutMainLoop();
    return 0;
}