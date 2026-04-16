// Includes the GLUT library for window management and line drawing.
#include <GL/glut.h>
// Includes math functions like sin() and cos() for rotation calculations.
#include <cmath>

// Stores the rotation angle in degrees.
float angle = 45.0;

// This function draws the original line and its rotated version.
void display() {
    // Clears the screen using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Converts the angle from degrees to radians because sin() and cos() use radians.
    float rad = angle * 3.1416 / 180.0;

    // Stores the x-coordinate of the original endpoint.
    int x = 100;
    // Stores the y-coordinate of the original endpoint.
    int y = 50;

    // Computes the rotated x-coordinate using the 2D rotation formula.
    int xr = x * cos(rad) - y * sin(rad);
    // Computes the rotated y-coordinate using the 2D rotation formula.
    int yr = x * sin(rad) + y * cos(rad);

    // Sets the drawing color to white for the original line.
    glColor3f(1, 1, 1);
    // Starts drawing the original line.
    glBegin(GL_LINES);
        // Sets the starting point of the line at the origin.
        glVertex2i(0, 0);
        // Sets the endpoint of the original line.
        glVertex2i(x, y);
    // Finishes drawing the original line.
    glEnd();

    // Sets the drawing color to red for the rotated line.
    glColor3f(1, 0, 0);
    // Starts drawing the rotated line.
    glBegin(GL_LINES);
        // Uses the origin as the starting point again.
        glVertex2i(0, 0);
        // Uses the rotated coordinates as the endpoint.
        glVertex2i(xr, yr);
    // Finishes drawing the rotated line.
    glEnd();

    // Forces immediate execution of the drawing commands.
    glFlush();
}

// Program entry point where the OpenGL/GLUT environment is initialized.
int main(int argc, char** argv) {
    // Initializes GLUT and processes startup arguments.
    glutInit(&argc, argv);
    // Sets single buffering with RGB color mode.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial window size in pixels.
    glutInitWindowSize(800, 600);
    // Sets the initial position of the window on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the application window with the provided title.
    glutCreateWindow("OpenGL Window");

    // Sets the background color to black.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic coordinate system for drawing.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the function that GLUT should call to draw the scene.
    glutDisplayFunc(display);
    // Enters the GLUT main loop and waits for events.
    glutMainLoop();

    // Returns 0 to indicate successful completion.
    return 0;
}

// Includes the GLUT header again; this repeated include does not change behavior because the header prevents duplicate definitions.
#include <GL/glut.h>
