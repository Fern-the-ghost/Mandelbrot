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
    unsigned long long int x = BASE_WIDTH * (BASE_ZOOM)
}

void ComplexPlane::zoomOut()
{

}

void ComplexPlane::setCenter(vector2i mousePixel)
{

}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{

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
