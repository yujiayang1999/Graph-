#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    HSLAPixel pt;
	pt.h = p.c.color.h;
	pt.s = p.c.color.s;
	double dist = sqrt((p.x - p.c.x)*(p.x - p.c.x) + (p.y -p.c.y)*(p.y -p.c.y));
	pt.l = p.c.color.l * pow(fadeFactor,dist);
	return pt;
}
