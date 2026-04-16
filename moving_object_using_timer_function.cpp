// Includes math functions like sin() and cos() for drawing circular wheels.
#include <cmath>
// Includes the GLUT library for window creation, drawing, and timer handling.
#include <GL/glut.h>

// Stores the horizontal offset of the car so it can move across the screen.
float carX = 0;

// This function draws the current frame of the animation.
void display() {
    // Clears the color buffer using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Comment label indicating the next shape is the main car body.
    // Car Body
    // Sets the drawing color to blue.
    glColor3f(0, 0, 1);
    // Starts drawing a quadrilateral for the car body.
    glBegin(GL_QUADS);
        // Bottom-left corner of the car body, shifted by carX.
        glVertex2f(carX + 100, 100);
        // Bottom-right corner of the car body, shifted by carX.
        glVertex2f(carX + 250, 100);
        // Top-right corner of the car body, shifted by carX.
        glVertex2f(carX + 250, 150);
        // Top-left corner of the car body, shifted by carX.
        glVertex2f(carX + 100, 150);
    // Ends the quadrilateral drawing.
    glEnd();

    // Comment label indicating the next shapes are the wheels.
    // Wheels
    // Sets the drawing color to white.
    glColor3f(1, 1, 1);
    // Starts drawing the first wheel as a polygon made of many points.
    glBegin(GL_POLYGON);
    // Loops through 360 degrees to approximate a circle.
    for(int i = 0; i < 360; i++) {
        // Converts the current angle from degrees to radians.
        float theta = i * 3.1416 / 180;
        // Adds one point on the circumference of the first wheel.
        glVertex2f(carX + 130 + 20 * cos(theta), 80 + 20 * sin(theta));
    }
    // Ends the first wheel polygon.
    glEnd();

    // Starts drawing the second wheel as another polygon.
    glBegin(GL_POLYGON);
    // Loops through 360 degrees to approximate the second circular wheel.
    for(int i = 0; i < 360; i++) {
        // Converts the current angle from degrees to radians.
        float theta = i * 3.1416 / 180;
        // Adds one point on the circumference of the second wheel.
        glVertex2f(carX + 220 + 20 * cos(theta), 80 + 20 * sin(theta));
    }
    // Ends the second wheel polygon.
    glEnd();

    // Swaps the back buffer to the front so the newly drawn frame appears on screen.
    glutSwapBuffers();
}

// This timer callback updates the car position for animation.
void update(int value) {
    // Moves the car a little to the right each time the timer runs.
    carX += 2;

    // If the car has completely moved past the right edge of the window...
    if(carX > 800)
        // ...reset it to the left side so it can re-enter the screen.
        carX = -300;

    // Requests the window to redraw using the updated car position.
    glutPostRedisplay();
    // Registers this update function again after about 16 ms for smooth animation.
    glutTimerFunc(16, update, 0);
}

// Program entry point where GLUT and the rendering setup are initialized.
int main(int argc, char** argv) {
    // Initializes GLUT and passes command-line arguments.
    glutInit(&argc, argv);
    // Enables double buffering and RGB color mode.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Sets the initial window size in pixels.
    glutInitWindowSize(800, 600);
    // Creates the window with the title shown in the title bar.
    glutCreateWindow("Moving Car");

    // Sets the background color to black with full opacity.
    glClearColor(0, 0, 0, 1);
    // Selects the projection matrix so we can set up the viewing area.
    glMatrixMode(GL_PROJECTION);
    // Resets the projection matrix to the identity matrix.
    glLoadIdentity();
    // Creates a 2D orthographic projection matching the window coordinates.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the display function that draws each frame.
    glutDisplayFunc(display);
    // Starts the timer immediately to begin the animation loop.
    glutTimerFunc(0, update, 0);

    // Enters the GLUT event loop and keeps the program running.
    glutMainLoop();
    // Returns 0 to indicate successful program termination.
    return 0;
}
