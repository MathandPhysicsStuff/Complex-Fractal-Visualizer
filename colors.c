#include "colors.h"

void gray_scale(FractalData *f, int *color, int i, int brightness)
{
	color[0] = (i%259)*brightness;
	color[1] = (i%259)*brightness;
	color[2] = (i%259)*brightness;
}

void hsv(FractalData *f, int *color, int i, int brightness)
{
	double r, g, b; //red green blue
	double h, s, v; //hue saturation value
	double c, x, m;

	h = i%359;
	v = 1;
	s = 1; 
	
	c = s*v;
	x = c*(1 - fabs(fmod(h/60, 2) - 1));
	m = v - c;

	if (0 <= h && h < 60){r = c, g = x, b = 0;}
	else if (60 <= h && h < 120){r = x, g = c, b = 0;}
	else if (120 <= h && h < 180){r = 0, g = c, b = x;}
	else if (180 <= h && h < 240){r = 0, g = x, b = c;}
	else if (240 <= h && h < 300){r = x, g = 0, b = c;}
	else if (300 <= h && h < 360){r = c, g = 0, b = x;}
	
	color[0] = (r+m)*(255*brightness);
	color[1] = (g+m)*(255*brightness);
	color[2] = (b+m)*(255*brightness);
}


/*
void hsv(FractalData* f, int *color, int i, int brightness)
{
	double r, g, b; //red green blue
	double h, s, v; //hue saturation value
	double c, x, m;

	h = i%359;
	v = 1;
	s = 1; 
	
	c = s*v;
	x = c*(1 - fabs(fmod(h/60, 2) - 1));
	m = v - c;

	if (0 <= h && h < 60){r = c, g = x, b = 0;}
	else if (60 <= h && h < 120){r = x, g = c, b = 0;}
	else if (120 <= h && h < 180){r = 0, g = c, b = x;}
	else if (180 <= h && h < 240){r = 0, g = x, b = c;}
	else if (240 <= h && h < 300){r = x, g = 0, b = c;}
	else if (300 <= h && h < 360){r = c, g = 0, b = x;}
	
	color[0] = (r+m)*(255*brightness);
	color[1] = (g+m)*(255*brightness);
	color[2] = (b+m)*(255*brightness);
}
*/














