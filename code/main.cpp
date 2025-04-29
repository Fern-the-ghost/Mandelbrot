#include "ComplexPlane.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
//Partnered With Anna :3

int main()
{
    unsigned int screenWidth = VideoMode::getDesktopMode().width / 2.0;
    unsigned int screenHeight = VideoMode::getDesktopMode().height / 2.0;

    /*class ComplexPlane : public Drawable { //inheritance
    public:
        VertexArray Points;
    private:
        //put smt here
    };*/
    VertexArray vertices(Points);

    RenderWindow window(VideoMode(width, height), "Complex plane!"); //RenderWindows is required to have string
    ComplexPlane plane(screenWidth, screenHeight));

    Font newFont;
    newFont.loadFromFile("./ZillaSlab-Bold.ttf"); //put a new font

    Text newText("Mandelbrot Set", newFont, 50);
    newText.setFillColor(Color::White);
    newText.setStyle(Text::Bold);
    newText.setPosition(0,0);

    Text moreText("Left-click to Zoom in", newFont,50);
    moreText.setFillColor(Color::White);
    moreText.setStyle(Text::Bold);
    moreText.setPosition(0,3);  

    Text addText("Right-click to Zoom out", newFont,50);
    addText.setFillColor(Color::White);
    addText.setStyle(Text::Bold);
    addText.setPosition(0,4);

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close(); 
        }
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                //Left click will zoomIn and call setCenter on the ComplexPlane object
                // with the(x, y) pixel location of the mouse click
                cout << "the left button was pressed" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;

                plane.zoomIn(); 
                plane.setCenter(event.mouseButton.x, event.mouseButton.y);
            }
            else if (event.mouseButton.button == Mouse::Right) {
            //Right click will zoomOut and call setCenter on the ComplexPlane 
            //object with the (x,y) pixel location of the mouse click
                cout << "the right button was pressed" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;

                plane.zoomOut();
                plane.setCenter(event.mouseButton.x, event.mouseButton.y);

            }
            
        }
        else if (event.type == Event::MouseMoved) { 
            //Call setMouseLocation on the ComplexPlane object to store the (x,y) pixel location of the mouse click
            //This will be used later to display the mouse coordinates as it moves
            plane.setMouseLocation(event.mouseMoved.x, event.mouseMoved.y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        plane.updateRender();
        plane.loadText();

        window.clear();
        window.draw(plane);
        window.draw(Text);
        window.display();
    }
    
    return 0;
}
