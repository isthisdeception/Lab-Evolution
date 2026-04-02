#include <windows.h>
#include <GL/glut.h>

void drawRiver() {
    // A soft blue color for the water
    glColor3f(0.0f, 0.5f, 1.0f);

    // Using GL_POLYGON with 8 vertices for a curved effect
    glBegin(GL_POLYGON);
        // Start from the bottom-left of the river
        glVertex2f(-0.2f, -1.0f);  // Vertex 1
        glVertex2f(-0.4f, -0.6f);  // Vertex 2 (bend left)
        glVertex2f(-0.1f, -0.2f);  // Vertex 3 (bend right)
        glVertex2f(-0.3f, 0.4f);   // Vertex 4 (bend left)
        glVertex2f(0.1f, 1.0f);    // Vertex 5 (Top-left exit)

        // Now move to the right bank and head back down
        glVertex2f(0.5f, 1.0f);    // Vertex 6 (Top-right exit)
        glVertex2f(0.1f, 0.4f);    // Vertex 7 (follow the curve)
        glVertex2f(0.3f, -0.2f);   // Vertex 8 (follow the curve)
        glVertex2f(0.0f, -0.6f);   // Vertex 9 (follow the curve)
        glVertex2f(0.2f, -1.0f);   // Vertex 10 (Bottom-right)
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a green background for the grass/land
    glColor3f(0.2f, 0.6f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Draw the river on top of the grass
    drawRiver();

    glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("River using GL_POLYGON");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
