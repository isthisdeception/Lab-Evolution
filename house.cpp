#include <windows.h> // Standard for Windows inclusion
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // =========================================================
    // 1. Draw the WALLS using GL_QUADS
    // =========================================================
    glColor3f(0.8f, 0.5f, 0.2f); // Light brown for walls
    glBegin(GL_QUADS);
        // We draw a simple rectangle centered near the bottom
        glVertex2f(-0.5f, -0.6f); // Bottom Left
        glVertex2f(0.5f, -0.6f);  // Bottom Right
        glVertex2f(0.5f, 0.1f);   // Top Right
        glVertex2f(-0.5f, 0.1f);  // Top Left
    glEnd();

    // =========================================================
    // 2. Draw the ROOF using GL_TRIANGLES
    // =========================================================
    glColor3f(0.7f, 0.1f, 0.1f); // Dark red for roof
    glBegin(GL_TRIANGLES);
        // The base of the triangle matches the top edge of the walls
        glVertex2f(-0.6f, 0.1f);  // Roof Bottom Left (slightly wider than wall)
        glVertex2f(0.6f, 0.1f);   // Roof Bottom Right
        glVertex2f(0.0f, 0.6f);   // Roof Peak
    glEnd();

    // =========================================================
    // Optional Details (for context)
    // =========================================================
    // Draw a door using GL_QUADS
    glColor3f(0.4f, 0.2f, 0.0f); // Dark brown door
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.6f);
        glVertex2f(0.15f, -0.6f);
        glVertex2f(0.15f, -0.2f);
        glVertex2f(-0.15f, -0.2f);
    glEnd();

    // Draw a ground line using GL_LINES
    glColor3f(0.0f, 0.5f, 0.0f); // Green grass
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, -0.6f);
        glVertex2f(1.0f, -0.6f);
    glEnd();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f); // Sky blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Standard 2D orthogonal viewing volume
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // Double buffering for smoother rendering on Windows
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House using Quads and Triangles");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
