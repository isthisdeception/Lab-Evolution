// Includes the GLUT library so we can create a window and draw pixels.
#include <GL/glut.h>
// Includes common math-related functions such as abs().
#include <cmath>

// Draws a single pixel at the specified coordinate.
void drawPixel(int x, int y) {
    // Starts drawing points.
    glBegin(GL_POINTS);
        // Places one point at the coordinate (x, y).
        glVertex2i(x, y);
    // Ends the point drawing.
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;   // step direction for x
    int sy = (y1 < y2) ? 1 : -1;   // step direction for y

    int err = dx - dy;

    while (true) {
        drawPixel(x1, y1);

        // Stop when destination is reached
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err = err - dy;
            x1 = x1 + sx;
        }

        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

// This function clears the screen and draws the Bresenham line.
void display() {
    // Clears the color buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // Sets the drawing color to white.
    glColor3f(1, 1, 1);

    // Draws a line from (100,100) to (400,300).
    bresenhamLine(100, 100, 400, 300);

    // Forces OpenGL to execute the drawing commands immediately.
    glFlush();
}

// Program entry point where GLUT is initialized and callbacks are registered.
int main(int argc, char** argv) {
    // Initializes GLUT and handles startup arguments.
    glutInit(&argc, argv);
    // Sets the display mode to single buffering and RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the size of the window.
    glutInitWindowSize(800, 600);
    // Sets the initial position of the window on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the OpenGL window.
    glutCreateWindow("OpenGL Window");

    // Sets the background color to black.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic projection matching the window coordinates.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Starts the GLUT event-processing loop.
    glutMainLoop();

    // Returns 0 to indicate successful execution.
    return 0;
}

// Includes the GLUT header again; this extra include is harmless because the header prevents duplicate definitions.
#include <GL/glut.h>
