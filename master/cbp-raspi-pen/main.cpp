#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "physics.h"
#include "EasyBMP/EasyBMP.h"
using namespace std;

int main(){
    //========================================================================
    /*
    velocity - milimeters per second
    time - seconds
    acceleration - milimetros per seconds at square
    output - milimeters
    */
    cout << deslEscalar(0, 1.3, 3.2) << "\n";

    float* vect = deslVectorial(0, 1, 1.345, 2.2, 6.4);
    cout << "(" << vect[0] << "," << vect[1] << "," << vect[2] << ")\n";

    free(vect);

    //======================================================================

    string line;
    string delimiter = ",";
    size_t pos = 0;
    string token;
    float x, y, z;
    bool isX = true;

    ifstream accelFile ("triangulo.raw");
    ofstream deslFile;
    deslFile.open ("desl.raw");
    if (accelFile.is_open()) {
         while ( getline (accelFile,line) ) {



          cout << "Original: "<< line << endl;


          while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                std::cout << token << std::endl;
                if (isX){
                    x = ::atof(token.c_str());
                    isX = false;
                }
                else{
                    y = ::atof(token.c_str());
                    isX = true;
                }
                line.erase(0, pos + delimiter.length());
            }
            cout << line << endl;
            z = ::atof(line.c_str());

            cout << "The output in float: " << x << "," << y << "," << z << endl;

            //here is needed to calculate the real aceleration in milimeters per second

            float realX = realAcceleration(x, 155);
            float realY = realAcceleration(y, 155);
            float realZ = realAcceleration(y, 155);

            //now is time to calculate the displacement for the given accelerations per each axis.
            //the time should to be a constant = 1 second / sample rate.(45Hz~50Hz)
            float * deslVector = deslVectorial(0, 0.022, realX, realY, realZ);

            deslFile << deslVector[0] << "," << deslVector[1] << "," << deslVector[2] << endl;

        }
        accelFile.close();
        deslFile.close();
    }
    else cout << "Unable to open file";

    //======================================================================
    //now there is a file named desl.raw, containing the displacement vectors.
    //to a rapid test, we want now to burn a .bmp image with the vectors.

    BMP output;
    output.SetSize(800,600);
    output.SetBitDepth(8);

    float point[2];
    point[0] = 300;
    point[1] = 350;




    ifstream deslFile2 ("desl.raw");
    if (deslFile2.is_open()) {
         while ( getline (deslFile2,line) ) {

          cout << "Original: "<< line << endl;


          while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                std::cout << token << std::endl;
                if (isX){
                    x = ::atof(token.c_str());
                    isX = false;
                }
                else{
                    y = ::atof(token.c_str());
                    isX = true;
                }
                line.erase(0, pos + delimiter.length());
            }
            cout << line << endl;
            z = ::atof(line.c_str());

            //tweak
            x = x+ 0.14;
            y = y+ 0.13;

            cout << "The output in float2: " << x << "," << y << "," << z << endl;



            output(point[0],point[1])->Red = 0;
            output(point[0],point[1])->Green = 0;
            output(point[0],point[1])->Blue = 0;

            if (point[0]+x <= output.TellHeight()){
                point[0]+= x;
            }
            if (point[1]+y <= output.TellWidth()){
                point[1]+= y;
            }


            /*
            if(x<0 && point[0] > 0){
                point[0]--;
            }
            else if(point[0] < output.TellWidth()){
                point[0]++;
            }
            if(y<0 && point[1] > 0){
                point[1]--;
            }
            else if(point[1] < output.TellHeight()){
                point[1]++;
            }*/

        }
        deslFile2.close();
    }
    else cout << "Unable to open file";


    output.WriteToFile("output.bmp");


    return 0;
}
