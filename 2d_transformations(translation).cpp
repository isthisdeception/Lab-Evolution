#include <GL/glut.h>

float tx = 100;
float ty = 50;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original Triangle
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2i(100, 100);
        glVertex2i(150, 200);
        glVertex2i(200, 100);
    glEnd();

    // Translated Triangle
    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2i(100 + tx, 100 + ty);
        glVertex2i(150 + tx, 200 + ty);
        glVertex2i(200 + tx, 100 + ty);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Window");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 800, 0, 600);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

#include <GL/glut.h>


