#include <windows.h>
#include <GL/glut.h>

void drawMountain(float x, float y, float width, float height, float r, float g, float b) {
    glBegin(GL_TRIANGLES);
        // Base left
        glColor3f(r * 0.8f, g * 0.8f, b * 0.8f); // Slightly darker side
        glVertex2f(x - width / 2, y);

        // Peak
        glColor3f(r, g, b); // Brightest at the peak
        glVertex2f(x, y + height);

        // Base right
        glColor3f(r * 0.6f, g * 0.6f, b * 0.6f); // Darkest side for 3D feel
        glVertex2f(x + width / 2, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Layer 1: Distant Mountains (Darker/Muted) ---
    drawMountain(-0.6f, -0.3f, 1.2f, 0.8f, 0.2f, 0.25f, 0.3f);
    drawMountain(0.5f, -0.3f, 1.0f, 0.7f, 0.2f, 0.25f, 0.3f);

    // --- Layer 2: Mid-ground Mountains ---
    drawMountain(-0.2f, -0.5f, 1.0f, 0.6f, 0.3f, 0.35f, 0.4f);
    drawMountain(0.7f, -0.5f, 0.8f, 0.5f, 0.3f, 0.35f, 0.4f);

    // --- Layer 3: Foreground (Lighter/Clearer) ---
    drawMountain(-0.7f, -0.8f, 0.9f, 0.5f, 0.4f, 0.45f, 0.5f);
    drawMountain(0.1f, -0.8f, 1.2f, 0.6f, 0.4f, 0.45f, 0.5f);
    drawMountain(0.8f, -0.8f, 0.7f, 0.4f, 0.4f, 0.45f, 0.5f);

    // Ground level
    glBegin(GL_QUADS);
        glColor3f(0.1f, 0.3f, 0.1f); // Dark green grass
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.3f);
        glVertex2f(-1.0f, -0.3f);
    glEnd();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // Sky Blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Layered Mountains - GL_TRIANGLES");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
