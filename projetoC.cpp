#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <string>
#include <sstream>

std::string linha, valor;
std::list<int> idades;
std::string vacina;          
std::string dose;     
std::string sexo;                       
char marcador = ',';
int cont = 0;  
int contAstraZeneca = 0;
int contDoseUnica = 0;
int contMasc = 0;
int contFem = 0;
int contMenorIdade = 0; 
float percentualFem;
float percentualMasc;

int main()
{
    std::ifstream arquivo("/Users/giuliamello/Desktop/projetoC/ExampleCSV.csv", std::ios::in);

    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) 
    {
        std::stringstream colunas(linha);
        std::string coluna;
        int j = 0;
        int idade = 0; 

        while (std::getline(colunas, valor, marcador)) { 
            if (j == 10) { 
                vacina = valor; 
                if (vacina == "ASTRAZENECA/FIOCRUZ") {
                    contAstraZeneca++;
                }

            } else if (j == 12) { 
                dose = valor; 
                if (dose == "Única") {
                    contDoseUnica++;
                }

            } else if (j == 3) { 
                sexo = valor;
                if (sexo.at(0) == 'M') {
                    contMasc++;
                }
                if (sexo.at(0) == 'F') {
                    contFem++;
                }

            } else if (j == 1) { 
                idade = std::stoi(valor); 
                if (idade < 18) {
                    contMenorIdade++;
                }
            }
            j++; 
        }

        cont++; 
    }


    percentualFem = ((float)contFem / cont) * 100;
    percentualMasc = ((float)contMasc / cont) * 100;

    printf("Quantidade de vacinas ASTRAZENECA/FIOCRUZ aplicadas: %d\n", contAstraZeneca);
    printf("Quantidade de vacinas dose única: %d\n", contDoseUnica);
    printf("Percentual de mulheres: %.2f%%\n", percentualFem);
    printf("Percentual de homens: %.2f%%\n", percentualMasc);
    printf("Quantidade de menores de idade: %d\n", contMenorIdade);

    return 0;
}
