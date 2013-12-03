#include "ImageGenerator.h"
#include <SixDegreesOfFreedom.h>

void GenerateImage(BMP* bmpParam, std::queue<SixDegreesOfFreedom> dataHolder){

	BMP bmp = *bmpParam;

	bmp.SetSize(800, 600);
	bmp.SetBitDepth(8);


	/*Inicio da imagem: ponta superior esquerda
	i: i pixels a esquerda da origem
	j: j pixels a baixo da origem

	Varrendo a imagem da esquerda pra direita, linha por linha*/
	/*int i,j;
	for(j = 0; i < bmp.TellHeight(); j++){
		for(i = 0; i < bmp.TellWidth(); i++){
			bmp(i,j)->Red = 0;
			bmp(i,j)->Green = 0;
			bmp(i,j)->Blue = 0;
		}
	}*/
	bmp.WriteToFile("test.bmp");
	
}

