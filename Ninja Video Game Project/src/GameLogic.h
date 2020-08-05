/*
 * File:   MAIN.c
 * Author: AMB
 *
 * Created on 21 de julio de 2014, 08:52 PM
 */

// PIC32MX695F12H Configuration Bit Settings

// 'C' source line config statements




//#include "Sprites_functions.h"


int Index_caida=0;

int lopresiono=0;
int pos=0;

const int tabla_caida[]={
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,

};

//const char tabla_salto[]={
const int tabla_salto[]={

-3,-3,-3,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-2,-2,-2,
-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0,
 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2,
 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
};

//-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,
//-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0,
// 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
// 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
// 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
// 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
// 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
//};

const int tabla_salto_largo[]={

-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-2,-2,
-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
};


const int Enemigos_nivel1[] =
{
24,21, NINJA_ESPADA,
41,21, NINJA_ESPADA,
60,21, NINJA_ESPADA,
71,20, NINJA_ESPADA,

98,21, NINJA_ESPADA,
108,21, NINJA_ESPADA,
125,21, NINJA_ESPADA,
149,21, NINJA_ESPADA,

180,21, NINJA_ESPADA,
210,26, NINJA_KUNAY,
217,26, NINJA_KUNAY,
224,26, NINJA_KUNAY,

258,18, NINJA_ESPADA,
295,21, NINJA_ESPADA,
308,21, NINJA_ESPADA,
318,21, NINJA_ESPADA,

344,17, NINJA_PASAMANOS,
350,17, NINJA_PASAMANOS,
359,21, NINJA_ESPADA,
386,21, NINJA_ESPADA,

412,16, NINJA_ESPADA,
419,9, NINJA_PASAMANOS,
431,9, NINJA_PASAMANOS,
451,19, NINJA_ESPADA,

467,22, NINJA_ESPADA,


498,20, NINJA_ESPADA,
508,20, NINJA_ESPADA,
495,20, NINJA_ESPADA,
505,20, NINJA_ESPADA,
};

const int Enemigos_nivel2[] =
{

15,22, NINJA_MORADO_ESPADA,
23,16, NINJA_MORADO_ESPADA,
32,10, NINJA_MORADO_ESPADA,
40,10, NINJA_MORADO_ESPADA,

73,11, NINJA_MORADO_ESPADA,
92,23, NINJA_MORADO_ESPADA,
110,27, NINJA_KUNAY,
120,27, NINJA_KUNAY,

146,15, NINJA_ESPADA,
154,15, NINJA_MORADO_ESPADA,
189,15, NINJA_MORADO_ESPADA,
212,13, NINJA_PASAMANOS,

246,21, NINJA_MORADO_ESPADA,
255,15, NINJA_MORADO_ESPADA,
270,15, NINJA_ESPADA,
274,27, NINJA_KUNAY,

304,19, NINJA_ESPADA,
310,19, NINJA_MORADO_ESPADA,
314,17, NINJA_MORADO_ESPADA,
321,17, NINJA_MORADO_ESPADA,

352,13, NINJA_MORADO_ESPADA,
358,17, NINJA_MORADO_ESPADA,
368,15, NINJA_ESPADA,
376,15, NINJA_ESPADA,
};

const int Enemigos_nivel3[] =
{

14,23, NINJA_MORADO_ESPADA,
18,23, NINJA_MORADO_ESPADA,
7,27, NINJA_MORADO_ESPADA,
22,30, NINJA_MORADO_ESPADA,

11,60, NINJA_MORADO_ESPADA,
21,60, NINJA_MORADO_ESPADA,
11,73, NINJA_MORADO_ESPADA,
22,73, NINJA_MORADO_ESPADA,

19,102, NINJA_ESPADA,
8,107, NINJA_MORADO_ESPADA,
14,115, NINJA_MORADO_ESPADA,
16,122, NINJA_ESPADA,

4,158, NINJA_MORADO_ESPADA,
15,165, NINJA_MORADO_ESPADA,
23,265, NINJA_ESPADA,
4,171, NINJA_ESPADA,

18,216, NINJA_ESPADA,
22,216, NINJA_MORADO_ESPADA,
12,224, NINJA_MORADO_ESPADA,
16,224, NINJA_MORADO_ESPADA,

17,254, NINJA_MORADO_ESPADA,
11,273, NINJA_MORADO_ESPADA,
15,273, NINJA_ESPADA,
21,273, NINJA_ESPADA,
};


const int Enemigos_nivel4[] =
{

15,21, NINJA_MORADO_ESPADA,
24,21, NINJA_MORADO_ESPADA,
54,18, NINJA_MORADO_ESPADA,
76,15, NINJA_PASAMANOS,

110,7, NINJA_MORADO_ESPADA,
120,13, NINJA_MORADO_ESPADA,
126,13, NINJA_MORADO_ESPADA,
135,21, NINJA_MORADO_ESPADA,

165,19, NINJA_ESPADA,
173,15, NINJA_PASAMANOS,
196,20, NINJA_MORADO_ESPADA,
213,19, NINJA_ESPADA,
};

const int Enemigos_nivel5[] =
{

13,19, NINJA_ESPADA,
23,19, NINJA_ESPADA,
27,19, NINJA_GRIS_HIELO,
38,21, NINJA_GRIS_HIELO,

72,23, NINJA_ESPADA,
75,15, NINJA_ESPADA,
86,19, NINJA_ESPADA,
94,15, NINJA_GRIS_HIELO,

124,23, NINJA_GRIS_HIELO,
137,13, NINJA_GRIS_HIELO,
145,15, NINJA_MORADO_ESPADA,
152,17, NINJA_GRIS_HIELO,

180,23, NINJA_ESPADA,
184,19, NINJA_ESPADA,
196,27, NINJA_CAFE_KUNAY,
207,27, NINJA_CAFE_KUNAY,

246,21, NINJA_ESPADA,
259,21, NINJA_GRIS_HIELO,
264,21, NINJA_GRIS_HIELO,
274,21, NINJA_GRIS_HIELO,
};

const int Enemigos_nivel6[] =
{

8,125, NINJA_ESPADA,
19,118, NINJA_ESPADA,
8,111, NINJA_GRIS_HIELO,
18,105, NINJA_GRIS_HIELO,

9,69, NINJA_GRIS_HIELO,
13,69, NINJA_GRIS_HIELO,
11,55, NINJA_ESPADA,
15,55, NINJA_GRIS_HIELO,

7,17, NINJA_GRIS_HIELO,
12,17, NINJA_GRIS_HIELO,
18,17, NINJA_MORADO_ESPADA,
23,17, NINJA_MORADO_ESPADA,

};

const int Enemigos_nivel8[] =
{

16,21, NINJA_CAFE_LODO,
23,21, NINJA_CAFE_LODO,
32,19, NINJA_ESPADA,
37,19, NINJA_CAFE_LODO,

72,17, NINJA_CAFE_LODO,
82,14, NINJA_CAFE_LODO,
94,13, NINJA_ESPADA,
99,13, NINJA_CAFE_LODO,

20,43, NINJA_ESPADA,
34,43, NINJA_ESPADA,
54,43, NINJA_ESPADA,
71,43, NINJA_ESPADA,

96,72, OGRO,
33,74, OGRO,
10,103, OGRO,
111,105, OGRO,

123,74, NINJA_CAFE_LODO,
123,62, NINJA_CAFE_LODO,
125,52, NINJA_CAFE_LODO,
131,46, NINJA_CAFE_LODO,

};

const int Enemigos_nivel10[] =
{

30,22, NINJA_ESPADA,
39,27, NINJA_KUNAY,
48,27, NINJA_KUNAY,
57,22, NINJA_ESPADA,

89,16, NINJA_CAFE_LODO,
95,16, NINJA_MORADO_ESPADA,
107,16, NINJA_MORADO_ESPADA,
113,20, NINJA_MORADO_KUNAY,

150,16, NINJA_ESPADA,
155,16, NINJA_ESPADA,
161,14, NINJA_ESPADA,
163,14, NINJA_ESPADA,

195,23, NINJA_MORADO_KUNAY,
200,27, NINJA_KUNAY,
209,23, NINJA_MORADO_KUNAY,
214,23, NINJA_MORADO_ESPADA,


};
const int Enemigos_nivel11[] =
{

17,11, NINJA_ESPADA,
25,11, NINJA_MORADO_KUNAY,
38,5, NINJA_MORADO_KUNAY,
44,5, NINJA_MORADO_KUNAY,

85,10, NINJA_PASAMANOS,
86,16, NINJA_MORADO_ESPADA,
91,16, NINJA_MORADO_ESPADA,
96,16, NINJA_MORADO_KUNAY,

130,17, NINJA_ESPADA,
140,22, NINJA_ESPADA,
144,22, NINJA_ESPADA,
148,22, NINJA_MORADO_KUNAY,

183,22, NINJA_MORADO_KUNAY,
196,19, NINJA_MORADO_ESPADA,
199,19, NINJA_MORADO_KUNAY,
204,14, NINJA_MORADO_ESPADA,


};


const int lamparas_nivel1[] =
{
    13, 18,ITEM_KUNAYS,
    28, 18,ITEM_KUNAYS,
    45,18,ITEM_DIAMANTE,
    55,18,ITEM_DIAMANTE,
    70,17,ITEM_KUNAYS,
    108 ,18,ITEM_KUNAYS,
    125 ,18,ITEM_MONEDA,
    148 ,18,ITEM_MONEDA,
    174 ,18,ITEM_MONEDA,
    181 ,18,ITEM_KUNAYS,
    248 ,14,ITEM_DIAMANTE,
    270 ,17,ITEM_KUNAYS,
    292 ,18,ITEM_KUNAYS,
    314 ,18,ITEM_DIAMANTE,
    332 ,12,ITEM_KUNAYS,
    379 ,14,ITEM_KUNAYS,
    395 ,18,ITEM_KUNAYS,
    421 ,5,ITEM_DIAMANTE,
    442 ,6,ITEM_DIAMANTE,
    465 ,21,ITEM_JAMON,
    1000 ,14,ITEM_DIAMANTE,// relleno para completar multiplos de 5
    1000 ,14,ITEM_DIAMANTE,
    1000 ,14,ITEM_DIAMANTE,
    1000,14,ITEM_DIAMANTE,
    1000 ,14,ITEM_DIAMANTE,
};


const int lamparas_nivel2[] =
{

6, 20,ITEM_KUNAYS,
20, 13,ITEM_MONEDA,
34, 7,ITEM_MONEDA,
41, 7,ITEM_MONEDA,
74, 9,ITEM_DIAMANTE,


102, 18,ITEM_KUNAYS,
116, 19,ITEM_KUNAYS,
125, 19,ITEM_MONEDA,
134, 19,ITEM_MONEDA,
139, 19,ITEM_MONEDA,


182, 13,ITEM_KUNAYS,
200, 15,ITEM_KUNAYS,
347, 11,ITEM_MONEDA,
357, 15,ITEM_MONEDA,
364, 19,ITEM_KUNAYS,



};

const int lamparas_nivel3[] =
{

16, 85,ITEM_KUNAYS,
11, 91,ITEM_MONEDA,
23, 98, ITEM_DIAMANTE,
10, 103,ITEM_MONEDA,
20, 111,ITEM_DIAMANTE,

12, 151, ITEM_MONEDA,
5, 158, ITEM_MONEDA,
23, 165,ITEM_MONEDA,
6, 171,ITEM_MONEDA,
16, 172,ITEM_MONEDA,

19, 216,ITEM_KUNAYS,
12, 224,ITEM_KUNAYS,
23, 227,ITEM_MONEDA,
4, 240,ITEM_MONEDA,
11, 240, ITEM_DIAMANTE,

};


const int lamparas_nivel4[] =
{

6, 18, ITEM_DIAMANTE,
22, 18,ITEM_MONEDA,
30, 18, ITEM_MONEDA,
45, 18, ITEM_DIAMANTE,
53, 16, ITEM_MONEDA,

96, 14, ITEM_MONEDA,
119, 11, ITEM_MONEDA,
131, 19,ITEM_MONEDA,
136, 19,ITEM_MONEDA,
142, 8, ITEM_KUNAYS,

194, 11, ITEM_DIAMANTE,
198, 18,ITEM_KUNAYS,
205, 17,ITEM_JAMON,
214, 16,ITEM_MONEDA,
224, 16, ITEM_DIAMANTE,

};


const int lamparas_nivel5[] =
{

6, 19, ITEM_MONEDA,
13, 17,ITEM_MONEDA,
20, 17, ITEM_KUNAYS,
25, 17, ITEM_KUNAYS,
36, 19, ITEM_MONEDA,

73, 15, ITEM_KUNAYS,
82, 17, ITEM_MONEDA,
86, 17,ITEM_MONEDA,
90, 15,ITEM_MONEDA,
95, 13, ITEM_KUNAYS,

127, 21, ITEM_MONEDA,
138, 13,ITEM_KUNAYS,
144, 15, ITEM_MONEDA,
152, 17,ITEM_MONEDA,
164, 19, ITEM_DIAMANTE,

230, 21, ITEM_KUNAYS,
238, 27, ITEM_DIAMANTE,
246, 19, ITEM_KUNAYS,
257, 19, ITEM_MONEDA,
266, 19, ITEM_MONEDA,


};

const int lamparas_nivel6[] =
{

10, 133, ITEM_MONEDA,
7, 125,ITEM_MONEDA,
19, 116, ITEM_KUNAYS,
6, 109, ITEM_KUNAYS,
20, 103, ITEM_DIAMANTE,

4, 65, ITEM_JAMON,
8, 55, ITEM_MONEDA,
6, 44, ITEM_DIAMANTE,
5, 27, ITEM_MONEDA,
14, 15, ITEM_KUNAYS,


};

const int lamparas_nivel8[] =
{

35, 16, ITEM_MONEDA,
43, 14,ITEM_MONEDA,
50, 14, ITEM_KUNAYS,
48, 23, ITEM_KUNAYS,
70, 14, ITEM_DIAMANTE,

71, 53, ITEM_MONEDA,
65, 53, ITEM_MONEDA,
54, 53, ITEM_DIAMANTE,
44, 53,ITEM_MONEDA,
8, 50, ITEM_KUNAYS,

9, 76, ITEM_MONEDA,
4, 84, ITEM_KUNAYS,
14, 88, ITEM_KUNAYS,
4, 102, ITEM_JAMON,
30, 98, ITEM_KUNAYS,

132, 82, ITEM_KUNAYS,
131, 68, ITEM_KUNAYS,
132, 52, ITEM_KUNAYS,
132, 43, ITEM_MONEDA,
132, 26, ITEM_KUNAYS,
};

const int lamparas_nivel10[] =
{

7, 19, ITEM_MONEDA,
14, 19,ITEM_MONEDA,
21, 19, ITEM_MONEDA,
29, 19, ITEM_MONEDA,
43, 19, ITEM_DIAMANTE,

88, 13, ITEM_MONEDA,
95, 13, ITEM_MONEDA,
106, 13, ITEM_DIAMANTE,
112, 13,ITEM_MONEDA,
122, 17, ITEM_MONEDA,

162, 11, ITEM_MONEDA,
169, 20, ITEM_MONEDA,
183, 20, ITEM_MONEDA,
210, 20, ITEM_MONEDA,
220, 8, ITEM_DIAMANTE,
};

const int lamparas_nivel11[] =
{

91, 13, ITEM_KUNAYS,
111, 13, ITEM_KUNAYS,
128, 14, ITEM_MONEDA,
141, 19, ITEM_MONEDA,
147, 19, ITEM_KUNAYS,


177, 19, ITEM_KUNAYS,
183, 19, ITEM_MONEDA,
197, 16, ITEM_KUNAYS,
205, 11, ITEM_MONEDA,
212, 20, ITEM_JAMON,
};

void codigo_FAMBOX()
{
    char buf[10];
//    utoa(buf,Niveles.FAMBOX_cod_cont,10);
//    print_txt(buf,4,7,BG_NEGRO,BLANCO);

   if((read_controller&Arriba)==0&&Control1.Arriba_presionado==0 && Niveles.FAMBOX_cod_cont == 0)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.Arriba_presionado=1;
   }else
       if((read_controller&Arriba)==0&&Control1.Arriba_presionado==0 && Niveles.FAMBOX_cod_cont != 0 && Niveles.FAMBOX_cod_cont != 1)
           Niveles.FAMBOX_cod_cont=0;

   if((read_controller&Arriba)==0&&Control1.Arriba_presionado==0 && Niveles.FAMBOX_cod_cont == 1)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.Arriba_presionado=1;
   }else
       if((read_controller&Arriba)==0&&Control1.Arriba_presionado==0 && Niveles.FAMBOX_cod_cont != 0 && Niveles.FAMBOX_cod_cont != 1)
           Niveles.FAMBOX_cod_cont=0;


   if((read_controller&Abajo)==0&&Control1.Abajo_presionado==0 && Niveles.FAMBOX_cod_cont == 2)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.Abajo_presionado=1;
   }else
       if((read_controller&Abajo)==0&&Control1.Abajo_presionado==0 && Niveles.FAMBOX_cod_cont != 2 && Niveles.FAMBOX_cod_cont != 3)
           Niveles.FAMBOX_cod_cont=0;

   if((read_controller&Abajo)==0&&Control1.Abajo_presionado==0 && Niveles.FAMBOX_cod_cont == 3)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.Abajo_presionado=1;
   }else
       if((read_controller&Abajo)==0&&Control1.Abajo_presionado==0 && Niveles.FAMBOX_cod_cont != 2 && Niveles.FAMBOX_cod_cont != 3)
           Niveles.FAMBOX_cod_cont=0;

   if((read_controller&Izquierda)==0&&Control1.IZ_presionado==0 && Niveles.FAMBOX_cod_cont == 4)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.IZ_presionado=1;
   }else
       if((read_controller&Izquierda)==0&&Control1.IZ_presionado==0 && Niveles.FAMBOX_cod_cont != 4)
           Niveles.FAMBOX_cod_cont=0;

   if((read_controller&Derecha)==0&&Control1.DE_presionado==0 && Niveles.FAMBOX_cod_cont == 5)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.DE_presionado=1;
   }else
       if((read_controller&Derecha)==0&&Control1.DE_presionado==0 && Niveles.FAMBOX_cod_cont != 5)
           Niveles.FAMBOX_cod_cont=0;

   if((read_controller&boton_A)==0&&Control1.A_presionado==0 && Niveles.FAMBOX_cod_cont == 6)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.A_presionado=1;
   }else
       if((read_controller&boton_A)==0&&Control1.A_presionado==0 && Niveles.FAMBOX_cod_cont != 6)
           Niveles.FAMBOX_cod_cont=0;

   if((read_controller&boton_B)==0&&Control1.B_presionado==0 && Niveles.FAMBOX_cod_cont == 7)
   {
       Niveles.FAMBOX_cod_cont++;
       Control1.B_presionado=1;
   }else
       if((read_controller&boton_B)==0&&Control1.B_presionado==0 && Niveles.FAMBOX_cod_cont != 7)
           Niveles.FAMBOX_cod_cont=0;


   if((read_controller&Abajo)==Abajo&&Control1.Abajo_presionado==1)
        Control1.Abajo_presionado=0;
   if((read_controller&Arriba)==Arriba&&Control1.Arriba_presionado==1)
        Control1.Arriba_presionado=0;
   if((read_controller&Izquierda)==Izquierda&&Control1.IZ_presionado==1)
        Control1.IZ_presionado=0;
   if((read_controller&Derecha)==Derecha&&Control1.DE_presionado==1)
        Control1.DE_presionado=0;
   if((read_controller&boton_A)==boton_A&&Control1.A_presionado==1)
        Control1.A_presionado=0;
   if((read_controller&boton_B)==boton_B&&Control1.B_presionado==1)
        Control1.B_presionado=0;



}

void Limpiar_sprites_mem()
{
    int cont =0 ;
    int x;
    while(cont<110)
    {
        spr[cont++].SPR_ATTR=0;
    }
    for(x = 0;x < 50000;x++)
    {
       VideoScreen.SpriteVmem[x]=0x00;
    }
}


void control_pausa()
{
    char buf[15];
    String STRdata;
    int cont;
    if(((read_controller&boton_start)==0) && (Control1.Start_presionado==0 )&& (Niveles.pausa==0))
    {
         Control1.Start_presionado=1;
         Control1.SPR_visibles=0;
         Niveles.pausa = 1;
    }

    if(((read_controller&boton_start)==0) && (Control1.Start_presionado==0 )&& (Niveles.pausa==1))
    {
        Control1.Start_presionado=1;
        Niveles.pausa = 0;
        Niveles.contador_pausa=0;
        for(cont=0;cont<21;cont++)
        {
            draw_ASCII(32,(5+cont)<<3,13<<3,BG_NEGRO,BLANCO);
            draw_ASCII(32,(5+cont)<<3,14<<3,BG_NEGRO,BLANCO);
            draw_ASCII(32,(5+cont)<<3,12<<3,BG_NEGRO,BLANCO);
            draw_ASCII(32,(5+cont)<<3,15<<3,BG_NEGRO,BLANCO);
        }
        Control1.SPR_visibles=1;
    }

    if(((read_controller&boton_start)==boton_start) && (Control1.Start_presionado==1))
        Control1.Start_presionado=0;
    
        /*STRdata = String(read_controller,HEX);
        STRdata.toCharArray(buf,15);
        print_txt(buf,9,5,BG_ROJO,BLANCO);  */


}


/***Estrutura de Variables usadas por el jugador 1 y 2****/
int MAPA_POS_Y_anterior=0;
void chequear_pos_IZ(int MIN_POS_x)
{
    if(Jugador1.POS_X<0)Jugador1.POS_X=0;
    if (Jugador1.POS_X < 100)
    {
                VideoScreen.MAP_Scroll_x--;

                if ((VideoScreen.MAP_Scroll_x) > MIN_POS_x)
                    Jugador1.POS_X=100;
    }
}


void chequear_pos_DE(int MAX_MAP_x)
{

    if(Jugador1.POS_X>192)Jugador1.POS_X=192;
    if (Jugador1.POS_X > 100)
    {
        VideoScreen.MAP_Scroll_x++;
        if (VideoScreen.MAP_Scroll_x < ((MAX_MAP_x-28)<<3))
            Jugador1.POS_X = 100;
    }
}


void Dialogo(const char texto_linea1[],const char texto_linea2[], const char texto_linea3[])
{
    int cont=0;
        for(cont=1;cont<21;cont++)
        {
            draw_ASCII(32,(2+cont)<<3,6<<3,BG_ROJO,BLANCO);
            draw_ASCII(32,(2+cont)<<3,7<<3,BG_ROJO,BLANCO);
            draw_ASCII(32,(2+cont)<<3,8<<3,BG_ROJO,BLANCO);
            draw_ASCII(127,(2+cont)<<3,5<<3,BG_ROJO,BLANCO);
            draw_ASCII(124,(2+cont)<<3,9<<3,BG_ROJO,BLANCO);
        }
        draw_ASCII(130,2<<3,6<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,22<<3,6<<3,BG_ROJO,BLANCO);
        draw_ASCII(130,2<<3,7<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,22<<3,7<<3,BG_ROJO,BLANCO);
        draw_ASCII(130,2<<3,8<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,22<<3,8<<3,BG_ROJO,BLANCO);

        draw_ASCII(126,2<<3,5<<3,BG_ROJO,BLANCO);
        draw_ASCII(128,22<<3,5<<3,BG_ROJO,BLANCO);
        draw_ASCII(123,2<<3,9<<3,BG_ROJO,BLANCO);
        draw_ASCII(125,22<<3,9<<3,BG_ROJO,BLANCO);

        print_txt(texto_linea1,3,6,BG_ROJO,BLANCO);
        print_txt(texto_linea2,3,7,BG_ROJO,BLANCO);
        print_txt(texto_linea3,3,8,BG_ROJO,BLANCO);
}



void recuadro_expandible(const char texto_linea1[],const char texto_linea2[], const char texto_linea3[])
{
    int cont;
    Niveles.contador_pausa++;

    if (Niveles.contador_pausa == 10)
    {
        draw_ASCII(126,13<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(128,14<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(123,13<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(125,14<<3,13<<3,BG_ROJO,BLANCO);
    }

    if (Niveles.contador_pausa == 100)
    {
        for(cont=1;cont<3;cont++)
        {
            draw_ASCII(32,(12+cont)<<3,13<<3,BG_ROJO,BLANCO);
            draw_ASCII(127,(12+cont)<<3,12<<3,BG_ROJO,BLANCO);
            draw_ASCII(124,(12+cont)<<3,14<<3,BG_ROJO,BLANCO);
        }
        draw_ASCII(130,12<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,15<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(126,12<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(128,15<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(123,12<<3,14<<3,BG_ROJO,BLANCO);
        draw_ASCII(125,15<<3,14<<3,BG_ROJO,BLANCO);
    }

    if (Niveles.contador_pausa == 200)
    {
        for(cont=1;cont<7;cont++)
        {
            draw_ASCII(32,(11+cont)<<3,13<<3,BG_ROJO,BLANCO);
            draw_ASCII(32,(11+cont)<<3,14<<3,BG_ROJO,BLANCO);
            draw_ASCII(127,(11+cont)<<3,12<<3,BG_ROJO,BLANCO);
            draw_ASCII(124,(11+cont)<<3,15<<3,BG_ROJO,BLANCO);
        }
        draw_ASCII(130,11<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,16<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(130,11<<3,14<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,16<<3,14<<3,BG_ROJO,BLANCO);

        draw_ASCII(126,11<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(128,16<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(123,11<<3,15<<3,BG_ROJO,BLANCO);
        draw_ASCII(125,16<<3,15<<3,BG_ROJO,BLANCO);
    }

    if (Niveles.contador_pausa == 300)
    {
        for(cont=1;cont<11;cont++)
        {
            draw_ASCII(32,(8+cont)<<3,13<<3,BG_ROJO,BLANCO);
            draw_ASCII(32,(8+cont)<<3,14<<3,BG_ROJO,BLANCO);
            draw_ASCII(127,(8+cont)<<3,12<<3,BG_ROJO,BLANCO);
            draw_ASCII(124,(8+cont)<<3,15<<3,BG_ROJO,BLANCO);
        }
        draw_ASCII(130,8<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,18<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(130,8<<3,14<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,18<<3,14<<3,BG_ROJO,BLANCO);

        draw_ASCII(126,8<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(128,18<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(123,8<<3,15<<3,BG_ROJO,BLANCO);
        draw_ASCII(125,18<<3,15<<3,BG_ROJO,BLANCO);
    }

    if (Niveles.contador_pausa == 400)
    {
        for(cont=1;cont<17;cont++)
        {
            draw_ASCII(32,(5+cont)<<3,13<<3,BG_ROJO,BLANCO);
            draw_ASCII(32,(5+cont)<<3,14<<3,BG_ROJO,BLANCO);
            draw_ASCII(127,(5+cont)<<3,12<<3,BG_ROJO,BLANCO);
            draw_ASCII(124,(5+cont)<<3,15<<3,BG_ROJO,BLANCO);
        }
        draw_ASCII(130,5<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,21<<3,13<<3,BG_ROJO,BLANCO);
        draw_ASCII(130,5<<3,14<<3,BG_ROJO,BLANCO);
        draw_ASCII(129,21<<3,14<<3,BG_ROJO,BLANCO);

        draw_ASCII(126,5<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(128,21<<3,12<<3,BG_ROJO,BLANCO);
        draw_ASCII(123,5<<3,15<<3,BG_ROJO,BLANCO);
        draw_ASCII(125,21<<3,15<<3,BG_ROJO,BLANCO);
    }

    if(Niveles.contador_pausa > 450)
    {
        Niveles.contador_pausa=500;
        print_txt(texto_linea1,6,13,BG_ROJO,BLANCO);
        print_txt(texto_linea2,6,14,BG_ROJO,BLANCO);
    }
}



void recuadro_encabezado()
{
    int cont;

    for(cont=1;cont<26;cont++)
    {
        draw_ASCII(127,cont<<3,0,BG_ROJO,BLANCO);
        draw_ASCII(124,cont<<3,16,BG_ROJO,BLANCO);
    }

    draw_ASCII(126,0,0,BG_ROJO,BLANCO);    
    draw_ASCII(126,0,0,BG_ROJO,BLANCO);
    draw_ASCII(128,26<<3,0,BG_ROJO,BLANCO);
    draw_ASCII(130,0,8,BG_ROJO,BLANCO);
    draw_ASCII(129,26<<3,8,BG_ROJO,BLANCO);
    draw_ASCII(123,0,16,BG_ROJO,BLANCO);
    draw_ASCII(125,26<<3,16,BG_ROJO,BLANCO);     

}


/*void VideoScreen.copy_BG_TILES(BG1_TILES,int opacidad)
{
    int cont;
    char mascara=0b11111111;
    cont=0;
    if (opacidad == 0)mascara=0b00000001;
    if (opacidad == 1)mascara=0b00100101;
    if (opacidad == 2)mascara=0b01001010;
    if (opacidad == 3)mascara=0b01101110;
    if (opacidad == 4)mascara=0b10010011;
    if (opacidad == 5)mascara=0b10110111;
    if (opacidad == 6)mascara=0b11011011;
    if (opacidad == 7)mascara=0b11111111;
    if (opacidad == 8)mascara=0;
    while(cont<16384)
    {
        VideoScreen.BG_TILESRAM[cont]=BG1_TILES[cont++]& mascara;
    }
}*/

void copy_bmp(int opacidad)
{
   int cont,x,y;
   char mascara=0b11111111;
   cont=0;
   if (opacidad == 0)mascara=0b00000001;
   if (opacidad == 1)mascara=0b00100101;
   if (opacidad == 2)mascara=0b01001001;
   if (opacidad == 3)mascara=0b01101110;
   if (opacidad == 4)mascara=0b10010010;
   if (opacidad == 5)mascara=0b10110110;
   if (opacidad == 6)mascara=0b11011011;
   if (opacidad == 7)mascara=0b11111111;

   for(y=0;y<104;y++)
   {
       for(x=0;x<96;x++)
       {
          VideoScreen.SpriteVmem[(y+50)*224+(x+64)]=NINJA_BMP[cont++] & mascara;
       }
   }
}


void copy_bmp128(int opacidad,const unsigned char BMP[])
{
   int cont,x,y;
   char mascara=0b11111111;
   cont=0;
   if (opacidad == 0)mascara=0b00000001;
   if (opacidad == 1)mascara=0b00100101;
   if (opacidad == 2)mascara=0b01001010;
   if (opacidad == 3)mascara=0b01101110;
   if (opacidad == 4)mascara=0b10010011;
   if (opacidad == 5)mascara=0b10110111;
   if (opacidad == 6)mascara=0b11011011;
   if (opacidad == 7)mascara=0b11111111;

   for(y=0;y<64;y++)
   {
       for(x=0;x<128;x++)
       {
          VideoScreen.SpriteVmem[(y+140)*224+(x+48)]=BMP[cont++] & mascara;
       }
   }
}


void DrawMegaSprite(short Sprite_base,unsigned int Atributo_NUM,int POS_X,int POS_Y,short Ancho,short Altura)
{
    int index=0;
    int index2=0;
    int espejo=0;
    short i,j;
    short Atributo;

    Atributo = Atributo_NUM & 0x00ff;
    index = (Atributo_NUM & 0xff00)>>8;
    if ((Atributo&SPR_Mirror_H)==SPR_Mirror_H)
        espejo = 1;
    if ((Atributo&SPR_Mirror_H)==0)
        espejo = 2;

    for(i=0;i<Altura;i++)
    {
        for(j=0;j<Ancho;j++)
        {
            if(((POS_Y+i*8)>24)&&((POS_Y+i*8)<216))
            {
                spr[index].SPR_ATTR = Atributo;
                if(espejo == 2)
                {
                    spr[index].X = POS_X+j*8;
                    spr[index].Y = POS_Y+i*8;
                    spr[index].SPR_NUM = Sprite_base+j+index2;
                }
                if(espejo == 1)
                {
                    spr[index].X = POS_X+(Ancho-1)*8-j*8;
                    spr[index].Y = POS_Y+i*8;
                    spr[index].SPR_NUM = Sprite_base+index2+j;
                }
            }
            else
                spr[index].SPR_ATTR = 0; // en caso que no este en los limites

            index++;
        }
        index2+=32;
    }
}

// <editor-fold defaultstate="collapsed" desc="Revisión de condiciones para la maquina de estados">

void Condiciones_correr()
{
    char *buf;
    if((read_controller&boton_B)==0 && Control1.B_presionado==0 && Jugador1.flag_cayendo == 0)
    {
        Control1.B_presionado=1;
        Jugador1.Estado = SALTO_NORMAL_1;
        Jugador1.flag_saltando=1;
        Jugador1.POS_Y_cont=0;
        Jugador1.Animacion_saltando=0;
        Jugador1.POS_Y_anterior=Jugador1.POS_Y;
        Jugador1.POS_X_anterior=Jugador1.POS_X;
        //lopresiono=1;
        //utoa(buf,Jugador1.Estado,10);

    }
    if(Jugador1.flag_corriendo == 0)
    {
        Jugador1.Estado = REPOSO;
    }

    if(Jugador1.flag_cayendo == 1)
    {
        Jugador1.Estado = CAYENDO_1;
        Jugador1.Animacion_cayendo=0;
    }

    if((read_controller&boton_Y)==0&&Control1.Y_presionado==0)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            DrawMegaSprite(196,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
        else
            DrawMegaSprite(196,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
        Control1.Y_presionado=1;
        Jugador1.flag_ataque_estado=2;
        Jugador1.Animacion_Ataque=0;
        Jugador1.Estado=ATAQUE_CORRIENDO_1;
    }else
    if((read_controller&boton_X)==0&&Control1.X_presionado==0&& kunay.cantidad > 0 && kunay.flag_lanzado == 0)
    {
        kunay.cantidad--;
        Jugador1.Estado = BALA_CORRIENDO_1;
//        if(kunay.cantidad < 0)
//        {
//            kunay.cantidad=0;
//            Jugador1.Estado = REPOSO;
//        }
        DrawMegaSprite(21,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        Jugador1.Animacion_lanzar_chunche=0;
        Control1.X_presionado=1;
    }
}
void Condiciones_saltonormal(int Cant_Bloques_De,int Cant_Bloques_Iz)
{
    char *buf;

    if(Jugador1.flag_cayendo == 0 && Jugador1.POS_Y_cont > 10)
    {
        //AjustePosY();
        Jugador1.flag_saltando=0;
        Jugador1.Estado = REPOSO;
    }
    if((Jugador1.flag_Obstruido_De==1||Jugador1.flag_Obstruido_Iz==1)&&((read_controller&Derecha)==0||(read_controller&Izquierda)==0))
    {
        if((Cant_Bloques_De>2||Cant_Bloques_Iz>2)&&Jugador1.flag_cayendo==1)
        {
            Jugador1.Estado=ESCALAR_1;
            Jugador1.flag_escalando=1;
            Jugador1.Animacion_escalando=0;
            DrawMegaSprite(318,0,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
                DrawMegaSprite(318,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
            else
                DrawMegaSprite(318,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
        }
    }
    if(Jugador1.flag_techo==1)
    {
        Jugador1.Estado=CAYENDO_1;

    }
    if(Jugador1.flag_pasamanos==1 && Jugador1.POS_Y_cont > 40)
    {
        Jugador1.Estado=PASAMANOS_1;
        DrawMegaSprite(297,0,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
            DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
        else
            DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
    }
    if((read_controller&boton_Y)==0&&Control1.Y_presionado==0&& Jugador1.POS_Y_cont > 10)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            DrawMegaSprite(220,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
        else
            DrawMegaSprite(220,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
        Control1.Y_presionado=1;
        Jugador1.flag_ataque_estado=4;
        Jugador1.Animacion_Ataque=0;
        Jugador1.Estado=SALTO_ATAQUE_1;
        Index_caida=0;
    }else
    if((read_controller&boton_X)==0&&Control1.X_presionado==0&& Jugador1.POS_Y_cont > 10&& kunay.cantidad > 0)
    {
        kunay.cantidad--;
//        if(kunay.cantidad < 0)
//        {
//            kunay.cantidad=0;
//            Jugador1.Estado = REPOSO;
//        }
        DrawMegaSprite(105,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        Jugador1.Animacion_Ataque=0;
        Control1.X_presionado=1;
        Jugador1.Estado = BALA_SALTANDO_1;
    }
}
void Condiciones_saltoestatico()
{
    if(Jugador1.flag_cayendo == 0 && Jugador1.POS_Y_cont > 10)
    {
       // AjustePosY();
        Jugador1.flag_saltando=0;
        Jugador1.Estado = REPOSO;
    }
    if(Jugador1.flag_techo==1)
        Jugador1.Estado=CAYENDO_1;

    if(Jugador1.flag_pasamanos==1 && Jugador1.POS_Y_cont > 40)
    {
        Jugador1.Estado=PASAMANOS_1;
        DrawMegaSprite(297,0,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
            DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
        else
            DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
    }

    if((read_controller&boton_Y)==0&&Control1.Y_presionado==0&& Jugador1.POS_Y_cont > 10)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            DrawMegaSprite(220,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
        else
            DrawMegaSprite(220,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
        Control1.Y_presionado=1;
        Jugador1.flag_ataque_estado=4;
        Jugador1.Animacion_Ataque=0;
        Jugador1.Estado=SALTO_ATAQUE_1;
        Index_caida=0;
    }else
    if((read_controller&boton_X)==0&&Control1.X_presionado==0&& Jugador1.POS_Y_cont > 10 && kunay.cantidad > 0)
    {
        Jugador1.Estado = BALA_SALTANDO_1;
        kunay.cantidad--;
//        if(kunay.cantidad < 0)
//        {
//            kunay.cantidad=0;
//            Jugador1.Estado = REPOSO;
//        }
        DrawMegaSprite(105,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        Jugador1.Animacion_lanzar_chunche=0;
        Control1.X_presionado=1;
    }
}
void Condiciones_cayendo()
{

}
void Condiciones_escalar(int MAX_MAP_x)
{
    if((read_controller&boton_B)==0&&Control1.B_presionado==0)
    {
            Jugador1.Estado= CAYENDO_1;
            Jugador1.Animacion_escalando=0;
            Control1.B_presionado=1;
            Jugador1.flag_escalando=0;
            Index_caida=0;
    }
    if(Jugador1.flag_cayendo==0 ||(Jugador1.flag_Obstruido_De == 0 && Jugador1.flag_Obstruido_Iz == 0) )
    {
        if((read_controller&Abajo)==Abajo)
        {
            Jugador1.POS_Y -=10;
            if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
            {
                Jugador1.POS_X +=3;
                if(Jugador1.POS_X > 100)
                {
                    VideoScreen.MAP_Scroll_x = VideoScreen.MAP_Scroll_x+(Jugador1.POS_X-100);
                    if (VideoScreen.MAP_Scroll_x < ((MAX_MAP_x-28)<<3))
                       Jugador1.POS_X = 100;
                }
            }
            else
            {
                Jugador1.POS_X -=3;
                if(Jugador1.POS_X < 100)
                {
                    VideoScreen.MAP_Scroll_x = VideoScreen.MAP_Scroll_x+(Jugador1.POS_X-100);
                    if ((VideoScreen.MAP_Scroll_x) > 0)
                        Jugador1.POS_X=100;
                }
            }

        }
        Jugador1.flag_escalando=0;
        Jugador1.Animacion_escalando=0;
        Jugador1.Estado=REPOSO;
    }
}
void Condiciones_pasamano()
{

    if((read_controller&boton_B)==0&&Control1.B_presionado==0)
    {
        Control1.B_presionado=1;
        Jugador1.Estado = SALTO_NORMAL_1;
        Jugador1.Animacion_pasamano=0;
        Jugador1.flag_saltando=1;
        Jugador1.POS_Y_cont=0;
        Jugador1.Animacion_saltando=0;
        Jugador1.POS_Y_anterior=Jugador1.POS_Y;
        Jugador1.POS_X_anterior=Jugador1.POS_X;
    }

    if ((read_controller&Abajo)==0||Jugador1.flag_pasamanos==0)
    {
        Jugador1.Estado= CAYENDO_1;
        Jugador1.Animacion_pasamano=0;
        Control1.B_presionado=1;
        Jugador1.flag_pasamanos=0;
        Index_caida=0;
    }

    if((read_controller&boton_Y)==0&&Control1.Y_presionado==0)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            DrawMegaSprite(309,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,3,3);
        else
            DrawMegaSprite(309,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        Control1.Y_presionado=1;
        Jugador1.flag_ataque_estado=3;
        Jugador1.Animacion_Ataque=0;
        Jugador1.Estado=ATAQUE_PASAMANOS_1;
    }else
    if((read_controller&boton_X)==0&&Control1.X_presionado==0&& kunay.cantidad > 0 && kunay.flag_lanzado == 0)
    {
        Jugador1.Estado = BALA_PASAMANO_1;
        kunay.cantidad--;

        DrawMegaSprite(303,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
        Jugador1.Animacion_lanzar_chunche=0;
        Control1.X_presionado=1;

    }

}


void AjustePosY(int MAX_MAP_y)
{
    if((Jugador1.POS_Y&0x0007)<=3)
    {
        Jugador1.POS_Y=Jugador1.POS_Y&0xfffffff8;
        VideoScreen.MAP_Scroll_y=VideoScreen.MAP_Scroll_y&0xfffffff8;
    }
    if((Jugador1.POS_Y&0x0007)>3)
    {
        Jugador1.POS_Y=(Jugador1.POS_Y&0xfffffff8);
        VideoScreen.MAP_Scroll_y=VideoScreen.MAP_Scroll_y&0xfffffff8;
    }

}

void AjusteSaltoScrollY(int MAX_MAP_y)
{
    if(Jugador1.flag_techo==0)
    {
       if (VideoScreen.MAP_Scroll_y < ((MAX_MAP_y-28)<<3) && (VideoScreen.MAP_Scroll_y) > 0)
       {

           VideoScreen.MAP_Scroll_y += tabla_salto[Jugador1.POS_Y_cont];
           Jugador1.POS_Y=104;
           Jugador1.POS_Y_anterior=104;
       }
       else
           Jugador1.POS_Y = Jugador1.POS_Y_anterior;
    }
}


void AjusteCaidaScrollY(int MAX_MAP_y)
{
    if(Jugador1.flag_techo==0)
    {
       if (VideoScreen.MAP_Scroll_y < ((MAX_MAP_y-28)<<3) && (VideoScreen.MAP_Scroll_y) > 0)
       {

           VideoScreen.MAP_Scroll_y += tabla_caida[Index_caida];
           Jugador1.POS_Y=104;
           //Jugador1.POS_Y_anterior=104;
       }
//       else
//           Jugador1.POS_Y = Jugador1.POS_Y_anterior;
    }
}

void AjustarMapScrollY(int MAX_MAP_y)
{

    if (Jugador1.POS_Y>MAPA_POS_Y_anterior &&Jugador1.POS_Y > 104)
    {
        VideoScreen.MAP_Scroll_y+=(Jugador1.POS_Y-MAPA_POS_Y_anterior);


        if (VideoScreen.MAP_Scroll_y < ((MAX_MAP_y-28)<<3))
        {
            Jugador1.POS_Y = 104+(Jugador1.POS_Y-MAPA_POS_Y_anterior);
        }
    }
    if (Jugador1.POS_Y<MAPA_POS_Y_anterior &&Jugador1.POS_Y < 104)
    {

        VideoScreen.MAP_Scroll_y-=(MAPA_POS_Y_anterior-Jugador1.POS_Y);


        if ((VideoScreen.MAP_Scroll_y) > 0)
        {
           Jugador1.POS_Y=104-(MAPA_POS_Y_anterior-Jugador1.POS_Y);
        }
    }
}

void INIT_ENEMIGOS(const int Enemigos_Nivel[])
{
    int enemigos_cont=0;
    int contador=0;
    while(enemigos_cont < Niveles.enemigos_x_Zona)
    {
        enemigo[enemigos_cont].MAP_POS_X=Enemigos_Nivel[Niveles.numero_enemigos+contador]<<3;
        contador++;
        enemigo[enemigos_cont].MAP_POS_Y=Enemigos_Nivel[Niveles.numero_enemigos+contador]<<3;
        contador++;
        enemigo[enemigos_cont].muerto=0;
        enemigo[enemigos_cont].estado=REPOSO;
        enemigo[enemigos_cont].vida=1;
        enemigo[enemigos_cont].ir_derecha=0;
        enemigo[enemigos_cont].POS_X_CONT=100; // esto ubica el sprite enemigo en el centro como punto de referencia X
        enemigo[enemigos_cont].POS_Y_CONT=enemigo[enemigos_cont].MAP_POS_Y; //Inicio punto de referencia Y
        enemigo[enemigos_cont].ir_izquierda=1;
        enemigo[enemigos_cont].contador_eventos=0;
        enemigo[enemigos_cont].Index_caida=0;
        enemigo[enemigos_cont].contador_eventos2=0;
        enemigo[enemigos_cont].flag_saltando=0;
        enemigo[enemigos_cont].flag_golpeado=0;
        enemigo[enemigos_cont].flag_lanzando_chunche=0;
        enemigo[enemigos_cont].Enemigo_tipo=Enemigos_Nivel[Niveles.numero_enemigos+contador];
        if(enemigo[enemigos_cont].Enemigo_tipo== OGRO)
            enemigo[enemigos_cont].vida=10;
        contador++;
        enemigos_cont++;
    }

}

void Kunay_Enemigo(int Enemigo_Numero)
{
    int index=0x0c+(Enemigo_Numero*12)+10; // calculo del indice del sprite del kunay

    if (kunay_enemigo[Enemigo_Numero].flag_origen == 1)
    {
        kunay_enemigo[Enemigo_Numero].flag_origen = 0;
        if ((enemigo[Enemigo_Numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            kunay_enemigo[Enemigo_Numero].ATRIBUTO = SPR_visible|SPR_Mirror_H|SPR_Banco1;
            spr[index].SPR_NUM = 222;
            spr[index+1].SPR_NUM = 223;
            spr[index].SPR_ATTR = kunay_enemigo[Enemigo_Numero].ATRIBUTO;
            spr[index+1].SPR_ATTR = kunay_enemigo[Enemigo_Numero].ATRIBUTO;
            spr[index].X = kunay_enemigo[Enemigo_Numero].POS_X;
            spr[index+1].X = kunay_enemigo[Enemigo_Numero].POS_X-8;
        }
        else
        {
            kunay_enemigo[Enemigo_Numero].ATRIBUTO = SPR_visible|SPR_Banco1;
            spr[index].SPR_NUM = 222;
            spr[index+1].SPR_NUM = 223;
            spr[index].SPR_ATTR = kunay_enemigo[Enemigo_Numero].ATRIBUTO;
            spr[index+1].SPR_ATTR = kunay_enemigo[Enemigo_Numero].ATRIBUTO;
            spr[index].X = kunay_enemigo[Enemigo_Numero].POS_X;
            spr[index+1].X = kunay_enemigo[Enemigo_Numero].POS_X+8;

        }
            spr[index].Y = kunay_enemigo[Enemigo_Numero].POS_Y;
            spr[index+1].Y = kunay_enemigo[Enemigo_Numero].POS_Y;
    }

    if(kunay_enemigo[Enemigo_Numero].Animacion_POS > 5 && kunay_enemigo[Enemigo_Numero].flag_lanzado==1)
    {
        spr[index].Y = kunay_enemigo[Enemigo_Numero].POS_Y+(kunay_enemigo[Enemigo_Numero].MAP_POS_Y-VideoScreen.MAP_Scroll_y);
        spr[index+1].Y = kunay_enemigo[Enemigo_Numero].POS_Y+(kunay_enemigo[Enemigo_Numero].MAP_POS_Y-VideoScreen.MAP_Scroll_y);
        if ((kunay_enemigo[Enemigo_Numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            kunay_enemigo[Enemigo_Numero].POS_X-=2;
            spr[index].X = kunay_enemigo[Enemigo_Numero].POS_X;
            spr[index+1].X = kunay_enemigo[Enemigo_Numero].POS_X-8;
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }
        else
        {
            kunay_enemigo[Enemigo_Numero].POS_X+=2;
            spr[index].X = kunay_enemigo[Enemigo_Numero].POS_X;
            spr[index+1].X = kunay_enemigo[Enemigo_Numero].POS_X+8;
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }

        if(kunay_enemigo[Enemigo_Numero].POS_X < 0 || kunay_enemigo[Enemigo_Numero].POS_X > 208||kunay_enemigo[Enemigo_Numero].POS_Y < 0 || kunay_enemigo[Enemigo_Numero].POS_Y > 208)
        {            
            kunay_enemigo[Enemigo_Numero].flag_lanzado=0;
            spr[index].SPR_ATTR = 0;
            spr[index+1].SPR_ATTR = 0;
        }
        kunay_enemigo[Enemigo_Numero].Animacion_POS = 0;
    }
}

void Bala_boss(int SPRTNUM,int bala_num)
{
    int index=0x0c+10+bala_num; // calculo del indice del sprite del kunay

    if (bala_boss[bala_num].flag_origen == 1)
    {
        boss_FX.play_lanzando=1;
        bala_boss[bala_num].flag_origen = 0;
        if ((boss.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_boss[bala_num].ATRIBUTO = SPR_visible|SPR_Mirror_H|SPR_Banco2;
            spr[index].SPR_NUM = SPRTNUM;

            spr[index].SPR_ATTR = bala_boss[bala_num].ATRIBUTO;

            spr[index].X = bala_boss[bala_num].POS_X;

        }
        else
        {
            bala_boss[bala_num].ATRIBUTO = SPR_visible|SPR_Banco2;
            spr[index].SPR_NUM = SPRTNUM;

            spr[index].SPR_ATTR = bala_boss[bala_num].ATRIBUTO;

            spr[index].X = bala_boss[bala_num].POS_X;

        }
            spr[index].Y = bala_boss[bala_num].POS_Y;
    }

    if(bala_boss[bala_num].Animacion_POS > 5 && bala_boss[bala_num].flag_lanzado==1)
    {
        spr[index].Y = bala_boss[bala_num].POS_Y+(bala_boss[bala_num].MAP_POS_Y-VideoScreen.MAP_Scroll_y);
        spr[index].SPR_NUM = SPRTNUM;
        if ((bala_boss[bala_num].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_boss[bala_num].POS_X-=2;
            spr[index].X = bala_boss[bala_num].POS_X;

//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }
        else
        {
            bala_boss[bala_num].POS_X+=2;
            spr[index].X = bala_boss[bala_num].POS_X;

//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }

        if(bala_boss[bala_num].POS_X < 0 || bala_boss[bala_num].POS_X > 208||bala_boss[bala_num].POS_Y < 0 || bala_boss[bala_num].POS_Y > 208)
        {
            bala_boss[bala_num].flag_lanzado=0;
            spr[index].SPR_ATTR = 0;

        }
        bala_boss[bala_num].Animacion_POS = 0;
    }
}


void Bala_Enemigo(int SPRTNUM,int bala_num)
{
    int index=0x0c+(bala_num*12)+9; // calculo del indice del sprite de la bala

    if (bala_enemigo[bala_num].flag_origen == 1)
    {
        bala_enemigo[bala_num].flag_origen = 0;
        if ((enemigo[bala_num].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_enemigo[bala_num].ATRIBUTO = SPR_visible|SPR_Mirror_H|SPR_Banco1;
            spr[index].SPR_NUM = SPRTNUM;

            spr[index].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;

            spr[index].X = bala_enemigo[bala_num].POS_X;

        }
        else
        {
            bala_enemigo[bala_num].ATRIBUTO = SPR_visible|SPR_Banco1;
            spr[index].SPR_NUM = SPRTNUM;

            spr[index].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;

            spr[index].X = bala_enemigo[bala_num].POS_X;

        }
            spr[index].Y = bala_enemigo[bala_num].POS_Y;
    }

    if(kunay_enemigo[bala_num].Animacion_POS > 10 && bala_enemigo[bala_num].flag_lanzado==1)
    {
        spr[index].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;
        spr[index].Y = bala_enemigo[bala_num].POS_Y+(bala_enemigo[bala_num].MAP_POS_Y-VideoScreen.MAP_Scroll_y);
        bala_enemigo[bala_num].SPR_POS_Y=spr[index].Y;
        spr[index].SPR_NUM = SPRTNUM;
        if ((bala_enemigo[bala_num].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_enemigo[bala_num].POS_X-=2;
            spr[index].X = bala_enemigo[bala_num].POS_X+(bala_enemigo[bala_num].MAP_POS_X-VideoScreen.MAP_Scroll_x);
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }
        else
        {
            bala_enemigo[bala_num].POS_X+=2;
            spr[index].X = bala_enemigo[bala_num].POS_X+(bala_enemigo[bala_num].MAP_POS_X-VideoScreen.MAP_Scroll_x);;

//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }

        if(spr[index].X < 0 || spr[index].X > 208||spr[index].Y < 24 || spr[index].Y > 208)
        {
            bala_enemigo[bala_num].flag_lanzado=0;
            spr[index].SPR_ATTR = 0;

        }
        kunay_enemigo[bala_num].Animacion_POS=0;
    }
}

void Bala2_Enemigo(int SPRTNUM,int bala_num)
{
    int index=((bala_num-5)*12)+10; // calculo del indice del sprite de la bala
                                    // en esta bala hay que tomar que cuenta que el indice esta a 5 pocciocones arriba para no colicionar con los datos de las balas individuales
    if (bala_enemigo[bala_num].flag_origen == 1)
    {
        bala_enemigo[bala_num].flag_origen = 0;
        if ((enemigo[bala_num-5].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_enemigo[bala_num].ATRIBUTO = SPR_visible|SPR_Mirror_H|SPR_Banco1;
            spr[index].SPR_NUM = SPRTNUM;
            spr[index+1].SPR_NUM = SPRTNUM+1;

            spr[index].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;
            spr[index+1].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;

            spr[index].X = bala_enemigo[bala_num].POS_X;
            spr[index+1].X = bala_enemigo[bala_num].POS_X+8;

        }
        else
        {
            bala_enemigo[bala_num].ATRIBUTO = SPR_visible|SPR_Banco1;
            spr[index].SPR_NUM = SPRTNUM;
            spr[index+1].SPR_NUM = SPRTNUM+1;

            spr[index].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;
            spr[index+1].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;

            spr[index].X = bala_enemigo[bala_num].POS_X;
            spr[index+1].X = bala_enemigo[bala_num].POS_X+8;

        }
            spr[index].Y = bala_enemigo[bala_num].POS_Y;
            spr[index+1].Y = bala_enemigo[bala_num].POS_Y;
    }

    if(kunay_enemigo[bala_num-5].Animacion_POS > 10 && bala_enemigo[bala_num].flag_lanzado==1)
    {
        spr[index].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;
        spr[index+1].SPR_ATTR = bala_enemigo[bala_num].ATRIBUTO;

        spr[index].Y = bala_enemigo[bala_num].POS_Y+(bala_enemigo[bala_num].MAP_POS_Y-VideoScreen.MAP_Scroll_y);
        spr[index+1].Y =spr[index].Y;

        bala_enemigo[bala_num].SPR_POS_Y=spr[index].Y;
        spr[index].SPR_NUM = SPRTNUM;
        spr[index+1].SPR_NUM = SPRTNUM+1;

        if ((bala_enemigo[bala_num].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_enemigo[bala_num].POS_X-=2;
            spr[index].X = bala_enemigo[bala_num].POS_X+(bala_enemigo[bala_num].MAP_POS_X-VideoScreen.MAP_Scroll_x);
            spr[index+1].X = spr[index].X-8;
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }
        else
        {
            bala_enemigo[bala_num].POS_X+=2;
            spr[index].X = bala_enemigo[bala_num].POS_X+(bala_enemigo[bala_num].MAP_POS_X-VideoScreen.MAP_Scroll_x);
            spr[index+1].X = spr[index].X+8;
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }

        if(spr[index].X < 0 || spr[index].X > 208|| spr[index].Y < 24 ||  spr[index].Y > 208)
        {
            bala_enemigo[bala_num].flag_lanzado=0;
            spr[index].SPR_ATTR = 0;
            spr[index+1].SPR_ATTR = 0;

        }
        kunay_enemigo[bala_num-5].Animacion_POS=0;
    }
}


void Bala_Disco_boss(int SPRTNUM,int bala_num)
{
    int index=0x0c+10+bala_num*4; // calculo del indice del sprite del kunay

    if (bala_boss[bala_num].flag_origen == 1)
    {
        boss_FX.play_lanzando=1;
        bala_boss[bala_num].flag_origen = 0;
        if ((boss.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_boss[bala_num].ATRIBUTO = SPR_visible|SPR_Mirror_H|SPR_Banco2|(index<<8);
            DrawMegaSprite(SPRTNUM, bala_boss[bala_num].ATRIBUTO,bala_boss[bala_num].POS_X,bala_boss[bala_num].POS_Y,2,2);

        }
        else
        {
            bala_boss[bala_num].ATRIBUTO = SPR_visible|SPR_Banco2|(index<<8);
            DrawMegaSprite(SPRTNUM, bala_boss[bala_num].ATRIBUTO,bala_boss[bala_num].POS_X,bala_boss[bala_num].POS_Y,2,2);

        }
            
    }

    if(bala_boss[bala_num].Animacion_POS > 5 && bala_boss[bala_num].flag_lanzado==1)
    {

        if ((bala_boss[bala_num].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            bala_boss[bala_num].POS_X-=2;
            DrawMegaSprite(SPRTNUM, bala_boss[bala_num].ATRIBUTO,bala_boss[bala_num].POS_X,bala_boss[bala_num].POS_Y+(bala_boss[bala_num].MAP_POS_Y-VideoScreen.MAP_Scroll_y),2,2);

//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }
        else
        {
            bala_boss[bala_num].POS_X+=2;
            DrawMegaSprite(SPRTNUM, bala_boss[bala_num].ATRIBUTO,bala_boss[bala_num].POS_X,bala_boss[bala_num].POS_Y,2,2);


//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }

        if(bala_boss[bala_num].POS_X < 0 || bala_boss[bala_num].POS_X > 208||bala_boss[bala_num].POS_Y < 0 || bala_boss[bala_num].POS_Y > 208)
        {
            bala_boss[bala_num].flag_lanzado=0;
            boss.flag_lanzando_chunche=0;
            spr[index].SPR_ATTR = 0;
            spr[index+1].SPR_ATTR = 0;
            spr[index+2].SPR_ATTR = 0;
            spr[index+3].SPR_ATTR = 0;

        }
        bala_boss[bala_num].Animacion_POS = 0;
    }
}

void Kunay()
{
    if (kunay.flag_origen == 1)
    {
        kunay.flag_origen = 0;
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            kunay.ATRIBUTO = SPR_visible|SPR_Mirror_H;
            spr[80].SPR_NUM = 489;
            spr[81].SPR_NUM = 490;
            spr[80].SPR_ATTR = kunay.ATRIBUTO;
            spr[81].SPR_ATTR = kunay.ATRIBUTO;
            spr[80].X = kunay.POS_X;
            spr[81].X = kunay.POS_X-8;
        }
        else
        {
            kunay.ATRIBUTO = SPR_visible;
            spr[80].SPR_NUM = 489;
            spr[81].SPR_NUM = 490;
            spr[80].SPR_ATTR = kunay.ATRIBUTO;
            spr[81].SPR_ATTR = kunay.ATRIBUTO;
            spr[80].X = kunay.POS_X;
            spr[81].X = kunay.POS_X+8;

        }
            spr[80].Y = kunay.POS_Y;
            spr[81].Y = kunay.POS_Y;
    }

    if(kunay.Animacion_POS > 5 && kunay.flag_lanzado==1)
    {
        spr[80].Y = kunay.POS_Y+(kunay.MAP_POS_Y-VideoScreen.MAP_Scroll_y);
        spr[81].Y = kunay.POS_Y+(kunay.MAP_POS_Y-VideoScreen.MAP_Scroll_y);

        kunay.SPR_POS_Y = spr[80].Y;
        if ((kunay.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
        {
            kunay.POS_X-=2;
            spr[80].X = kunay.POS_X;
            spr[81].X = kunay.POS_X-8;
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }
        else
        {
            kunay.POS_X+=2;
            spr[80].X = kunay.POS_X;
            spr[81].X = kunay.POS_X+8;
//            spr[38].Y = kunay.POS_Y;
//            spr[39].Y = kunay.POS_Y;
        }

        if(kunay.POS_X < 0 || kunay.POS_X > 208||kunay.POS_Y < 0 || kunay.POS_Y > 208)
        {
            kunay.flag_lanzado=0;
            spr[80].SPR_ATTR = 0;
            spr[81].SPR_ATTR = 0;
        }
        kunay.Animacion_POS = 0;
    }
}

void INIT_LAMPARAS(const int lamparas_nivel[])
{
    int lamparas_cont=0;
    int contador=0;

    while(lamparas_cont < 5)
    {
        lampara[lamparas_cont].MAP_POS_X = lamparas_nivel[Niveles.contador_lamparas+contador]<<3;
        contador++;
        lampara[lamparas_cont].MAP_POS_Y = lamparas_nivel[Niveles.contador_lamparas+contador]<<3;
        contador++;
        lampara[lamparas_cont].reventada=0;
        lampara[lamparas_cont].seleccionada=0;
        lampara[lamparas_cont].ITEM_VISIBLE=0;
        lampara[lamparas_cont].contador=0;
        lampara[lamparas_cont].POS_Y_CONT=0;
        lampara[lamparas_cont].expiracion=0;
        lampara[lamparas_cont].flag_suelo = 0;
        lampara[lamparas_cont].ITEM = lamparas_nivel[Niveles.contador_lamparas+contador];
        contador++;
        lamparas_cont++;
    }
}

void Jugador1_CONTROL(const unsigned char MAPA[],int MIN_MAP_x,int MIN_MAP_y,int MAX_MAP_x,int MAX_MAP_y)
{
    int index1_map;
    int Cant_Bloques_De=0;
    int Cant_Bloques_Iz=0;
    int cont=0,x;
    int comparaciones=0;
    int temp;
    char buf[15];
   /* String STRdata;
    STRdata = String(Jugador1.POS_Y,10);
    STRdata.toCharArray(buf,15);
    print_txt(buf,15,3,BG_ROJO,BLANCO);
    STRdata = String(Jugador1.POS_X,10);
    STRdata.toCharArray(buf,15);
    print_txt(buf,15,4,BG_ROJO,BLANCO);*/

    
    MAPA_POS_Y_anterior =Jugador1.POS_Y; // se guarda la posicion en Y anterior para hacer el scroll luego de todas las comparaciones
    while(cont < 3)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((Jugador1.POS_X+VideoScreen.Scroll_X+4)>>3)+cont)&0x001f) | ((((Jugador1.POS_Y+VideoScreen.Scroll_Y+24)&0x00f8)>>3)*32);
        else
            index1_map = ((((Jugador1.POS_X+VideoScreen.Scroll_X+2)>>3)+cont)&0x001f) | ((((Jugador1.POS_Y+VideoScreen.Scroll_Y+24)&0x00f8)>>3)*32);
//        VideoScreen.MAP_1[165+cont]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {

            comparaciones++;
            Index_caida = 0;
        }
        if(temp == 4||temp == 5||temp == 20||temp == 21||temp == 47||temp == 63 )
        {
            //DrawMegaSprite(125,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if((Jugador1.muerto==0) & (Jugador1.flag_transparente == 0))
            {
                DrawMegaSprite(125,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Estado=GOLPE_MUERTE_2;
                Jugador1.Animacion_Ataque=0;
                Jugador1.contador_eventos=0;
                 Niveles.Contador_eventos=0;
            }
            //Jugador1.muerto=1;
            //print_txt("Picos",8,6,BG_NEGRO,BLANCO);

        }
        cont++;
    }
    if (comparaciones > 0)
    {
        Jugador1.flag_cayendo=0;
    }
    else
        Jugador1.flag_cayendo=1;
//utoa(buf,Jugador1.Estado,10);
//    print_txt(buf,8,4,BG_ROJO,BLANCO);

    cont=0;
    comparaciones=0;

    while(cont < 3)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((Jugador1.POS_X+28+VideoScreen.Scroll_X)>>3))&0x001f) | (((((Jugador1.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        else
            index1_map = ((((Jugador1.POS_X+21+VideoScreen.Scroll_X)>>3))&0x001f) | (((((Jugador1.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        //VideoScreen.MAP_1[72+cont*32]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        cont++;
    }
    if (comparaciones > 0)
        Jugador1.flag_Obstruido_De=1;
    else
        Jugador1.flag_Obstruido_De=0;
    if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
    Cant_Bloques_De=comparaciones;
    cont=0;
    comparaciones=0;

    while(cont < 3)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((Jugador1.POS_X+26+VideoScreen.Scroll_X)>>3)-3)&0x001f) | (((((Jugador1.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        else
            index1_map = ((((Jugador1.POS_X+19+VideoScreen.Scroll_X)>>3)-3)&0x001f) | (((((Jugador1.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);

        //VideoScreen.MAP_1[68+cont*32]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        cont++;
    }
    if (comparaciones > 0)
        Jugador1.flag_Obstruido_Iz=1;
    else
        Jugador1.flag_Obstruido_Iz=0;

    if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
    Cant_Bloques_Iz=comparaciones;


    cont =0;
    comparaciones=0;
    Jugador1.flag_techo=0;
    Jugador1.flag_pasamanos=0;
    while(cont<3)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((Jugador1.POS_X+VideoScreen.Scroll_X+5)>>3)+cont)&0x001f) | (((((Jugador1.POS_Y+VideoScreen.Scroll_Y)>>3))&0x001f)*32);
        else
            index1_map = ((((Jugador1.POS_X+VideoScreen.Scroll_X+2)>>3)+cont)&0x001f) | (((((Jugador1.POS_Y+VideoScreen.Scroll_Y)>>3))&0x001f)*32);
        //VideoScreen.MAP_1[37+cont]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            Jugador1.flag_techo=1;
        }
        if(temp==64||temp==65)
        {
            Jugador1.flag_pasamanos=1;

        }
        cont++;
    }
// if(Jugador1.Animacion_posicion>10&&Jugador1.flag_escalando==0 && Jugador1.flag_ataque_estado!=1&&Jugador1.flag_ataque_estado!=3&&Jugador1.flag_agachado==0&&Jugador1.flag_ataque_estado!=5&&Jugador1.muerto==0&&Jugador1.flag_transparente==0&&Jugador1.Estado!=AGACHADO)
    if(Jugador1.Animacion_posicion>10&&Jugador1.flag_escalando==0 && Jugador1.flag_ataque_estado!=1&&Jugador1.flag_ataque_estado!=3&&Jugador1.flag_agachado==0&&Jugador1.flag_ataque_estado!=5&&Jugador1.muerto==0&&Jugador1.Estado!=AGACHADO&&Jugador1.Estado!=CONGELADO) // control del desplazamiento en (X,Y)
    {

        Jugador1.flag_corriendo=0; // se limpia la bandera
        if ((read_controller&Derecha)==0)
        {
            if (Jugador1.flag_Obstruido_De == 0)
            Jugador1.POS_X++;
            if(Jugador1.flag_transparente == 0)
                Jugador1.ATRIBUTO = SPR_visible|SPR_Banco0;
            else
                Jugador1.ATRIBUTO = SPR_invisible&SPR_Banco0;
            
            
            Jugador1.flag_corriendo=1;
            chequear_pos_DE(MAX_MAP_x);
        }

        if ((read_controller&Izquierda)==0)
        {
            if (Jugador1.flag_Obstruido_Iz == 0)
            Jugador1.POS_X--;
            if(Jugador1.flag_transparente == 0)
                Jugador1.ATRIBUTO = SPR_visible|SPR_Banco0|SPR_Mirror_H;
            else
                Jugador1.ATRIBUTO = SPR_invisible&(SPR_Banco0|SPR_Mirror_H);
            Jugador1.flag_corriendo=1;
            chequear_pos_IZ(MIN_MAP_x);
        }
        Jugador1.Animacion_posicion = 0;

    }

    if((read_controller&boton_B)==boton_B)
            Control1.B_presionado=0;

// manejador de la bala o kunay en este caso
    if(Jugador1.POS_Y > 214 && Jugador1.muerto==0)
    {
        Jugador1.vidas--;
        Jugador1.Estado=MUERTE_CAIDA;
        Jugador1.Animacion_general=0;
        Niveles.opacidad = 7;
        Niveles.Contador_eventos = 0;
    }
// <editor-fold defaultstate="collapsed" desc="Maquina de estados Jugador 1">
    switch (Jugador1.Estado)
    {
        case REPOSO:
            Jugador1.flag_escalando=0;
            Jugador1.flag_ataque_estado=0;
            DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if(Jugador1.flag_cayendo == 1) Jugador1.Estado = CAYENDO_1;
            if(Jugador1.flag_corriendo==1) Jugador1.Estado = CORRER_1;

            if((read_controller&Abajo)==0 && Jugador1.flag_cayendo == 0)
            {

                Jugador1.Estado = AGACHADO;
                Jugador1.flag_agachado=1;
            }
            if((read_controller&boton_X)==0&&Control1.X_presionado==0&& kunay.cantidad > 0 && kunay.flag_lanzado == 0)
            {
                Jugador1.Estado = BALA_REPOSO_1;
                kunay.cantidad--;

                DrawMegaSprite(12,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                Control1.X_presionado=1;

            }else

            if((read_controller&boton_Y)==0&&Control1.Y_presionado==0)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(117,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(117,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Control1.Y_presionado=1;
                Jugador1.flag_ataque_estado=1;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_DETENIDO_1;
                
            }


            if((read_controller&boton_B)==0&&Control1.B_presionado==0 && Jugador1.flag_cayendo == 0)
            {
                DrawMegaSprite(117,0,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Estado= SALTO_ESTATICO_1;
                Jugador1.POS_Y_anterior=Jugador1.POS_Y;
                Control1.B_presionado=1;
                Jugador1.POS_Y_cont=0;
                Jugador1.flag_saltando=1;
            }
            Jugador1.Estado_Anterior=0;
            Jugador1.Animacion_caminando = 0;
        break;
    //*************************correr
        case CORRER_1:
            if(Jugador1.Animacion_caminando>Delay_Correr)
            {
                DrawMegaSprite(3,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_caminando=0;
                Jugador1.Estado = CORRER_2;
                Jugador1.Estado_Anterior=CORRER_2;
                Jugador1.Animacion_caminando = 0;
            }
            Condiciones_correr();
        break;

        case CORRER_2:

            if(Jugador1.Animacion_caminando>Delay_Correr)
            {
                DrawMegaSprite(6,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.Estado_Anterior==CORRER_2)
                    Jugador1.Estado = CORRER_3;
                if (Jugador1.Estado_Anterior==CORRER_3)
                    Jugador1.Estado = CORRER_1;

                Jugador1.Animacion_caminando = 0;
            }
            Condiciones_correr();
        break;

        case CORRER_3:

            if(Jugador1.Animacion_caminando>Delay_Correr)
            {
                DrawMegaSprite(9,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_caminando=0;
                Jugador1.Estado = CORRER_2;
                Jugador1.Estado_Anterior=CORRER_3;
                Jugador1.Animacion_caminando = 0;
            }
            Condiciones_correr();
        break;

//*************************Ataque correr
        case GOLPE_MUERTE_1:
            Jugador1.flag_transparente=1;  // luego que es tocado por algo que baja energia

            if(Jugador1.Animacion_Ataque>80)
            {
                Jugador1.contador_eventos++;
                DrawMegaSprite(125,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_Ataque=0;
            }
            if(Jugador1.Animacion_Ataque>25)
                DrawMegaSprite(114,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);

            if(Jugador1.contador_eventos > 10)
            {
                Jugador1.contador_eventos=0;
                Jugador1.Estado = MUERTE_CAIDA;
                Jugador1.vidas--;
                Limpiar_sprites_mem();
                DrawMegaSprite(114,0,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                //Jugador1.flag_transparente=0;
            }
        break;
        case GOLPE_MUERTE_2:
            Jugador1.flag_transparente=1;
            if(Jugador1.Animacion_Ataque>7)
            {
                Jugador1.contador_eventos++;
                Jugador1.Animacion_Ataque=0;
                if(Jugador1.flag_cayendo == 1)
                {
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                    AjusteCaidaScrollY(MAX_MAP_y);
                    Index_caida++;
                }
                if (Jugador1.flag_cayendo == 0)
                {
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                     Index_caida=0;
                     Jugador1.flag_escalando=0;
                }

                if (Jugador1.mirror==0)
                {
                    if (Jugador1.flag_Obstruido_De == 0)
                    Jugador1.POS_X+=1;
                    chequear_pos_DE(MAX_MAP_x);
                }
                else
                {
                    if (Jugador1.flag_Obstruido_Iz == 0)
                    Jugador1.POS_X-=1;
                    chequear_pos_IZ(MIN_MAP_x);

                }
            }

            if((Jugador1.contador_eventos&4)==4)
                DrawMegaSprite(125,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            else
                DrawMegaSprite(114,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);

            if(Jugador1.contador_eventos > 16)
            {
                Jugador1.contador_eventos=0;
                Niveles.Contador_eventos=0;
                Jugador1.vida--;
                if(Jugador1.vida <= 0)
                {
                    Jugador1.flag_transparente=0;
                    Jugador1.vidas--;
                    Jugador1.vida=0;
                    Jugador1.Estado = MUERTE_CAIDA;
                    Jugador1.muerto=1;

                }
                else
                    Jugador1.Estado = REPOSO;

                DrawMegaSprite(114,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                //Jugador1.flag_transparente=0;
            }

        break;
        case GOLPE_MUERTE_3:
            DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
        break;

//**************************salto normal

        case SALTO_NORMAL_1:
            Condiciones_saltonormal(Cant_Bloques_De,Cant_Bloques_Iz);
            if(Jugador1.Animacion_saltando>Delay_Salto&&Jugador1.Estado==SALTO_NORMAL_1)
            {
                DrawMegaSprite(208,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);

                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;



                Jugador1.Animacion_saltando=0;
                Jugador1.Estado = SALTO_NORMAL_2;
            }

        break;

        case SALTO_NORMAL_2:
            Condiciones_saltonormal(Cant_Bloques_De,Cant_Bloques_Iz);

            if(Jugador1.Animacion_saltando>Delay_Salto&&Jugador1.Estado==SALTO_NORMAL_2)
            {

                DrawMegaSprite(211,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;

                Jugador1.Animacion_saltando=0;
                Jugador1.Estado = SALTO_NORMAL_3;
            }

        break;

        case SALTO_NORMAL_3:
            Condiciones_saltonormal(Cant_Bloques_De,Cant_Bloques_Iz);
            if(Jugador1.Animacion_saltando>Delay_Salto&&Jugador1.Estado==SALTO_NORMAL_3)
            {

                DrawMegaSprite(214,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;


                Jugador1.Animacion_saltando=0;
                Jugador1.Estado=SALTO_NORMAL_4;
            }

        break;

        case SALTO_NORMAL_4:
            Condiciones_saltonormal(Cant_Bloques_De,Cant_Bloques_Iz);
            if(Jugador1.Animacion_saltando>Delay_Salto&&Jugador1.Estado==SALTO_NORMAL_4)
            {

                DrawMegaSprite(217,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;

                Jugador1.Animacion_saltando=0;
                Jugador1.Estado=SALTO_NORMAL_1;
            }

        break;

//**************************salto normal
        case SALTO_ESTATICO_1:


            if(Jugador1.Animacion_saltando>Delay_Salto)
            {
                DrawMegaSprite(96,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;


                Jugador1.Animacion_saltando=0;

                if (Jugador1.POS_Y_cont>(POS_Y_MAX/2))
                    Jugador1.Estado = SALTO_ESTATICO_2;
            }
            Condiciones_saltoestatico();
        break;

        case SALTO_ESTATICO_2:

            if(Jugador1.Animacion_saltando>Delay_Salto)
            {
                DrawMegaSprite(99,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;

                Jugador1.Animacion_saltando=0;
                if (Jugador1.POS_Y_cont>(POS_Y_MAX-28))
                    Jugador1.Estado = SALTO_ESTATICO_3;
            }
            Condiciones_saltoestatico();
        break;

        case SALTO_ESTATICO_3:


            if(Jugador1.Animacion_saltando>Delay_Salto)
            {
                DrawMegaSprite(102,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Jugador1.POS_Y_cont < 8)
                    Jugador1.POS_Y_anterior+=tabla_salto[Jugador1.POS_Y_cont++];
                AjusteSaltoScrollY(MAX_MAP_y);
                if(Jugador1.POS_Y_cont > POS_Y_MAX)
                Jugador1.POS_Y_cont=POS_Y_MAX;

                Jugador1.Animacion_saltando=0;

            }
            Condiciones_saltoestatico();
        break;

//**************************salto Ataque

        break;
        case SALTO_ATAQUE_1:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(288,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(288,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);

                if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                 //AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_Ataque=0;
                 Index_caida++;
                 if(Index_caida > 255) Index_caida = 255;

                 Jugador1.Estado=SALTO_ATAQUE_2;


                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_ataque_estado=1;
                     Jugador1.Estado=ATAQUE_DETENIDO_1;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
        break;

        case SALTO_ATAQUE_2:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                 if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(292,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(292,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                 if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                 //AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_Ataque=0;
                 Index_caida++;
                 if(Index_caida > 255) Index_caida = 255;

                 Jugador1.Estado=SALTO_ATAQUE_3;


                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_ataque_estado=1;
                     Jugador1.Estado=ATAQUE_DETENIDO_2;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
        break;

        case SALTO_ATAQUE_3:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                 DrawMegaSprite(292,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                 if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                 //AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_Ataque=0;
                 Jugador1.Animacion_cayendo=0;
                 Index_caida++;
                 if(Index_caida > 255) Index_caida = 255;
                 DrawMegaSprite(99,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                 Jugador1.Estado=CAYENDO_1;
                 Jugador1.flag_ataque_estado=0;

                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_ataque_estado=0;
                     Jugador1.Estado=REPOSO;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
        break;
/****************** Cayendo  ****************************************/
        case CAYENDO_1:
            if(Jugador1.Animacion_cayendo > Delay_Cayendo)
            {
                 DrawMegaSprite(99,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                 if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];

                 AjusteCaidaScrollY(MAX_MAP_y);
                 //AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_cayendo=0;
                 Index_caida++;
                 if (Index_caida > 30)
                 {
                     Jugador1.Estado=CAYENDO_2;
                 }

                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_escalando=0;
                     Jugador1.Estado=REPOSO;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
        break;

        case CAYENDO_2:
            if(Jugador1.Animacion_cayendo > Delay_Cayendo)
            {
                 DrawMegaSprite(102,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                 if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];

                 AjusteCaidaScrollY(MAX_MAP_y);
                 //AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_cayendo=0;
                 Index_caida++;


                 if (Jugador1.flag_cayendo == 0)
                 {
                     if(Index_caida>20)
                        AjustePosY(MAX_MAP_y);
                     Index_caida=0;
                     Jugador1.flag_escalando=0;
                     Jugador1.Estado=REPOSO;
                 }



            }
        break;

//**********************************escalar
        case ESCALAR_1:
            Condiciones_escalar(MAX_MAP_x);

            if(Jugador1.Animacion_escalando > Delay_Escalando)
            {

                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
                        DrawMegaSprite(318,Jugador1.ATRIBUTO,Jugador1.POS_X+10,Jugador1.POS_Y,2,3);
                else
                        DrawMegaSprite(318,Jugador1.ATRIBUTO,Jugador1.POS_X+1,Jugador1.POS_Y,2,3);
                Jugador1.Animacion_escalando=0;
                if ((read_controller&Arriba)==0)
                {

                    if(Jugador1.flag_techo==0)
                    Jugador1.POS_Y--;


                    if(Jugador1.Animacion_general>100)
                    {
                       Jugador1.Animacion_general=0;
                       Jugador1.Estado=ESCALAR_2;
                    }

                }
                else
                    if ((read_controller&Abajo)==0)
                    {


                        Jugador1.POS_Y++;




                        if(Jugador1.Animacion_general>100)
                        {
                           Jugador1.Animacion_general=0;
                           Jugador1.Estado=ESCALAR_2;
                        }

                    }


            }
        break;
        case ESCALAR_2:
            Condiciones_escalar(MAX_MAP_x);
            if(Jugador1.Animacion_escalando > Delay_Escalando)
            {

                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
                        DrawMegaSprite(384,Jugador1.ATRIBUTO,Jugador1.POS_X+10,Jugador1.POS_Y,2,3);
                else
                        DrawMegaSprite(384,Jugador1.ATRIBUTO,Jugador1.POS_X+1,Jugador1.POS_Y,2,3);
                Jugador1.Animacion_escalando=0;
                if ((read_controller&Arriba)==0)
                {

                    if(Jugador1.flag_techo==0)
                    Jugador1.POS_Y--;

                    if(Jugador1.Animacion_general>100)
                    {
                       Jugador1.Animacion_general=0;
                       Jugador1.Estado=ESCALAR_3;
                    }

                }
                else
                    if ((read_controller&Abajo)==0)
                    {


                        Jugador1.POS_Y++;


                        if(Jugador1.Animacion_general>100)
                        {
                           Jugador1.Animacion_general=0;
                           Jugador1.Estado=ESCALAR_3;
                        }

                    }

            }

        break;
        case ESCALAR_3:
            Condiciones_escalar(MAX_MAP_x);
            if(Jugador1.Animacion_escalando > Delay_Escalando)
            {

                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
                        DrawMegaSprite(386,Jugador1.ATRIBUTO,Jugador1.POS_X+10,Jugador1.POS_Y,2,3);
                else
                        DrawMegaSprite(386,Jugador1.ATRIBUTO,Jugador1.POS_X+1,Jugador1.POS_Y,2,3);
                Jugador1.Animacion_escalando=0;


                if ((read_controller&Arriba)==0)
                {

                    if(Jugador1.flag_techo==0)
                    Jugador1.POS_Y--;
                    if(Jugador1.Animacion_general>100)
                    {
                       Jugador1.Animacion_general=0;
                       Jugador1.Estado=ESCALAR_1;
                    }

                }
                else
                    if ((read_controller&Abajo)==0)
                    {

                        Jugador1.POS_Y++;
                        if(Jugador1.Animacion_general>100)
                        {
                           Jugador1.Animacion_general=0;
                           Jugador1.Estado=ESCALAR_1;
                        }

                    }

            }

        break;

        case PASAMANOS_1:
            if(Jugador1.Animacion_pasamano > Delay_Pasamanos)
            {
                DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
                if(Jugador1.flag_corriendo==1)
                Jugador1.Estado=PASAMANOS_2;
                Jugador1.Estado_Anterior=PASAMANOS_2;
               Jugador1.Animacion_pasamano=0;
               Jugador1.Animacion_posicion = 0;
            }
            Condiciones_pasamano();

            break;
        case PASAMANOS_2:
            if(Jugador1.Animacion_pasamano > Delay_Pasamanos)
            {
                DrawMegaSprite(299,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
                if(Jugador1.flag_corriendo==1)
                {
                    if (Jugador1.Estado_Anterior==PASAMANOS_2)
                        Jugador1.Estado=PASAMANOS_3;
                    if (Jugador1.Estado_Anterior==PASAMANOS_3)
                        Jugador1.Estado=PASAMANOS_1;
                }
                Jugador1.Animacion_posicion = 0;
               Jugador1.Animacion_pasamano=0;
            }
            Condiciones_pasamano();
            break;
        case PASAMANOS_3:
            if(Jugador1.Animacion_pasamano>Delay_Pasamanos)
            {
                DrawMegaSprite(301,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
                if(Jugador1.flag_corriendo==1)
                Jugador1.Estado = PASAMANOS_2;
                Jugador1.Estado_Anterior=PASAMANOS_3;
                Jugador1.Animacion_pasamano = 0;
                Jugador1.Animacion_posicion = 0;
            }
            Condiciones_pasamano();
            break;

        case ATAQUE_DETENIDO_1:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(121,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(121,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Jugador1.flag_ataque_estado=1;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_DETENIDO_2;
            }
            break;
        case ATAQUE_DETENIDO_2:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(192,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(192,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Jugador1.flag_ataque_estado=1; // 1: ataque detenido
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_DETENIDO_3;
            }
            break;
        case ATAQUE_DETENIDO_3:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                DrawMegaSprite(192,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=REPOSO;
                Jugador1.flag_ataque_estado=0;
            }
            break;



       case ATAQUE_CORRIENDO_1:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(200,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(200,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Jugador1.flag_ataque_estado=2;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_CORRIENDO_2;
            }
            break;
        case ATAQUE_CORRIENDO_2:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(204,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(204,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Jugador1.flag_ataque_estado=2; // 1: ataque detenido
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_CORRIENDO_3;
            }
            break;
        case ATAQUE_CORRIENDO_3:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                DrawMegaSprite(204,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=REPOSO;
                Jugador1.flag_ataque_estado=0;
            }
            break;

        case ATAQUE_PASAMANOS_1:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(312,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,3,3);
                else
                    DrawMegaSprite(312,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.flag_ataque_estado=3;
                Jugador1.Animacion_posicion = 0;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_PASAMANOS_2;
            }
            break;
        case ATAQUE_PASAMANOS_2:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(315,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,3,3);
                else
                    DrawMegaSprite(315,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.flag_ataque_estado=3; // 1: ataque detenido
                Jugador1.Animacion_Ataque=0;
                Jugador1.Animacion_posicion = 0;
                Jugador1.Estado=ATAQUE_PASAMANOS_3;
            }
            break;
        case ATAQUE_PASAMANOS_3:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                DrawMegaSprite(315,0,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
                Jugador1.Animacion_Ataque=0;
                Jugador1.Animacion_posicion = 0;
                Jugador1.Estado=PASAMANOS_1;
                Jugador1.flag_ataque_estado=0;
            }
            break;

        case AGACHADO:
            DrawMegaSprite(391,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if((read_controller&Abajo)==Abajo)
            {
                Jugador1.Estado = REPOSO;
                Jugador1.flag_agachado=0;
            }
            if((read_controller&boton_Y)==0&&Control1.Y_presionado==0)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(394,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(394,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Control1.Y_presionado=1;
                Jugador1.flag_ataque_estado=5;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_AGACHADO_1;
            }else

            if((read_controller&boton_X)==0&&Control1.X_presionado==0&& kunay.cantidad > 0 && kunay.flag_lanzado == 0)
            {
                kunay.cantidad--;

                DrawMegaSprite(391,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                Jugador1.flag_lanzando_chunche=1;
                Control1.X_presionado=1;
                Jugador1.Estado = BALA_AGACHADO_1;
            }
            break;

        case ATAQUE_AGACHADO_1:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(398,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(398,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Jugador1.flag_ataque_estado=5;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_AGACHADO_2;
            }
            break;
        case ATAQUE_AGACHADO_2:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                    DrawMegaSprite(402,Jugador1.ATRIBUTO,Jugador1.POS_X-8,Jugador1.POS_Y,4,3);
                else
                    DrawMegaSprite(402,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Jugador1.flag_ataque_estado=5;
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=ATAQUE_AGACHADO_3;
            }
            break;
        case ATAQUE_AGACHADO_3:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                DrawMegaSprite(315,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                DrawMegaSprite(391,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_Ataque=0;
                Jugador1.Estado=AGACHADO;
                Jugador1.flag_ataque_estado=0;

            }
            break;

        case BALA_AGACHADO_1:
            if(Jugador1.Animacion_lanzar_chunche >Delay_Ataque)
            {
                DrawMegaSprite(406,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                if(kunay.flag_lanzado==0)
                    Jugador1.Estado=BALA_AGACHADO_2;
                else
                    Jugador1.Estado=AGACHADO;

            }
            break;

        case BALA_AGACHADO_2:
            if(Jugador1.Animacion_lanzar_chunche > Delay_Ataque)
            {
                Jugador1.Estado=BALA_AGACHADO_3;
                DrawMegaSprite(409,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                kunay.flag_lanzado = 1;
                kunay.flag_origen = 1;
                kunay.MAP_POS_X = VideoScreen.MAP_Scroll_x;
                kunay.MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                kunay.POS_X = Jugador1.POS_X;
                kunay.POS_Y = Jugador1.POS_Y+15;
            }
            break;
        case BALA_AGACHADO_3:
            if(Jugador1.Animacion_lanzar_chunche > Delay_Ataque)
            {
                Jugador1.Estado=AGACHADO;
                Jugador1.Animacion_lanzar_chunche=0;
            }
            break;

        case BALA_PASAMANO_1:
            if(Jugador1.Animacion_lanzar_chunche >Delay_Ataque)
            {
                DrawMegaSprite(305,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);

                Jugador1.Animacion_lanzar_chunche=0;
                Jugador1.Animacion_posicion = 0;
                if(kunay.flag_lanzado==0)
                    Jugador1.Estado=BALA_PASAMANO_2;
                else
                    Jugador1.Estado=PASAMANOS_1;

            }
            break;

        case BALA_PASAMANO_2:
            if(Jugador1.Animacion_lanzar_chunche > Delay_Ataque)
            {
                Jugador1.Estado=BALA_PASAMANO_3;
                DrawMegaSprite(307,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);

                Jugador1.Animacion_lanzar_chunche=0;
                Jugador1.Animacion_posicion = 0;
                kunay.flag_lanzado = 1;
                kunay.flag_origen = 1;
                kunay.MAP_POS_X = VideoScreen.MAP_Scroll_x;
                kunay.MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                kunay.POS_X = Jugador1.POS_X;
                kunay.POS_Y = Jugador1.POS_Y+8;
            }
            break;
        case BALA_PASAMANO_3:
            if(Jugador1.Animacion_lanzar_chunche > 10)
            {
                DrawMegaSprite(307,0,Jugador1.POS_X,Jugador1.POS_Y,2,3);
                DrawMegaSprite(297,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,2,3);
                Jugador1.Animacion_posicion = 0;
                Jugador1.Estado=PASAMANOS_1;
                Jugador1.Animacion_lanzar_chunche=0;
            }
            break;

        case BALA_REPOSO_1:
            if(Jugador1.Animacion_lanzar_chunche >Delay_Ataque)
            {
                DrawMegaSprite(15,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                if(kunay.flag_lanzado==0)
                    Jugador1.Estado=BALA_REPOSO_2;
                else
                    Jugador1.Estado=REPOSO;

            }
            break;
        case BALA_REPOSO_2:
            if(Jugador1.Animacion_lanzar_chunche > Delay_Ataque)
            {
                Jugador1.Estado=BALA_REPOSO_3;
                DrawMegaSprite(18,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                kunay.flag_lanzado = 1;
                kunay.flag_origen = 1;
                kunay.MAP_POS_X = VideoScreen.MAP_Scroll_x;
                kunay.MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                kunay.POS_X = Jugador1.POS_X;
                kunay.POS_Y = Jugador1.POS_Y+8;
            }
            break;
        case BALA_REPOSO_3:
            if(Jugador1.Animacion_lanzar_chunche > 2)
            {
                Jugador1.Estado=REPOSO;
                Jugador1.Animacion_lanzar_chunche=0;

            }

            break;



        case BALA_CORRIENDO_1:
            DrawMegaSprite(21,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if(Jugador1.Animacion_lanzar_chunche >Delay_Ataque)
            {
                DrawMegaSprite(24,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;

                if(kunay.flag_lanzado==0)
                    Jugador1.Estado=BALA_CORRIENDO_2;
                else
                {
                    Jugador1.Estado=CORRER_1;
                    DrawMegaSprite(3,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                }

            }
            break;
        case BALA_CORRIENDO_2:
            DrawMegaSprite(24,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if(Jugador1.Animacion_lanzar_chunche > Delay_Ataque)
            {
                Jugador1.Estado=BALA_CORRIENDO_3;

                DrawMegaSprite(27,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Animacion_lanzar_chunche=0;
                kunay.flag_lanzado = 1;
                kunay.flag_origen = 1;
                kunay.MAP_POS_X = VideoScreen.MAP_Scroll_x;
                kunay.MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                kunay.POS_X = Jugador1.POS_X;
                kunay.POS_Y = Jugador1.POS_Y+8;
            }
            break;
        case BALA_CORRIENDO_3:
            DrawMegaSprite(27,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if(Jugador1.Animacion_lanzar_chunche > 20)
            {

                DrawMegaSprite(3,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Jugador1.Estado=CORRER_1;
                Jugador1.Animacion_lanzar_chunche=0;
            }

            break;
        case BALA_SALTANDO_1:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                 DrawMegaSprite(105,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                 AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_Ataque=0;
                 Index_caida++;
                 if(Index_caida > 255) Index_caida = 255;

                 Jugador1.Estado=BALA_SALTANDO_2;


                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_ataque_estado=1;
                     Jugador1.Estado=REPOSO;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
            break;
        case BALA_SALTANDO_2:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                 DrawMegaSprite(108,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                 if (Jugador1.flag_cayendo==1 || Index_caida < 8)
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                 AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_Ataque=0;
                 Index_caida++;
                 if(Index_caida > 255) Index_caida = 255;

                 Jugador1.Estado=BALA_SALTANDO_3;
                kunay.flag_lanzado = 1;
                kunay.flag_origen = 1;
                kunay.MAP_POS_X = VideoScreen.MAP_Scroll_x;
                kunay.MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                kunay.POS_X = Jugador1.POS_X;
                kunay.POS_Y = Jugador1.POS_Y+8;

                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_ataque_estado=1;
                     Jugador1.Estado=REPOSO;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
            break;
        case BALA_SALTANDO_3:
            if(Jugador1.Animacion_Ataque > Delay_Ataque)
            {
                 DrawMegaSprite(108,0,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                 Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                 AjusteSaltoScrollY(MAX_MAP_y);
                 Jugador1.Animacion_Ataque=0;
                 Jugador1.Animacion_cayendo=0;
                 Index_caida++;
                 if(Index_caida > 255) Index_caida = 255;
                 DrawMegaSprite(99,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                 Jugador1.Estado=CAYENDO_1;
                 Jugador1.flag_ataque_estado=0;

                 if(Jugador1.flag_cayendo == 0)
                 {
                     Jugador1.flag_ataque_estado=0;
                     Jugador1.Estado=REPOSO;
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                 }

            }
            break;
        case MUERTE_CAIDA:
            Jugador1.ATRIBUTO =0;
            Jugador1.flag_transparente=0;
            DrawMegaSprite(108,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
            Jugador1.muerto=1;
            if (Jugador1.vidas <= 0 )
            {
                Control1.SPR_visibles=0;
                Niveles.Enemigos_inicializados=0;
                Niveles.opacidad =0;
                Jugador1.Numero_monedas =0;
                Jugador1.puntos=0;
                kunay.cantidad=0;

                //
                Niveles.Contador_eventos++;
                if (Niveles.Contador_eventos==1)
                    Niveles.contador_pausa = 0;

                if (Jugador1.continues==1)
                recuadro_expandible("    Game Over", " Presione START", "");
                if (Jugador1.continues==2)
                recuadro_expandible("  Continue x 1", " Presione START", "");
                if (Jugador1.continues==3)
                recuadro_expandible("  Continue x 2", " Presione START", "");
                if (Jugador1.continues>3)
                recuadro_expandible("  Continue  ", " Presione START", "");

                if (Niveles.Contador_eventos==3)
                    Niveles.Contador_eventos=3;

                if((read_controller&boton_start)==0)
                {

                    Control1.SPR_visibles=1;
                    Control1.X_presionado=1;
                    Niveles.contador_lamparas=0;
                    Control1.Start_presionado=1;
                    Niveles.Contador_eventos=0;
                    Niveles.contador_pausa = 0;
                    Jugador1.Estado = REPOSO;
                    Niveles.estado = Niveles.estado_continue;
                    Jugador1.continues--;
                    Jugador1.puntos=0;
                    Jugador1.vidas=3;
                    if(Jugador1.continues==0)
                    {
                        Niveles.estado=0;
                    }

                    Jugador1.muerto=0;
                    cont=0;
                    while(cont<110)
                    {
                        spr[cont++].SPR_ATTR=0;
                    }
                    for(x = 0;x < 50000;x++)
                    {
                        
                       VideoScreen.SpriteVmem[x]=0x00;
                    }
                     Jugador1.POS_X = Jugador1.POS_X_INIT;
                     Jugador1.POS_Y = Jugador1.POS_Y_INIT;
                }
                Jugador1.Animacion_general=0;
            }
            if(Jugador1.Animacion_general>25 && Jugador1.vidas > 0 && Jugador1.visible==0)
            {
                Jugador1.Animacion_general=0;
                if(Niveles.Contador_eventos==0)
                {
                    if(Niveles.opacidad < 0)
                        Niveles.Contador_eventos=1;
                    VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad--);
                }
                if(Niveles.Contador_eventos==1)
                {
                   VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
                   if(Niveles.opacidad > 7)
                    {                       
                       // Niveles.Enemigos_inicializados=0;
                        Niveles.enemigos_x_Zona=4;
                        VideoScreen.load_MAP(MAPA,Niveles.MIN_MAP_x>>3,Niveles.MIN_MAP_y>>3,MAX_MAP_x,MAX_MAP_y);
//                        INIT_LAMPARAS(lamparas_nivel1);
//                        INIT_ENEMIGOS(Enemigos_nivel1);
                        
                        Jugador1.POS_X = Jugador1.POS_X_INIT;
                        Jugador1.POS_Y = Jugador1.POS_Y_INIT;
                        
                        Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                        //kunay.cantidad = 0;
                        kunay.flag_lanzado=0;
                        kunay.flag_origen=0;
                        Jugador1.vida = 10;
                        Jugador1.muerto=0;
                        Jugador1.Estado=REPOSO;                       
                        Jugador1.contador_eventos=0;
                        Niveles.Contador_eventos=0;
                        Niveles.boss_music_load=0;
                        Niveles.boss_music_play=0;
                        cont=0;
                        while(cont<9)
                        {
                           bala_enemigo[cont].flag_lanzado=0;
                           kunay_enemigo[cont++].flag_lanzado=0;
                        }

                        cont=0;
                        while(cont<110)
                        {
                            spr[cont++].SPR_ATTR=0;
                        }
                        //Jugador1.puntos=0;
                    }
                }
            }

            break;


        case CONGELADO:

            if(Jugador1.contador_eventos == 1)
            DrawMegaSprite(388,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
            if(Jugador1.contador_eventos == 2)
            DrawMegaSprite(388,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if(Jugador1.contador_eventos == 4)
            DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
            if(Jugador1.contador_eventos > 6)
            DrawMegaSprite(388,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);

            Jugador1.flag_transparente=1;
            if(Jugador1.Animacion_Ataque>10)
            {
                Jugador1.contador_eventos++;
                Jugador1.Animacion_Ataque=0;
                if(Jugador1.flag_cayendo == 1)
                {
                    Jugador1.POS_Y = Jugador1.POS_Y + tabla_caida[Index_caida];
                    AjusteCaidaScrollY(MAX_MAP_y);
                    Index_caida++;
                }
                if (Jugador1.flag_cayendo == 0)
                {
//                     if(Index_caida>20)
//                        AjustePosY(MAX_MAP_y);
                     Index_caida=0;
                     Jugador1.flag_escalando=0;
                }

                if(Jugador1.contador_eventos < 28)
                {
                    if (Jugador1.mirror==0)
                    {
                        if (Jugador1.flag_Obstruido_De == 0)
                        Jugador1.POS_X+=1;
                        chequear_pos_DE(MAX_MAP_x);
                    }
                    else
                    {
                        if (Jugador1.flag_Obstruido_Iz == 0)
                        Jugador1.POS_X-=1;
                        chequear_pos_IZ(MIN_MAP_x);
                    }
                }
            }

            if(Jugador1.contador_eventos > 64)
            {
                Jugador1.contador_eventos=0;
                Niveles.Contador_eventos=0;
                Jugador1.vida--;
                if(Jugador1.vida <= 0)
                {
                    Jugador1.flag_transparente=0;
                    Jugador1.vidas--;
                    Jugador1.vida=0;
                    Jugador1.Estado = MUERTE_CAIDA;
                    Jugador1.muerto=1;

                }
                else
                    Jugador1.Estado = REPOSO;
                DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                //Jugador1.flag_transparente=0;
            }

            break;
    }

    // </editor-fold>
    if(Jugador1.POS_Y < 208)
        Kunay();

    if((read_controller&Abajo)==Abajo)
    {
        Jugador1.flag_agachado=0;
    }

    //
    if(Jugador1.flag_cayendo == 0)
        AjustePosY(MAX_MAP_y);
    else
    AjustarMapScrollY(MAX_MAP_y);


    if(Jugador1.flag_transparente == 1)
    { 
        if((Jugador1.tiempo_Transparente & 64) == 64)
        {
            Jugador1.ATRIBUTO = Jugador1.ATRIBUTO & SPR_invisible;
        }  
        else
        {
            Jugador1.ATRIBUTO = Jugador1.ATRIBUTO | SPR_visible;
        }       

        if(Jugador1.tiempo_Transparente > 2048)
        {
            Jugador1.tiempo_Transparente = 0;
            Jugador1.flag_transparente = 0; 
        }
        
    }
    
    

    if(Jugador1.puntos >= 10000)
    {
        Jugador1_FX.play_fambox_cod=1;  // sonido cuando se gana una vida

        Jugador1.puntos-=10000;
        Jugador1.vidas++;
    }


    if ((VideoScreen.MAP_Scroll_x) <= MIN_MAP_x)  // control de limites del nivel
        VideoScreen.MAP_Scroll_x=MIN_MAP_x;
    if (VideoScreen.MAP_Scroll_x >= ((MAX_MAP_x-28)<<3))
        VideoScreen.MAP_Scroll_x=((MAX_MAP_x-28)<<3);

    if ((VideoScreen.MAP_Scroll_y) <= MIN_MAP_y)  // control de limites del nivel
        VideoScreen.MAP_Scroll_y=MIN_MAP_y;
    if (VideoScreen.MAP_Scroll_y >= ((MAX_MAP_y-28)<<3))
        VideoScreen.MAP_Scroll_y=((MAX_MAP_y-28)<<3);

    VideoScreen.Scroll_MAP(MAPA,MAX_MAP_x,MAX_MAP_y);

    if((read_controller&boton_Y)==boton_Y)
        Control1.Y_presionado=0;
    if((read_controller&boton_X)==boton_X)
        Control1.X_presionado=0;
        

}


void copy_tiles(int tile_fuente,int tile_destino,int tamanho) // tamaño 3 = 3x3,2= 2x2, etc
{
    int index=0;
    int offset1=0;
    int offset2=0;
    int cont_max=0;
    int cont=0;
    cont_max = 64*tamanho;
    while(cont<tamanho)
    {
        offset1 = (tile_fuente+cont*16)<<6;
        offset2 = (tile_destino+cont*16)<<6;
        index=0;
         while(index < cont_max)
         {
                VideoScreen.BG_TILESRAM[offset2+index]=BG1_TILES_ANIMATED[offset1+index];
                index++;
         }
        cont++;
    }
}


void Animar_tiles(int animacion1,int animacion2,int animacion3,int animacion4)
{
    copy_tiles(11 + animacion1*2,4,2);
    copy_tiles(32 + animacion2*2,172,2);
    copy_tiles(8+ animacion3,190,1);
    copy_tiles(0+ animacion4*2,230,2);
}

void Encabezado(int vida, int kunays, int puntos)
{
    int cont,x,y;
    char buf[15];
    String STRdata;
    spr[90].SPR_ATTR = SPR_visible;
    spr[91].SPR_ATTR = SPR_visible;
    spr[90].SPR_NUM = 489;
    spr[91].SPR_NUM = 490;
    spr[90].X = 48;
    spr[91].X = 56;
    spr[90].Y = 8;
    spr[91].Y = 8;


    STRdata = String(kunays,DEC);
    STRdata.toCharArray(buf,15);
    //utoa(buf,kunays,10);
    print_txt(" ",5,1,BG_ROJO,BLANCO);
    print_txt("   ",9,1,BG_ROJO,BLANCO);
    print_txt("  ",24,1,BG_ROJO,BLANCO);
    print_txt("x",8,1,BG_ROJO,BLANCO);
    print_txt("x",23,1,BG_ROJO,BLANCO);
    print_txt("HI:      ",12,1,BG_ROJO,VERDE);
    print_txt(buf,9,1,BG_ROJO,BLANCO);
    STRdata = String(Jugador1.Numero_monedas,10);
    STRdata.toCharArray(buf,15);
    print_txt(buf,15,1,BG_ROJO,BLANCO);
    STRdata = String(Jugador1.vidas,10);
    STRdata.toCharArray(buf,15);
    print_txt(buf,24,1,BG_ROJO,BLANCO);

    for (cont=0;cont < 10;cont++)
    {
        if (cont < vida)
            spr[cont+95].SPR_ATTR = SPR_visible;
        else
            spr[cont+95].SPR_ATTR = 0;
        spr[cont+95].SPR_NUM = 499;
        spr[cont+95].Y = 8;
        spr[cont+95].X = cont*3 + 8;
    }
    cont=0;
    for(y=0;y<12;y++)
    {
       for(x=0;x<14;x++)
       {
          VideoScreen.SpriteVmem[(y+5)*224+(x+170)]=NINJA_HEAD_BMP[cont++];
       }
    }
}


void SHOW_INTRO_TXT()
{
    int cont=0;

   // print_txt(Texto_intro,1,3,BG_NEGRO,BLANCO);
    while(cont<13)
    {        
        Jugador1.Animacion_general=0;
        print_line(Texto_intro,cont+Niveles.TXT_PAG, cont+1,BG_NEGRO,BLANCO);
        cont++;
    }
    
//    print_txt("   no habia nada que se   ",1,4,BG_NEGRO,BLANCO);
//    print_txt("    se pudiera hacer;     ",1,5,BG_NEGRO,BLANCO);
//    print_txt("  el enemigo se acercaba  ",1,6,BG_NEGRO,BLANCO);
//    print_txt(" cada dia mas y amenazaba ",1,7,BG_NEGRO,BLANCO);
//    print_txt(" con destruir a todo aquel",1,8,BG_NEGRO,BLANCO);
//    print_txt(" que osase hacerle frente.",1,9,BG_NEGRO,BLANCO);
//    print_txt("El gran emperador de Japon",1,10,BG_NEGRO,BLANCO);


}



void presentacion()
{
    int delay1;
    int x;
    int cont=0;

    codigo_FAMBOX();
    AudioOut.FX_jugador1();

    if(Niveles.opacidad < 7)
            delay1 = 10;
    if((read_controller&boton_start)==0 && Control1.X_presionado==0)
    {
        
        if(Niveles.FAMBOX_cod_cont >= 8)
            Jugador1_FX.play_fambox_cod=1;
        if(Niveles.opacidad >= 7)
        delay1 = 100;
        Control1.Start_presionado=1;
        Control1.X_presionado=1;
        Niveles.Contador_eventos=0;
        Niveles.TXT_PAG=0;
        Niveles.TXT_INDEX=0;
        print_txt("Press Start",8,21,BG_NEGRO,BLANCO);      
        
    }
    else
    {
        if(Niveles.opacidad >= 7)
            delay1 = 28;
    }


    if(Jugador1.Animacion_general > 15 && Control1.X_presionado==0)
    {
        Niveles.Contador_eventos++;

        if(Niveles.Contador_eventos > delay1)
        {
            Niveles.opacidad++;
            if(Niveles.opacidad >= 7)
            {
                
                Niveles.opacidad=7;
                print_txt("Press Start",8,21,BG_NEGRO,BLANCO);
                print_txt("FAMBOX II, 2014",6,25,BG_NEGRO,BLANCO);
                //VideoScreen.MAP_1[24*32+7]=190;
            }
            else
                copy_bmp(Niveles.opacidad);
            Niveles.Contador_eventos=0;
        }
        if(Niveles.Contador_eventos>(delay1/2))
            print_txt("             ",8,21,BG_NEGRO,BLANCO);
            
        Jugador1.Animacion_general = 0;
        VideoScreen.Scroll_Y = 0;
        VideoScreen.Scroll_X++;
        VideoScreen.Scroll_X=VideoScreen.Scroll_X&0x00ff;

    }

    if(Jugador1.Animacion_general > (delay1+50) && Control1.X_presionado==1 && Jugador1_FX.play_fambox_cod==0)
    {

        Niveles.Contador_eventos++;

        if(Niveles.Contador_eventos > 8 &&Niveles.Contador_eventos<10)
        {
            SHOW_INTRO_TXT();
            Niveles.TXT_INDEX++;

            if(Niveles.TXT_INDEX==200)
            {            
                Niveles.TXT_PAG=13;
                Limpiar_sprites_mem();
            }
            if(Niveles.TXT_INDEX==400)
            {
                Niveles.TXT_PAG=26;
                Limpiar_sprites_mem();
            }    
            if(Niveles.TXT_INDEX==600)
            {
                Niveles.TXT_PAG=39;  
                Limpiar_sprites_mem();  
            }    
            if(Niveles.TXT_INDEX==800)
            {
                Niveles.TXT_PAG=52;
                Limpiar_sprites_mem();
            }    
            if(Niveles.TXT_INDEX==1000)   
            {
                Niveles.TXT_PAG=65;
                Limpiar_sprites_mem();
            }    
            if(Niveles.TXT_INDEX==1200)
                Niveles.texto_intro_cont=1;
            
            copy_bmp128(Niveles.opacidad, INTRO_bmp);
            VideoScreen.copy_BG_TILES(BG1_TILES,1);
            Niveles.opacidad++;
            if(Niveles.opacidad > 7)
                Niveles.opacidad = 7;
            
            
            if(((read_controller&boton_start)==boton_start && Control1.Start_presionado==1))
                Control1.Start_presionado=0;

            if(Niveles.texto_intro_cont==1||((read_controller&boton_start)==0 && Control1.Start_presionado==0))
            {
                Niveles.texto_intro_cont=0;
                Niveles.opacidad=0;
                Control1.Start_presionado=1;
                Niveles.Contador_eventos = 10;
                AudioOut.wr_play_song(1500,0x00);
            }
            else
                Niveles.Contador_eventos = 8;
        }


        if(Niveles.Contador_eventos==10)
        {            
            
        }
         
        if(Niveles.Contador_eventos == 7)
        {
            VideoScreen.load_MAP(INTRO,0,0,MAX_INTRO_x,MAX_INTRO_y);
            VideoScreen.Scroll_MAP(MAPA1,MAX_MAP1_x,MAX_MAP1_y);
            Limpiar_sprites_mem();
        }

        if(Niveles.Contador_eventos < 7)
        {
            VideoScreen.copy_BG_TILES(BG1_TILES,0);
            Niveles.opacidad--;
            if(Niveles.opacidad < 0) Niveles.opacidad=0;
                copy_bmp(Niveles.opacidad);
        }
        if(Niveles.Contador_eventos == 11)
        {
            Niveles.opacidad=0;
            VideoScreen.load_MAP(MAPA1,0,0,MAX_MAP1_x,MAX_MAP1_y);

            VideoScreen.Scroll_MAP(MAPA1,MAX_MAP1_x,MAX_MAP1_y);
            print_txt("           ",8,21,BG_NEGRO,BLANCO);
            print_txt("                ",6,25,BG_NEGRO,BLANCO);
            for(x = 0;x < 50000;x++)
            {
               VideoScreen.SpriteVmem[x]=0x00;
            }
        }
        if(Niveles.Contador_eventos > 18)
        {
            
            Niveles.contador_lamparas=0;
            VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {
                
                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                INIT_LAMPARAS(lamparas_nivel1);
                INIT_ENEMIGOS(Enemigos_nivel1);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;

                Jugador1.vidas= 3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=2;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                Jugador1.puntos=0;
                Jugador1.Numero_monedas=0;
                recuadro_encabezado();
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel1, track_Nivel1, Pattern_size_Nivel1,numero_de_canales_Nivel1, numero_de_patrones_Nivel1,song_size_Nivel1);
                AudioOut.wr_play_song(1500,0x01);

                if(Niveles.FAMBOX_cod_cont >= 8)
                {
                    kunay.cantidad = 99;
                    Jugador1.vidas= 99;                    
                }
                
            }

        }
        Jugador1.Animacion_general = 0;
    }


}


int Deco_enemigo(int tipo)
{
    int SPR_NUM;
    switch(tipo)
    {
        case NINJA_ESPADA:
            SPR_NUM = 6;
            break;

        case NINJA_KUNAY:
            SPR_NUM = 21;
            break;
        case NINJA_PASAMANOS:
            SPR_NUM = 210;
            break;

        case NINJA_MORADO_ESPADA:
            SPR_NUM = 96;
            break;

        case NINJA_MORADO_KUNAY:
            SPR_NUM = 105;
            break;

        case NINJA_CAFE_KUNAY:
            SPR_NUM = 204;
            break;

        case NINJA_CAFE_LODO:
            SPR_NUM = 192;
            break;

        case NINJA_GRIS_HIELO:
            SPR_NUM = 384;
            break;

        case OGRO:
            SPR_NUM = 316;
            break;

    }

    return SPR_NUM;

}

// <editor-fold defaultstate="collapsed" desc="Sprites enemigos">

void check_suelo()
{
    int cont=0,temp;
    int comparaciones=0;
    int index1_map;
    
    while(cont < 3)  /// se conpara si ya se llego a algun filo en el nivel
    {
        if ((boss.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((boss.POS_X+VideoScreen.Scroll_X+4)>>3)+cont)&0x001f) | ((((boss.POS_Y+VideoScreen.Scroll_Y+24)&0x00f8)>>3)*32);
        else
            index1_map = ((((boss.POS_X+VideoScreen.Scroll_X)>>3)+cont)&0x001f) | ((((boss.POS_Y+VideoScreen.Scroll_Y+24)&0x00f8)>>3)*32);
//        VideoScreen.MAP_1[165+cont]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }        
        cont++;
    }
    if (comparaciones > 0)
    {
        boss.flag_cayendo=0;
    }
    else
        boss.flag_cayendo=1;
    
    
    
}
void check_techo()
{

    
}
void check_de()
{
    int cont=0,temp;
    int comparaciones=0;
    int index1_map;
    while(cont < 3)
    {
        if ((boss.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((boss.POS_X+28+VideoScreen.Scroll_X)>>3))&0x001f) | (((((boss.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        else
            index1_map = ((((boss.POS_X+21+VideoScreen.Scroll_X)>>3))&0x001f) | (((((boss.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        //VideoScreen.MAP_1[72+cont*32]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        cont++;
    }
    if (comparaciones > 0)
        boss.flag_Obstruido_De=1;
    else
        boss.flag_Obstruido_De=0;
    
    
}
void check_iz()
{
    int cont=0,temp;
    int comparaciones=0;
    int index1_map;
    while(cont < 3)
    {
        if ((boss.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((boss.POS_X+26+VideoScreen.Scroll_X)>>3)-3)&0x001f) | (((((boss.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        else
            index1_map = ((((boss.POS_X+19+VideoScreen.Scroll_X)>>3)-3)&0x001f) | (((((boss.POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);

        //VideoScreen.MAP_1[68+cont*32]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        cont++;
    }
    if (comparaciones > 0)
        boss.flag_Obstruido_Iz=1;
    else
        boss.flag_Obstruido_Iz=0;

    
}
void mov_x(int limite_de,int limite_iz)
{
    if(boss.AnimacionPosicion>boss.POS_X_CONT && boss.flag_corriendo==1 && (boss.estado != REPOSO || boss.Enemigo_tipo == BOSS4))
    {
       
        boss.AnimacionPosicion=0;
       if(boss.POS_X >= limite_de && boss.ir_derecha == 1)
       {
           boss.ir_izquierda = 1;
           boss.ir_derecha =0;

       }else
       if(boss.POS_X <= limite_iz &&boss.ir_izquierda ==1)
       {
           boss.ir_izquierda = 0;
           boss.ir_derecha = 1;
       }
        if(boss.ir_derecha == 1)
            boss.POS_X++;
        if(boss.ir_izquierda == 1)
            boss.POS_X--;
    }    
}

void golpe()
{
     // jugador 1 golpea enemigo
        if((boss.POS_Y)>(Jugador1.POS_Y-8)&&boss.POS_Y<(Jugador1.POS_Y+24)&&boss.vida>0)
        {
            if(Jugador1.flag_ataque_estado>0&&boss.flag_golpeado==0)
            {
                if(((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(boss.POS_X)>(Jugador1.POS_X-28)&&boss.POS_X<(Jugador1.POS_X+10))||
                        ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0 &&(boss.POS_X)>(Jugador1.POS_X+10)&&boss.POS_X<(Jugador1.POS_X+30)))
                {

                    boss.estado_anterior=boss.estado;// se guarda el ultimo estado
                    boss.flag_golpeado=1;
                    boss.estado=GOLPE_MUERTE_1;
                    DrawMegaSprite(288,(boss.ATRIBUTO&0xfffc)|0b00000001,boss.POS_X,boss.POS_Y,3,3);
                    boss.Animacion_General=0;
                    boss.flag_ataque_estado=0;
                    boss.vida--;
                    if(boss.vida<=0)
                    {
                        boss.estado=GOLPE_MUERTE_2;
                        boss_FX.play_muriendo = 0;

                    }

                }

            }
        }

        if((boss.POS_Y+23)>(kunay.POS_Y+4)&&boss.POS_Y<(kunay.POS_Y+4)&&boss.flag_golpeado==0&&((boss.Enemigo_tipo==BOSS4&&boss.estado==REPOSO)||boss.Enemigo_tipo!=BOSS4))
        {
            if(kunay.flag_lanzado==1&&kunay.flag_origen==0&&boss.vida>0)
            {
                if(((kunay.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(boss.POS_X+20)>(kunay.POS_X)&&(boss.POS_X+20)<(kunay.POS_X+16))||
                        ((kunay.ATRIBUTO&SPR_Mirror_H)==0 &&(boss.POS_X+8)>(kunay.POS_X)&&(boss.POS_X+8)<(kunay.POS_X+16)))
                {
                    boss.estado_anterior=boss.estado;// se guarda el ultimo estado
                    boss.flag_golpeado=0;
                    boss.estado=GOLPE_MUERTE_1;
                    DrawMegaSprite(288,(boss.ATRIBUTO&0xfffc)|0b00000001,boss.POS_X,boss.POS_Y,3,3);
                    boss.Animacion_General=0;
                    kunay.flag_lanzado=0;
                    kunay.flag_origen=0;
                    spr[80].SPR_ATTR = 0;
                    spr[81].SPR_ATTR = 0;
                    boss.vida--;
                    if(boss.vida<=0)
                    {
                        boss.estado=GOLPE_MUERTE_2;
                        
                    }
                    boss.flag_ataque_estado=0;
                }
            }
        }


}

void check_mirror(unsigned int ATTR_TEMP)
{
    if ((Jugador1.POS_X+24) < boss.POS_X)
        {
            //Jugador1.mirror=1; // por donde se le da el golpe al jugador
            boss.ir_derecha =0;
            boss.ir_izquierda=1;
        }
        if ((Jugador1.POS_X-24) > boss.POS_X)
        {
            //Jugador1.mirror=0; // por donde se da el golpe al jugador
            boss.ir_derecha =1;
            boss.ir_izquierda=0;
        }

    if (boss.ir_derecha == 1)
        boss.ATRIBUTO=ATTR_TEMP;
    if (boss.ir_izquierda == 1)
        boss.ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;
}


void bloque_cayendo(int SPR_NUM,int bloque_num,int banco)
{
    int ATTR_TEMP;
    ATTR_TEMP =((0x18+(bloque_num*6))<<8);
    int delay1;


    if(banco==1)
        delay1 = 20;
    else
        delay1 = 7;

    if (bala_boss[bloque_num+2].flag_origen == 1)
    {
        bala_boss[bloque_num+2].flag_origen = 0;
        if(banco==1)
            bala_boss[bloque_num+2].ATRIBUTO = SPR_visible|SPR_Banco1|ATTR_TEMP;
        else
            bala_boss[bloque_num+2].ATRIBUTO = SPR_visible|SPR_Banco2|ATTR_TEMP;

        DrawMegaSprite(SPR_NUM, bala_boss[bloque_num+2].ATRIBUTO,bala_boss[bloque_num+2].POS_X,bala_boss[bloque_num+2].POS_Y,3,2);
        bala_boss[bloque_num+2].SPR_POS_Y=0;

    }

    if(bala_boss[bloque_num+2].Animacion_POS > delay1 && bala_boss[bloque_num+2].flag_lanzado==1)
    {
        bala_boss[bloque_num+2].Animacion_POS=0;
        DrawMegaSprite(SPR_NUM, bala_boss[bloque_num+2].ATRIBUTO,bala_boss[bloque_num+2].POS_X,bala_boss[bloque_num+2].POS_Y,2,3);
        bala_boss[bloque_num+2].POS_Y+=tabla_caida[bala_boss[bloque_num+2].SPR_POS_Y++];
        if(bala_boss[bloque_num+2].SPR_POS_Y>64)bala_boss[bloque_num+2].SPR_POS_Y=64;

        if(bala_boss[bloque_num+2].POS_Y > 170)
        {
           DrawMegaSprite(SPR_NUM,SPR_Banco1|ATTR_TEMP,bala_boss[bloque_num+2].POS_X,bala_boss[bloque_num+2].POS_Y,2,3);
           bala_boss[bloque_num+2].flag_lanzado=0;
        }
    }



}

void JugadorGolpe(int ATTR)
{
    if (Jugador1.flag_transparente == 0)
    {
        Index_caida=0;
        Jugador1.Estado = GOLPE_MUERTE_2;   // inicio de la maquina de estado para el ataque
        if ((ATTR&SPR_Mirror_H)==SPR_Mirror_H) // se determina la direcion a la que se mueve el jugador despues del golpe
            Jugador1.mirror=1;
        else
            Jugador1.mirror=0;
    } 
    

}


void boss_muerto()
{
   if(boss.Animacion_General<10)
        AudioOut.wr_play_fx(tabladefrecuencias[C_2],0x01,30,0x05,0x01);

    if(boss.Animacion_General>40&&boss.Animacion_General<=80)
    {
        boss.muerto=1;
        DrawMegaSprite(288,(boss.ATRIBUTO&0xfffc)|0b00000001,boss.POS_X,boss.POS_Y,3,3);
    }
    if(boss.Animacion_General>80&&boss.Animacion_General<=120)
    {
        DrawMegaSprite(292,(boss.ATRIBUTO&0xfffc)|0b00000001,boss.POS_X,boss.POS_Y,3,3);
    }
    if(boss.Animacion_General>120&&boss.Animacion_General<=160)
    {
        DrawMegaSprite(295,(boss.ATRIBUTO&0xfffc)|0b00000001,boss.POS_X,boss.POS_Y,3,3);
    }
    if(boss.Animacion_General>500)
    {

        DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,3,3);
        AudioOut.WR_AUDIO_DATA(Pattern_final, track_final, Pattern_size_final,numero_de_canales_final, numero_de_patrones_final,song_size_final);
        AudioOut.wr_play_song(1000,0x01);
        boss.muerto=1;
        boss.estado = MUERTE_CAIDA;
       
        boss.Animacion_General=0;
        Niveles.opacidad=7;
    }

}

void boss_nivel1()   // Jefe nivel 1
{
    char En_Rango;
    int cont;
    unsigned int ATTR_TEMP;
    int boss_ramdom;
    char buf[10];
    boss.Enemigo_tipo=BOSS1;
    RAMDOM();
    boss_ramdom = RAMDOM_INT;
    

    if (boss.POS_X > 0 && boss.POS_X <= 224)
        En_Rango=1;
    else
        En_Rango=0;


    if (En_Rango==1&&boss.muerto==0)
       ATTR_TEMP=SPR_Banco2|SPR_visible|((0x0c)<<8);
    else
       ATTR_TEMP=SPR_Banco2|((0x0c)<<8);

    if (boss.ir_derecha == 1)
        boss.ATRIBUTO=ATTR_TEMP;
    if (boss.ir_izquierda == 1)
        boss.ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;

    check_suelo();
    check_de();
    check_iz();
    mov_x(192,10);
    golpe(); //jugador golpea el jefe

///////***************enemigo golpea jugador 1*******************************/
    if(boss.flag_ataque_estado==0 && boss.flag_saltando == 0)
    {
        if((boss.POS_X)>(Jugador1.POS_X-40)&&boss.POS_X<(Jugador1.POS_X+50))// comparamos si estamos cerca del jugador 1
               boss.flag_ataque_estado=2;   // inicio de la maquina de estado para el ataque
        if((boss.POS_X + 32)>(Jugador1.POS_X-40)&&(boss.POS_X+32)<(Jugador1.POS_X+50))// comparamos si estamos cerca del jugador 1
               boss.flag_ataque_estado=2;   // inicio de la maquina de estado para el ataque
    }

    if(boss.estado != REPOSO && ((boss.flag_saltando==1&&boss.Index_caida > 24) || boss.flag_ataque_estado==2) && boss.vida > 0 &&((boss.POS_Y<(Jugador1.POS_Y+1)&&(boss.POS_Y+24)>(Jugador1.POS_Y+1))||(boss.POS_Y<(Jugador1.POS_Y+23)&&(boss.POS_Y+24)>(Jugador1.POS_Y+23))))
    {
        if(((boss.POS_X)>(Jugador1.POS_X)&&boss.POS_X<(Jugador1.POS_X+20))||((boss.POS_X+16)>(Jugador1.POS_X)&&(boss.POS_X+16)<(Jugador1.POS_X+20)))
        {

            JugadorGolpe(boss.ATRIBUTO);
        }
    }

    if((boss.POS_Y+10) > Jugador1.POS_Y+24 && boss.flag_saltando==0)
    {
        boss.flag_saltando=1;
    }


    if (En_Rango == 1 && Jugador1.POS_X < boss.POS_X && boss.flag_saltando==0)
    {
        //Jugador1.mirror=1; // por donde se le da el golpe al jugador
        boss.ir_derecha =0;
        boss.ir_izquierda=1;
    }
    if (En_Rango == 1 && Jugador1.POS_X > boss.POS_X && boss.flag_saltando==0)
    {
        //Jugador1.mirror=0; // por donde se da el golpe al jugador
        boss.ir_derecha =1;
        boss.ir_izquierda=0;
    }
    cont=0;
    while(cont<2)
    {
        if(boss.vida>0&&bala_boss[cont].flag_lanzado==1)
        {
            if((Jugador1.POS_Y+23)>(bala_boss[cont].POS_Y+4)&&Jugador1.POS_Y<(bala_boss[cont].POS_Y+4))
            {
                if(((bala_boss[cont].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X+20)<(bala_boss[cont].POS_X+16))
                        ||((bala_boss[cont].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X+8)<(bala_boss[cont].POS_X+16)))
                {
                    JugadorGolpe(boss.ATRIBUTO);
                }
            }
        }
        cont++;
    }


/************************************************************/

    if(bala_boss[0].animacion_cont > 0 && bala_boss[0].animacion_cont <= 25)
    {
        Bala_boss(484,0);
        Bala_boss(484,1);
    }
    if(bala_boss[0].animacion_cont > 25&& bala_boss[0].animacion_cont <= 50)
    {
        Bala_boss(485,0);
        Bala_boss(485,1);
    }
    if(bala_boss[0].animacion_cont > 50 && bala_boss[0].animacion_cont <= 75)
    {
        Bala_boss(486,0);
        Bala_boss(486,1);
    }

    bala_boss[0].animacion_cont++;
    bala_boss[1].animacion_cont++;
    if(bala_boss[0].animacion_cont > 75)
    {
        bala_boss[0].animacion_cont = 0;
    }
    if(bala_boss[1].animacion_cont > 1000)
    {
        bala_boss[1].animacion_cont = 0;
    }

//    if (boss.flag_corriendo == 1 && boss.flag_saltando==0 && boss.flag_cayendo == 1 && Niveles.estado>19 && boss.Index_caida < 32)
//    {
//        boss.flag_saltando=1;
//        boss.estado = BALA_SALTANDO_1;
//        boss.Index_caida=32;
//    }

    switch(boss.estado)
    {
        case REPOSO:
            DrawMegaSprite(0,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
            if(boss.Animacion_General>2000)
            {
                boss.POS_X_CONT=20;
                boss.estado = CORRER_1;
                boss.Animacion_General=0;
                boss.flag_corriendo=1;
            }
            break;

        case CORRER_1:
            if(boss.Animacion_General>30)
            {
                boss.flag_corriendo=1;
                DrawMegaSprite(3,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = CORRER_2;
                boss.estado_anterior=CORRER_2;
            }
            break;
        case CORRER_2:                        
            if(boss.Animacion_General>30)
            {
                DrawMegaSprite(6,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                if(boss.estado_anterior==CORRER_3)
                    boss.estado = CORRER_1;
                if(boss.estado_anterior==CORRER_2)
                    boss.estado = CORRER_3;
            }
            break;
        case CORRER_3:
            if(boss.Animacion_General>30)
            {

                DrawMegaSprite(9,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = CORRER_2;
                boss.estado_anterior=CORRER_3;
                if(boss_ramdom > 2000 && boss_ramdom < 105000 &&((boss.POS_Y<(Jugador1.POS_Y+1)&&(boss.POS_Y+24)>(Jugador1.POS_Y+1))||(boss.POS_Y<(Jugador1.POS_Y+23)&&(boss.POS_Y+24)>(Jugador1.POS_Y+23))))
                    boss.flag_ataque_estado=1;
            }

            if(boss.flag_ataque_estado==1)
            {
                boss.estado = ATAQUE_DETENIDO_1;
                boss.Animacion_General=0;
            }else
                if(boss.flag_saltando==1)
                {
                    boss.POS_X_CONT=20;
                    boss.Index_caida=0;
                    boss.estado = BALA_SALTANDO_1;
                    boss.Animacion_General=0;
                    DrawMegaSprite(18,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                }

            if(boss.flag_ataque_estado==2 )
            {
                boss.POS_X_CONT=7;
                boss.estado = ATAQUE_CORRIENDO_1;
                boss.Animacion_General=0;
                 DrawMegaSprite(18,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
            }
            if (boss.flag_cayendo==1 )
            {
                boss.POS_X_CONT=15;
                boss.Index_caida=0;
                boss.estado = BALA_SALTANDO_1;
                boss.Animacion_General=0;
                DrawMegaSprite(18,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
            }
            break;

        case ATAQUE_CORRIENDO_1:
            if(boss.Animacion_General>80)
            {
                DrawMegaSprite(21,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = ATAQUE_CORRIENDO_2;
            }
            break;
        case ATAQUE_CORRIENDO_2:
            if(boss.Animacion_General>80)
            {
                DrawMegaSprite(24,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = ATAQUE_CORRIENDO_3;
            }
            break;
        case ATAQUE_CORRIENDO_3:
            if(boss.Animacion_General>80)
            {
                DrawMegaSprite(27,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
            }
            if(boss.Animacion_General>150)
            {
                boss.Animacion_General=0;
                boss.estado = REPOSO;
                boss.flag_ataque_estado=0;
                boss.flag_corriendo=0;
            }  
            break;

        case ATAQUE_DETENIDO_1:
            if(bala_boss[1].flag_lanzado == 0 && boss.POS_Y > (Jugador1.POS_Y+2)&&boss.POS_Y < (Jugador1.POS_Y+20))
            {
                if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                {
                    boss.flag_lanzando_chunche=1;
                    bala_boss[1].flag_lanzado = 1;
                    bala_boss[1].flag_origen = 1;
                    bala_boss[1].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                    bala_boss[1].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                    bala_boss[1].POS_X = boss.POS_X;
                    bala_boss[1].POS_Y = boss.POS_Y+8;
                }
            }
            if(boss.Animacion_General>100)
            {
                 boss.estado = REPOSO;
                 boss.Animacion_General=0;
                 boss.flag_ataque_estado=0;
            }
            break;
        
        case BALA_SALTANDO_1:
            if(boss.Animacion_General>Delay_Salto)
            {
                if(bala_boss[0].flag_lanzado == 0 && boss.POS_Y > (Jugador1.POS_Y)&&boss.POS_Y < (Jugador1.POS_Y+24))
                {
                    if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                    {
                        boss.flag_lanzando_chunche=1;
                        bala_boss[0].flag_lanzado = 1;
                        bala_boss[0].flag_origen = 1;
                        bala_boss[0].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        bala_boss[0].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        bala_boss[0].POS_X = boss.POS_X;
                        bala_boss[0].POS_Y = boss.POS_Y+8;
                    }
                }
                if(boss.contador_eventos2==0)
                {
                    if(boss.flag_lanzando_chunche == 1)
                        boss.contador_eventos2=1;
                    DrawMegaSprite(12,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                }
                if(boss.flag_lanzando_chunche == 1)
                {
                    if(boss.contador_eventos2==1)
                    {
                        boss.contador_eventos2=2;
                        DrawMegaSprite(15,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                    }else
                    if(boss.contador_eventos2==2)
                    {
                        boss.contador_eventos2=3;
                        DrawMegaSprite(15,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                    }
                }
                if(boss.contador_eventos2==3)
                {
                    boss.contador_eventos2=0;
                    boss.flag_lanzando_chunche=0;
                }
                if (boss.flag_cayendo==1 || boss.Index_caida < 8)
                    boss.POS_Y = boss.POS_Y + tabla_salto[boss.Index_caida++];


                if(boss.Index_caida > POS_Y_MAX) boss.Index_caida = POS_Y_MAX;

                if (boss.flag_cayendo==0 && boss.Index_caida > 10)
                {
                    boss.contador_eventos2=0;
                    boss.flag_saltando=0;
                    boss.flag_ataque_estado=0;
                    boss.estado=REPOSO;
                    boss.POS_Y=boss.POS_Y&0xfffffff8; /// correcion de la posicion en Y                    
                }
                boss.Animacion_General=0;
            }
            break;

        case GOLPE_MUERTE_1:
            if(boss.Animacion_General>10)
            {
                boss.estado = CORRER_1;
                boss.Animacion_General=0;
            }
            break;
        case GOLPE_MUERTE_2:
            boss_muerto();
            break;


        case MUERTE_CAIDA:
//muerto no
            if(boss.Animacion_General>3000)
            {                
                boss.Animacion_General=2980;
                AudioOut.wr_play_song(2000,0x00);
                VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad--);
                if(Niveles.opacidad<=0)
                {
                    Limpiar_sprites_mem();
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;
                    Niveles.estado=4;
                    Niveles.opacidad=0;
                    VideoScreen.load_MAP(MAPA2,0,0,MAX_MAP2_x,MAX_MAP2_y);
                    VideoScreen.Scroll_MAP(MAPA2,MAX_MAP2_x,MAX_MAP2_y);
                }
                DrawMegaSprite(6,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Niveles.estado_continue=4;
            }
            DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,3,3);
            break;
    }
    AudioOut.FX_enemigo(15);
    if(Jugador1.flag_ataque_estado==0&&boss.flag_golpeado==1)
        boss.flag_golpeado=0;

}

void boss_nivel2()   // Jefe nivel 2
{
    char En_Rango;
    int cont;
    unsigned int ATTR_TEMP;
    int boss_ramdom;
    char buf[10];
boss.Enemigo_tipo=BOSS2;
    RAMDOM();
    boss_ramdom = RAMDOM_INT&0x000ffff;


    if (boss.POS_X > 0 && boss.POS_X <= 224)
        En_Rango=1;
    else
        En_Rango=0;


    if (En_Rango==1&&boss.muerto==0)
       ATTR_TEMP=SPR_Banco2|SPR_visible|((0x0c)<<8);
    else
       ATTR_TEMP=SPR_Banco2|((0x0c)<<8);

    if (boss.ir_derecha == 1)
        boss.ATRIBUTO=ATTR_TEMP;
    if (boss.ir_izquierda == 1)
        boss.ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;

    check_suelo();
    check_de();
    check_iz();
    mov_x(192,24);
    golpe(); //jugador golpea el jefe

    if(boss.estado != REPOSO && ((boss.flag_saltando==1 && boss.Index_caida > 32) || boss.flag_ataque_estado==2) && boss.vida > 0 &&((boss.POS_Y<(Jugador1.POS_Y+1)&&(boss.POS_Y+24)>(Jugador1.POS_Y+1))||(boss.POS_Y<(Jugador1.POS_Y+23)&&(boss.POS_Y+24)>(Jugador1.POS_Y+23))))
    {
        if(((boss.POS_X)>(Jugador1.POS_X)&&boss.POS_X<(Jugador1.POS_X+24))||((boss.POS_X+16)>(Jugador1.POS_X)&&(boss.POS_X+16)<(Jugador1.POS_X+24)))
        {
            JugadorGolpe(boss.ATRIBUTO);
        }
    }

    if((boss.POS_X > (Jugador1.POS_X-32) && boss.POS_X < (Jugador1.POS_X+32)) && boss.flag_saltando==0 && Jugador1.POS_X > 24)
    {
        boss.flag_saltando=1;
    }

cont=0;
    while(cont<2)
    {
        if(boss.vida>0&&bala_boss[cont].flag_lanzado==1)
        {
            if((Jugador1.POS_Y+23)>(bala_boss[cont].POS_Y+8)&&Jugador1.POS_Y<(bala_boss[cont].POS_Y+8))
            {
                if(((bala_boss[cont].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X+20)<(bala_boss[cont].POS_X+16))
                        ||((bala_boss[cont].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X+8)<(bala_boss[cont].POS_X+16)))
                {
                   JugadorGolpe(boss.ATRIBUTO);
                }
            }
        }
        cont++;
    }



    if (En_Rango == 1 && (Jugador1.POS_X+24) < boss.POS_X  && Jugador1.POS_X > 24 )
    {
        //Jugador1.mirror=1; // por donde se le da el golpe al jugador
        if (boss.flag_saltando == 0)
        {
            boss.ir_derecha =0;
            boss.ir_izquierda=1;
        }
        
      
    }
    if (En_Rango == 1 && (Jugador1.POS_X-24) > boss.POS_X )
    {
        //Jugador1.mirror=0; // por donde se da el golpe al jugador
        if(boss.flag_saltando == 0)
        {
            boss.ir_derecha =1;
            boss.ir_izquierda=0;
        }
    }

    if(bala_boss[0].animacion_cont > 0 && bala_boss[0].animacion_cont <= 50)
    {
        Bala_Disco_boss(472,0);
        Bala_Disco_boss(472,1);
    }
    if(bala_boss[0].animacion_cont > 50&& bala_boss[0].animacion_cont <= 100)
    {
        Bala_Disco_boss(474,0);
        Bala_Disco_boss(474,1);
    }
    if(bala_boss[0].animacion_cont > 100 && bala_boss[0].animacion_cont <= 150)
    {
        Bala_Disco_boss(476,0);
        Bala_Disco_boss(476,1);
    }
    if(bala_boss[0].animacion_cont > 150 && bala_boss[0].animacion_cont <= 200)
    {
        Bala_Disco_boss(478,0);
        Bala_Disco_boss(478,1);
        bala_boss[0].animacion_cont=0;
    }

    if(bala_boss[0].animacion_cont > 200)
        bala_boss[0].animacion_cont=0;

    bala_boss[0].animacion_cont++;

    if((Jugador1.POS_X+64) < boss.POS_X && boss.flag_ataque_estado==0 && bala_boss[1].flag_lanzado==0)
        boss.flag_ataque_estado=1;

    if((Jugador1.POS_X-64) > boss.POS_X && boss.flag_ataque_estado==0 && bala_boss[1].flag_lanzado==0)
        boss.flag_ataque_estado=1;
  


    switch(boss.estado)
    {
        case REPOSO:
            DrawMegaSprite(96,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
            if(boss.Animacion_General>1000)
            {
                boss.POS_X_CONT=20;
                boss.estado = CORRER_1;
                boss.Animacion_General=0;
                boss.flag_corriendo=1;
            }

            break;

         case CORRER_1:

            if(boss.Animacion_General>30)
            {
                boss.flag_corriendo=1;
                DrawMegaSprite(111,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = CORRER_2;
                boss.estado_anterior=CORRER_2;
            }
            break;
        case CORRER_2:
            if(boss.Animacion_General>30)
            {
                DrawMegaSprite(114,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                if(boss.estado_anterior==CORRER_3)
                    boss.estado = CORRER_1;
                if(boss.estado_anterior==CORRER_2)
                    boss.estado = CORRER_3;
            }
            break;
        case CORRER_3:
            if(boss.Animacion_General>30)
            {

                DrawMegaSprite(117,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = CORRER_2;
                boss.estado_anterior=CORRER_3;
                
            }

            if(boss.flag_ataque_estado==1)
            {
                boss.estado = ATAQUE_DETENIDO_1;
                boss.Animacion_General=0;
            }else
            if(boss.flag_saltando == 1)
            {
                boss.contador_eventos=0;
                if(boss.vida>10)
                    boss.POS_X_CONT=16;
                else
                    boss.POS_X_CONT=7;
                boss.Index_caida=0;
                boss.estado = BALA_SALTANDO_1;
                boss.Animacion_General=0;
                DrawMegaSprite(123,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);

            }

            break;


        case ATAQUE_DETENIDO_1:
            if(bala_boss[0].flag_lanzado == 0 && boss.POS_Y > (Jugador1.POS_Y-8)&&boss.POS_Y < (Jugador1.POS_Y+32))
            {
                if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                {
                    boss.flag_lanzando_chunche=1;
                    bala_boss[0].flag_lanzado = 1;
                    bala_boss[0].flag_origen = 1;
                    bala_boss[0].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                    bala_boss[0].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                    bala_boss[0].POS_X = boss.POS_X;
                    bala_boss[0].POS_Y = boss.POS_Y;
                }
            }
            if(boss.Animacion_General>100)
            {
                 boss.estado = REPOSO;
                 boss.Animacion_General=200;
                 boss.flag_ataque_estado=0;
            }

            break;


         case BALA_SALTANDO_1:
            if(boss.Animacion_General>Delay_Salto)
            {

                if(boss.contador_eventos==1)

                    DrawMegaSprite(120,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);

                else
                    DrawMegaSprite(123,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);


                if (boss.flag_cayendo==1 || boss.Index_caida < 8)
                    boss.POS_Y = boss.POS_Y + tabla_salto[boss.Index_caida++];


                if(boss.Index_caida > POS_Y_MAX) boss.Index_caida = POS_Y_MAX;

                if(boss.Index_caida > POS_Y_MAX/2) boss.contador_eventos=1;


                if (boss.flag_cayendo==0 && boss.Index_caida > 10)
                {
                    boss.contador_eventos=0;
                    boss.contador_eventos2=0;
                    boss.flag_saltando=0;
                    boss.flag_ataque_estado=0;
                    boss.estado=REPOSO;
                    boss.POS_Y=boss.POS_Y&0xfffffff8; /// correcion de la posicion en Y

                }
                boss.Animacion_General=0;
            }
            break;

        case GOLPE_MUERTE_1:
            if(boss.Animacion_General>10)
            {
                boss.estado = CORRER_1;
                boss.Animacion_General=0;
            }
            break;
        case GOLPE_MUERTE_2:
            boss_muerto();
            break;


        case MUERTE_CAIDA:
//muerto no
            if(boss.Animacion_General>3000)
            {
                
                boss.Animacion_General=2980;
                AudioOut.wr_play_song(2000,0x00);
                VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad--);
                if(Niveles.opacidad<=0)
                {
                    Limpiar_sprites_mem();
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;
                    Niveles.estado=11;
                    Niveles.opacidad=0;
                    VideoScreen.load_MAP(MAPA5,0,0,MAX_MAP5_x,MAX_MAP5_y);
                    VideoScreen.Scroll_MAP(MAPA5,MAX_MAP5_x,MAX_MAP5_y);
                }
                DrawMegaSprite(6,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Niveles.estado_continue=11;
            }
            DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,3,3);
            break;


    }

    AudioOut.FX_enemigo(15);

    if(Jugador1.flag_ataque_estado==0&&boss.flag_golpeado==1)
        boss.flag_golpeado=0;

}

void boss_nivel3()   // Jefe nivel 3
{
    char En_Rango;
    int cont;
    unsigned int ATTR_TEMP;
    int boss_ramdom;
    char buf[10];
    boss.Enemigo_tipo=BOSS3;
    RAMDOM();
    boss_ramdom = RAMDOM_INT&0x000ffff;


    if (boss.POS_X > 0 && boss.POS_X <= 224)
        En_Rango=1;
    else
        En_Rango=0;


    if (En_Rango==1 && boss.muerto==0)
       ATTR_TEMP=SPR_Banco2|SPR_visible|((0x0c)<<8);
    else
       ATTR_TEMP=SPR_Banco2|((0x0c)<<8);

    if (boss.ir_derecha == 1)
        boss.ATRIBUTO=ATTR_TEMP;
    if (boss.ir_izquierda == 1)
        boss.ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;

    check_suelo();
    check_de();
    check_iz();

    if(boss.estado!=DESTRUIR)
        mov_x(194,4);
    golpe(); //jugador golpea el jefe


    if( Jugador1.flag_transparente==0 && ((boss.flag_saltando==1 && boss.Index_caida > 32) || boss.estado == REPOSO) && boss.vida > 0 &&((boss.POS_Y<(Jugador1.POS_Y+1)&&(boss.POS_Y+24)>(Jugador1.POS_Y+1))||(boss.POS_Y<(Jugador1.POS_Y+23)&&(boss.POS_Y+24)>(Jugador1.POS_Y+23))))
    {
        if(((boss.POS_X)>(Jugador1.POS_X)&&boss.POS_X<(Jugador1.POS_X+24))||((boss.POS_X+16)>(Jugador1.POS_X)&&(boss.POS_X+16)<(Jugador1.POS_X+24)))
        {
            JugadorGolpe(boss.ATRIBUTO);
        }
    }


    if(boss.vida>0&&bala_boss[0].flag_lanzado==1)
    {
        if((Jugador1.POS_Y+23)>(bala_boss[0].POS_Y+8)&&Jugador1.POS_Y<(bala_boss[0].POS_Y+8))
        {
            if(((bala_boss[0].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_boss[0].POS_X)&&(Jugador1.POS_X+20)<(bala_boss[0].POS_X+16))
                    ||((bala_boss[0].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_boss[0].POS_X)&&(Jugador1.POS_X+8)<(bala_boss[0].POS_X+16)))
            {
                JugadorGolpe(boss.ATRIBUTO);
            }
        }
    }
    
    if(boss.vida>0&&bala_boss[1].flag_lanzado==1 && Jugador1.flag_transparente == 0)
    {
        if((Jugador1.POS_Y+23)>(bala_boss[1].POS_Y+8)&&Jugador1.POS_Y<(bala_boss[1].POS_Y+8))
        {
            if(((bala_boss[1].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_boss[1].POS_X)&&(Jugador1.POS_X+20)<(bala_boss[1].POS_X+16))
                    ||((bala_boss[1].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_boss[1].POS_X)&&(Jugador1.POS_X+8)<(bala_boss[1].POS_X+16)))
            {
                JugadorGolpe(boss.ATRIBUTO);
                Jugador1.Estado=CONGELADO;   // inicio de la maquina de estado para el ataque               
            }
        }
    }
     

    Bala_boss(491,0);
    Bala_boss(491,1);
    bloque_cayendo(30,0,1);
    bloque_cayendo(30,1,1);
    bloque_cayendo(30,2,1);
    bloque_cayendo(30,3,1);



    cont=2;
    while(cont<6)
    {
        if(boss.vida>0&&bala_boss[cont].flag_lanzado==1)
        {
            if(((Jugador1.POS_Y)>(bala_boss[cont].POS_Y)&&Jugador1.POS_Y<(bala_boss[cont].POS_Y+24))||
                ((Jugador1.POS_Y+23)>(bala_boss[cont].POS_Y)&&(Jugador1.POS_Y+23)<(bala_boss[cont].POS_Y+24)))
            {
                if(((Jugador1.POS_X)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X)<(bala_boss[cont].POS_X+16))||
                        ((Jugador1.POS_X+24)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X+24)<(bala_boss[cont].POS_X+16)))
                {
                    JugadorGolpe(boss.ATRIBUTO);
                }
            }
        }
        cont++;
    }

    if((Jugador1.POS_X+80) < boss.POS_X && boss.flag_ataque_estado==0 && bala_boss[1].flag_lanzado==0 && boss.ir_izquierda==1)
        boss.flag_ataque_estado=1;

    if((Jugador1.POS_X-80) > boss.POS_X && boss.flag_ataque_estado==0 && bala_boss[1].flag_lanzado==0 && boss.ir_derecha==1)
        boss.flag_ataque_estado=1;

   
        
    switch(boss.estado)
    {
        case DESTRUIR:
            if(boss.Animacion_General>80)
            {
                check_mirror(ATTR_TEMP);
                boss.Animacion_General=0;

                if(boss.contador_eventos == 0 && bala_boss[1].flag_lanzado==0)
                {
                    boss.flag_lanzando_chunche=0;
                   DrawMegaSprite(210,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos =1;
                }else
                if(boss.contador_eventos == 1)
                {
                   DrawMegaSprite(213,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos =2;
                }else
                if(boss.contador_eventos == 2)
                {
                   DrawMegaSprite(216,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos = 3;
                }else
                if(boss.contador_eventos == 3)
                {
                   DrawMegaSprite(219,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos = 4;
                }else
                if(boss.contador_eventos == 4)
                {
                   boss.contador_eventos2++;
                   DrawMegaSprite(219,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos =5;
                   if(bala_boss[1].flag_lanzado == 0)
                    {
                        if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                        {
                            boss.flag_lanzando_chunche=1;
                            bala_boss[1].flag_lanzado = 1;
                            bala_boss[1].flag_origen = 1;
                            bala_boss[1].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                            bala_boss[1].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                            bala_boss[1].POS_X = boss.POS_X;
                            bala_boss[1].POS_Y = boss.POS_Y+8;
                        }
                    }

                }else
                    if(boss.contador_eventos == 5)
                    {
                       DrawMegaSprite(219,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                         boss.contador_eventos =0;
                    }

                if(boss.contador_eventos2 > 3)
                {
                    boss.estado=REPOSO;
                    boss.flag_desatorar = 0;
                    DrawMegaSprite(468-(boss.SPRITE_NUM<<1),SPR_Banco1|(0x3c00),0,160,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM1<<1),SPR_Banco1|(0x4000),0,168,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM2<<1),SPR_Banco1|(0x4400),16,160,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM3<<1),SPR_Banco1|(0x4800),16,168,2,2);
                    cont=0;
                    while(cont<4)
                    {
                        VideoScreen.MAP_1[20*32+cont]=158;
                        VideoScreen.MAP_1[21*32+cont]=158;
                        VideoScreen.MAP_1[22*32+cont]=158;
                        VideoScreen.MAP_1[23*32+cont]=158;
                        cont++;
                    }
                }


                boss.SPRITE_NUM--;
                boss.SPRITE_NUM1--;
                boss.SPRITE_NUM2--;
                boss.SPRITE_NUM3--;
                if(boss.SPRITE_NUM<0)
                {
                    boss.SPRITE_NUM=3;
                    if(bala_boss[1].POS_X < 32 && boss.flag_desatorar == 1)
                        AudioOut.wr_play_fx(tabladefrecuencias[G_3],0x01,30,0x07,0x04);
                }
                if(boss.SPRITE_NUM1<0)
                {
                    boss.SPRITE_NUM1=3;
                }
                if(boss.SPRITE_NUM2<0)
                {
                    boss.SPRITE_NUM2=3;
                }
                if(boss.SPRITE_NUM3<0)
                {
                    boss.SPRITE_NUM3=3;
                }

                if((bala_boss[1].POS_X < 24 && bala_boss[1].flag_lanzado == 1)|| boss.flag_desatorar ==1)
                {
                    boss.flag_desatorar = 1;                   
                    DrawMegaSprite(468-(boss.SPRITE_NUM<<1),SPR_Banco1|SPR_visible|(0x3c00),0,160,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM1<<1),SPR_Banco1|SPR_visible|(0x4000),0,176,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM2<<1),SPR_Banco1|SPR_visible|(0x4400),16,160,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM3<<1),SPR_Banco1|SPR_visible|(0x4800),16,176,2,2);
                }

            }
            break;



        case REPOSO:
            DrawMegaSprite(192,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);


            if((((boss.flag_corriendo==1 || boss.flag_ataque_estado==1))||
              (boss.flag_ataque_estado==0 && boss.POS_X > (Jugador1.POS_X - 8)&&boss.POS_X < (Jugador1.POS_X +32))||
              (boss.flag_ataque_estado==0 && (boss.POS_X+24) > (Jugador1.POS_X - 8)&&(boss.POS_X+24) < (Jugador1.POS_X +32)))&&boss.Animacion_General>200)
            {
                if((boss_ramdom & 0x0003)==0)
                {
                    boss.flag_corriendo=0;
                }
                if((boss_ramdom & 0x0003)==1 && bala_boss[0].flag_lanzado == 0 )
                {
                    boss.estado = ATAQUE_DETENIDO_1;
                    boss.contador_eventos=0;
                    boss.Animacion_General=0;
                    boss.flag_corriendo=0;
                    boss.flag_lanzando_chunche=0;
                    boss.POS_X_CONT = 8;
                    
                }
                if((boss_ramdom & 0x0003)==2 && bala_boss[1].flag_lanzado == 0 )
                {
                    boss.POS_X_CONT = 8;
                    boss.estado = ATAQUE_DETENIDO_2;
                    boss.contador_eventos=0;
                    boss.Animacion_General=0;
                    boss.flag_corriendo=0;
                    boss.flag_lanzando_chunche=0;

                }
                if((boss_ramdom & 0x0003)==3 && bala_boss[2].flag_lanzado == 0)                
                {
                    boss.POS_X_CONT=10;
                    boss.estado = ATAQUE_DETENIDO_3;
                    boss.Animacion_General=0;
                    boss.contador_eventos=0;
                    boss.flag_corriendo=0;
                    boss.flag_lanzando_chunche=0;                   

                }

            }
            
            else
            {
                if(boss.POS_X > Jugador1.POS_X && boss.POS_X < (Jugador1.POS_X+64) && boss.ir_izquierda == 1 && boss.flag_corriendo==0)
                {
                    boss.POS_X_CONT = 7;
                    boss.estado = CORRER_1;
                    boss.Animacion_General=0;
                    boss.flag_corriendo=1;
                }
                if(boss.POS_X < Jugador1.POS_X && boss.POS_X > (Jugador1.POS_X-64) && boss.ir_derecha == 1 && boss.flag_corriendo==0)
                {
                    boss.POS_X_CONT = 7;
                    boss.estado = CORRER_1;
                    boss.Animacion_General=0;
                    boss.flag_corriendo=1;
                }

                /*if(((kunay.flag_lanzado==1 && (kunay.POS_X+64) > boss.POS_X  && (kunay.ATRIBUTO&SPR_Mirror_H)==0)
                        ||(kunay.flag_lanzado==1 && (kunay.POS_X-64) < boss.POS_X  && (kunay.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                        || (Jugador1.flag_saltando==1 && boss.flag_corriendo==0) )&& boss.flag_cayendo == 0)
                {
                    boss.estado_anterior = REPOSO;
                    boss.estado = BALA_SALTANDO_1;
                    boss.contador_eventos=0;
                    boss.contador_eventos2=0;
                    if(boss.vida>10)
                        boss.POS_X_CONT=16;
                    else
                        boss.POS_X_CONT=7;

                    boss.Index_caida=0;
                    boss.flag_lanzando_chunche=0;
                    boss.Animacion_General=0;
                    DrawMegaSprite(288,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                }*/
            }

//            if(boss.flag_ataque_estado == 1&&(boss_ramdom & 0x0003)==1)
//            {
//                boss.estado = ATAQUE_DETENIDO_1;
//                boss.Animacion_General=0;
//                boss.flag_corriendo=0;
//            }else
//            if(boss.flag_ataque_estado == 1 &&(boss_ramdom & 0x0003)==2 && bala_boss[1].flag_lanzado == 0 )
//            {
//                boss.POS_X_CONT = 8;
//                boss.estado = ATAQUE_DETENIDO_2;
//                boss.contador_eventos=0;
//                boss.Animacion_General=0;
//                boss.flag_corriendo=0;
//            }else
//            if(boss.flag_ataque_estado == 1 &&(boss_ramdom & 0x0003)==3)
//            {
//                boss.POS_X_CONT=10;
//                boss.estado = ATAQUE_DETENIDO_3;
//                boss.Animacion_General=0;
//                boss.flag_corriendo=0;
//            }

            break;


        case CORRER_1:


            if(boss.Animacion_General>30)
            {
                boss.flag_corriendo=1;
                DrawMegaSprite(201,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = CORRER_2;
                boss.estado_anterior=CORRER_2;
            }

            if(boss.ir_derecha == 1 && boss.POS_X > 188)
            {
                boss.ir_derecha=0;
                boss.ir_izquierda=1;
                boss.estado=REPOSO;
                boss.flag_corriendo=0;

            }
            if(boss.ir_izquierda == 1 && boss.POS_X < 14)
            {
                boss.ir_derecha=1;
                boss.ir_izquierda=0;
                boss.estado=REPOSO;
                boss.flag_corriendo=0;
            }

            if(((kunay.flag_lanzado==1 && (kunay.POS_X+64) > boss.POS_X  && (kunay.ATRIBUTO&SPR_Mirror_H)==0)
                ||(kunay.flag_lanzado==1 && (kunay.POS_X-64) < boss.POS_X  && (kunay.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                ||(Jugador1.flag_saltando==1 && boss.flag_corriendo==0) )&& boss.flag_cayendo == 0)
            {               
                
                boss.flag_corriendo=1;
                boss.estado_anterior=CORRER_2;
                boss.contador_eventos=0;
                boss.contador_eventos2=0;
                if(boss.vida>10)
                    boss.POS_X_CONT=16;
                else
                    boss.POS_X_CONT=7;
                boss.Index_caida=0;
                boss.estado = BALA_SALTANDO_1;
                boss.Animacion_General=0;
                DrawMegaSprite(288,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);

            }
            break;
        case CORRER_2:
            if(boss.Animacion_General>30)
            {
                DrawMegaSprite(204,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                if(boss.estado_anterior==CORRER_3)
                    boss.estado = CORRER_1;
                if(boss.estado_anterior==CORRER_2)
                    boss.estado = CORRER_3;
            }
            break;

        case CORRER_3:
            if(boss.Animacion_General>30)
            {

                DrawMegaSprite(207,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                boss.Animacion_General=0;
                boss.estado = CORRER_2;
                boss.estado_anterior=CORRER_3;

            }

            if(boss.flag_ataque_estado==1)
            {
                boss.flag_lanzando_chunche=0;
                boss.estado = ATAQUE_CORRIENDO_1;
                boss.Animacion_General=0;
            }

            break;

        case BALA_SALTANDO_1:
            if(boss.Animacion_General>Delay_Salto)
            {
                check_mirror(ATTR_TEMP);
                if(bala_boss[0].flag_lanzado == 0 && boss.POS_Y > (Jugador1.POS_Y)&&boss.POS_Y < (Jugador1.POS_Y+24))
                {
                    
                    if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                    {

                        boss.flag_lanzando_chunche=1;
                        bala_boss[0].flag_lanzado = 1;
                        bala_boss[0].flag_origen = 1;
                        bala_boss[0].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        bala_boss[0].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        bala_boss[0].POS_X = boss.POS_X;
                        bala_boss[0].POS_Y = boss.POS_Y+8;
                    }
                }

                if(boss.contador_eventos2==0)
                {
                    boss.contador_eventos2=1;
                    DrawMegaSprite(288,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                }

                if(boss.contador_eventos2==1)
                {
                    boss.contador_eventos2=2;
                    DrawMegaSprite(291,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                }

                if(boss.contador_eventos2==2)
                {
                    boss.contador_eventos2=0;
                    boss.flag_lanzando_chunche=0;
                }

                if (boss.flag_cayendo==1 || boss.Index_caida < 8)
                    boss.POS_Y = boss.POS_Y + tabla_salto[boss.Index_caida++];


                if(boss.Index_caida > POS_Y_MAX) boss.Index_caida = POS_Y_MAX;

                if (boss.flag_cayendo==0 && boss.Index_caida > 10)
                {
                    boss.contador_eventos2=0;
                    boss.flag_saltando=0;
                    boss.flag_ataque_estado=0;
                    boss.estado=REPOSO;                    
                    boss.POS_Y=boss.POS_Y&0xfffffff8; /// correcion de la posicion en Y
                }
                boss.Animacion_General=0;
            }
            break;

        case ATAQUE_DETENIDO_1:            
            if(boss.Animacion_General>50)
            {
                if(boss.contador_eventos==1)
                    DrawMegaSprite(192,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                if(boss.contador_eventos==2)
                    DrawMegaSprite(195,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                if(boss.contador_eventos==3)
                    DrawMegaSprite(198,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                if(boss.contador_eventos==4)
                {
                    DrawMegaSprite(198,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                    if(bala_boss[0].flag_lanzado == 0 && boss.POS_Y > (Jugador1.POS_Y-8)&&boss.POS_Y < (Jugador1.POS_Y+32))
                    {
                        check_mirror(ATTR_TEMP);
                        if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                        {
                            boss.flag_lanzando_chunche=1;
                            bala_boss[0].flag_lanzado = 1;
                            bala_boss[0].flag_origen = 1;
                            bala_boss[0].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                            bala_boss[0].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                            bala_boss[0].POS_X = boss.POS_X;
                            bala_boss[0].POS_Y = boss.POS_Y+8;
                        }
                        boss.contador_eventos=0;
                    }
                    boss.estado = REPOSO;
                }
                 boss.Animacion_General=0;
                 boss.flag_ataque_estado=0;
                 boss.contador_eventos++;
            }
            break;

        case ATAQUE_DETENIDO_2:

            if(boss.Animacion_General>80)
            {
                boss.Animacion_General=0;
                check_mirror(ATTR_TEMP);
                if(boss.contador_eventos == 0 && bala_boss[1].flag_lanzado==0)
                {
                    boss.flag_lanzando_chunche=0;
                   DrawMegaSprite(210,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos =1;
                }else
                if(boss.contador_eventos == 1)
                {
                   DrawMegaSprite(213,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos =2;
                }else
                if(boss.contador_eventos == 2)
                {
                   DrawMegaSprite(216,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos = 3;
                }else
                if(boss.contador_eventos == 3)
                {
                   DrawMegaSprite(219,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos = 4;
                }else
                if(boss.contador_eventos == 4)
                {
                   DrawMegaSprite(219,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                   boss.contador_eventos =5;
                   if(bala_boss[1].flag_lanzado == 0)
                    {
                        if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                        {
                            boss.flag_lanzando_chunche=1;
                            bala_boss[1].flag_lanzado = 1;
                            bala_boss[1].flag_origen = 1;
                            bala_boss[1].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                            bala_boss[1].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                            bala_boss[1].POS_X = boss.POS_X;
                            bala_boss[1].POS_Y = boss.POS_Y+8;
                        }
                    }
                   
                }else
                    if(boss.contador_eventos == 5)
                    {
                        boss.estado=REPOSO;
                        boss.flag_corriendo=0;
                        boss.contador_eventos =0;
                    }              

            }

            break;

        case ATAQUE_DETENIDO_3:
            if(boss.Animacion_General>50)
            {
                boss.Animacion_General=0;
                if(boss.contador_eventos==1)
                    DrawMegaSprite(192,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                if(boss.contador_eventos==2)
                    DrawMegaSprite(195,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                if(boss.contador_eventos==3)
                    DrawMegaSprite(198,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                if(boss.contador_eventos==4)
                {
                    DrawMegaSprite(198,boss.ATRIBUTO,boss.POS_X,boss.POS_Y,3,3);
                    if(bala_boss[2].flag_lanzado == 0)
                    {
                        bala_boss[2].flag_lanzado = 1;
                        bala_boss[2].flag_origen = 1;
                        bala_boss[2].POS_X = (boss_ramdom & 0x003f) ;
                        bala_boss[2].POS_Y = 0;
                        bala_boss[3].flag_lanzado = 1;
                        bala_boss[3].flag_origen = 1;
                        bala_boss[3].POS_X = (RAMDOM_INT2 & 0x07F)+20;
                        bala_boss[3].POS_Y = 0;
                        bala_boss[4].flag_lanzado = 1;
                        bala_boss[4].flag_origen = 1;
                        bala_boss[4].POS_X = (boss_ramdom & 0x001f)+100;
                        bala_boss[4].POS_Y = 0;
                        bala_boss[5].flag_lanzado = 1;
                        bala_boss[5].flag_origen = 1;
                        bala_boss[5].POS_X = (RAMDOM_INT2 & 0x001f)+130;
                        bala_boss[5].POS_Y = 0;
                        boss.contador_eventos=0;
                    }
                    boss.estado = REPOSO;
                }
                boss.contador_eventos++;
            }
            break;

        case ATAQUE_CORRIENDO_1:
            if(bala_boss[0].flag_lanzado == 0 && (boss.POS_Y-8) < (Jugador1.POS_Y)&& (boss.POS_Y+28) > (Jugador1.POS_Y+24))
            {
                
                    if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                    {
                        check_mirror(ATTR_TEMP);
                        boss.flag_lanzando_chunche=1;
                        bala_boss[0].flag_lanzado = 1;
                        bala_boss[0].flag_origen = 1;
                        bala_boss[0].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        bala_boss[0].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        bala_boss[0].POS_X = boss.POS_X;
                        bala_boss[0].POS_Y = boss.POS_Y+8;
                    }
             }
            boss.estado= CORRER_1;
            break;

        case GOLPE_MUERTE_1:
            if(boss.Animacion_General>10)
            {

                boss.estado = boss.estado_anterior;
                boss.Animacion_General=0;
            }
            break;

        case GOLPE_MUERTE_2:
            boss_muerto();
            break;

        case MUERTE_CAIDA:
//muerto no
            if(boss.Animacion_General>3000)
            {
                
                boss.Animacion_General=2980;
                AudioOut.wr_play_song(2000,0x00);
                VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad--);
                if(Niveles.opacidad<=0)
                {
                    Limpiar_sprites_mem();
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;
                    Niveles.estado=16;
                    Niveles.opacidad=0;
                    VideoScreen.load_MAP(MAPA8,0,0,MAX_MAP8_x,MAX_MAP8_y);
                    VideoScreen.Scroll_MAP(MAPA8,MAX_MAP8_x,MAX_MAP8_y);
                }
                DrawMegaSprite(6,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Niveles.estado_continue=16;
            }
            DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,3,3);
            break;

    }

AudioOut.FX_enemigo(15);
    if(Jugador1.flag_ataque_estado==0&&boss.flag_golpeado==1)
        boss.flag_golpeado=0;

}

void boss_nivel4()   // jefe nivel 4
{

    char En_Rango;
    int cont;
    unsigned int ATTR_TEMP;
    int boss_ramdom;
    char buf[10];
    boss.Enemigo_tipo=BOSS4;
    RAMDOM();
    boss_ramdom = RAMDOM_INT&0x000ffff;


    if (boss.POS_X > 0 && boss.POS_X <= 224)
        En_Rango=1;
    else
        En_Rango=0;


    if (En_Rango==1 && boss.muerto==0)
       ATTR_TEMP=SPR_Banco2|SPR_visible|((0x0c)<<8);
    else
       ATTR_TEMP=SPR_Banco2|((0x0c)<<8);

    if (boss.ir_derecha == 1)
        boss.ATRIBUTO=ATTR_TEMP;
    if (boss.ir_izquierda == 1)
        boss.ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;


    mov_x(194,4);
    golpe(); //jugador golpea el jefe


    if(bala_boss[0].animacion_cont > 0 && bala_boss[0].animacion_cont <= 25)
    {
        Bala_boss(500,0);
        Bala_boss(500,1);

        bloque_cayendo(30,0,2);
        bloque_cayendo(30,1,2);
        bloque_cayendo(30,2,2);
        bloque_cayendo(30,3,2);
    }
    if(bala_boss[0].animacion_cont > 25&& bala_boss[0].animacion_cont <= 50)
    {
        Bala_boss(501,0);
        Bala_boss(501,1);
        bloque_cayendo(126,0,2);
        bloque_cayendo(126,1,2);
        bloque_cayendo(126,2,2);
        bloque_cayendo(126,3,2);
    }
    if(bala_boss[0].animacion_cont > 50 && bala_boss[0].animacion_cont <= 75)
    {
        Bala_boss(502,0);
        Bala_boss(502,1);
        bloque_cayendo(222,0,2);
        bloque_cayendo(222,1,2);
        bloque_cayendo(222,2,2);
        bloque_cayendo(222,3,2);
    }
    if(bala_boss[0].animacion_cont > 75 && bala_boss[0].animacion_cont <= 100)
    {
        Bala_boss(503,0);
        Bala_boss(503,1);
        bloque_cayendo(126,0,2);
        bloque_cayendo(126,1,2);
        bloque_cayendo(126,2,2);
        bloque_cayendo(126,3,2);
        bala_boss[0].animacion_cont=0;
    }

    if(bala_boss[0].animacion_cont > 200)
        bala_boss[0].animacion_cont=0;
    bala_boss[0].animacion_cont++;

    if( Jugador1.flag_transparente==0 && (boss.contador_eventos == 2 || boss.estado == ATAQUE_DETENIDO_3)&&((boss.flag_saltando==1 && boss.Index_caida > 32) || boss.estado == REPOSO || boss.estado == ATAQUE_DETENIDO_3) && boss.vida > 0 &&((boss.POS_Y<(Jugador1.POS_Y+1)&&(boss.POS_Y+24)>(Jugador1.POS_Y+1))||(boss.POS_Y<(Jugador1.POS_Y+23)&&(boss.POS_Y+24)>(Jugador1.POS_Y+23))))
    {
        if ((boss.estado != ATAQUE_DETENIDO_3 &&(((boss.POS_X)>(Jugador1.POS_X)&&boss.POS_X<(Jugador1.POS_X+24))||((boss.POS_X+16)>(Jugador1.POS_X)&&(boss.POS_X+16)<(Jugador1.POS_X+24))))||
             (boss.estado == ATAQUE_DETENIDO_3 &&(((boss.POS_X+16)<(Jugador1.POS_X)&&(boss.POS_X+32)>(Jugador1.POS_X)&&boss.ir_derecha == 1)||((boss.POS_X)<(Jugador1.POS_X+24)&&(boss.POS_X+16)>(Jugador1.POS_X+24)&&boss.ir_izquierda == 1))))

        {
            JugadorGolpe(boss.ATRIBUTO);
        }

    }


    if(boss.vida>0&&bala_boss[0].flag_lanzado==1)
    {
        if((Jugador1.POS_Y+23)>(bala_boss[0].POS_Y+8)&&Jugador1.POS_Y<(bala_boss[0].POS_Y+8))
        {
            if(((bala_boss[0].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_boss[0].POS_X)&&(Jugador1.POS_X+20)<(bala_boss[0].POS_X+16))
                    ||((bala_boss[0].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_boss[0].POS_X)&&(Jugador1.POS_X+8)<(bala_boss[0].POS_X+16)))
            {
                JugadorGolpe(boss.ATRIBUTO);
            }
        }
    }



    cont=2;
    while(cont<6)
    {
        if(boss.vida>0&&bala_boss[cont].flag_lanzado==1)
        {
            if(((Jugador1.POS_Y)>(bala_boss[cont].POS_Y)&&Jugador1.POS_Y<(bala_boss[cont].POS_Y+24))||
                ((Jugador1.POS_Y+23)>(bala_boss[cont].POS_Y)&&(Jugador1.POS_Y+23)<(bala_boss[cont].POS_Y+24)))
            {
                if(((Jugador1.POS_X)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X)<(bala_boss[cont].POS_X+16))||
                        ((Jugador1.POS_X+24)>(bala_boss[cont].POS_X)&&(Jugador1.POS_X+24)<(bala_boss[cont].POS_X+16))||
                        ((Jugador1.POS_X)<(bala_boss[cont].POS_X+8)&&(Jugador1.POS_X+24)>(bala_boss[cont].POS_X+8)))
                {
                    JugadorGolpe(boss.ATRIBUTO);
                }
            }
        }
        cont++;
    }


    switch(boss.estado)
    {
        case REPOSO:
                if((boss_ramdom & 0x0003)==1 && bala_boss[0].flag_lanzado == 0 && boss.flag_corriendo == 1
                        && boss.POS_Y > (Jugador1.POS_Y-8)&&boss.POS_Y < (Jugador1.POS_Y+32))
                {
                    boss.estado = ATAQUE_DETENIDO_1;
                    boss.contador_eventos=0;
                    boss.Animacion_General=0;
                    boss.flag_corriendo=0;
                    boss.flag_lanzando_chunche=0;
                    boss.POS_X_CONT = 8;
                }
                if((boss_ramdom & 0x0003)==2 && boss.flag_corriendo == 0)
                {
                    boss.POS_X_CONT = 8;
                    boss.estado = ATAQUE_DETENIDO_2;
                    boss.contador_eventos=0;
                    boss.contador_eventos2 = 2;
                    boss.Animacion_General=0;
                    boss.flag_corriendo=0;
                    boss.flag_lanzando_chunche=0;
                }
                if(((boss_ramdom & 0x0003)==3 && boss.flag_corriendo == 0)||(kunay.flag_lanzado==1))
                {
                    boss.POS_X_CONT=10;
                    boss.estado = ATAQUE_DETENIDO_3;
                    boss.Animacion_General=0;
                    boss.contador_eventos=0;
                }



            if(boss.Animacion_General>100)
            {
                

                boss.Offset_x=0;
                if(boss.contador_eventos2 == 0)
                {
                   boss.flag_corriendo=1;
                   boss.POS_X_CONT = 15;
                }

                if(boss.contador_eventos2 > 20)
                {
                    boss.flag_corriendo=0;
                    boss.contador_eventos2=0;
                }

                boss.SPRITE_W=3;
                boss.Animacion_General=0;
                boss.contador_eventos2++;
                if(boss.contador_eventos == 0)
                {
                    boss.SPRITE_NUM=294;
                    boss.POS_Y_CONT=0;

                }
                if(boss.contador_eventos == 1)
                {
                    boss.SPRITE_NUM=297;
                    boss.POS_Y_CONT=-2;
                }
                if(boss.contador_eventos == 2)
                {
                    boss.SPRITE_NUM=300;
                    boss.POS_Y_CONT=0;
                }
                if(boss.contador_eventos == 3)
                {
                    boss.SPRITE_NUM=297;
                    boss.POS_Y_CONT=2;
                    
                }

                boss.contador_eventos++;
                if(boss.contador_eventos >3)
                {
                    boss.contador_eventos=0;
                    boss.POS_Y_CONT=0;
                }

            }


            

            break;


        case ATAQUE_DETENIDO_1:
            if(boss.Animacion_General>50)
            {
                boss.estado_anterior=ATAQUE_DETENIDO_1;
                if(boss.contador_eventos==1)
                {
                    boss.SPRITE_NUM=303;
                    boss.SPRITE_W=3;
                }

                if(boss.contador_eventos==2)
                {
                    boss.SPRITE_NUM=306;
                    boss.SPRITE_W=4;

                }
                if(boss.contador_eventos==3)
                {
                    boss.SPRITE_NUM=310;
                    boss.SPRITE_W=4;
                }

               
                if(boss.contador_eventos==4)
                {

                    if(bala_boss[0].flag_lanzado == 0 && boss.POS_Y > (Jugador1.POS_Y-8)&&boss.POS_Y < (Jugador1.POS_Y+32))
                    {
                        check_mirror(ATTR_TEMP);
                        if(En_Rango==1 && boss.flag_lanzando_chunche==0)
                        {
                            boss.flag_lanzando_chunche=1;
                            bala_boss[0].flag_lanzado = 1;
                            bala_boss[0].flag_origen = 1;
                            bala_boss[0].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                            bala_boss[0].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                            bala_boss[0].POS_X = boss.POS_X;
                            bala_boss[0].POS_Y = boss.POS_Y+8;
                        }
                        
                    }
                    boss.contador_eventos=0;
                    boss.estado = REPOSO;
                    boss.flag_corriendo=1;
                    DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,4,3);
                    boss.SPRITE_W=3;
                    boss.SPRITE_NUM=294;
                }
                 boss.Animacion_General=0;
                 boss.flag_ataque_estado=0;
                 boss.contador_eventos++;
            }
            break;

        case ATAQUE_DETENIDO_2:
        
            if(boss.visible==0)
                boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);

            if(boss.Animacion_General > 60)
            {
                boss.Animacion_General=0;

                if(boss.contador_eventos==1)
                {
                    boss.visible=0;
                    DrawMegaSprite(408,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                }
                if(boss.contador_eventos==2)
                {
                    DrawMegaSprite(410,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==3)
                {
                    DrawMegaSprite(412,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==4)
                {
                    DrawMegaSprite(414,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==6)
                {
                    DrawMegaSprite(414,SPR_Banco2|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                }
                
                if(boss.contador_eventos==7)
                {   
                    boss.visible=1;
                    boss.SPRITE_W=3;
                    boss.SPRITE_NUM=314;
                    boss.POS_X = Jugador1.POS_X+2;
                    boss.POS_Y = 64;
                    boss.ir_izquierda=0;
                    boss.ir_derecha=1;
                    if(boss.contador_eventos2>6)
                    {
                        boss.estado = REPOSO;
                        boss.contador_eventos = 0;
                        boss.flag_corriendo=1;
                        if(Jugador1.POS_X < 170 && Jugador1.POS_X > 0)
                            boss.POS_X = Jugador1.POS_X+32;
                        else
                            boss.POS_X = 100;
                        boss.POS_Y = 168;
                        boss.ir_izquierda=1;
                        boss.ir_derecha=0;
                    }
                            
                }
                if(boss.contador_eventos==8)
                {
                    boss.SPRITE_NUM=317;
                    boss.ir_izquierda=1;
                    boss.ir_derecha=0;
                }

                if(boss.contador_eventos==9)
                {
                    boss.SPRITE_NUM=314;
                    boss.ir_izquierda=0;
                    boss.ir_derecha=1;
                }

                
                if(boss.contador_eventos==10)
                {
                    AudioOut.wr_play_fx(tabladefrecuencias[F_3],0x01,32,0x07,0x04);
                    if(bala_boss[boss.contador_eventos2].flag_lanzado == 0)
                    {
                        bala_boss[boss.contador_eventos2].flag_lanzado = 1;
                        bala_boss[boss.contador_eventos2].flag_origen = 1;
                        bala_boss[boss.contador_eventos2].POS_X =  boss.POS_X;
                        bala_boss[boss.contador_eventos2].POS_Y = boss.POS_Y+16;
                        boss.contador_eventos=0;
                    }
                    boss.contador_eventos2++;
                    boss.contador_eventos=0;
                }
                boss.contador_eventos++;                
            }           
            break;

        case ATAQUE_DETENIDO_3:
             if(boss.visible==0)
                boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);

            if(boss.Animacion_General > 60)
            {
                boss.Animacion_General=0;

                if(boss.contador_eventos==1)
                {
                    boss.visible=0;
                    DrawMegaSprite(408,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                }
                if(boss.contador_eventos==2)
                {
                    DrawMegaSprite(410,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==3)
                {
                    DrawMegaSprite(412,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==4)
                {
                    DrawMegaSprite(414,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==6)
                {
                    DrawMegaSprite(414,SPR_Banco2|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    check_mirror(ATTR_TEMP);                    
                    boss.SPRITE_W=4;
                    boss.SPRITE_NUM=384;
                    boss.POS_Y = Jugador1.POS_Y;
                    if(boss.ir_derecha)
                    {
                        boss.POS_X = Jugador1.POS_X-32;
                    }
                    else
                         boss.POS_X = Jugador1.POS_X+32;
                    

                }

                if(boss.contador_eventos==7)
                {                    
                    DrawMegaSprite(414,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                }
                if(boss.contador_eventos==8)
                {
                    DrawMegaSprite(412,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==9)
                {
                    DrawMegaSprite(410,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==10)
                {
                    DrawMegaSprite(408,SPR_Banco2|SPR_visible|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss.contador_eventos==11)
                {
                    DrawMegaSprite(414,SPR_Banco2|(0x4800),boss.POS_X+2,boss.POS_Y+6,2,2);
                    boss.visible=1;
                }


                if(boss.contador_eventos==12)
                {
                    AudioOut.wr_play_fx(tabladefrecuencias[G_3],0x01,40,0x03,0x02);
                    boss.flag_corriendo=1;
                    boss.SPRITE_W=4;
                    boss.SPRITE_NUM=388;

                }
                if(boss.contador_eventos==13)
                {
                    boss.SPRITE_W=4;
                    boss.SPRITE_NUM=392;

                }
                if(boss.contador_eventos==14)
                {
                    boss.SPRITE_W=4;
                    boss.SPRITE_NUM=396;

                }
                if(boss.contador_eventos==15)
                {
                    boss.SPRITE_W=3;
                    boss.SPRITE_NUM=294;
                    DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,4,3);
                    boss.contador_eventos=0;
                    boss.estado=REPOSO;
                }

                boss.contador_eventos++;
            }
            break;

        case GOLPE_MUERTE_1:
            if(boss.Animacion_General>10)
            {
                boss.estado = boss.estado_anterior;
                boss.Animacion_General=0;
            }
            break;

        case GOLPE_MUERTE_2:
            boss_muerto();
            break;

        case MUERTE_CAIDA:
            if(boss.Animacion_General>3000)
            {
                boss.Animacion_General=2980;
                AudioOut.wr_play_song(2000,0x00);
                VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad--);
                if(Niveles.opacidad<=0)
                {
                    Limpiar_sprites_mem();
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;
                    Niveles.estado=19;
                    Niveles.opacidad=0;
                    VideoScreen.load_MAP(MAPA10,0,0,MAX_MAP10_x,MAX_MAP10_y);
                    VideoScreen.Scroll_MAP(MAPA10,MAX_MAP10_x,MAX_MAP10_y);
                }
                DrawMegaSprite(6,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                Niveles.estado_continue=19;
            }
            DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,3,3);
            break;

    }

    if(boss.SPRITE_W==4)// correcion de la pocision para la animacion
    {
        if((boss.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
           boss.Offset_x=8;
        else
           boss.Offset_x=0;
    }
    else
         boss.Offset_x=0;


    if(boss.muerto==0)
    {

        DrawMegaSprite(boss.SPRITE_NUM,boss.ATRIBUTO,boss.POS_X-boss.Offset_x,boss.POS_Y+boss.POS_Y_CONT,boss.SPRITE_W,3);
    }

    AudioOut.FX_enemigo(15);
    if(Jugador1.flag_ataque_estado==0&&boss.flag_golpeado==1)
        boss.flag_golpeado=0;
}


void boss_nivel5()
{

    char En_Rango;
    int cont;
    unsigned int ATTR_TEMP;
    int boss_final_ramdom;
    char buf[10];
     


    if (boss_final.POS_X > 0 && boss_final.POS_X <= 224)
        En_Rango=1;
    else
        En_Rango=0;


    if (En_Rango==1 && boss_final.muerto==0)
       ATTR_TEMP=SPR_Banco2|SPR_visible|((0x0c)<<8);
    else
       ATTR_TEMP=SPR_Banco2|((0x0c)<<8);

    if (boss_final.ir_derecha == 1)
        boss_final.ATRIBUTO=ATTR_TEMP;
    if (boss_final.ir_izquierda == 1)
        boss_final.ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;

    switch(boss_final.estado)
    {
        
        case DIALOGO:

            if(boss_final.contador_eventos==0)
                Dialogo("...Muy Bien Tatsuko","veamos si puedes", "   detenerme");

            if(boss_final.Animacion_General > 200)
            {
                boss_final.Animacion_General=0;
                boss_final.SPRITE_NUM=400;
                boss_final.SPRITE_W=3;
                boss_final.visible=1;
                if(boss_final.contador_eventos==20)
                {
                    boss_final.contador_eventos=0;
                    Limpiar_sprites_mem();
                    boss_final.estado=REPOSO;
                    recuadro_encabezado();

                }
                boss_final.contador_eventos++;
            }


            break;
        case REPOSO:
            
            if(boss_final.visible==0)
            {
                boss_final.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
            }

            if(boss_final.Animacion_General > 80)
            {
                boss_final.Animacion_General=0;

                if(boss_final.contador_eventos==0)
                {
                    boss_final.visible=1;
                     boss_final.SPRITE_NUM=400;
                     boss_final.SPRITE_W=3;
                }
                if(boss_final.contador_eventos==2)
                {
                     boss_final.SPRITE_NUM=403;
                     boss_final.SPRITE_W=3;
                }
                if(boss_final.contador_eventos==4)
                {
                     boss_final.SPRITE_NUM=406;
                     boss_final.SPRITE_W=2;
                     DrawMegaSprite(0,SPR_Banco2|((0x0c)<<8),boss_final.POS_X-boss_final.Offset_x,boss_final.POS_Y+boss_final.POS_Y_CONT,3,3);
                }
                if(boss_final.contador_eventos==6)
                {
                    AudioOut.wr_play_fx(tabladefrecuencias[C_4],0x01,32,0x07,0x04);
                    boss_final.visible=0;
                    DrawMegaSprite(408,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                }
                if(boss_final.contador_eventos==7)
                {
                    DrawMegaSprite(410,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    
                }
                if(boss_final.contador_eventos==8)
                {
                    AudioOut.wr_play_fx(tabladefrecuencias[A_3],0x01,32,0x07,0x04);
                    DrawMegaSprite(412,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    
                }
                if(boss_final.contador_eventos==9)
                {
                    DrawMegaSprite(414,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    
                }
                if(boss_final.contador_eventos==10)
                {
                    DrawMegaSprite(414,SPR_Banco2|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    check_mirror(ATTR_TEMP);
                }

                if(boss_final.contador_eventos==11)
                {
                    DrawMegaSprite(414,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                }
                if(boss_final.contador_eventos==12)
                {
                    AudioOut.wr_play_fx(tabladefrecuencias[G_3],0x01,32,0x07,0x04);
                    DrawMegaSprite(412,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    
                }
                if(boss_final.contador_eventos==13)
                {
                    DrawMegaSprite(410,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    
                }
                if(boss_final.contador_eventos==14)
                {
                    DrawMegaSprite(408,SPR_Banco2|SPR_visible|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    boss_final.ATRIBUTO=SPR_Banco2|((0x0c)<<8);
                }
                if(boss_final.contador_eventos==15)
                {
                    DrawMegaSprite(414,SPR_Banco2|(0x4800),boss_final.POS_X+2,boss_final.POS_Y+6,2,2);
                    boss.POS_X = boss_final.POS_X;
                    boss.POS_Y = boss_final.POS_Y;
                    Niveles.boss_sec++;
                    boss_final.contador_eventos=0;
                    if(Niveles.boss_sec==1)
                    {
                        boss_final.estado=BOSS_1;
                        boss.estado=REPOSO;
                    }
                    if(Niveles.boss_sec==2)
                    {
                        boss_final.estado=BOSS_2;
                        boss.estado=REPOSO;
                    }
                    if(Niveles.boss_sec==3)
                    {
                        boss_final.estado=BOSS_3;
                        boss.estado=REPOSO;
                    }
                    if(Niveles.boss_sec==4)
                    {
                        boss.vida=10;
                        boss_final.estado=BOSS_4;
                        boss.estado=REPOSO;
                    }
                    if(Niveles.boss_sec==5)

                        boss_final.estado=GOLPE_MUERTE_2;
                }
                    boss_final.contador_eventos++;
            }
            break;

        case BOSS_1:
            boss_nivel1();
            if(boss.vida < 15&&bala_boss[0].flag_lanzado==0&&bala_boss[1].flag_lanzado==0)
            {
                cont=0;
                while(cont<6)
                bala_boss[cont++].flag_lanzado=0;
                boss_final.Animacion_General=0;
                boss_final.contador_eventos=0;
                boss_final.estado=REPOSO;
            }
            break;

        case BOSS_2:
            boss_nivel2();
            if(boss.vida < 10&&bala_boss[0].flag_lanzado==0&&bala_boss[1].flag_lanzado==0)
            {
                cont=0;
                while(cont<6)
                bala_boss[cont++].flag_lanzado=0;
                boss_final.Animacion_General=0;
                boss_final.contador_eventos=0;
                boss_final.estado=REPOSO;
            }
            break;

        case BOSS_3:
            boss_nivel3();
            if(boss.vida < 5 && bala_boss[0].flag_lanzado==0 && bala_boss[1].flag_lanzado==0
                    &&bala_boss[2].flag_lanzado==0&&bala_boss[3].flag_lanzado==0
                    &&bala_boss[4].flag_lanzado==0&&bala_boss[5].flag_lanzado==0)
            {
                cont=0;
                while(cont<6)
                bala_boss[cont++].flag_lanzado=0;

                boss_final.Animacion_General=0;
                boss_final.contador_eventos=0;
                boss_final.estado=REPOSO;
            }
            break;

        case BOSS_4:
            boss_nivel4();
            if(boss.vida <= 0&& bala_boss[0].flag_lanzado==0 && bala_boss[1].flag_lanzado==0
                    &&bala_boss[2].flag_lanzado==0&&bala_boss[3].flag_lanzado==0
                    &&bala_boss[4].flag_lanzado==0&&bala_boss[5].flag_lanzado==0)
            {
                Control1.Habilitar=0;
                boss_final.Animacion_General=0;
                boss_final.contador_eventos=0;
                boss_final.estado=REPOSO;
            }
            break;

        case GOLPE_MUERTE_2:

            read_controller=0xffff;
            if(boss_final.Animacion_General<10)
                AudioOut.wr_play_fx(tabladefrecuencias[C_2],0x01,30,0x05,0x01);

            if(boss_final.Animacion_General>40&&boss_final.Animacion_General<=80)
            {
                boss_final.muerto=1;
                DrawMegaSprite(288,(boss_final.ATRIBUTO&0xfffc)|0b00000001,boss_final.POS_X,boss_final.POS_Y,3,3);
            }
            if(boss_final.Animacion_General>80&&boss_final.Animacion_General<=120)
            {
                DrawMegaSprite(292,(boss_final.ATRIBUTO&0xfffc)|0b00000001,boss_final.POS_X,boss_final.POS_Y,3,3);
            }
            if(boss_final.Animacion_General>120&&boss_final.Animacion_General<=160)
            {
                DrawMegaSprite(295,(boss_final.ATRIBUTO&0xfffc)|0b00000001,boss_final.POS_X,boss_final.POS_Y,3,3);
            }
            if(boss_final.Animacion_General>500)
            {

                DrawMegaSprite(288,boss_final.ATRIBUTO&SPR_invisible,boss_final.POS_X,boss_final.POS_Y,3,3);
                AudioOut.WR_AUDIO_DATA(Pattern_final, track_final, Pattern_size_final,numero_de_canales_final, numero_de_patrones_final,song_size_final);
                AudioOut.wr_play_song(1000,0x01);
                boss_final.muerto=1;
                boss_final.estado = MUERTE_CAIDA;

                boss_final.Animacion_General=0;
                Niveles.opacidad=7;
            }
                    break;


        case MUERTE_CAIDA:
            if(boss.Animacion_General>6000)
            {
                
                AudioOut.wr_play_song(2000,0x00);                
                Limpiar_sprites_mem();
                VideoScreen.MAP_Scroll_x=0;
                VideoScreen.MAP_Scroll_y=0;
                Niveles.estado = 24;
                Niveles.opacidad=0;
                VideoScreen.load_MAP(FINAL,0,0,MAX_FINAL_x,MAX_FINAL_y);
                VideoScreen.Scroll_MAP(FINAL,MAX_FINAL_x,MAX_FINAL_y);
                DrawMegaSprite(6,0,Jugador1.POS_X,Jugador1.POS_Y,4,3);
                DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
                Niveles.estado_continue=24;
                Niveles.Contador_eventos=0;
            }
            DrawMegaSprite(288,boss.ATRIBUTO&SPR_invisible,boss.POS_X,boss.POS_Y,3,3);


            break;



    }


    if(boss_final.muerto==0 && (boss_final.estado==REPOSO||boss_final.estado==DIALOGO))
    {        
        DrawMegaSprite(boss_final.SPRITE_NUM,boss_final.ATRIBUTO,boss_final.POS_X-boss_final.Offset_x,boss_final.POS_Y+boss_final.POS_Y_CONT,boss_final.SPRITE_W,3);
    }


//    AudioOut.FX_enemigo(15);
//    if(Jugador1.flag_ataque_estado==0&&boss_final.flag_golpeado==1)
//        boss_final.flag_golpeado=0;
}


void ENEMIGOS(int Enemigo_numero) // se manejan todos los enemigos simples de los niveles
{
    int index1_map;
    int Cant_Bloques_De=0;
    int Cant_Bloques_Iz=0;
    int cont=0;
    int comparaciones=0;
    int temp;
    int Enemigo_SPR;
    int SPRITE_NUM_temp;
    unsigned int SPRITE_ATTR_temp;
    int SPRITE_W=3;
    int SPRITE_H=3;

    char En_Rango;
    unsigned int ATTR_TEMP;

    Enemigo_SPR=Deco_enemigo(enemigo[Enemigo_numero].Enemigo_tipo); // se extrae el numero del primer sprite

    enemigo[Enemigo_numero].POS_X = (enemigo[Enemigo_numero].MAP_POS_X-VideoScreen.MAP_Scroll_x)&0x00ff;  // calcula de la posicion respecto al movimiento del jugador
    enemigo[Enemigo_numero].POS_Y = (enemigo[Enemigo_numero].MAP_POS_Y-VideoScreen.MAP_Scroll_y)&0x00ff;

    if ((enemigo[Enemigo_numero].MAP_POS_Y > VideoScreen.MAP_Scroll_y && enemigo[Enemigo_numero].MAP_POS_Y < (VideoScreen.MAP_Scroll_y +200))&&(enemigo[Enemigo_numero].MAP_POS_X > VideoScreen.MAP_Scroll_x && enemigo[Enemigo_numero].MAP_POS_X < (VideoScreen.MAP_Scroll_x +200)))
        En_Rango=1;
    else
        En_Rango=0;


    if (En_Rango==1&&enemigo[Enemigo_numero].muerto==0)
       ATTR_TEMP=SPR_Banco1|SPR_visible|((0x0c+(Enemigo_numero*12))<<8);
    else
    {
       ATTR_TEMP=SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8);
       enemigo[Enemigo_numero].ATRIBUTO = ATTR_TEMP;
    }

    if (enemigo[Enemigo_numero].ir_derecha == 1)
        enemigo[Enemigo_numero].ATRIBUTO=ATTR_TEMP;
    if (enemigo[Enemigo_numero].ir_izquierda == 1)
        enemigo[Enemigo_numero].ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;


    

    while(cont < 3)  /// se compara si ya se llego a algun filo en el nivel
    {
        if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((enemigo[Enemigo_numero].POS_X+VideoScreen.Scroll_X+4)>>3)+cont)&0x001f) | ((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y+24)&0x00f8)>>3)*32);
        else
            index1_map = ((((enemigo[Enemigo_numero].POS_X+VideoScreen.Scroll_X)>>3)+cont)&0x001f) | ((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y+24)&0x00f8)>>3)*32);
//        VideoScreen.MAP_1[165+cont]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        else
        {
            if(enemigo[Enemigo_numero].mirror ==0 && enemigo[Enemigo_numero].Enemigo_tipo != NINJA_PASAMANOS)
            {
                if(enemigo[Enemigo_numero].ir_derecha==1)
                {
                    enemigo[Enemigo_numero].ir_derecha=0;
                    enemigo[Enemigo_numero].ir_izquierda=1;
                    enemigo[Enemigo_numero].mirror = 1;
                }else
                if(enemigo[Enemigo_numero].ir_izquierda==1)
                {
                    enemigo[Enemigo_numero].ir_derecha=1;
                    enemigo[Enemigo_numero].ir_izquierda=0;
                    enemigo[Enemigo_numero].mirror = 1;
                }
            }
        }
        cont++;
    }
    if (comparaciones > 0)
    {
        enemigo[Enemigo_numero].flag_cayendo=0;
    }
    else
        enemigo[Enemigo_numero].flag_cayendo=1;



    cont=0;
    comparaciones=0;

    while(cont < 3)
    {
        if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((enemigo[Enemigo_numero].POS_X+28+VideoScreen.Scroll_X)>>3))&0x001f) | (((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        else
            index1_map = ((((enemigo[Enemigo_numero].POS_X+21+VideoScreen.Scroll_X)>>3))&0x001f) | (((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        //VideoScreen.MAP_1[72+cont*32]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        cont++;
    }
    if (comparaciones > 0)
        enemigo[Enemigo_numero].flag_Obstruido_De=1;
    else
        enemigo[Enemigo_numero].flag_Obstruido_De=0;

    if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==0)
    Cant_Bloques_De=comparaciones;

    cont=0;
    comparaciones=0;

    while(cont < 3)
    {
        if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((enemigo[Enemigo_numero].POS_X+26+VideoScreen.Scroll_X)>>3)-3)&0x001f) | (((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);
        else
            index1_map = ((((enemigo[Enemigo_numero].POS_X+19+VideoScreen.Scroll_X)>>3)-3)&0x001f) | (((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y)>>3)+cont)&0x001f)*32);

        //VideoScreen.MAP_1[68+cont*32]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            comparaciones++;
        }
        cont++;
    }
    if (comparaciones > 0)
        enemigo[Enemigo_numero].flag_Obstruido_Iz=1;
    else
        enemigo[Enemigo_numero].flag_Obstruido_Iz=0;

    if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
    Cant_Bloques_Iz=comparaciones;


    ////// comparaciones ninja de pasamanos

    cont =0;
    comparaciones=0;
    enemigo[Enemigo_numero].flag_techo=0;    
    while(cont<3)
    {
        if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
            index1_map = ((((enemigo[Enemigo_numero].POS_X+VideoScreen.Scroll_X-8)>>3)+cont)&0x001f) | (((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y+5)>>3))&0x001f)*32);
        else
            index1_map = ((((enemigo[Enemigo_numero].POS_X+VideoScreen.Scroll_X)>>3)+cont)&0x001f) | (((((enemigo[Enemigo_numero].POS_Y+VideoScreen.Scroll_Y+5)>>3))&0x001f)*32);
//        if(enemigo[0].Enemigo_tipo == NINJA_PASAMANOS)
//                VideoScreen.MAP_1[37+96+cont]=VideoScreen.MAP_1[index1_map];
        temp=VideoScreen.MAP_1[index1_map];
        if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
        {
            enemigo[Enemigo_numero].flag_techo=1;
        }
        if(temp==64||temp==65)
        {
            enemigo[Enemigo_numero].flag_pasamanos=1;
        }
        else
            enemigo[Enemigo_numero].flag_pasamanos=0;
        cont++;
    }




// hacemos que el enemigo corra
    if(enemigo[Enemigo_numero].Enemigo_tipo!=NINJA_PASAMANOS&&enemigo[Enemigo_numero].Enemigo_tipo!=NINJA_CAFE_KUNAY&&
            enemigo[Enemigo_numero].Enemigo_tipo!=NINJA_KUNAY&&
      enemigo[Enemigo_numero].vida>0&&En_Rango==1&&enemigo[Enemigo_numero].muerto==0&&enemigo[Enemigo_numero].AnimacionPosicion >20 &&
      enemigo[Enemigo_numero].flag_ataque_estado==0&&enemigo[Enemigo_numero].flag_saltando==0&&enemigo[Enemigo_numero].flag_lanzando_chunche == 0) // control del desplazamiento en (X,Y)
    {
        if (enemigo[Enemigo_numero].contador_eventos > 10) // retardo para cambio de forma de correr
        {
             enemigo[Enemigo_numero].mirror = 0;
             enemigo[Enemigo_numero].contador_eventos=0;
        }
        if (enemigo[Enemigo_numero].mirror == 1)
            enemigo[Enemigo_numero].contador_eventos++;

        enemigo[Enemigo_numero].flag_corriendo=0; // se limpia la bandera

        if (enemigo[Enemigo_numero].ir_derecha == 1)
        {
            if (enemigo[Enemigo_numero].flag_Obstruido_De == 0)
            {
                enemigo[Enemigo_numero].MAP_POS_X++;
                enemigo[Enemigo_numero].POS_X_CONT++;
            }


            if(enemigo[Enemigo_numero].POS_X_CONT > 200 || enemigo[Enemigo_numero].flag_Obstruido_De == 1)
            {
                enemigo[Enemigo_numero].ir_izquierda = 1;
                enemigo[Enemigo_numero].ir_derecha = 0;
            }

            enemigo[Enemigo_numero].flag_corriendo=1;
        }

        if (enemigo[Enemigo_numero].ir_izquierda == 1)
        {
            if (enemigo[Enemigo_numero].flag_Obstruido_Iz == 0)
            {
                enemigo[Enemigo_numero].MAP_POS_X--;
                enemigo[Enemigo_numero].POS_X_CONT--;
            }

            if (enemigo[Enemigo_numero].POS_X_CONT<0 ||enemigo[Enemigo_numero].flag_Obstruido_Iz == 1)
            {
                enemigo[Enemigo_numero].ir_izquierda = 0;
                enemigo[Enemigo_numero].ir_derecha = 1;
            }

            enemigo[Enemigo_numero].flag_corriendo=1;
        }
        enemigo[Enemigo_numero].AnimacionPosicion = 0;
    }


    // jugador 1 golpea enemigo
        if(En_Rango == 1 &&(enemigo[Enemigo_numero].POS_Y)>(Jugador1.POS_Y-8)&&enemigo[Enemigo_numero].POS_Y<(Jugador1.POS_Y+24)&&enemigo[Enemigo_numero].vida>0)
        {

            if(Jugador1.flag_ataque_estado>0 )
            {
                if(((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(enemigo[Enemigo_numero].POS_X)>(Jugador1.POS_X-24)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+10))||
                        ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0 &&(enemigo[Enemigo_numero].POS_X)>(Jugador1.POS_X+10)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+26)))
                {
                    enemigo[Enemigo_numero].estado=GOLPE_MUERTE_1;
                    DrawMegaSprite(0,SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,4,3);
                    enemigo[Enemigo_numero].SPRITE_NUM=288;
                    enemigo[Enemigo_numero].Animacion_General=0;
                    enemigo[Enemigo_numero].flag_ataque_estado=0;
                    enemigo[Enemigo_numero].vida=0;
                }

            }
        }

        if(En_Rango == 1 &&(enemigo[Enemigo_numero].POS_Y+23)>(kunay.SPR_POS_Y+4)&&enemigo[Enemigo_numero].POS_Y<(kunay.SPR_POS_Y+4))
        {


            if(kunay.flag_lanzado==1&&kunay.flag_origen==0&&enemigo[Enemigo_numero].vida>0)
            {
                if(((kunay.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(enemigo[Enemigo_numero].POS_X)<(kunay.POS_X)&&(enemigo[Enemigo_numero].POS_X+20)>(kunay.POS_X))||
                        ((kunay.ATRIBUTO&SPR_Mirror_H)==0 &&(enemigo[Enemigo_numero].POS_X)<(kunay.POS_X+16)&&(enemigo[Enemigo_numero].POS_X+20)>(kunay.POS_X+16)))
                {
                    enemigo[Enemigo_numero].estado=GOLPE_MUERTE_1;
                    DrawMegaSprite(0,SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,4,3);

                    enemigo[Enemigo_numero].SPRITE_NUM=288;
                    enemigo[Enemigo_numero].Animacion_General=0;
                    kunay.flag_lanzado=0;
                    kunay.flag_origen=0;
                    spr[80].SPR_ATTR = 0;
                    spr[81].SPR_ATTR = 0;
                    enemigo[Enemigo_numero].vida=0;
                    enemigo[Enemigo_numero].flag_ataque_estado=0;
                }
            }
        }


    if(Jugador1.flag_transparente==0&&Jugador1.muerto==0&&En_Rango == 1)
    {
        if(enemigo[Enemigo_numero].Enemigo_tipo == NINJA_ESPADA)
        {
    ///////***************enemigo golpea jugador 1*******************************/
            if((enemigo[Enemigo_numero].POS_X)>(Jugador1.POS_X-10)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+30))// comparamos si estamos cerca del jugador 1
                   enemigo[Enemigo_numero].flag_ataque_estado=1;   // inicio de la maquina de estado para el ataque
            if((enemigo[Enemigo_numero].POS_X + 32)>(Jugador1.POS_X-10)&&(enemigo[Enemigo_numero].POS_X+32)<(Jugador1.POS_X+30))// comparamos si estamos cerca del jugador 1
                   enemigo[Enemigo_numero].flag_ataque_estado=1;   // inicio de la maquina de estado para el ataque
    /************************************************************/
        }
        
       // <editor-fold defaultstate="collapsed" desc="Enemigo Espada ">
        if(enemigo[Enemigo_numero].vida > 0 &&(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_ESPADA||enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA))
        {

            if(((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==0&&(enemigo[Enemigo_numero].POS_X+24)>(Jugador1.POS_X)&&(enemigo[Enemigo_numero].POS_X+24)<(Jugador1.POS_X+26))||
                    (((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H&&enemigo[Enemigo_numero].POS_X>(Jugador1.POS_X)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+26))))// comparamos si estamos cerca del jugador 1
            {
                if((enemigo[Enemigo_numero].POS_Y)>(Jugador1.POS_Y-8)&&enemigo[Enemigo_numero].POS_Y<(Jugador1.POS_Y+24)&&(enemigo[Enemigo_numero].flag_ataque_estado==1||enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_ESPADA))
                {
                    JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
                }
            }

        }
// </editor-fold>



       // <editor-fold defaultstate="collapsed" desc="Enemigo kunay ">

        if (En_Rango == 1 && Jugador1.POS_X < enemigo[Enemigo_numero].POS_X && enemigo[Enemigo_numero].Enemigo_tipo == NINJA_KUNAY)
        {
            //Jugador1.mirror=1; // por donde se le da el golpe al jugador
            enemigo[Enemigo_numero].ir_derecha =0;
            enemigo[Enemigo_numero].ir_izquierda=1;
        }
        if (En_Rango == 1 && Jugador1.POS_X > enemigo[Enemigo_numero].POS_X && enemigo[Enemigo_numero].Enemigo_tipo == NINJA_KUNAY)
        {
            //Jugador1.mirror=0; // por donde se da el golpe al jugador
            enemigo[Enemigo_numero].ir_derecha =1;
            enemigo[Enemigo_numero].ir_izquierda=0;
        }

        if(enemigo[Enemigo_numero].vida > 0 && enemigo[Enemigo_numero].Enemigo_tipo == NINJA_KUNAY && ((enemigo[Enemigo_numero].POS_Y)>(Jugador1.POS_Y)&&enemigo[Enemigo_numero].POS_Y<(Jugador1.POS_Y+24)))
        {

            if(((enemigo[Enemigo_numero].POS_X)>(Jugador1.POS_X)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+24))||((enemigo[Enemigo_numero].POS_X+16)>(Jugador1.POS_X)&&(enemigo[Enemigo_numero].POS_X+16)<(Jugador1.POS_X+24)))
            {
                JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
            }

        }
        
        // </editor-fold>


    }


    if(enemigo[Enemigo_numero].vida>0&&kunay_enemigo[Enemigo_numero].flag_lanzado==1)
    {
        if((Jugador1.POS_Y+23)>(kunay_enemigo[Enemigo_numero].POS_Y+4)&&Jugador1.POS_Y<(kunay_enemigo[Enemigo_numero].POS_Y+4))
        {
            if(((kunay_enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(kunay_enemigo[Enemigo_numero].POS_X)&&(Jugador1.POS_X+20)<(kunay_enemigo[Enemigo_numero].POS_X+16))
                    ||((kunay_enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(kunay_enemigo[Enemigo_numero].POS_X)&&(Jugador1.POS_X+8)<(kunay_enemigo[Enemigo_numero].POS_X+16)))
            {
                JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
            }
        }
    }


    if(enemigo[Enemigo_numero].vida>0&&bala_enemigo[Enemigo_numero].flag_lanzado==1&&Jugador1.Estado != CONGELADO && Jugador1.flag_transparente==0 )
    {
        if((Jugador1.POS_Y+23)>(bala_enemigo[Enemigo_numero].SPR_POS_Y+4)&&Jugador1.POS_Y<(bala_enemigo[Enemigo_numero].SPR_POS_Y+4))
        {
            if(((bala_enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_enemigo[Enemigo_numero].POS_X)&&(Jugador1.POS_X+20)<(bala_enemigo[Enemigo_numero].POS_X+16))
                    ||((bala_enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_enemigo[Enemigo_numero].POS_X)&&(Jugador1.POS_X+8)<(bala_enemigo[Enemigo_numero].POS_X+16)))
            {
                JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
                Jugador1.Estado = CONGELADO;   // inicio de la maquina de estado para el ataque                
            }
        }
    }

    if(enemigo[Enemigo_numero].vida>0&&bala_enemigo[Enemigo_numero+5].flag_lanzado==1&&Jugador1.Estado != GOLPE_MUERTE_2)
    {
        if((Jugador1.POS_Y+23)>(bala_enemigo[Enemigo_numero+5].SPR_POS_Y+4)&&Jugador1.POS_Y<(bala_enemigo[Enemigo_numero+5].SPR_POS_Y+4))
        {
            if(((bala_enemigo[Enemigo_numero+5].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_enemigo[Enemigo_numero+5].POS_X)&&(Jugador1.POS_X+20)<(bala_enemigo[Enemigo_numero+5].POS_X+16))
                    ||((bala_enemigo[Enemigo_numero+5].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_enemigo[Enemigo_numero+5].POS_X)&&(Jugador1.POS_X+8)<(bala_enemigo[Enemigo_numero+5].POS_X+16)))
            {
                JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
            }
        }
    }

    if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_GRIS_HIELO)
    {
        if(bala_enemigo[Enemigo_numero].animacion_cont > 0 && bala_enemigo[Enemigo_numero].animacion_cont <= 25)
        {
            Bala_Enemigo(480,Enemigo_numero);
        }
        if(bala_enemigo[Enemigo_numero].animacion_cont > 25&& bala_enemigo[Enemigo_numero].animacion_cont <= 50)
        {
            Bala_Enemigo(481,Enemigo_numero);
        }
        if(bala_enemigo[Enemigo_numero].animacion_cont > 50 && bala_enemigo[Enemigo_numero].animacion_cont <= 75)
        {
            Bala_Enemigo(482,Enemigo_numero);
        }
        if(bala_enemigo[Enemigo_numero].animacion_cont > 75 && bala_enemigo[Enemigo_numero].animacion_cont <= 100)
        {
            Bala_Enemigo(483,Enemigo_numero);
            bala_enemigo[Enemigo_numero].animacion_cont = 0;
        }

        bala_enemigo[Enemigo_numero].animacion_cont++;
    }

    if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_LODO)
    {
        if(bala_enemigo[Enemigo_numero+5].animacion_cont > 0 && bala_enemigo[Enemigo_numero+5].animacion_cont <= 75)
        {
            Bala2_Enemigo(508,Enemigo_numero+5);
        }
        if(bala_enemigo[Enemigo_numero+5].animacion_cont > 75 && bala_enemigo[Enemigo_numero+5].animacion_cont <= 150)
        {
            Bala2_Enemigo(510,Enemigo_numero+5);            
        }
        if(bala_enemigo[Enemigo_numero+5].animacion_cont > 150)
            bala_enemigo[Enemigo_numero+5].animacion_cont = 0;
         bala_enemigo[Enemigo_numero+5].animacion_cont++;
    }

    
    Kunay_Enemigo(Enemigo_numero);
    if(En_Rango == 0)
            enemigo[Enemigo_numero].flag_ataque_estado=0;
 

    switch(enemigo[Enemigo_numero].estado)
    {
        case REPOSO:
            
            enemigo[Enemigo_numero].SPRITE_NUM=0;
            enemigo[Enemigo_numero].SPRITE_W=3;

            if(enemigo[Enemigo_numero].flag_corriendo==1 && enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
            {
                enemigo[Enemigo_numero].estado=CORRER_1;
                enemigo[Enemigo_numero].SPRITE_NUM=0;
                
            }
            if(enemigo[Enemigo_numero].flag_corriendo==1 && enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_LODO)
            {
                enemigo[Enemigo_numero].estado=CORRER_1;
                enemigo[Enemigo_numero].SPRITE_NUM=195;

            }
            
            if(enemigo[Enemigo_numero].flag_corriendo==1 && enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_ESPADA)
            {
                enemigo[Enemigo_numero].estado=CORRER_1;
                enemigo[Enemigo_numero].SPRITE_NUM=96;
                SPRITE_ATTR_temp=enemigo[Enemigo_numero].ATRIBUTO;
               enemigo[Enemigo_numero].SPRITE_W=3;
            }

            if(enemigo[Enemigo_numero].flag_corriendo==1 && enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_KUNAY)
            {
                enemigo[Enemigo_numero].estado=CORRER_1;
                enemigo[Enemigo_numero].SPRITE_NUM=105;
                SPRITE_ATTR_temp=enemigo[Enemigo_numero].ATRIBUTO;
                enemigo[Enemigo_numero].SPRITE_W=3;
            }

            if(enemigo[Enemigo_numero].flag_corriendo==1 && enemigo[Enemigo_numero].Enemigo_tipo== NINJA_GRIS_HIELO)
            {
                enemigo[Enemigo_numero].estado=CORRER_1;
                enemigo[Enemigo_numero].SPRITE_NUM=384;
                SPRITE_ATTR_temp=enemigo[Enemigo_numero].ATRIBUTO;
               enemigo[Enemigo_numero].SPRITE_W=3;
            }

            if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_PASAMANOS && enemigo[Enemigo_numero].vida > 0)
            {
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].estado=PASAMANOS_1;
                enemigo[Enemigo_numero].contador_eventos2=0;
                enemigo[Enemigo_numero].contador_eventos=0;
                enemigo[Enemigo_numero].ir_derecha =0;
                enemigo[Enemigo_numero].ir_izquierda=1;
            }
            if((enemigo[Enemigo_numero].Enemigo_tipo== NINJA_KUNAY ||enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_KUNAY)&& enemigo[Enemigo_numero].vida > 0 && enemigo[Enemigo_numero].Animacion_General > 500)
            {
                enemigo[Enemigo_numero].MAP_POS_Y = enemigo[Enemigo_numero].POS_Y_CONT;
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].flag_saltando=1;
                enemigo[Enemigo_numero].estado=BALA_SALTANDO_1;
                enemigo[Enemigo_numero].contador_eventos2=0;
                enemigo[Enemigo_numero].Index_caida=0;
            }

            break;

        case CORRER_1:
            if(enemigo[Enemigo_numero].flag_ataque_estado==1&&enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
            {
                enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_1;
                enemigo[Enemigo_numero].Animacion_General=0;
            }

            if(enemigo[Enemigo_numero].Animacion_General>30)
            {
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=0;
                }
                    
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_ESPADA)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=96;
                }

                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_GRIS_HIELO)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=387;
                }

                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_KUNAY)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=105;
                }

                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_LODO)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=195;
                }
                enemigo[Enemigo_numero].SPRITE_W=3;
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].estado = CORRER_2;
                enemigo[Enemigo_numero].estado_anterior=CORRER_2;
            }
            break;

        case CORRER_2:
            if(enemigo[Enemigo_numero].flag_ataque_estado==1&&enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
            {
                enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_1;
                enemigo[Enemigo_numero].Animacion_General=0;
            }
            if(enemigo[Enemigo_numero].Animacion_General>30)
            {
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=3;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_ESPADA)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=99;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_GRIS_HIELO)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=390;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_LODO)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=198;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_KUNAY)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=108;
                }
                enemigo[Enemigo_numero].SPRITE_W=3;
                enemigo[Enemigo_numero].Animacion_General=0;
                if(enemigo[Enemigo_numero].estado_anterior==CORRER_3)
                    enemigo[Enemigo_numero].estado = CORRER_1;
                if(enemigo[Enemigo_numero].estado_anterior==CORRER_2)
                    enemigo[Enemigo_numero].estado = CORRER_3;
            }

            break;
        case CORRER_3:
            if(enemigo[Enemigo_numero].flag_ataque_estado==1&&enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
            {
                enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_1;
                enemigo[Enemigo_numero].Animacion_General=0;
            }           

            if(enemigo[Enemigo_numero].Animacion_General>30)
            {
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_ESPADA)
                {

                    enemigo[Enemigo_numero].SPRITE_NUM=6;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_ESPADA)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=102;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_GRIS_HIELO)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=393;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_LODO)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=201;
                }
                if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_MORADO_KUNAY)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=111;
                }
                   SPRITE_ATTR_temp=enemigo[Enemigo_numero].ATRIBUTO;
                   enemigo[Enemigo_numero].SPRITE_W=3;

                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].estado = CORRER_2;
                enemigo[Enemigo_numero].estado_anterior=CORRER_3;
            }
            if(enemigo[Enemigo_numero].POS_Y > (Jugador1.POS_Y-8) && enemigo[Enemigo_numero].POS_Y < (Jugador1.POS_Y+27) &&(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_GRIS_HIELO )&& bala_enemigo[Enemigo_numero].flag_lanzado==0)
                enemigo[Enemigo_numero].estado = BALA_REPOSO_1;
            if(enemigo[Enemigo_numero].POS_Y > (Jugador1.POS_Y-8) && enemigo[Enemigo_numero].POS_Y < (Jugador1.POS_Y+27) &&enemigo[Enemigo_numero].Enemigo_tipo == NINJA_CAFE_LODO&& bala_enemigo[Enemigo_numero+1].flag_lanzado==0)
                enemigo[Enemigo_numero].estado = BALA_REPOSO_2;
            if(enemigo[Enemigo_numero].POS_Y > (Jugador1.POS_Y-8) && enemigo[Enemigo_numero].POS_Y < (Jugador1.POS_Y+27) &&enemigo[Enemigo_numero].Enemigo_tipo == NINJA_MORADO_KUNAY&& bala_enemigo[Enemigo_numero+1].flag_lanzado==0)
                enemigo[Enemigo_numero].estado = BALA_REPOSO_3;
            break;

        case ATAQUE_DETENIDO_1:
            if(enemigo[Enemigo_numero].flag_ataque_estado==0)
            {
                enemigo[Enemigo_numero].estado = REPOSO;
                enemigo[Enemigo_numero].SPRITE_NUM=17;
                enemigo[Enemigo_numero].ATRIBUTO=SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8);
                enemigo[Enemigo_numero].SPRITE_W=4;

            }
            if(enemigo[Enemigo_numero].Animacion_General>30)
            {                
                enemigo[Enemigo_numero].SPRITE_NUM=9;

                enemigo[Enemigo_numero].SPRITE_W=4;
                enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_2;
                enemigo[Enemigo_numero].Animacion_General=0;
            }
            break;
        case ATAQUE_DETENIDO_2:
            if(enemigo[Enemigo_numero].Animacion_General>30)
            {                
                enemigo[Enemigo_numero].SPRITE_NUM=13;
                enemigo[Enemigo_numero].SPRITE_W=4;
                enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_3;
                enemigo[Enemigo_numero].Animacion_General=0;
            }
            break;
        case ATAQUE_DETENIDO_3:
            if(enemigo[Enemigo_numero].Animacion_General>30)
            {
                enemigo[Enemigo_numero].SPRITE_NUM=17;
                enemigo[Enemigo_numero].SPRITE_W=4;
                enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_1;
                enemigo[Enemigo_numero].Animacion_General=0;
                 enemigo[Enemigo_numero].flag_ataque_estado=0;
            }
            break;

        case BALA_REPOSO_1:
            
            if(bala_enemigo[Enemigo_numero].flag_lanzado == 0 && enemigo[Enemigo_numero].POS_Y > (Jugador1.POS_Y-8) && enemigo[Enemigo_numero].POS_Y < (Jugador1.POS_Y+27))
            {
                if(En_Rango==1 && enemigo[Enemigo_numero].flag_lanzando_chunche==0)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=384;
                    enemigo[Enemigo_numero].flag_lanzando_chunche=1;
                    bala_enemigo[Enemigo_numero].flag_lanzado = 1;
                    bala_enemigo[Enemigo_numero].flag_origen = 1;
                    bala_enemigo[Enemigo_numero].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                    bala_enemigo[Enemigo_numero].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                    bala_enemigo[Enemigo_numero].POS_X = enemigo[Enemigo_numero].POS_X;
                    bala_enemigo[Enemigo_numero].POS_Y = enemigo[Enemigo_numero].POS_Y+8;
                }
                
            }
            if(enemigo[Enemigo_numero].Animacion_General>100)
            {
                enemigo[Enemigo_numero].flag_lanzando_chunche=0;
                 enemigo[Enemigo_numero].estado = REPOSO;
                 enemigo[Enemigo_numero].Animacion_General=0;
                 enemigo[Enemigo_numero].flag_ataque_estado=0;
            }

            break;

        case BALA_REPOSO_2:
                if(bala_enemigo[Enemigo_numero+5].flag_lanzado == 0 && enemigo[Enemigo_numero].POS_Y > (Jugador1.POS_Y-8) && enemigo[Enemigo_numero].POS_Y < (Jugador1.POS_Y+27))
                {
                    if(En_Rango==1 && enemigo[Enemigo_numero].flag_lanzando_chunche==0)
                    {
                        enemigo[Enemigo_numero].SPRITE_NUM=207;
                        enemigo[Enemigo_numero].flag_lanzando_chunche=1;
                        bala_enemigo[Enemigo_numero+5].flag_lanzado = 1;
                        bala_enemigo[Enemigo_numero+5].flag_origen = 1;
                        bala_enemigo[Enemigo_numero+5].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        bala_enemigo[Enemigo_numero+5].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        bala_enemigo[Enemigo_numero+5].POS_X = enemigo[Enemigo_numero].POS_X;
                        bala_enemigo[Enemigo_numero+5].POS_Y = enemigo[Enemigo_numero].POS_Y+8;
                       
                    }
                }

                if(enemigo[Enemigo_numero].Animacion_General>250)
                {
                    enemigo[Enemigo_numero].flag_lanzando_chunche=0;
                     enemigo[Enemigo_numero].estado = REPOSO;
                     enemigo[Enemigo_numero].Animacion_General=0;
                     enemigo[Enemigo_numero].flag_ataque_estado=0;
                }

                break;
        case BALA_REPOSO_3:
            

            if(enemigo[Enemigo_numero].Animacion_General>0 && enemigo[Enemigo_numero].Animacion_General>=30)
            {
                enemigo[Enemigo_numero].SPRITE_NUM=114;
            }
            if(enemigo[Enemigo_numero].Animacion_General>30 && enemigo[Enemigo_numero].Animacion_General>=60)
            {
                enemigo[Enemigo_numero].SPRITE_NUM=117;
            }
            if(enemigo[Enemigo_numero].Animacion_General>60 && enemigo[Enemigo_numero].Animacion_General>=100)
            {
                if(kunay_enemigo[Enemigo_numero].flag_lanzado == 0 && (enemigo[Enemigo_numero].POS_Y+12) > (Jugador1.POS_Y)&&(enemigo[Enemigo_numero].POS_Y+12) < (Jugador1.POS_Y+24))
                {
                    if(En_Rango==1 && enemigo[Enemigo_numero].flag_lanzando_chunche==0)
                    {
                        enemigo[Enemigo_numero].flag_lanzando_chunche=1;
                        kunay_enemigo[Enemigo_numero].flag_lanzado = 1;
                        kunay_enemigo[Enemigo_numero].flag_origen = 1;
                        kunay_enemigo[Enemigo_numero].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        kunay_enemigo[Enemigo_numero].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        kunay_enemigo[Enemigo_numero].POS_X = enemigo[Enemigo_numero].POS_X;
                        kunay_enemigo[Enemigo_numero].POS_Y = enemigo[Enemigo_numero].POS_Y+8;
                    }

                }
            }
            if(enemigo[Enemigo_numero].Animacion_General>100)
            {
                enemigo[Enemigo_numero].flag_lanzando_chunche=0;
                 enemigo[Enemigo_numero].estado = REPOSO;
                 enemigo[Enemigo_numero].Animacion_General=0;
                 enemigo[Enemigo_numero].flag_ataque_estado=0;
            }

            break;


        case PASAMANOS_1:
            if(enemigo[Enemigo_numero].Animacion_General>40)
            {
                if(kunay_enemigo[Enemigo_numero].flag_lanzado == 0 && (enemigo[Enemigo_numero].POS_Y+12) > (Jugador1.POS_Y)&&(enemigo[Enemigo_numero].POS_Y+12) < (Jugador1.POS_Y+24))
                {
                    if(En_Rango==1 && enemigo[Enemigo_numero].flag_lanzando_chunche==0)
                    {
                        enemigo[Enemigo_numero].flag_lanzando_chunche=1;
                        kunay_enemigo[Enemigo_numero].flag_lanzado = 1;
                        kunay_enemigo[Enemigo_numero].flag_origen = 1;
                        kunay_enemigo[Enemigo_numero].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        kunay_enemigo[Enemigo_numero].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        kunay_enemigo[Enemigo_numero].POS_X = enemigo[Enemigo_numero].POS_X;
                        kunay_enemigo[Enemigo_numero].POS_Y = enemigo[Enemigo_numero].POS_Y+8;
                    }

                }
                
                DrawMegaSprite(0,SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,3,3);

                if (En_Rango == 0)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=17;
                    enemigo[Enemigo_numero].ATRIBUTO=SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8);
                    enemigo[Enemigo_numero].SPRITE_W=3;
                    
                }else
                    enemigo[Enemigo_numero].SPRITE_W=2;

                                    
                if(enemigo[Enemigo_numero].contador_eventos2==0 && En_Rango==1)
                {
                    enemigo[Enemigo_numero].SPRITE_W=2;
                    if(enemigo[Enemigo_numero].ir_derecha==1)
                        enemigo[Enemigo_numero].MAP_POS_X++;
                    if(enemigo[Enemigo_numero].ir_izquierda==1)
                        enemigo[Enemigo_numero].MAP_POS_X--;
                    
                    if(enemigo[Enemigo_numero].contador_eventos==0)
                        enemigo[Enemigo_numero].SPRITE_NUM=210;
                    if(enemigo[Enemigo_numero].contador_eventos==1)
                        enemigo[Enemigo_numero].SPRITE_NUM=212;
                    if(enemigo[Enemigo_numero].contador_eventos==2)
                        enemigo[Enemigo_numero].SPRITE_NUM=214;
                        
                    enemigo[Enemigo_numero].contador_eventos++;

                    if(enemigo[Enemigo_numero].contador_eventos==3)
                    {
                        enemigo[Enemigo_numero].contador_eventos=0;

                        if(enemigo[Enemigo_numero].flag_pasamanos==0 && enemigo[Enemigo_numero].dir_cambio ==1)
                            enemigo[Enemigo_numero].dir_cambio = 0;
                    }

                    if(enemigo[Enemigo_numero].flag_lanzando_chunche == 1)
                    {
                        enemigo[Enemigo_numero].SPRITE_W=2;
                        enemigo[Enemigo_numero].contador_eventos2=1;
                        enemigo[Enemigo_numero].SPRITE_NUM=216;
                        
                    }
                    if(enemigo[Enemigo_numero].flag_pasamanos==0 && enemigo[Enemigo_numero].dir_cambio == 0 && enemigo[Enemigo_numero].mirror == 0 )
                    {
                        enemigo[Enemigo_numero].mirror  = 1;
                        enemigo[Enemigo_numero].dir_cambio = 1;
                        enemigo[Enemigo_numero].ir_derecha=0;
                        enemigo[Enemigo_numero].ir_izquierda=1;

                    }else
                        if(enemigo[Enemigo_numero].flag_pasamanos==0 && enemigo[Enemigo_numero].dir_cambio == 0 && enemigo[Enemigo_numero].mirror == 1)
                        {
                            enemigo[Enemigo_numero].mirror  = 0;
                            enemigo[Enemigo_numero].dir_cambio = 1;
                            enemigo[Enemigo_numero].ir_derecha=1;
                            enemigo[Enemigo_numero].ir_izquierda=0;
                        }

                }

                if(enemigo[Enemigo_numero].flag_lanzando_chunche == 1)
                {
                    if(enemigo[Enemigo_numero].contador_eventos2==1)
                    {
                        enemigo[Enemigo_numero].contador_eventos2=2;
                        enemigo[Enemigo_numero].SPRITE_NUM=218;
                        
                    }else
                    if(enemigo[Enemigo_numero].contador_eventos2==2)
                    {
                        enemigo[Enemigo_numero].contador_eventos2=3;
                        enemigo[Enemigo_numero].SPRITE_NUM=220;
                    }
                }


                if(enemigo[Enemigo_numero].contador_eventos2==3)
                {
                    enemigo[Enemigo_numero].contador_eventos2=0;
                    enemigo[Enemigo_numero].flag_lanzando_chunche=0;
                }



               enemigo[Enemigo_numero].Animacion_General=0;
            }


            break;

        case GOLPE_MUERTE_1:
            enemigo[Enemigo_numero].SPRITE_W=3;
            if(enemigo[Enemigo_numero].Animacion_General>40)
            {              
               enemigo[Enemigo_numero].SPRITE_NUM=291;
               enemigo[Enemigo_numero].Animacion_General=0;
               enemigo[Enemigo_numero].estado = GOLPE_MUERTE_2;
            }
            if(enemigo[Enemigo_numero].Animacion_General<7&&enemigo[Enemigo_numero].Animacion_General>0)
                enemigo[Enemigo_numero].SPRITE_NUM=Enemigo_SPR;
                
            break;
        case GOLPE_MUERTE_2:
            enemigo[Enemigo_numero].SPRITE_W=3;
            if(enemigo[Enemigo_numero].Animacion_General>40)
            {
               enemigo[Enemigo_numero].SPRITE_NUM=294;
               enemigo[Enemigo_numero].Animacion_General=0;
               enemigo[Enemigo_numero].estado = GOLPE_MUERTE_3;
            }
            if(enemigo[Enemigo_numero].Animacion_General<37&&enemigo[Enemigo_numero].Animacion_General>30)
                enemigo[Enemigo_numero].SPRITE_NUM=Enemigo_SPR;
                
            break;
        case GOLPE_MUERTE_3:
            enemigo[Enemigo_numero].SPRITE_W=3;
            if(enemigo[Enemigo_numero].Animacion_General>40)
            {
                enemigo[Enemigo_numero].SPRITE_NUM=297;
            }

            if(enemigo[Enemigo_numero].Animacion_General>80)
            {
                enemigo[Enemigo_numero].flag_lanzando_chunche=0;
                kunay_enemigo[Enemigo_numero].flag_lanzado = 0;
                kunay_enemigo[Enemigo_numero].flag_origen = 0;
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].muerto=1;
                enemigo[Enemigo_numero].SPRITE_NUM=297;
                enemigo[Enemigo_numero].ATRIBUTO=SPR_Banco1|((0x0c+(Enemigo_numero*12))<<8);
                enemigo[Enemigo_numero].SPRITE_W=4;
                
            }
            break;

        case BALA_SALTANDO_1:
            if(enemigo[Enemigo_numero].Animacion_General>20)
            {

                enemigo[Enemigo_numero].SPRITE_W=3;
                if(kunay_enemigo[Enemigo_numero].flag_lanzado == 0 && enemigo[Enemigo_numero].POS_Y > (Jugador1.POS_Y)&&enemigo[Enemigo_numero].POS_Y < (Jugador1.POS_Y+24))
                {
                    if(En_Rango==1 && enemigo[Enemigo_numero].flag_lanzando_chunche==0)
                    {
                        enemigo[Enemigo_numero].flag_lanzando_chunche=1;
                        kunay_enemigo[Enemigo_numero].flag_lanzado = 1;
                        kunay_enemigo[Enemigo_numero].flag_origen = 1;
                        kunay_enemigo[Enemigo_numero].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        kunay_enemigo[Enemigo_numero].MAP_POS_Y = VideoScreen.MAP_Scroll_y;
                        kunay_enemigo[Enemigo_numero].POS_X = enemigo[Enemigo_numero].POS_X;
                        kunay_enemigo[Enemigo_numero].POS_Y = enemigo[Enemigo_numero].POS_Y+8;
                    }

                }


                if(enemigo[Enemigo_numero].contador_eventos2==0)
                {
                    if(enemigo[Enemigo_numero].flag_lanzando_chunche == 1)
                        enemigo[Enemigo_numero].contador_eventos2=1;

                    if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_KUNAY)
                        enemigo[Enemigo_numero].SPRITE_NUM=21;
                    if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_KUNAY)
                        enemigo[Enemigo_numero].SPRITE_NUM=120;
                }

                if(enemigo[Enemigo_numero].flag_lanzando_chunche == 1)
                {
                    if(enemigo[Enemigo_numero].contador_eventos2==1)
                    {
                        enemigo[Enemigo_numero].contador_eventos2=2;
                        if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_KUNAY)
                            enemigo[Enemigo_numero].SPRITE_NUM=24;
                        if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_KUNAY)
                            enemigo[Enemigo_numero].SPRITE_NUM=123;
                        
                    }else
                    if(enemigo[Enemigo_numero].contador_eventos2==2)
                    {
                        enemigo[Enemigo_numero].contador_eventos2=3;
                        if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_KUNAY)
                            enemigo[Enemigo_numero].SPRITE_NUM=27;
                        if(enemigo[Enemigo_numero].Enemigo_tipo== NINJA_CAFE_KUNAY)
                            enemigo[Enemigo_numero].SPRITE_NUM=207;
                    }
                }


                if(enemigo[Enemigo_numero].contador_eventos2==3)
                {
                    enemigo[Enemigo_numero].contador_eventos2=0;
                    enemigo[Enemigo_numero].flag_lanzando_chunche=0;
                }

                enemigo[Enemigo_numero].MAP_POS_Y = enemigo[Enemigo_numero].MAP_POS_Y + tabla_salto_largo[enemigo[Enemigo_numero].Index_caida++];


                if(enemigo[Enemigo_numero].Index_caida > POS_Y_MAX) enemigo[Enemigo_numero].Index_caida = POS_Y_MAX;

                if((enemigo[Enemigo_numero].flag_cayendo==0 || enemigo[Enemigo_numero].POS_Y>214)&& enemigo[Enemigo_numero].Index_caida > 10)
                {
                    enemigo[Enemigo_numero].flag_saltando=0;
                    enemigo[Enemigo_numero].estado=REPOSO;
                }
                enemigo[Enemigo_numero].Animacion_General=0;
            }
            break;

        case MUERTE_CAIDA:
            break;

    }
    

    if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H && enemigo[Enemigo_numero].SPRITE_W > 3)
        DrawMegaSprite(enemigo[Enemigo_numero].SPRITE_NUM,enemigo[Enemigo_numero].ATRIBUTO,enemigo[Enemigo_numero].POS_X-8,enemigo[Enemigo_numero].POS_Y,4,3);
    else
        DrawMegaSprite(enemigo[Enemigo_numero].SPRITE_NUM,enemigo[Enemigo_numero].ATRIBUTO,enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,enemigo[Enemigo_numero].SPRITE_W,3);

    AudioOut.FX_enemigo(Enemigo_numero);
}

void OGROMUERTO(int Enemigo_numero)
{
    enemigo[Enemigo_numero].flag_golpeado=1;
    enemigo[Enemigo_numero].vida--;
    enemigo[Enemigo_numero].SPRITE_NUM=316;
    AudioOut.wr_play_fx(tabladefrecuencias[G_2],0x01,30,0x02,0x01);
    enemigo[Enemigo_numero].Animacion_General=0;
    enemigo[Enemigo_numero].contador_eventos=0;
    enemigo[Enemigo_numero].estado=GOLPE_MUERTE_1;
    if(enemigo[Enemigo_numero].vida <= 0)
    {
        enemigo[Enemigo_numero].estado = MUERTE_CAIDA;
        DrawMegaSprite(0,SPR_Banco1|((0x18)<<8),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,4,5);
    }

}



void OGROVERDE(int Enemigo_numero)
{
    int index1_map;
    int Cant_Bloques_De=0;
    int Cant_Bloques_Iz=0;
    int cont=0;
    int comparaciones=0;
    int temp;
    int Enemigo_SPR;
    int SPRITE_NUM_temp;
    unsigned int SPRITE_ATTR_temp;
    int SPRITE_W=3;
    int SPRITE_H=3;

    char En_Rango;
    unsigned int ATTR_TEMP;

    Enemigo_SPR=Deco_enemigo(enemigo[Enemigo_numero].Enemigo_tipo); // se extrae el numero del primer sprite

    enemigo[Enemigo_numero].POS_X = (enemigo[Enemigo_numero].MAP_POS_X-VideoScreen.MAP_Scroll_x)&0x00ff;  // calcula de la posicion respecto al movimiento del jugador
    enemigo[Enemigo_numero].POS_Y = (enemigo[Enemigo_numero].MAP_POS_Y-VideoScreen.MAP_Scroll_y)&0x00ff;

    if ((enemigo[Enemigo_numero].MAP_POS_Y > VideoScreen.MAP_Scroll_y && enemigo[Enemigo_numero].MAP_POS_Y < (VideoScreen.MAP_Scroll_y +200))&&(enemigo[Enemigo_numero].MAP_POS_X > VideoScreen.MAP_Scroll_x && enemigo[Enemigo_numero].MAP_POS_X < (VideoScreen.MAP_Scroll_x +200)))
    {
        En_Rango=1;
        enemigo[Enemigo_numero].visible=1;
    }
    else
    {
        En_Rango=0;
        if(enemigo[Enemigo_numero].visible==1)
        {
            DrawMegaSprite(0,SPR_Banco1|((0x18)<<8),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,4,5);
            enemigo[Enemigo_numero].visible=0;
        }

    }

    

    if (En_Rango==1&&enemigo[Enemigo_numero].muerto==0)
       ATTR_TEMP=SPR_Banco1|SPR_visible|((0x18)<<8);
    else
    {
       ATTR_TEMP=SPR_Banco1|((0x18)<<8);
       enemigo[Enemigo_numero].ATRIBUTO = ATTR_TEMP;
    }

    if (enemigo[Enemigo_numero].ir_derecha == 1)
        enemigo[Enemigo_numero].ATRIBUTO=ATTR_TEMP;
    if (enemigo[Enemigo_numero].ir_izquierda == 1)
        enemigo[Enemigo_numero].ATRIBUTO = SPR_Mirror_H|ATTR_TEMP;

    if(enemigo[Enemigo_numero].AnimacionPosicion > 100 && enemigo[Enemigo_numero].estado == CORRER_1 && enemigo[Enemigo_numero].muerto==0)
    {
        enemigo[Enemigo_numero].AnimacionPosicion=0;
        if (enemigo[Enemigo_numero].ir_derecha==1)
        {
            enemigo[Enemigo_numero].MAP_POS_X++;
            enemigo[Enemigo_numero].POS_X_CONT++;

            if(enemigo[Enemigo_numero].POS_X_CONT > 100)
            {
                enemigo[Enemigo_numero].ir_izquierda = 1;
                enemigo[Enemigo_numero].ir_derecha = 0;
            }
        }


        if (enemigo[Enemigo_numero].ir_izquierda==1)
        {
            enemigo[Enemigo_numero].MAP_POS_X--;
            enemigo[Enemigo_numero].POS_X_CONT--;

            if (enemigo[Enemigo_numero].POS_X_CONT<36)
            {
                enemigo[Enemigo_numero].ir_izquierda = 0;
                enemigo[Enemigo_numero].ir_derecha = 1;
            }

        }

    }


        if(bala_enemigo[5].animacion_cont > 0 && bala_enemigo[5].animacion_cont <= 200)
        {
            Bala2_Enemigo(484,5);
        }
        if(bala_enemigo[5].animacion_cont > 200 && bala_enemigo[5].animacion_cont <= 400)
        {
            Bala2_Enemigo(486,5);
        }
        if(bala_enemigo[5].animacion_cont > 400)
            Bala2_Enemigo(488,5);

        if(bala_enemigo[5].animacion_cont > 600)
            bala_enemigo[5].animacion_cont = 0;


         bala_enemigo[5].animacion_cont++;

        if((enemigo[Enemigo_numero].POS_Y)<(Jugador1.POS_Y+16)&&(enemigo[Enemigo_numero].POS_Y+40)>(Jugador1.POS_Y+16)
                &&enemigo[Enemigo_numero].vida>0)
        {
            if(Jugador1.flag_ataque_estado>0&&enemigo[Enemigo_numero].flag_golpeado==0 && En_Rango==1)
            {
                if(((Jugador1.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(enemigo[Enemigo_numero].POS_X)>(Jugador1.POS_X-29)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+10))||
                        ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0 &&(enemigo[Enemigo_numero].POS_X)>(Jugador1.POS_X+10)&&enemigo[Enemigo_numero].POS_X<(Jugador1.POS_X+30)))
                {
                    OGROMUERTO(Enemigo_numero);
                }
            }
        }


        if((enemigo[Enemigo_numero].POS_Y+40)>(kunay.POS_Y+4)&&enemigo[Enemigo_numero].POS_Y<(kunay.POS_Y+4)&&enemigo[Enemigo_numero].flag_golpeado==0)
        {
            if(kunay.flag_lanzado==1&&kunay.flag_origen==0&&enemigo[Enemigo_numero].vida>0 && En_Rango==1)
            {
                if(((kunay.ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(enemigo[Enemigo_numero].POS_X+20)>(kunay.POS_X)&&(enemigo[Enemigo_numero].POS_X+20)<(kunay.POS_X+16))||
                        ((kunay.ATRIBUTO&SPR_Mirror_H)==0 &&(enemigo[Enemigo_numero].POS_X+8)>(kunay.POS_X)&&(enemigo[Enemigo_numero].POS_X+8)<(kunay.POS_X+16)))
                {
                    OGROMUERTO(Enemigo_numero);
                }
            }
        }


    if(enemigo[Enemigo_numero].vida>0&&bala_enemigo[5].flag_lanzado==1 && Jugador1.Estado != GOLPE_MUERTE_2 && enemigo[Enemigo_numero].visible==1)
    {
        if((Jugador1.flag_agachado==0 &&(Jugador1.POS_Y+28)>(bala_enemigo[5].SPR_POS_Y+4)&&(Jugador1.POS_Y-4)<(bala_enemigo[5].SPR_POS_Y+4))||
           (Jugador1.flag_agachado==1 &&(Jugador1.POS_Y+24)>(bala_enemigo[5].SPR_POS_Y+4)&&(Jugador1.POS_Y+4)<(bala_enemigo[5].SPR_POS_Y+4)))
        {
            if(((bala_enemigo[5].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H &&(Jugador1.POS_X+20)>(bala_enemigo[5].POS_X)&&(Jugador1.POS_X+20)<(bala_enemigo[5].POS_X+16))
                    ||((bala_enemigo[5].ATRIBUTO&SPR_Mirror_H)==0 &&(Jugador1.POS_X+8)>(bala_enemigo[5].POS_X)&&(Jugador1.POS_X+8)<(bala_enemigo[5].POS_X+16)))
            {
                JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
            }
        }
    }



        if(enemigo[Enemigo_numero].vida > 0&& enemigo[Enemigo_numero].visible==1 && (((enemigo[Enemigo_numero].POS_Y)<(Jugador1.POS_Y+12)&&(enemigo[Enemigo_numero].POS_Y+40)>(Jugador1.POS_Y+12))))
        {

            if(((enemigo[Enemigo_numero].POS_X+8)>(Jugador1.POS_X)&&(enemigo[Enemigo_numero].POS_X+8)<(Jugador1.POS_X+24))||
                    ((enemigo[Enemigo_numero].POS_X+24)>(Jugador1.POS_X)&&(enemigo[Enemigo_numero].POS_X+24)<(Jugador1.POS_X+24)))
            {
                JugadorGolpe(enemigo[Enemigo_numero].ATRIBUTO);
            }

        }


    switch(enemigo[Enemigo_numero].estado)
    {
        case REPOSO:
            enemigo[Enemigo_numero].SPRITE_NUM=300;
            enemigo[Enemigo_numero].contador_eventos=0;
            if(enemigo[Enemigo_numero].Animacion_General>500)
            {
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].estado = CORRER_1;
            }
            break;

        case CORRER_1:
            if(enemigo[Enemigo_numero].Animacion_General>260)
            {                
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].contador_eventos++;                
                if(enemigo[Enemigo_numero].contador_eventos==1)
                    enemigo[Enemigo_numero].SPRITE_NUM=304;
                if(enemigo[Enemigo_numero].contador_eventos==2)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=300;
                    if(En_Rango==1)
                        AudioOut.wr_play_fx(tabladefrecuencias[F_4],0x01,30,0x07,0x04);
                }
                if(enemigo[Enemigo_numero].contador_eventos==3)
                    enemigo[Enemigo_numero].SPRITE_NUM=308;
                if(enemigo[Enemigo_numero].contador_eventos==4)
                {
                    enemigo[Enemigo_numero].SPRITE_NUM=300;
                    enemigo[Enemigo_numero].contador_eventos=0;
                    if(En_Rango==1)
                        AudioOut.wr_play_fx(tabladefrecuencias[G_4],0x01,30,0x07,0x04);
                }                    
            }

            if( (enemigo[Enemigo_numero].POS_Y) < (Jugador1.POS_Y) && (enemigo[Enemigo_numero].POS_Y+48) > Jugador1.POS_Y)
            {
                    if(bala_enemigo[5].flag_lanzado == 0)
                    {
                        enemigo[Enemigo_numero].SPRITE_NUM=312;
                        enemigo[Enemigo_numero].estado = ATAQUE_DETENIDO_1;
                         enemigo[Enemigo_numero].Animacion_General=0;
                         enemigo[Enemigo_numero].flag_lanzando_chunche=0;

                    }
            }

            break;

        case ATAQUE_DETENIDO_1:
                enemigo[Enemigo_numero].SPRITE_NUM=316;
                if(bala_enemigo[5].flag_lanzado == 0 && enemigo[Enemigo_numero].Animacion_General>260)
                {
                    enemigo[Enemigo_numero].Animacion_General=0;
                    if(En_Rango==1 && enemigo[Enemigo_numero].flag_lanzando_chunche==0)
                    {
                        AudioOut.wr_play_fx(tabladefrecuencias[F_3],0x01,32,0x07,0x04);                        
                        enemigo[Enemigo_numero].flag_lanzando_chunche=1;
                        bala_enemigo[5].flag_lanzado = 1;
                        bala_enemigo[5].flag_origen = 0;
                        if ((enemigo[Enemigo_numero].ATRIBUTO&SPR_Mirror_H)==SPR_Mirror_H)
                        {
                            bala_enemigo[5].ATRIBUTO = SPR_visible|SPR_Mirror_H|SPR_Banco1;
                            bala_enemigo[5].POS_X = enemigo[Enemigo_numero].POS_X+8;
                        }
                        else
                        {
                            bala_enemigo[5].ATRIBUTO = SPR_visible|SPR_Banco1;
                            bala_enemigo[5].POS_X = enemigo[Enemigo_numero].POS_X+16;
                        }
                            
                        bala_enemigo[5].MAP_POS_X = VideoScreen.MAP_Scroll_x;
                        bala_enemigo[5].MAP_POS_Y = VideoScreen.MAP_Scroll_y;                        
                        bala_enemigo[5].POS_Y = enemigo[Enemigo_numero].POS_Y+10;
                        enemigo[Enemigo_numero].estado = REPOSO;

                    }
                }
            break;

        case GOLPE_MUERTE_1:
            if(enemigo[Enemigo_numero].Animacion_General > 200)
                enemigo[Enemigo_numero].SPRITE_NUM=304;

            if(enemigo[Enemigo_numero].Animacion_General>500)
            {
                enemigo[Enemigo_numero].flag_golpeado=0;                
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].estado = REPOSO;
                boss.SPRITE_NUM=0;
                boss.SPRITE_NUM1=3;
                boss.SPRITE_NUM2=2;
                boss.SPRITE_NUM3=1;
            }
            break;

        case MUERTE_CAIDA:

            enemigo[Enemigo_numero].muerto=1;
            if(enemigo[Enemigo_numero].contador_eventos < 12)
            {
                DrawMegaSprite(468-(boss.SPRITE_NUM<<1),SPR_Banco1|SPR_visible|(0x1800),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,2,2);
                DrawMegaSprite(468-(boss.SPRITE_NUM1<<1),SPR_Banco1|SPR_visible|(0x1c00),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y+12,2,2);
                DrawMegaSprite(468-(boss.SPRITE_NUM2<<1),SPR_Banco1|SPR_visible|(0x2000),enemigo[Enemigo_numero].POS_X+12,enemigo[Enemigo_numero].POS_Y,2,2);
                DrawMegaSprite(468-(boss.SPRITE_NUM3<<1),SPR_Banco1|SPR_visible|(0x2400),enemigo[Enemigo_numero].POS_X+14,enemigo[Enemigo_numero].POS_Y+16,2,2);
            }

            if(enemigo[Enemigo_numero].Animacion_General>100 && enemigo[Enemigo_numero].contador_eventos < 12)
            {
                enemigo[Enemigo_numero].Animacion_General=0;
                enemigo[Enemigo_numero].contador_eventos++;

                boss.SPRITE_NUM--;
                boss.SPRITE_NUM1--;
                boss.SPRITE_NUM2--;
                boss.SPRITE_NUM3--;
                if(boss.SPRITE_NUM<0)
                {
                    boss.SPRITE_NUM=3;
                    AudioOut.wr_play_fx(tabladefrecuencias[G_3],0x01,30,0x07,0x04);
                }
                if(boss.SPRITE_NUM1<0)
                {
                    boss.SPRITE_NUM1=3;
                }
                if(boss.SPRITE_NUM2<0)
                {
                    boss.SPRITE_NUM2=3;
                    AudioOut.wr_play_fx(tabladefrecuencias[G_3],0x01,30,0x07,0x04);
                }
                if(boss.SPRITE_NUM3<0)
                {
                    boss.SPRITE_NUM3=3;
                }

                if(enemigo[Enemigo_numero].contador_eventos>=12)
                {
                    DrawMegaSprite(468-(boss.SPRITE_NUM<<1),SPR_Banco1|SPR_visible|(0x1800),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM1<<1),SPR_Banco1|SPR_visible|(0x1c00),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y+12,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM2<<1),SPR_Banco1|SPR_visible|(0x2000),enemigo[Enemigo_numero].POS_X+12,enemigo[Enemigo_numero].POS_Y,2,2);
                    DrawMegaSprite(468-(boss.SPRITE_NUM3<<1),SPR_Banco1|SPR_visible|(0x2400),enemigo[Enemigo_numero].POS_X+14,enemigo[Enemigo_numero].POS_Y+16,2,2);

                    DrawMegaSprite(0,SPR_Banco1|((0x18)<<8),enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,4,5);
                }

            }
            break;
    }

   if(En_Rango==1 && enemigo[Enemigo_numero].muerto==0)
    DrawMegaSprite(enemigo[Enemigo_numero].SPRITE_NUM,enemigo[Enemigo_numero].ATRIBUTO,enemigo[Enemigo_numero].POS_X,enemigo[Enemigo_numero].POS_Y,4,5);

    //AudioOut.FX_enemigo(Enemigo_numero);
}

void Lampara_ITEM(int numero)
{
    int index1_map,temp;
    char En_Rango;
    unsigned int ATTR_TEMP;
    if ((lampara[numero].MAP_POS_Y > VideoScreen.MAP_Scroll_y && lampara[numero].MAP_POS_Y < (VideoScreen.MAP_Scroll_y +200))&&(lampara[numero].MAP_POS_X > VideoScreen.MAP_Scroll_x && lampara[numero].MAP_POS_X < (VideoScreen.MAP_Scroll_x +208)))
        En_Rango=1;
    else
        En_Rango=0;

    ATTR_TEMP =((0x3c+(numero*4))<<8);

    lampara[numero].POS_X = (lampara[numero].MAP_POS_X-VideoScreen.MAP_Scroll_x)&0x00ff;  // calcula de la posicion respecto al movimiento del jugador
    lampara[numero].POS_Y = (lampara[numero].MAP_POS_Y-VideoScreen.MAP_Scroll_y+lampara[numero].POS_Y_CONT)&0x00ff;

    if (En_Rango==1&&lampara[numero].reventada==0)
       lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;
    else
       lampara[numero].ATRIBUTO=0|ATTR_TEMP;

    if(lampara[numero].ITEM_VISIBLE==0)  /// agregar una variable para cuando esta en rango  acuerdese de eso
    {
        DrawMegaSprite(478,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
    }
    if( lampara[numero].ITEM_VISIBLE==0 && lampara[numero].reventada==0 && En_Rango==1)
    {
        if ((Jugador1.ATRIBUTO&SPR_Mirror_H)==0)
        {
            if(Jugador1.flag_ataque_estado != 0 && lampara[numero].POS_X < (Jugador1.POS_X+26) && lampara[numero].POS_X > (Jugador1.POS_X+10) )
            {
                if(lampara[numero].POS_Y < (Jugador1.POS_Y+10) && lampara[numero].POS_Y > (Jugador1.POS_Y-8) )
                {
                    lampara[numero].reventada=1;
                    lampara[numero].ITEM_VISIBLE=1;
                    lampara[numero].POS_Y_CONT=0;
                    lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    DrawMegaSprite(478,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
                    lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;
                }
            }
        }
        else
        {
            if(Jugador1.flag_ataque_estado != 0 && lampara[numero].POS_X < (Jugador1.POS_X+10) && lampara[numero].POS_X > (Jugador1.POS_X-22) )
            {
                if(lampara[numero].POS_Y < (Jugador1.POS_Y+10) && lampara[numero].POS_Y > (Jugador1.POS_Y-8) )
                {
                    lampara[numero].reventada=1;
                    lampara[numero].ITEM_VISIBLE=1;
                    lampara[numero].POS_Y_CONT=0;
                    lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    DrawMegaSprite(478,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
                    lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;

                }

            }
        }
    }
    if( lampara[numero].ITEM_VISIBLE==1&&En_Rango==0)
    {
        lampara[numero].ATRIBUTO=0|ATTR_TEMP;
        DrawMegaSprite(478,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
    }

    if( lampara[numero].ITEM_VISIBLE==1&&En_Rango==1)
    {
        lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;
        if (lampara[numero].expiracion>200)
        {
            lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;
        }
        if (lampara[numero].expiracion>210)
        {
            lampara[numero].ATRIBUTO=0|ATTR_TEMP;
        }
        if (lampara[numero].expiracion>220)
        {
            lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;
        }
        if (lampara[numero].expiracion>230)
        {
            lampara[numero].ATRIBUTO=0|ATTR_TEMP;
        }
        if (lampara[numero].expiracion>240)
        {
            lampara[numero].ATRIBUTO=SPR_visible|ATTR_TEMP;
        }
        if (lampara[numero].expiracion>260)
        {
            lampara[numero].expiracion=0;
            lampara[numero].ATRIBUTO=0|ATTR_TEMP;
            lampara[numero].ITEM_VISIBLE=0;
            DrawMegaSprite(478,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
        }
        switch(lampara[numero].ITEM)
        {
            case ITEM_MONEDA:
                if(lampara[numero].Animacion_general > 6)
                {
                    if(lampara[numero].POS_X < (Jugador1.POS_X+20) && lampara[numero].POS_X > (Jugador1.POS_X+3)&&lampara[numero].POS_Y < (Jugador1.POS_Y+24) && lampara[numero].POS_Y > (Jugador1.POS_Y))
                    {
                         lampara[numero].seleccionada=1;
                         lampara[numero].ITEM_VISIBLE=0;
                         Jugador1.Numero_monedas += 250;
                         Jugador1.puntos+=250;
                         lampara[numero].POS_Y_CONT=0;
                         lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    }
                    lampara[numero].expiracion++;
//                     print_txt("ITEM MONEDA",8,4);
                    DrawMegaSprite(480+lampara[numero].spr_contador,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,1,1);
                    index1_map = ((((lampara[numero].POS_X+VideoScreen.Scroll_X+4)>>3))&0x001f) | ((((lampara[numero].POS_Y+VideoScreen.Scroll_Y+8)&0x00f8)>>3)*32);
                    temp=VideoScreen.MAP_1[index1_map];
                    if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
                    {
                        lampara[numero].flag_suelo = 1;
                    }
                    else
                        if(lampara[numero].flag_suelo == 0)
                         lampara[numero].POS_Y_CONT++;
                    lampara[numero].Animacion_general=0;
                    lampara[numero].contador++;
                    if(lampara[numero].contador > 10)
                    {
                        lampara[numero].spr_contador++;
                        if(lampara[numero].spr_contador>2)lampara[numero].spr_contador=0;
                        lampara[numero].contador = 0;
                    }

                }
                break;

            case ITEM_SAKE:
                if(lampara[numero].Animacion_general > 6)
                {
                    if(lampara[numero].POS_X < (Jugador1.POS_X+20) && lampara[numero].POS_X > (Jugador1.POS_X+3)&&lampara[numero].POS_Y < (Jugador1.POS_Y+24) && lampara[numero].POS_Y > (Jugador1.POS_Y))
                    {
                        lampara[numero].seleccionada=1;
                         lampara[numero].ITEM_VISIBLE=0;
                         Jugador1.vida+=3;
                         if (Jugador1.vida>10)Jugador1.vida=10;
                         lampara[numero].POS_Y_CONT=0;
                         lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    }
                    lampara[numero].expiracion++;
                    DrawMegaSprite(483,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,1,1);
                    index1_map = ((((lampara[numero].POS_X+VideoScreen.Scroll_X+4)>>3))&0x001f) | ((((lampara[numero].POS_Y+VideoScreen.Scroll_Y+8)&0x00f8)>>3)*32);
                    temp=VideoScreen.MAP_1[index1_map];
                    if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
                    {
                        lampara[numero].flag_suelo = 1;
                    }
                    else
                        if(lampara[numero].flag_suelo == 0)
                         lampara[numero].POS_Y_CONT++;
                    lampara[numero].Animacion_general=0;

                }
                break;
            case ITEM_DIAMANTE:
                if(lampara[numero].Animacion_general > 6)
                {
                    if(lampara[numero].POS_X < (Jugador1.POS_X+20) && lampara[numero].POS_X > (Jugador1.POS_X+3)&&lampara[numero].POS_Y < (Jugador1.POS_Y+24) && lampara[numero].POS_Y > (Jugador1.POS_Y))
                    {
                        lampara[numero].seleccionada=1;
                         lampara[numero].ITEM_VISIBLE=0;
                         Jugador1.Numero_monedas+=1000;
                         Jugador1.puntos+=1000;
                         lampara[numero].POS_Y_CONT=0;
                         lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    }
                    lampara[numero].expiracion++;
                    DrawMegaSprite(484,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,1,1);
                    index1_map = ((((lampara[numero].POS_X+VideoScreen.Scroll_X+4)>>3))&0x001f) | ((((lampara[numero].POS_Y+VideoScreen.Scroll_Y+8)&0x00f8)>>3)*32);
                    temp=VideoScreen.MAP_1[index1_map];
                    if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
                    {
                        lampara[numero].flag_suelo = 1;
                    }
                    else
                        if(lampara[numero].flag_suelo == 0)
                         lampara[numero].POS_Y_CONT++;
                    lampara[numero].Animacion_general=0;

                }
                break;
            case ITEM_KUNAYS:
                if(lampara[numero].Animacion_general > 6)
                {
                    if(lampara[numero].POS_X < (Jugador1.POS_X+20) && lampara[numero].POS_X > (Jugador1.POS_X+3)&&lampara[numero].POS_Y < (Jugador1.POS_Y+24) && lampara[numero].POS_Y > (Jugador1.POS_Y))
                    {
                        lampara[numero].seleccionada=1;
                         lampara[numero].ITEM_VISIBLE=0;
                         kunay.cantidad+=3;
                         lampara[numero].POS_Y_CONT=0;
                         lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    }
                    lampara[numero].expiracion++;
                    DrawMegaSprite(476,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
                    index1_map = ((((lampara[numero].POS_X+VideoScreen.Scroll_X+4)>>3))&0x001f) | ((((lampara[numero].POS_Y+VideoScreen.Scroll_Y+16)&0x00f8)>>3)*32);
                    temp=VideoScreen.MAP_1[index1_map];
                    if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
                    {
                        lampara[numero].flag_suelo = 1;
                    }
                    else
                        if(lampara[numero].flag_suelo == 0)
                         lampara[numero].POS_Y_CONT++;
                    lampara[numero].Animacion_general=0;

                }
                break;
            case ITEM_JAMON:
                if(lampara[numero].Animacion_general > 6)
                {
                    if(lampara[numero].POS_X < (Jugador1.POS_X+20) && lampara[numero].POS_X > (Jugador1.POS_X+3)&&lampara[numero].POS_Y < (Jugador1.POS_Y+24) && lampara[numero].POS_Y > (Jugador1.POS_Y))
                    {
                        lampara[numero].seleccionada=1;
                         lampara[numero].ITEM_VISIBLE=0;
                         Jugador1.vida+=6;
                         if (Jugador1.vida>10)Jugador1.vida=10;
                         lampara[numero].POS_Y_CONT=0;
                         lampara[numero].ATRIBUTO=0|ATTR_TEMP;
                    }
                    lampara[numero].expiracion++;
                    DrawMegaSprite(414,lampara[numero].ATRIBUTO,lampara[numero].POS_X,lampara[numero].POS_Y,2,2);
                    index1_map = ((((lampara[numero].POS_X+VideoScreen.Scroll_X+4)>>3))&0x001f) | ((((lampara[numero].POS_Y+VideoScreen.Scroll_Y+16)&0x00f8)>>3)*32);
                    temp=VideoScreen.MAP_1[index1_map];
                    if((temp < 68 || (temp > 81 && temp < 84))&&temp!=64&&temp!=65)
                    {
                        lampara[numero].flag_suelo = 1;
                    }
                    else
                        if(lampara[numero].flag_suelo == 0)
                         lampara[numero].POS_Y_CONT++;
                    lampara[numero].Animacion_general=0;

                }
                break;
        }
    }
    AudioOut.FX_lamparas(numero);

}

// </editor-fold>

void Nivel_1_0()
{
    // Control de lamparas en el nivel    
        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);
    

    if(VideoScreen.MAP_Scroll_x >= 80*8  && VideoScreen.MAP_Scroll_x < 81*8)
    {
        Niveles.contador_lamparas=5*3;
        Niveles.MIN_MAP_x = 64*8 ;
        INIT_LAMPARAS(lamparas_nivel1);

    }
    if(VideoScreen.MAP_Scroll_x >= 200*8  && VideoScreen.MAP_Scroll_x < 201*8)
    {
        Niveles.MIN_MAP_x = 192*8 ;
        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel1);
    }
    if(VideoScreen.MAP_Scroll_x >= 340*8  && VideoScreen.MAP_Scroll_x < 341*8)
    {
        Niveles.MIN_MAP_x = 288*8;
        Niveles.contador_lamparas=15*3;
        INIT_LAMPARAS(lamparas_nivel1);
    }
    if (VideoScreen.MAP_Scroll_x >= 484*8 && Jugador1.muerto==0)
    {
        Niveles.estado=3;
        boss.POS_X = 180;
        boss.POS_Y = 160;
        boss.ir_izquierda=1;
        boss.ir_derecha=0;
        boss.estado=0;
        boss.muerto=0;
        boss.vida=10;  // el jefe del nivel uno solo tiene 10 de vida
//        Niveles.numero_enemigos=25*3; // se apuntan a los siguientes 4 enemigos
//        Niveles.enemigos_x_Zona=4;
//        INIT_ENEMIGOS(Enemigos_nivel1);

        Niveles.MIN_MAP_x = 484*8;
        if(Niveles.boss_music_load==0)
        {
            Niveles.boss_music_load=1;
            Niveles.boss_music_play=1;
        }
    }

    if(Niveles.boss_music_play == 1)
    {
        AudioOut.WR_AUDIO_DATA(Pattern_Boss, track_Boss, Pattern_size_Boss,numero_de_canales_Boss, numero_de_patrones_Boss,song_size_Boss);
        AudioOut.wr_play_song(1850,0x01);
        Niveles.boss_music_play = 0;

    }


    // control de enemigos en el nivel,
    if(VideoScreen.MAP_Scroll_x >= 75*8  && VideoScreen.MAP_Scroll_x < 76*8 && Niveles.Enemigos_inicializados==0)
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel1);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_x >= 150*8  && VideoScreen.MAP_Scroll_x < 151*8 && Niveles.Enemigos_inicializados==1)
        {
            Niveles.Enemigos_inicializados=2;
            Niveles.numero_enemigos=8*3; // se apuntan a los siguientes 4 enemigos
            Niveles.enemigos_x_Zona=4;
            INIT_ENEMIGOS(Enemigos_nivel1);
         }else
            if(VideoScreen.MAP_Scroll_x >= 227*8  && VideoScreen.MAP_Scroll_x < 228*8 && Niveles.Enemigos_inicializados==2)
            {
                Niveles.Enemigos_inicializados=3;
                Niveles.numero_enemigos=12*3; // se apuntan a los siguientes 4 enemigos
                Niveles.enemigos_x_Zona=4;
                INIT_ENEMIGOS(Enemigos_nivel1);
            }else
                if(VideoScreen.MAP_Scroll_x >= 319*8  && VideoScreen.MAP_Scroll_x < 320*8 && Niveles.Enemigos_inicializados==3)
                {
                    Niveles.Enemigos_inicializados=4;
                    Niveles.numero_enemigos=16*3; // se apuntan a los siguientes 4 enemigos
                    Niveles.enemigos_x_Zona=4;
                    INIT_ENEMIGOS(Enemigos_nivel1);
                }else
                    if(VideoScreen.MAP_Scroll_x >= 387*8  && VideoScreen.MAP_Scroll_x < 388*8 && Niveles.Enemigos_inicializados==4)
                    {
                        Niveles.Enemigos_inicializados=5;
                        Niveles.numero_enemigos=20*3; // se apuntan a los siguientes 4 enemigos
                        Niveles.enemigos_x_Zona=4;
                        INIT_ENEMIGOS(Enemigos_nivel1);
                    }else
                        if(VideoScreen.MAP_Scroll_x >= 451*8  && VideoScreen.MAP_Scroll_x < 452*8 && Niveles.Enemigos_inicializados==5)
                        {
                            Niveles.Enemigos_inicializados=6;
                            Niveles.numero_enemigos=24*3; // se apuntan a los siguientes 4 enemigos
                            Niveles.enemigos_x_Zona=1;
                            INIT_ENEMIGOS(Enemigos_nivel1);
                        }
    

    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }
    
    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA1,Niveles.MIN_MAP_x,0,MAX_MAP1_x,MAX_MAP1_y);        
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();


}

void Nivel_1_0_boss()
{

    if (Niveles.pausa == 0)
    {
        
//        ENEMIGOS(0);
//        ENEMIGOS(1);
//        ENEMIGOS(2);
//        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA1,Niveles.MIN_MAP_x,0,MAX_MAP1_x,MAX_MAP1_y);   
        if(Jugador1.muerto==1)
        {
            Niveles.MIN_MAP_x = 384*8;            
            Niveles.Enemigos_inicializados=4;
            if(Jugador1.continues > 0)
                Niveles.estado = 2;
            AudioOut.WR_AUDIO_DATA(Pattern_Nivel1, track_Nivel1, Pattern_size_Nivel1,numero_de_canales_Nivel1, numero_de_patrones_Nivel1,song_size_Nivel1);
            AudioOut.wr_play_song(1500,0x01);
            Niveles.boss_music_load=0;                       

        }   

        if(Jugador1.muerto==0)
            boss_nivel1();
    }
    
    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    //AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1    
    if(Jugador1.muerto==0 && boss.muerto == 0)
        control_pausa();

}


void Nivel_2_0()
{
    char buf[10];
    // Control de lamparas en el nivel

        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_x >= 75*8  && VideoScreen.MAP_Scroll_x < 76*8)
    {
        Niveles.contador_lamparas=5*3;        
        INIT_LAMPARAS(lamparas_nivel2);

    }
    if(VideoScreen.MAP_Scroll_x >= 155*8  && VideoScreen.MAP_Scroll_x < 156*8)
    {
        
        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel2);
    }

    if(VideoScreen.MAP_Scroll_x >= 45*8  && VideoScreen.MAP_Scroll_x < 46*8 )
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel2);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_x >= 120*8  && VideoScreen.MAP_Scroll_x < 121*8 )
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel2);
           Niveles.Enemigos_inicializados=2;
        }else
            if(VideoScreen.MAP_Scroll_x >= 220*8  && VideoScreen.MAP_Scroll_x < 221*8 )
            {
               Niveles.numero_enemigos=12*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel2);
               Niveles.Enemigos_inicializados=3;
            }else
                if(VideoScreen.MAP_Scroll_x >= 277*8  && VideoScreen.MAP_Scroll_x < 278*8 )
                {
                   Niveles.numero_enemigos=16*3;
                   Niveles.enemigos_x_Zona=4;
                   INIT_ENEMIGOS(Enemigos_nivel2);
                   Niveles.Enemigos_inicializados=4;
                }else
                    if(VideoScreen.MAP_Scroll_x >= 319*8  && VideoScreen.MAP_Scroll_x < 320*8 )
                    {
                       Niveles.numero_enemigos=20*3;
                       Niveles.enemigos_x_Zona=4;
                       INIT_ENEMIGOS(Enemigos_nivel2);
                       Niveles.Enemigos_inicializados=5;
                    }

    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA2,Niveles.MIN_MAP_x,0,MAX_MAP2_x,MAX_MAP2_y);
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();

//utoa(buf,Jugador1.POS_X,10);
//        print_txt(buf,4,7,BG_NEGRO,BLANCO);
    if(Jugador1.POS_X > 190)
    {
        Jugador1.POS_Y_anterior=0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 50;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 50;
        Limpiar_sprites_mem();        
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        VideoScreen.load_MAP(MAPA3,0,0,MAX_MAP3_x,MAX_MAP3_y);
        VideoScreen.Scroll_MAP(MAPA3,MAX_MAP3_x,MAX_MAP3_y);
        Niveles.opacidad=0;
        Niveles.estado = 6;
    }


}

void Nivel_2_1()
{


        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);

    if(VideoScreen.MAP_Scroll_y >= 115*8  && VideoScreen.MAP_Scroll_y < 116*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel3);

    }
    if(VideoScreen.MAP_Scroll_y >= 187*8  && VideoScreen.MAP_Scroll_y < 189*8)
    {

        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel3);
    }



    if(VideoScreen.MAP_Scroll_y >= 33*8  && VideoScreen.MAP_Scroll_y < 34*8 )
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel3);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_y >= 76*8  && VideoScreen.MAP_Scroll_y < 77*8 )
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel3);
           Niveles.Enemigos_inicializados=2;
        }else
            if(VideoScreen.MAP_Scroll_y >= 122*8  && VideoScreen.MAP_Scroll_y < 123*8 )
            {
               Niveles.numero_enemigos=12*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel3);
               Niveles.Enemigos_inicializados=3;
            }else
                if(VideoScreen.MAP_Scroll_y >= 184*8  && VideoScreen.MAP_Scroll_y < 185*8 )
                {
                   Niveles.numero_enemigos=16*3;
                   Niveles.enemigos_x_Zona=4;
                   INIT_ENEMIGOS(Enemigos_nivel3);
                   Niveles.Enemigos_inicializados=4;
                }else
                    if(VideoScreen.MAP_Scroll_y >= 224*8  && VideoScreen.MAP_Scroll_y < 225*8 )
                    {
                       Niveles.numero_enemigos=20*3;
                       Niveles.enemigos_x_Zona=4;
                       INIT_ENEMIGOS(Enemigos_nivel3);
                       Niveles.Enemigos_inicializados=5;
                    }


    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA3,0,0,MAX_MAP3_x,MAX_MAP3_y);
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();


    if(Jugador1.POS_X >190 && Jugador1.POS_Y > 160)
    {
        Jugador1.POS_Y_anterior=0;
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        VideoScreen.load_MAP(MAPA4,0,0,MAX_MAP4_x,MAX_MAP4_y);
        VideoScreen.Scroll_MAP(MAPA4,MAX_MAP4_x,MAX_MAP4_y);
        Niveles.opacidad=0;
        Niveles.estado = 8;
    }

}
void Nivel_2_2()
{


    Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_x >= 64*8  && VideoScreen.MAP_Scroll_x < 65*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel4);

    }
    if(VideoScreen.MAP_Scroll_x >= 162*8  && VideoScreen.MAP_Scroll_x < 163*8)
    {

        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel4);
    }
    
        if(VideoScreen.MAP_Scroll_x >= 85*8  && VideoScreen.MAP_Scroll_x < 86*8 )
        {
           Niveles.numero_enemigos=4*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel4);
           Niveles.Enemigos_inicializados=2;
        }else
            if(VideoScreen.MAP_Scroll_x >= 138*8  && VideoScreen.MAP_Scroll_x < 139*8 )
            {
               Niveles.numero_enemigos=8*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel4);
               Niveles.Enemigos_inicializados=3;
            }


    if(VideoScreen.MAP_Scroll_x >= 228*8  && VideoScreen.MAP_Scroll_x < 229*8 && Jugador1.muerto==0)
    {
        Niveles.MIN_MAP_x = 288*8;
        Niveles.estado=10;
        boss.POS_X = 180;
        boss.POS_Y = 152;
        boss.ir_izquierda=1;
        boss.ir_derecha=0;
        boss.estado=0;
        boss.muerto=0;
        boss.vida=15;
//        Niveles.numero_enemigos=25*3; // se apuntan a los siguientes 4 enemigos
//        Niveles.enemigos_x_Zona=4;
//        INIT_ENEMIGOS(Enemigos_nivel1);

        if(Niveles.boss_music_load==0)
        {
            Niveles.boss_music_load=1;
            Niveles.boss_music_play=1;
        }

    }


    if(Niveles.boss_music_play == 1)
    {
        AudioOut.WR_AUDIO_DATA(Pattern_Boss, track_Boss, Pattern_size_Boss,numero_de_canales_Boss, numero_de_patrones_Boss,song_size_Boss);
        AudioOut.wr_play_song(1850,0x01);
        Niveles.boss_music_play = 0;
    }

    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA4,Niveles.MIN_MAP_x,0,MAX_MAP4_x,MAX_MAP4_y);
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();

}

void Nivel_2_0_boss()
{
    if (Niveles.pausa == 0)
    {

        if(boss.muerto==0)
            Jugador1_CONTROL(MAPA4,Niveles.MIN_MAP_x,0,MAX_MAP4_x,MAX_MAP4_y);
        if(Jugador1.muerto==1)
        {
            Niveles.MIN_MAP_x = 0;
            if(Niveles.boss_music_load==1)
            {                
                if(Jugador1.continues > 0)
                Niveles.estado = 9;
                Niveles.boss_music_load=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel2, track_Nivel2, Pattern_size_Nivel2,numero_de_canales_Nivel2, numero_de_patrones_Nivel2,song_size_Nivel2);
                AudioOut.wr_play_song(1500,0x01);
            }
        }        
//        ENEMIGOS(0);
//        ENEMIGOS(1);
//        ENEMIGOS(2);
//        ENEMIGOS(3);
        

        if(Jugador1.muerto==0)
            boss_nivel2();
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1
    if(Jugador1.muerto==0 && boss.muerto == 0)
        control_pausa();
}


void Nivel_3_0()
{
    char buf[10];
    // Control de lamparas en el nivel

        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_x >= 45*8  && VideoScreen.MAP_Scroll_x < 46*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel5);

    }
    if(VideoScreen.MAP_Scroll_x >= 99*8  && VideoScreen.MAP_Scroll_x < 100*8)
    {

        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel5);
    }

    if(VideoScreen.MAP_Scroll_x >= 202*8  && VideoScreen.MAP_Scroll_x < 203*8)
    {

        Niveles.contador_lamparas=15*3;
        INIT_LAMPARAS(lamparas_nivel5);
    }



    if(VideoScreen.MAP_Scroll_x >= 45*8  && VideoScreen.MAP_Scroll_x < 46*8 )
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel5);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_x >= 100*8  && VideoScreen.MAP_Scroll_x < 101*8 )
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel5);
           Niveles.Enemigos_inicializados=2;
        }else
            if(VideoScreen.MAP_Scroll_x >= 150*8  && VideoScreen.MAP_Scroll_x < 151*8 )
            {
               Niveles.numero_enemigos=12*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel5);
               Niveles.Enemigos_inicializados=3;
            }else
                if(VideoScreen.MAP_Scroll_x >= 212*8  && VideoScreen.MAP_Scroll_x < 213*8 )
                {
                   Niveles.numero_enemigos=16*3;
                   Niveles.enemigos_x_Zona=4;
                   INIT_ENEMIGOS(Enemigos_nivel5);
                   Niveles.Enemigos_inicializados=4;
                }
    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA5,Niveles.MIN_MAP_x,0,MAX_MAP5_x,MAX_MAP5_y);
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();

//utoa(buf,Jugador1.POS_X,10);
//        print_txt(buf,4,7,BG_NEGRO,BLANCO);
    if(Jugador1.POS_X > 190)
    {
        VideoScreen.copy_BG_TILES(BG1_TILES,0);
        Jugador1.POS_Y_anterior=0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 164;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 164;
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;        
        Niveles.opacidad=0;
        Niveles.estado = 13;
    }


}

void Nivel_3_1()
{
    char buf[10];
    // Control de lamparas en el nivel

        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_y >= 80*8  && VideoScreen.MAP_Scroll_y < 81*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel6);
    }  

    if(VideoScreen.MAP_Scroll_y >= 78*8  && VideoScreen.MAP_Scroll_y < 79*8 )
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel6);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_y >= 27*8  && VideoScreen.MAP_Scroll_y < 28*8 )
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel6);
           Niveles.Enemigos_inicializados=2;
        }


    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    

    
    if(Jugador1.muerto == 1 && Jugador1.vidas>0)
    {
        
        Jugador1.visible=1;
        //Jugador1.muerto =0;
        VideoScreen.copy_BG_TILES(BG1_TILES,0);
        Jugador1.POS_Y_anterior=0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 164;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 164;
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        Niveles.opacidad=0;
        Niveles.estado = 13;

    }



    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA6,Niveles.MIN_MAP_x,Niveles.MIN_MAP_y,MAX_MAP6_x,MAX_MAP6_y);
    }
    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();

//utoa(buf,Jugador1.POS_X,10);
//        print_txt(buf,4,7,BG_NEGRO,BLANCO);
//utoa(buf,Jugador1.POS_Y,10);
//        print_txt(buf,4,8,BG_NEGRO,BLANCO);
    if(Jugador1.POS_X > 190 && Jugador1.POS_Y <= 110)
    {

        boss.POS_X = 180;
        boss.POS_Y = 168;
        boss.ir_izquierda=1;
        boss.ir_derecha=0;
        boss.estado=DESTRUIR;
        boss.vida=15;
        boss.muerto=0;
        boss.SPRITE_NUM=1;
        boss.SPRITE_NUM1=0;
        boss.SPRITE_NUM2=2;
        boss.SPRITE_NUM3=3;

        boss.contador_eventos2=0;
        boss.contador_eventos=0;
        Jugador1.Estado=REPOSO;

        Niveles.MIN_MAP_y=0;
        Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 136;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 136;
        Jugador1.POS_Y_anterior=0;
        //kunay.cantidad = 0;
        Niveles.MIN_MAP_x=0;

        //Jugador1.vidas=3;
        Jugador1.vida = 10;
        Control1.X_presionado=0;
        Jugador1.contador_eventos=0;
        Niveles.estado=14;
        Niveles.boss_music_load=1;
        Niveles.boss_music_play=1;
        
        
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        VideoScreen.load_MAP(MAPA7,0,0,MAX_MAP7_x,MAX_MAP7_y);
        VideoScreen.Scroll_MAP(MAPA7,MAX_MAP7_x,MAX_MAP7_y);
        Niveles.opacidad=0;
        Niveles.estado = 15;
        recuadro_encabezado();
        AudioOut.WR_AUDIO_DATA(Pattern_Boss, track_Boss, Pattern_size_Boss,numero_de_canales_Boss, numero_de_patrones_Boss,song_size_Boss);
        AudioOut.wr_play_song(1850,0x01);
        Jugador1_CONTROL(MAPA7,Niveles.MIN_MAP_x,0,MAX_MAP7_x,MAX_MAP7_y);

    }

}

void Nivel_3_0_Boss()
{
    if (Niveles.pausa == 0)
    {
       if(boss.estado != DESTRUIR)
            Jugador1_CONTROL(MAPA7,Niveles.MIN_MAP_x,0,MAX_MAP7_x,MAX_MAP7_y);

        if(Jugador1.muerto==1)
        {
            AudioOut.wr_play_fx(0,0x01,0,0x06,0x07);
            Niveles.MIN_MAP_x = 0;
            if(Niveles.boss_music_load==1)
            {
                
                Jugador1.visible=1;
                VideoScreen.copy_BG_TILES(BG1_TILES,0);
                Jugador1.POS_Y_anterior=0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Limpiar_sprites_mem();
                VideoScreen.MAP_Scroll_x=0;
                VideoScreen.MAP_Scroll_y=0;
                Niveles.opacidad=0;
                

                if(Jugador1.continues > 0 && Jugador1.vidas>0)
                Niveles.estado = 13;
                else

                Niveles.boss_music_load=0;
                
            }
        }

         
//        ENEMIGOS(0);
//        ENEMIGOS(1);
//        ENEMIGOS(2);
//        ENEMIGOS(3);


        if(Jugador1.muerto==0)
            boss_nivel3();
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1
    if(Jugador1.muerto==0 && boss.muerto == 0)
        control_pausa();

}



void Nivel_4_0()
{
//    char buf[10];
    // Control de lamparas en el nivel

        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_y >= 19*8  && VideoScreen.MAP_Scroll_y < 30*8 && VideoScreen.MAP_Scroll_x >= 71*8  && VideoScreen.MAP_Scroll_x < 72*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel8);
    }
    if(VideoScreen.MAP_Scroll_y >= 40*8 && VideoScreen.MAP_Scroll_y < 70*8  && VideoScreen.MAP_Scroll_x >= 85*8  && VideoScreen.MAP_Scroll_x < 86*8)
    {
        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel8);
    }
    if(VideoScreen.MAP_Scroll_y >= 70*8  && VideoScreen.MAP_Scroll_x >= 100*8  && VideoScreen.MAP_Scroll_x < 101*8)
    {
        Niveles.contador_lamparas=15*3;
        INIT_LAMPARAS(lamparas_nivel8);
    }

    if( VideoScreen.MAP_Scroll_y < 19*8 && VideoScreen.MAP_Scroll_x >= 41*8  && VideoScreen.MAP_Scroll_x < 42*8)
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel8);
       Niveles.Enemigos_inicializados=1;
    }
       else
        if( VideoScreen.MAP_Scroll_y > 17*8 && VideoScreen.MAP_Scroll_y < 27*8 && VideoScreen.MAP_Scroll_x >= 85*8  && VideoScreen.MAP_Scroll_x < 86*8)
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel8);
           Niveles.Enemigos_inicializados=2;
        }else
            if( VideoScreen.MAP_Scroll_y > 30*8 && VideoScreen.MAP_Scroll_y < 41*8 && VideoScreen.MAP_Scroll_x >= 75*8  && VideoScreen.MAP_Scroll_x < 76*8)
            {
               Niveles.numero_enemigos=12*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel8);
               Niveles.Enemigos_inicializados=2;
            }else
                if( VideoScreen.MAP_Scroll_y > 70*8 && VideoScreen.MAP_Scroll_y < 74*8 && VideoScreen.MAP_Scroll_x >= 100*8 )
                {
                   Niveles.numero_enemigos=16*3;
                   Niveles.enemigos_x_Zona=4;
                   INIT_ENEMIGOS(Enemigos_nivel8);
                   Niveles.Enemigos_inicializados=2;
                }


    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }


    if(Jugador1.Estado == MUERTE_CAIDA && Jugador1.vidas>0)
    {

        Jugador1.visible=1;
        Jugador1.muerto=0;
        Jugador1.Estado = REPOSO;
        //Jugador1.muerto =0;
        VideoScreen.copy_BG_TILES(BG1_TILES,0);
        Jugador1.POS_Y_anterior=0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 90;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 90;
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        Niveles.opacidad=0;
        Niveles.estado = 16;

    }
    if (Niveles.pausa == 0 )
    {
        if( Niveles.estado != 16)
        {
            if(enemigo[0].Enemigo_tipo!=OGRO)
                ENEMIGOS(0);
            else
                OGROVERDE(0);
            if(enemigo[1].Enemigo_tipo!=OGRO)
                ENEMIGOS(1);
            else
                OGROVERDE(1);
            if(enemigo[2].Enemigo_tipo!=OGRO)
                ENEMIGOS(2);
            else
                OGROVERDE(2);
            if(enemigo[3].Enemigo_tipo!=OGRO)
                ENEMIGOS(3);
            else
                OGROVERDE(3);


        }
        Jugador1_CONTROL(MAPA8,Niveles.MIN_MAP_x,Niveles.MIN_MAP_y,MAX_MAP8_x,MAX_MAP8_y);
    }

    

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();

//utoa(buf,Jugador1.POS_X,10);
//        print_txt(buf,4,7,BG_NEGRO,BLANCO);
//utoa(buf,Jugador1.POS_Y,10);
//        print_txt(buf,4,8,BG_NEGRO,BLANCO);
    if(Jugador1.POS_X > 190 && Jugador1.POS_Y <= 110)
    {

        boss.POS_X = 180;
        boss.POS_Y = 168;
        boss.ir_izquierda=1;
        boss.ir_derecha=0;
        boss.muerto=0;
        boss.estado=REPOSO;
        boss.vida=20;


        boss.contador_eventos2=0;
        boss.contador_eventos=0;
        boss.flag_corriendo=1;
        Jugador1.Estado=REPOSO;

        Niveles.MIN_MAP_y=0;
        Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 136;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 136;
        Jugador1.POS_Y_anterior=0;
        //kunay.cantidad = 0;
        Niveles.MIN_MAP_x=0;
        //Jugador1.vidas=3;
        Jugador1.vida = 10;
        Control1.X_presionado=0;
        Jugador1.contador_eventos=0;
        Niveles.estado=18;
        Niveles.boss_music_load=1;
        Niveles.boss_music_play=1;
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        VideoScreen.load_MAP(MAPA9,0,0,MAX_MAP9_x,MAX_MAP9_y);
        VideoScreen.Scroll_MAP(MAPA9,MAX_MAP9_x,MAX_MAP9_y);
        Niveles.opacidad=0;
        Niveles.estado = 18;
        recuadro_encabezado();
        AudioOut.WR_AUDIO_DATA(Pattern_Boss, track_Boss, Pattern_size_Boss,numero_de_canales_Boss, numero_de_patrones_Boss,song_size_Boss);
        AudioOut.wr_play_song(1850,0x01);
    }


}


void Nivel_4_0_Boss()
{
    if (Niveles.pausa == 0)
    {
        Jugador1_CONTROL(MAPA9,Niveles.MIN_MAP_x,0,MAX_MAP9_x,MAX_MAP9_y);

        if(Jugador1.muerto==1)
        {
            AudioOut.wr_play_fx(0,0x01,0,0x06,0x07);
            Niveles.MIN_MAP_x = 0;
            if(Niveles.boss_music_load==1)
            {

                Jugador1.visible=1;
                VideoScreen.copy_BG_TILES(BG1_TILES,0);
                Jugador1.POS_Y_anterior=0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Limpiar_sprites_mem();
                VideoScreen.MAP_Scroll_x=0;
                VideoScreen.MAP_Scroll_y=0;
                Niveles.opacidad=0;

                if(Jugador1.continues > 0 && Jugador1.vidas>0)
                Niveles.estado = 16;
                else
                Niveles.boss_music_load=0;

            }
        }


          
//        ENEMIGOS(0);
//        ENEMIGOS(1);
//        ENEMIGOS(2);
//        ENEMIGOS(3);


        if(Jugador1.muerto==0)
            boss_nivel4();
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1
    if(Jugador1.muerto==0 && boss.muerto == 0)
        control_pausa();

}


void Nivel_5_0()
{
    // Control de lamparas en el nivel

        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_x >= 50*8  && VideoScreen.MAP_Scroll_x < 51*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel10);

    }
    if(VideoScreen.MAP_Scroll_x >= 130*8  && VideoScreen.MAP_Scroll_x < 131*8)
    {

        Niveles.contador_lamparas=10*3;
        INIT_LAMPARAS(lamparas_nivel10);
    }





    if(VideoScreen.MAP_Scroll_x >= 60*8  && VideoScreen.MAP_Scroll_x < 61*8 )
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel10);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_x >= 120*8  && VideoScreen.MAP_Scroll_x < 121*8 )
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel10);
           Niveles.Enemigos_inicializados=2;
        }else
            if(VideoScreen.MAP_Scroll_x >= 167*8  && VideoScreen.MAP_Scroll_x < 168*8 )
            {
               Niveles.numero_enemigos=12*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel10);
               Niveles.Enemigos_inicializados=3;
            }

    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA10,Niveles.MIN_MAP_x,Niveles.MIN_MAP_y,MAX_MAP10_x,MAX_MAP10_y);
    }
    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();



    if(Jugador1.POS_X > 190)
    {
        VideoScreen.copy_BG_TILES(BG1_TILES,0);
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        Niveles.opacidad=0;
        Niveles.estado = 21;
    }
}

void Nivel_5_1()
{

    // Control de lamparas en el nivel

        Lampara_ITEM(0);
        Lampara_ITEM(1);
        Lampara_ITEM(2);
        Lampara_ITEM(3);
        Lampara_ITEM(4);


    if(VideoScreen.MAP_Scroll_x >= 150*8  && VideoScreen.MAP_Scroll_x < 151*8)
    {
        Niveles.contador_lamparas=5*3;
        INIT_LAMPARAS(lamparas_nivel11);

    }



    if(VideoScreen.MAP_Scroll_x >= 50*8  && VideoScreen.MAP_Scroll_x < 51*8 )
    {
       Niveles.numero_enemigos=4*3;
       Niveles.enemigos_x_Zona=4;
       INIT_ENEMIGOS(Enemigos_nivel11);
       Niveles.Enemigos_inicializados=1;
    }else
        if(VideoScreen.MAP_Scroll_x >= 100*8  && VideoScreen.MAP_Scroll_x < 101*8 )
        {
           Niveles.numero_enemigos=8*3;
           Niveles.enemigos_x_Zona=4;
           INIT_ENEMIGOS(Enemigos_nivel11);
           Niveles.Enemigos_inicializados=2;
        }else
            if(VideoScreen.MAP_Scroll_x >= 154*8  && VideoScreen.MAP_Scroll_x < 155*8 )
            {
               Niveles.numero_enemigos=12*3;
               Niveles.enemigos_x_Zona=4;
               INIT_ENEMIGOS(Enemigos_nivel11);
               Niveles.Enemigos_inicializados=3;
            }


    if(delay1 > 40)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    if (Niveles.pausa == 0)
    {
        ENEMIGOS(0);
        ENEMIGOS(1);
        ENEMIGOS(2);
        ENEMIGOS(3);
        Jugador1_CONTROL(MAPA11,Niveles.MIN_MAP_x,Niveles.MIN_MAP_y,MAX_MAP11_x,MAX_MAP11_y);
    }
    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

    if (Niveles.pausa == 1 && Jugador1.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(Jugador1.muerto==0)
        control_pausa();



     if(Jugador1.POS_X > 190)
    {
        boss.POS_X = 128;
        boss.POS_Y = 184;
        boss_final.POS_X = 128;
        boss_final.POS_Y = 184;
        boss.ir_izquierda=1;
        boss.ir_derecha=0;
        boss_final.ir_izquierda=1;
        boss_final.ir_derecha=0;
        boss.muerto=0;
        boss.estado=REPOSO;
        boss_final.estado=DIALOGO;
        boss.vida=20;


        boss.contador_eventos2=0;
        boss.contador_eventos=0;
        boss_final.contador_eventos=0;
        boss.flag_corriendo=1;
        Jugador1.Estado=REPOSO;

        Niveles.MIN_MAP_y=0;
        Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
        Jugador1.POS_X = 0;
        Jugador1.POS_Y = 184;
        Jugador1.POS_X_INIT = 0;
        Jugador1.POS_Y_INIT = 184;
        Jugador1.POS_Y_anterior=0;
        //kunay.cantidad = 0;
        Niveles.MIN_MAP_x=0;
        //Jugador1.vidas=3;
        Jugador1.vida = 10;
        Control1.X_presionado=0;
        Jugador1.contador_eventos=0;
        Niveles.boss_sec=0;

        Niveles.boss_music_load=1;
        Niveles.boss_music_play=1;
        Limpiar_sprites_mem();
        VideoScreen.MAP_Scroll_x=0;
        VideoScreen.MAP_Scroll_y=0;
        VideoScreen.load_MAP(MAPA12,0,0,MAX_MAP12_x,MAX_MAP12_y);
        VideoScreen.Scroll_MAP(MAPA12,MAX_MAP12_x,MAX_MAP12_y);
        Niveles.opacidad=0;
        Niveles.estado = 23;
        recuadro_encabezado();
        AudioOut.WR_AUDIO_DATA(Pattern_intro, track_intro, Pattern_size_intro,numero_de_canales_intro, numero_de_patrones_intro,song_size_intro);
        AudioOut.wr_play_song(1500,0x01);
        Jugador1_CONTROL(MAPA12,Niveles.MIN_MAP_x,0,MAX_MAP12_x,MAX_MAP12_y);
    }

}

void Nivel_5_0_Boss()
{
    if (Niveles.pausa == 0)
    {

        if(boss_final.estado != DIALOGO)
          Jugador1_CONTROL(MAPA12,Niveles.MIN_MAP_x,0,MAX_MAP12_x,MAX_MAP12_y);
        if(Jugador1.muerto==1)
        {
            AudioOut.wr_play_fx(0,0x01,0,0x06,0x07);
            Niveles.MIN_MAP_x = 0;
            if(Niveles.boss_music_load==1)
            {

                Jugador1.visible=1;
                VideoScreen.copy_BG_TILES(BG1_TILES,0);
                Jugador1.POS_Y_anterior=0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Limpiar_sprites_mem();
                VideoScreen.MAP_Scroll_x=0;
                VideoScreen.MAP_Scroll_y=0;
                Niveles.opacidad=0;

                if(Jugador1.continues > 0 && Jugador1.vidas>0)
                    Niveles.estado = 21;
                else
                    Niveles.boss_music_load=0;

            }
        }

        
//        ENEMIGOS(0);
//        ENEMIGOS(1);
//        ENEMIGOS(2);
//        ENEMIGOS(3);

          if(Jugador1.muerto==0)
          {  
            boss_nivel5();
          }
        
    }

    if (Niveles.pausa == 1 && Jugador1.muerto==0&&boss_final.muerto==0)
    {
        recuadro_expandible("     Pausa", " Presione START", "");
    }
    if(delay1 > 40&&boss_final.muerto==0)
    {
        Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
        delay1=0;
        //recuadro_encabezado();
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1
    if(Jugador1.muerto==0 && boss.muerto == 0)
        control_pausa();

}

void Final()
{
    int x=0;

     Control1.Habilitar=0;
     if(Niveles.Contador_eventos==0)
     {
         if(Jugador1.Animacion_general>20)
         {
             Jugador1.visible=1;
             Jugador1.Animacion_general=0;
             if(Jugador1.POS_X < 100)
                Niveles.Contador_eventos=1;
             else
             {
                VideoScreen.MAP_Scroll_x++;
                Jugador1.POS_X--;
                read_controller=0;
               read_controller = Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
             }
             VideoScreen.Scroll_MAP(FINAL,MAX_FINAL_x,MAX_FINAL_y);

         }
         DrawMegaSprite(0,Jugador1.ATRIBUTO,Jugador1.POS_X,Jugador1.POS_Y,3,3);
     }


    if(Niveles.Contador_eventos==1)
    {
        read_controller=0;
        read_controller = Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
        if(VideoScreen.MAP_Scroll_x>96)
        {
            read_controller=0;
            //read_controller = Derecha | Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
            read_controller =  Izquierda | Arriba | Abajo | boton_Y | boton_X ;
            AudioOut.wr_play_fx(tabladefrecuencias[E_4],0x01,22,0x01,0x03);
            Niveles.Contador_eventos=2;
        }
    }else
        if(Niveles.Contador_eventos==2)
        {
            read_controller=0;
            read_controller = Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
            if(VideoScreen.MAP_Scroll_x>176)
            {
                read_controller=0;
                //read_controller = Derecha | Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
                read_controller =  Izquierda | Arriba | Abajo | boton_Y | boton_X ;
                AudioOut.wr_play_fx(tabladefrecuencias[E_4],0x01,22,0x01,0x03);
                Niveles.Contador_eventos=3;
            }

        }else
            if(Niveles.Contador_eventos==3)
            {
                read_controller=0;
                read_controller = Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
                if(VideoScreen.MAP_Scroll_x>344)
                {
                    read_controller = 0xffff;

                    Niveles.Contador_eventos=4;
                }

            }

        if(Niveles.Contador_eventos>=4&&Niveles.Contador_eventos<100)
        {
            if(Jugador1.Animacion_general>100)
            {
                Jugador1.Animacion_general=0;
                if((Niveles.Contador_eventos&0x0003)==0)
                    DrawMegaSprite(0,SPR_visible|SPR_Mirror_H|SPR_Banco3|(0x0c<<8),164,126,3,3);
                if((Niveles.Contador_eventos&0x0003)==1)
                    DrawMegaSprite(3,SPR_visible|SPR_Mirror_H|SPR_Banco3|(0x0c<<8),164,126,3,3);
                if((Niveles.Contador_eventos&0x0003)==2)
                    DrawMegaSprite(6,SPR_visible|SPR_Mirror_H|SPR_Banco3|(0x0c<<8),164,126,3,3);
                if((Niveles.Contador_eventos&0x0003)==3)
                    DrawMegaSprite(3,SPR_visible|SPR_Mirror_H|SPR_Banco3|(0x0c<<8),164,126,3,3);
                Niveles.Contador_eventos++;

                if(Niveles.Contador_eventos==20)
                    Dialogo("...Gracias Tatsuko","al asesinarme", "Nauro me Atrapo");
                if(Niveles.Contador_eventos==50)
                    Dialogo("...Pero ahora por","fin soy libre", "...hasta pronto");
                if(Niveles.Contador_eventos==100)
                {
                    Limpiar_sprites_mem();
                    AudioOut.WR_AUDIO_DATA(Pattern_final, track_final, Pattern_size_final,numero_de_canales_final, numero_de_patrones_final,song_size_final);

                }
            }

        }

     if(Niveles.Contador_eventos>=96&&Niveles.Contador_eventos<111)
     {

        if(Jugador1.Animacion_general>100)
        {
            Jugador1.Animacion_general=0;
            if(Niveles.Contador_eventos>=96&&Niveles.Contador_eventos<105)
                DrawMegaSprite((Niveles.Contador_eventos&0x000f)*3,SPR_visible|SPR_Mirror_H|SPR_Banco3|(0x0c<<8),164,126,3,3);
            if(Niveles.Contador_eventos>=105&&Niveles.Contador_eventos<111)
                DrawMegaSprite(((Niveles.Contador_eventos&0x000f)-9)*3+96,SPR_visible|SPR_Mirror_H|SPR_Banco3|(0x0c<<8),164,126,3,3);

            Niveles.Contador_eventos++;
            if(Niveles.Contador_eventos==111)
            {
                Limpiar_sprites_mem();
                Niveles.opacidad=7;
                AudioOut.wr_play_song(1000,0x01);               

            }
        }
        
     }

     if(Niveles.Contador_eventos==111)
     {
         read_controller=0;
         read_controller = Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
         if(Jugador1.POS_X > 190)
         {
             Jugador1.visible=0;
             Limpiar_sprites_mem();
             read_controller = 0xffff;
             Niveles.Contador_eventos=112;
         }

     }

     if(Niveles.Contador_eventos>=112&&Niveles.Contador_eventos<119)
     {
        if(Jugador1.Animacion_general>250)
        {
            Jugador1.Animacion_general=0;
            VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad--);
            Niveles.Contador_eventos++;
           if(Niveles.Contador_eventos==119)
           {
                for(x = 0;x < 1024;x++)// limpiar el mapa
                {
                   VideoScreen.MAP_1[x]=104;
                }
                VideoScreen.copy_BG_TILES(BG1_TILES,8);
                AudioOut.wr_play_song(1500,0x01);
                AudioOut.WR_AUDIO_DATA(Pattern_ending, track_ending, Pattern_size_ending,numero_de_canales_ending, numero_de_patrones_ending,song_size_ending);
                copy_bmp128(7, FINAL_bmp);
           }
            
        }         

     }

     if(Niveles.Contador_eventos==119)
     {
        print_line("La pelea con Nauru habia",0, 2,BG_NEGRO,BLANCO);
        print_line("    llegado a su fin,   ",0, 3,BG_NEGRO,BLANCO);
        print_line("la amenaza que se cernia",0, 4,BG_NEGRO,BLANCO);
        print_line("   sobre Tatsuko habia  ",0, 5,BG_NEGRO,BLANCO);
        print_line("       desaparecido.    ",0, 6,BG_NEGRO,BLANCO);
        print_line(" Nauro habia huido, la  ",0, 7,BG_NEGRO,BLANCO);
        print_line("oscuridad habia poseido ",0, 8,BG_NEGRO,BLANCO);
        print_line(" su corazon, divagando  ",0, 9,BG_NEGRO,BLANCO);
        print_line("    entre la  locura    ",0, 10,BG_NEGRO,BLANCO);
        print_line("  no descansaria hasta  ",0, 11,BG_NEGRO,BLANCO);
        print_line("que la sangre de Tatsuko",0, 12,BG_NEGRO,BLANCO);
        print_line("  impregne la tierra.   ",0, 13,BG_NEGRO,BLANCO);
        if(Jugador1.Animacion_general>15000)
        {
            Niveles.Contador_eventos=120;
            Jugador1.Animacion_general=0;
            Limpiar_sprites_mem();            
        }

     }


     if(Niveles.Contador_eventos>=120 && Niveles.Contador_eventos<123)
     {
        Jugador1.POS_X=13*8;
        Jugador1.POS_Y=18*8;
        Jugador1.visible=1;
        read_controller=0;
        VideoScreen.MAP_Scroll_x=0;
        read_controller = Izquierda | Arriba | Abajo | boton_B | boton_Y | boton_X ;
        if((Jugador1.Animacion_general&0x0c00)==0x0c00)
        {
            read_controller=0;
            read_controller = Izquierda | Arriba | Abajo | boton_B | boton_X ;
        }
        for(x = 0;x < 4;x++)// limpiar el mapa
        {
           VideoScreen.MAP_1[x+684]=x;
           VideoScreen.MAP_1[x+716]=x+16;
        }
     }


     if(Niveles.Contador_eventos==120)
     {
        print_line("        CREDITOS        ",0, 2,BG_NEGRO,ROJO);
        print_line("                        ",0, 3,BG_NEGRO,BLANCO);
        print_line("                        ",0, 4,BG_NEGRO,BLANCO);
        print_line("                        ",0, 5,BG_NEGRO,BLANCO);
        print_line("Esquema de Juego        ",0, 6,BG_NEGRO,GRIS);
        print_line("                        ",0, 7,BG_NEGRO,BLANCO);
        print_line("             ANDRES MB. ",0, 8,BG_NEGRO,VERDE);
        print_line("             FRAN MB.   ",0, 9,BG_NEGRO,AZUL);
        print_line("                        ",0, 10,BG_NEGRO,BLANCO);
        print_line("Dibujo de escenarios    ",0, 11,BG_NEGRO,GRIS);
        print_line("             FRAN MB.   ",0, 12,BG_NEGRO,AZUL);
        print_line("                        ",0, 13,BG_NEGRO,BLANCO);

        if(Jugador1.Animacion_general>20000)
        {
            Niveles.Contador_eventos=121;
            Jugador1.Animacion_general=0;
        }

     }


     if(Niveles.Contador_eventos==121)
     {
        print_line("        CREDITOS        ",0, 2,BG_NEGRO,ROJO);
        print_line("                        ",0, 3,BG_NEGRO,BLANCO);
        print_line("Efectos de sonido       ",0, 4,BG_NEGRO,GRIS);
        print_line("             ANDRES MB. ",0, 5,BG_NEGRO,VERDE);
        print_line("                        ",0, 6,BG_NEGRO,BLANCO);
        print_line("Musica                  ",0, 7,BG_NEGRO,GRIS);
        print_line("             ANDRES MB. ",0, 8,BG_NEGRO,VERDE);
        print_line("                        ",0, 9,BG_NEGRO,BLANCO);
        print_line("Programador             ",0, 10,BG_NEGRO,GRIS);
        print_line("             ANDRES MB. ",0, 11,BG_NEGRO,VERDE);
        print_line("                        ",0, 12,BG_NEGRO,BLANCO);
        print_line("                        ",0, 13,BG_NEGRO,BLANCO);

        if(Jugador1.Animacion_general>20000)
        {
            Niveles.Contador_eventos=122;
            Jugador1.Animacion_general=0;
        }

     }


     if(Niveles.Contador_eventos==122)
     {
        print_line("        CREDITOS        ",0, 2,BG_NEGRO,ROJO);
        print_line("                        ",0, 3,BG_NEGRO,BLANCO);
        print_line("Historia                ",0, 4,BG_NEGRO,GRIS);
        print_line("        JEREMY MB.      ",0, 5,BG_NEGRO,BLANCO);
        print_line("                        ",0, 6,BG_NEGRO,BLANCO);
        print_line("                        ",0, 7,BG_NEGRO,BLANCO);
        print_line("Y un agradecimiento muy ",0, 8,BG_NEGRO,BLANCO);
        print_line("     especial para      ",0, 9,BG_NEGRO,BLANCO);
        print_line("                        ",0, 10,BG_NEGRO,BLANCO);
        print_line("      EDWIN MB.         ",0, 11,BG_NEGRO,BLANCO);
        print_line("                        ",0, 12,BG_NEGRO,BLANCO);
        print_line("   Ya que sin el este   ",0, 13,BG_NEGRO,BLANCO);
        print_line("proyecto igual se habria",0, 14,BG_NEGRO,BLANCO);
        print_line("      terminado         ",0, 15,BG_NEGRO,BLANCO);
        print_line("      JA JA ... :)      ",0, 16,BG_NEGRO,BLANCO);

        if(Jugador1.Animacion_general>20000)
        {
            Niveles.Contador_eventos=123;
            Jugador1.Animacion_general=0;
            Limpiar_sprites_mem();
            Jugador1.visible=0;
        }

     }


     if(Niveles.Contador_eventos==123)
     {
        print_line("                        ",0, 2,BG_NEGRO,BLANCO);
        print_line("                        ",0, 3,BG_NEGRO,BLANCO);
        print_line("                        ",0, 4,BG_NEGRO,BLANCO);
        print_line("                        ",0, 5,BG_NEGRO,BLANCO);
        print_line("                        ",0, 6,BG_NEGRO,BLANCO);
        print_line("                        ",0, 7,BG_NEGRO,BLANCO);
        print_line("                        ",0, 8,BG_NEGRO,BLANCO);
        print_line("    Hasta la proxima    ",0, 9,BG_NEGRO,BLANCO);
        print_line("       aventura         ",0, 10,BG_NEGRO,BLANCO);
        print_line("                        ",0, 11,BG_NEGRO,BLANCO);
        print_line("                        ",0, 12,BG_NEGRO,BLANCO);
        print_line("      FAMBOX 2014       ",0, 13,BG_NEGRO,ROJO);

        if(Jugador1.Animacion_general>30000)
             Niveles.Contador_eventos=124;

     }


    if(Niveles.Contador_eventos>=1 && Jugador1.visible==1)
    {
        Jugador1_CONTROL(FINAL,0,0,MAX_FINAL_x,MAX_FINAL_y);
    }

    AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1
}

int animacion1=0;
int animacion2=0;
int animacion3=0;
int animacion4=0;
char boton_L_precionado=0,boton_R_precionado=0;
    unsigned int cont1=0,cont2=0;
    
   
    char buf[15];

void NINJA_GAME_init()
{

    Jugador1.Estado=REPOSO;
    Niveles.estado=0;    
    Control1.SPR_visibles=1;
    Control1.Habilitar=1;
    
    AudioOut.copy_WAVE(EXPLOSION); 



   /* Jugador1.POS_X_INIT = 0;
           Jugador1.POS_Y_INIT = 164;
    Niveles.estado=13;
        boss.POS_X = 180;
        boss.POS_Y = 160;
        boss.ir_izquierda=1;
        boss.ir_derecha=0;
        boss.estado=0;
        boss.muerto=0;
        boss.vida=10;  // el jefe del nivel uno solo tiene 10 de vida
//        Niveles.numero_enemigos=25*3; // se apuntan a los siguientes 4 enemigos
//        Niveles.enemigos_x_Zona=4;
//        INIT_ENEMIGOS(Enemigos_nivel1);
Niveles.MIN_MAP_x = 480*8;



 Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                kunay.cantidad = 0;
                //Niveles.MIN_MAP_x=0;
                Jugador1.vidas=10;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                //Niveles.estado=2;
                Jugador1.puntos=0;
                Jugador1.flag_transparente=0;
        AudioOut.WR_AUDIO_DATA(Pattern_Boss, track_Boss, Pattern_size_Boss,numero_de_canales_Boss, numero_de_patrones_Boss,song_size_Boss);
        AudioOut.wr_play_song(1850,0x01);
        recuadro_encabezado();
        VideoScreen.load_MAP(MAPA1,Niveles.MIN_MAP_x>>3,Niveles.MIN_MAP_y>>3,MAX_MAP1_x,MAX_MAP1_y);
        
        for (size_t i = Niveles.MIN_MAP_x; i < 3872; i++)
        {
            VideoScreen.Scroll_MAP(MAPA1,MAX_MAP1_x,MAX_MAP1_y);
                VideoScreen.MAP_Scroll_x++;                
        }        
        Niveles.MIN_MAP_x = 484*8;
        Jugador1.continues=5;*/
}
int contador;
void NINJA_GAME_LOOP()
{
    cont1=0;     
        if(delay2 > 80) // anima todos los tiles del juego
        {      
            Animar_tiles(animacion1,animacion2,animacion3,animacion4);
            animacion1++;
            animacion2++;
            animacion3++;
            animacion4++;
            if(animacion1 > 1) animacion1=0;
            if(animacion2 > 2) animacion2=0;
            if(animacion3 > 2) animacion3=0;
            if(animacion4 > 3) animacion4=0;
            delay2=0;

        }
        //Jugador1_CONTROL(MAPA1,MAX_MAP1_x,MAX_MAP1_y);
        if(Niveles.estado==0)
        {
           AudioOut.WR_AUDIO_DATA(Pattern_intro, track_intro, Pattern_size_intro,numero_de_canales_intro, numero_de_patrones_intro,song_size_intro);
           AudioOut.wr_play_song(1500,0x01);
           AudioOut.effect_channel(0, 500);  /// se enciende el reverb en el sonido
           VideoScreen.load_MAP(Presentacion,0,0,MAX_Presentacion_x,MAX_Presentacion_y);
           Jugador1.POS_X_INIT = 0;
           Jugador1.POS_Y_INIT = 164;
           cont1=0;
           while(cont1 < 6)
           {
               draw_TILES(BG1_TILES,160+cont1*16,32,32+cont1*8);
               draw_TILES(BG1_TILES,161+cont1*16,32+8,32+cont1*8);
               draw_TILES(BG1_TILES,162+cont1*16,32+16,32+cont1*8);

               draw_TILES(BG1_TILES,160+cont1*16,176,32+cont1*8);
               draw_TILES(BG1_TILES,161+cont1*16,176+8,32+cont1*8);
               draw_TILES(BG1_TILES,162+cont1*16,176+16,32+cont1*8);
               cont1++;
           }
           
           copy_bmp(0);
           Niveles.opacidad=0;
           Niveles.Contador_eventos=0;
           Jugador1.continues=10;
           Niveles.estado_continue=1;
           Niveles.estado=1;
           Niveles.FAMBOX_cod_cont=0;
        }
        if(Niveles.estado==1)
        {
            if(Jugador1.continues >=3)
                presentacion();
            else
            {
                VideoScreen.copy_BG_TILES(BG1_TILES,7);
                VideoScreen.load_MAP(MAPA1,0,0,MAX_MAP1_x,MAX_MAP1_y);
                Niveles.Enemigos_inicializados=0;
                Niveles.contador_lamparas=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                INIT_LAMPARAS(lamparas_nivel1);
                INIT_ENEMIGOS(Enemigos_nivel1);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=2;
                Jugador1.puntos=0;
                Jugador1.flag_transparente=0;
                recuadro_encabezado();
            }

        }
        if(Niveles.estado==2)
        {
            Nivel_1_0();
        }
        if(Niveles.estado==3)
        {
            Nivel_1_0_boss();
            /*char buf[15];
            String STRdata;
            //disableCore1WDT();
        STRdata = String(contador++,DEC);
                STRdata.toCharArray(buf,15);
                print_txt(buf,9,4,BG_ROJO,BLANCO);*/
        }
        if(Niveles.estado==4)
        {
            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }
            if(Niveles.opacidad == 1)
            {
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;
                                        
                    VideoScreen.load_MAP(MAPA2,0,0,MAX_MAP2_x,MAX_MAP2_y);
                    VideoScreen.Scroll_MAP(MAPA2,MAX_MAP2_x,MAX_MAP2_y);
            }
            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {
                
                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel2);
                INIT_ENEMIGOS(Enemigos_nivel2);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Niveles.estado_continue=4;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=5;
                Jugador1.flag_transparente=0;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel2, track_Nivel2, Pattern_size_Nivel2,numero_de_canales_Nivel2, numero_de_patrones_Nivel2,song_size_Nivel2);
                AudioOut.wr_play_song(1500,0x01);
                AudioOut.effect_channel(0, 500);  /// se enciende el reverb en el sonido

            }


        }
        if(Niveles.estado==5)
        {
            Nivel_2_0();
        }
        if(Niveles.estado==6)
        {
            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }

            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {

                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel3);
                INIT_ENEMIGOS(Enemigos_nivel3);
                
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 50;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 50;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_y=0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=7;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel2, track_Nivel2, Pattern_size_Nivel2,numero_de_canales_Nivel2, numero_de_patrones_Nivel2,song_size_Nivel2);
                AudioOut.wr_play_song(1500,0x01);
            }
             
        }
        if(Niveles.estado==7)
        {
            Nivel_2_1();
        }
        if(Niveles.estado==8)
        {
            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }

            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {

                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel4);
                INIT_ENEMIGOS(Enemigos_nivel4);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;              
                Jugador1.POS_Y_anterior=0;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=9;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel2, track_Nivel2, Pattern_size_Nivel2,numero_de_canales_Nivel2, numero_de_patrones_Nivel2,song_size_Nivel2);
                AudioOut.wr_play_song(1500,0x01);
                AudioOut.effect_channel(1, 300);  /// se enciende el reverb en el sonido

            }

        }
        if(Niveles.estado==9)
        {
            Nivel_2_2();
        }
        
        if(Niveles.estado==10)
        {
            Nivel_2_0_boss();
        }

        if(Niveles.estado==11)
        {
            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }

            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {

                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel5);
                INIT_ENEMIGOS(Enemigos_nivel5);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Jugador1.POS_Y_anterior=0;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=12;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel1, track_Nivel1, Pattern_size_Nivel1,numero_de_canales_Nivel1, numero_de_patrones_Nivel1,song_size_Nivel1);
                AudioOut.wr_play_song(1500,0x01);
                AudioOut.effect_channel(0, 650);  /// se apaga el reverb en el sonido

            }
        }

        if(Niveles.estado==12)
        {
            Nivel_3_0();
        }
        if(Niveles.estado==13)
        {
            if(Niveles.opacidad == 0)
            {
                VideoScreen.load_MAP(MAPA6,0,96,MAX_MAP6_x,MAX_MAP6_y);
                VideoScreen.Scroll_MAP(MAPA6,MAX_MAP6_x,MAX_MAP6_y);
                while(VideoScreen.MAP_Scroll_y<((MAX_MAP6_y<<3)-28*8))// ajuste del scroll en y
                {
                    VideoScreen.MAP_Scroll_y++;
                    VideoScreen.Scroll_MAP(MAPA6,MAX_MAP6_x,MAX_MAP6_y);
                }                            
            }

            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }

            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {

                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel6);
                INIT_ENEMIGOS(Enemigos_nivel6);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Jugador1.POS_Y_anterior=0;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Jugador1.visible=0;
                Jugador1.muerto=0;
                Jugador1.Estado=REPOSO;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=14;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel1, track_Nivel1, Pattern_size_Nivel1,numero_de_canales_Nivel1, numero_de_patrones_Nivel1,song_size_Nivel1);
                AudioOut.wr_play_song(1500,0x01);
            }
        }
        if(Niveles.estado==14)
        {
            Nivel_3_1();            
        }

        if(Niveles.estado == 15)
        {
            Nivel_3_0_Boss();
        }
        if(Niveles.estado == 16)
        {

            if(Niveles.opacidad == 0)
            {
                VideoScreen.load_MAP(MAPA8,0,0,MAX_MAP8_x,MAX_MAP8_y);
                VideoScreen.Scroll_MAP(MAPA8,MAX_MAP8_x,MAX_MAP8_y);
                cont1=0;
                while(cont1<48)
                {
                    VideoScreen.Scroll_MAP(MAPA8,MAX_MAP8_x,MAX_MAP8_y);
                    cont1++;
                    VideoScreen.MAP_Scroll_y++;
                }
            }

            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }

            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {
                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel8);
                INIT_ENEMIGOS(Enemigos_nivel8);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 90;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 90;
                Jugador1.POS_Y_anterior=0;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Jugador1.visible=0;
                Jugador1.muerto=0;
                Jugador1.Estado=REPOSO;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=17;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.wr_play_song(2600,0x01);
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel4, track_Nivel4, Pattern_size_Nivel4,numero_de_canales_Nivel4, numero_de_patrones_Nivel4,song_size_Nivel4);
                AudioOut.effect_channel(1, 500);  /// se enciende el reverb en el sonido
            }

        }
        if(Niveles.estado == 17)
        {
            Nivel_4_0();
        }
        if(Niveles.estado == 18)
        {
            Nivel_4_0_Boss();
        }

        if(Niveles.estado == 19)
        {
            if(Niveles.opacidad == 0)
            {
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;

                    VideoScreen.load_MAP(MAPA10,0,0,MAX_MAP10_x,MAX_MAP10_y);
                    VideoScreen.Scroll_MAP(MAPA10,MAX_MAP10_x,MAX_MAP10_y);
            }
            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }

            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {
                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel10);
                INIT_ENEMIGOS(Enemigos_nivel10);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 164;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 164;
                Jugador1.POS_Y_anterior=0;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                Jugador1.visible=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=20;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel1, track_Nivel1, Pattern_size_Nivel1,numero_de_canales_Nivel1, numero_de_patrones_Nivel1,song_size_Nivel1);
                AudioOut.wr_play_song(1500,0x01);
                AudioOut.effect_channel(0, 650);  /// se apaga el reverb en el sonido
            }            
        }
        if(Niveles.estado == 20)
        {
            Nivel_5_0();
        }
        if(Niveles.estado == 21)
        {
            if(Niveles.opacidad == 0)
            {
                    VideoScreen.MAP_Scroll_x=0;
                    VideoScreen.MAP_Scroll_y=0;

                    VideoScreen.load_MAP(MAPA11,0,0,MAX_MAP11_x,MAX_MAP11_y);
                    VideoScreen.Scroll_MAP(MAPA11,MAX_MAP11_x,MAX_MAP11_y);
            }
            if(boss.Animacion_General>50)
            {
               VideoScreen.copy_BG_TILES(BG1_TILES,Niveles.opacidad++);
               boss.Animacion_General=0;
            }
            Encabezado(Jugador1.vida,kunay.cantidad,Jugador1.Numero_monedas);
            if(Niveles.opacidad > 7)
            {

                Niveles.Enemigos_inicializados=0;
                Niveles.numero_enemigos=0;
                Niveles.enemigos_x_Zona=4;
                Niveles.contador_lamparas=0;
                INIT_LAMPARAS(lamparas_nivel11);
                INIT_ENEMIGOS(Enemigos_nivel11);
                Niveles.MIN_MAP_y=0;
                Jugador1.ATRIBUTO =SPR_visible|SPR_Banco0;
                Jugador1.POS_X = 0;
                Jugador1.POS_Y = 56;
                Jugador1.POS_X_INIT = 0;
                Jugador1.POS_Y_INIT = 56;
                Jugador1.POS_Y_anterior=0;
                //kunay.cantidad = 0;
                Niveles.MIN_MAP_x=0;
                Jugador1.visible=0;
                //Jugador1.vidas=3;
                Jugador1.vida = 10;
                Control1.X_presionado=0;
                Jugador1.contador_eventos=0;
                Niveles.estado=22;
                Niveles.boss_music_load=0;
                Niveles.boss_music_play=0;
                recuadro_encabezado();
                Jugador1.flag_transparente=0;
                AudioOut.WR_AUDIO_DATA(Pattern_Nivel1, track_Nivel1, Pattern_size_Nivel1,numero_de_canales_Nivel1, numero_de_patrones_Nivel1,song_size_Nivel1);
                AudioOut.wr_play_song(1500,0x01);
                AudioOut.effect_channel(0, 650);  /// se apaga el reverb en el sonido
            }

        }

        if(Niveles.estado == 22)
        {
            Nivel_5_1();
        }

        if(Niveles.estado == 23)
        {
            Nivel_5_0_Boss();
        }

        if(Niveles.estado == 24)
        {
            Final();
        }

        AudioOut.FX_jugador1();  // se procesan los efectos de sonido del jugador 1

        if(kunay.cantidad > 99)
            kunay.cantidad = 99;
        if(Jugador1.vidas > 99)
            Jugador1.vidas = 99;
        if(Jugador1.vida > 99)
            Jugador1.vida = 99;
    
}






