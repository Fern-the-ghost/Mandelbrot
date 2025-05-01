#include "ComplexPlane.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sstream>
#include <complex>
//Partnered with Anna :3 
using namespace std;

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    m_pixel_size = {pixelWidth, pixelHeight};
    m_aspectRatio = static_cast<float>(pixelHeight) / static_cast<float>(pixelWidth);
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = State::CALCULATING;
    m_mouseLocation = {0.f, 0.f};
    //Initialize VertexArray with Points and pixelWidth with pixelHeight
    m_vArray.setPrimitiveType(Points);
    m_vArray.resize(pixelWidth * pixelHeight );
}

void ComplexPlane::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_vArray);
}

void ComplexPlane::zoomIn()
{
    m_zoomCount++;
    unsigned long long int xNew = BASE_WIDTH * (pow(BASE_ZOOM,m_zoomCount));
    unsigned long long int yNew = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM,m_zoomCount));
    m_plane_size = {xNew,yNew};
    m_state = State::CALCULATING;
}

void ComplexPlane::zoomOut()
{
    m_zoomCount--;
    unsigned long long int xNew = BASE_WIDTH * (pow(BASE_ZOOM,m_zoomCount));
    unsigned long long int yNew = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM,m_zoomCount));
    m_plane_size = {xNew,yNew};
    m_state = State::CALCULATING;
}

void ComplexPlane::setCenter(sf::Vector2i mousePixel)
{
    m_plane_center = sf::Vector2f(ComplexPlane::mapPixelToCoords(mousePixel));
    m_state = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(sf::Vector2i mousePixel)
{
    m_mouseLocation = sf::Vector2f(ComplexPlane::mapPixelToCoords(mousePixel));
}

void ComplexPlane::loadText(sf::Text& text)
{
    stringstream words;

    words.str("");

    words << "Mandelbrot Set" << endl;
    words << "Center: (" << m_plane_center.x << "," << m_plane_center.y << ")" << endl;
    //Will update the cursor when the user moves the mouse in the window screen
    words << "Cursor: (" << m_mouseLocation.x << "," << m_mouseLocation.y << ")" << endl;
    
    words << "Left-click to Zoom in" << endl;
    words << "Right-click to Zoom out" << endl;

    text.setString(words.str());
}

void ComplexPlane::updateRender()
{
    if (m_state == State::CALCULATING)
    {
        for(int j = 0; j < m_pixel_size.x; j++)
        {
            for(int i = 0; i < m_pixel_size.y; i++)
            {
                m_vArray[j + i * m_pixel_size.x].position = {(float)j,(float)i};
                ComplexPlane::mapPixelToCoords(m_pixel_size);
                int iterCount = ComplexPlane::countIterations(m_plane_size);
                sf::Uint8 r, g, b;
                ComplexPlane::iterationsToRGB(iterCount, r, g, b);
                m_vArray[j + i * m_pixel_size.x].color = { r,g,b };
            }
        }
        m_state = State::DISPLAYING;
    }
}

int ComplexPlane::countIterations(sf::Vector2f coord)
{
    //Will count the iterations for coord
    int iter;
    for(int i = 0; i < coord.x; i++)
    {
        for(int j = 0; j <coord.y; j++)
        {
            iter++;
        }
    }
    return iter;
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{

    if(count < 51)
    {
        //color number is #04f06a
        r = 4;
        g = 241;
        b = 107;
    }
    else if(count >= 51 && count < 102)
    {
        //Color number is #abebd2
        r = 172;
        g = 236;
        b = 211;
    }
    else if(count >= 102 && count < 153)
    {
        //Color number is #9eccbb
        r = 158;
        g = 204;
        b = 187;
    }
    else if(count >= 153 && count < 204)
    {
        //Color number is #6d5a5a
        r = 109;
        g = 90;
        b = 90;
    }
    else if(count >= 204 && count < 255)
    {
        //Color number #454545
        r = 69;
        g = 69;
        b = 69;
    }
    else
    {
        //will make the color black
        r = 0;
        g = 0;
        b = 0;
    }

}

sf::Vector2f ComplexPlane::mapPixelToCoords(sf::Vector2i mousePixel)
{
    sf::Vector2f newCoord;

    float numX = m_plane_center.x - m_plane_size.x / 2.0f; //should be +c or -c
    float numY = m_plane_center.y - m_plane_size.y / 2.0f; // should be +c or -c

    newCoord.x = ((mousePixel.x)/m_plane_size.x) * m_plane_size.x + numX;
    newCoord.y = ((mousePixel.y)/m_plane_size.y) * m_plane_size.y + numY;

    return newCoord;
}
