#include <cmath>
#include <GL/glut.h>

float carX = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Car Body
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(carX + 100, 100);
        glVertex2f(carX + 250, 100);
        glVertex2f(carX + 250, 150);
        glVertex2f(carX + 100, 150);
    glEnd();

    // Wheels
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float theta = i * 3.1416 / 180;
        glVertex2f(carX + 130 + 20 * cos(theta), 80 + 20 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float theta = i * 3.1416 / 180;
        glVertex2f(carX + 220 + 20 * cos(theta), 80 + 20 * sin(theta));
    }
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    carX += 2;

    if(carX > 800)
        carX = -300;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Moving Car");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
