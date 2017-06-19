#include <vector>
#include "tinyxml2.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <map>
#define T 0.0
#define S 1.0
#define R 2.0

using namespace std;
using namespace tinyxml2;

double alpha = 0.0f, beta = 0.0f, raio = 20.0f;
double camX, camY, camZ;
int startX, startY, tracking = 0;



class Model{
public:
    string nome; //nome do modelo desenhado
    vector <float> pontos; //vector que armazena os pontos
};

class Group{
public:
    map<int,vector<float> > transf;
    vector <Model*> mod;
    vector <Group*> grup;
};

class Scene{
public:
    vector<Group*> grupos;
};



Scene* c; // variavel global da cena


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

/**
 * read_File3D:
 * le os pontos guardados no ficheiro .3d
 * e guarda no vetor de pontos do modelo que estamos a ler
**/
Model* read_File3D(const char* file){
    Model* mod = new Model();
    mod->nome = file;
    double a, b, c;
    ifstream input_file(file);
    while (input_file >> a >> b >> c){
        mod->pontos.push_back(a);
        mod->pontos.push_back(b);
        mod->pontos.push_back(c);
    }
    return mod;
}

/**
 * drawFigures:
 * 1º fazemos as transformações que lemos no XML (percorrendo o vetor ordem, com o iterator o)
 * 2º Escolhemos as cores. consoante a figura que vamos desenhar [AQUI PODIAMOS MUDAR ISTO, E POR A COR EM FUNÇÃO DO NOME DO PLANETA
 * PARA ISSO TINHAMOS DE POR O NOME DO PLANETA NO GRUPO, NO XML]
 * 3º desenhamos as figuras, com a função glVertex3f, lendo os pontos do vetor pontosAux que é uma copia do vetor pontos do modelo
 * que estamos a tratar, lendo esses pontos 3 a 3.
 * 4º Se tivermos subgrupos chamamos recursivamente esta função
**/
void drawFigures(Group* p){
    vector<float> aux;
    map<int,vector<float> >::iterator it;
    int t=0;
    int i;
    glPushMatrix();
    for (it=p->transf.begin(); it != p->transf.end(); ++it){
        aux = it->second;
        if(it->first == T){
            glTranslatef(aux[0],aux[1],aux[2]);

        }else if(it->first == S){
            glScalef(aux[0],aux[1],aux[2]);

        }else if(it->first == R){
            glRotatef(aux[0],aux[1],aux[2],aux[3]);
        }
    }
    vector<float> pontosAux;
    for(i = 0;i< p->mod.size();i++){
        pontosAux = p->mod[i]->pontos;
        glBegin(GL_TRIANGLES);
        float red=0.2,green=0.5,blue=0.1; // para ir mudando as cores
        for(i = 0; i < pontosAux.size(); i+=3){ /** desenha triangulos, lendo 3 a 3 do vetor de pontos **/
            glColor3f((GLfloat) fmod(red, 1.0), (GLfloat) fmod(green, 1.0), (GLfloat) fmod(blue, 1.0));
            glVertex3f(pontosAux[i], pontosAux[i+1], pontosAux[i+2]);
            red+=0.1;green+=0.2;blue+=0.2;
        }
        glEnd();
    } /** Para o caso de termos subgrupos **/
    vector<Group*>::iterator k;
    for(k = p->grup.begin();k != p->grup.end();++k){
        drawFigures(*k);
    }
    glPopMatrix();
}

/**
 * drawScene:
 * Desenhamos cada um dos grupos que lemos no XML, do primeiro para o ultimo
**/

void drawScene(Scene* c){
    int i;
    for (i=0; i < c->grupos.size();i++){
        drawFigures(c->grupos[i]);
    }
}


/**
 * readGroup:
 * Por cada grupo que temos, criamos uma classe Group correspondente a esse grupo, com os seus modelos e subgrupos.
 * Por sua vez, se dentro de um grupo temos outro grupo(subgrupo), chamamos recursivamente este metodo
 * para criarmos as classes group para cada um dos subgrupos encontrados
**/

Group* readGroup(XMLElement* grupo){ /// AQUI MUDEI O NOME DE elemName ----------> tag
    string tag;
    Group* g = new Group();
    const char* ficheiro;
    const char* atri;
    vector<int>::const_iterator i;
    vector<float> aux;

    for (XMLElement* filho = grupo->FirstChildElement(); filho != NULL; filho = filho->NextSiblingElement()){
        tag = filho->Value();

        if(tag == "Group"){
            g->grup.push_back(readGroup(filho));
        }else if(tag == "Translate")
            
        {   
            atri = filho->Attribute("x");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("y");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("z");
            if(atri != NULL) aux.push_back(atof(atri));
            g->transf.insert(pair<int,vector<float> >(T,aux)); /// insere no map a trasformação (T; x,y,z)
            aux.clear(); /// para ele nao ter os pontos da trasnformação anterior
        }
        else if(tag == "Scale")
        {  
           
            atri = filho->Attribute("x");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("y");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("z");
            if(atri != NULL) aux.push_back(atof(atri));
            g->transf.insert(pair<int,vector<float> >(S,aux)); /// insere no map a trasformação (S; x,y,z)
            aux.clear(); /// para ele nao ter os pontos da trasnformação anterior
        }else if(tag == "Rotate")
        {  
            
            atri = filho->Attribute("ang");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("x");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("y");
            if(atri != NULL) aux.push_back(atof(atri));
            atri = filho->Attribute("z");
            if(atri != NULL) aux.push_back(atof(atri));
            g->transf.insert(pair<int,vector<float> >(R,aux)); /// insere no map a trasformação (R; ang,x,y,z)
            aux.clear(); /// para ele nao ter os pontos da trasnformação anterior

        }
        else if(tag == "Models")
        { /** UMA TAG MODELS SO PODE TER UM MODEL **/
            XMLElement* neto = filho->FirstChildElement();
                ficheiro = neto->Attribute("file"); // vai buscar os atributos de file
                if (ficheiro != NULL) {
                    g->mod.push_back(read_File3D(ficheiro));
                }
        }
    }

    return g;
}

/**
 * beginParsing:
 * Lemos o ficheiro XML, guardando cada grupo no vetor grupos da classe Scene
**/
Scene* beginParsing(XMLElement* xmlE){
    Scene* c = new Scene();
    for (XMLElement* filho = xmlE->FirstChildElement()->ToElement(); filho != NULL; filho = filho->NextSiblingElement()){
        if(readGroup(filho)==NULL)
            return NULL;
        else { // cada grupo que temos guardamos na classe Group, no  vetor de grupos, e assim sucessivamente para cada subgrupo encontrado
            c->grupos.push_back(readGroup(filho));
        }
    }
    return c;
}




void processKeys(unsigned char key, int xx, int yy) {
    switch (key) {
        case 'q':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;

        case 'e':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        case 'w':
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;
    }
}




void processMouseButtons(int button, int state, int xx, int yy) {
    //cout << tracking << endl;

    if (state == GLUT_DOWN)  {
        startX = xx;
        startY = yy;
        if (button == GLUT_LEFT_BUTTON)
            tracking = 1;
        else if (button == GLUT_RIGHT_BUTTON)
            tracking = 2;
        else
            tracking = 0;
    }
    else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha += (xx - startX);
            beta += (yy - startY);
        }
        else if (tracking == 2) {

            raio -= yy - startY;
            if (raio < 3)
                raio = 3.0;
        }
        tracking = 0;
    }
}

void processMouseMotion(int xx, int yy) {

    int deltaX, deltaY;
    int alphaAux, betaAux;
    int rAux;

    if (!tracking)
        return;

    deltaX = xx - startX;
    deltaY = yy - startY;

    if (tracking == 1) {


        alphaAux = alpha + deltaX;
        betaAux = beta + deltaY;

        if (betaAux > 85.0)
            betaAux = 85.0;
        else if (betaAux < -85.0)
            betaAux = -85.0;

        rAux = raio;
    }
    else if (tracking == 2) {

        alphaAux = alpha;
        betaAux = beta;
        rAux = raio - deltaY;
        if (rAux < 3)
            rAux = 3;
    }
    camX = (float) (rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0));
    camZ = (float) (rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0));
    camY = (float) (rAux * sin(betaAux * 3.14 / 180.0));
}




void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(camX,camY,camZ,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);
    //glPolygonMode(GL_FRONT, GL_LINE);
    if(c!=NULL)
        drawScene(c);

    //End of frame
    glutSwapBuffers();
}



int main(int argc, char **argv) {
    cout << "__/\\\\\\\\____________/\\\\\\\\_______/\\\\\\\\\\_______/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\_________/\\\\\\\\\\\\\\\\\\_____" << endl;
    cout << "_\\/\\\\\\\\\\\\________/\\\\\\\\\\\\_____/\\\\\\///\\\\\\____\\///////\\\\\\/////______/\\\\\\///\\\\\\_____/\\\\\\///////\\\\\\___" << endl;
    cout << "_\\/\\\\\\//\\\\\\____/\\\\\\//\\\\\\___/\\\\\\/__\\///\\\\\\________\\/\\\\\\_________/\\\\\\/__\\///\\\\\\__\\/\\\\\\_____\\/\\\\\\___" << endl;
    cout << "_\\/\\\\\\\\///\\\\\\/\\\\\\/_\\/\\\\\\__/\\\\\\______\\//\\\\\\_______\\/\\\\\\________/\\\\\\______\\//\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\/____" << endl;
    cout << "_\\/\\\\\\__\\///\\\\\\/___\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\//////\\\\\\____" << endl;
    cout << "_\\/\\\\\\____\\///_____\\/\\\\\\_\\//\\\\\\______/\\\\\\________\\/\\\\\\_______\\//\\\\\\______/\\\\\\__\\/\\\\\\____\\//\\\\\\___" << endl;
    cout << "_\\/\\\\\\_____________\\/\\\\\\__\\///\\\\\\__/\\\\\\__________\\/\\\\\\________\\///\\\\\\__/\\\\\\____\\/\\\\\\_____\\//\\\\\\__" << endl;
    cout << "_\\/\\\\\\_____________\\/\\\\\\____\\///\\\\\\\\\\/___________\\/\\\\\\__________\\///\\\\\\\\\\/_____\\/\\\\\\______\\//\\\\\\_" << endl;
    cout << "_\\///______________\\///_______\\/////_____________\\///_____________\\/////_______\\///________\\///__" << endl;
    cout << "João Gomes - a70400 - LCC                                               João Dias - a72095 - MIEI" << endl;
    cout << "Joel Morais - a70841 - MIEI                                        Luis Ventuzelos - a73002 - LCC\n" << endl;


    string ficheiro;


    ficheiro = "Sistema.xml";

    XMLDocument doc;
    int loadOkay = doc.LoadFile(ficheiro.c_str());
    /**
     * loadOkay:
     * Returns XML_SUCCESS (0) on success, or
     * an errorID.
    **/
    if (!loadOkay) {
        XMLElement *scene = doc.FirstChildElement("Scene");
        if (!scene) { // se documento nao tem nada
            cerr << "Failed to load file: No root element." << endl;
            doc.Clear();
            return EXIT_FAILURE; // retorna o erro do cerr
        }
  
        c = new Scene();
        c = beginParsing(scene);

        if (c == NULL) {
            cerr << "ERRO" << endl;
        }
    }
    else{
        cerr << doc.ErrorName() << endl;
        cout<<"ola ERRO"<<endl;
        return EXIT_FAILURE;
    }
    // inicialização
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");


    // registo de funções
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);

    // pôr aqui registo da funções do teclado e rato
    glutKeyboardFunc(processKeys);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);





    // alguns settings para OpenGL
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // entrar no ciclo do GLUT
    glutMainLoop();

    return 1;
}