
#include "renders.h"
#include "figuras.h"
#include "math.h"

#define PI 3.14159265359
#define ANCHO_RIEL 1.5
#define ANCHO_TUBO_RIEL 0.1
#define LARGO_CARRIL 1.0
#define RESOLUCION 4


GLfloat blanco[3] = { 1.0, 1.0, 1.0 };

CFiguras figuras;

float distanciaDosPuntos(float aX, float aY, float aZ, float bX, float bY, float bZ) {
	return sqrt(pow(bX - aX, 2) + pow(bY - aY, 2) + pow(bZ - aZ, 2));
}

float radiansToDegrees(float radians) {
	return (radians * 180) / PI;
}

void Render::cube(float lenght, float height, float width,
					GLuint top, GLuint down, GLuint left,
					GLuint right, GLuint front, GLuint back) {

	GLfloat vertexes[8][3] = {
		{-0.5f*lenght, 0.5f*height, 0.5f*width},     // V0
		{ 0.5f*lenght, 0.5f*height, 0.5f*width },    // V1
		{ 0.5f*lenght, 0.5f*height, -0.5f*width },   // V2
		{ -0.5f*lenght, 0.5f*height, -0.5f*width },  // V3
		{ -0.5f*lenght, -0.5f*height, 0.5f*width },  // V4
		{ 0.5f*lenght, -0.5f*height, 0.5f*width },   // V5
		{ 0.5f*lenght, -0.5f*height, -0.5f*width },  // V6
		{ -0.5f*lenght, -0.5f*height, -0.5f*width }, // V7
	};

	glBindTexture(GL_TEXTURE_2D, top);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[5]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[0]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, front);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[1]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[3]);
		glEnd();
}

void Render::skyBox(float lenght, float height, float width,
					GLuint top, GLuint down, GLuint side,
					float sideMov) {

	GLfloat vertexes[8][3] = {
		{ -0.5f*lenght, 0.5f*height, 0.5f*width },   // V0
		{ 0.5f*lenght, 0.5f*height, 0.5f*width },    // V1
		{ 0.5f*lenght, 0.5f*height, -0.5f*width },   // V2
		{ -0.5f*lenght, 0.5f*height, -0.5f*width },  // V3
		{ -0.5f*lenght, -0.5f*height, 0.5f*width },  // V4
		{ 0.5f*lenght, -0.5f*height, 0.5f*width },   // V5
		{ 0.5f*lenght, -0.5f*height, -0.5f*width },  // V6
		{ -0.5f*lenght, -0.5f*height, -0.5f*width }, // V7
	};

	glBindTexture(GL_TEXTURE_2D, top);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 5.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(5.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(5.0f, 5.0f); glVertex3fv(vertexes[6]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // left
		glNormal3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f + sideMov, 1.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f + sideMov, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(0.25f + sideMov, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.25f + sideMov, 1.0f); glVertex3fv(vertexes[3]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // right
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.50f + sideMov, 1.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(0.50f + sideMov, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(0.75f + sideMov, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(0.75f + sideMov, 1.0f); glVertex3fv(vertexes[1]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // front
		glNormal3f(0.0f, 0.0f, -1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.75f + sideMov, 1.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(0.75f + sideMov, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f + sideMov, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f + sideMov, 1.0f); glVertex3fv(vertexes[0]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // back
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.25f + sideMov, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.25f + sideMov, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.50f + sideMov, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(0.50f + sideMov, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();
}

void Render::plane(float lenght, float height, int repeat, GLuint texture) {
	GLfloat vertexes[4][3] = {
		{ -lenght * 0.5f, height * 0.5f, 0.0 },
		{ -lenght * 0.5f, -height * 0.5f, 0.0 },
		{ lenght * 0.5f, -height * 0.5f, 0.0 },
		{ lenght * 0.5f, height * 0.5f, 0.0 },
	};

	glBindTexture(GL_TEXTURE_2D, texture);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 3.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertexes[3]);
		glEnd();
}




