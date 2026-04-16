// Includes the GLUT library so we can create a window and draw 2D shapes.
#include <GL/glut.h>

// Stores the horizontal scaling factor.
float sx = 2.0;
// Stores the vertical scaling factor.
float sy = 1.5;

// This function draws the original rectangle and its scaled version.
void display() {
    // Clears the current color buffer using the background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Comment label indicating the next shape is the original rectangle.
    // Original Rectangle
    // Sets the color to red for the original rectangle.
    glColor3f(1, 0, 0);
    // Starts drawing a quadrilateral.
    glBegin(GL_QUADS);
        // Bottom-left corner of the original rectangle.
        glVertex2i(100, 100);
        // Bottom-right corner of the original rectangle.
        glVertex2i(200, 100);
        // Top-right corner of the original rectangle.
        glVertex2i(200, 200);
        // Top-left corner of the original rectangle.
        glVertex2i(100, 200);
    // Ends the original rectangle drawing.
    glEnd();

    // Comment label indicating the next shape is the scaled rectangle.
    // Scaled Rectangle
    // Sets the color to green for the scaled rectangle.
    glColor3f(0, 1, 0);
    // Starts drawing the scaled rectangle.
    glBegin(GL_QUADS);
        // Bottom-left corner after applying scaling to x and y.
        glVertex2i(100 * sx, 100 * sy);
        // Bottom-right corner after applying scaling to x and y.
        glVertex2i(200 * sx, 100 * sy);
        // Top-right corner after applying scaling to x and y.
        glVertex2i(200 * sx, 200 * sy);
        // Top-left corner after applying scaling to x and y.
        glVertex2i(100 * sx, 200 * sy);
    // Ends the scaled rectangle drawing.
    glEnd();

    // Forces the drawing commands to be executed immediately.
    glFlush();
}

// Program entry point where GLUT is initialized and callbacks are assigned.
int main(int argc, char** argv) {
    // Initializes GLUT and handles command-line arguments.
    glutInit(&argc, argv);
    // Sets the window to single-buffered RGB mode.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the width and height of the window.
    glutInitWindowSize(800, 600);
    // Sets the initial window position on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the window with the title shown in the title bar.
    glutCreateWindow("OpenGL Window");

    // Sets the clear color to black with full opacity.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic projection for the drawing area.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Starts the GLUT event loop.
    glutMainLoop();

    // Returns 0 to indicate the program finished successfully.
    return 0;
}

// Includes the GLUT header again; this duplicate include does not affect execution because the header is guarded.
#include <GL/glut.h>
