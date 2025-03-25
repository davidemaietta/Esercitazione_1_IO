#include <fstream>
#include <iostream>
#include <iomanip>

double transform(double value)
{
	return 0.75*value-1.75;
}

int main()
{
	
std::ifstream infile("./data.txt");

if(infile.fail())
{
	std::cerr << "errore nell'apertura del file" 
	<< std::endl;
	return 1;
} // provo ad aprire il file da cui devo leggere i dati

std::ofstream outfile("../result.txt"); //creo file output nella cartella Exercise2 e non Debug
outfile << std::setprecision(16) << std::scientific; // imposto notazione scientifica

if (outfile.is_open()) {
	outfile << "# N Mean\n";
} else {
	std::cerr << "Errore nell'apertura del file"
	<< std::endl;
	return 1;
} // scrivo la prima riga
	
double val;
double tval; 
unsigned int n = 0;
double mean = 0;
while(infile >> val)
{
	n++;
	tval = transform(val);
	mean = (mean*(n-1)+tval)/n;
	outfile << n << " " << mean << "\n";

}

outfile.close();
std::cout << "file result.txt successivamente compilato" <<std::endl;

	return 0;
}
