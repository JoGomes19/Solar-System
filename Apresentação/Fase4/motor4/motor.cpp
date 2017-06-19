#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <map>
#include <vector>
#include "tinyxml2.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <IL/il.h>


#define T 0.0
#define S 1.0
#define R 2.0

using namespace std;
using namespace tinyxml2;

double alpha = 0.0f, beta = 0.0f, raio = 20.0f;
double camX, camY, camZ;
int startX, startY, tracking = 0;
long currentTime = 0;
float t = 0.0;



// GLfloat amb[3] = {0.2, 0.2, 0.2};
// GLfloat diff[3] = {1.0, 1.0, 1.0};
// GLfloat specularLight[3] = { 0.0f, 0.0f, 0.0f};


class Point{
public:
    float pontos[3];
};



class Model{
public:
    string nome; //nome do modelo desenhado
    const char* img;
    GLuint buffer; // para dizermos qual é o nosso vbo
    vector <float> pontos; //vector que armazena os pontos
    GLuint norm;
    GLuint textCoord;
    GLuint textId;
    int numeroVertices;
    vector <float> normal; // pontos normais
    vector <float> textura; //pontos de textura
};

class Group{
public:
    int timeR, timeT;
    float before;
    float s; //contador de segundos
    int n;   //numero de pontos
    map<int,vector<float> > transf;
    vector<Point*> pontos;
    vector <Model*> mod;
    vector <Group*> grup;
};

class Scene{
public:
    //vector<Ligths*> luzes;
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






void getCatmullRomPoint(float t, int *indices, float *res,vector<Point*> p1) {
    float res_aux[4];
    int i;
    // catmull-rom matrix
    float m[4][4] = {   {-0.5f,  1.5f, -1.5f,  0.5f},
                        { 1.0f, -2.5f,  2.0f, -0.5f},
                        {-0.5f,  0.0f,  0.5f,  0.0f},
                        { 0.0f,  1.0f,  0.0f,  0.0f}};

    for (i=0; i<4; i++)
        res_aux[i]= pow(t,3) * m[0][i] +  pow(t,2) * m[1][i] + t * m[2][i] + m[3][i];

    for(i=0;i<3;i++){
        res[i]=res_aux[0]*p1[indices[0]]->pontos[i] + res_aux[1]*p1[indices[1]]->pontos[i] +res_aux[2]*p1[indices[2]]->pontos[i] + res_aux[3]*p1[indices[3]]->pontos[i];
    }
}

// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(Group* g,float gt, float *res) {

    float t = gt * g->n; // this is the real global t
    int index = floor(t);  // which segment
    t = t - index; // where within  the segment

    // indices store the points
    int indices[4];
    indices[0] = (index + g->n-1)%g->n;   indices[1] = (indices[0]+1)%g->n;
    indices[2] = (indices[1]+1)%g->n; indices[3] = (indices[2]+1)%g->n;

    getCatmullRomPoint(t, indices, res,g->pontos);
}

void renderCatmullRomCurve(Group* g) {
    float  gtt;
    float res[3];
    // desenhar a curva usando segmentos de reta - GL_LINE_LOOP

    glBegin(GL_LINE_LOOP);
    for (gtt=0; gtt<1; gtt+=0.01){
        getGlobalCatmullRomPoint(g,gtt,res);
        glVertex3fv(res);
    }
    glEnd();
}



Model* read_File3D(const char* fig , const char* file2){
    int i=0;
    Model* m = new Model();
    m->nome = fig;
    m->img = file2;
    float a,b,c;
    int n,j=0;

    ifstream input_file(fig);
    input_file >> n;
    m->numeroVertices = n;
    int t = 0, texturas = (n/3)*2; // numero de texturas

    while(i<(n)){
        input_file >> a >> b >> c;
                    m->pontos.push_back(a);i++;
                    m->pontos.push_back(b);i++;
                    m->pontos.push_back(c);i++;

    }
    while(j<(n)){
        input_file >> a >> b >> c;
                    m->normal.push_back(a);j++;
                    m->normal.push_back(b);j++;
                    m->normal.push_back(c);j++;

    }
    while(t<(texturas)){
        input_file >> a >> b;
                    m->textura.push_back(a);t++;
                    m->textura.push_back(b);t++;

    }

    //printf("%d %d %d\n", i,j,h );
    return m;
}



void drawFigures(Group* p){
    vector<float> aux;
    map<int,vector<float> >::iterator it;
    //int t=0;
    unsigned i;
    float timeT;
    glPushMatrix();
    for (it=p->transf.begin(); it != p->transf.end(); ++it){
        aux = it->second;
        float res[3];
        if(it->first == T ){
            renderCatmullRomCurve(p);
            getGlobalCatmullRomPoint(p,(p->s),res);
            glTranslatef(res[0],res[1],res[2]);
        }

        //glPushMatrix();
        if(it->first == R){
            long int tempo = aux[0];
            glRotatef(360*(currentTime%tempo)/(tempo),aux[1],aux[2],aux[3]);
        }

        if(it->first == S){
            glScalef(aux[0],aux[1],aux[2]);
        }
        //se o tempo anterior estiver a 0 actualize com o tempo currente
        if(p->before==0)
            p->before = currentTime;
        else{//actualiza a variavel t de modo que demora o tempo de translacao
            timeT = aux[0];
            p->s += ((currentTime-(p->before))/(timeT*1000));
            p->before = currentTime;
        }

    }


    for(i = 0;i< p->mod.size();i++){
        //glBindBuffer(GL_ARRAY_BUFFER,p->mod[i]->buffer);//activar o vbo
        if(p->mod[i]->nome == "anel.3d") glRotatef(-25,0,0,1) ;
			glBindBuffer(GL_ARRAY_BUFFER,p->mod[i]->buffer);//activar o vbo
			glVertexPointer(3,GL_FLOAT,0,0);

			glBindBuffer(GL_ARRAY_BUFFER,p->mod[i]->textCoord);
			glTexCoordPointer(2, GL_FLOAT,0,0);
			glBindTexture(GL_TEXTURE_2D,p->mod[i]->textId);

		   	float white[4] = {1,0,0,0};
			glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
			glDrawArrays(GL_TRIANGLES,0,(p->mod[i]->numeroVertices)/3);
			glBindTexture(GL_TEXTURE_2D,0);
		    }
		    //glEnd();
    ////
    /** Para o caso de termos subgrupos **/
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
    unsigned i;
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
Group* readGroup(XMLElement* grupo){
    string tag,elemN;
    Group* g = new Group();
    const char* ficheiro_planeta;
    const char* ficheiro_textura;
    const char* atri;
    vector<int>::const_iterator i;
    vector<float> aux;
    g->timeR = g->timeT = 0.0;

    int nPontos = 0;

    for (XMLElement* filho = grupo->FirstChildElement(); filho != NULL; filho = filho->NextSiblingElement()){
        tag = filho->Value();

        if(tag == "Group"){
            g->grup.push_back(readGroup(filho));
        }else if(tag == "Translate"){
            atri = filho ->Attribute("time");
            if(atri != NULL) aux.push_back(atof(atri)); //g->timeT
            g->transf.insert(pair<int,vector<float> >(T,aux)); /// insere no map a trasformação (T; x,y,z)
            aux.clear(); /// para ele nao ter os pontos da trasnformação anterior
            g->before = 0.0;
            g->s =0.0;
            for (XMLElement* elem3 = filho->FirstChildElement(); elem3 != NULL; elem3 = elem3->NextSiblingElement()){
                elemN = elem3 ->Value();
                if(elemN == "point"){
                    Point* ponto1 = new Point();
                    ponto1->pontos[0] = atof(elem3->Attribute("x"));
                    ponto1->pontos[1] = atof(elem3->Attribute("y"));
                    ponto1->pontos[2] = atof(elem3->Attribute("z"));
                    g->pontos.push_back(ponto1);
                    nPontos++;
                }
                g->n=nPontos;
            }
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
            atri = filho->Attribute("time");
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
            ficheiro_planeta = neto->Attribute("file"); // vai buscar os atributos de ficheiro
            ficheiro_textura = neto->Attribute("texture");
            if (ficheiro_planeta != NULL && ficheiro_textura != NULL) {
                g->mod.push_back(read_File3D(ficheiro_planeta,ficheiro_textura));
            }
        }
    }

    return g;
}

/**
 * Funções para tratar do VBO:
 *    -> groupToVBO
 *    -> initVBO
 **/

void groupToVBO(Group* g){
    unsigned j;
	size_t i;
for(i=0;i < g->mod.size();i++){
    Model *m = g->mod[i];
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glGenBuffers(1,&(m->buffer));//criar um novo vbo , e usar a variavel criada para armazenar o identificador do vbo
	glBindBuffer(GL_ARRAY_BUFFER,m->buffer);//ativar o vbo
	glBufferData(GL_ARRAY_BUFFER, m->pontos.size()*sizeof(float),&(m->pontos).front(),GL_STATIC_DRAW);//carregar os vertices do vertexb para o

	//glGenBuffers(1,&(m->norm));
	//glBindBuffer(GL_ARRAY_BUFFER, m->norm);
	//glBufferData(GL_ARRAY_BUFFER,m->normal.size()*sizeof(float),&(m->normal).front(),GL_STATIC_DRAW);
	
	glGenBuffers(1,&(m->textCoord));
	glBindBuffer(GL_ARRAY_BUFFER,m->textCoord);
	glBufferData(GL_ARRAY_BUFFER, m->textura.size()*sizeof(float), &(m->textura).front(), GL_STATIC_DRAW);
	

	unsigned int t,tw,th;
	unsigned char *texData;
    
	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	ilGenImages(1,&t);
	ilBindImage(t);
	ilLoadImage((ILstring)(m->img));
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	texData = ilGetData();
    
	glGenTextures(1,&(m->textId));
	
	glBindTexture(GL_TEXTURE_2D,m->textId);
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_T,GL_REPEAT);
    
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
    }

	

    for(j = 0;j<g->grup.size();j++){ /// se o grupo tiver mais grupos (caso da terra e do saturno) entra neste ciclo
        groupToVBO(g->grup[j]);
    }
}




void initVBO(Scene* s){
    size_t i;
    for(i = 0;i<s->grupos.size();i++){ /// por cada grupo da Scene, vamos por os seus pontos no VBO, com a função groupToVBO
        groupToVBO(s->grupos[i]);
    }
}


/**
 * beginParsing:
 * Lemos o ficheiro XML, guardando cada grupo no vetor grupos da classe Scene
**/
Scene* beginParsing(XMLElement* xmlE){
    Scene* c = new Scene();
    //const char* value;
    for (XMLElement* filho = xmlE->FirstChildElement()->ToElement(); filho != NULL; filho = filho->NextSiblingElement()){
        if(readGroup(filho)==NULL)
            return NULL;
        else { // cada grupo que temos guardamos na classe Group, no  vetor de grupos, e assim sucessivamente para cada subgrupo encontrado
            c->grupos.push_back(readGroup(filho));
        }
    }
    return c;
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


    currentTime = glutGet(GLUT_ELAPSED_TIME);
	glPolygonMode(GL_FRONT, GL_FILL);
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
        cout<<"ERRO"<<endl;
        return EXIT_FAILURE;
    }
    // inicialização
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM-Fase 4");


    // registo de funções
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);

    // pôr aqui registo da funções do teclado e rato
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);


    // alguns settings para OpenGL
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_2D);

    #ifndef __APPLE__
    glewInit();
    #endif
    initVBO(c);
    //glEnable(GL_LIGHTING);



    // entrar no ciclo do GLUT
    glutMainLoop();

    return 1;
}
