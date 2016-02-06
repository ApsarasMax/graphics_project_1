//
// pointBrush.h
//
// The header file for Point Brush. 
//

#ifndef POINTBRUSH_H
#define POINTBRUSH_H

#include "impBrush.h"
#include "math.h"

#define PI 3.1415926535897

class PointBrush : public ImpBrush
{
public:
	PointBrush( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );

	void RightBrushBegin( const Point source, const Point target );
	void RightBrushMove( const Point source, const Point target );
	void RightBrushEnd( const Point source, const Point target );
};

#endif
