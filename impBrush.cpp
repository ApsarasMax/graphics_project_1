//
// impBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "impBrush.h"

#include <iostream>
using namespace std;

// Static class member initializations
int			ImpBrush::c_nBrushCount	= 0;
ImpBrush**	ImpBrush::c_pBrushes	= NULL;

// Static class member initializations
int			ImpBrush::c_nLineMethodCount	= 0;
ImpBrush**	ImpBrush::c_pLineMethods	= NULL;

ImpBrush::ImpBrush(ImpressionistDoc*	pDoc, 
				   const char*			name) :
					m_pDoc(pDoc), 
					m_pBrushName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and brushes
//---------------------------------------------------
ImpressionistDoc* ImpBrush::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current brush
//---------------------------------------------------
const char* ImpBrush::BrushName(void)
{
	return m_pBrushName;
}

//----------------------------------------------------
// Set the color to paint with to the color at source,
// which is the coord at the original window to sample 
// the color from
//----------------------------------------------------
void ImpBrush::SetColor (const Point source)
{
	ImpressionistDoc* pDoc = GetDocument();
	double alpha = pDoc->getAlpha();
	//cout << alpha <<endl;

	//GLubyte color[4];
	GLubyte color[3];

	memcpy ( color, pDoc->GetOriginalPixel( source ), 3 );
	//color[3] = 10;
	//cout<<color[3]<<endl;

	  
 
	//glColor4ubv( color );
	glColor3ubv( color );
	

	 
	// glEnable(GL_BLEND);
	// glDisable(GL_DEPTH_TEST);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	// glBlendColor( color[0],  color[1], color[2], 255);
	//glColor4ub( color[0],  color[1], color[2], 255);

	//glColor4ub( 255, 0, 0, 255 ); 

	      

}


