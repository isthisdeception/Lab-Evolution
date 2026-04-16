#include <GL/glut.h>

float sx = 2.0;
float sy = 1.5;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original Rectangle
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i(100, 100);
        glVertex2i(200, 100);
        glVertex2i(200, 200);
        glVertex2i(100, 200);
    glEnd();

    // Scaled Rectangle
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
        glVertex2i(100 * sx, 100 * sy);
        glVertex2i(200 * sx, 100 * sy);
        glVertex2i(200 * sx, 200 * sy);
        glVertex2i(100 * sx, 200 * sy);
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


