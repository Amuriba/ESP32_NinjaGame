/* Adaptación del Juego de Ninja realizado en 2015 en PIC32
*  se utilizo un codigo de driver de Audio y video propiedad de 
*   Copyright (c) 2020, Peter Barrett
*  el cual es de uso Libre todo lo de mas es creación de
*  Andres Murillo
*
*
**************************************************************************************************/
//#include <Update.h>
#include <soc/rtc.h>
//#include "soc/rtc_wdt.h"
#include <Arduino.h>
#include "video_out.h"
#include "Content\TilesROM.h"
#include "Content\MapData.h"
#include "RenderBG.h"
#include "Content\ColorTable.h"
#include "Content\ImageData.h"
#include "Content\FX_sound.h"
#include "CommonFunc.h"
#include "AudioGen.h"

AudioGen AudioOut;


#include "GameLogic.h"
#include "esp_task_wdt.h"

#define TWDT_TIMEOUT_S          3
#define TASK_RESET_PERIOD_S     2



const int XRES = 320;
//const int YRES = 144;
const int YRES = 240;
int colorscreen = 0;
//Graphics graphics(XRES, YRES);
int Scroll_X;
int Scroll_Y;



bool _inited = false;
bool standard = true; // NTSC = true

uint8_t* videodata = 0;

int interval = 150;
int interval2 = 1100; // intervalo de refresco de variables 



void GameDraw(void *data)
{  
  //Serial.print("WDT config: ");
  //Serial.println(esp_task_wdt_init(3,false));
  
  //vTaskDelay(1000);
  Serial.println("VideoRender");
  Serial.println("AudioGenerator");
  int previus =0;
  
  int currentmillis = millis();  
  bool toggle=false;
  //disableCore0WDT();
  while (true)
  {
    //Serial.println(esp_task_wdt_reset());
   // rtc_wdt_feed();
    
     previus = millis();
     
     if(Vblank_Flag)
     {  
        
        VideoScreen.DrawScreen(0,0);   
        Vblank_Flag=false; 
        if(Control1.Habilitar==1)          
          Readjoy();// leer el gamepad          
        
        Dibujar_sprites(VideoScreen.SpriteVmem);        
        interval = AudioOut.song.BMP/16;
        
        vTaskDelay(3);
        
         
    }
    
      _lines = VideoScreen.frame;
        if(AudiobufferEmtyP1)// generar la primera parte del buffer de audio
        {
          
          AudiobufferEmtyP1=false;
          AudioOut.AudioUpdate(_audio_buffer,0);  
                      
        }   
        if(AudiobufferEmtyP2) // generar la segunda parte del buffer de audio
        {
          AudiobufferEmtyP2=false;
          AudioOut.AudioUpdate(_audio_buffer,256);                           
        }        
    
        if((previus-currentmillis)>interval)
        {
          currentmillis = millis();
            digitalWrite(2,HIGH); 
            AudioOut.player();      /// tareas de reproduccion de Audio, musica y efectos.
            digitalWrite(2,LOW);
            if(toggle)
            {
              toggle=false;                          
            }
            else
            {
              if(!toggle) toggle=true;                             
            }      
        }           
  }

}

void clear_screen()
    {
        if (videodata)
            memset(videodata,0,256*240);
    }


 void init_screen()
    {
        Serial.printf("init_screen\n");
        videodata = new uint8_t[256*240];      

        // center on 240?
        _lines = new uint8_t*[240];        
        const uint8_t* s = videodata;
        for (int y = 0; y < 240; y++) {
          
            _lines[y] = (uint8_t*)s;
            s += 256;
        }
        clear_screen();
        
    }

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
   rtc_clk_cpu_freq_set(RTC_CPU_FREQ_240M);              //highest cpu frequency
   init_screen(); 
    for (int x = 0; x < 256; x++)
    {    
      for (int y = 0; y < 240; y++)
      {      
        _lines[y][x] = 0;
      }    
    } 


    Serial.println("******************************************************************************");  
    Serial.print("CPU:");Serial.print(ESP.getCpuFreqMHz());Serial.println(" MHZ");
    Serial.print("RAM:");Serial.print(ESP.getHeapSize());Serial.println(" Bytes");
    Serial.print("PSRAM:");Serial.print(ESP.getPsramSize());Serial.println(" Bytes");
    Serial.print("FLASH:");Serial.print(ESP.getFlashChipSize());Serial.println(" Bytes");
    Serial.println("******************************************************************************");  
    pinMode(2,OUTPUT);    
    VideoScreen.yres = 240;
    VideoScreen.xres = 256;
    VideoScreen.init_screen(_lines);
    VideoScreen.Clear_MAP();
    VideoScreen.copy_BG_TILES(BG1_TILES,7);
    //VideoScreen.load_MAP(MAPA2,0,0,MAX_MAP2_x,MAX_MAP2_y);
//disableCore0WDT();
//disableCore1WDT();
    

    xTaskCreatePinnedToCore(GameDraw, "Game_Task",5 * 1024, NULL, 10, NULL, 0); 
    //xTaskCreatePinnedToCore(GameUpdate, "Game_Update",16* 1024, NULL, 10, NULL, 1); 
}

// Game update implemented on loop routine in core 0
int currentmicros = micros();
int previusMicros = 0;
void loop() {    
    char buf[15];
  String STRdata;
    //disableCore1WDT();
   /* STRdata = String(rtc_time_get,DEC);
        STRdata.toCharArray(buf,15);
        print_txt(buf,9,4,BG_ROJO,BLANCO);*/
        
    previusMicros = micros();
    if((previusMicros-currentmicros)>interval2)
    { 
      DelayVariables(); 
      currentmicros = micros();          
    }

    if (!_inited) { 
      NINJA_GAME_init();       
      if (_lines) {
        printf("video_init\n");
        video_init(4,3,sms_4_phase,standard); // start the A/V pump     
        _inited = true;
      } else {
      vTaskDelay(1);
    }
    //gen_ntsc_pal_tables();
  }else
     NINJA_GAME_LOOP();
   //vTaskDelay(1);
}