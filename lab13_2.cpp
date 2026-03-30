#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}
void updateImage(bool image[N][M],int X,int Y,int Z){
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 70; j++){
            if(sqrt(pow((i-Y),2)+pow((j-Z),2)) <= X-1) image[i][j] = 1;
        }
    }
}

void showImage(const bool image[N][M]){
    for(int k = 0; k < 72; k++){ cout << '-';}
    cout << '\n';
    for(int m = 0; m < 30; m++){
        cout << '|';
        for(int o = 0; o < 70; o++){
            if(image[m][o] == 0){ 
                cout << ' ';}
            else if(image[m][o] == 1) cout << '*';
        }
        cout << '|';
        cout << '\n';
    }
    for(int n = 0; n < 72; n++){ 
        cout << '-';
    }
    cout << '\n';
}