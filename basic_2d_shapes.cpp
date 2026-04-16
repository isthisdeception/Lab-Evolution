// Includes the GLUT library so we can create a window and draw basic shapes.
#include <GL/glut.h>

// This function draws several basic 2D primitives.
void display() {
    // Clears the color buffer using the current background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Comment label indicating the next primitive is a single point.
    // Point
    // Sets the size of points to 5 pixels.
    glPointSize(5);
    // Starts drawing points.
    glBegin(GL_POINTS);
        // Draws one point at the given coordinate.
        glVertex2i(100, 100);
    // Ends the point drawing.
    glEnd();

    // Comment label indicating the next primitive is a line.
    // Line
    // Starts drawing a line using two endpoints.
    glBegin(GL_LINES);
        // First endpoint of the line.
        glVertex2i(150, 100);
        // Second endpoint of the line.
        glVertex2i(250, 200);
    // Ends the line drawing.
    glEnd();

    // Comment label indicating the next primitive is a triangle.
    // Triangle
    // Starts drawing a triangle using three vertices.
    glBegin(GL_TRIANGLES);
        // First vertex of the triangle.
        glVertex2i(300, 100);
        // Second vertex of the triangle.
        glVertex2i(250, 200);
        // Third vertex of the triangle.
        glVertex2i(350, 200);
    // Ends the triangle drawing.
    glEnd();

    // Comment label indicating the next primitive is a rectangle.
    // Rectangle
    // Starts drawing a quadrilateral for the rectangle.
    glBegin(GL_QUADS);
        // Bottom-left corner of the rectangle.
        glVertex2i(400, 100);
        // Bottom-right corner of the rectangle.
        glVertex2i(550, 100);
        // Top-right corner of the rectangle.
        glVertex2i(550, 200);
        // Top-left corner of the rectangle.
        glVertex2i(400, 200);
    // Ends the rectangle drawing.
    glEnd();

    // Comment label indicating the next primitive is a polygon.
    // Polygon
    // Starts drawing a polygon with multiple sides.
    glBegin(GL_POLYGON);
        // First vertex of the polygon.
        glVertex2i(600, 100);
        // Second vertex of the polygon.
        glVertex2i(650, 150);
        // Third vertex of the polygon.
        glVertex2i(630, 220);
        // Fourth vertex of the polygon.
        glVertex2i(570, 220);
        // Fifth vertex of the polygon.
        glVertex2i(550, 150);
    // Ends the polygon drawing.
    glEnd();

    // Forces OpenGL to execute the drawing commands immediately.
    glFlush();
}

// Program entry point where GLUT is initialized and the window is created.
int main(int argc, char** argv) {
    // Initializes GLUT and passes command-line arguments.
    glutInit(&argc, argv);
    // Sets the display mode to single buffering with RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial window size.
    glutInitWindowSize(800, 600);
    // Sets the initial window position on the screen.
    glutInitWindowPosition(100, 100);
    // Creates the OpenGL window with the specified title.
    glutCreateWindow("OpenGL Window");

    // Sets the background color to black.
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Defines a 2D orthographic projection for the drawing area.
    gluOrtho2D(0, 800, 0, 600);

    // Registers the function that will draw the scene.
    glutDisplayFunc(display);
    // Starts the GLUT event loop.
    glutMainLoop();

    // Returns 0 to indicate the program completed successfully.
    return 0;
}

// Includes the GLUT header again; this duplicate include does not affect behavior because the header is protected.
#include <GL/glut.h>
