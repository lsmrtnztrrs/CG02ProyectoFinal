/*
	LABORATORIO DE COMPUTACÓN GRÁFICA

		PROYECTO FINAL

			> PARQUE DE DIVERSIONES <

			GRUPO: 02
			SEMESTRE: 2019

			Guzman Esquivel Raul 
			Martinez Torres Luis Martin

			VISUAL STUDIO 2017

*/

/*
TECLAS

		w/w: Mover camara adelante.
		s/S: Mover camara atras.
		a/A: Mover camara izquierda.
		d/D: Mover camara derecha.
		q/Q: Mover camara arriba.
		e/E: Mover camara abajo.
*/	
		

//		<: Rotar camara izquierda.
//		>: Rotar camara derecha.
//		^: Rotar camara arriba.
//		v: Rotar camara abajo.
//
//		i/I: Mover brazos del monito
//		u/U: Mover piernas del monito
//		y/Y: Mover de posicion el mon0
//	    h/H: Mover de posicion el monito
//		j/J: Mover de posicion el monito



//		k/k: Tomar lo Kframes
//		l/L: Reproducir los Kframes guardados

		//SPACE : Comenzar con recorrido de las figuras 3d de los monitos.



#include "Main.h"

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "renders.h"
#include "animaciones.h"
#include "cmodel/CModel.h"




////Solo para Visual Studio 2015
//#if (_MSC_VER == 1900)
//#   pragma comment( lib, "legacy_stdio_definitions.lib" )
//#endif

/* VARIABLES GLOBALES */
static GLuint ciudad_display_list;	//Display List for the Monito
float movX = 0.0f, movY = 0.0f, movZ = 0.0f;
float sideSkyBox = 0.0f;
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;
float movBrazoDer = 0.0;

#define MAX_FRAMES 10
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotRodDer;
	float rotBrazos;
	float rotInc;
	float rotInc2;
	float rotInc3;
	float giroMonito;
	float giroMonitoInc;


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 5;			//introducir datos
bool play = false;
int playIndex = 0;

int rueda = 0;
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis

/* FIN VARIABLES GLOBALES */

/* OBJETOS DE CLASES */
CFiguras figura;
Render renders;
CFiguras obj;
CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito
CCamera camera;
AnimacionSuperman animSuperman;

/* FIN OBJETOS DE CLASES */

/* INICIO LUZ */

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

/* FIN LUZ */

/* INICIO MATERIALES */

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

/* FIN MATERIALES */

/* INICIO TEXTURAS */

CTexture none;
CTexture wood;
CTexture skyBox;
CTexture skyBoxSide;
CTexture tabiqueMarron;
CTexture entradaTabiqueMarron;
CTexture grass;
CTexture asfalto;
CTexture taquilla;
CTexture six;
CTexture super;
CTexture asiento;
CTexture tentaculo;
CTexture DavidJones;
CTexture CuerpoPulpo;
CTexture Ventosa;
CTexture Kraken;
CTexture Cancha;
CTexture Camiseta;
/* FIN TEXTURAS */

/* MODELOS */

CModel kit;
CModel oldhouse;
CModel llanta;
CModel banca;
CModel tree1;
CModel barda;
CModel castle;
CModel trees;
CModel tree;
CModel ent;
CModel avion;
CModel avion1;
CModel barda2;
CModel table;
CModel people;
CModel store;
CModel car;
CModel car2;
CModel car3;
CModel dead_trees;
CModel tienda;
CModel balto;
/* FIN MODELOS */

	//			ANIMACIONES ANIMACION

	//Animación de HURACAN

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

int anim_soporte = 0.0;
int anim_soporte2 = 0.0;

//Animacion Persona
float movKit = 0.0;
float voltear = 90.0;
float rotRodDer = 0.0;
float rotBrazos = 0.0;
bool g_persona = false;
bool g_persona2 = true;

//Animación del coche
float angRot = 0.0;
float movKitX = 0.0;
float movKitZ = 0.0;
float rotKit = 0.0;
float rotTires = 0.0;
bool g_fanimacion = false;
bool g_avanza = false;

bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;

bool avion1Girando = false;
float giroAvion1 = 0.0;

void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
	KeyFrame[FrameIndex].rotRodDer = rotRodDer;
	KeyFrame[FrameIndex].rotBrazos = rotBrazos;
	KeyFrame[FrameIndex].giroMonito = giroMonito;

	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	rotRodIzq = KeyFrame[0].rotRodIzq;
	rotRodDer = KeyFrame[0].rotRodDer;
	rotBrazos = KeyFrame[0].rotBrazos;
	giroMonito = KeyFrame[0].giroMonito;

}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;
	KeyFrame[playIndex].rotInc2 = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;
	KeyFrame[playIndex].rotInc3 = (KeyFrame[playIndex + 1].rotBrazos - KeyFrame[playIndex].rotBrazos) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;

}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, Camiseta.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindroTextura(0.25, 0.25, 15, Camiseta.GLindex);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	glRotatef(15 + rotBrazos, 0, 0, 1);//Girar cabeza
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);//Codo
	glRotatef(15 + rotBrazos, 0, 1, 0);//girar codo
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(-0, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0); //Codo
	glRotatef(15 + rotBrazos, 0, 1, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(0, 0, 1, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodDer, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* CARGA TEXTURAS */

	none.LoadTGA("texturas/none.tga");
	none.BuildGLTexture();
	none.ReleaseImage();

	wood.LoadTGA("texturas/wood2.tga");
	wood.BuildGLTexture();
	wood.ReleaseImage();

	skyBox.LoadTGA("texturas/skyBox.tga");
	skyBox.BuildGLTexture();
	skyBox.ReleaseImage();

	skyBoxSide.LoadTGA("texturas/skyBoxSide.tga");
	skyBoxSide.BuildGLTexture();
	skyBoxSide.ReleaseImage();

	tabiqueMarron.LoadTGA("texturas/tabiqueMarron.tga");
	tabiqueMarron.BuildGLTexture();
	tabiqueMarron.ReleaseImage();

	entradaTabiqueMarron.LoadTGA("texturas/entradaTabiqueMarron.tga");
	entradaTabiqueMarron.BuildGLTexture();
	entradaTabiqueMarron.ReleaseImage();

	grass.LoadTGA("texturas/grass.tga");
	grass.BuildGLTexture();
	grass.ReleaseImage();

	DavidJones.LoadTGA("texturas/DavidJones.tga");
	DavidJones.BuildGLTexture();
	DavidJones.ReleaseImage();

	CuerpoPulpo.LoadTGA("texturas/CuerpoPulpo.tga");
	CuerpoPulpo.BuildGLTexture();
	CuerpoPulpo.ReleaseImage();

	Ventosa.LoadTGA("texturas/Ventosa.tga");
	Ventosa.BuildGLTexture();
	Ventosa.ReleaseImage();

	Kraken.LoadTGA("texturas/Kraken.tga");
	Kraken.BuildGLTexture();
	Kraken.ReleaseImage();

	Cancha.LoadTGA("texturas/Cancha.tga");
	Cancha.BuildGLTexture();
	Cancha.ReleaseImage();

	asfalto.LoadTGA("texturas/asfalto2.tga");
	asfalto.BuildGLTexture();
	asfalto.ReleaseImage();

	taquilla.LoadTGA("texturas/taquilla.tga");
	taquilla.BuildGLTexture();
	taquilla.ReleaseImage();

	six.LoadTGA("texturas/six.tga");
	six.BuildGLTexture();
	six.ReleaseImage();

	super.LoadTGA("texturas/super.tga");
	super.BuildGLTexture();
	super.ReleaseImage();

	asiento.LoadTGA("texturas/asientos2.tga");
	asiento.BuildGLTexture();
	asiento.ReleaseImage();

	Camiseta.LoadTGA("texturas/Camiseta.tga");
	Camiseta.BuildGLTexture();
	Camiseta.ReleaseImage();

	/* FIN CARGA TEXTURAS */

	/* CARGA MODELOS 3DS */

	kit._3dsLoad("3ds/kitt.3ds");

	oldhouse._3dsLoad("3ds/oldhouse/oldhouse.3ds");
	oldhouse.LoadTextureImages();
	oldhouse.GLIniTextures();
	oldhouse.ReleaseTextureImages();

	avion1._3dsLoad((char*)"3ds/Mig_29_3ds.3DS");

	banca._3dsLoad("3ds/b.3ds");
	tree1._3dsLoad("3ds/t.3ds");
	tree._3dsLoad("3ds/tree.3ds");
	barda._3dsLoad("3ds/f.3ds");
	barda._3dsLoad("3ds/f.3ds");
	barda2._3dsLoad("3ds/fence2.3ds");
	ent._3dsLoad("3ds/main.3ds");
	avion._3dsLoad("3ds/airplane.3ds");
	table._3dsLoad("3ds/picnic.3ds");
	people._3dsLoad("3ds/people.3ds");
	dead_trees._3dsLoad("3ds/dead_trees.3ds");
	store._3dsLoad("3ds/store.3ds");
	balto._3dsLoad("3ds/balto.3ds");

	car._3dsLoad("3ds/car.3ds");
	car2._3dsLoad("3ds/car2.3ds");
	car3._3dsLoad("3ds/car3.3ds");

	llanta._3dsLoad("k_rueda.3ds");

	/* FIN CARGA MODELOS 3DS*/

	/*Carga de keyframes*/


	camera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

}


void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();

	glPushMatrix(); // INICIO CAMARA

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(camera.mPos.x, camera.mPos.y, camera.mPos.z,
		camera.mView.x, camera.mView.y, camera.mView.z,
		camera.mUp.x, camera.mUp.y, camera.mUp.z);

	// INICIO AREA DE DIBUJO

	/////////Rueda de la Fortuna///////////////

		//////////Rueda /////////////

	glPushMatrix();
	
	glTranslatef(-5.0f, -6.0f, 9.0);
	glScalef(6, 6, 6);
	glRotatef(40.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(1, 0, 1);

	glPushMatrix();
	glDisable(GL_LIGHTING);

	glBegin(GL_TRIANGLES); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor3f(0, 0, 0);
	glVertex3f(0.0, 0, .5);
	glVertex3f(-1, -4, .5);
	glVertex3f(1, -4, .5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex3f(0.0, 0, -.5);
	glVertex3f(-1, -4, -.5);
	glVertex3f(1, -4, -.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glColor3f(0,1,0);
	glutSolidCube(.75);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(0.0f, 11.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(11.0f, 0.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(-11.0f, 0.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(0.0f, -11.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(8.0f, -8.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(-8.0f, 8.0f, 0.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(-8.0f, -8.0f, 0.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(8.0f, 8.0f, 0.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(1.5, 10, 6);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rueda, 0, 0, 1);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutWireTorus(.5, 2, 3, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0, 0);
	glRotatef(rueda, 0, 0, 1);
	
	glutWireTorus(1, .6, 2, 10);
	glColor3f(1.0f, 1, 1);
	glPopMatrix();

	
	glPopMatrix();

	///////////////////////////////////////////

	//////////////////Avion////////////////

	//Avion
	glPushMatrix();
	glTranslatef(140, 50, -132);
	glRotatef(giroAvion1, 0, 1, 0);
	glRotatef(30, 0, 0, 1);
	figura.cilindro(0.1, -10, 10);
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(0, -10, 0);
	glScalef(0.03, 0.03, 0.03);
	avion1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	///////////////////////////////////////

		/* SKYBOX */

	glPushMatrix();
	glDisable(GL_LIGHTING);
	renders.skyBox(240.0, 60.0, 200.0, skyBox.GLindex, grass.GLindex, skyBoxSide.GLindex, sideSkyBox);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/* FIN SKYBOX */

	//simbolo parque de diversiones 
	glPushMatrix();
	glTranslatef(-85.0f, -29.0f, -20.5f);
	glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	renders.cube(30.0, 0.2, 30.0,
		six.GLindex, six.GLindex, six.GLindex, six.GLindex, six.GLindex, six.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Cancha de Futbol

	glPushMatrix();
	glTranslatef(10.0f, -29.0f, -80.5f);
	//glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	renders.cube(50.0, 0.2, 20.0,
		Cancha.GLindex, Cancha.GLindex, Cancha.GLindex, Cancha.GLindex, Cancha.GLindex, Cancha.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0f, -26.0f, -80.5f);
	//glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	monito();
	glEnable(GL_LIGHTING);
	glPopMatrix();

  
	//		ASFALTO ESTACIONAMIENTO
	glPushMatrix();

	glTranslatef(-102.0f, -30.0f, 75.5f);
	glScalef(35, 0.05, 45);
	glDisable(GL_LIGHTING);
	fig1.prisma2(asfalto.GLindex, 0);
	glEnable(GL_LIGHTING);

	glPopMatrix();	// TERMINA ASFALTO

	

/* EJES DE REFERENCIA */

	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/* FIN EJES DE REFERENCIA */
	
	/* Martillo */
	glPushMatrix();
		glTranslatef(80.0f, -29.0f, -60.0f);
		glDisable(GL_LIGHTING);
		renders.cube(45.0, 1.0, 45.0,
			wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
			wood.GLindex, wood.GLindex, wood.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, -15.0f, -60.0f);
		glDisable(GL_LIGHTING);
		//glRotatef(90, 1, 1, 0);							// Mango del martillo
		obj.prisma(25, 4, 4, Camiseta.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, 0.0f, -60.0f);
		glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);
		
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, 0.0f);
			glDisable(GL_LIGHTING);
			glRotatef(90, 1, 0, 0);							// Cilindro giratorio martillo
			obj.cilindroTextura(3, 3, 12, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0f, -5.0f, 4.0f);
			glDisable(GL_LIGHTING);
			glRotatef(90, 0, 0, 1);							// Martillo giratorio derecho
			obj.prisma(2, 29, 2, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.0f, -22.0f, 4.0f);
			glDisable(GL_LIGHTING);
			//glRotatef(90, 0, 1, 0);							// Cabina del martillo derecho
			renders.cube(15.0, 5.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
				wood.GLindex, asiento.GLindex, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0f, 11.0f, 4.0f);
			glDisable(GL_LIGHTING);
			//glRotatef(90, 0, 1, 0);							// Contrapeso del martillo derecho
			renders.cube(8.0, 3.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
				wood.GLindex, wood.GLindex, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, 0.0f, -60.0f);
		glRotatef(anim_soporte + 50, 0.0, 0.0, -1.0);
		
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, -3.0f);
			glDisable(GL_LIGHTING);
			glRotatef(90, 1, 0, 0);							// Cilindro giratorio martillo
			obj.cilindroTextura(3, 3, 12, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0f, -5.0f, -4.0f);
			glDisable(GL_LIGHTING);
			glRotatef(90, 0, 0, 1);							// Martillo giratorio izquierdo
			obj.prisma(2, 29, 2, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.0f, -22.0f, -4.0f);
			glDisable(GL_LIGHTING);
			//glRotatef(90, 0, 1, 0);							// Cabina del martillo izquierdo
			renders.cube(15.0, 5.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
				wood.GLindex, wood.GLindex, asiento.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0f, 11.0f, -4.0f);
			glDisable(GL_LIGHTING);
			//glRotatef(90, 0, 1, 0);							// Contrapeso del martillo izquierdo
			renders.cube(8.0, 3.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
				wood.GLindex, wood.GLindex, wood.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	/*Fin de rueda del martillo*/

	/* Comienza el pulpo */

	glPushMatrix();
	glTranslatef(80.0f, -29.0f, -10.0f);
	glDisable(GL_LIGHTING);
	renders.cube(45.0, 1.0, 45.0,
		wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
		wood.GLindex, wood.GLindex, wood.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, -25.0f, -10.0f);
		glDisable(GL_LIGHTING);
		renders.cube(25.0, 10.0, 25.0,
			CuerpoPulpo.GLindex, CuerpoPulpo.GLindex, CuerpoPulpo.GLindex,		//	Base del pulpo 
			CuerpoPulpo.GLindex, CuerpoPulpo.GLindex, CuerpoPulpo.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(80.0f, -20.0f, -10.0f);
		glDisable(GL_LIGHTING);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);
		obj.cilindroTextura(15, 1, 12, wood.GLindex);		// Base giratoria del pulpo
		glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(80.0f, -19.0f, -10.0f);
		glDisable(GL_LIGHTING);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);
		obj.cilindroTextura(8, 10, 12, Kraken.GLindex);		// Cuerpo del pulpo
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, -5.0f, -10.0f);
		glDisable(GL_LIGHTING);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);
		obj.esfera(10, 12, 12, DavidJones.GLindex);				// Cabeza del pulpo
		glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix();										// primer tentaculo del pulpo
		glTranslatef(80.0f, -20.0f, -10.0f);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);
		
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(12.0f, 1.0f, 0.0f);			// primer tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(12.0f, 6.0f, 0.0f);			// primer tentaculo del pulpo
			glRotatef(45, 0, 0, -1);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(31.0f, 16.0f, 0.0f);			// primer tentaculo del pulpo
			glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(30.0f, 5.0f, 0.0f);			// primer tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(1, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(30.0f, 3.0f, 0.0f);			// primer tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			glRotatef(anim_soporte + 50, 0.0, -1.0, 0.0);
			renders.cube(10.0, 4.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	Cabina giratoria 
				wood.GLindex, wood.GLindex, asiento.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();										// Segundo tentaculo del pulpo
	glTranslatef(80.0f, -20.0f, -10.0f);
	glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-12.0f, 1.0f, 0.0f);			// Segundo tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-12.0f, 6.0f, 0.0f);			// Segundo tentaculo del pulpo
			glRotatef(45, 0, 0, 1);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-21.0f, 16.0f, 0.0f);			// Segundo tentaculo del pulpo
			glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-30.0f, 5.0f, 0.0f);			// Segundo tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(1, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-30.0f, 3.0f, 0.0f);			// Segundo tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			glRotatef(anim_soporte + 50, 0.0, -1.0, 0.0);
			renders.cube(10.0, 4.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	Cabina giratoria 
				wood.GLindex, wood.GLindex, asiento.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	
	glPopMatrix();
	
	glPushMatrix();										// Tercer tentaculo del pulpo
	glTranslatef(80.0f, -20.0f, -10.0f);
	glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 1.0f, 12.0f);			// Tercer tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 6.0f, 12.0f);			// Tercer tentaculo del pulpo
			glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 16.0f, 21.0f);			// Tercer tentaculo del pulpo
			glRotatef(90, 1, 0, 0);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 5.0f, 30.0f);			// Tercer tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(1, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 3.0f, 30.0f);			// Tercer tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			glRotatef(anim_soporte + 50, 0.0, -1.0, 0.0);
			renders.cube(10.0, 4.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	Cabina giratoria 
				wood.GLindex, wood.GLindex, asiento.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPopMatrix();

	glPushMatrix();										// Cuarto tentaculo del pulpo
	glTranslatef(80.0f, -20.0f, -10.0f);
	glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 1.0f, -12.0f);			// Cuarto tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
			
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 6.0f, -12.0f);			// Cuarto tentaculo del pulpo
			glRotatef(45, -1, 0, 0);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 16.0f, -31.0f);			// Cuarto tentaculo del pulpo
			glRotatef(90, 1, 0, 0);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 5.0f, -30.0f);			// Cuarto tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(1, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0f, 3.0f, -30.0f);			// Cuarto tentaculo del pulpo
			//glRotatef(90, 0, 0, 1);
			//glRotatef(90, 0, 1, 0);
			glRotatef(anim_soporte + 50, 0.0, -1.0, 0.0);
			renders.cube(10.0, 4.0, 5.0,
				wood.GLindex, wood.GLindex, wood.GLindex,		//	Cabina giratoria 
				wood.GLindex, wood.GLindex, asiento.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();										// Quinto tentaculo del pulpo
		glTranslatef(80.0f, -20.0f, -10.0f);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(8.0f, 1.0f, 8.0f);			// Quinto tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(8.0f, 6.0f, 8.0f);			// Quinto tentaculo del pulpo
			glRotatef(45, 1, 1, -1);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			//glRotatef(45, 0, 1, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(15.0f, 17.0f, 12.5f);			// Quinto tentaculo del pulpo
			//glRotatef(45, 1, 1, 0);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(15.0f, 26.0f, 12.5f);			// Quinto tentaculo del pulpo
			glRotatef(45, 1, 1, -1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();										// Sexto tentaculo del pulpo
		glTranslatef(80.0f, -20.0f, -10.0f);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-8.0f, 1.0f, 8.0f);			// Sexto tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-8.0f, 6.0f, 8.0f);			// Sexto tentaculo del pulpo
			glRotatef(45, 1, 1, 1);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			//glRotatef(45, 0, 1, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-12.0f, 16.5f, 15.0f);			// Sexto tentaculo del pulpo
			//glRotatef(45, 1, 1, 0);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-12.0f, 25.5f, 15.0f);			// Sexto tentaculo del pulpo
			glRotatef(45, 1, 1, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();										// Septimo tentaculo del pulpo
		glTranslatef(80.0f, -20.0f, -10.0f);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-8.0f, 1.0f, -8.0f);			// Septimo tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-8.0f, 6.0f, -8.0f);			// Septimo tentaculo del pulpo
			glRotatef(45, -1, -1, 1);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			//glRotatef(45, 0, 1, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-12.0f, 16.5f, -15.0f);			// Septimo tentaculo del pulpo
			//glRotatef(45, 1, 1, 0);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(-12.0f, 25.5f, -15.0f);			// Septimo tentaculo del pulpo
			glRotatef(45, -1, -1, 1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();										// Octavo tentaculo del pulpo
		glTranslatef(80.0f, -20.0f, -10.0f);
		glRotatef(anim_soporte + 50, 0.0, 1.0, 0.0);

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(8.0f, 1.0f, -8.0f);			// Octavo tentaculo del pulpo
			//glRotatef(45, 1, 0, 0);
			obj.cilindroTextura(2, 6, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(8.0f, 6.0f, -8.0f);			// Octavo tentaculo del pulpo
			glRotatef(45, -1, 1, -1);
			obj.cilindroTextura(2, 15, 12, Ventosa.GLindex);
			//glRotatef(45, 0, 1, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(12.0f, 16.5f, -15.0f);			// Octavo tentaculo del pulpo
			//glRotatef(45, 1, 1, 0);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(12.0f, 25.5f, -15.0f);			// Octavo tentaculo del pulpo
			glRotatef(45, -1, 1, -1);
			//glRotatef(90, 0, 1, 0);
			obj.cilindroTextura(2, 10, 12, Ventosa.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

	glPopMatrix();
	/* Fin del pulpo */
	   
	/* ENTRADA 1*/

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	glTranslatef(-60.0f, -28.0f, 21.5f);
	glRotatef(90, 0, 1, 0);		//		MODIFIQ
	renders.cube(15.0, 4.0, 3.0,
		tabiqueMarron.GLindex, none.GLindex, tabiqueMarron.GLindex,
		tabiqueMarron.GLindex, entradaTabiqueMarron.GLindex, entradaTabiqueMarron.GLindex);


	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	/* FIN ENTRADA */

	/* ENTRADA 2*/
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	glTranslatef(-60.0f, -28.0f, 41.75f);
	glRotatef(90, 0, 1, 0);		//		MODIFIQ
	renders.cube(15.0, 4.0, 3.0,
		tabiqueMarron.GLindex, none.GLindex, tabiqueMarron.GLindex,
		tabiqueMarron.GLindex, entradaTabiqueMarron.GLindex, entradaTabiqueMarron.GLindex);


	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	/* FIN ENTRADA 2*/

	/* TAQUILLAS */

	glPushMatrix();
	glTranslatef(-60.0f, -28.0f, 11.0f);
	glRotatef(270, 0, 1, 0);		//		MODIFIQ
	renders.cube(6.0f, 6.0f, 9.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
		tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -28.0f, 32.0f);
	glRotatef(270, 0, 1, 0);		//		MODIFIQ
	renders.cube(6.0f, 6.0f, 9.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
		tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-60.0f, -28.0f, 52.0f);
	glRotatef(270, 0, 1, 0);		//		MODIFIQ
	renders.cube(6.0f, 6.0f, 9.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
		tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
	glPopMatrix();
	/* FIN TAQUILLAS */

	/* Montaña Rusa  */

	
	/* Montaña rusa */

	//		INICIO DE MODELOS EN 3DS

	glPushMatrix();		// PUSH PRINCIPAL
	glDisable(GL_COLOR_MATERIAL);		//	ACTIVAR COLORES PARA MODELOS 3D

	// CASA DEL TERROR
	
	glPushMatrix();
	glTranslatef(80, -29, 65);
	glRotatef(90, 0, -1, 0);
	glScalef(4, 2.5, 3);
	oldhouse.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	/* Arboles de la casa del terror

	glPushMatrix();
	glTranslatef(85, -29, 40);
	//glRotatef(90, 0, -1, 0);
	glScalef(1, 1, 1);
	dead_trees.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(95, -29, 35);
	//glRotatef(90, 0, -1, 0);
	glScalef(1, 1, 1);
	dead_trees.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(75, -29, 40);
	//glRotatef(90, 0, -1, 0);
	glScalef(1, 1, 1);
	dead_trees.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(75, -29, 90);
	//glRotatef(90, 0, -1, 0);
	glScalef(1, 1, 1);
	dead_trees.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	*/

	// FIN DE CASA DEL TEORROR
										
	//		BANCAS

	glPushMatrix();
	glTranslatef(10, -28.7, -95);
	glScalef(1.5, 1.5, 1.5);
	banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -28.7, -95);
	glScalef(1.5, 1.5, 1.5);
	banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, -28.7, -95);
	glScalef(1.5, 1.5, 1.5);
	banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, -28.7, -65);
	glRotatef(180, 0, 1, 0);
	glScalef(1.5, 1.5, 1.5);
	banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20, -28.7, -65);
	glRotatef(180, 0, 1, 0);
	glScalef(1.5, 1.5, 1.5);
	banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, -28.7, -65);
	glRotatef(180, 0, 1, 0);
	glScalef(1.5, 1.5, 1.5);
	banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//		TERMINO BANCAS

	// BARDAS PULPO

	glPushMatrix();
	glTranslatef(45, -30.0, -96);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, -30.0, -90);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, -30.0, -84);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, -30.0, -78);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, -30.0, -72);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, -30.0, -66);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, -30.0, -62);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(42, -30.0, -59);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(36, -30.0, -59);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, -30.0, -59);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(24, -30.0, -59);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -56);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -50);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -44);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -38);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -32);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -26);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();



	//	ENTRADA EN PULPO

	glPushMatrix();
	glTranslatef(18, -30.0, -23);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12, -30.0, -23);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -30.0, -23);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//		entrada
	glPushMatrix();
	glTranslatef(2, -30.0, -17);
	glRotatef(90, 0, 1, 0);
	ent.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18, -30.0, -11);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12, -30.0, -11);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -30.0, -11);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	// TERMINA ENTRADA DE PULPO

	// BARDA PULPO

	glPushMatrix();
	glTranslatef(21, -30.0, -8);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, -2);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, 4);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, 10);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, 16);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, -30.0, 22);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(24, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(36, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	glPushMatrix();
	glTranslatef(42, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(48, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(54, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//		BARDA PARA CASA DEL TERROR
	glPushMatrix();
	glTranslatef(63, -30.0, 28);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 34);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 40);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	glPushMatrix();
	glTranslatef(63, -30.0, 46);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 52);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 58);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	//	CAMINO PARA CASA DEL TERROR

	glPushMatrix();
	glTranslatef(60, -30.0, 61);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(54, -30.0, 61);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(48, -30.0, 61);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(42, -30.0, 61);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(36, -30.0, 61);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//	MAIN
	glPushMatrix();
	glTranslatef(33, -30.0, 67);
	glRotatef(90, 0, 1, 0);
	ent.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//	TERMINO MAIN

	glPushMatrix();
	glTranslatef(60, -30.0, 73);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(54, -30.0, 73);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(48, -30.0, 73);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(42, -30.0, 73);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(36, -30.0, 73);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	//	FIN CAMINO

	glPushMatrix();
	glTranslatef(63, -30.0, 76);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 82);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 88);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 94);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(63, -30.0, 100);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();



	//		TERMINO BARDA DE LA CASA DEL TERRROR

	glPushMatrix();
	glTranslatef(66, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(72, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(78, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(84, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(90, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(96, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(102, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(108, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(114, -30.0, 25);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	// TERMINO BARDA DEL PULPO

	//		ARBOLES
	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, 40.5f);
	tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, 10.5f);
	tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, -20.5f);
	tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, -50.5f);
	tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, -80.5f);
	tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//		INDIVIDUALES

	glPushMatrix();
	glTranslatef(35.0f, -30.0f, -85.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(35.0f, -30.0f, -80.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35.0f, -30.0f, -90.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35.0f, -30.0f, -75.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0f, -30.0f, -85.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0f, -30.0f, -80.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0f, -30.0f, -90.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0f, -30.0f, -75.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-45.0f, -30.0f, -95.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0f, -30.0f, -80.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-35.0f, -30.0f, -60.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0f, -30.0f, -45.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.0f, -30.0f, 85.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, -30.0f, 55.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, -30.0f, 45.5f);
	tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	//		TERMINA ALBOLES

	// BARDA PARA ENTRADA


	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 57.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 60.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 63.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 67.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 70.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 74.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 74.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 77.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 81.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 84.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 88.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 91.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 95.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 98.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	//	BARDA DE LA DERECHA

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 6.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, 2.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -1.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -4.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -8.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -11.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -15.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -18.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -22.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -25.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -29.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -32.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -36.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -39.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -43.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -46.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -50.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -53.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -57.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -60.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -64.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -67.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -71.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -74.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -78.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -81.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -85.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -88.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -92.0f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0f, -29.5f, -95.5f);
	glRotatef(90, 0, 1.0, 0.0);
	barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
	// FIN BARDA PARA ENTRADA


	// MESA ---------------------------------------------------------------------------

	glPushMatrix();
	glTranslatef(-45.0f, -30.0f, -85.5f);
	glScalef(2.5, 2.5, 2.5);
	//	glRotatef(90, 0, 1.0, 0.0);
	table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0f, -30.0f, -85.5f);
	glScalef(2.5, 2.5, 2.5);
	//	glRotatef(90, 0, 1.0, 0.0);
	table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-35.0f, -30.0f, -65.5f);
	glScalef(2.5, 2.5, 2.5);
	//	glRotatef(90, 0, 1.0, 0.0);
	table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0f, -30.0f, 70.5f);
	glScalef(2.5, 2.5, 2.5);
	//	glRotatef(90, 0, 1.0, 0.0);
	table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40.0f, -30.0f, 65.5f);
	glScalef(2.5, 2.5, 2.5);
	//	glRotatef(90, 0, 1.0, 0.0);
	table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-50.0f, -30.0f, 70.5f);
	glScalef(2.5, 2.5, 2.5);
	//	glRotatef(90, 0, 1.0, 0.0);
	table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//	 FIN DE MESA

	//		INICIO STORE----------------------------------------------------------------

	glPushMatrix();
	glTranslatef(-40.0f, -30.0f, 90.0f);
	glRotatef(180, 0, 1.0, 0.0);
	glScalef(4.0, 4.0, 4.0);
	store.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//		Darth Vader-----------------------------------------

	//		FIN STORE

	//		INICIO Car
	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, 60.5f);
	glRotatef(90, 0, 1.0, 0.0);
	//glScalef(4.0, 4.0, 4.0);
	car.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, 68.5f);
	glRotatef(90, 0, 1.0, 0.0);
	//glScalef(4.0, 4.0, 4.0);
	car2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-112.0f, -30.0f, 76.5f);
	glRotatef(90, 0, 1.0, 0.0);
	//glScalef(4.0, 4.0, 4.0);
	car3.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-90.0f, -30.0f, 85.5f);
	glRotatef(90, 0, 1.0, 0.0);
	//glScalef(4.0, 4.0, 4.0);
	car.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-90.0f, -30.0f, 90.5f);
	glRotatef(90, 0, 1.0, 0.0);
	//glScalef(4.0, 4.0, 4.0);
	car2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-90.0f, -30.0f, 94.5f);
	glRotatef(90, 0, 1.0, 0.0);
	//glScalef(4.0, 4.0, 4.0);
	car3.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
	//		FIN Car

	// Barda estacionamiento
	glPushMatrix();
	glTranslatef(-117.0f, -30.0f, 98.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-111.0f, -30.0f, 98.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-105.0f, -30.0f, 98.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-99.0f, -30.0f, 98.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-93.0f, -30.0f, 98.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-87.0f, -30.0f, 98.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-84.0f, -30.0f, 95.5f);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-84.0f, -30.0f, 77.5f);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-84.0f, -30.0f, 71.5f);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-84.0f, -30.0f, 65.5f);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-84.0f, -30.0f, 59.5f);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-84.0f, -30.0f, 53.5f);
	glRotatef(90, 0, 1, 0);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-87.0f, -30.0f, 50.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-93.0f, -30.0f, 50.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-99.0f, -30.0f, 50.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-105.0f, -30.0f, 50.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-111.0f, -30.0f, 50.5f);
	barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
	//	Fin Barda estacionamiento


	// COMIENZO DE PERSONAS

	glPushMatrix();
		glTranslatef(-40.0f, -38.0f, 15.0f);
		glRotatef(45, 0, 1, 0);
		glScalef(2.3, 2.3, 2.3);			///		PRUEBA
		glTranslatef(movKit, 4, 0);
		people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-40.0f, -38.0f, 18.0f);
		glRotatef(45, 0, 1, 0);
		glScalef(2.3, 2.3, 2.3);			///		PRUEBA
		glTranslatef(movKit, 4, 0);
		people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-40.0f, -38.0f, 20.0f);
		glRotatef(45, 0, 1, 0);
		glScalef(2.3, 2.3, 2.3);			///		PRUEBA
		glTranslatef(movKit, 4, 0);
		people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-40.0f, -38.0f, 25.0f);
		glRotatef(90, 0, 1, 0);
		glScalef(2.3, 2.3, 2.3);			///		PRUEBA
		glTranslatef(movKit, 4, 0);
		people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-40.0f, -30.0f, 28.0f);
		glRotatef(180, 0, 1, 0);
		glScalef(1, 1, 1);			///		PRUEBA
		glTranslatef(0, 4, movKit);
		balto.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 10.0f, 0.0f);
		glRotatef(180, 0, 1, 0);
		glScalef(1, 1, 1);			///		PRUEBA
		glTranslatef(0, 4, movKit);
		avion.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	//			ANIMACION-----------------------------------------------------------------------------------

	glPushMatrix();
	glTranslatef(-40.0f, -30.0f, 65.5f);
	glScalef(2.0, 2.0, 2.0);
	people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40.0f, -30.0f, 55.5f);
	glScalef(1.0,1.0,1.0);
	balto.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-40.0f, -30.0f, -65.5f);
	glScalef(2.0, 2.0, 2.0);
	people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40.0f, -30.0f, -55.5f);
	glScalef(1.0, 1.0, 1.0);
	balto.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, -30.0f, -65.5f);
	glScalef(2.0, 2.0, 2.0);
	people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, -30.0f, -55.5f);
	glScalef(1.0,1.0,1.0);
	balto.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();
	



	// FIN DE PERSONAS






	glEnable(GL_COLOR_MATERIAL); //	DESACTIVAR COLORES PARA MODELOS 3D


	glPopMatrix();		// POP PRINCIPAL

	glColor3f(1.0, 1.0, 1.0);

	glPopMatrix(); // FIN AREA DE DIBUJO
	glPopMatrix(); // FIN CAMARA

	glutSwapBuffers();
}

void animacion()
{
	obj.text_izq -= 0.001;
	obj.text_der -= 0.001;
	if (obj.text_izq < -1)
		obj.text_izq = 0;
	if (obj.text_der < 0)
		obj.text_der = 1;

	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;
	//rotacion 
	if (dwElapsedTime >= 5)
	{
		rueda = (rueda - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}
	//Movimiento Avion
	if (avion1Girando)
	{
		if (giroAvion1 < 360)
			giroAvion1 += 0.5;
		else
			giroAvion1 = 0;
	}

	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			rotRodDer += KeyFrame[playIndex].rotInc2;
			rotBrazos += KeyFrame[playIndex].rotInc3;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;

			i_curr_steps++;
		}

	}


	glutPostRedisplay();
}


void reshape(int width, int height) {

	// Prevenir division entre 0

	if (!height)
		return;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION); // Activamos la matriz de proyeccion. 
	glLoadIdentity();// "limpiamos" esta con la matriz identidad.

	gluPerspective(45, (GLfloat)width / (GLfloat)height, 0.01, 1000.0);

	glMatrixMode(GL_MODELVIEW); // Activamos la matriz de modelado/visionado. 
	glLoadIdentity();  // "Limpiamos" la matriz
	return;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0);
		break;
	case 'w':   //Movimientos de camara
	case 'W':
		camera.Move_Camera(CAMERASPEED + 2.2);
		break;

	case 's':
	case 'S':
		camera.Move_Camera(-(CAMERASPEED + 2.2));
		break;

	case 'a':
	case 'A':
		camera.Strafe_Camera(-(CAMERASPEED + 2.4));
		break;

	case 'd':
	case 'D':
		camera.Strafe_Camera(CAMERASPEED + 2.4);
		break;

	case 'q':
	case 'Q':
		camera.UpDown_Camera(CAMERASPEED + 0.5);
		break;

	case 'e':
	case 'E':
		camera.UpDown_Camera(-(CAMERASPEED + 0.5));
		break;

		//			ANIMACION DE PERSONA
	case 'r':
	case 'R':
		movKit = 0.0;
		g_persona2 = true;
		g_persona = false;
		voltear = 90.0;
		break;

	case'ñ':
	case'Ñ':
		avion1Girando = !avion1Girando;
		break;

	case ' ':		//Poner algo en movimiento
		movKit = 0.0;
		movKitX = 0.0;
		g_persona2 = true;
		g_persona = false;
		voltear = 90.0;



		g_persona ^= true; //Activamos/desactivamos la animacíon
		break;

		//			FIN DE ANIMACION DE PERSONA
		
	case 'O':		//  ANimacion del carro al estacionamiento
	case 'o':
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon
		circuito = false;
		break;

	case 'v':		//  
	case 'V':
		circuito ^= true; //Activamos/desactivamos la animacíon
		g_fanimacion = false;
		break;

	case 'k':		//
	case 'K':
		if (FrameIndex < MAX_FRAMES)
		{
			saveFrame();
		}

		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex > 1))
		{

			resetElements();
			//First Interpolation				
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;




	case 'y':
	case 'Y':
		posZ++;
		printf("%f \n", posZ);
		break;

	case 'g':
	case 'G':
		posX--;
		printf("%f \n", posX);
		break;

	case 'h':
	case 'H':
		posZ--;
		printf("%f \n", posZ);
		break;

	case 'j':
	case 'J':
		posX++;
		printf("%f \n", posX);
		break;

	case 'b':
		rotRodIzq++;
		printf("%f \n", rotRodIzq);
		break;

	case 'B':
		rotRodIzq--;
		printf("%f \n", rotRodIzq);
		break;

	case 'u':
		rotRodDer++;
		printf("%f \n", rotRodDer);
		break;

	case 'U':
		rotRodDer--;
		printf("%f \n", rotRodDer);
		break;

	case 'i':
		rotBrazos++;
		printf("%f \n", rotBrazos);
		break;

	case 'I':
		rotBrazos--;
		printf("%f \n", rotBrazos);
		break;

	case 'p':
		giroMonito++;
		break;

	case 'P':
		giroMonito--;
		break;

	}

	glutPostRedisplay();
	return;

}

void specialKeys(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_PAGE_UP:
		camera.UpDown_Camera(CAMERASPEED + 0.4);
		break;

	case GLUT_KEY_PAGE_DOWN:
		camera.UpDown_Camera(-(CAMERASPEED + 0.4));
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		camera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		camera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}

	glutPostRedisplay();

}

void animation() {

	/* ANIMACION SKYBOX --> MOVIMIENTO DEL CIELO */

	if (sideSkyBox >= 1.0)
		sideSkyBox = 0.0;
	else
		sideSkyBox += 0.00005;

	
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 5)
		{
			rueda = (rueda - 1) % 360;

			dwLastUpdateTime = dwCurrentTime;
		}
	if (dwElapsedTime >= 30)
	{

		anim_soporte = (anim_soporte + 20) % 360;
		anim_soporte2 = -anim_soporte;
		anim_soporte2 = (anim_soporte2 + 50) % 360;
		dwLastUpdateTime = dwCurrentTime;



	}


	

	//		PERSONA

	if (g_persona && movKit <= 10)
	{

		movKit += 0.5;

		if (movKit == 10) {
			g_persona2 = false;
			g_persona = false;
			voltear = -90.0;
			movKit = -10;
		}

		//	voltear;

	}


	if (g_persona2 == false && movKit <= 10)
	{
		movKit += 0.5;

		if (movKit == 10) {
			voltear = 90.0;
			movKit = -10;
			g_persona2 = true;
			g_persona = true;
		}

	}







	glutPostRedisplay();
}

void audio() {
	
	PlaySound("feria.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}


int main(int argc, char** argv) {

	//audio();

	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(1280, 720);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Parque de Diversiones"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(specialKeys);	//Otras
	glutIdleFunc(animation);

	glutMainLoop();          // 

	return 0;
}