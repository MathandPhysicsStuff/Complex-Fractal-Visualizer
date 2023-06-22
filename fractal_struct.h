#ifndef FRACTAL_STRUCT_H
#define FRACTAL_STRUCT_H


typedef struct FractalData
{

	int x_mp, y_mp;     //mouse point
	int nx_mp, ny_mp;   //new mouse point
	long double fx_mp, fy_mp;   //floating mouse point

	long double x_point , y_point;  //point on the screen to zoom over
	long double lxoff, uxoff;       //x lower/upper offsets
	long double lyoff, uyoff;       //y lower/upper offsets

	long double xlb, xub;   //x lower/upper bounds  
	long double ylb, yub;   //y lower/upper bounds  

	int iter;
	
	//Fractal variables
	long double n;
	long double a, b;
	long double na, nb;		//next a/b
	long double rp, ip;		//real part imaginary part

} FractalData;
 
#endif
