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

// Draws a line from (x1, y1) to (x2, y2) using Bresenham's line algorithm.
void bresenhamLine(int x1, int y1, int x2, int y2) {
    // Calculates the horizontal distance between the endpoints.
    int dx = abs(x2 - x1);
    // Calculates the vertical distance between the endpoints.
    int dy = abs(y2 - y1);
    // Initializes the decision parameter used by Bresenham's algorithm.
    int p = 2 * dy - dx;

    // Starts x at the first endpoint's x-coordinate.
    int x = x1;
    // Starts y at the first endpoint's y-coordinate.
    int y = y1;

    // Continues plotting pixels until x reaches the second endpoint.
    while (x <= x2) {
        // Draws the current pixel on the line.
        drawPixel(x, y);

        // If the decision parameter is negative...
        if (p < 0) {
            // ...choose the next pixel directly to the right and update p.
            p = p + 2 * dy;
        } else {
            // Otherwise move one step upward as well.
            y++;
            // Updates the decision parameter after choosing the diagonal pixel.
            p = p + 2 * dy - 2 * dx;
        }

        // Moves to the next x-position.
        x++;
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
