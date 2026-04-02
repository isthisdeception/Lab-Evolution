#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

// 1. SUN: Loop-based Polygon Approximation
void drawSun(float cx, float cy, float r, int segments) {
    glColor3f(1.0f, 0.9f, 0.0f); // Yellow
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * float(i) / float(segments);
        glVertex2f(r * cosf(theta) + cx, r * sinf(theta) + cy);
    }
    glEnd();
}

// 2. MOUNTAINS: Layered GL_TRIANGLES
void drawMountain(float x, float y, float w, float h, float r, float g, float b) {
    glBegin(GL_TRIANGLES);
        glColor3f(r * 0.8f, g * 0.8f, b * 0.8f); glVertex2f(x - w / 2, y);
        glColor3f(r, g, b);                     glVertex2f(x, y + h);
        glColor3f(r * 0.6f, g * 0.6f, b * 0.6f); glVertex2f(x + w / 2, y);
    glEnd();
}

// 3. RIVER: GL_POLYGON (10 vertices)
void drawRiver() {
    glColor3f(0.0f, 0.4f, 0.8f); // Deep Blue
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, -1.0f); glVertex2f(-0.5f, -0.6f);
        glVertex2f(-0.2f, -0.2f); glVertex2f(-0.4f, 0.2f);
        glVertex2f(0.0f, 0.5f);   // Left Bank up
        glVertex2f(0.4f, 0.5f);   // Top crossing
        glVertex2f(0.1f, 0.2f);   glVertex2f(0.3f, -0.2f);
        glVertex2f(0.0f, -0.6f);  glVertex2f(0.2f, -1.0f);
    glEnd();
}

// 4. HOUSE: GL_QUADS for walls, GL_TRIANGLES for roof
void drawHouse(float x, float y) {
    // Walls
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(x - 0.2f, y);
        glVertex2f(x + 0.2f, y);
        glVertex2f(x + 0.2f, y + 0.3f);
        glVertex2f(x - 0.2f, y + 0.3f);
    glEnd();

    // Roof
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 0.25f, y + 0.3f);
        glVertex2f(x + 0.25f, y + 0.3f);
        glVertex2f(x, y + 0.5f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw Sun
    drawSun(0.7f, 0.7f, 0.15f, 100);

    // Draw Background Mountains (Layered)
    drawMountain(-0.5f, -0.2f, 1.2f, 0.7f, 0.2f, 0.3f, 0.2f);
    drawMountain(0.4f, -0.2f, 1.0f, 0.6f, 0.2f, 0.3f, 0.2f);

    // Draw Ground
    glColor3f(0.1f, 0.5f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.2f);  glVertex2f(-1.0f, -0.2f);
    glEnd();

    // Draw River
    drawRiver();

    // Draw House
    drawHouse(-0.6f, -0.5f);

    glutSwapBuffers();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Sky Blue
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Complete OpenGL Scene - Windows");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
