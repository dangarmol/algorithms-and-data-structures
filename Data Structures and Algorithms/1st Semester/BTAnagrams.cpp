// Anagramas

// Formar todas las palabras de m letras sobre un alfabeto de {1, n} sin letras repetidas

#include <iostream>
using namespace std;

bool esValida(char solucion[], int k)
{
    int i = 0;
    while (i < k && solucion[i] != solucion[k]) i++;
    return i == k;
}

bool esSolucion(int k, int m)
{
    return k == (m - 1);
}

void tratarSolucion(char solucion[], int n)
{
    cout << "Solucion: ";
    
    for (int i = 0; i <= n; i++)
        cout << solucion[i] << " ";
    cout << endl;
}

void anagramas(char sol[], int k, int n, int m)
{
    for (int offset = 0; offset < n; offset++)
    {
        sol[k] = 'a' + offset;
        if (esValida(sol, k))
        {
            if (esSolucion(k, m))
                tratarSolucion(sol, k);
            else
                anagramas(sol, k + 1, n, m);
        }
    }
}

int main()
{
    char v[10000];
    int a, b;
    cin >> a >> b;
    anagramas(v, 0, a, b);
    return 0;
}
