#pragma once

#include "ComplexObject.h"
#include "ScrollTube.h"

class Tube : public ComplexObject {

public:
	Tube(Position position, std::string path, int color);
	Tube(const Tube& tube);
	virtual ~Tube();
	virtual Object* clone();

	virtual void draw();
	virtual void clear();
	virtual void move(int dx, int dy);

	static const int width = 10;

protected:
	virtual void build();
	
};
