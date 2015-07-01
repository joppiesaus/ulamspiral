#pragma once

#include <vector>

#include <GL/glew.h>

struct Pixel
{
	Pixel(short _x, short _y) : x(_x), y(_y){}
	short x, y;
};

struct DrawPixel
{
	GLfloat x, y;
};

class PixelList
{
public:
	PixelList();
	~PixelList();

	// Destroys it(only dpx, because that's how I build it, I'm sorry but this is not a game engine)
	void destroy();

	// Adds a pixel
	void add(short x, short y);
	void add(const Pixel& pix);

	// Converts everything to NDC
	void build();

	// Draws all pixels
	void drawAll();	

private:
	std::vector<Pixel> m_pixels;
	std::vector<DrawPixel> m_dpx;
};

