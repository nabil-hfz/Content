////Compleixtate(n*m*m)
////Alg. Edmonds Karp
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n, m, s, t, fluxMaxim; // s-nodul sursa, t-nodul destinatie din reatea asociata grafului
//vector<vector<int>> capacitate;
//vector<vector<int>> rezultat;
//vector<int> parante;
//vector<vector<int>> listaAdiacenta;
//vector<int> degreeIn, degreeOut;
//ifstream fin("harta.in");
//ofstream fout("harta.out");
//
//void citire()
//{
//    fin >> n;
//    degreeIn = vector<int>(n + 1, 0);
//    degreeOut = vector<int>(n + 1, 0);
//    listaAdiacenta = vector<vector<int>>(2*n+3, vector<int>());
//    capacitate = vector<vector<int>>(2 * n + 3, vector<int>(2 * n + 3, 0));
//    rezultat = vector<vector<int>>(n + 1, vector<int>());
//    parante = vector<int>(2 * n + 2, -1);
//    for (int i = 1; i <= n; i++)
//    {
//        fin >> degreeOut[i] >> degreeIn[i];
//    }
//}
//// constructia retelei de transport
//void constructieRetea()
//{
//    s = 0; t = 2 * n + 1;
//    // conectam toate nodurile din multimea X la sursa printr-o muchie cu capacitatea egala cu gradul exterior al fiecarui nod
//    for (int i = 1; i <= n; i++)
//    {
//        listaAdiacenta[s].push_back(i);
//        listaAdiacenta[i].push_back(s);
//        capacitate[s][i] = degreeOut[i];
//    }
//    // conectam toate nodurile din multimea Y la destinatie print-o muchie cu capacitatea egala cu gradul intern al fiecarui nod
//    for (int i = n + 1; i < t; i++)
//    {
//        listaAdiacenta[t].push_back(i);
//        listaAdiacenta[i].push_back(t);
//        capacitate[i][t] = degreeIn[i-n];
//    }
//    // conectam toate nodurile din multimile X si Y print-o muchie cu capacitatea egala cu 1 mai putin nodurile care provin din acelasi nod
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = n + 1; j < t; j++)
//        {
//            if (i + n == j)
//                continue;
//            listaAdiacenta[i].push_back(j);
//            listaAdiacenta[j].push_back(i);
//            capacitate[i][j] = 1;
//        }
//    }
//}
//// resetam vectorul de parinti
//void reseteazaParinte()
//{
//    for (int i = 0; i <= t; i++)
//    {
//        parante[i] = -1;
//    }
//    parante[s] = -2;
//}
//// descoperirea unui lant nesaturat si calculam capacitatea reziduala minima a lantului
//int bfs()
//{
//    queue<pair<int, int>> coada;
//    coada.push({ s,10000000 });
//    while (!coada.empty())
//    {
//        int nod = coada.front().first;
//        int flux = coada.front().second;
//        coada.pop();
//        for (int i : listaAdiacenta[nod] )
//        {
//            if (parante[i] == -1 && capacitate[nod][i] > 0)
//            {
//                parante[i] = nod;
//                int flow = min(flux, capacitate[nod][i]);
//                if (i == t)
//                {
//                    return flow;
//                }
//                coada.push({ i,flow });
//            }
//        }
//    }
//    return 0;
//}
//void afisare()
//{
//    fout << fluxMaxim << "\n";
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j : rezultat[i])
//        {
//            fout << i << " " << j - n << "\n";
//        }
//    }
//}
//int main()
//{
//    citire();
//    constructieRetea();
//    reseteazaParinte();
//    int c;
//    // cat timp descoperim un lant nesaturat in reteua de transport
//    while (c=bfs())
//    {
//        fluxMaxim = fluxMaxim + c;
//        int nod = t;
//        // revizuim fluxul de-a lungul lantului descoperit si adaugam sau scoatem din lista de adiacenta a grafului rezultat muchii
//        while (nod != s)
//        {
//            int stramos = parante[nod];
//            capacitate[stramos][nod] -= c;
//            capacitate[nod][stramos] += c;
//            if (nod > s && nod < t && stramos<t && stramos>s)
//            {
//                // adaugam muchia in graful rezultat daca este directa
//                if (stramos < nod)
//                {
//                    rezultat[stramos].push_back(nod);
//                }
//                    // scoatem muchia din graful rezultat daca este indirecta
//                else
//                {
//                    for (int i = 0; i < rezultat[nod].size(); i++)
//                    {
//                        if (rezultat[nod][i] == stramos)
//                        {
//                            rezultat[nod].erase(rezultat[nod].begin() + i);
//                            break;
//                        }
//                    }
//                }
//            }
//            nod = stramos;
//        }
//        reseteazaParinte();
//    }
//    afisare();
//}