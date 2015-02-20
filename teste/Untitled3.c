
#include <allegro.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

#include "arquivos.h"
#include "types_declarations.h"
volatile int timer ;//inicializa o timer
int posi_x = 0;
int devagar;
void incrementa_timer() {
    timer ++;
    } //função do tempo  loop ++
END_OF_FUNCTION(incrementa_timer) //volta com esse incrementa timer que eu nao sei par q serve


int main() {      //funcao principal

	init();

    carro = load_bitmap("carroparadireita.bmp" , NULL);  // ponteiro que carega a imagem no jogo
    estrada = load_bitmap("estrada.bmp",NULL);//abrindo a figura
    char *filename = "galinhafrente.bmp";  //declara um ponteiro q chama a figura

    setFigura(&fig, filename, 100, 100, 30); //define o lugar em que ela se encontra
    printFigura(fig);

    //timer na main

    LOCK_FUNCTION(incrementa_timer);//trancando a funçao
    LOCK_VARIABLE(timer);//trancando a variavel (pra q ???)
install_int_ex(incrementa_timer, MSEC_TO_TIMER(1));

  //LOOP PRNCIPAL
	while (!key[KEY_ESC]) {  // essa
		/* put your code here */
       carromovimento();// função do carro
       comando_galinha();
       printFigura(fig);// desenha tudo acada vez que acontece
	}

    destroy_bitmap(estrada);
	deinit();
	return 0;
}
END_OF_MAIN()

  void carromovimento(){
  devagar= timer%0.1;

     }

void comando_galinha(){
if (  (key[KEY_UP])  // se aperta tecla
             || (key[KEY_RIGHT])
             || (key[KEY_DOWN])
             || (key[KEY_LEFT]))
        {
            if (key[KEY_UP]) moveFigura(&fig,'U');   //move oq? (galinha) como(up)
            if (key[KEY_RIGHT]) moveFigura(&fig, 'R');
            if (key[KEY_DOWN]) moveFigura(&fig, 'D');
            if (key[KEY_LEFT]) moveFigura(&fig, 'L');
           // printFigura(fig);

            rest(10);

        }}

void init() {// função do allegro que define as coisas basicas
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);//instal mod grafic ,1º detect drive,2º 3º resolu tela, rest recomend00
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}

void setFigura(figura *fig, char *filename, int x, int y, int raio){  //função
     fig->pf = load_bitmap(filename,NULL);// carrega a imagem
     fig->x = x;  //tamanho
     fig->y = y;  //tamanho
   fig->raio = raio;  //tamanho
}

void printFigura(figura fig){  // sempre imprimindo a figura na tela ao chamar essa função


     buffer = create_bitmap(SCREEN_W, SCREEN_H);
     stretch_blit(estrada, buffer, 0,0,estrada->w, estrada->h,
                  0,0, SCREEN_W, SCREEN_H);  //estica a figura de fundo

     //draw_sprite(buffer, estrada, 0,0);
        draw_sprite(buffer, carro,devagar,0);  //desenha o carro no buffer


     textprintf_centre_ex(buffer, font, SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1,"%d",timer);

     draw_sprite(buffer, fig.pf, fig.x,fig.y);
     blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
     destroy_bitmap(buffer);
}

void moveFigura(figura *fig, char c){   //função que realmente move a figura
     switch (c){
            case 'U':  // up   anda 10 posições
                  fig->y=fig->y-10;
                 break;
            case 'L': //left  nada 10 posições
                 fig->x=fig->x-10;
                 break;
            case 'D':  //dow  anda 10 posições
                 fig->y=fig->y+10;
                 break;
            case 'R':    //right  anda 10 posições
                 fig->x=fig->x+10;
                 break;
     }
}
//variavel

