#include <QCoreApplication>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45,ratio,1,100);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}
float angle = 0.0f;
void renderScene(void) {

    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(	1.0f, 5.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f);

    //glRotatef(angle, 0.0f, 1.0f, 0.0f);

    // Dessiner le centre du repère
    glutWireSphere (0.05f,20,20);


    glPushMatrix ();
    // Dessiner l'axe des X
    glColor3f(1.0,0.0,0.0);
    glTranslatef (0.05f,0.0f,0.0f);
 //   glRotatef (90,0.0,0.0,0.0);
    glRotatef (90,0.0,1.0,0.0);
    gluCylinder (quadratic,0.05,0.05,1.5,20,20);

    // Dessiner le sens des X
    glColor3f(0.5,0.5,0.5);
    glTranslatef (0.0f,0.0f,1.5f);
    glutSolidCone (0.1f,0.2,20,20);
    glPopMatrix ();


    glPushMatrix ();
    // Dessiner l'axe des Z
    glColor3f(0.0,0.0,1.0);
//    glTranslatef (0.0f,0.0f,0.0f);
//    glRotatef (90,1.0,0.0,0.0);
//    glRotatef (90,0.0,1.0,0.0);
    gluCylinder (quadratic,0.05,0.05,1.5,20,20);

    // Dessiner le sens des Z
    glColor3f(0.5,0.5,0.5);
    glTranslatef (0.0f,0.0f,1.5f);
    glutSolidCone (0.1f,0.2,20,20);

    glPopMatrix ();

    glPushMatrix ();
    // Dessiner l'axe des Y
    glColor3f(0.0,1.0,0.0);
    glTranslatef (0.0f,-0.05f,0.0f);
    glRotatef (90,1.0,0.0,0.0);
//    glRotatef (90,0.0,1.0,0.0);
    gluCylinder (quadratic,0.05,0.05,1.5,20,20);

    // Dessiner le sens des Y
    glColor3f(0.5,0.5,0.5);
    glTranslatef (0.0f,0.0f,1.5f);
    glutSolidCone (0.1f,0.2,20,20);

    glPopMatrix ();



//    angle+=0.1f;

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Free repère");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

    // enter GLUT event processing loop
    glutMainLoop();


    return a.exec();
}
