#include "ComplexPlane.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sstream>
#include <complex>
//Partnered With Anna :3 
using namespace std;

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

    RenderWindow window(VideoMode(screenWidth, screenHeight), "Complex plane!"); //RenderWindows is required to have string
    ComplexPlane plane(screenWidth, screenHeight);

    Font newFont;
    newFont.loadFromFile("./ZillaSlab-Bold.ttf"); //put a new font

    //Will be used as  a template for all of the strings
    Text newText("", newFont, 50);
    newText.setFillColor(Color::White);
    newText.setStyle(Text::Bold);

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
                std::cout << "the left button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                plane.zoomIn(); 
                Vector2i mousePos = Mouse::getPosition();
                plane.setCenter(mousePos);
            }
            else if (event.mouseButton.button == Mouse::Right) {
            //Right click will zoomOut and call setCenter on the ComplexPlane 
            //object with the (x,y) pixel location of the mouse click
                std::cout << "the right button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                
                plane.zoomOut();
                Vector2i mousePs = Mouse::getPosition();
                plane.setCenter(mousePs);

            }
            
        }
        else if (event.type == Event::MouseMoved) { 
            //Call setMouseLocation on the ComplexPlane object to store the (x,y) pixel location of the mouse click
            //This will be used later to display the mouse coordinates as it moves
            Vector2i mouseMo = Mouse::getPosition();
            plane.setCenter(mouseMo);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        //Will call the render to update it and fixing the size
        plane.updateRender();
        //Updates the text that has the location of the cursor and the center
        plane.loadText(newText);
    }
    //will draw all the items on the screen and display it for the user to see
    window.clear();
    window.draw(plane);
    window.draw(newText);
    window.display();
    
    return 0;
}
