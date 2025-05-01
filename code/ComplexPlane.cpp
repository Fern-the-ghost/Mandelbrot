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
    m_mouseLocation = {0.f, 0.f};
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
    m_plane_center = Vector2f(ComplexPlane::mapPixelToCoords(mousePixel));
    m_state = STATE::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
    m_mouseLocation = Vector2f(COMPLEXPLANE::mapPixelToCoords(mousePixel));
}

void ComplexPlane::loadText(Text& text)
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
    //Will count the iterations for coord
    size_t iter;
    for(int i = 0; i < coord.x; i++)
    {
        for(int j = 0; j <coord.y; j++)
        {
            iter++;
        }
    }
    return iter;
}

void ComplexPlane::iterationsToRGB(size_t count, Unit8& r, Unit8& g, Unit8& b)
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

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
    Vector 2f coord;

    float numX = m_plane_center.x - m_plane_size.x / 2.0f;
    float numY = m_plane_center.y - m_plane_size.y / 2.0f;

    coord.x = ((mousePixel.x)/m_plane_size.x) * m_plane_size.x + numX;
    coord.y = ((mousePixel.y)/m_plane_size.y) * m_plane_size.y * numY;

    return coord;
}
