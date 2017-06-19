//#define _USE_MATH_DEFINES

#include <iostream>
//#include <list>
//#include <map>
#include <sstream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

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

    float a, b, c,h,r;
    int st,sl,s;




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
        outputFile << length/2  << " " << height << " " << -length/2 << " " << -length/2 << " " << height << " " << -length/2 << " " << -length/2 << " " << height << " " << length/2  << endl;

        outputFile << length/2  << " " << height << " " << -length/2 << " " << -length/2 << " " << height << " " << length/2  << " " << length/2  << " " << height << " " << length/2  << endl;

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
        float hP,rP,h,r,y;
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

    else if (figura == "esfera"){
        cout << "Escreva por esta ordem: raio slices stacks" << endl;
        cin >> r >> sl >> st;
        float raio = r;
        int slices = sl;
        int stacks = st;
        float alpha;
        float beta = -M_PI / 2;
        float angF; // angulo da fatia
        outputFile.open("esfera.3d");
        for(int i =0; i < slices; i++){
            alpha = 3 * M_PI/2;
            for(int j=0; j < stacks; j++){
                angF = beta + M_PI / slices;

                outputFile << raio*cos(angF)*sin(alpha) << " " << raio*sin(angF) << " " << raio*cos(angF)*cos(alpha) << endl;
                outputFile << raio*cos(beta)*sin(alpha) << " " << raio*sin(beta) << " " << raio*cos(beta)*cos(alpha) << endl;

                alpha = alpha + 2 * M_PI/stacks;
                outputFile << raio*cos(beta)*sin(alpha) << " " << raio*sin(beta) << " " << raio*cos(beta)*cos(alpha) << endl;

                outputFile << raio*cos(beta)*sin(alpha) << " " << raio*sin(beta) << " " << raio*cos(beta)*cos(alpha) << endl;
                outputFile << raio*cos(angF)*sin(alpha) << " " << raio*sin(angF) << " " << raio*cos(angF)*cos(alpha) << endl;

                alpha = alpha - 2 * M_PI/stacks;
                outputFile << raio*cos(angF)*sin(alpha) << " " << raio*sin(angF) << " " << raio*cos(angF)*cos(alpha) << endl;
                alpha = alpha + 2 * M_PI/stacks;
            }
            beta = beta + M_PI/slices;
        }
        outputFile.close();
    }
    else{
        cout << "Figura invalida." << endl;
        return -1;
    }
    cout << "Figura gerada com sucesso." << endl;

    return 0;
}