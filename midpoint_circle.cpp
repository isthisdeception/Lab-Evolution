// Includes the GLUT library so we can create a window and draw pixels.
#include <GL/glut.h>

// Draws a single pixel at the specified coordinate.
void drawPixel(int x, int y) {
    // Starts drawing points.
    glBegin(GL_POINTS);
        // Places one point at position (x, y).
        glVertex2i(x, y);
    // Ends the point drawing.
    glEnd();
}

// Plots all eight symmetric points of a circle for the current (x, y) offset.
void plotCirclePoints(int xc, int yc, int x, int y) {
    // Plots the point in the first octant.
    drawPixel(xc + x, yc + y);
    // Plots the mirrored point in the second octant.
    drawPixel(xc - x, yc + y);
    // Plots the mirrored point in the eighth octant.
    drawPixel(xc + x, yc - y);
    // Plots the mirrored point in the seventh octant.
    drawPixel(xc - x, yc - y);
    // Plots the mirrored point after swapping x and y.
    drawPixel(xc + y, yc + x);
    // Plots the corresponding mirrored point on the left side.
    drawPixel(xc - y, yc + x);
    // Plots the corresponding mirrored point below the x-axis.
    drawPixel(xc + y, yc - x);
    // Plots the final symmetric point of the set.
    drawPixel(xc - y, yc - x);
}

// Draws a circle centered at (xc, yc) with radius r using the midpoint circle algorithm.
void midpointCircle(int xc, int yc, int r) {
    // Starts x at 0 on the circle boundary.
    int x = 0;
    // Starts y at the radius value.
    int y = r;
    // Initializes the decision parameter for the midpoint circle algorithm.
    int p = 1 - r;

    // Continues until x crosses y, which completes one octant.
    while (x <= y) {
        // Plots the eight symmetric points for the current x and y.
        plotCirclePoints(xc, yc, x, y);

        // Moves to the next x position.
        x++;

        // If the midpoint is inside the circle...
        if (p < 0) {
            // ...update only the decision parameter.
            p = p + 2 * x + 1;
        } else {
            // Otherwise move one step downward in y.
            y--;
            // Updates the decision parameter after changing both x and y.
            p = p + 2 * (x - y) + 1;
        }
    }
}

// This function clears the screen and draws the circle.
void display() {
    // Clears the color buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // Sets the drawing color to white.
    glColor3f(1, 1, 1);

    // Draws a circle centered at (300,300) with radius 100.
    midpointCircle(300, 300, 100);

    // Forces OpenGL to execute the drawing commands immediately.
    glFlush();
}

// Program entry point where GLUT is initialized and the window is created.
int main(int argc, char** argv) {
    // Initializes GLUT and processes command-line arguments.
    glutInit(&argc, argv);
    // Sets single buffering with RGB color mode.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the size of the application window.
    glutInitWindowSize(800, 600);
    // Sets the initial position of the window on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the OpenGL window with the specified title.
    glutCreateWindow("OpenGL Window");

    // Sets the clear color to black.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic projection for the drawing coordinate system.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Starts the GLUT event loop.
    glutMainLoop();

    // Returns 0 to indicate successful execution.
    return 0;
}

// Includes the GLUT header again; this repeated include is harmless because duplicate inclusion is prevented.
#include <GL/glut.h>
