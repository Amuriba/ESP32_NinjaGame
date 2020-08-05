
/*   clase para generar el Audio */
/* autor Andres Murillo          */
#include "Content\SoundWAVData.h"

#define C_0  3-4
#define Cs0   4-4
#define D_0   5-4
#define Ds0  6-4
#define E_0   7-4
#define F_0  8-4
#define Fs0  9-4
#define G_0  10-4
#define Gs0  11-4


#define A_0   12-4
#define As0  13-4
#define B_0   14-4
#define C_1  15-4
#define Cs1   16-4
#define D_1   17-4
#define Ds1  18-4
#define E_1   19-4
#define F_1  20-4
#define Fs1   21-4
#define G_1  22-4
#define Gs1   23-4

#define A_1   A_0+12
#define As1   As0+12
#define B_1   B_0+12

#define C_2   C_1+12
#define Cs2   Cs1+12
#define D_2   D_1+12
#define Ds2   Ds1+12
#define E_2   E_1+12
#define F_2   F_1+12
#define Fs2   Fs1+12
#define G_2   G_1+12
#define Gs2   Gs1+12

#define A_2   A_1+12
#define As2   As1+12
#define B_2   B_1+12

#define C_3   C_2+12
#define Cs3   Cs2+12
#define D_3   D_2+12
#define Ds3   Ds2+12
#define E_3   E_2+12
#define F_3   F_2+12
#define Fs3   Fs2+12
#define G_3   G_2+12
#define Gs3   Gs2+12

#define A_3   A_2+12
#define As3   As2+12
#define B_3   B_2+12
#define C_4   C_3+12
#define Cs4   Cs3+12
#define D_4   D_3+12
#define Ds4   Ds3+12
#define E_4   E_3+12
#define F_4   F_3+12
#define Fs4   Fs3+12
#define G_4   G_3+12
#define Gs4   Gs3+12

#define A_4   A_3+12
#define As4   As3+12
#define B_4   B_3+12

#define C_5   C_4+12
#define Cs5   Cs4+12
#define D_5   D_4+12
#define Ds5   Ds4+12
#define E_5   E_4+12
#define F_5   F_4+12
#define Fs5   Fs4+12
#define G_5   G_4+12
#define Gs5   Gs4+12

#define A_5   A_4+12
#define As5   As4+12
#define B_5   B_4+12

#define C_6   C_5+12
#define Cs6   Cs5+12
#define D_6   D_5+12
#define Ds6   Ds5+12
#define E_6   E_5+12
#define F_6   F_5+12
#define Fs6   Fs5+12
#define G_6   G_5+12
#define Gs6   Gs5+12

#define A_6   A_5+12
#define As6   As5+12
#define B_6   B_5+12

#define C_7   C_6+12
#define Cs7   Cs6+12
#define D_7   D_6+12
#define Ds7   Ds6+12
#define E_7   E_6+12
#define F_7   F_6+12
#define Fs7   Fs6+12
#define G_7   G_6+12
#define Gs7   Gs6+12
#define KOFF 0xff

#define MAX_BOMBO 2200
#define MAX_REDOBLE 2056
#define MAX_JUMP 3900
#define MAX_THROW 3300
#define MAX_CRASH 8400
#define MAX_GRITO 4512
#define MAX_ESPADA 2080
#define MAX_OSC 255
#define MAX_WAVE 4000

struct Channel
{
    int fase_ch;
    int frec_ch;
    int Volumen_ch;
    int valor_ch;
    uint8_t valor_conv_ch;
    int nota;
    int play;
    int instrumento;
};


struct Music
{
    int Play;
    int PAT_INDEX;
    int limit;
    int numero_de_canales;
    int cont_song;
    int song_size;
    int track_index;
    unsigned int BMP;

};

struct EFF_CONTROL
{
    unsigned char Effect_NUM;
    unsigned int Deep;
    unsigned char Enable;
    unsigned int delay;
    unsigned int reverb1;
    unsigned int reverb2;
    unsigned int reverb3;
    unsigned int reverb4;
    unsigned int reverb5;
    unsigned int chorus;
    unsigned int pitch;
    unsigned int fasor;
    unsigned int Max_count;

};

const short tabladefrecuencias[] = {
0, 12, 13,14,15,16,17,18,19,20,21,22,24,25,27,
28,30,32,34,36,38,40,43,45,48,51,54,
57,60,64,68,71,76,80,85,91,96,102,108,
114,121,129,137,144,153,161,172,182,192,202,215,
228,241,257,271,286,306,324,344,364,386,409,433,
459,487,516,547,579,614,651,690,731,774,821,870,
};

class AudioGen {
    public:
    Music song;
    Channel CH0,CH1,CH2,CH3,CH4,CH5,CH6,CH7,CH8,CH9,CH10,CH11,CH12;
    EFF_CONTROL effect;
    uint16_t valor;
    uint16_t valor_FX;
    uint8_t Pattern[16048];
    uint8_t track[256];
    uint8_t Pattern_size[256];
    uint16_t reverb[3000];
    uint8_t WAVE1[4000];

void wr_play_song(unsigned int BMP,uint8_t CMD)
{    
    song.Play=CMD; 
    song.BMP=BMP;      
}

void wr_start_song()
{
    song.Play=1;   
}

void wr_stop_song()
{
    song.Play=0;  
}

void effect_channel(uint8_t tipo, unsigned int deep)
{   
    effect.Enable=tipo;    
    effect.Effect_NUM=tipo;    
    effect.Deep=deep;   

    if(effect.Deep>999)effect.Deep=999;
            effect.reverb1=effect.Deep;
            effect.reverb2=effect.Deep*2;
            effect.reverb3=effect.Deep*3;
            effect.reverb4=2000;
            effect.reverb5=2500; 
    
}

void copy_WAVE(const uint8_t *WAVE)
{
    unsigned int index=0;  
      
    while(index<4000)
    {
        
            WAVE1[index] = WAVE[index];
            index++;
        
    }
}

void wr_play_fx(uint16_t FREC,uint8_t CMD,uint8_t volumen,uint8_t CH, uint8_t intrumento)
{
    uint16_t temp;    
    uint16_t frec=FREC;    
       
    uint8_t play=CMD;
  

   temp=CH & 0x0f;
    switch(temp)
    {
        case 1:
            CH6.play = play;
            CH6.instrumento = intrumento;
            CH6.Volumen_ch = volumen;
            CH6.frec_ch = frec;
            break;

        case 2:
            CH7.play = play;
            CH7.instrumento = intrumento;
            CH7.Volumen_ch = volumen;
            CH7.frec_ch = frec;

            break;

        case 3:
            CH8.play = play;
            CH8.instrumento = intrumento;
            CH8.Volumen_ch = volumen;
            CH8.frec_ch = frec;

            break;

        case 4:
            CH9.play = play;
            CH9.instrumento = intrumento;
            CH9.Volumen_ch = volumen;
            CH9.frec_ch = frec;
            break;
        case 5:
            CH10.play = play;
            CH10.instrumento = intrumento;
            CH10.Volumen_ch = volumen;
            CH10.frec_ch = frec;
            break;
        case 6:
            CH11.play = play;
            CH11.instrumento = intrumento;
            CH11.Volumen_ch = volumen;
            CH11.frec_ch = frec;
            break;
        case 7:
            CH12.play = play;
            CH12.instrumento = intrumento;
            CH12.Volumen_ch = volumen;
            CH12.frec_ch = frec;
           break;

    }
   
}

void FX_lamparas(int lampara_num)
{
    if(lampara[lampara_num].seleccionada==1 && lampara_FX[lampara_num].play_romper==0)
    {
        lampara_FX[lampara_num].SEC_Contador = 1;
        lampara_FX[lampara_num].play_romper=1;
    }
    if(lampara_FX[lampara_num].play_romper==1)
    {
        lampara_FX[lampara_num].SEC_Contador ++;
        if(lampara_FX[lampara_num].SEC_Contador == 10)
        {
            wr_play_fx(tabladefrecuencias[D_5],0x01,15,0x03,0x07);
        }
        if(lampara_FX[lampara_num].SEC_Contador == 200)
        {
            wr_play_fx(tabladefrecuencias[E_5],0x01,15,0x03,0x07);
        }
        if(lampara_FX[lampara_num].SEC_Contador == 400)
        {
            wr_play_fx(tabladefrecuencias[G_5],0x01,15,0x03,0x07);
        }
        if(lampara_FX[lampara_num].SEC_Contador == 600)
        {
            lampara[lampara_num].seleccionada=0;
            lampara_FX[lampara_num].SEC_Contador = 0;
            wr_play_fx(tabladefrecuencias[G_5],0x01,0,0x03,0x07);
            lampara_FX[lampara_num].play_romper=0;
        }
    }


}

void FX_enemigo(int enemigo_num)
{
    if(boss_FX.play_lanzando==1)
    {       
        if(boss.FX_tiempo >20)
        {
            boss.FX_tiempo=0;
            wr_play_fx(tabladefrecuencias[boss_FX.SEC_Contador+60],0x01,20,0x06,0x07);
            boss_FX.SEC_Contador+=3;
        }
        if(boss_FX.SEC_Contador > 20)
        {
            boss_FX.play_lanzando=0;
            boss_FX.SEC_Contador=0;
            wr_play_fx(0,0x01,0,0x06,0x07);
        }
    }
    if (enemigo_num < 10)
    {
        if(enemigo[enemigo_num].flag_ataque_estado>0 && Enemigo_FX[enemigo_num].play_atacando==0 && enemigo[enemigo_num].muerto == 0)
            {
                Enemigo_FX[enemigo_num].play_atacando = 1;
                if (enemigo[enemigo_num].Enemigo_tipo == NINJA_ESPADA)
                {
                    wr_play_fx(tabladefrecuencias[D_4],0x01,30,0x03,0x02);
                }        
            }
            if(enemigo[enemigo_num].flag_ataque_estado==0)
            {
                Enemigo_FX[enemigo_num].play_atacando=0;

            }       

            if(enemigo[enemigo_num].estado == GOLPE_MUERTE_1 && Enemigo_FX[enemigo_num].play_muriendo == 0)
            {
                Enemigo_FX[enemigo_num].play_muriendo = 1;
                wr_play_fx(tabladefrecuencias[C_3],0x01,30,0x02,0x01);
            }
            if(enemigo[enemigo_num].muerto == 1)
            {
                Enemigo_FX[enemigo_num].play_muriendo = 0;
            }
    }
    
            


    if(boss.estado == GOLPE_MUERTE_1 && boss_FX.play_muriendo == 0)
    {
        boss_FX.play_muriendo = 1;
        wr_play_fx(tabladefrecuencias[A_2],0x01,30,0x02,0x01);
    }
    

    if(boss.muerto == 1 || boss.estado != GOLPE_MUERTE_1 )
    {
        boss_FX.play_muriendo = 0;
    }
}

void FX_jugador1()
{
//char buf[15];
    uint8_t nota1,nota2;

    if(Jugador1_FX.play_fambox_cod==1)
    {
       if(Jugador1.FX_tiempo > 50)
       {
           nota1 = FAMBOX_COD_tone[Jugador1_FX.SEC_Contador];
           nota2 = FAMBOX_COD_tone[Jugador1_FX.SEC_Contador+2];
           if(nota1 !=0xff && nota2 !=0xff)
              Jugador1_FX.SEC_Contador+=4;
           if(nota1 < 128 || nota2 < 128)
           {
               wr_play_fx(tabladefrecuencias[nota1-12],0x01,FAMBOX_COD_tone[Jugador1_FX.SEC_Contador+1]-0x10,0x04,0x07);
               wr_play_fx(tabladefrecuencias[nota2-12],0x01,FAMBOX_COD_tone[Jugador1_FX.SEC_Contador+3]-0x10,0x05,0x07);
           }
           else
           {
               wr_play_fx(0,0x01,0,0x04,0x07);
               wr_play_fx(0,0x01,0,0x05,0x07);
                    Jugador1_FX.play_fambox_cod = 0;
                    Jugador1_FX.SEC_Contador = 0;               
           }
            Jugador1.FX_tiempo=0;
       }
    }

    if(Niveles.pausa==1 && Jugador1_FX.play_pausa==0)
    {
       Jugador1_FX.play_pausa=1;
       Jugador1_FX.SEC_Contador = 0;
       Jugador1.FX_tiempo=0;
    }
    if(Jugador1_FX.play_pausa==1)
    {
       if(Jugador1.FX_tiempo > 50)
       {
           nota1 = Pausa_tone[Jugador1_FX.SEC_Contador];
           nota2 = Pausa_tone[Jugador1_FX.SEC_Contador+2];
           if(nota1 !=0xff && nota2 !=0xff)
              Jugador1_FX.SEC_Contador+=4;
           if(nota1 < 128 || nota2 < 128)
           {
               wr_play_fx(tabladefrecuencias[nota1-12],0x01,Pausa_tone[Jugador1_FX.SEC_Contador+1]-0x10,0x04,0x05);
               wr_play_fx(tabladefrecuencias[nota2-12],0x01,Pausa_tone[Jugador1_FX.SEC_Contador+3]-0x10,0x05,0x07);
           }
           else
           {
               wr_play_fx(0,0x01,0,0x04,0x07);
               wr_play_fx(0,0x01,0,0x05,0x08);
               if(Niveles.pausa==0)
               {
                    Jugador1_FX.play_pausa = 0;
                    Jugador1_FX.SEC_Contador = 0;
               }
           }
            Jugador1.FX_tiempo=0;
       }
    }

    if(Jugador1.flag_ataque_estado > 0 && Jugador1_FX.play_atacando==0)
    {
        Jugador1_FX.play_atacando=1;
        wr_play_fx(tabladefrecuencias[C_4],0x01,28,0x01,0x02);
    }
    if(Jugador1.flag_ataque_estado == 0)
    {
        Jugador1_FX.play_atacando=0;
    }   

    if((read_controller&boton_B)==0 && Jugador1_FX.play_saltando==0 && Jugador1.flag_cayendo == 1)
    {
        Jugador1_FX.play_saltando=1;
        wr_play_fx(tabladefrecuencias[E_4],0x01,22,0x01,0x03);
    }
    if(Jugador1.flag_cayendo == 0)
    {
        Jugador1_FX.play_saltando=0;
    }
    if (Jugador1.muerto==1 && Jugador1_FX.play_muriendo == 0)
    {
        wr_stop_song();
        wr_play_song(1500,0x00);
        Jugador1_FX.play_muriendo = 1;
        Jugador1_FX.SEC_Contador = 0;
    }
    if(Jugador1_FX.play_muriendo == 1 && Jugador1_FX.play_pausa==0)
    {
       if(Jugador1.FX_tiempo > 90)
       {
           nota1 = Dead_tone[Jugador1_FX.SEC_Contador];
           nota2 = Dead_tone[Jugador1_FX.SEC_Contador+1];
           if(nota1 !=0xff && nota2 !=0xff)
              Jugador1_FX.SEC_Contador+=2;
           if(nota1 < 128 || nota2 < 128)
           {               
               wr_play_fx(tabladefrecuencias[nota1],0x01,6,0x04,0x07);
               wr_play_fx(tabladefrecuencias[nota2],0x01,6,0x05,0x07);
           }
           else
           {
               wr_play_fx(0,0x01,0,0x04,0x07);
               wr_play_fx(0,0x01,0,0x05,0x07);
               if(Jugador1.muerto==0)
               {
                    Jugador1_FX.play_muriendo = 0;
                    Jugador1_FX.SEC_Contador = 0;
               }
               wr_start_song(); // se vuelve a reproducir la cancion principal
               //wr_start_song(); // se envia dos veces el comando para asegurar, error del SPI :S
           }
            Jugador1.FX_tiempo=0;
       }
    }

}


    void music()
    {

        int temp=0;
        

    /******************** canal de audio 1 ****************************************/

        if(CH0.Volumen_ch>0)
        {
            temp = CH0.fase_ch>>7;
            CH0.fase_ch = CH0.fase_ch + CH0.frec_ch;
            if(CH0.instrumento==1)
            {
                if(CH0.play == 1)
                {                    
                    CH0.valor_ch=BOMBO[temp]* CH0.Volumen_ch;
                    if(temp > MAX_BOMBO)
                    {                        
                        CH0.fase_ch = 0;
                        CH0.play = 0;
                    }
                }
                else
                {
                    CH0.fase_ch = 0;
                }
            }
            else
                if(CH0.instrumento==2)
                {
                    if(CH0.play == 1)
                    {                        
                        CH0.valor_ch = REDOBLE[temp]* CH0.Volumen_ch;
                        if(temp > MAX_REDOBLE)
                        {                            
                            CH0.fase_ch = 0;
                            CH0.play = 0;
                        }
                    }
                    else
                    {
                        CH0.fase_ch = 0;
                    }
                }
                else
                    if(CH0.instrumento==3)
                    {
                        if(CH0.play == 1)
                        {
                            CH0.valor_ch = CRASH[temp]* CH0.Volumen_ch;
                            if(temp > MAX_CRASH)
                            {
                                CH0.fase_ch = 0;
                                CH0.play = 0;
                            }
                        }
                        else
                        {
                            CH0.fase_ch = 0;
                        }
                    }
                    else
                        if(CH0.instrumento==4)
                        {
                            CH0.valor_ch =Sierra[temp]* CH0.Volumen_ch;
                            if(temp > MAX_OSC) CH0.fase_ch = 0;
                        }
                        else
                            if(CH0.instrumento==5)
                            {
                                CH0.valor_ch = cuadrada[temp]* CH0.Volumen_ch;
                                if(temp > MAX_OSC)
                                {
                                    CH0.fase_ch = 0;
                                }
                            }
                            else
                                if(CH0.instrumento==6)
                                {
                                    if(temp > MAX_OSC)
                                    {
                                        CH0.fase_ch = 0;
                                        temp=0;
                                    }
                                    CH0.valor_ch = triangulo[temp]* CH0.Volumen_ch;
                                }

        }
    /******************************************************************/
    /******************** canal de audio 2 ****************************************/
        if(CH1.Volumen_ch>0)
        {
            temp = CH1.fase_ch>>7;
            CH1.fase_ch = CH1.fase_ch + CH1.frec_ch;
            if(CH1.instrumento==1)
            {
                if(CH1.play == 1)
                {                    
                    CH1.valor_ch = BOMBO[temp]* CH1.Volumen_ch;
                    if(temp > MAX_BOMBO)
                    {                        
                        CH1.fase_ch = 0;
                        CH1.play = 0;
                    }
                }
                else
                {
                    CH1.fase_ch = 0;
                }
            }
            else
                if(CH1.instrumento==2)
                {
                    if(CH1.play == 1)
                    {                        
                        CH1.valor_ch = REDOBLE[temp]* CH1.Volumen_ch;
                        if(temp > MAX_REDOBLE)
                        {                            
                            CH1.fase_ch = 0;
                            CH1.play = 0;
                        }
                    }
                    else
                    {
                        CH1.fase_ch = 0;
                    }

                }
                else
                    if(CH1.instrumento==3)
                    {
                        if(CH1.play == 1)
                        {
                            CH1.valor_ch = CRASH[temp]* CH1.Volumen_ch;
                            if(temp > MAX_CRASH)
                            {
                                CH1.fase_ch = 0;
                                CH1.play = 0;
                            }
                        }
                        else
                        {
                            CH1.fase_ch = 0;
                        }
                    }
                    else
                        if(CH1.instrumento==4)
                        {
                            CH1.valor_ch =Sierra[temp]* CH1.Volumen_ch;
                            if(temp > MAX_OSC) CH1.fase_ch = 0;
                        }
                        else
                            if(CH1.instrumento==5)
                            {

                                CH1.valor_ch =cuadrada[temp]* CH1.Volumen_ch;
                                if(temp > MAX_OSC) CH1.fase_ch = 0;

                            }
                            else
                                if(CH1.instrumento==6)
                                {

                                    CH1.valor_ch = triangulo[temp]* CH1.Volumen_ch;
                                    if(temp > 254) CH1.fase_ch = 0;

                                }
        }


    /******************************************************************/
    /******************** canal de audio 2 ****************************************/


        if(CH2.Volumen_ch>0)
        {
            temp = CH2.fase_ch>>7;
            CH2.fase_ch = CH2.fase_ch + CH2.frec_ch;
            if(CH2.instrumento==1)
            {
                if(CH2.play == 1)
                {
                    CH2.valor_ch = BOMBO[temp]* CH2.Volumen_ch;
                    if(temp > MAX_BOMBO)
                    {
                        CH2.fase_ch = 0;
                        CH2.play = 0;
                    }
                }
                else
                {
                    CH2.fase_ch = 0;
                }

            }
            else
                if(CH2.instrumento==2)
                {
                    if(CH2.play == 1)
                    {
                        CH2.valor_ch = REDOBLE[temp]* CH2.Volumen_ch;
                        if(temp > MAX_REDOBLE)
                        {
                            CH2.fase_ch = 0;
                            CH2.play = 0;
                        }
                    }
                    else
                    {
                        CH2.fase_ch = 0;
                    }

                }
                else
                    if(CH2.instrumento==3)
                    {
                        if(CH2.play == 1)
                        {
                            CH2.valor_ch = CRASH[temp]* CH2.Volumen_ch;
                            if(temp > MAX_CRASH)
                            {
                                CH2.fase_ch = 0;
                                CH2.play = 0;
                            }
                        }
                        else
                        {
                            CH2.fase_ch = 0;
                        }
                    }
                    else
                        if(CH2.instrumento==4)
                        {
                            CH2.valor_ch =Sierra[temp]* CH2.Volumen_ch;
                            if(temp > MAX_OSC) CH2.fase_ch = 0;
                        }
                        else
                            if(CH2.instrumento==5)
                            {

                                CH2.valor_ch =cuadrada[temp]* CH2.Volumen_ch;
                                if(temp > MAX_OSC) CH2.fase_ch = 0;

                            }
                            else
                                if(CH2.instrumento==6)
                                {

                                    CH2.valor_ch = triangulo[temp]* CH2.Volumen_ch;
                                    if(temp > MAX_OSC) CH2.fase_ch = 0;

                                }

        }
    /******************************************************************/
    /******************** canal de audio 3 ****************************************/


        if(CH3.Volumen_ch>0)
        {
            temp = CH3.fase_ch>>7;
            CH3.fase_ch = CH3.fase_ch + CH3.frec_ch;
            if(CH3.instrumento==1)
            {
                if(CH3.play == 1)
                {
                    CH3.valor_ch = BOMBO[temp]* CH3.Volumen_ch;
                    if(temp > MAX_BOMBO)
                    {
                        CH3.fase_ch = 0;
                        CH3.play = 0;
                    }
                }
                else
                {
                    CH3.fase_ch = 0;
                }

            }
            else
                if(CH3.instrumento==2)
                {
                    if(CH3.play == 1)
                    {

                        CH3.valor_ch = REDOBLE[temp]* CH3.Volumen_ch;
                        if(temp > MAX_REDOBLE)
                        {
                            CH3.fase_ch = 0;
                            CH3.play = 0;
                        }
                    }
                    else
                    {
                        CH3.fase_ch = 0;
                    }

                }
                else
                    if(CH3.instrumento==3)
                    {
                        if(CH3.play == 1)
                        {
                            CH3.valor_ch = CRASH[temp]* CH3.Volumen_ch;
                            if(temp > MAX_CRASH)
                            {
                                CH3.fase_ch = 0;
                                CH3.play = 0;
                            }
                        }
                        else
                        {
                            CH3.fase_ch = 0;
                        }
                    }
                    else
                        if(CH3.instrumento==4)
                        {
                            CH3.valor_ch =Sierra[temp]* CH3.Volumen_ch;
                            if(temp > MAX_OSC) CH3.fase_ch = 0;
                        }
                        else
                            if(CH3.instrumento==5)
                            {

                                CH3.valor_ch =cuadrada[temp]* CH3.Volumen_ch;
                                if(temp > MAX_OSC) CH3.fase_ch = 0;

                            }
                            else
                                if(CH3.instrumento==6)
                                {

                                    CH3.valor_ch = triangulo[temp]* CH3.Volumen_ch;
                                    if(temp > 254) CH3.fase_ch = 0;

                                }

        }
    /******************************************************************/
    /******************** canal de audio 4 ****************************************/


        if(CH4.Volumen_ch>0)
        {
            temp = CH4.fase_ch>>7;
            CH4.fase_ch = CH4.fase_ch + CH4.frec_ch;
            if(CH4.instrumento==1)
            {
                if(CH4.play == 1)
                {
                    CH4.valor_ch = BOMBO[temp]* CH4.Volumen_ch;
                    if(temp > MAX_BOMBO)
                    {
                        CH4.fase_ch = 0;
                        CH4.play = 0;
                    }
                }
                else
                {
                    CH4.fase_ch = 0;
                }

            }
            else
                if(CH4.instrumento==2)
                {
                    if(CH4.play == 1)
                    {
                        CH4.valor_ch = REDOBLE[temp]* CH4.Volumen_ch;
                        if(temp > MAX_REDOBLE)
                        {
                            CH4.fase_ch = 0;
                            CH4.play = 0;
                        }
                    }
                    else
                    {
                        CH4.fase_ch = 0;
                    }

                }
                else
                    if(CH4.instrumento==3)
                    {
                        if(CH4.play == 1)
                        {
                            CH4.valor_ch = CRASH[temp]* CH4.Volumen_ch;
                            if(temp > MAX_CRASH)
                            {
                                CH4.fase_ch = 0;
                                CH4.play = 0;
                            }
                        }
                        else
                        {
                            CH4.fase_ch = 0;
                        }
                    }
                    else
                        if(CH4.instrumento==4)
                        {
                            CH4.valor_ch =Sierra[temp]* CH4.Volumen_ch;
                            if(temp > MAX_OSC) CH4.fase_ch = 0;
                        }
                        else
                            if(CH4.instrumento==5)
                            {

                                CH4.valor_ch =cuadrada[temp]* CH4.Volumen_ch;
                                if(temp > MAX_OSC) CH4.fase_ch = 0;

                            }
                            else
                                if(CH4.instrumento==6)
                                {

                                    CH4.valor_ch = triangulo[temp]* CH4.Volumen_ch;
                                    if(temp > 254) CH4.fase_ch = 0;

                                }

        }
    /******************************************************************/
    /******************** canal de audio 5 ****************************************/
        if(CH5.Volumen_ch>0)
        {
            temp = CH5.fase_ch>>7;
            CH5.fase_ch = CH5.fase_ch + CH5.frec_ch;
            if(CH5.instrumento==1)
            {
                if(CH5.play == 1)
                {
                    CH5.valor_ch = BOMBO[temp]* CH5.Volumen_ch;
                    if(temp > MAX_BOMBO)
                    {
                        CH5.fase_ch = 0;
                        CH5.play = 0;
                    }
                }
                else
                {
                    CH5.fase_ch = 0;
                }

            }
            else
                if(CH5.instrumento==2)
                {
                    if(CH5.play == 1)
                    {
                        CH5.valor_ch = REDOBLE[temp]* CH5.Volumen_ch;
                        if(temp > MAX_REDOBLE)
                        {
                            CH5.fase_ch = 0;
                            CH5.play = 0;
                        }
                    }
                    else
                    {
                        CH5.fase_ch = 0;
                    }

                }
                else
                    if(CH5.instrumento==3)
                    {
                        if(CH5.play == 1)
                        {
                            CH5.valor_ch = CRASH[temp]* CH5.Volumen_ch;
                            if(temp > MAX_CRASH)
                            {
                                CH5.fase_ch = 0;
                                CH5.play = 0;
                            }
                        }
                        else
                        {
                            CH5.fase_ch = 0;
                        }
                    }
                    else
                        if(CH5.instrumento==4)
                        {
                            CH5.valor_ch =Sierra[temp]* CH5.Volumen_ch;
                            if(temp > MAX_OSC) CH5.fase_ch = 0;
                        }
                        else
                            if(CH5.instrumento==5)
                            {

                                CH5.valor_ch =cuadrada[temp]* CH5.Volumen_ch;
                                if(temp > MAX_OSC) CH5.fase_ch = 0;

                            }
                            else
                                if(CH5.instrumento==6)
                                {

                                    CH5.valor_ch = triangulo[temp]* CH5.Volumen_ch;
                                    if(temp > 254)
                                        CH5.fase_ch = 0;

                                }

        }

    /******************************************************************/


        valor = CH0.valor_ch+CH1.valor_ch+CH2.valor_ch+CH3.valor_ch+CH4.valor_ch+CH5.valor_ch;
    }

    void FX()
    {
    unsigned int temp=0;
    
    /******************** canal de audio 6 ****************************************/

        if(CH6.Volumen_ch>0)
        {
            temp = CH6.fase_ch>>7;
            CH6.fase_ch = CH6.fase_ch + CH6.frec_ch;
            if(CH6.instrumento==1)
            {
                if(CH6.play == 1)
                {
                    CH6.valor_ch=Grito[temp]* CH6.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH6.fase_ch = 0;
                        CH6.play = 0;
                    }
                }
                else
                {
                    CH6.fase_ch = 0;
                }

            }
            else
                if(CH6.instrumento==2)
                {
                    if(CH6.play == 1)
                    {
                        CH6.valor_ch = Espada[temp]* CH6.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH6.fase_ch = 0;
                            CH6.play = 0;
                        }
                    }
                    else
                    {
                        CH6.fase_ch = 0;
                    }

                }else
                    if(CH6.instrumento==3)
                    {
                        if(CH6.play == 1)
                        {
                            CH6.valor_ch = JUMP[temp]* CH6.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH6.fase_ch = 0;
                                CH6.play = 0;
                            }
                        }
                        else
                        {
                            CH6.fase_ch = 0;
                        }

                    }else
                        if(CH6.instrumento==4)
                        {
                            if(CH6.play == 1)
                            {
                                CH6.valor_ch = WAVE1[temp]* CH6.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH6.fase_ch = 0;
                                    CH6.play = 0;
                                }
                            }
                            else
                            {
                                CH6.fase_ch = 0;
                            }

                        }else
                            if(CH6.instrumento==5)
                            {
                                CH6.valor_ch =Sierra[temp]* CH6.Volumen_ch;
                                if(temp > MAX_OSC) CH6.fase_ch = 0;
                            }
                            else
                                if(CH6.instrumento==7)
                                {
                                    CH6.valor_ch = cuadrada[temp]* CH6.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH6.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH6.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH6.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH6.valor_ch = triangulo[temp]* CH6.Volumen_ch;
                                    }

        }
    /******************************************************************/

        /******************** canal de audio 7 ****************************************/

        if(CH7.Volumen_ch>0)
        {
            temp = CH7.fase_ch>>7;
            CH7.fase_ch = CH7.fase_ch + CH7.frec_ch;
            if(CH7.instrumento==1)
            {
                if(CH7.play == 1)
                {

                    CH7.valor_ch=Grito[temp]* CH7.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH7.fase_ch = 0;
                        CH7.play = 0;
                    }
                }
                else
                {
                    CH7.fase_ch = 0;
                }

            }
            else
                if(CH7.instrumento==2)
                {
                    if(CH7.play == 1)
                    {
                        CH7.valor_ch = Espada[temp]* CH7.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH7.fase_ch = 0;
                            CH7.play = 0;
                        }
                    }
                    else
                    {
                        CH7.fase_ch = 0;
                    }

                }else
                    if(CH7.instrumento==3)
                    {
                        if(CH7.play == 1)
                        {
                            CH7.valor_ch = JUMP[temp]* CH7.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH7.fase_ch = 0;
                                CH7.play = 0;
                            }
                        }
                        else
                        {
                            CH7.fase_ch = 0;
                        }

                    }else
                        if(CH7.instrumento==4)
                        {
                            if(CH7.play == 1)
                            {
                                CH7.valor_ch = WAVE1[temp]* CH7.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH7.fase_ch = 0;
                                    CH7.play = 0;
                                }
                            }
                            else
                            {
                                CH7.fase_ch = 0;
                            }

                        }else
                            if(CH7.instrumento==5)
                            {
                                CH7.valor_ch =Sierra[temp]* CH7.Volumen_ch;
                                if(temp > MAX_OSC) CH7.fase_ch = 0;
                            }
                            else
                                if(CH7.instrumento==7)
                                {
                                    CH7.valor_ch = cuadrada[temp]* CH7.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH7.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH7.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH7.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH7.valor_ch = triangulo[temp]* CH7.Volumen_ch;
                                    }

        }
    /******************************************************************/

    /******************** canal de audio 8 ****************************************/

        if(CH8.Volumen_ch>0)
        {
            temp = CH8.fase_ch>>7;
            CH8.fase_ch = CH8.fase_ch + CH8.frec_ch;
            if(CH8.instrumento==1)
            {
                if(CH8.play == 1)
                {

                    CH8.valor_ch=Grito[temp]* CH8.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH8.fase_ch = 0;
                        CH8.play = 0;
                    }
                }
                else
                {
                    CH8.fase_ch = 0;
                }

            }
            else
                if(CH8.instrumento==2)
                {
                    if(CH8.play == 1)
                    {
                        CH8.valor_ch = Espada[temp]* CH8.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH8.fase_ch = 0;
                            CH8.play = 0;
                        }
                    }
                    else
                    {
                        CH8.fase_ch = 0;
                    }

                }else
                    if(CH8.instrumento==3)
                    {
                        if(CH8.play == 1)
                        {
                            CH8.valor_ch = JUMP[temp]* CH8.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH8.fase_ch = 0;
                                CH8.play = 0;
                            }
                        }
                        else
                        {
                            CH8.fase_ch = 0;
                        }

                    }else
                        if(CH8.instrumento==4)
                        {
                            if(CH8.play == 1)
                            {
                                CH8.valor_ch = WAVE1[temp]* CH8.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH8.fase_ch = 0;
                                    CH8.play = 0;
                                }
                            }
                            else
                            {
                                CH8.fase_ch = 0;
                            }

                        }else
                            if(CH8.instrumento==5)
                            {
                                CH8.valor_ch =Sierra[temp]* CH8.Volumen_ch;
                                if(temp > MAX_OSC) CH8.fase_ch = 0;
                            }
                            else
                                if(CH8.instrumento==7)
                                {
                                    CH8.valor_ch = cuadrada[temp]* CH8.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH8.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH8.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH8.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH8.valor_ch = triangulo[temp]* CH8.Volumen_ch;
                                    }

        }
    /******************************************************************/

    /******************** canal de audio 9 ****************************************/

        if(CH9.Volumen_ch>0)
        {
            temp = CH9.fase_ch>>7;
            CH9.fase_ch = CH9.fase_ch + CH9.frec_ch;
            if(CH9.instrumento==1)
            {
                if(CH9.play == 1)
                {

                    CH9.valor_ch=Grito[temp]* CH9.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH9.fase_ch = 0;
                        CH9.play = 0;
                    }
                }
                else
                {
                    CH9.fase_ch = 0;
                }

            }
            else
                if(CH9.instrumento==2)
                {
                    if(CH9.play == 1)
                    {
                        CH9.valor_ch = Espada[temp]* CH9.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH9.fase_ch = 0;
                            CH9.play = 0;
                        }
                    }
                    else
                    {
                        CH9.fase_ch = 0;
                    }

                }else
                    if(CH9.instrumento==3)
                    {
                        if(CH9.play == 1)
                        {
                            CH9.valor_ch = JUMP[temp]* CH9.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH9.fase_ch = 0;
                                CH9.play = 0;
                            }
                        }
                        else
                        {
                            CH9.fase_ch = 0;
                        }

                    }else
                        if(CH9.instrumento==4)
                        {
                            if(CH9.play == 1)
                            {
                                CH9.valor_ch = WAVE1[temp]* CH9.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH9.fase_ch = 0;
                                    CH9.play = 0;
                                }
                            }
                            else
                            {
                                CH9.fase_ch = 0;
                            }

                        }else
                            if(CH9.instrumento==5)
                            {
                                CH9.valor_ch =Sierra[temp]* CH9.Volumen_ch;
                                if(temp > MAX_OSC) CH9.fase_ch = 0;
                            }
                            else
                                if(CH9.instrumento==7)
                                {
                                    CH9.valor_ch = cuadrada[temp]* CH9.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH9.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH9.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH9.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH9.valor_ch = triangulo[temp]* CH9.Volumen_ch;
                                    }

        }
    /******************************************************************/
    /******************** canal de audio 10 ****************************************/

        if(CH10.Volumen_ch>0)
        {
            temp = CH10.fase_ch>>7;
            CH10.fase_ch = CH10.fase_ch + CH10.frec_ch;
            if(CH10.instrumento==1)
            {
                if(CH10.play == 1)
                {

                    CH10.valor_ch=Grito[temp]* CH10.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH10.fase_ch = 0;
                        CH10.play = 0;
                    }
                }
                else
                {
                    CH10.fase_ch = 0;
                }

            }
            else
                if(CH10.instrumento==2)
                {
                    if(CH10.play == 1)
                    {
                        CH10.valor_ch = Espada[temp]* CH10.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH10.fase_ch = 0;
                            CH10.play = 0;
                        }
                    }
                    else
                    {
                        CH10.fase_ch = 0;
                    }

                }else
                    if(CH10.instrumento==3)
                    {
                        if(CH10.play == 1)
                        {
                            CH10.valor_ch = JUMP[temp]* CH10.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH10.fase_ch = 0;
                                CH10.play = 0;
                            }
                        }
                        else
                        {
                            CH10.fase_ch = 0;
                        }

                    }else
                        if(CH10.instrumento==4)
                        {
                            if(CH10.play == 1)
                            {
                                CH10.valor_ch = WAVE1[temp]* CH10.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH10.fase_ch = 0;
                                    CH10.play = 0;
                                }
                            }
                            else
                            {
                                CH10.fase_ch = 0;
                            }

                        }else
                            if(CH10.instrumento==5)
                            {
                                CH10.valor_ch =Sierra[temp]* CH10.Volumen_ch;
                                if(temp > MAX_OSC) CH10.fase_ch = 0;
                            }
                            else
                                if(CH10.instrumento==7)
                                {
                                    CH10.valor_ch = cuadrada[temp]* CH10.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH10.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH10.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH10.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH10.valor_ch = triangulo[temp]* CH10.Volumen_ch;
                                    }

        }
    /******************************************************************/

    /******************** canal de audio 11 ****************************************/

        if(CH11.Volumen_ch>0)
        {
            temp = CH11.fase_ch>>7;
            CH11.fase_ch = CH11.fase_ch + CH11.frec_ch;
            if(CH11.instrumento==1)
            {
                if(CH11.play == 1)
                {

                    CH11.valor_ch=Grito[temp]* CH11.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH11.fase_ch = 0;
                        CH11.play = 0;
                    }
                }
                else
                {
                    CH11.fase_ch = 0;
                }

            }
            else
                if(CH11.instrumento==2)
                {
                    if(CH11.play == 1)
                    {
                        CH11.valor_ch = Espada[temp]* CH11.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH11.fase_ch = 0;
                            CH11.play = 0;
                        }
                    }
                    else
                    {
                        CH11.fase_ch = 0;
                    }

                }else
                    if(CH11.instrumento==3)
                    {
                        if(CH11.play == 1)
                        {
                            CH11.valor_ch = JUMP[temp]* CH11.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH11.fase_ch = 0;
                                CH11.play = 0;
                            }
                        }
                        else
                        {
                            CH11.fase_ch = 0;
                        }

                    }else
                        if(CH11.instrumento==4)
                        {
                            if(CH11.play == 1)
                            {
                                CH11.valor_ch = WAVE1[temp]* CH11.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH11.fase_ch = 0;
                                    CH11.play = 0;
                                }
                            }
                            else
                            {
                                CH11.fase_ch = 0;
                            }

                        }else
                            if(CH11.instrumento==5)
                            {
                                CH11.valor_ch =Sierra[temp]* CH11.Volumen_ch;
                                if(temp > MAX_OSC) CH11.fase_ch = 0;
                            }
                            else
                                if(CH11.instrumento==7)
                                {
                                    CH11.valor_ch = cuadrada[temp]* CH11.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH11.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH11.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH11.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH11.valor_ch = triangulo[temp]* CH11.Volumen_ch;
                                    }

        }
    /******************************************************************/

    /******************** canal de audio 12 ****************************************/

        if(CH12.Volumen_ch>0)
        {
            temp = CH12.fase_ch>>7;
            CH12.fase_ch = CH12.fase_ch + CH12.frec_ch;
            if(CH12.instrumento==1)
            {
                if(CH12.play == 1)
                {

                    CH12.valor_ch=Grito[temp]* CH12.Volumen_ch;
                    if(temp > MAX_GRITO)
                    {
                        CH12.fase_ch = 0;
                        CH12.play = 0;
                    }
                }
                else
                {
                    CH12.fase_ch = 0;
                }

            }
            else
                if(CH12.instrumento==2)
                {
                    if(CH12.play == 1)
                    {
                        CH12.valor_ch = Espada[temp]* CH12.Volumen_ch;
                        if(temp > MAX_ESPADA)
                        {
                            CH12.fase_ch = 0;
                            CH12.play = 0;
                        }
                    }
                    else
                    {
                        CH12.fase_ch = 0;
                    }

                }else
                    if(CH12.instrumento==3)
                    {
                        if(CH12.play == 1)
                        {
                            CH12.valor_ch = JUMP[temp]* CH12.Volumen_ch;
                            if(temp > MAX_JUMP)
                            {
                                CH12.fase_ch = 0;
                                CH12.play = 0;
                            }
                        }
                        else
                        {
                            CH12.fase_ch = 0;
                        }

                    }else
                        if(CH12.instrumento==4)
                        {
                            if(CH12.play == 1)
                            {
                                CH12.valor_ch = WAVE1[temp]* CH12.Volumen_ch;
                                if(temp > MAX_WAVE)
                                {
                                    CH12.fase_ch = 0;
                                    CH12.play = 0;
                                }
                            }
                            else
                            {
                                CH12.fase_ch = 0;
                            }

                        }else
                            if(CH12.instrumento==5)
                            {
                                CH12.valor_ch =Sierra[temp]* CH12.Volumen_ch;
                                if(temp > MAX_OSC) CH12.fase_ch = 0;
                            }
                            else
                                if(CH12.instrumento==7)
                                {
                                    CH12.valor_ch = cuadrada[temp]* CH12.Volumen_ch;
                                    if(temp > MAX_OSC)
                                    {
                                        CH12.fase_ch = 0;
                                    }
                                }
                                else
                                    if(CH12.instrumento==8)
                                    {
                                        if(temp > MAX_OSC)
                                        {
                                            CH12.fase_ch = 0;
                                            temp=0;
                                        }
                                        CH12.valor_ch = triangulo[temp]* CH12.Volumen_ch;
                                    }

        }


        if(CH6.play==0)
            CH6.valor_ch = 128;
        if(CH7.play==0)
            CH7.valor_ch = 128;
        if(CH8.play==0)
            CH8.valor_ch = 128;
        if(CH9.play==0)
            CH9.valor_ch = 128;
        if(CH10.play==0)
            CH10.valor_ch = 128;
        if(CH11.play==0)
            CH11.valor_ch = 128;  
        if(CH12.play==0)
            CH12.valor_ch = 128;    

    /******************************************************************/
    valor_FX= CH6.valor_ch + CH7.valor_ch + CH8.valor_ch +CH9.valor_ch+CH10.valor_ch+CH11.valor_ch+CH12.valor_ch;
    }

    void AudioUpdate(uint16_t *AudioBuffer, int part)
    {
        //int sample;
        int limit = part + 256;
        for (size_t i = part; i < limit; i++)
        {
            music();
            FX();            
            //AudioBuffer[i]= (valor>>4) + (valor_FX>>4) + 100;   
            switch(effect.Effect_NUM)
            {
                case 0:
                    AudioBuffer[i] = (valor_FX>>4)+(valor>>4);//+reverb[index_reverb];
                    break;

                case 1:
                    AudioBuffer[i] = (valor_FX>>5)+(valor>>5)+((reverb[effect.reverb1++]+reverb[effect.reverb2++]+reverb[effect.reverb3++])>>2);//+reverb[effect.reverb4++]+reverb[effect.reverb5++];
                    reverb[effect.delay++]=((valor_FX>>5)+(valor>>5));

                    if(effect.delay>3000)effect.delay=0;

                    if(effect.reverb1>3000)
                        effect.reverb1=0;

                    if(effect.reverb2>3000)
                        effect.reverb2=0;

                    if(effect.reverb3>3000)
                        effect.reverb3=0;

                    if(effect.reverb4>3000)
                        effect.reverb4=0;

                    if(effect.reverb5>3000)
                        effect.reverb5=0;
                    break;

            }

            
        } 
        
    }

    void WR_AUDIO_DATA(const uint8_t PATTERN[],const uint8_t TRACK[],const uint8_t PAT_SIZE[],int numero_canales,int numero_patrones,int size)
    {
        int index=0;   
    Serial.println("Audio PAttern");
    int col=0;

    song.track_index=0;
    song.cont_song = 0;
    song.PAT_INDEX=0;
    song.limit=0;
    CH0.nota=0xff;
    CH1.nota=0xff;
    CH2.nota=0xff;
    CH3.nota=0xff;
    CH4.nota=0xff;
    CH5.nota=0xff;
    CH6.nota=0xff;
    CH0.instrumento=0xff;
    CH1.instrumento=0xff;
    CH2.instrumento=0xff;
    CH3.instrumento=0xff;
    CH4.instrumento=0xff;
    CH5.instrumento=0xff;
    CH6.instrumento=0xff;


    while(index<15000)
    {        
        Pattern[index]=PATTERN[index];
        
        index++;
    }    
    index=0;
    while(index<256)
    {        
        track[index]=TRACK[index];  
        //Serial.printf("0x%02X,",track[index]);  
        
        index++;      
    }
    
    index=0;
    while(index<256)
    {
        Pattern_size[index]=PAT_SIZE[index];
        index++;
        
    }
   
    song.numero_de_canales=numero_canales;
    //song.limit=numero_patrones;
    song.song_size=size;   
    
}

    void player()
    {
        unsigned int temp=0;
        if(song.Play == 1)
        {
            if (song.PAT_INDEX < song.limit)
            {             
                if(Pattern[song.PAT_INDEX]!=0xff)
                        CH0.nota = Pattern[song.PAT_INDEX];
                else
                    CH0.nota = 0xff;
                if(Pattern[song.PAT_INDEX+3]!=0xff)
                        CH1.nota = Pattern[song.PAT_INDEX+3];
                else
                    CH1.nota = 0xff;
                if(Pattern[song.PAT_INDEX+6]!=0xff)
                        CH2.nota = Pattern[song.PAT_INDEX+6];
                else
                    CH2.nota = 0xff;
                if(Pattern[song.PAT_INDEX+9]!=0xff)
                        CH3.nota = Pattern[song.PAT_INDEX+9];
                else
                    CH3.nota = 0xff;
                if(Pattern[song.PAT_INDEX+12]!=0xff)
                        CH4.nota = Pattern[song.PAT_INDEX+12];
                else
                        CH4.nota = 0xff;
                if(Pattern[song.PAT_INDEX+15]!=0xff)
                        CH5.nota = Pattern[song.PAT_INDEX+15];
                else
                    CH5.nota = 0xff;

                if(Pattern[song.PAT_INDEX+1]!=0xff)
                        CH0.instrumento = Pattern[song.PAT_INDEX+1];
                if(Pattern[song.PAT_INDEX+4]!=0xff)
                        CH1.instrumento = Pattern[song.PAT_INDEX+4];
                if(Pattern[song.PAT_INDEX+7]!=0xff)
                        CH2.instrumento = Pattern[song.PAT_INDEX+7];
                if(Pattern[song.PAT_INDEX+10]!=0xff)
                        CH3.instrumento = Pattern[song.PAT_INDEX+10];
                if(Pattern[song.PAT_INDEX+13]!=0xff)
                        CH4.instrumento = Pattern[song.PAT_INDEX+13];
                if(Pattern[song.PAT_INDEX+16]!=0xff)
                        CH5.instrumento = Pattern[song.PAT_INDEX+16];



                if(Pattern[song.PAT_INDEX+2]==0xff && CH0.nota < 128)
                    CH0.Volumen_ch = 20;
                if( Pattern[song.PAT_INDEX+2] < 128)
                    CH0.Volumen_ch = Pattern[song.PAT_INDEX+2] - 0x10;

                if(Pattern[song.PAT_INDEX+5]==0xff && CH1.nota < 128)
                    CH1.Volumen_ch = 20;
                if(Pattern[song.PAT_INDEX+5] < 128)
                    CH1.Volumen_ch = Pattern[song.PAT_INDEX+5] - 0x10;

                if(Pattern[song.PAT_INDEX+8]==0xff && CH2.nota < 128)
                    CH2.Volumen_ch = 16;
                if(Pattern[song.PAT_INDEX+8] < 128)
                    CH2.Volumen_ch = Pattern[song.PAT_INDEX+8] - 0x10;

                if(Pattern[song.PAT_INDEX+11]==0xff && CH3.nota < 128)
                    CH3.Volumen_ch = 16;
                if(Pattern[song.PAT_INDEX+11] < 128)
                    CH3.Volumen_ch = Pattern[song.PAT_INDEX+11] - 0x10;

                if(Pattern[song.PAT_INDEX+14]==0xff && CH4.nota < 128)
                    CH4.Volumen_ch = 16;
                if(Pattern[song.PAT_INDEX+14] < 128)
                    CH4.Volumen_ch = Pattern[song.PAT_INDEX+14] - 0x10;


                if(Pattern[song.PAT_INDEX+17]==0xff && CH5.nota < 128)
                    CH5.Volumen_ch = 16;
                if(Pattern[song.PAT_INDEX+17] < 128)
                    CH5.Volumen_ch = Pattern[song.PAT_INDEX+17] - 0x10;



                    song.PAT_INDEX=song.PAT_INDEX + song.numero_de_canales*3;
                    if(CH0.nota < 128)
                    {                     
                        if(CH0.instrumento < 4 || CH0.Volumen_ch==0)
                        CH0.fase_ch=0;
                        CH0.play =1;
                        CH0.frec_ch =  tabladefrecuencias[CH0.nota-12];
                    }
                    else
                    {

                    }

                    if(CH1.nota < 128)
                    {                     
                        if(CH1.instrumento < 4|| CH1.Volumen_ch==0)
                        CH1.fase_ch=0;
                        CH1.play =1;
                        CH1.frec_ch =  tabladefrecuencias[CH1.nota-12];
                    }
                    else
                    {

                    }

                    if(CH2.nota < 128)
                    {
                        if(CH2.instrumento < 4|| CH2.Volumen_ch==0)
                        CH2.fase_ch=0;
                        CH2.play =1;
                        CH2.frec_ch =  tabladefrecuencias[CH2.nota-12];
                    }
                    else
                    {
                        CH2.play=0;
                    }

                    if(CH3.nota < 128)
                    {
                        if(CH3.instrumento < 4|| CH3.Volumen_ch==0)
                        CH3.fase_ch=0;
                        CH3.play =1;
                        CH3.frec_ch =  tabladefrecuencias[CH3.nota-12];
                    }
                    else
                    {
                        CH3.play=0;
                    }

                    if(CH4.nota < 128)
                    {
                        if(CH4.instrumento < 4|| CH4.Volumen_ch==0)
                        CH4.fase_ch=0;
                        CH4.play =1;
                        CH4.frec_ch =  tabladefrecuencias[CH4.nota-12];
                    }
                    else
                    {
                        CH4.play=0;
                    }

                    if(CH5.nota < 128)
                    {
                        if(CH5.instrumento < 4|| CH5.Volumen_ch==0)
                        CH5.fase_ch=0;
                        CH5.play =1;
                        CH5.frec_ch =  tabladefrecuencias[CH5.nota-12];
                    }
                    else
                    {
                        CH5.play=0;

                    }

            }
            if(song.PAT_INDEX >= song.limit)
            {
                song.track_index = track[song.cont_song];
                song.PAT_INDEX=0;
                temp=0;
                //LED_VERDE=~LED_VERDE;
                while(temp < song.track_index)
                {
                    song.PAT_INDEX = song.PAT_INDEX + song.numero_de_canales*Pattern_size[temp++]*3;
                }
                song.limit = song.PAT_INDEX+Pattern_size[temp]*song.numero_de_canales*3;
                song.cont_song++;
            }

            if (song.cont_song > song.song_size)
            {
                song.track_index=0;
                song.cont_song = 0;
                song.PAT_INDEX=0;
                song.limit=0;
                song.cont_song=0;

            }
        }
        if(song.Play==0)
        {
           song.track_index=0;
           song.cont_song = 0;
           song.PAT_INDEX=0;
           song.limit=0;
           CH0.nota=0xff;
           CH1.nota=0xff;
           CH2.nota=0xff;
           CH3.nota=0xff;
           CH4.nota=0xff;
           CH5.nota=0xff;
           CH6.nota=0xff;
           CH0.instrumento=0xff;
           CH1.instrumento=0xff;
           CH2.instrumento=0xff;
           CH3.instrumento=0xff;
           CH4.instrumento=0xff;
           CH5.instrumento=0xff;
           CH6.instrumento=0xff;
        }

    }
};