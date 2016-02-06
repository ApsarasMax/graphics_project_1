//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Text_Display.H>
#include <Fl/Fl_Int_Input.H>

#include "impressionist.h"
#include "originalView.h"
#include "paintView.h"

#include "impBrush.h"

const int FLT_WIDTH = 5;
const int FLT_HEIGHT = 5;

class ImpressionistUI {
public:
	ImpressionistUI();
	~ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;

	Fl_Choice*			m_BrushTypeChoice;
	Fl_Choice*			m_LineDirectionMethodChoice;

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Slider*			m_BrushLineWidthSlider;
	Fl_Slider*			m_BrushAngleSlider;
	Fl_Slider*			m_BrushAlphaSlider;

	Fl_Button*          m_ClearCanvasButton;

// for filter dialog
	Fl_Window*			m_filterDialog;
	Fl_Text_Display*	m_filterText;

	Fl_Int_Input*		m_filterInput;
	Fl_Int_Input*		m_filterDivisor;
	Fl_Int_Input*		m_filterOffset;

	Fl_Button*          m_Preview;
	Fl_Button*          m_Apply;
	Fl_Button*          m_Cancle;

// for filter numbers


	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);

	int 				getLineWidth();
	void				setLineWidth(int lineWidth);

	int 				getAngle();
	void				setAngle(int angle);

	double 				getAlpha();
	void				setAlpha(double alpha);

	// Callbacks for the image filter dialogue (different from
	// the other callbacks because they aren't static)
	void				initFltDesignUI(void);
	void				updateFilter(void);

	void				cancelFilter(void);
	void				applyFilter(void);
	void				previewFilter(void);

	// filter matrix value
	double					getVal();
	double					getDivisor();
	double					getOffset();


private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nSize;
	int 	m_nLineWidth;
	int 	m_nAngle;
	float 	m_nAlpha;

	int 	m_nMyInputValue;
	int 	m_nFilterDivisor;
	int 	m_nFilterOffset;

	// These attributes are set by the filter kernel UI
	double fltKernel[FLT_WIDTH*FLT_HEIGHT];		//the kernel of the image filter
	double scale,offset;						//the divisor and offset parameter, 
												//applied after convolving to transform 
												//the filtered image into the range [0,255]


	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
	static Fl_Menu_Item		lineDirectionMethodMenu[NUM_LINE_METHOD+1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_filter(Fl_Menu_* o, void* v);

	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void	cb_lineDirectionChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void	cb_lineWidthSlides(Fl_Widget* o, void* v);
	static void	cb_angleSlides(Fl_Widget* o, void* v);
	static void	cb_alphaSlides(Fl_Widget* o, void* v);

	static void	cb_myInput(Fl_Widget* o, void* v);
	static void	cb_filterDivisor(Fl_Widget* o, void* v);
	static void	cb_filterOffset(Fl_Widget* o, void* v);
	static void	cb_preview_button(Fl_Widget* o, void* v);
	static void	cb_apply_button(Fl_Widget* o, void* v);
	static void	cb_cancel_button(Fl_Widget* o, void* v);

};

#endif

