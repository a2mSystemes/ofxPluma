/*
 * MyModule.h
 *
 *  Created on: 19 févr. 2016
 *      Author: ange
 */

#ifndef SRC_GSTREAMERMODULE_H_
#define SRC_GSTREAMERMODULE_H_
#include "PlayerModule.h"
#include "ofVideoPlayer.h"
#include "ofLog.h"
#include "ofUtils.h"



class GstreamerModule: public PlayerModule
{
public:
  virtual ~GstreamerModule(){};

    std::string getDescription() const
    {
        //ofLogWarning("MyModule") << "get description " << test;
        return "MyModule";
    }
    void setup();
    void update();
    void draw();
    void play()
    {
        if( this->player.isPaused() )
            this->player.play();
    }
    void pause()
    {
        if ( this->player.isPlaying() )
            this->player.setPaused(true);
    }
    void setFile(std::string path)
    {
        this->path = path;
    }
    void togglePlay(){
      if(! this->player.isPaused()){
	  ofLogWarning("MyModule") << "isPlaying";
	  this->pause();
      }else{
	  ofLogWarning("MyModule") << "isPaused";
	  this->play();
      }
    }

    void setState(int state){
      switch (state){
	case 'S':
	  this->player.stop();
	  break;
	case 'P':
	  this->play();
	  break;
	default:
	  break;
      }
    }

      void stop(){
	this->player.stop();
    }

      int getPositionInt(){
	return (int) ( this->player.getPosition() * (float) this->totalFrames );
      }
      std::string const getPostion() {
	return ofToString(getPositionInt() ) + " on " + ofToString(this->totalFrames);

      }
      void fullScreen(bool full){

      }
      void setPath(std::string path){
	this->path = path;
      }
private:
    ofVideoPlayer player;
    std::string path;
    int totalFrames;

}
;
PLUMA_INHERIT_PROVIDER(GstreamerModule, PlayerModule);


#endif /* SRC_GSTREAMERMODULE_H_ */
