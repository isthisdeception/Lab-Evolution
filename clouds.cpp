#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

// 1. Core Circle Function (Used for Sun, Leaves, and Clouds)
void drawCircle(float cx, float cy, float r, int segments, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * float(i) / float(segments);
        glVertex2f(r * cosf(theta) + cx, r * sinf(theta) + cy);
    }
    glEnd();
}

// 2. NEW: Cloud Function (Clusters of white circles)
void drawCloud(float x, float y) {
    // A cloud is made of 4-5 overlapping white circles
    drawCircle(x, y, 0.07f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.05f, y + 0.02f, 0.08f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.1f, y, 0.07f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.05f, y - 0.02f, 0.06f, 30, 1.0f, 1.0f, 1.0f);
}

// 3. Tree Function
void drawTree(float x, float y) {
    glColor3f(0.4f, 0.2f, 0.0f); // Trunk
    glBegin(GL_QUADS);
        glVertex2f(x - 0.03f, y);
        glVertex2f(x + 0.03f, y);
        glVertex2f(x + 0.03f, y + 0.2f);
        glVertex2f(x - 0.03f, y + 0.2f);
    glEnd();
    // Leaves
    drawCircle(x, y + 0.25f, 0.08f, 30, 0.0f, 0.5f, 0.0f);
    drawCircle(x - 0.05f, y + 0.2f, 0.07f, 30, 0.0f, 0.45f, 0.0f);
    drawCircle(x + 0.05f, y + 0.2f, 0.07f, 30, 0.0f, 0.45f, 0.0f);
}

// 4. Mountain Function
void drawMountain(float x, float y, float w, float h, float r, float g, float b) {
    glBegin(GL_TRIANGLES);
        glColor3f(r * 0.8f, g * 0.8f, b * 0.8f); glVertex2f(x - w / 2, y);
        glColor3f(r, g, b);                     glVertex2f(x, y + h);
        glColor3f(r * 0.6f, g * 0.6f, b * 0.6f); glVertex2f(x + w / 2, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. Sun
    drawCircle(0.7f, 0.7f, 0.15f, 100, 1.0f, 0.9f, 0.0f);

    // 2. Clouds (Placed in the sky)
    drawCloud(-0.6f, 0.75f);
    drawCloud(-0.2f, 0.85f);
    drawCloud(0.2f, 0.78f);

    // 3. Background Mountains
    drawMountain(-0.5f, -0.2f, 1.2f, 0.7f, 0.2f, 0.3f, 0.2f);
    drawMountain(0.4f, -0.2f, 1.0f, 0.6f, 0.2f, 0.3f, 0.2f);

    // 4. Ground
    glColor3f(0.1f, 0.5f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.2f);  glVertex2f(-1.0f, -0.2f);
    glEnd();

    // 5. River (POLYGON)
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, -1.0f); glVertex2f(-0.5f, -0.6f);
        glVertex2f(-0.2f, -0.2f); glVertex2f(-0.4f, 0.2f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.4f, 0.5f);
        glVertex2f(0.1f, 0.2f);   glVertex2f(0.3f, -0.2f);
        glVertex2f(0.0f, -0.6f);  glVertex2f(0.2f, -1.0f);
    glEnd();

    // 6. House & Trees
    // drawHouse function removed for brevity, but same logic applies
    drawTree(0.35f, -0.6f);
    drawTree(0.55f, -0.8f);

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
    glutCreateWindow("River Scene with Clouds");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
