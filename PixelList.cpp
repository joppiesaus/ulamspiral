#include "PixelList.h"
#include "Variables.h"


PixelList::PixelList()
{
}


PixelList::~PixelList()
{
}

void PixelList::destroy()
{
	m_dpx.clear();
}


void PixelList::add(short x, short y)
{
	m_pixels.push_back(Pixel(x, y)); // {x, y} will work too
}

void PixelList::add(const Pixel& pix)
{
	m_pixels.push_back(pix);
}

void PixelList::build()
{
	m_dpx.resize(m_pixels.size());

	for (size_t i = 0; i < m_pixels.size(); i++)
	{
		// TODO: Fix this crap
#if GRAPH_SIZE % 2 == 0
		m_dpx[i] = DrawPixel
		{
			(GLfloat)(((GLfloat)m_pixels[i].x * 2.0f) / SCREEN_SIZE),
			(GLfloat)(((GLfloat)m_pixels[i].y * 2.0f - PIXEL_SIZE * 2) / SCREEN_SIZE)
		};
#else
		m_dpx[i] = DrawPixel
		{
			(GLfloat)(((GLfloat)m_pixels[i].x * 2.0f - PIXEL_SIZE) / SCREEN_SIZE),
			(GLfloat)(((GLfloat)m_pixels[i].y * 2.0f - PIXEL_SIZE) / SCREEN_SIZE)
		};
#endif
	}
	m_pixels.clear();
}

void PixelList::drawAll()
{
	static const GLfloat NPS = (GLfloat)PIXEL_SIZE * 2.0f / SCREEN_SIZE;

	for (auto pix : m_dpx)
	{
		glBegin(GL_TRIANGLES);
		glVertex2f(pix.x, pix.y);
		glVertex2f(pix.x, pix.y + NPS);
		glVertex2f(pix.x + NPS, pix.y + NPS);
		glVertex2f(pix.x, pix.y);
		glVertex2f(pix.x + NPS, pix.y);
		glVertex2f(pix.x + NPS, pix.y + NPS);
		glEnd();
	}
}