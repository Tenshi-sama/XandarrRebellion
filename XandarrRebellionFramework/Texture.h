#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Texture {
protected:
	int alpha_;
	string name_;
	SDL_Point rotation_point_;
	double rotate_;
	float scaleX_, scaleY_;
	SDL_Texture* texture_;
	bool visible_;
	int width_, height_;
	int x_, y_;

public:
	Texture();
	Texture(SDL_Renderer* r, const string& imgLocation);
	~Texture();

	bool LoadTexture(SDL_Renderer* r, const string& imgLocation);
	bool CreateTextureFromText(SDL_Renderer*r, const string& textValue, TTF_Font* textFont, SDL_Color textColor);
	void Draw(SDL_Renderer* r);

	inline int alpha() const { return alpha_; }
	inline const string& name() const { return name_; }
	inline int rotationX() const { return rotation_point_.x; }
	inline int rotationY() const { return rotation_point_.y; }
	inline double rotate() const { return rotate_; }
	inline float scaleX() const { return scaleX_; }
	inline float scaleY() const { return scaleY_; }
	inline SDL_Texture* texture() const { return texture_; }
	inline bool visible() const { return visible_; }
	inline int width() const { return width_; }
	inline int height() const { return height_; }
	inline int x() const { return x_; }
	inline int y() const { return y_; }

	void alpha(int newValue);
	inline void name(const string& newValue) { name_ = newValue; }
	inline void rotationX(const int newValue) { rotation_point_.x = newValue; }
	inline void rotationY(const int newValue) { rotation_point_.y = newValue; }
	inline void rotate(const double newValue) { rotate_ = newValue; }
	inline void scaleX(const float newValue) { scaleX_ = newValue; }
	inline void scaleY(const float newValue) { scaleY_ = newValue; }
	inline void visible(const bool newValue) { visible_ = newValue; }
	inline void width(const int newValue) { width_ = newValue; }
	inline void height(const int newValue) { height_ = newValue; }
	inline void x(const int newValue) { x_ = newValue; }
	inline void y(const int newValue) { y_ = newValue; }

};

#endif