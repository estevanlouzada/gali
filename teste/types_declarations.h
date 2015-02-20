#define MAX_X 640
#define MAX_Y 480
#define V_MAX_X 0
#define V_MAX_Y 0
#define COLOR_BITS 32
#define VIDEO_CARD GFX_AUTODETECT_FULLSCREEN
#define DIGI_CARD DIGI_AUTODETECT
#define MIDI_CARD MIDI_AUTODETECT

typedef struct{
   BITMAP *pf;
   int x,y;
   int raio;
   int passo;
}figura;

void init(); //declara a função
void deinit(); //declarando a função

void setfgura(figura *);
void setFigura(figura *fig, char *filename, int x, int y, int raio);//declaranado //fig eh o ponteiro da struc
void printFigura(figura fig);//declarando
void moveFigura(figura *fig, char c);//declarando
void comando_galinha();
void carromovimento();

BITMAP *estrada;
BITMAP* carro;
BITMAP* buffer;

figura fig;
