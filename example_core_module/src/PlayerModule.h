/*
 * BaseModule.h
 *
 *  Created on: 19 févr. 2016
 *      Author: ange
 */

#ifndef SRC_PLAYERMODULE_H_
#define SRC_PLAYERMODULE_H_

#include "ofxPluma.h"
#include "ofUtils.h"

class PlayerModule
{
public:

    virtual std::string getDescription() const = 0;
    virtual void setup()=0;
    virtual void update()=0;
    virtual void draw() = 0;
    virtual void play()=0;
    virtual void pause()=0;
    virtual void stop()=0;
    virtual void togglePlay()=0;
    virtual void setState(int state)=0;
    virtual void fullScreen(bool full)=0;
    virtual std::string const getPostion()=0;
    virtual void setPath(std::string path)=0;

};

PLUMA_PROVIDER_HEADER(PlayerModule);
#endif /* SRC_PLAYERMODULE_H_ */
