// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"
//#include <algorithm>

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname);			// called by the UI to load image
	int		saveImage(char *iname);			// called by the UI to save image


	int     clearCanvas();                  // called by the UI to clear the drawing canvas

	void applyFilter( const unsigned char* sourceBuffer, //The filter kernel
		int srcBufferWidth, int srcBufferHeight,
		unsigned char* destBuffer,
		const double *filterKernel, 
		int knlWidth, int knlHeight, 
		double divisor, double offset );

	void	setBrushType(int type);			// called by the UI to set the brushType
	void	setLineMethod(int type);		// called by the UI to set the lineMethod

	int		getSize();						// get the UI size
	void	setSize(int size);				// set the UI size
	int		getLineWidth();					// get the UI line width
	void	setLineWidth(int width);		// set the UI line width
	int		getAngle();						// get the angle
	void	setAngle(int angle);			// set the angle
	double	getAlpha();						// get the alpha
	void	setAlpha(double alpha);			// set the alpha
	char*	getImageName();					// get the current image name

	double		getVal();						// get the filter matrix value
	double		getDivisor();					// get the filter divisor value
	double		getOffset();					// get the filter offset value

	int 	min(int a, int b);				// get the min number
	

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;	
	// Bitmaps for original image and painting.
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;

	// Used by the filtering code so that we can
	// preview filters before applying.
	unsigned char*	m_ucPreviewBackup;



	// The current active brush.
	ImpBrush*			m_pCurrentBrush;	

	// The current active line direction method.
	ImpBrush*			m_pCurrentLineMethod;	

	

	// Size of the brush.
	int m_nSize;							

	ImpressionistUI*	m_pUI;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );



private:
	char			m_imageName[256];

};

extern void MessageBox(char *message);

#endif
