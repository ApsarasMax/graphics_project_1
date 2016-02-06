//
// pointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "singleLineBrush.h"

extern float frand();

SingleLineBrush::SingleLineBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

Point brushDirStart_singleline;
Point brushDirEnd_singleline;

void SingleLineBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();

	int width = pDoc->getLineWidth();


	//glPointSize( (float)size );
	glLineWidth( (float)width );

	BrushMove( source, target );

	brushDirStart_singleline = source;
}

void SingleLineBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "SingleLineBrush::BrushMove  document is NULL\n" );
		return;
	}

	if(pDoc->m_pCurrentLineMethod==ImpBrush::c_pLineMethods[1]){
		brushDirEnd_singleline = source;
		int angle_brush = atan2 (brushDirEnd_singleline.y - brushDirStart_singleline.y,brushDirEnd_singleline.x - brushDirStart_singleline.x) * 180 / PI;
		if(angle_brush<0) angle_brush+=360;

		pDoc->setAngle(angle_brush);
		brushDirStart_singleline = source;
	}

	int size = pDoc->getSize();

	int angle = pDoc->getAngle();

	glBegin(GL_LINES);
		SetColor( source );

		glVertex2d( target.x, target.y );

		glVertex2d(target.x+size*cos(2*PI*angle/360), target.y+size*sin(2*PI*angle/360));

	glEnd();
}

void SingleLineBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}


void SingleLineBrush::RightBrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void SingleLineBrush::RightBrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "SingleLineBrush::BrushMove  document is NULL\n" );
		return;
	}

	glBegin( GL_POINTS );
		SetColor( source );

		glVertex2d( target.x, target.y );

	glEnd();
}

void SingleLineBrush::RightBrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

