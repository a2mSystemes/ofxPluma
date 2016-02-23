/*
 * ofxPluma.h
 *
 *  Created on: 19 févr. 2016
 *      Author: ange
 */

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
