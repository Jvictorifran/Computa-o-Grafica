#include <GL/freeglut.h>

void desenha(void);
void atualiza(int value);

float xOffset = 0.0f;
float stepx= 0.01f;  // Velocidade do movimento
float yoffset = 0.0f;
float stepy = 0.01f;
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("FreeGLUT Example");
    
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(desenha);
    glutTimerFunc(50, atualiza, 0);  // Chama `atualiza` a cada 50ms

    glutMainLoop();
    return 0;
}

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);

    glBegin(GL_LINE_LOOP);//desenhando quadrado
        glVertex2f(0.5 , 0.5 + yoffset);//um ponto em cada vertice do quadrado
        glVertex2f(-0.5, 0.5 + yoffset);
        glVertex2f(-0.5 , -0.5 + yoffset) ;
        glVertex2f(0.5 , -0.5 + yoffset);
    glEnd();

    glFlush();
}

void atualiza(int value) {
   xOffset += stepx;
    yoffset += stepy;
   //Se atingir os limites da tela, inverte a direção do movimento
   if (xOffset > 0.5f || xOffset < -0.5f) {
    stepx = -stepx;  // Inverte o sentido do movimento
    }
    if (yoffset > 0.5f || yoffset < -0.5f){
      stepy = -stepy;
    }
    glutPostRedisplay();
    glutTimerFunc(50, atualiza, 0);  // Chama `atualiza` novamente após 50ms
}
void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);


    glFlush();
}