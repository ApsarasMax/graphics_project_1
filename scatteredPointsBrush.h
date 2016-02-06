//
// pointBrush.h
//
// The header file for Point Brush. 
//

#ifndef SCATTEREDPOINTSBRUSH_H
#define SCATTEREDPOINTSBRUSH_H

#include "impBrush.h"

class ScatteredPointsBrush : public ImpBrush
{
public:
	ScatteredPointsBrush( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );

	void RightBrushBegin( const Point source, const Point target );
	void RightBrushMove( const Point source, const Point target );
	void RightBrushEnd( const Point source, const Point target );
};

#endif
