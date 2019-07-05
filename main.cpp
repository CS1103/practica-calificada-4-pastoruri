#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;
int position=0; //yo se profe, esta variable global esta fea, pero no termine de implementar el future con el promise
template<typename T>
void searche(vector<T> vec,int lim_inf,int lim_sup){
    int aux=vec[lim_inf];
    int pos=lim_inf;
    for(int i=lim_inf; i<lim_sup;i++){
        if(vec[i]>aux){
            aux=vec[i];
            pos=i;
        }
    }
    cout<<"El mayor del intervalo "<<lim_inf<<"-"<<lim_sup<<" es "<<vec[pos]<<endl;
   if(position<vec[pos]) position=vec[pos];
}

template <typename T>
void search(vector<T> myvec, int numhilos){
    vector<thread> hilos;
    int len = myvec.size();
    int divisions = len/numhilos;
    int lastlen=len-numhilos*divisions+divisions;
    int limmin=0;
    int limsup=divisions;
    for(int i=0;i<numhilos-1;i++){
        hilos.emplace_back(&searche<T>,myvec,limmin,limsup);
        limmin+=divisions;
        limsup+=divisions;
    }
    hilos.emplace_back(&searche<T>,myvec,len-lastlen,len);

    for (int i = 0; i < numhilos; i++) {
        hilos[i].join();
    }

    cout<<endl<<"El mayor numero del vector es "<<position;
}




int main() {

    vector<int> a={1,2,3,4,5,6,7,8,9,0};
    search(a,4);


    return 0;
}
