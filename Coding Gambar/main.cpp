#include "stdlib.h"
#include "gl/glut.h"
#include "math.h"

const double PI = 3.141592653589793;
int i;

void back(){
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex2d (-150,150);
	glVertex2d(150,150);
	glVertex2d(150,-150);
	glVertex2d (-150,-150);
	glEnd();
}

void lingkaran(float radius, int jumlah_titik, int x_tengah, int y_tengah) {
	glBegin(GL_POLYGON);
	for (i=0;i<=360;i++){
    	float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
  		glVertex2f(x,y);
 	}
 	glEnd();
}

void elips(float rx, float ry, float xc, float yc, int n){
	glBegin(GL_POLYGON);
	double t;
	for (int i=0; i<n; ++i){
		t=i * 2.0 * 3.14159 / n;
		glVertex2f( rx*cos(t)+xc, ry*sin(t)+yc);
	}
	glEnd();
}

void kotak (){
	glBegin (GL_POLYGON);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (-5.0f, -14.0f);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (-5.0f, -8.5f);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (-4.0f, -8.5f);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (-4.0f, -14.0f);
	glEnd ();
}

void kotak2 (){
	glBegin (GL_POLYGON);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (5.0f, -14.0f);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (5.0f, -8.5f);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (4.0f, -8.5f);
	glColor3f (0.0, 0.0, 1.4); glVertex2f (4.0f, -14.0f);
	glEnd ();
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
 	back();
 	glColor3f(0.0, 0.0, 1.4);
 	lingkaran(10,70,0,0);
 	glColor3f(1.0, 1.0, 1.0);
	elips(-4.30,8.30,0.0,6.0,40.20);
	glColor3f(0.0, 0.0, 1.4);
	elips(-4.10,8.20,0.0,6.0,40.20);
 	glColor3f(1.0, 1.0, 1.0);
 	lingkaran(1.5,70,-2.0,7);
 	glColor3f(0.0, 0.0, 0.0);
 	lingkaran(0.5,70,-2.0,6);
 	glColor3f(1.0, 1.0, 1.0);
 	lingkaran(1.5,70,2.0,7);
 	glColor3f(0.0, 0.0, 0.0);
 	lingkaran(0.5,70,2.0,6);
 	glColor3f(1.0, 0.0, 0.0);
 	elips(-1.65,0.65,0.0,1.3,36.0);
 	glColor3f(0.0, 0.0, 0.0);
 	elips(-1.30,0.35,3.0,13.5,30.0);
 	glColor3f(0.0, 0.0, 0.0);
 	elips(-1.30,0.35,-3.0,13.5,30.0);
 	glColor3f(0.0, 0.0, 1.4);
 	kotak();
 	kotak2();
 	glFlush();
}

int main(int argc, char **argv) {
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowSize(600, 600);
	 glutInitWindowPosition(200, 200);
	 glutCreateWindow("Kambing");
	 gluOrtho2D(-15., 15., -15., 15.);
	 glutDisplayFunc(Draw);
	 glutMainLoop();
	 return 0;
}
