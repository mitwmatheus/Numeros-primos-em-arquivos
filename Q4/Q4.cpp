#include <iostream>
#include <fstream>
using namespace std;

//Ao invés de pedir a quantidade de inteiros que o arquivos possui eu descobri usando o seekg por isso não tem nenhuma interacao

int main(){
	ifstream l("inteiros.dat");
	int tam, div=0, quant=0;
	l.seekg(0, ios::end);
	tam=(l.tellg())/sizeof(int);
	l.seekg(0, ios::beg);
	int *v=new int[tam];
	for(int i=0;i<tam;i++){
		l.read((char *) (&v[i]),sizeof(int));
	}
	
	ofstream primos("primos.dat");
	
	for(int i=0;i<tam;i++){
		for(int j=1;j<=v[i];j++){
			if(v[i]%j==0){
				div++;
			}
		}
		if(div==2 or v[i]==1){
			//cout<<v[i]<<endl;
			primos.write((const char *) (&v[i]),sizeof(int));
			quant++;
		}
		div=0;
	}
	
	cout<<quant<<" ";
	
	for(int i=0;i<tam;i++){
		for(int j=1;j<=v[i];j++){
			if(v[i]%j==0){
				div++;
			}
		}
		if(div==2 or v[i]==1){
			cout<<v[i]<<" ";
		}
		div=0;
	}
	return 0;
}
