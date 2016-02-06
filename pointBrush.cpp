//
// pointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "pointBrush.h"

extern float frand();

PointBrush::PointBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

void PointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void PointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "PointBrush::BrushMove  document is NULL\n" );
		return;
	}

	glBegin( GL_POINTS );
		SetColor( source );

		glVertex2d( target.x, target.y );

	glEnd();
}

void PointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}


Point dragStart;
Point dragEnd;


void PointBrush::RightBrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();



	//glPointSize( (float)size );

	//BrushMove( source, target );


	dragStart=source;
}

void PointBrush::RightBrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "PointBrush::BrushMove  document is NULL\n" );
		return;
	}

	// glBegin( GL_POINTS );
	// 	SetColor( source );

	// 	glVertex2d( target.x, target.y );

	// glEnd();
}

void PointBrush::RightBrushEnd( const Point source, const Point target )
{
	// do nothing so far

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	dragEnd=target;
	glBegin(GL_LINES);
		glColor3ub( 0, 0, 255);
		glVertex2d(dragStart.x,dragStart.y ); 
		glVertex2d(dragEnd.x,dragEnd.y ); 

	glEnd();

	glDisable(GL_LINES);

	int angle = atan2 (dragEnd.y - dragStart.y,dragEnd.x - dragStart.x) * 180 / PI;
	if(angle<0) angle+=360;

	pDoc->setAngle(angle);


}

