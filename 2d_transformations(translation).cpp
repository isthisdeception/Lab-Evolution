// Includes the GLUT library so we can create a window and draw graphics.
#include <GL/glut.h>

// Stores the horizontal translation distance.
float tx = 100;
// Stores the vertical translation distance.
float ty = 50;

// This function draws the original triangle and the translated triangle.
void display() {
    // Clears the window using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Comment label indicating the next shape is the original triangle.
    // Original Triangle
    // Sets the drawing color to red.
    glColor3f(1, 0, 0);
    // Starts drawing a triangle.
    glBegin(GL_TRIANGLES);
        // First vertex of the original triangle.
        glVertex2i(100, 100);
        // Second vertex of the original triangle.
        glVertex2i(150, 200);
        // Third vertex of the original triangle.
        glVertex2i(200, 100);
    // Finishes drawing the original triangle.
    glEnd();

    // Comment label indicating the next shape is the translated triangle.
    // Translated Triangle
    // Sets the drawing color to green.
    glColor3f(0, 1, 0);
    // Starts drawing the translated triangle.
    glBegin(GL_TRIANGLES);
        // First translated vertex after adding tx and ty.
        glVertex2i(100 + tx, 100 + ty);
        // Second translated vertex after adding tx and ty.
        glVertex2i(150 + tx, 200 + ty);
        // Third translated vertex after adding tx and ty.
        glVertex2i(200 + tx, 100 + ty);
    // Finishes drawing the translated triangle.
    glEnd();

    // Forces OpenGL to execute the drawing commands immediately.
    glFlush();
}

// Program entry point where GLUT and the OpenGL window are initialized.
int main(int argc, char** argv) {
    // Initializes GLUT and processes any command-line arguments.
    glutInit(&argc, argv);
    // Sets the display mode to single buffering with RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial width and height of the window.
    glutInitWindowSize(800, 600);
    // Sets the initial screen position of the window.
    glutInitWindowPosition(100, 100);
    // Creates the window with the given title.
    glutCreateWindow("OpenGL Window");

    // Sets the background color to black with full opacity.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic projection for the coordinate system.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display callback function.
    glutDisplayFunc(display);
    // Starts the GLUT event-processing loop.
    glutMainLoop();

    // Returns 0 to indicate successful execution.
    return 0;
}

// Includes the GLUT header again; this repeated include is harmless because the header uses include guards.
#include <GL/glut.h>
