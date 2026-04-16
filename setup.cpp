// Includes the GLUT library so we can create a window and use OpenGL drawing functions.
#include <GL/glut.h>

// This function is called whenever the window needs to be redrawn.
void display() {
    // Clears the color buffer using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Placeholder comment showing where drawing commands can be added later.
    // Drawing code here

    // Forces OpenGL to execute the drawing commands immediately.
    glFlush();
}

// Program entry point where GLUT and the window are initialized.
int main(int argc, char** argv) {
    // Initializes GLUT and processes any command-line arguments.
    glutInit(&argc, argv);
    // Sets the display mode to single buffering with RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial window size.
    glutInitWindowSize(800, 600);
    // Sets the initial window position on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the OpenGL window with the specified title.
    glutCreateWindow("OpenGL Window");

    // Sets the background color to black with full opacity.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic projection for drawing coordinates.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Starts the GLUT main event loop.
    glutMainLoop();

    // Returns 0 to indicate successful program execution.
    return 0;
}
