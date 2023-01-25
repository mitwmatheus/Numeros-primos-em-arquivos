#include <iostream>
#include <fstream>
using namespace std;

int main(){
	/*ofstream a("inteiros.dat");
	int n;
	cin>>n;
	int *v=new int [n];
	
	for(int i=0;i<n;i++){
		cin>>v[i];
		a.write((const char *) (&v[i]), sizeof(int)); //Armazena o que esta no vetor v na pos[i] dentro do arquivo bin
	}*/
	
	ifstream primos("primos.dat");
	int tam, n;
	primos.seekg(0, ios::end);
	tam=(primos.tellg())/sizeof(int);
	primos.seekg(0, ios::beg);
	for(int i=0;i<tam;i++){
		primos.read((char *) (&n),sizeof(int));
		cout<<n;
	}
		
	return 0;
}
