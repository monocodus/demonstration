
/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define eb emplace_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "["; forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i; cerr << "]" << endl;
}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}


#include <GL/glut.h>
#include "imageloader.h"
#include "color.h"

using namespace std;

const float BOX_SIZE = 15.0f;
const float h = 1.f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box
GLuint _textureId,_textureId1,_textureId2,_textureId3;           //The OpenGL id of the texture
GLUquadricObj *quad = gluNewQuadric();
GLUquadricObj *quad1 = gluNewQuadric();
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 27: //Escape key
        exit(0);
    }
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGB,
                 image->width, image->height,
                 0,
                 GL_RGB,
                 GL_UNSIGNED_BYTE,
                 image->pixels);
    return textureId;
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    Image* image = loadBMP("C:\\Users\\Sanim\\Desktop\\thesis\\Tajmahal_cg\\1.bmp");
    _textureId = loadTexture(image);
    delete image;

    image = loadBMP("C:\\Users\\Sanim\\Desktop\\thesis\\Tajmahal_cg\\2.bmp");
    _textureId1 = loadTexture(image);
    delete image;

     image = loadBMP("C:\\Users\\Sanim\\Desktop\\thesis\\Tajmahal_cg\\3.bmp");
    _textureId2 = loadTexture(image);
    delete image;

    image = loadBMP("C:\\Users\\Sanim\\Desktop\\thesis\\Tajmahal_cg\\4.bmp");
    _textureId3 = loadTexture(image);
    delete image;

    //Image* image = loadBMP("aust.bmp");
    //_textureId = loadTexture(image);
    //delete image;
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void TajFloor() {
    glColor3d(White);
    glBegin(GL_QUADS);
    //Top face
    glNormal3f(0.0, 1.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, h / 2, -BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, h / 2, BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, h / 2, BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, h / 2, -BOX_SIZE / 2);

    //Bottom face

    glNormal3f(0.0, -1.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -h / 2, -BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, -h / 2, -BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, -h / 2, BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, -h / 2, BOX_SIZE / 2);

    //Left face
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -h / 2, -BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, -h / 2, BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, h / 2, BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, h / 2, -BOX_SIZE / 2);

    //Right face
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(BOX_SIZE / 2, -h / 2, -BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, h / 2, -BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, h / 2, BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, -h / 2, BOX_SIZE / 2);



    //Front face
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(-BOX_SIZE / 2, -h / 2, BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, -h / 2, BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, h / 2, BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, h / 2, BOX_SIZE / 2);

    //Back face
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(-BOX_SIZE / 2, -h / 2, -BOX_SIZE / 2);
    glVertex3f(-BOX_SIZE / 2, h / 2, -BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, h / 2, -BOX_SIZE / 2);
    glVertex3f(BOX_SIZE / 2, -h / 2, -BOX_SIZE / 2);
    glEnd();
}

void minarCenterCylinder(float a,float b) {
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, _textureId3);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricNormals(quad, true);
    gluQuadricTexture(quad, true);
    glPushMatrix();
    glTranslated(a,0.0,b);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.8,0.6,7,8,1);
    glPopMatrix();
}

void minarRings(float a,float b,float c) {
    glPushMatrix();
    glTranslated(a,c,b);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.9,0.9,.25,8,1);
    gluDisk(quad,0,0.9,50,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(a,c+.25,b);
    glRotated(90.,-1.,0.,0.);
    gluDisk(quad,0,0.9,50,1);
    glPopMatrix();
}

void minarHead(float a,float b) {
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, _textureId2);
    gluQuadricOrientation(quad1, GLU_OUTSIDE);
    gluQuadricNormals(quad1, true);
    gluQuadricTexture(quad1, true);
    glPushMatrix();
    glTranslated(a,7,b);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad1,0.6,0.6,1.25,8,1);
    glPopMatrix();



    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricNormals(quad, true);
    gluQuadricTexture(quad, true);
    glPushMatrix();
    glTranslated(a,8.25,b);
    glRotated(90.,-1.,0.,0.);
    gluDisk(quad,0,0.6,50,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(a,8.25,b);
    glRotated(90.,-1.,0.,0.);
    glutSolidSphere(0.6,50,50);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, _textureId3);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricNormals(quad, true);
    gluQuadricTexture(quad, true);
    glPushMatrix();
    glTranslated(a,8,b);
    glRotated(90.,-1.,0.,0.);
    glutSolidCone(0.9,.25,50,50);
    gluDisk(quad,0,0.9,50,1);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, _textureId3);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricNormals(quad, true);
    gluQuadricTexture(quad, true);
    glPushMatrix();
    glColor3d(Gold);
    glTranslated(a,8.25+.6,b);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.1,0.1,.25,8,1);
    glPopMatrix();
    glColor3d(White);
}


void minar() {

    minarCenterCylinder(BOX_SIZE/2-.8,BOX_SIZE/2-.8);
    minarRings(BOX_SIZE/2-.8,BOX_SIZE/2-.8,2.33);
    minarRings(BOX_SIZE/2-.8,BOX_SIZE/2-.8,2.33*2);
    minarRings(BOX_SIZE/2-.8,BOX_SIZE/2-.8,2.33*3);
    minarHead(BOX_SIZE/2-.8,BOX_SIZE/2-.8);


    minarCenterCylinder(-BOX_SIZE/2+.8,BOX_SIZE/2-.8);
    minarRings(-BOX_SIZE/2+.8,BOX_SIZE/2-.8,2.33);
    minarRings(-BOX_SIZE/2+.8,BOX_SIZE/2-.8,2.33*2);
    minarRings(-BOX_SIZE/2+.8,BOX_SIZE/2-.8,2.33*3);
    minarHead(-BOX_SIZE/2+.8,BOX_SIZE/2-.8);

    minarCenterCylinder(-BOX_SIZE/2+.8,-BOX_SIZE/2+.8);
    minarRings(-BOX_SIZE/2+.8,-BOX_SIZE/2+.8,2.33);
    minarRings(-BOX_SIZE/2+.8,-BOX_SIZE/2+.8,2.33*2);
    minarRings(-BOX_SIZE/2+.8,-BOX_SIZE/2+.8,2.33*3);
    minarHead(-BOX_SIZE/2+.8,-BOX_SIZE/2+.8);

    minarCenterCylinder(BOX_SIZE/2-.8,-BOX_SIZE/2+.8);
    minarRings(BOX_SIZE/2-.8,-BOX_SIZE/2+.8,2.33);
    minarRings(BOX_SIZE/2-.8,-BOX_SIZE/2+.8,2.33*2);
    minarRings(BOX_SIZE/2-.8,-BOX_SIZE/2+.8,2.33*3);
    minarHead(BOX_SIZE/2-.8,-BOX_SIZE/2+.8);

}
double x = 6,y = 6;
void wall1() {

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0f, 0.0f);
    glTexCoord2f(0.f, 0.0f);
    glVertex3f(-BOX_SIZE / 2 + x, h / 2 , BOX_SIZE / 2 - x);
    glTexCoord2f(1.f, 0.f);
    glVertex3f(-BOX_SIZE / 2 + x, h / 2 + y-1, BOX_SIZE / 2 - x);
    glTexCoord2f(1.f, 1.f);
    glVertex3f(BOX_SIZE / 2 - x, h / 2 + y-1, BOX_SIZE / 2 - x);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(BOX_SIZE / 2 - x, h / 2, BOX_SIZE / 2 - x);
    glEnd();

    glPushMatrix();
    glTranslated(-BOX_SIZE / 2 + x+.1, h / 2+ y-1 , BOX_SIZE / 2 - x);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.50,8,1);
    glColor3d(White);
    glPopMatrix();

    glPushMatrix();
    glTranslated(BOX_SIZE / 2 - x-.1, h / 2 + y-1, BOX_SIZE / 2 - x);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.50,8,1);
    glColor3d(White);
    glPopMatrix();
}
double z = 2;
double _w2;
void wall2() {
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, _textureId1);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0f, 0.0f);
    glTexCoord2f(0.f, 0.0f);
    glVertex3f(-BOX_SIZE / 2 + x, h / 2 , BOX_SIZE / 2 - x);

    glTexCoord2f(1.f, 0.0f);
    glVertex3f(-BOX_SIZE / 2 + x, h / 2 + y - z, BOX_SIZE / 2 - x);

    glTexCoord2f(1.f, 1.0f);
    glVertex3f(-BOX_SIZE / 2 + .75*x, h / 2 + y - z, BOX_SIZE / 2 - x);
    //__(-BOX_SIZE / 2 + .75*x, h / 2 + y - z, BOX_SIZE / 2 - x);

    glTexCoord2f(0.f, 1.0f);
    glVertex3f(-BOX_SIZE / 2 + .75*x, h / 2, BOX_SIZE / 2 - x);
    glEnd();
}

void wall3() {

    glBindTexture(GL_TEXTURE_2D, _textureId1);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0f, 0.0f);

    glTexCoord2f(0.f, 0.0f);
    glVertex3f(-BOX_SIZE / 2 + .75*x, h / 2, BOX_SIZE / 2 - x);

    glTexCoord2f(1.f, 0.0f);
    glVertex3f(-BOX_SIZE / 2 + .75*x, h / 2 + y - z, BOX_SIZE / 2 - x);

    glTexCoord2f(1.f, 1.0f);
    glVertex3f(-BOX_SIZE / 3.25 , h / 2 + y - z, BOX_SIZE / 2 - 1.25*x);


    glTexCoord2f(0.f, 1.0f);
    glVertex3f(-BOX_SIZE / 3.25, h / 2 , BOX_SIZE / 2 - 1.25*x);

    glEnd();

    glPushMatrix();
    glTranslated(-BOX_SIZE / 2 + .75*x, h / 2 + y - z, BOX_SIZE / 2 - x-.1);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.50,8,1);
    glColor3d(White);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-BOX_SIZE / 3.25 , h / 2 + y - z, BOX_SIZE / 2 - 1.25*x-.1);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.50,8,1);
    glColor3d(White);
    glPopMatrix();
}

void centerBig(){
    glPushMatrix();
    glTranslated(0,5,-BOX_SIZE/5);
    gluSphere(quad,2,50,50);
    glBindTexture(GL_TEXTURE_2D, _textureId3);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricNormals(quad, true);
    gluQuadricTexture(quad, true);
    glTranslated(0,2,0);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.50,8,1);
    glColor3d(White);
    glPopMatrix();
}

void side(){

    glPushMatrix();
    glTranslated(-3,4.75,-BOX_SIZE/2.75);
    gluSphere(quad,1,50,50);
    glTranslated(0,1,0);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.50,8,1);
    glColor3d(White);
    glPopMatrix();

    glPushMatrix();
    glTranslated(BOX_SIZE/2.75,0,0);
    glTranslated(-3,4.75,-BOX_SIZE/2.75);
    gluSphere(quad,1,50,50);
    glTranslated(0,1,0);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.25,8,1);
    glColor3d(White);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,BOX_SIZE/2.75);
    glTranslated(-3,4.75,-BOX_SIZE/2.75);
    gluSphere(quad,1,50,50);
    glTranslated(0,1,0);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.25,8,1);
    glColor3d(White);
    glPopMatrix();

    glPushMatrix();
    glTranslated(BOX_SIZE/2.75,0,BOX_SIZE/2.75);
    glTranslated(-3,4.75,-BOX_SIZE/2.75);
    gluSphere(quad,1,50,50);
    glTranslated(0,1,0);
    glColor3d(Gold);
    glRotated(90.,-1.,0.,0.);
    gluCylinder(quad,0.05,0.05,.25,8,1);
    glColor3d(White);
    glPopMatrix();


}


void house() {

    glPushMatrix();
    glTranslated(0,0,2);
    wall1();
    wall2();
    glPushMatrix();
    glTranslated(BOX_SIZE/3.35,0,0);
    wall2();
    glPopMatrix();

    glPushMatrix();
    wall3();
    glPopMatrix();

    glPushMatrix();
    rep(i,3) {
        glTranslated(-3,0,-3);
        glRotated(-90.,0,1,0);
        wall1();
        wall2();
        glPushMatrix();
        glTranslated(BOX_SIZE/3.35,0,0);
        wall2();
        glPopMatrix();
        wall3();
    }
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, _textureId3);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricNormals(quad, true);
    gluQuadricTexture(quad, true);
    centerBig();
    side();
    glPopMatrix();

}

void dd(){
    glPushMatrix();
        glBegin(GL_QUADS);
        glVertex3f(-BOX_SIZE/3.35 , h / 2 + y - z, BOX_SIZE / 6.45);
        glVertex3f(BOX_SIZE / 3.35, h / 2 + y - z, BOX_SIZE / 6.45);
        glVertex3f(BOX_SIZE/3.35, h / 2 + y - z, -BOX_SIZE / 3.5);
        glVertex3f(-BOX_SIZE/3.35 , h / 2 + y - z, -BOX_SIZE /3.5);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(-BOX_SIZE/3.35 , h / 2 + y - z, BOX_SIZE / 6.45);
        glVertex3f(BOX_SIZE / 3.35, h / 2 + y - z, BOX_SIZE / 6.45);
        glVertex3f(BOX_SIZE / 2 - .75*x, h / 2 + y - z, BOX_SIZE / 4.35);
        glVertex3f(-BOX_SIZE / 2 + .75*x, h / 2 + y - z , BOX_SIZE / 4.35);
        glEnd();

        glPushMatrix();

        glTranslated(0,0,-BOX_SIZE/8);
        glRotated(-180,0,1,0);
        glBegin(GL_QUADS);
        glVertex3f(-BOX_SIZE/3.35 , h / 2 + y - z, BOX_SIZE / 6.45);
        glVertex3f(BOX_SIZE / 3.35, h / 2 + y - z, BOX_SIZE / 6.45);
        glVertex3f(BOX_SIZE / 2 - .75*x, h / 2 + y - z, BOX_SIZE / 4.35);
        glVertex3f(-BOX_SIZE / 2 + .75*x, h / 2 + y - z , BOX_SIZE / 4.35);
        glEnd();
        glPopMatrix();

    glPopMatrix();
}

void front(){

}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -40.0f);

    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
    TajFloor();
    minar();
    house();
    dd();

    glutSwapBuffers();
}


void update(int value) {
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);

    glutCreateWindow("Tajmahal");
    initRendering();

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}


