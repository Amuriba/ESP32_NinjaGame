/* 
 * File:   Video_Core.h
 * Author: AMB
 *
 * Created on 3 de agosto de 2014, 10:59 PM
 */


#include <stdio.h>
#include <stdlib.h>
#define NINJA_ESPADA 0
#define NINJA_KUNAY 1
#define NINJA_PASAMANOS 2
#define NINJA_MORADO_ESPADA 3
#define NINJA_MORADO_KUNAY 4
#define NINJA_CAFE_KUNAY 5
#define NINJA_CAFE_LODO 6
#define NINJA_GRIS_HIELO 7
#define OGRO 8

#define BOSS1 9
#define BOSS2 10
#define BOSS3 11
#define BOSS4 12


#define SPR_Mirror_H 0b01000000
#define SPR_Mirror_V 0b10000000
#define SPR_Banco0   0b00000000
#define SPR_Banco1   0b00000001
#define SPR_Banco2   0b00000010
#define SPR_Banco3   0b00000011
#define SPR_visible    0b00100000
#define SPR_invisible  0b1111111111011111
#define Delay_Salto 10
#define Delay_Cayendo 7
#define Delay_Escalando 15   //10
#define Delay_Ataque 40
#define Delay_Pasamanos 50
#define Delay_Correr 20



#define ITEM_MONEDA 0
#define ITEM_SAKE 1
#define ITEM_DIAMANTE 2
#define ITEM_KUNAYS 3
#define ITEM_JAMON 4

#define POS_Y_MAX 64

#define BG_AZUL 0b00000001
#define BG_ROJO 0b00100000
#define BG_VERDE 0b00000100
#define BG_NEGRO 0b00000000
#define BG_BLANCO 0b11111111

#define AZUL 0b01000111
#define ROJO 0b11101001
#define VERDE 0b00011100
#define BLANCO 0b11111111
#define GRIS 0b11010011


#define JOY_CLK 5
#define JOY_LATCH 18
#define JOY1_DATA 19
#define JOY2_DATA 21

// control de Snes
#define Arriba 0x0800
#define Abajo 0x0400
#define Izquierda 0x0200
#define Derecha 0x0100
#define boton_A 0x0080
#define boton_B 0x8000
#define boton_X 0x0040
#define boton_Y 0x4000
#define boton_start 0x1000
#define boton_selec 0x2000
#define boton_L 0x0020
#define boton_R 0x0010



#define REPOSO 0

#define CORRER_1 1
#define CORRER_2 2
#define CORRER_3 3

#define GOLPE_MUERTE_1 4
#define GOLPE_MUERTE_2 5
#define GOLPE_MUERTE_3 6

#define SALTO_NORMAL_1 7
#define SALTO_NORMAL_2 8
#define SALTO_NORMAL_3 9
#define SALTO_NORMAL_4 10

#define SALTO_ESTATICO_1 11
#define SALTO_ESTATICO_2 12
#define SALTO_ESTATICO_3 13

#define SALTO_ATAQUE_1 14
#define SALTO_ATAQUE_2 15
#define SALTO_ATAQUE_3 16

#define CAYENDO_1 17
#define CAYENDO_2 18

#define ESCALAR_1 19
#define ESCALAR_2 20
#define ESCALAR_3 21

#define PASAMANOS_1 22
#define PASAMANOS_2 23
#define PASAMANOS_3 24


#define ATAQUE_DETENIDO_1 25
#define ATAQUE_DETENIDO_2 26
#define ATAQUE_DETENIDO_3 27

#define ATAQUE_CORRIENDO_1 28
#define ATAQUE_CORRIENDO_2 29
#define ATAQUE_CORRIENDO_3 30

#define ATAQUE_PASAMANOS_1 31
#define ATAQUE_PASAMANOS_2 32
#define ATAQUE_PASAMANOS_3 33

#define AGACHADO 34

#define ATAQUE_AGACHADO_1 35
#define ATAQUE_AGACHADO_2 36
#define ATAQUE_AGACHADO_3 37

#define BALA_AGACHADO_1 38
#define BALA_AGACHADO_2 39
#define BALA_AGACHADO_3 40

#define BALA_PASAMANO_1 41
#define BALA_PASAMANO_2 42
#define BALA_PASAMANO_3 43

#define BALA_REPOSO_1 44
#define BALA_REPOSO_2 45
#define BALA_REPOSO_3 46

#define BALA_SALTANDO_1 47
#define BALA_SALTANDO_2 48
#define BALA_SALTANDO_3 49

#define BALA_CORRIENDO_1 50
#define BALA_CORRIENDO_2 51
#define BALA_CORRIENDO_3 52

#define MUERTE_CAIDA 53

#define GOLPEADO_1 55
#define GOLPEADO_2 56
#define GOLPEADO_3 57
#define CONGELADO  58


#define DESTRUIR 59


#define BOSS_1 60
#define BOSS_2 61
#define BOSS_3 62
#define BOSS_4 63

#define DIALOGO 64


RenderScreen VideoScreen;

uint16_t read_controller=65535;
uint16_t read_controller2=65535;
unsigned int delay1=0;
unsigned int delay2=0;


int offset_adjust=100;

struct SPRITE  // estructura del sprite
{
    int X;
    int Y;
    int SPR_NUM;
    int SPR_ATTR;

}
spr[128],
spr_buff[128];

struct Nivel
{
    int numero_nivel;
    int boss_sec;
    int estado_continue;
    int contador_lamparas;
    int Contador_eventos;
    int contador_pausa;
    int opacidad;
    int estado;
    int pausa;
    int FAMBOX_cod_cont;
    int numero_enemigos;
    int enemigos_x_Zona;
    int Enemigos_inicializados;
    char boss_zone;
    char boss_music_load;
    char boss_music_play;
    int MAP_MAX_Y;
    int MAP_MAX_X;
    int MAP_INI_X;
    int MAP_INI_Y;
    int MIN_MAP_x;
    int MIN_MAP_y;
    int MAX_MAP_x;
    int MAX_MAP_y;
    int texto_intro_cont;
    int TXT_INDEX;
    int TXT_PAG;

}Niveles;


struct lampara
{
    int ATRIBUTO;
    int POS_X;
    int POS_Y;
    int POS_Y_CONT;
    int MAP_POS_Y;
    int MAP_POS_X;
    int contador;
    int spr_contador;
    int reventada;
    uint8_t seleccionada;
    int ITEM_VISIBLE;
    int ITEM;
    int Animacion_general;
    uint8_t flag_suelo;
    int expiracion;

}lampara[10];


struct Balas
{
    int SPR_POS_Y;
    int POS_X;
    int POS_Y;
    int ATRIBUTO;
    int cantidad;
    int animacion_cont;
    int MAP_POS_Y;
    int MAP_POS_X;
    int Animacion_POS;
    uint8_t flag_colision;  // define si se toco algun enemigo en la pantalla;
    uint8_t flag_lanzado;
    uint8_t flag_origen;   // dice si fue lanzado por un enemigo o el jugador

}kunay,kunay_enemigo[10],bala_boss[10],bala_enemigo[20];


struct Control
{
    uint8_t Habilitar;
    uint8_t IZ_presionado;
    uint8_t DE_presionado;
    uint8_t Arriba_presionado;
    uint8_t Abajo_presionado;
    uint8_t B_presionado;
    uint8_t A_presionado;
    uint8_t X_presionado;
    uint8_t Y_presionado;
    uint8_t Select_presionado;
    uint8_t Start_presionado;
    uint8_t L_presionado;
    uint8_t R_presionado;
    uint8_t SPR_visibles;
}Control1,Control2;

struct Jugador
{
    int ATRIBUTO;
    int POS_X_INIT;
    int POS_Y_INIT;
    int POS_X;
    int POS_X_anterior;
    int POS_Y;
    int POS_Y_anterior;
    int POS_Y_cont;
    uint8_t mirror;
    uint8_t visible;
    int Estado;
    int Estado_Anterior;
    int contador_eventos;
    int tiempo_Transparente;

    uint8_t Animacion_escalando;
    uint8_t Animacion_pasamano;
    uint8_t Animacion_caminando;
    uint8_t Animacion_saltando;
    uint8_t Animacion_cayendo;
    uint8_t Animacion_Ataque;
    uint8_t Animacion_agachado;
    uint8_t Animacion_lanzar_chunche;
    uint8_t Animacion_bala;
    uint8_t Animacion_posicion;
    uint8_t Animacion_posicion2;
    int Animacion_general;

    uint8_t flag_Obstruido_De;
    uint8_t flag_Obstruido_Iz;
    uint8_t flag_techo;
    uint8_t flag_pasamanos;
    uint8_t flag_cayendo;
    uint8_t flag_corriendo;
    uint8_t flag_saltando;
    uint8_t flag_escalando;
    uint8_t flag_lanzando_chunche;
    uint8_t flag_ataque_estado; // 0: no hay ataque, 1:ataque detenido, 2:ataque corriendo, 3: ataque pasamanos, 4: ataque saltando, 5: ataque agachado
    uint8_t flag_bala_estado;
    uint8_t flag_agachado;
    uint8_t flag_transparente;  // luego que es tocado por algo que baja energia
    
    uint8_t muerto;
    int FX_tiempo;
    int Numero_balas;
    int Numero_monedas;
    int continues;
    int puntos;
    int vidas;
    int vida;

}Jugador1,Jugador2;

/***Estructura de variables usadas para los enemigos ******************/
struct enemigo
{
    int ATRIBUTO;
    int SPRITE_NUM;
    int SPRITE_NUM1;
    int SPRITE_NUM2;
    int SPRITE_NUM3;
    int SPRITE_NUM4;
    int SPRITE_W;
    int SPRITE_H;
    int POS_X;
    int POS_Y;
    int POS_Y_CONT;
    int POS_X_CONT;
    int Offset_x;
    int MAP_POS_Y;
    int MAP_POS_X;
    uint8_t mirror;
    uint8_t dir_cambio;
    uint8_t visible;
    int estado;
    int Enemigo_tipo;
    uint8_t AnimacionPosicion;
    int Animacion_General;
    
    int estado_anterior;
    int contador_eventos;
    int contador_eventos2;
    int Index_caida;
    uint8_t ir_derecha;
    uint8_t ir_izquierda;

    uint8_t flag_golpeado;
    uint8_t flag_Obstruido_De;
    uint8_t flag_Obstruido_Iz;
    uint8_t flag_techo;
    uint8_t flag_pasamanos;
    uint8_t flag_cayendo;
    uint8_t flag_corriendo;
    uint8_t flag_saltando;
    uint8_t flag_escalando;
    uint8_t flag_lanzando_chunche;
    uint8_t flag_ataque_estado; // 0: no hay ataque, 1:ataque detenido, 2:ataque corriendo, 3: ataque pasamanos, 4: ataque saltando, 5: ataque agachado
    uint8_t flag_bala_estado;
    uint8_t flag_desatorar;
    uint8_t vida;
    uint8_t muerto;
    int FX_tiempo;

}enemigo[10],boss,boss_final;


int RAMDOM_INT=1;


void RAMDOM()
{
    int newbit =0;

     if(RAMDOM_INT & 0x8000) newbit ^= 1;
     if(RAMDOM_INT & 0x4000) newbit ^= 1;
     if(RAMDOM_INT & 0x1000) newbit ^= 1;
     if(RAMDOM_INT & 0x0400) newbit ^= 1;
     RAMDOM_INT = (RAMDOM_INT << 1) | newbit;


}
int RAMDOM_INT2=1;


void RAMDOM2()
{
    int newbit =0;

     if(RAMDOM_INT2 & 0x8000) newbit ^= 1;
     if(RAMDOM_INT2 & 0x4000) newbit ^= 1;
     if(RAMDOM_INT2 & 0x1000) newbit ^= 1;
     if(RAMDOM_INT2 & 0x0400) newbit ^= 1;
     RAMDOM_INT2 = (RAMDOM_INT2 << 1) | newbit;


}

void draw_TILES(const uint8_t table[],unsigned int sprite_number,int x,int y)
{
    int cont = 0;
    int i=0,j=0;

    cont=sprite_number*64;
    i=x+y*224;
    while (j < 64)
    {
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       VideoScreen.SpriteVmem[i++]=table[cont++];
       j=j+8;
       i=i+216;
    }

}

void Clear_Sprites(unsigned int sprite_number,int x,int y)
{
    int cont = 0;
    int i=0,j=0;
    cont=sprite_number*64;
    i=x+y*224;
    while (j < 64)
    {
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       VideoScreen.SpriteVmem[i++]=0;
       j=j+8;
       i=i+216;
    }

}

void draw_ASCII(uint8_t sprite_number,int x,int y,uint8_t BG_color,uint8_t font_color)
{
    int cont = 0;
    int i=0,j=0;
    cont=sprite_number*64;
    i=x+y*224;
    while (j < 64)
    {
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
        if (ASCII_TABLE[cont]==0)
            VideoScreen.SpriteVmem[i]=BG_color;
        else
            VideoScreen.SpriteVmem[i]=ASCII_TABLE[cont]&font_color;
        cont++;
        i++;
       
        j=j+8;
        i=i+216;
    }

}
// </editor-fold>

void print_line(char *txt,int linea, int y,uint8_t BG_color,uint8_t font_color)
{
    int contador_interno=0;
    char caracter=' ';

        while(caracter != 0 && contador_interno < 27)
        {
            caracter = txt[contador_interno + linea*26];
            draw_ASCII(caracter,(1+contador_interno)<<3,(y<<3)+y,BG_color,font_color);               
            contador_interno++;
            caracter = txt[contador_interno + linea*26];
        }

}

void print_line(const char *txt,int linea, int y,uint8_t BG_color,uint8_t font_color)
{
    int contador_interno=0;
    char caracter=' ';

        while(caracter != 0 && contador_interno < 26)
        {
            caracter = txt[contador_interno + linea*26];            
            draw_ASCII(caracter,(1+contador_interno)<<3,(y<<3)+(y*2),BG_color,font_color);               
            contador_interno++;
            caracter = txt[contador_interno + linea*26];
        }

}


void print_txt(char *txt,int x, int y,uint8_t BG_color,uint8_t font_color)
{
    int contador_interno=0;
    char caracter=' ';

        while(caracter != 0 )
        {
            caracter = txt[contador_interno];
            draw_ASCII(caracter,(x+contador_interno)<<3,(y<<3),BG_color,font_color);
            contador_interno++;
            caracter = txt[contador_interno];
        }

}

void print_txt(const char *txt,int x, int y,uint8_t BG_color,uint8_t font_color)
{
    int contador_interno=0;
    char caracter=' ';

        while(caracter != 0 )
        {
            caracter = txt[contador_interno];
            draw_ASCII(caracter,(x+contador_interno)<<3,(y<<3),BG_color,font_color);
            contador_interno++;
            caracter = txt[contador_interno];
        }

}



void Readjoy()
{
    int contador_joy=0;
    uint16_t ReadDataBuffer1=0;
    uint16_t ReadDataBuffer2=0;
    pinMode(JOY_LATCH,OUTPUT); 
    pinMode(JOY_CLK,OUTPUT); 
    pinMode(JOY1_DATA,INPUT); 
    
    digitalWrite(JOY_LATCH,LOW);
     
    digitalWrite(JOY_CLK,LOW);
    digitalWrite(JOY_LATCH,HIGH);
    delayMicroseconds(1);
    digitalWrite(JOY_LATCH,LOW);
    delayMicroseconds(1);
     ReadDataBuffer1=digitalRead(JOY1_DATA);
     ReadDataBuffer2=digitalRead(JOY2_DATA);
     while(contador_joy < 16)
     {
         ReadDataBuffer1 = ReadDataBuffer1<<1;
         ReadDataBuffer1 = ReadDataBuffer1+digitalRead(JOY1_DATA);
         ReadDataBuffer2 = ReadDataBuffer2<<1;
         ReadDataBuffer2 = ReadDataBuffer2+digitalRead(JOY2_DATA);

         digitalWrite(JOY_CLK,HIGH);
         delayMicroseconds(1);
         contador_joy++;
         digitalWrite(JOY_CLK,LOW);         
         delayMicroseconds(1);
     }
     digitalWrite(JOY_LATCH,HIGH);
     read_controller = ReadDataBuffer1;
     read_controller2 = ReadDataBuffer2 ;
}

void DelayVariables()
{
    //RAMDOM();
    //RAMDOM2();
    delay1++;
        delay2++;
        Jugador1.Animacion_escalando++;
        Jugador1.Animacion_pasamano++;
        Jugador1.Animacion_caminando++;
        Jugador1.Animacion_saltando++;
        Jugador1.Animacion_cayendo++;
        Jugador1.Animacion_Ataque++;
        Jugador1.Animacion_agachado++;
        Jugador1.Animacion_lanzar_chunche++;
        Jugador1.Animacion_bala++;
        Jugador1.Animacion_posicion++;
        Jugador1.Animacion_posicion2++;
        Jugador1.Animacion_general++;
        kunay.Animacion_POS++;
        Jugador1.FX_tiempo++;
        enemigo[0].AnimacionPosicion++;
        enemigo[1].AnimacionPosicion++;
        enemigo[2].AnimacionPosicion++;
        enemigo[3].AnimacionPosicion++;
        enemigo[4].AnimacionPosicion++;
        enemigo[5].AnimacionPosicion++;

        enemigo[0].Animacion_General++;
        enemigo[1].Animacion_General++;
        enemigo[2].Animacion_General++;
        enemigo[3].Animacion_General++;
        enemigo[4].Animacion_General++;
        enemigo[5].Animacion_General++;

        lampara[0].Animacion_general++;
        lampara[1].Animacion_general++;
        lampara[2].Animacion_general++;
        lampara[3].Animacion_general++;
        lampara[4].Animacion_general++;
        lampara[5].Animacion_general++;
        kunay_enemigo[0].Animacion_POS++;
        kunay_enemigo[1].Animacion_POS++;
        kunay_enemigo[2].Animacion_POS++;
        kunay_enemigo[3].Animacion_POS++;
        kunay_enemigo[4].Animacion_POS++;

        bala_boss[0].Animacion_POS++;
        bala_boss[1].Animacion_POS++;
        bala_boss[2].Animacion_POS++;
        bala_boss[3].Animacion_POS++;
        bala_boss[4].Animacion_POS++;
        bala_boss[5].Animacion_POS++;
        bala_boss[6].Animacion_POS++;
        boss.FX_tiempo++;
        boss.AnimacionPosicion++;
        boss.Animacion_General++;
        boss_final.Animacion_General++;
        Jugador1.tiempo_Transparente++;

        
}


void Dibujar_sprites(uint8_t *SpriteVMEM)
{
    
    SPRITE SPR;
    uint8_t pixeldata;
    int Banco;       
    int MAPINDEX;
    for (size_t i = 0; i < 128; i++)     
    {         
        if((spr_buff[i].SPR_ATTR & 0x20) == 0x20)
            Clear_Sprites(spr_buff[i].SPR_NUM,spr_buff[i].X,spr_buff[i].Y);  
    }
    for (size_t i = 0; i < 128; i++)     
    {                
                SPR = spr[i];               
                spr_buff[i].SPR_NUM = spr[i].SPR_NUM;
                spr_buff[i].SPR_ATTR = spr[i].SPR_ATTR;
                spr_buff[i].X = spr[i].X;
                spr_buff[i].Y = spr[i].Y;

                Banco = SPR.SPR_ATTR & 0x03;    
                if((SPR.SPR_ATTR & 0x20) == 0x20 && Control1.SPR_visibles==1)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        for (int x = 0; x < 8; x++)
                        {
                            if ((SPR.SPR_ATTR & 0x40) == 0x00)
                            {
                                MAPINDEX = SPR.SPR_NUM * 64 + x + y * 8;                                   
                            }
                            else
                            {
                                MAPINDEX = SPR.SPR_NUM * 64 - x + y * 8 + 7;                                                              
                            }

                            if (Banco== 0)                                            
                                pixeldata = Sprites[MAPINDEX];
                            if (Banco == 1)                                            
                                pixeldata = Sprites1[MAPINDEX];
                            if (Banco == 2)                                            
                                pixeldata = Sprites2[MAPINDEX];
                            if (Banco == 3)
                                pixeldata = Sprites3[MAPINDEX]; 

                            if (SPR.X >= 0 && SPR.Y >= 0 && SPR.X < 224 && SPR.Y < 224)
                            {
                                int bufferindex = SPR.X + SPR.Y * 224 + y * 224 + x;
                                if(bufferindex < 50176)
                                {                                                                               
                                    //pixels[SPR.X + SPR.Y * 256 + y * 256 + x] = (int)pixel_data.PackedValue;
                                    if ((SPR.X + x) < 224 && (SPR.Y + y) < 224)
                                    {
                                        if(pixeldata > 0)
                                            SpriteVMEM[bufferindex] = pixeldata;
                                        
                                    }                                     
                                }                                
                            }                            
                            
                        }
                    }

                }
            }
 // </editor-fold>
}

#define RGB_TO_YIQ( r, g, b, y, i ) (\
    (y = (r) * 0.299f + (g) * 0.587f + (b) * 0.114f),\
    (i = (r) * 0.596f - (g) * 0.275f - (b) * 0.321f),\
    ((r) * 0.212f - (g) * 0.523f + (b) * 0.311f)\
)




static void gen_ntsc_pal_tables()
{
    uint32_t rgb[256];
    float yuv_rotation = 2*M_PI*33/360; // 33 degree rotation
    printf("uint32_t sms_4_phase[256] = {\n");
    int cc_width = 4;
    const uint8_t _p[8] = {0,36,72,108,144,180,216,255};
    for (int i = 0; i < 256; i++) {
        int r = i >> 5;
        int g = (i >> 2) & 0x7;
        int b = (i & 0x3) << 1;
        b |= (b >> 2);
        r = _p[r];
        g = _p[g];
        b = _p[b];
        rgb[i] = (r << 16) | (g << 8) | b;

        float y, ii, q = RGB_TO_YIQ( r, g, b, y, ii );
        float phase = atan2(ii,q);
        float phase_yuv = phase + yuv_rotation;
        float saturation = sqrt(ii*ii + q*q)/80;    // <== this is somewhat ad hoc TODO
        float offset = 2*M_PI*2/3;  // 270 deg

        /*
        // yuv 2 ways: rotation of YIQ or derived from RGB
        uint8_t u = 0.493*(b - y)*63;
        uint8_t v = 0.877*(r - y)*63;
        float uu = cos(phase_yuv)*saturation*63;
        float vv = sin(phase_yuv)*saturation*63;
        uint8_t p0 = atan2(0.436798*uu,0.614777*vv)*256/(2*M_PI) + 192;
        uint8_t p1 = atan2(0.436798*uu,-0.614777*vv)*256/(2*M_PI) + 192;
        int ci = (p0 << 24) | (p1 << 16);
        if (!mono)
            ci |= (int)(saturation + 0.5);
         */

       y /= 255;   // TODO?
        y = y*(WHITE_LEVEL-BLACK_LEVEL) + BLACK_LEVEL;
        int p[4] = {0};
        for (int j = 0; j < cc_width; j++)
            p[j] = y;   // 0x1D is really black, really BLANKING_LEVEL

        if ((r == g) && (g == b)) {
            //
        } else {
            if (cc_width == 4) {
                for (int j = 0; j < 4; j++)
                    p[j] += sin(phase + offset + 2*M_PI*j/4)*BLANKING_LEVEL/2*saturation;
            } else {
                for (int j = 0; j < 3; j++)
                    p[j] += sin(phase + offset + 2*M_PI*j/3)*BLANKING_LEVEL/2*saturation;
            }
        }

        uint32_t pi = 0;
        for (int j = 0; j < 4; j++)
            pi = (pi << 8) | p[j] >> 8;
        printf("0x%08X,",pi);
        if ((i & 7) == 7)
            printf("\n");
    }
    printf("};\n");

    //make_yuv_palette("_sms",rgb,256);
}

