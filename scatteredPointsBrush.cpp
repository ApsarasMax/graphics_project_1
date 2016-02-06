//
// pointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredPointsBrush.h"

extern float frand();

ScatteredPointsBrush::ScatteredPointsBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredPointsBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();


	//glPointSize( (float)size );
	glPointSize(1);

	BrushMove( source, target );
}

void ScatteredPointsBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredPointsBrush::BrushMove  document is NULL\n" );
		return;
	}

	int size = pDoc->getSize();
	float x=frand();


	for(int i = 0; i < 0.5*size*size; i++){
		float x_rand = (frand()-0.5)*size;
		float y_rand = (frand()-0.5)*size;
		Point source_1=Point(source.x+x_rand, source.y+y_rand);

		glBegin( GL_POINTS );
			SetColor( source_1 );

			glVertex2d( target.x+x_rand, target.y+y_rand );

		glEnd();

	}

	// glBegin( GL_POINTS );
	// 	SetColor( source );

	// 	glVertex2d( target.x, target.y );

	// glEnd();
}

void ScatteredPointsBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}



void ScatteredPointsBrush::RightBrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void ScatteredPointsBrush::RightBrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredPointsBrush::BrushMove  document is NULL\n" );
		return;
	}

	glBegin( GL_POINTS );
		SetColor( source );

		glVertex2d( target.x, target.y );

	glEnd();
}

void ScatteredPointsBrush::RightBrushEnd( const Point source, const Point target )
{
	// do nothing so far
}
