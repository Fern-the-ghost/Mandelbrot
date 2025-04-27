#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

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