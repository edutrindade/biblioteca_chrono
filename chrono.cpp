#include <iostream>
#include <chrono>
#include <ctime>
#include <windows.h>

using namespace std;
using namespace chrono;

#define TAMANHO 50000

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    cout << "*** Imprimindo " << TAMANHO << " asteriscos ***" << endl;
    system("PAUSE");

    // Definição do clock t1 para marcar o início da contagem
    steady_clock::time_point t1 = steady_clock::now();

    for (int i = 0; i < TAMANHO; i++)
    {
        cout << " * ";
    }

    // Definição do clock t2 para marcar o término da contagem
    steady_clock::time_point t2 = steady_clock::now();

    // Criação via template class da variável tempo que receberá a duration_cast da chrono de t2 - t1
    duration<double> tempo = duration_cast<duration<double>>(t2 - t1);

    cout << "\nTempo de execução: " << tempo.count() << " segundos." << endl;

    return 0;
}