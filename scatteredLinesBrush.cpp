//
// pointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredLinesBrush.h"

extern float frand();

ScatteredLinesBrush::ScatteredLinesBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}


Point brushDirStart_scatteredlines;
Point brushDirEnd_scatteredlines;

void ScatteredLinesBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();

	int width = pDoc->getLineWidth();


	//glPointSize( (float)size );
	glLineWidth( (float)width );

	BrushMove( source, target );


	brushDirStart_scatteredlines = source;

}

void ScatteredLinesBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if(pDoc->m_pCurrentLineMethod==ImpBrush::c_pLineMethods[1]){
		brushDirEnd_scatteredlines = source;
		int angle_brush = atan2 (brushDirEnd_scatteredlines.y - brushDirStart_scatteredlines.y,brushDirEnd_scatteredlines.x - brushDirStart_scatteredlines.x) * 180 / PI;
		if(angle_brush<0) angle_brush+=360;

		pDoc->setAngle(angle_brush);
		brushDirStart_scatteredlines = source;
	}

	float x_rand_1 = (((float)rand()/RAND_MAX)-0.5)*30;
	float y_rand_1 = (((float)rand()/RAND_MAX)-0.5)*30;

	float x_rand_2 = (((float)rand()/RAND_MAX)-0.5)*30;
	float y_rand_2 = (((float)rand()/RAND_MAX)-0.5)*30;

	Point source_1=Point(source.x+x_rand_1, source.y+y_rand_1);
	Point source_2=Point(source.x+x_rand_2, source.y+y_rand_2);

	if ( pDoc == NULL ) {
		printf( "SingleLineBrush::BrushMove  document is NULL\n" );
		return;
	}

	int size = pDoc->getSize();

	int angle = pDoc->getAngle();

	glBegin(GL_LINES);
		SetColor( source );

		glVertex2d( target.x, target.y );

		glVertex2d(target.x+size*cos(2*PI*angle/360), target.y+size*sin(2*PI*angle/360));

	glEnd();

	glBegin(GL_LINES);
		SetColor( source_1 );

		glVertex2d( target.x+x_rand_1, target.y+y_rand_1 );

		glVertex2d(target.x+x_rand_1+size*cos(2*PI*angle/360), target.y+y_rand_1+size*sin(2*PI*angle/360));

	glEnd();

	glBegin(GL_LINES);
		SetColor( source_2 );

		glVertex2d( target.x+x_rand_2, target.y+y_rand_2 );

		glVertex2d(target.x+x_rand_2+size*cos(2*PI*angle/360), target.y+y_rand_2+size*sin(2*PI*angle/360));

	glEnd();
}

void ScatteredLinesBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}



Point dragStart_scatteredlines;
Point dragEnd_scatteredlines;


void ScatteredLinesBrush::RightBrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();



	//glPointSize( (float)size );

	//BrushMove( source, target );


	dragStart_scatteredlines=source;
}

void ScatteredLinesBrush::RightBrushMove( const Point source, const Point target )
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

void ScatteredLinesBrush::RightBrushEnd( const Point source, const Point target )
{
	// do nothing so far

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	dragEnd_scatteredlines=target;
	glBegin(GL_LINES);
		glColor3ub( 0, 0, 255);
		glVertex2d(dragStart_scatteredlines.x,dragStart_scatteredlines.y ); 
		glVertex2d(dragEnd_scatteredlines.x,dragEnd_scatteredlines.y ); 

	glEnd();

	glDisable(GL_LINES);

	int angle = atan2 (dragEnd_scatteredlines.y - dragStart_scatteredlines.y,dragEnd_scatteredlines.x - dragStart_scatteredlines.x) * 180 / PI;
	if(angle<0) angle+=360;

	pDoc->setAngle(angle);


}