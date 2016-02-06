//
// pointBrush.h
//
// The header file for Point Brush. 
//

#ifndef SCATTEREDCIRCLESBRUSH_H
#define SCATTEREDCIRCLESBRUSH_H

#include "impBrush.h"
#include "math.h"


#define PI 3.1415926535897

class ScatteredCirclesBrush : public ImpBrush
{
public:
	ScatteredCirclesBrush( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );

	void RightBrushBegin( const Point source, const Point target );
	void RightBrushMove( const Point source, const Point target );
	void RightBrushEnd( const Point source, const Point target );
};

#endif
