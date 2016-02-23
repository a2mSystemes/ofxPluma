ofxPluma
========

ofxPluma is a currently work in progress addon. The goal of this addon is to allow modular and pluggable (with modules or plugins) development for [openFrameworks](http://openframeworks.cc/). ofxPluma make use of [pluma-frameworks](http://pluma-framework.sourceforge.net/)

## Dependencies

No deps for now.

## Usage

- Set up a module interface

```c++
/*********************************************
/*
/*file MyCoolModuleInterface.h
/*
/*********************************************/


#ifndef MYCOOLMODULEINTERFACE_H_
#define MYCOOLMODULEINTERFACE_H_
#include "ofxPluma.h"

//this interface is an abstract class with only pure virtual functions
class MyCoolModuleInterface{
    virtual std::string getDescription() const=0;
}

//create a Provider class (eg. a factory) for your Module with some Macro define in Pluma

PLUMA_PROVIDER_HEADER(MyCoolModuleInterface);
#endif /* MYCOOLMODULEINTERFACE_H_ */

```
**You NEED a .cpp source file for defining source of MyCoolModuleInterfaceProvider**

```c++
/*********************************************
/*
/*file MyCoolModuleInterface.cpp
/*
/*********************************************/


#include "MyCoolModuleInterface.h"

//PLUMA_PROVIDER_SOURCE(Type, Version, minor)
PLUMA_PROVIDER_SOURCE(MyCoolModuleInterface, 1, 1);

```

- Now you can just implement this interface

```c++
/*********************************************
/*
/*file MyCoolModule.h 
/*
/*********************************************/


#ifndef MYCOOLMODULE_H_
#define MYCOOLMODULE_H_
#include "MyCoolModuleInterface.h"

//this interface is an abstract class with only pure virtual functions
class MyCoolModule: public MyCoolModuleInterface{
    std::string getDescription() const{return "hello world !!!";};
}


//create a Provider class (eg. a factory) for your Module with some Macro define in Pluma

PLUMA_INHERIT_PROVIDER (MyCoolModule, MyCoolModuleInterface);
#endif /* MYCOOLMODULE_H_ */
```
- and now you can use your module as a Core module or a loadable module :

```c++
/*********************************************
/*
/*file ofApp.h 
/*
/*********************************************/
#pragma once


#include "ofMain.h"
#include "ofxPluma.h"
#include "MyCoolModuleInterface.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		ofxPluma::Manager moduleManager;
		std::vector<MyCoolModuleInterfaceProvider *> providers;
		MyCoolModuleInterface* myModule;

		
};

```
```c++
/*********************************************
/*
/*file ofApp.cpp 
/*
/*********************************************/
#include "ofApp.h"
/* Core modules include */
#include "MyCoolModule.h"

void ofApp::setup(){
    ofSetBackgroundColor(ofColor::white);
    moduleManager.acceptProviderType<MyCoolModuleInterfaceProvider>();
    moduleManager.addProvider(new MyCoolModuleProvider());
    //load included Modules that inherits from MyCoolModuleInterface
    //moduleManager.load(ofToDataPath("modules/MyModuleThatInheritsFromMyCoolModuleInterface"));
    moduleManager.getProviders(modulesProvider);
    std::vector<MyCoolModuleInterfaceProvider *>::iterator it;
    for (it = modulesProvider.begin(); it != modulesProvider.end(); it++)
    {
        myModule = (*it)->create();
    }
}

void ofApp:: draw(){
    ofSetColor(ofColor::black);
    // see myModule in action
    ofDrawBitmapString(myModule->getDescription(), 0, 0);
}

```



## Lmitations

for now only core module integration works. And this is a huge limitation for a plugin system. The problem relays on the compilation with static libs. In fact if you want to integrate [openFrameworks](http://openframeworks.cc/) in your module, you have to find a way of compile it with all it's dependencies.
The is a basic module.mk in the ofxPluma folder and You have to integrate it in your makefile chain.

## TODO

- better (and working :( \ ) makefile integration for external plugin compilation.
- setting up a manifest and an archive system for easier plugin integration in apps.
- A lot of other stuffs......

## Credits and license

Developed by
- Ange-Marie MAURIN A2M Systèmes : http://a2msystemes.fr

Pluma is developed by : 
- Gil Costa 
see [pluma-frameworks](http://pluma-framework.sourceforge.net/) for the license terms.

Video test file from Gâtechien.


