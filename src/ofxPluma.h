
// *******************************************************************************
//
// ofxPluma.h
//
//     Created on: 23 févr. 2016
//      Author: Ange-Marie MAURIN
//
//
// Copyright (c) 2015 Ange-Marie MAURIN A2M Systèmes <http://a2msystemes.fr>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// *******************************************************************************

#ifndef ADDONS_OFXPLUMA_SRC_OFXPLUMA_H_
#define ADDONS_OFXPLUMA_SRC_OFXPLUMA_H_
#include "Pluma/Pluma.hpp"
#include "Pluma/Connector.hpp"
#include "Pluma/Host.hpp"
#include "Pluma/Connector.hpp"





using namespace pluma;
#define OFXPLUMA_DEFAULT_VERSION 1
#define OFXPLUMA_DEFAULT_VERSION_LOWEST 1


namespace ofxPluma
{
class Manager;
class ModuleIface;
class ModuleIfaceProvider;
class ModuleBase;
class ModuleBaseProvider;
}



class ofxPluma::Manager: public Pluma
    {}
;

class ofxPluma::ModuleIface
{
public:
    virtual ~ModuleIface()=0;
    virtual std::string getDescription() const = 0;

};

class ofxPluma::ModuleBase: public ofxPluma::ModuleIface
{
public:
    virtual ~ModuleBase();
    std::string getDescription()const
    {
        return "ofxPluma::ModuleBase";
    };
};

class test{
  static const int variable = 2;
  int const getVariable()const {return variable;}
};

PLUMA_PROVIDER_HEADER(ofxPluma::ModuleIface);
PLUMA_INHERIT_PROVIDER(ofxPluma::ModuleBase, ofxPluma::ModuleIface);




#endif /* ADDONS_OFXPLUMA_SRC_OFXPLUMA_H_ */
