/********************************************************************************** 
 
 Copyright (C) 2012 Syed Reza Ali (www.syedrezaali.com)
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 **********************************************************************************/

#ifndef OFXUI_WIDGETWITHLABEL
#define OFXUI_WIDGETWITHLABEL

#include "ofxUIWidget.h"

class ofxUILabel; 

class ofxUIWidgetWithLabel : public ofxUIWidget           
{
public:
    ofxUIWidgetWithLabel() : ofxUIWidget() 
    {        
 
    }
    
    virtual ~ofxUIWidgetWithLabel() 
    {

    }
        
    virtual bool hasLabel()
    {
        return true; 
    }
    
    virtual ofxUILabel* getLabelWidget()
    {
        return label;
    }
    
    virtual void toggleColors()
    {
        ofColor fill = getColorFill();
        float af = fill.a;
        ofColor back = getColorBack();
        float ab = back.a;
        
        setColorFill(ofColor(back, af));
        setColorBack(ofColor(fill, ab));
    }
    
    virtual void setModal(bool _modal)      //allows for piping mouse/touch input to widgets that are outside of parent's rect/canvas
    {
        modal = _modal;
        if(modal == true)
        {
            if(parent != NULL)
            {
                parent->addModalWidget(this);
            }
        }
        else
        {
            if(parent != NULL)
            {
                parent->removeModalWidget(this);            
            }
        }    
    }
    
protected:    
    ofxUILabel *label;
};

#endif
