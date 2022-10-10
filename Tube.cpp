#include "Tube.h"

Tube::Tube(Position position, std::string path, int color) : ComplexObject(path, color) {
	currentFrame = rand() % frames.size();
	setPosition(position);
}

Tube::Tube(const Tube& tube) : ComplexObject(tube) {
	setPosition(position);
}

Tube::~Tube() {

}

Object* Tube::clone() {
	return new Tube(*this);
}

void Tube::draw() {
	//ComplexObject::draw();
	std::vector<Object*>* frame = frames[currentFrame];
	for (int i = 0; i < frame->size(); i += width) {
		(*frame)[i]->draw();
	}
}

void Tube::clear() {
	//ComplexObject::clear();
	std::vector<Object*>* frame = frames[currentFrame];
	for (int i = width - 1; i < frame->size(); i += width) {
		(*frame)[i]->clear();
	}
}

void Tube::move(int dx, int dy) {
	
	if(ScrollTube::initialProcess == true) ComplexObject::move(dx, dy);
	else {
		if (dx == -1 && dy == 0) {
			clear();	
			position.x -= 1;
			//-- zmienia pozycje wszystkich klatek procz tej w aktualnym cyklu
			for (int i = 0; i < frames.size(); ++i) {
				if (i != currentFrame) {
					std::vector<Object*>* frame = frames[i];
					for (int j = 0; j < frame->size(); ++j) {
						(*frame)[j]->move(-1, 0);
					}
				}
			}
			//--
			std::vector<Object*>* frame = frames[currentFrame];
			for (int i = 0; i < frame->size(); i += width) {
				// i + (width-1) - last
				delete (*frame)[i + width - 1];
				frame->erase(frame->begin() + (i + width - 1));
				Object* newObject = (*frame)[i]->clone();
				newObject->left();
				frame->insert(frame->begin() + i, newObject);
			}
		}
	}
}



void Tube::build() {}