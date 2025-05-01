#include "ComplexPlane.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sstream>
#include <complex>
//Partnered with Anna :3 

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    m_pixel_size = (pixelWidth, pixelHeight);
    m_aspectRatio = (pixelHeight) / pixelWidth;
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = STATE::CALCULATING;
    //Initialize VertexArray with Points and pixelWidth with pixelHeight
    m_vArray(Points(pixelWidth * pixelHeight));
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(m_vArray);
}

void ComplexPlane::zoomIn()
{
    m_zoomCount++;
    unsigned long long int x = BASE_WIDTH * (pow(BASE_ZOOM,m_ZoomCount));
    unsigned long long int y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM,m_ZoomCount));
    m_plane_size = (x,y);
    m_state = STATE::CALCULATING;
}

void ComplexPlane::zoomOut()
{
    m_zoomCount--;
    unsigned long long int x = BASE_WIDTH * (pow(BASE_ZOOM,m_ZoomCount));
    unsigned long long int y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM,m_ZoomCount));
    m_plane_size = (x,y);
    m_state = STATE::CALCULATING;
}

void ComplexPlane::setCenter(vector2i mousePixel)
{
    m_plane_center = Vector2f(ComplexPlane::mapPixelToCoords);
    m_state = STATE::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
    m_mouseLocation = Vector2f(COMPLEXPLANE::mapPixelToCoords);
}

void ComplexPlane::loadText(Text& text)
{
    stringstream words;

    words.str("");

    words << "Mandelbrot Set" << endl;

    //Will update the x and y coords for the center if button was clicked
    if(event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left)
    {
        words << "Center: (" << x << "," << y << ")" << endl;
    }

    //Will update the cursor when the user moves the mouse in the window screen
    if(event.type == Event::MouseMoved)
    {
        words << "Cursor: (" << x << "," << y << ")" << endl;
    }
    
    words << "Left-click to Zoom in" << endl;
    words << "Right-click to Zoom out" << endl;
}

void ComplexPlane::updateRender()
{
    if (m_State == CALCULATING)
    {
        for(int i = 0; i < m_pixel_size.y; i++)
        {
            for(int j = 0; j < m_pixel_size.x; j++)
            {
                Vector2f coord = mapPixelToCoords({j,i});
                int iterCount = countIterations(coords);
                Uint8 r,g,b;
                iterationsToRGB(itercount, r, g, b);
                int index = j + i * m_pixel_size.x;
                m_vArray[j + i * pixelWidth].position = {(float)j,(float)i};
                m_vArray[j + i * pixelWidth].color = { r,g,b };
            }
        }
        m_state = STATE::DISPLAYING;
    }
}

size_t ComplexPlane::countIterations(Vector2f coord)
{
    //Count the number of iterations for coord
}

void ComplexPlane::iterationsToRGB(size_t count, Unit8& r, Unit8& g, Unit8& b)
{
    r = (0,255);
    g = (0,255);
    b = (0,255);

    //set a rabge fron 0 to MAX_ITER either diide tvhe colors to 5 regions
    //or you can install a sliding effect on the color
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
    //would we need to use a double for loop?
    //to find a value of n in [a,b] into [c,d]
    //use ((n-a)/ (b-a)) * (d-c) + c
    //(d-c) either equals m_plane_size.x or m_plane_size.y
    //to find +c use for x: (m_plane_center.x - m_plane_size.x / 2.0)
    //to find +c use for y: (m_plane_center.y - m_plane_size.y / 2.0)
}
