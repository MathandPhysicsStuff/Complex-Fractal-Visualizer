#ifndef FRACTAL_STRUCT_H
#define FRACTAL_STRUCT_H


typedef struct FractalData
{
	int x_mp, y_mp;     //mouse point
	int nx_mp, ny_mp;   //new mouse point
	double fx_mp, fy_mp;   //floating mouse point

	double x_point , y_point;  //point on the screen to zoom over
	double lxoff, uxoff;       //x lower/upper offsets
	double lyoff, uyoff;       //y lower/upper offsets

	double xlb, xub;   //x lower/upper bounds  
	double ylb, yub;   //y lower/upper bounds  

	double re;	//real point
	double im;	//imaginary point
	
	int iter;	//iteration

} FractalData;
 
#endif
