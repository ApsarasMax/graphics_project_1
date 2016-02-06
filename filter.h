//
// pointBrush.h
//
// The header file for Point Brush. 
//

#ifndef FILTER_H
#define FILTER_H

#include "impBrush.h"

class Filter  : public ImpBrush
{
public:
		Filter( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

		void filter();
};

#endif
