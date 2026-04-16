#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Point
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2i(100, 100);
    glEnd();

    // Line
    glBegin(GL_LINES);
        glVertex2i(150, 100);
        glVertex2i(250, 200);
    glEnd();

    // Triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(300, 100);
        glVertex2i(250, 200);
        glVertex2i(350, 200);
    glEnd();

    // Rectangle
    glBegin(GL_QUADS);
        glVertex2i(400, 100);
        glVertex2i(550, 100);
        glVertex2i(550, 200);
        glVertex2i(400, 200);
    glEnd();

    // Polygon
    glBegin(GL_POLYGON);
        glVertex2i(600, 100);
        glVertex2i(650, 150);
        glVertex2i(630, 220);
        glVertex2i(570, 220);
        glVertex2i(550, 150);
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


