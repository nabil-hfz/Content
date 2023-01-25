//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <climits>
//#include <stack>
//#include <unordered_map>
//
//using namespace std;
//
//// ifstream fin("input.txt");
//// ofstream fout("output.txt");
//
//
//
///*
// * Algoritmul este prezentat in curs. Pasii sunt urmatorii:
// * 1. Se adauga o sursa si un destinatie fictive
// * 2. Se adauga muchiile de la sursa si destinatie la cele doua multimi de noduri
// * 3. Se considrea acum fiecare muchie din graf ca avand capacitatea 1
// * 4. Se aplica algoritmul lui Ford-Fulkerson
// * 5. Se afiseaza numarul de muchii din multimea de muchii care au fost folosite
// */
//
//// ---------------------- //
//// Construim o structura de date care ne va ajuta sa reprezentam un graf
//struct Edge
//{
//    // Pozitia ne va trebui la Ford-Fulkerson
//    int from, to, capacity, pozitie;
//};
//
//int n, m, e, s, d;
//int total_nodes;
//vector<vector<int>> graph;
//vector<Edge> edges;
//// ---------------------- //
//
//
//
//
//// Functia care adauga o muchie in graful rezidual
//void addEdge (int x, int y)
//{
//    // In lista de adiacenta o sa pastram indexul muchiei
//    int index = (int) edges.size();
//
//    // Creem muchia
//    Edge e1 = {x, y, 1, index + 1};
//
//    // Adaugam muchia in lista de adiacenta
//    graph[y].push_back(index + 1);
//    edges.push_back(e1);
//
//    // Trebuie sa adaugam si muchia inversa pentru graful residual
//    Edge e2 = {y, x, 0, index};
//    graph[x].push_back(index);
//    edges.push_back(e2);
//
//}
//
//// Folosim BFS pentru a determina daca exista un drum de la sursa la destinatie
//// In Ford-Fulkerson vom folosi BFS pentru a determina daca exista un drum de la sursa la destinatie, care sa aiba capacitatea mai mare decat 0
//// Asta inseamna ca mai putem adauga flux pe acel drum
//
//// Vector de parinti pentru a putea parcurge arborele bfs
//vector<int> parante;
//// Vector unde tinem daca un nod a fost vizitat sau nu
//vector<int> vizitat;
//
//bool bfs ()
//{
//    parante.clear();
//    parante.resize(total_nodes);
//    vizitat.clear();
//    vizitat.resize(total_nodes, 0);
//
//    // Vom porni intotdeauna de la sursa
//    vizitat[s] = 1;
//    // Coada in care vom retine nodurile
//    queue<int> q;
//    q.push(s);
//    // Cat timp mai avem noduri in coada pargurgem graful
//    while (!q.empty())
//    {
//        int nod = q.front();
//        q.pop();
//        // Parcurgem muchiile din lista de adiacenta, care sunt
//        // retinute sub forma de index catre muchia din vectorul de muchii
//        if (nod != d)
//            for (auto index_muchie: graph[nod])
//            {
//                // Deschidem muchia
//                Edge ed = edges[index_muchie];
//                // Daca nodul nu a fost vizitat si muchia are capacitatea mai mare decat 0
//                if (!vizitat[ed.to] && ed.capacity > 0)
//                {
//                    // Marchez nodul ca vizitat
//                    vizitat[ed.to] = 1;
//                    // Marchez parintele nodului
//                    parante[ed.to] = index_muchie;
//                    // Adaug nodul in coada
//                    q.push(ed.to);
//                    // Daca am ajuns la destinatie, atunci am gasit un drum
//                }
//            }
//    }
//    cout << vizitat[d] << ' ';
//    return vizitat[d];
//}
//
//// Functia care calculeaza fluxul maxim
//// Ford-Fulkerson
//int fordFulkerson ()
//{
//    // Flux maxim
//    int flux = 0;
//    // Cat timp mai exista un drum de la sursa la destinatie
//    while (bfs())
//    {
//        for (auto index_muchie: graph[d])
//        {
//            if (vizitat[edges[index_muchie].to] && edges[edges[index_muchie].pozitie].capacity > 0)
//            {
//                int capactiate = INT_MAX;
//                Edge ed = edges[index_muchie];
//                parante[d] = ed.pozitie;
//                int nod = d;
//                while (nod != s)
//                {
//                    capactiate = min(capactiate, edges[parante[nod]].capacity);
//                    nod = edges[parante[nod]].from;
//                }
//                nod = d;
//                // Actualizam fluxul, deci mai trebuie sa parcurgem drumul de la destinatie la sursa
//                while (nod != s)
//                {
//                    edges[edges[parante[nod]].pozitie].capacity += capactiate;
//                    edges[parante[nod]].capacity -= capactiate;
//                    nod = edges[parante[nod]].from;
//                }
//                flux += capactiate;
//            }
//        }
//    }
//    return flux;
//}
//
//int main ()
//{
//
//    ifstream cin("cuplaj.in");
//    ofstream cout("cuplaj.out");
//    cin >> n >> m >> e;
//    // Calculam numarul total de noduri
//    total_nodes = n + m + 2;
//    // Construim sursa si destinatia
//    // Stim ca nodurile incep de la 0 si sunt consecutive
//    s = 0;
//    d = total_nodes - 1;
//    // Construim graful
//    graph.resize(total_nodes);
//
//    // Citim muchiile
//    for (int i = 0; i < e; i++)
//    {
//        int x, y;
//        cin >> x >> y;
//        // Adaugam muchia in lista de adiacenta
//        addEdge(x, y + n);
//    }
//
//    // Adaugam muchiile de la sursa la nodurile din multimea A
//    for (int i = 1; i <= n; ++i)
//        addEdge(s, i);
//
//    // Adaugam muchiile de la nodurile din multimea B la destinatie
//    for (int i = 1; i <= m; ++i)
//        addEdge(i + n, d);
//
//    // Aplicam Ford-Fulkerson
//    cout << fordFulkerson() << endl;
//
//    for (Edge muchie: edges)
//    {
//        if (muchie.from < muchie.to && muchie.from != 0 && muchie.to != d && muchie.capacity == 0)
//            cout << muchie.from << " " << muchie.to - n << '\n';
//    }
//    return 0;
//}