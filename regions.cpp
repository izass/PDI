#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>


using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat origin, negative;
    Vec2i p1, p2;
    int row, col;
    
    //abre a imagem que se deseja trabalhar
    origin =imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    if(!origin.data)
        cout << "não foi possivel abrir a imagem\n";
    
    //nomeia a janela de exibição e a coloca para assumir as dimensões da imagem
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Região negativa", WINDOW_AUTOSIZE);

    row = origin.rows;
    col = origin.cols;

    origin.copyTo(negative);
        
    //leitura dos pontos
    while(1){
        cout << "informe as coordenadas do ponto 1!\n";
        cin >> p1[0] >> p1[1];
        
        cout << "informe as coordenadas do ponto 2!\n";        
        cin >> p2[0] >> p2[1];

        if (p1[0]<0||p1[0]>row||p1[1]<0||p1[1]>col||p2[0]<0||p2[0]>row||p2[1]<0||p2[1]>col)
            cout << "pontos invalidos, informe novamente!\n";
        else 
            break;
    }
    
    //aqui fazemos o negativo da imagem
    for(int i=p1[0];i<p1[1];i++){
        for(int j=p2[0];j<p2[1];j++)
            negative.at<uchar>(i,j)=255-negative.at<uchar>(i,j);        
    }

    //imprime a imagem numa janela na tela
    imshow("Original", origin);
    waitKey();
    imshow("Região negativa", negative);
    waitKey();

    return 0;
}