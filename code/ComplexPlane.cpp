#include "ComplexPlane.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
//Partnered with Anna :3

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    //m_pixel_size = 
    //m_aspectRatio = 
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_State = State::CALCULATING;
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
    m_State = CALCULATING;
}

void ComplexPlane::zoomOut()
{
    m_zoomCount--;
    unsigned long long int x = BASE_WIDTH * (pow(BASE_ZOOM,m_ZoomCount));
    unsigned long long int y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM,m_ZoomCount));
    m_plane_size = (x,y);
    m_State = CALCULATING;
}

void ComplexPlane::setCenter(vector2i mousePixel)
{
    m_plane_center = Vector2f(ComplexPlane::mapPixelToCoords);
    m_State = CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
    m_mouseLocation = Vector2f(COMPLEXPLANE::mapPixelToCoords);
}

void ComplexPlane::loadText(Text& text)
{
    
}

void ComplexPlane::updateRender()
{
    if (m_State == CALCULATING)
    {
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {

            }
        }
    }
}

int ComplexPlane::countIterations(Vector2f coord)
{

}

void ComplexPlane::iterationsToRGB(size_t count, Unit8& r, Unit8& g, Unit8& b)
{

}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{

}
