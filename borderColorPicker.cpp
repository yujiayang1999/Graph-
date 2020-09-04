#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    this->borderSize = borderSize;
	this->fillColor = fillColor;
	this->img = img;
	this->tolerance = tolerance;
}

HSLAPixel borderColorPicker::operator()(point p)
{
	if(p.x < borderSize || p.y < borderSize ||
          p.x > img.width()-1-borderSize || p.y > img.height()-1-borderSize){
		return fillColor;
	}else if(img.getPixel(p.x,p.y)->dist(p.c.color)>tolerance){
		return fillColor;
	}
		for(int tmpx=p.x-borderSize; tmpx<=p.x+borderSize; tmpx++) {
			for(int tmpy=p.y-borderSize; tmpy<=p.y+borderSize; tmpy++){
				if(tmpx == p.x && tmpy ==p.y) continue;
				int disx = p.x-tmpx;
				int disy = p.y-tmpy;
				HSLAPixel* curr = img.getPixel(tmpx, tmpy);
				if((disx*disx+disy*disy) <= borderSize*borderSize){
					if((tmpx>=0 && tmpx <= img.width()-1 && tmpy >=0 && tmpy <= img.height()-1)&&(curr->dist(p.c.color)>tolerance))
					return fillColor;
		        }
			}
		}
		return *img.getPixel(p.x,p.y);
}

			
