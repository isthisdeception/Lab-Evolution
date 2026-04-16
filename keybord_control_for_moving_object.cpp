#include <GL/glut.h>

int x = 100;
int y = 100;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + 50, y);
        glVertex2i(x + 50, y + 50);
        glVertex2i(x, y + 50);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int mouseX, int mouseY) {
    switch(key) {
        case 'w': y += 10; break;
        case 's': y -= 10; break;
        case 'a': x -= 10; break;
        case 'd': x += 10; break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Keyboard Movement");

    gluOrtho2D(0, 800, 0, 600);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
