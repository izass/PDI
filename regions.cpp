#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>


using namespace cv;
using namespace std;

int main(int, char**) {
    Mat image;
    Vec2i p1, p2;
    
    //abre a imagem que se deseja trabalhar
    image =imread("biel.png", CV_LOAD_IMAGE_GRAYSCALE);
    if(!image.data)
        cout << "não foi possivel abrir a imagem\n";
    
    //nomeia a janela de exibição e a coloca para assumir as dimensões da imagem
    namedWindow("janela", WINDOW_AUTOSIZE);
    
    //leitura dos pontos
    while(1){
        cout << "informe as coordenadas do ponto 1!\n";
        cin >> p1[0] >> p1[1];
        
        cout << "informe as coordenadas do ponto 2!\n";        
        cin >> p2[0] >> p2[1];

        if (p1[0]<0||p1[0]>256||p1[1]<0||p1[1]>256||p2[0]<0||p2[0]>256||p2[1]<0||p2[1]>256)
            cout << "pontos invalidos, informe novamente!\n";
        else 
            break;
    }
    
    //aqui fazemos o negativo da imagem
    for(int i=p1[0];i<p1[1];i++){
        for(int j=p2[0];j<p2[1];j++)
            image.at<uchar>(i,j)=255-image.at<uchar>(i,j);        
    }

    //imprime a imagem numa janela na tela
    imshow("janela", image);
    waitKey();

    return 0;
}