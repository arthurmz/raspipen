#include "ImageGenerator.h"
#include <SixDegreesOfFreedom.h>
#include <iomanip>
#include "ProcessGyroscopeData.h"

using namespace std;





void GenerateImage(BMP* bmpParam, std::queue<SixDegreesOfFreedom> dataHolder){

	std::queue<SixDegreesOfFreedom> saida = ProcessGyroscopeData(dataHolder);

	std::cout << "hue " << saida.size() << "\n";
	while (saida.size() > 0){
		SixDegreesOfFreedom f = saida.front();
		saida.pop();
		std::cout << f.EX << " " << f.EY << " " << f.EZ << " "<< f.AX << " " << f.AY << " " << f.AZ << "\n";
	}

	
	//configurando a imagem======================================================================
	BMP bmp = *bmpParam;

	bmp.SetSize(800, 600);
	bmp.SetBitDepth(8);

	int i = 200;
	int j = 150;


	int YAnterior = 0;
	int ZAnterior = 0;


	//============================================================================================
	/*while(!dataHolder.empty()){
		SixDegreesOfFreedom SixDoF0 = dataHolder.front();
		dataHolder.pop();

		cout << setiosflags(ios::fixed) << setprecision(2) << "Filtro0: "<< SixDoF0.EX << " " << SixDoF0.EY << " " 
		<< SixDoF0.EZ << " " << SixDoF0.AX << " " << SixDoF0.AY << " " << SixDoF0.AZ << "\n";

		SixDegreesOfFreedom SixDoF1 = ProcessGyroscopeData(SixDoF0);

		cout << setiosflags(ios::fixed) << setprecision(2) << "Filtro1: "<< SixDoF1.EX << " " << SixDoF1.EY << " " 
		<< SixDoF1.EZ << " " << SixDoF1.AX << " " << SixDoF1.AY << " " << SixDoF1.AZ << "\n";

		int Ypercorrido = (SixDoF1.AY/500) + YAnterior;
		int Zpercorrido = (SixDoF1.AZ/500) + ZAnterior;

		int w;
		int k;
		for(w = 0; w < Ypercorrido; w++){
			for(k = 0; k < Zpercorrido; k++){
				bmp(i+k,j+w)->Red = 0;
				bmp(i+k,j+w)->Green = 0;
				bmp(i+k,j+w)->Blue = 0;
			}
		}
		i = i + k;
		j = j + w;
	}


		
	bmp.WriteToFile("test.bmp");*/
	
}

