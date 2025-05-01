#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sstream>
#include <complex>
//Partnered with Anna :3 

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

enum class State
{
    CALCULATING;
    DISPLAYING;
};

class ComplexPlane :: public Drawable
{
    public:
        ComplexPlane(int, int);
        void draw(RenderTarget&, RenderStates) const;
        void zoomIn();
        void zoomOut();
        void setCenter(vector2i);
        void setMouseLocation(Vector2i);
        void loadText(Text&);
        void updateRender();

    private:
        size_t countIterations(Vector2f);
        void iterationsToRGB(size_t, Unit8&, Unit8&, Unit8&);
        Vector2f mapPixelToCoords(Vector2i);
        VertexArray m_vArray;
        State m_state;
        Vector2f m_mouseLocation;
        Vector2i m_pizel_size;
        Vector2f m_plane_center;
        Vector2f m_plane_size;
        int m_zoomCount;
        float m_aspectRatio;

};

#endif
