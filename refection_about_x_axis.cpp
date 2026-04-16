// Includes the GLUT library so we can open a window and draw graphics.
#include <GL/glut.h>

// This function is responsible for drawing everything in the window.
void display() {
    // Clears the screen using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Comment label indicating the next triangle is the original one.
    // Original Triangle
    // Sets the drawing color to red.
    glColor3f(1, 0, 0);
    // Starts drawing a triangle using three vertices.
    glBegin(GL_TRIANGLES);
        // First vertex of the original triangle.
        glVertex2i(100, 100);
        // Second vertex of the original triangle.
        glVertex2i(150, 200);
        // Third vertex of the original triangle.
        glVertex2i(200, 100);
    // Finishes drawing the original triangle.
    glEnd();

    // Comment label indicating the next triangle is the reflected version across the X-axis.
    // Reflected Triangle about X-axis
    // Sets the drawing color to green.
    glColor3f(0, 1, 0);
    // Starts drawing the reflected triangle.
    glBegin(GL_TRIANGLES);
        // First reflected vertex with the y-value negated.
        glVertex2i(100, -100);
        // Second reflected vertex with the y-value negated.
        glVertex2i(150, -200);
        // Third reflected vertex with the y-value negated.
        glVertex2i(200, -100);
    // Finishes drawing the reflected triangle.
    glEnd();

    // Forces OpenGL to execute the queued drawing commands immediately.
    glFlush();
}

// Program entry point where the GLUT window and callbacks are set up.
int main(int argc, char** argv) {
    // Initializes GLUT and passes command-line arguments.
    glutInit(&argc, argv);
    // Sets single buffering and RGB color mode.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial window size.
    glutInitWindowSize(800, 600);
    // Sets the initial window position on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the OpenGL window with the given title.
    glutCreateWindow("OpenGL Window");

    // Sets the background color to black with full opacity.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Creates a 2D orthographic viewing area from (0,0) to (800,600).
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Starts the GLUT event loop.
    glutMainLoop();

    // Returns 0 to indicate successful execution.
    return 0;
}

// Includes the GLUT header again; this duplicate include is harmless because the header is protected by include guards.
#include <GL/glut.h>
