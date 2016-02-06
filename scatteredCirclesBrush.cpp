//
// pointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredCirclesBrush.h"

extern float frand();

ScatteredCirclesBrush::ScatteredCirclesBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredCirclesBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void ScatteredCirclesBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	float x_rand_1 = (((float)rand()/RAND_MAX)-0.5)*30;
	float y_rand_1 = (((float)rand()/RAND_MAX)-0.5)*30;

	float x_rand_2 = (((float)rand()/RAND_MAX)-0.5)*30;
	float y_rand_2 = (((float)rand()/RAND_MAX)-0.5)*30;

	Point source_1=Point(source.x+x_rand_1, source.y+y_rand_1);
	Point source_2=Point(source.x+x_rand_2, source.y+y_rand_2);

	if ( pDoc == NULL ) {
		printf( "ScatteredCirclesBrush::BrushMove  document is NULL\n" );
		return;
	}

	int size = pDoc->getSize();
	float radius = size/2;
	GLint circle_points = 100; 

	for(float i=0;i<radius;i+=0.02){
		glBegin(GL_LINE_LOOP); 
		SetColor( source );
		for (int j = 0; j < circle_points; j++) {    
		   float angle = 2*PI*j/circle_points; 
		   glVertex2f(target.x+i*cos(angle), target.y+i*sin(angle)); 
		} 
		glEnd();

		glBegin(GL_LINE_LOOP); 
		SetColor( source_1 );
		for (int j = 0; j < circle_points; j++) {    
		   float angle = 2*PI*j/circle_points; 
		   glVertex2f(target.x+x_rand_1+i*cos(angle), target.y+y_rand_1+i*sin(angle)); 
		} 
		glEnd();

		glBegin(GL_LINE_LOOP); 
		SetColor( source_2 );
		for (int j = 0; j < circle_points; j++) {    
		   float angle = 2*PI*j/circle_points; 
		   glVertex2f(target.x+x_rand_2+i*cos(angle), target.y+y_rand_2+i*sin(angle)); 
		} 
		glEnd();
	}

}

void ScatteredCirclesBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}


void ScatteredCirclesBrush::RightBrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void ScatteredCirclesBrush::RightBrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredCirclesBrush::BrushMove  document is NULL\n" );
		return;
	}

	glBegin( GL_POINTS );
		SetColor( source );

		glVertex2d( target.x, target.y );

	glEnd();
}

void ScatteredCirclesBrush::RightBrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

