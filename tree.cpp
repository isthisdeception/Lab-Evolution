#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

// 1. FIXED: Changed name to drawSun to match the call in display()
// Also ensures the color is set inside the function
void drawSun(float cx, float cy, float r, int segments, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * float(i) / float(segments);
        glVertex2f(r * cosf(theta) + cx, r * sinf(theta) + cy);
    }
    glEnd();
}

// 2. TREE: GL_QUADS for trunk, polygons for leaves
void drawTree(float x, float y) {
    // Trunk - GL_QUADS
    glColor3f(0.4f, 0.2f, 0.0f); // Dark Brown
    glBegin(GL_QUADS);
        glVertex2f(x - 0.03f, y);
        glVertex2f(x + 0.03f, y);
        glVertex2f(x + 0.03f, y + 0.2f);
        glVertex2f(x - 0.03f, y + 0.2f);
    glEnd();

    // Leaves - Using drawSun function (which is just a circle) to make bushy leaves
    drawSun(x, y + 0.25f, 0.08f, 30, 0.0f, 0.5f, 0.0f);
    drawSun(x - 0.05f, y + 0.2f, 0.07f, 30, 0.0f, 0.45f, 0.0f);
    drawSun(x + 0.05f, y + 0.2f, 0.07f, 30, 0.0f, 0.45f, 0.0f);
}

// 3. MOUNTAINS: Layered GL_TRIANGLES
void drawMountain(float x, float y, float w, float h, float r, float g, float b) {
    glBegin(GL_TRIANGLES);
        glColor3f(r * 0.8f, g * 0.8f, b * 0.8f); glVertex2f(x - w / 2, y);
        glColor3f(r, g, b);                     glVertex2f(x, y + h);
        glColor3f(r * 0.6f, g * 0.6f, b * 0.6f); glVertex2f(x + w / 2, y);
    glEnd();
}

// 4. RIVER: GL_POLYGON
void drawRiver() {
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, -1.0f); glVertex2f(-0.5f, -0.6f);
        glVertex2f(-0.2f, -0.2f); glVertex2f(-0.4f, 0.2f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.4f, 0.5f);
        glVertex2f(0.1f, 0.2f);   glVertex2f(0.3f, -0.2f);
        glVertex2f(0.0f, -0.6f);  glVertex2f(0.2f, -1.0f);
    glEnd();
}

// 5. HOUSE: Quads and Triangles
void drawHouse(float x, float y) {
    glColor3f(0.6f, 0.4f, 0.2f); // Walls
    glBegin(GL_QUADS);
        glVertex2f(x - 0.2f, y); glVertex2f(x + 0.2f, y);
        glVertex2f(x + 0.2f, y + 0.3f); glVertex2f(x - 0.2f, y + 0.3f);
    glEnd();

    glColor3f(0.8f, 0.1f, 0.1f); // Roof
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 0.25f, y + 0.3f); glVertex2f(x + 0.25f, y + 0.3f);
        glVertex2f(x, y + 0.5f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Now this matches the function name above
    drawSun(0.7f, 0.7f, 0.15f, 100, 1.0f, 0.9f, 0.0f);

    // Background Mountains
    drawMountain(-0.5f, -0.2f, 1.2f, 0.7f, 0.2f, 0.3f, 0.2f);
    drawMountain(0.4f, -0.2f, 1.0f, 0.6f, 0.2f, 0.3f, 0.2f);

    // Ground
    glColor3f(0.1f, 0.5f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.2f);  glVertex2f(-1.0f, -0.2f);
    glEnd();

    drawRiver();
    drawHouse(-0.6f, -0.5f);

    // Trees
    drawTree(0.35f, -0.6f);
    drawTree(0.55f, -0.8f);

    glutSwapBuffers();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fixed River Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
