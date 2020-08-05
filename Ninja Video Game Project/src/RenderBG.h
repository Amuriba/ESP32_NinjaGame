/*this class use de _line buffer to render an image with bagground tiles content*/


class RenderScreen
{
        public: 
        int Width;
        int height;
        int Scroll_X;
        int Scroll_Y;
        int MAP_Scroll_x;
        int MAP_Scroll_y;
        //uint8_t *VideoScreen;
        uint8_t *SpriteVmem;
        int xres;
        int yres;
        uint8_t **frame;
        int cursorX, cursorY, cursorBaseX;
        unsigned int frontColor, backColor;
        uint8_t BG_TILESRAM[16384];
        uint8_t MAP_1[1024];


        //int opacidad = 0x07;       


        void copy_BG_TILES(const uint8_t *Tiles,uint8_t opacidad)
        {
            int cont;
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
            if (opacidad == 8)mascara=0;
            while(cont<16384)
            {
                BG_TILESRAM[cont]=Tiles[cont] & mascara;
                cont++;
            }
        }
        void init_screen(uint8_t **_vbuffimagedata)
        {

            //frame = _vbuffimagedata;  
            frame = _vbuffimagedata; 
            

           // VideoScreen = (uint8_t *)malloc(65536 * sizeof(uint8_t));
            SpriteVmem = (uint8_t *)malloc(50176 * sizeof(uint8_t));
            Scroll_X = 0;
            Scroll_Y = 0;
        }

        void Clear_MAP()
        {
            for(int y = 0; y < 224 ;y++)
            {
                for(int x = 0; x < 224 ;x++)
                {
                    //VideoScreen[x + y * 256] = 0;
                    if(x < 224 && y < 224)
                    {                        
                        SpriteVmem[x+y*224] = 0;                        
                    }
                }
            } 

            for (size_t i = 0; i < yres; i++)
            {
                for (size_t j = 0; j < xres; j++)
                {
                    frame[i][j]=0;
                }
                
            }                   
                   
            Scroll_X = 0;
            Scroll_Y = 0;
        }
        void load_MAP(const unsigned char *MAPA,int MAP_offset_x ,int MAP_offset_y, int MAX_MAP_x, int MAX_MAP_y)// inicializacion del mapa en las coordenadas X,Y
        {
            int x = 0, y = 0;
            
                       
            int y_max;
            int x_max;

            if (MAX_MAP_x <= 28)
            {
                x_max = 28;

            }
            else
                x_max = 32;

            if (MAX_MAP_y <= 28)
            {
                y_max = 28;
            }
            else
                y_max = 32;


            for (y = 0; y < y_max; y++)
            {
                for (x = 0; x < x_max; x++)
                {
                    MAP_1[y * 32 + x] = MAPA[(y + MAP_offset_y) * MAX_MAP_x + x + MAP_offset_x];
                }
            }
            MAP_Scroll_x = MAP_offset_x << 3;
            MAP_Scroll_y = MAP_offset_y << 3;
        }
             
        void Scroll_MAP(const unsigned char *MAPA,int MAX_MAP_x,int MAX_MAP_y)
        {
            int MAP_offset_x;
            int MAP_offset_y;            
            int index_y=0;
            int index_x=0;
            int x,x1,x2,x3,x4;
            int y,y1,y2,y3,y4;
            int y_max;
            int x_max;


            int cont_y;
            int cont_x;
            MAP_offset_x =MAP_Scroll_x>>3;
            MAP_offset_y =MAP_Scroll_y>>3;
            Scroll_X = MAP_Scroll_x&0x00ff;
            Scroll_Y = MAP_Scroll_y&0x00ff;
            
            if (MAX_MAP_x<=28)
            {
                x_max=28;        
            }
            else
            x_max=32;

            if (MAX_MAP_y<=28)
            {
                y_max=28;        
            }
            else
            y_max=32;

            x=Scroll_X>>3;
            x1=(x-1)&0x001f;
            x2=(x-2)&0x001f;
            x3=(x+28)&0x001f;
            x4=(x+29)&0x001f;
            for(cont_y = 0;cont_y < y_max;cont_y++)
            {
                index_y=(cont_y+(Scroll_Y>>3))&0x001f;
                MAP_1[index_y*32|x1]=MAPA[(cont_y+MAP_offset_y)*MAX_MAP_x+MAP_offset_x-1];
                MAP_1[index_y*32|x2]=MAPA[(cont_y+MAP_offset_y)*MAX_MAP_x+MAP_offset_x-2];
                MAP_1[index_y*32|x3]=MAPA[(cont_y+MAP_offset_y)*MAX_MAP_x+MAP_offset_x+28];
                MAP_1[index_y*32|x4]=MAPA[(cont_y+MAP_offset_y)*MAX_MAP_x+MAP_offset_x+29];
            }

            y=Scroll_Y>>3;
            y1=(y-1)&0x001f;
            y2=(y-2)&0x001f;
            y3=(y+28)&0x001f;
            y4=(y+29)&0x001f;
            for(cont_x = 0;cont_x < x_max;cont_x++)
            {
                index_x=(cont_x+(Scroll_X>>3))&0x001f;
                MAP_1[y1*32|index_x]=MAPA[(MAP_offset_y-1)*MAX_MAP_x+MAP_offset_x+cont_x];
                MAP_1[y2*32|index_x]=MAPA[(MAP_offset_y-2)*MAX_MAP_x+MAP_offset_x+cont_x];
                MAP_1[y3*32|index_x]=MAPA[(MAP_offset_y+28)*MAX_MAP_x+MAP_offset_x+cont_x];
                MAP_1[y4*32|index_x]=MAPA[(MAP_offset_y+29)*MAX_MAP_x+MAP_offset_x+cont_x];
            }

            if (MAX_MAP_x<=28)
            {
                x_max=28;
                for(y = 0;y < y_max;y++)
                {
                    for(x = 28;x < 32;x++)
                    {
                    MAP_1[y*32+x]=104;
                    }
                }
            }
            else
            x_max=32;

            if (MAX_MAP_y<=28)
            {
                y_max=28;
                for(y = 28;y < 32;y++)
                {
                    for(x = 0;x < x_max;x++)
                    {
                    MAP_1[y*32+x]=104;
                    }
                }
            }
            else
            y_max=32;           

        }
        
       void DrawScreen(int MAX_MAP_x, int MAX_MAP_y)
       {
            int FineScroll_X = 0;
            int FineScroll_Y = 0;
            int firtsTile_X=0;
            int firtsTile_Y=0;
            


            //Scroll_X = MAP_Scroll_x & 0x00ff;
            //Scroll_Y = MAP_Scroll_y & 0x00ff;

            FineScroll_X = Scroll_X&0x00000007;
            FineScroll_Y = Scroll_Y&0x00000007;
            firtsTile_X = Scroll_X>>3;
            firtsTile_Y = Scroll_Y>>3;
           

            int lineIndex = firtsTile_Y;
            int FinelineIndex = FineScroll_Y;
            int TileCounterX = firtsTile_X;
            int BGindex=0;
            uint8_t SPRpixel =0;
            
            int sprindex =0;
             
            for(int LineCounter = 0; LineCounter< 220; LineCounter++)   
            {               
                for(int tile_index_X = 0; tile_index_X < 32; tile_index_X++)
                {   
                          
                    for (int i = 0; i < 8; i++)
                    {
                         
                        if (tile_index_X < 28)
                        {
                            BGindex = (MAP_1[(lineIndex)*32+TileCounterX]*64) + FineScroll_X + FinelineIndex*8; 
                            //SPRpixel = SpriteVmem[LineCounter * 224 +(tile_index_X<<3)+i];
                            SPRpixel = SpriteVmem[sprindex++];
                            if(SPRpixel == 0)
                                frame[LineCounter+8][(tile_index_X<<3)+i+10] = BG_TILESRAM[BGindex];  
                            else
                                frame[LineCounter+8][(tile_index_X<<3)+i+10] = SPRpixel;                                   
                        }             
                        
                        FineScroll_X++;
                        if(FineScroll_X == 8)
                        {
                            FineScroll_X=0;
                            TileCounterX++;
                        }
                        TileCounterX=TileCounterX&0x001f;
                    }   
                }     
                FinelineIndex++;        
                if (FinelineIndex == 8)
                {
                    FinelineIndex = 0;
                    lineIndex++;  
                }
                lineIndex = lineIndex&0x001f;
            }   
        }       

};