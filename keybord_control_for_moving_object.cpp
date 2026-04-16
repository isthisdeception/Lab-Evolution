// Includes the GLUT library so we can create a window, draw shapes, and handle keyboard input.
#include <GL/glut.h>

// Stores the current x-coordinate of the square's bottom-left corner.
int x = 100;
// Stores the current y-coordinate of the square's bottom-left corner.
int y = 100;

// This function is called whenever the window needs to be redrawn.
void display() {
    // Clears the window using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Starts defining a four-sided polygon (a quadrilateral).
    glBegin(GL_QUADS);
        // Sets the first vertex at the bottom-left corner of the square.
        glVertex2i(x, y);
        // Sets the second vertex at the bottom-right corner of the square.
        glVertex2i(x + 50, y);
        // Sets the third vertex at the top-right corner of the square.
        glVertex2i(x + 50, y + 50);
        // Sets the fourth vertex at the top-left corner of the square.
        glVertex2i(x, y + 50);
    // Finishes the quadrilateral definition.
    glEnd();

    // Forces OpenGL to execute the drawing commands immediately.
    glFlush();
}

// This function runs when a keyboard key is pressed.
void keyboard(unsigned char key, int mouseX, int mouseY) {
    // Checks which key was pressed and updates the square position.
    switch(key) {
        // Moves the square upward by increasing y.
        case 'w': y += 10; break;
        // Moves the square downward by decreasing y.
        case 's': y -= 10; break;
        // Moves the square to the left by decreasing x.
        case 'a': x -= 10; break;
        // Moves the square to the right by increasing x.
        case 'd': x += 10; break;
    }

    // Marks the window for redraw so the square appears in its new position.
    glutPostRedisplay();
}

// Program entry point where GLUT and the window are initialized.
int main(int argc, char** argv) {
    // Initializes GLUT and processes any command-line arguments.
    glutInit(&argc, argv);
    // Sets the display mode to single buffering with RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial window width and height in pixels.
    glutInitWindowSize(800, 600);
    // Creates the application window with the given title.
    glutCreateWindow("Keyboard Movement");

    // Defines a 2D orthographic projection from (0,0) to (800,600).
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Registers the keyboard callback function.
    glutKeyboardFunc(keyboard);

    // Starts the GLUT event-processing loop and keeps the window running.
    glutMainLoop();
    // Returns 0 to indicate the program ended successfully.
    return 0;
}
