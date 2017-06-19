#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <vector>
#include <tinyxml.h>
#include <math.h>
#include <fstream>


using namespace std;



float alpha = 0.0f, beta = 0.0f, raio = 30.0f;
double camX=20.0, camY=30.0, camZ=20.0;

vector <string> xmlF; // vetor com os nomes dos ficheiros


void atualizaCamara() {
	// passa coordenadas esfericas para coordenadas cartesianas
	camX = raio * cos(beta) * sin(alpha);
	camY = raio * sin(beta);
	camZ = raio * cos(beta) * cos(alpha);
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	double ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void drawFigures(){

    float a, b, c;
	float red=0.2,green=0.5,blue=0.1; // para ir mudando as cores

	vector<string>::const_iterator nome;
	for (nome = xmlF.begin(); nome != xmlF.end(); ++nome) {

		// nome = xmlF.begin(), 'nome' fica com apontador para a primeira posição de 'xmlF'
		if (*nome == "box.3d"){
			ifstream input_file("box.3d");
			glBegin(GL_TRIANGLES);
			while (input_file >> a >> b >> c){ // le 3 inteiros de cada vez
				glColor3f((GLfloat) fmod(red, 1.0), (GLfloat) fmod(green, 1.0), (GLfloat) fmod(blue, 1.0));
				glVertex3f(a, b, c);
				red+=0.1;green+=0.2;blue+=0.2;
			}
			glEnd();
		}
		else if (*nome == "cone.3d"){
			glBegin(GL_TRIANGLES);
			ifstream input_file("cone.3d");
			while (input_file >> a >> b >> c){
				glColor3f((GLfloat) fmod(red,1.0),(GLfloat) fmod(green,1.0),(GLfloat) fmod(blue,1.0));
				glVertex3f(a, b, c);
				red+=0.1;green+=0.2;blue+=0.2;
			}
			glEnd();
		}
		else if (*nome == "plano.3d"){
			glBegin(GL_TRIANGLES);
			ifstream input_file("plano.3d");
			while (input_file >> a >> b >> c){
				glColor3f((GLfloat) fmod(red,1.0),(GLfloat) fmod(green,1.0),(GLfloat) fmod(blue,1.0));
				glVertex3f(a, b, c);
				red+=0.1;green+=0.2;blue+=0.2;
			}
			glEnd();
		}
		else if (*nome == "esfera.3d"){
			glBegin(GL_TRIANGLES);
			ifstream input_file("esfera.3d");
			while (input_file >> a >> b >> c){
				glColor3f((GLfloat) fmod(red, 1.0), (GLfloat) fmod(green, 1.0), (GLfloat) fmod(blue, 1.0));
				glVertex3f(a, b, c);
				red+=0.1;green+=0.2;blue+=0.2;

			}
			glEnd();
		}
	}
}


void renderScene(void) {
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glPolygonMode(GL_FRONT,GL_LINE);
	//glPolygonMode(GL_BACK,GL_FILL);


	// set the camera
	glLoadIdentity();
	gluLookAt(camX,camY,camZ,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	drawFigures();

	// End of frame
	glutSwapBuffers();
}



void camara(unsigned char key, int x, int y) {
		if(key == 'd' || key == 'D')
			alpha -=0.1;
		else if(key == 'a' || key == 'A')
			alpha += 0.1;
		else if(key == 'q' || key == 'Q'){
			beta += 0.1f;
			if (beta > 1.5f)
				beta = 1.5f;
		}
		else if(key == 'e' || key == 'E'){
			beta -= 0.1f;
			if (beta < -1.5f)
				beta = -1.5f;
		}
		else if(key == 'w' || key == 'W'){
			raio -= 0.5f;
			if (raio < 0.1f)
				raio = 0.1f;
		}
		else if(key == 's' || key == 'S')
			raio += 0.5f;

	atualizaCamara(); // para atualizar a posiçao da camara
	glutPostRedisplay();
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
    cout << "Introduza o nome do ficheiro XML que pretende usar:" << endl;
    cin >> ficheiro;
    cout << ficheiro << endl; // depois tiramos isto, so serve para teste


	TiXmlDocument doc(ficheiro.c_str());
    // abrir o ficheiro xml pretendido
    // c_str() passa o objeto string para o tipo char*
    // assim podemos abrir qualquer ficheiro xml que quisermos,
    // desde que esteja no seguinte formato:
    // <scene>
    //      <Model file = "fig.3d" />
    // </scene>

	bool loadOkay = doc.LoadFile(); // variavel booleana diz se o ficheiro foi aberto corretamente, isto é, se o ficheiro existe
	if(loadOkay){	// caso o ficheiro pretendido exista
	    const char* file;
	    TiXmlElement *scene = doc.FirstChildElement("scene");
	    if(!scene){ // se documento nao tem nada
	    	cerr << "Failed to load file: No root element." << endl;
			doc.Clear();
			return EXIT_FAILURE; // retorna o erro
	    }

		TiXmlElement *linha = scene->FirstChildElement("Model")->ToElement();
        // para navegarmos ate às linhas que têm campo Model, e depois ver
        // cada um dos seus irmãos mais novos, podemos fazer isto porque
        // escrevemos o xml manualmente e sabemos como ele esta escrito


		for (; linha != NULL; linha = linha->NextSiblingElement()) {
		// ciclo para percorrer o ficheiro xml e para desenhar cada uma das figuras que estão lá referidas

			// podemos fazer isto porque escrevemos o xml manualmente
			file = linha->Attribute("file"); // vai buscar os atributos de file, que neste caso é apenas 1

			if (file != NULL){
				xmlF.push_back(file); // guarda o nome do ficheiro.3d no final do vetor "nome"
			}
		} // for

	} // if
	else{ // caso o ficheiro pretendido não exista, devolve segmentation fault
		cerr << doc.ErrorDesc() << endl;
		return EXIT_FAILURE;
	} 


// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(camara);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
