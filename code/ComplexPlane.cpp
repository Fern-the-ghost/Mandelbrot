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
    m_pixel_size = (pixelWidth * pixelHeight);
    m_aspectRatio = (pixelHeight / pixelWidth);
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = STATE::CALCULATING;
    //Initialize VertexArray with Points and pixelWidth with pixelHeight
    //VertexArray m_vArray(Points(pixelWidth * pixelHeight));
    //don't know if this would work on the Vertex Array part
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

    if(ComplexPlane::setCenter != (0,0))
    {
        //update the center in text(?)
    }

    if(ComplexPlane::setMouseLocation != //original location(?))
    {
        //update the mouse location in text
        //dont know if we would need to use a double for loop(?)
    }

    //Center: (0,0) will need to use setCenter
    //Cursor: (cursor.x, cursor.y) most likely will need to use MouseLocation
}

void ComplexPlane::updateRender()
{
    Uint8 = r,g,b;


    if (m_State == CALCULATING)
    {
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                //set the position of the Vertex Array
                m_vArray[j + i * pixelWidth].position = {(float)j,(float)i};
                //use ComplexPlane::mapPixelToCoords to find the pixel coord on the screen
                //use the countIterations to get the count variable
                //use the local variables for r g b to store the current pixel
                //Pass all 4 variables: count,r,g,b to iterationsToRGB
                //use a variable named color to store the VertexArray that works with j,i
            }
        }
    }
    m_state = STATE::CALCULATING;
}

int ComplexPlane::countIterations(Vector2f coord)
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
