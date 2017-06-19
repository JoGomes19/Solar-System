//#define _USE_MATH_DEFINES

#include <iostream>
//#include <list>
//#include <map>
#include <sstream>
#include <string>
#include <fstream>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;
map<int,vector<float> > pontos;


class Triplo{
public:
    double x;
    double y;
    double z;
};


Triplo* normal(Triplo* p1, Triplo* p2 ,Triplo* p3){
    Triplo* n = new Triplo();
    Triplo* v1 = new Triplo();
    Triplo* v2 = new Triplo();

    /// v1 = p2-p1
    v1->x = p2->x - p1->x;
    v1->y = p2->y - p1->y;
    v1->z = p2->z - p1->z;

    /// v2 = p3-p1
    v2->x = p3->x - p1->x;
    v2->y = p3->y - p1->y;
    v2->z = p3->z - p1->z;

    /// n = v1*v2/norma(v1*v2)
    n->x = v1->y * v2->z - v1->z * v2->y;
    n->y = v1->z * v2->x - v1->x * v2->z;
    n->z = v1->x * v2->y - v1->y * v2->x;

    float length;

    /// norma = sqrt(x^2+y^2+z^2)
    length = (float) sqrt((n->x * n->x) +
                          (n->y * n->y) +
                          (n->z * n->z));
    if (length == 0.0f)
        length =  1.0f;

    n->x = n->x / length;
    n->y = n->y / length;
    n->z = n->z / length;

    return n;
}


map<int,vector<double>> drawSphere(float raio,int slices,int stacks){
    map<int,vector<double> > pontos;
    vector<double> aux_P;
    vector<double> aux_N;
    vector<double> aux_T;
    /**
     * Chaves do map:
     * 1 -> pontos;
     * 2 -> normais;
     * 3 -> texturas;
    **/
    //pontos.insert(pair<int,vector<double> >(i,aux));
    float alpha=0;
    float beta = -M_PI / 2;
    float angF; // angulo da fatia
    Triplo* p1   = new Triplo();
    Triplo* p2   = new Triplo();
    Triplo* p3   = new Triplo();
    Triplo* norm;
    double x,y,z;

    for(int i=0; i < slices; i++){
        alpha = 0.0;

        for(int j=0; j < stacks; j++){
            /// triangulo 1
            angF = beta + M_PI / slices;
            x = raio*cos(angF)*sin(alpha);
            y = raio*sin(angF);
            z = raio*cos(angF)*cos(alpha);
            p1->x = x;
            p1->y = y;
            p1->z = z;
            aux_P.push_back(x);
            aux_P.push_back(y);
            aux_P.push_back(z);

            alpha = alpha + 2 * M_PI/stacks;
            x = raio*cos(beta)*sin(alpha);
            y = raio*sin(beta);
            z = raio*cos(beta)*cos(alpha);
            p2->x = x;
            p2->y = y;
            p2->z = z;
            aux_P.push_back(x);
            aux_P.push_back(y);
            aux_P.push_back(z);

            //alpha = alpha + 2 * M_PI/stacks;
            x = raio*cos(angF)*sin(alpha);
            y = raio*sin(angF);
            z = raio*cos(angF)*cos(alpha);
            p3->x = x;
            p3->y = y;
            p3->z = z;
            aux_P.push_back(x);
            aux_P.push_back(y);
            aux_P.push_back(z);

            norm = normal(p1,p2,p3); /// normal no ponto p1
            aux_N.push_back(norm->x);
            aux_N.push_back(norm->y);
            aux_N.push_back(norm->z);

            norm = normal(p2,p1,p3); /// normal no ponto p2
            aux_N.push_back(norm->x);
            aux_N.push_back(norm->y);
            aux_N.push_back(norm->z);

            norm = normal(p3,p2,p1); /// normal no ponto p3
            aux_N.push_back(norm->x);
            aux_N.push_back(norm->y);
            aux_N.push_back(norm->z);


            /// triangulo 2
            x = raio*cos(beta)*sin(alpha);
            y = raio*sin(beta);
            z = raio*cos(beta)*cos(alpha);
            p1->x = x;
            p1->y = y;
            p1->z = z;
            aux_P.push_back(x);
            aux_P.push_back(y);
            aux_P.push_back(z);

            alpha = alpha - 2 * M_PI/stacks;
            x = raio*cos(angF)*sin(alpha);
            y = raio*sin(angF);
            z = raio*cos(angF)*cos(alpha);
            p2->x = x;
            p2->y = y;
            p2->z = z;
            aux_P.push_back(x);
            aux_P.push_back(y);
            aux_P.push_back(z);


            //alpha = alpha - 2 * M_PI/stacks;
            x = raio*cos(beta)*sin(alpha);
            y = raio*sin(beta);
            z = raio*cos(beta)*cos(alpha);
            p3->x = x;
            p3->y = y;
            p3->z = z;
            aux_P.push_back(x);
            aux_P.push_back(y);
            aux_P.push_back(z);

            norm = normal(p1,p2,p3); /// normal no ponto p1
            aux_N.push_back(norm->x);
            aux_N.push_back(norm->y);
            aux_N.push_back(norm->z);

            norm = normal(p2,p1,p3); /// normal no ponto p2
            aux_N.push_back(norm->x);
            aux_N.push_back(norm->y);
            aux_N.push_back(norm->z);
            norm = normal(p3,p2,p1); /// normal no ponto p3
            aux_N.push_back(norm->x);
            aux_N.push_back(norm->y);
            aux_N.push_back(norm->z);


            aux_T.push_back((j+1.0f)/stacks);
            aux_T.push_back((i+1.0f)/slices);

            aux_T.push_back((j+1.0f)/stacks);
            aux_T.push_back((i*1.0f)/slices);

            aux_T.push_back((j*1.0f)/stacks);
            aux_T.push_back((i+1.0f)/slices);

            aux_T.push_back((j+1.0f)/stacks);
            aux_T.push_back((i*1.0f)/slices);

            aux_T.push_back((j*1.0f)/stacks);
            aux_T.push_back((i*1.0f)/slices);

            aux_T.push_back((j*1.0f)/stacks);
            aux_T.push_back((i+1.0f)/slices);


            alpha = alpha + 2 * M_PI/stacks;
        }
        beta = beta + M_PI/slices;
    }
    pontos.insert(pair<int,vector<double> >(1,aux_P));
    pontos.insert(pair<int,vector<double> >(2,aux_N));
    pontos.insert(pair<int,vector<double> >(3,aux_T));

    return pontos;
}





vector<float> splitString(string line,int type){ // type = 1 entao é porque estamos a trabalhar ocm floats, caso contrario estamos com ints
    vector<float> values;
    vector<string> aux;
    //string s = "scott>=tiger>=mushroom";
    string delimiter = ",";

    size_t pos = 0;
    string token;
    while ((pos = line.find(",")) != string::npos) {
        token = line.substr(0, pos);
        //cout << token << endl;
        line.erase(0, pos + delimiter.length());
        if(type == 1)
            values.push_back(stof(token));
        else values.push_back(stoi(token));
    }
    pos = line.find("\n");
    token = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());
    if(type == 1)
        values.push_back(stof(token));
    else values.push_back(stoi(token));
    return values;
}

Triplo makeMatrix(vector <float> p, float u, float v){ /// olhamos para um triplo como se fosse um ponto
    Triplo ret;

    int i, j, pos = 0;
    float mp[4][4][3];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++, pos+=3) {
            mp[i][j][0] = p[pos];   // x
            mp[i][j][1] = p[pos+1]; // y
            mp[i][j][2] = p[pos+2]; // z
        }
    }

    /// matrizes patch (estão no formulario)
    float M[4][4] = { { -1, 3, -3, 1 },{ 3, -6, 3, 0 },{ -3, 3, 0, 0 },{ 1, 0, 0, 0 } };
    float UM[1][4];

    // u^3 u^2 u 1
    // v^3 v^2 v 1
    float U[1][4] = { {(float) pow(u, 3), (float) pow(u, 2), u, 1 } };
    float V[4][1] = {{(float) pow(v, 3)}, {(float) pow(v, 2)}, {v }, {1 } };
    ///



    for (i = 0; i < 4; i++) {
        UM[0][i] = (U[0][0] * M[0][i])
                   + (U[0][1] * M[1][i])
                   + (U[0][2] * M[2][i])
                   + (U[0][3] * M[3][i]);
    }

    float UMP[1][4][3];
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            UMP[0][i][j] =
                    (UM[0][0] * mp[0][i][j])
                    + (UM[0][1] * mp[1][i][j])
                    + (UM[0][2] * mp[2][i][j])
                    + (UM[0][3] * mp[3][i][j]);
        }
    }

    float MV[4][1];

    for (i = 0; i < 4; i++) {
        MV[i][0] = (M[i][0] * V[0][0])
                   + (M[i][1] * V[1][0])
                   + (M[i][2] * V[2][0])
                   + (M[i][3] * V[3][0]);
    }

    float UMPMV[3];
    for (i = 0; i < 3; i++) {
        UMPMV[i] = (UMP[0][0][i] * MV[0][0])
                   + (UMP[0][1][i] * MV[1][0])
                   + (UMP[0][2][i] * MV[2][0])
                   + (UMP[0][3][i] * MV[3][0]);
    }

    ret.x = UMPMV[0];
    ret.y = UMPMV[1];
    ret.z = UMPMV[2];

    return ret;
}


void drawTeapot(int slices, int stacks) {
    float difU = (1 / (float)slices);
    float difV = 1 / (float)stacks;

    map<int, vector<float>>::const_iterator map_iter;



    ofstream outputFile;
    outputFile.open("cometa.3d");
    for(map_iter = pontos.cbegin(); map_iter != pontos.cend() ; ++map_iter) {
        for (float j = 0; j < 1; j += difU) {
            for (float k = 0; k < 1; k += difV) {
                Triplo p0, p1, p2, p3,p4,p5;
                /** pontos dos triangulos **/
                p0 = makeMatrix(map_iter->second, j, k);
                outputFile << p0.x << " " << p0.y << " " <<  p0.z << endl;

                p1 = makeMatrix(map_iter->second, j, k + difV);
                outputFile << p1.x << " " << p1.y << " " <<  p1.z << endl;

                p2 = makeMatrix(map_iter->second, j + difU, k+difV);
                outputFile << p2.x << " " << p2.y << " " <<  p2.z << endl;

                p4 = makeMatrix(map_iter->second, j + difU, k+difV);
                outputFile << p4.x << " " << p4.y << " " <<  p4.z << endl;

                p5 = makeMatrix(map_iter->second, j+difU, k);
                outputFile << p5.x << " " << p5.y << " " <<  p5.z << endl;

                p3 = makeMatrix(map_iter->second, j, k);
                outputFile << p3.x << " " << p3.y << " " <<  p3.z << endl;
            }
        }
    }
}


void readPatch(string nome,int slices, int stacks){ /* http://www.cplusplus.com/forum/beginner/11304/ */
    ifstream myfile(nome.c_str());
    int n_patches=0;
    map<int,vector<float> > pontos_Aux;
    if (myfile.is_open()) {
        string line;
        getline(myfile,line);               /** passo 1 **/
        //cout << line << endl;
        n_patches = stoi(line);
        int i=0;
        vector<float> indices;
        ///vector<string> aux;
        while(i<n_patches){                 /** passo 2 **/
            getline(myfile,line); // lemos a proxima linha que ainda nao foi lida
            indices = splitString(line,0);
            pontos_Aux.insert(pair<int,vector<float> >(i,indices));
            i++;
            indices.clear();
        }
        getline(myfile,line);               /** passo 3 **/
        int n_points = stoi(line);
        //cout << control_points << endl;
        i=0;
        vector <float> aux;
        vector <float> control_points;
        while(i<n_points){                  /** passo 4 **/
            getline(myfile,line);
            //cout << line << endl;
            aux = splitString(line,1);
            for(unsigned j=0; j<aux.size(); j++)
                control_points.push_back(aux[j]);
            i++;
        }
        i=0;
        aux.clear();
        for( auto map_iter = pontos_Aux.cbegin() ; map_iter != pontos_Aux.cend() ; ++map_iter ) { /** passo 5 **/
            for(unsigned vec_ind=0; vec_ind < map_iter->second.size() ; vec_ind++) {
                //cout << map_iter->second[vec_iter] << endl;
                int x = map_iter->second[vec_ind]*3; /// cada ponto de controlo vale como 3 prosições
                aux.push_back(control_points[x]);
                aux.push_back(control_points[x+1]);
                aux.push_back(control_points[x+2]);
            }
            //cout << aux.size() << endl;
            pontos.insert(pair<int,vector<float> >(i,aux));
            aux.clear();
            i++;
        }
        cout << "Parsing feito com sucesso" << endl;
        drawTeapot(slices, stacks);
    }
    else {
        cout << "Erro ao abrir o ficheiro" << endl;
        return;
    }
}



int main() {
    ofstream outputFile;
    string figura;
    // cin le do stdin
    cout << "_____/\\\\\\\\\\\\\\\\\\\\\\\\_____________________________________________________/\\\\\\______________________________" << endl;
    cout << "___/\\\\\\//////////_____________________________________________________\\/\\\\\\______________________________" << endl;
    cout << "__/\\\\\\________________________________________________________________\\/\\\\\\______________________________" << endl;
    cout << "_\\/\\\\\\____/\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\___/\\\\/\\\\\\\\\\\\\\___/\\\\\\\\\\\\\\\\\\___________\\/\\\\\\______/\\\\\\\\\\_____/\\\\/\\\\\\\\\\\\\\__" << endl;
    cout << "_\\/\\\\\\___\\/////\\\\\\___/\\\\\\/////\\\\\\_\\/\\\\\\/////\\\\\\_\\////////\\\\\\_____/\\\\\\\\\\\\\\\\\\____/\\\\\\///\\\\\\__\\/\\\\\\/////\\\\\\_" << endl;
    cout << "_\\/\\\\\\_______\\/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\__\\/\\\\\\___\\///____/\\\\\\\\\\\\\\\\\\\\___/\\\\\\////\\\\\\___/\\\\\\__\\//\\\\\\_\\/\\\\\\___\\///__" << endl;
    cout << "_\\/\\\\\\_______\\/\\\\\\_\\//\\\\///////___\\/\\\\\\__________/\\\\\\/////\\\\\\__\\/\\\\\\__\\/\\\\\\__\\//\\\\\\__/\\\\\\__\\/\\\\\\_________" << endl;
    cout << "_\\//\\\\\\\\\\\\\\\\\\\\\\\\/___\\//\\\\\\\\\\\\\\\\\\\\_\\/\\\\\\_________\\//\\\\\\\\\\\\\\\\/\\\\_\\//\\\\\\\\\\\\\\/\\\\__\\///\\\\\\\\\\/___\\/\\\\\\_________" << endl;
    cout << "__\\////////////______\\//////////__\\///___________\\////////\\//___\\///////\\//_____\\/////_____\\///__________" << endl;
    cout << "João Gomes - a70400 - LCC                                                       João Dias - a72095 - MIEI" << endl;
    cout << "Joel Morais - a70841 - MIEI                                                Luis Ventuzelos - a73002 - LCC\n" << endl;

    cout << "Que figura pretende gerar ?" << endl;
    cin >> figura;

    float a, b, c,h,r,r_;
    int st,sl;




    if (figura == "box"){
        cout << "Escreva o tamanho dos 3 lados" << endl;
        cin >> a >> b >> c;
        float x_ = a;
        float y_ = b;
        float z_ = c;

        outputFile.open("box.3d");
        // face de tras
        outputFile << x_/2  << " " << 0 << " " << -z_/2 << " " << -x_/2 << " " << 0 << " " << -z_/2 << " " << -x_/2 << " " << y_ << " " << -z_/2 << endl;
        outputFile << x_/2  << " " << 0 << " " << -z_/2 << " " << -x_/2 << " " << y_ << " " << -z_/2 << " " << x_/2 << " " << y_ << " " << -z_/2 << endl;
        // face da direita
        outputFile << x_/2  << " " << 0 << " " << -z_/2 << " " << x_/2 << " " << y_ << " " << z_/2 << " " << x_/2 << " " << 0 << " " << z_/2 << endl;
        outputFile << x_/2  << " " << 0 << " " << -z_/2 << " " << x_/2 << " " << y_ << " " << -z_/2 << " " << x_/2 << " " << y_ << " " << z_/2 << endl;
        // face da frente
        outputFile << x_/2  << " " << 0 << " " << z_/2 << " " << -x_/2 << " " << y_ << " " << z_/2 << " " << -x_/2 << " " << 0 << " " << z_/2 << endl;
        outputFile << x_/2  << " " << 0 << " " << z_/2 << " " << x_/2  << " " << y_ << " " << z_/2 << " " << -x_/2 << " " << y_ << " " << z_/2 << endl;
        // face da esquerda
        outputFile << -x_/2 << " " << 0 << " " << z_/2 << " " << -x_/2 << " " << y_ << " " << -z_/2 << " " << -x_/2 << " " << -0 << " " << -z_/2 << endl;
        outputFile << -x_/2 << " " << 0 << " " << z_/2 << " " << -x_/2 << " " << y_ << " " << z_/2 << " " << -x_/2 << " " << y_ << " " << -z_/2 << endl;
        // face de baixo
        outputFile << x_/2  << " " << 0 << " " << z_/2 << " " << -x_/2 << " " << 0 << " " << z_/2 << " " << -x_/2 << " " << 0 << " " << -z_/2 << endl;
        outputFile << x_/2  << " " << 0 << " " << z_/2 << " " << -x_/2 << " " << -0 << " " << -z_/2 << " " << x_/2 << " " << 0 << " " << -z_/2 << endl;
        // face de cima
        outputFile << -x_/2 << " " << y_ << " " << -z_/2 << " " << -x_/2 << " " << y_ << " " << z_/2 << " "  << x_/2 << " "  << y_ << " " << z_/2 << endl;
        outputFile << x_/2  << " " << y_ << " " << z_/2  << " " << x_/2  << " " << y_ << " " << -z_/2 << " " << -x_/2 << " " << y_ << " " << -z_/2 << endl;
        outputFile.close();
    }

    else if (figura == "plano"){
        cout << "Escreva por esta ordem: lado altura" << endl;
        cin >> a >> b;
        float length = a;
        float height = b;

        outputFile.open("plano.3d");
        outputFile << length/2  << " " << height << " " << -length/2 << -length/2 << " " << height << " " << -length/2 << -length/2 << " " << height << " " << length/2  << endl;

        outputFile << length/2  << " " << height << " " << -length/2 << -length/2 << " " << height << " " << length/2  << length/2  << " " << height << " " << length/2  << endl;

        outputFile.close();


    }

    else if (figura == "cone"){
        cout << "Escreva por esta ordem: raio altura slices stacks" << endl;
        cin >> r >> h >> sl >> st;
        float raio   = r;
        float height = h;
        int slices   = sl;
        int stacks   = st;
        int i=0,j;
        float ang,angP;
        float h_camada = height/stacks;
        float hP,rP,r,y;
        float p = 1*raio/height;
        outputFile.open("cone.3d");
        for(i=0; i <= slices; i++){
            ang = i*2*M_PI/slices;
            angP = (i+1)*2*M_PI/slices;
            r = raio;
            y = 0;
            j=0;
            h = height-(h_camada*j);
            hP = height-(h_camada*(j+1));

            for(h = height - (h_camada*j); j < stacks; j++){
                hP = height-(h_camada*(j+1));
                rP = hP*p;

                outputFile << r*sin(ang) << " " << y  << " " << r*cos(ang)  << " " << rP*sin(angP) << " " << y+h_camada << " " << rP*cos(angP) << " " <<  rP*sin(ang) << " " << y+h_camada  << " " << rP*cos(ang)  << endl;
                outputFile << r*sin(ang) << " " <<  y << " " <<  r*cos(ang) << " " << r*sin(angP)  << " " <<  y         << " " <<  r*cos(angP) << " " << rP*sin(angP) << " " <<  y+h_camada << " " <<  rP*cos(angP) << endl;


                r = rP;
                h = hP;
                y += h_camada;
                hP = height-(h_camada*(j+1));
                rP = hP*p;
            }
            outputFile << raio*sin(ang)  << " " << 0.0f << " " << raio*cos(ang)  << endl;
            outputFile << 0.0f           << " " << 0.0f << " " << 0.0f           << endl;
            outputFile << raio*sin(angP) << " " << 0.0f << " " << raio*cos(angP) << endl;

        }
        outputFile.close();
    }

    else if (figura == "planeta" || figura == "sol"){ // esfera
        cout << "Escreva por esta ordem: raio slices stacks" << endl;
        cin >> r >> sl >> st;
        float raio = r;
        int slices = sl;
        int stacks = st;
        //vector<double> pontos;
        //vector<double> texturas;
        //vector<double> normais;
        map<int,vector<double>> pontos = drawSphere(raio,slices,stacks);
        outputFile.open(figura+".3d");
        outputFile <<  pontos.cbegin()->second.size() << endl;
        for( auto map_iter = pontos.cbegin() ; map_iter != pontos.cend() ; ++map_iter ) {
            // cout << map_iter->first << endl;
            for (unsigned j = 0; j < map_iter->second.size();) {
                if(map_iter->first == 3){
                    outputFile << map_iter->second[j] << " " << map_iter->second[j+1] << endl;
                    j+=2;
                }
                else {
                    outputFile << map_iter->second[j] << " " << map_iter->second[j + 1] << " " << map_iter->second[j + 2] << " " << endl;
                    j+=3;
                }
            }
        }
        outputFile.close();
    }

    else if (figura == "anel"){
        cout << "Escreva por esta ordem: raioInterno raioExterno altura slices stacks" << endl;
        cin >> r >> r_ >> h >> sl >> st;
        float rI = r;
        float rO = r_;
        int slices = sl;
        int stacks = st;
        float height = h;
        float h  = height/stacks,heightCurrent,heightProx;
        float ang,angP,radius = rI+rO;
        outputFile.open("anel.3d");
        for(int i=0; i < slices; i++){
            heightCurrent=0,heightProx=h;
            ang = i*2*M_PI/slices;
            angP = (i+1)*2*M_PI/slices;
            outputFile << rI*sin(ang)      << " " << height << " " << rI*cos(ang)      << endl;
            outputFile << radius*sin(ang)  << " " << height << " " << radius*cos(ang)  << endl;
            outputFile << radius*sin(angP) << " " << height << " " << radius*cos(angP) << endl;

            outputFile << rI*sin(ang)      << " " << height << " " << rI*cos(ang)      << endl;
            outputFile << radius*sin(angP) << " " << height << " " << radius*cos(angP) << endl;
            outputFile << rI*sin(angP)     << " " << height << " " << rI*cos(angP)     << endl;
            //////
            outputFile << radius*sin(angP)<< " " << 0 << " " << radius*cos(angP) << endl;
            outputFile << radius*sin(ang) << " " << 0 << " " << radius*cos(ang)  << endl;
            outputFile << rI*sin(ang)     << " " << 0 << " " << rI*cos(ang)      << endl;

            outputFile << rI*sin(angP)    << " " << 0 << " " << rI*cos(angP)     << endl;
            outputFile << radius*sin(angP)<< " " << 0 << " " << radius*cos(angP) << endl;
            outputFile << rI*sin(ang)     << " " << 0 << " " << rI*cos(ang)      << endl;
            for(int j=0; j < stacks;j++){
                /// fora
                outputFile << radius*sin(angP) << " " << heightCurrent << " " << radius*cos(angP) << endl;
                outputFile << radius*sin(ang)  << " " << heightProx    << " " << radius*cos(ang)  << endl;
                outputFile << radius*sin(ang)  << " " << heightCurrent << " " << radius*cos(ang)  << endl;

                outputFile << radius*sin(angP) << " " << heightProx    << " " << radius*cos(angP) << endl;
                outputFile << radius*sin(ang)  << " " << heightProx    << " " << radius*cos(ang)  << endl;
                outputFile << radius*sin(angP) << " " << heightCurrent << " " << radius*cos(angP) << endl;
                /// dentro

                outputFile << rI*sin(ang) << " " << heightCurrent << " " << rI*cos(ang)  << endl;
                outputFile << rI*sin(ang) << " " << heightProx    << " " << rI*cos(ang)  << endl;
                outputFile << rI*sin(angP)<< " " << heightCurrent << " " << rI*cos(angP) << endl;

                outputFile << rI*sin(angP)<< " " << heightProx    << " " << rI*cos(angP) << endl;
                outputFile << rI*sin(angP)<< " " << heightCurrent << " " << rI*cos(angP) << endl;
                outputFile << rI*sin(ang) << " " << heightProx    << " " << rI*cos(ang)  << endl;
                heightCurrent = heightProx;
                heightProx+=h;
            }
        }
    }

    else if (figura == "cometa"){
        cout << "Escreva por esta ordem: stacks slices" << endl;
        cin >> sl >> st;
        readPatch("teapot.patch",sl,st);
    }

    else{
        cout << "Figura invalida." << endl;
        return -1;
    }
    cout << "Figura gerada com sucesso." << endl;

    return 0;
}