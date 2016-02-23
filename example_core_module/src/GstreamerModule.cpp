/*
 * MyModule.cpp
 *
 *  Created on: 19 févr. 2016
 *      Author: ange
 */

#include "GstreamerModule.h"

void GstreamerModule::setup()
{
  player.load(this->path);
  this->totalFrames = player.getTotalNumFrames();
}
void GstreamerModule::update()
{
  player.update();
}
void GstreamerModule::draw()
{
  player.draw(0,0);
}
