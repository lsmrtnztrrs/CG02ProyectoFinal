
#include "Main.h"

#define PI 3.14159265359



class Render {
	public:
	
		// void skyBox(float lenght, float height, float width, GLuint sideTexture);
		void cube(float lenght, float height, float width, GLuint top, GLuint down, GLuint left, GLuint right, GLuint front, GLuint back);
		void skyBox(float lenght, float height, float width, GLuint top, GLuint down, GLuint side, float sideMov);
		void plane(float lenght, float height, int repeat ,GLuint texture);
		
};

class Superman {
	public:
		
		void carril(float posX, float posY, float posZ, float rotY, float rotZ, float long1, float long2);
		void carrilConexion(float posX, float posY, float posZ, float rotY, bool izq);
		void carrilVertical(float longRiel1, float longRiel2, float ancho);
		void soporte(float posX, float posY, float posZ, float alturaSoporte, float alturaIndv, float largo, float ancho);
};









class Carril {
public:

	float longitud;
	float angX1, angX2, angZ1, angZ2;
	GLfloat Vm[3], Vaux[3];

	float radiansToDegrees(float radians) {
		return (radians * 180) / PI;
	}

	float absF(float num) {
		if (num < 0.0)
			return num * -1.0;
		else
			return num;
	}

	void carril(GLfloat Vi[3], GLfloat Vf[3]);

};