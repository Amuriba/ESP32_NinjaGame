# ESP32_NinjaGame
Original Retro Game Based on Old school NES, SMS, Gameboy ninja game, 


It use an ESP32 WROOM card base with 4 MB of Flash

Connect an SNES controller to pins 
```
// SNES gamepad ESP 32 Pins

Pinout Data
Pin Name    SNES Pin #    ESP PIN |         _________________
GND             1           GND   |  SNES: |_°_°_°_°_|_°_°_°_)
P/S (Latch)     5         GPIO18  |          7             1          
Clock           6         GPIO05  |  
Data            4         GPIO19  |  
Vcc +5v	        7                 |  

*******************************************************************************/

```
For A/V connetion use the following, base on https://github.com/rossumur/esp_8_bit/blob/master/src/video_out.h driver, thanks for rossumur for this piece of code

```
    -----------
    |         |
    |      25 |------------------> video out
    |         |
    |      23 |---/\/\/\/----|---> audio out
    |         |     10k      |
    |         |             ---
    |  ESP32  |             --- 10nf
    |         |              |
    |         |              v gnd
    |         |
    -----------

```
