#include <stdio.h>
#include <stdlib.h>
#define N 7
typedef struct AdjVertex {
    struct AdjVertex* next;
    char aName;
    struct Edge* e;
}AdjVertex;

typedef struct Vertex {
    struct Vertex* next;
    char vName;
    int visited;
    struct AdjVertex* aHead;
}Vertex;

typedef struct Edge {
    struct Edge* next;
    char u, v;
    int weight;
}Edge;

typedef struct {
    int vCnt, eCnt;
    struct Edge* eHead;
    struct Vertex* vHead;
}GraphType;

void init(GraphType* G) {
    G->eCnt = G->vCnt = 0;
    G->eHead = NULL;
    G->vHead = NULL;
}
void makeVertex(GraphType* G, char vName) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->aHead = NULL;
    v->next = NULL;
    v->vName = vName;
    v->visited = 0;
    G->vCnt++;
    Vertex* p = G->vHead;
    if (p == NULL)
        G->vHead = v;
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = v;
    }
}

Vertex* findVertex(GraphType* G, char vName) {
    Vertex* p = G->vHead;
    while (p->vName != vName)
        p = p->next;
    return p;
}

void makeAdj(Vertex* v, char aName, Edge* e) {
    AdjVertex* a = (AdjVertex*)malloc(sizeof(AdjVertex));
    a->aName = aName;
    a->e = e;
    a->next = NULL;
    AdjVertex* p = v->aHead;
    if (p == NULL)
        v->aHead = a;
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = a;
    }
}

void insertEdge(GraphType* G, char v1, char v2, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->next = NULL;
    e->u = v1;
    e->v = v2;
    e->weight = weight;
    G->eCnt++;
    Vertex* v = findVertex(G,v1);
    makeAdj(v,v2,e);
    v = findVertex(G, v2);
    makeAdj(v,v1,e);
}

void Sollin(GraphType* G) {
    int eCnt = 0;
    while (eCnt<N) {
        for (Vertex* v = G->vHead;v!=NULL;v=v->next) {
            if (v->visited == 0) {
                v->visited = 1;
                int min = 1000;
                AdjVertex* ma = NULL;
                for (AdjVertex* a = v->aHead;a!=NULL;a=a->next) {
                    Vertex* u = findVertex(G, a->aName);
                    if (a->e->weight < min) {
                        min = a->e->weight;
                        ma = a;
                    }
                }
                if (ma) {
                    Vertex* u = findVertex(G, ma->aName);
                    u->visited = 1;
                    printf("[%c %d] ", u->vName, ma->e->weight);
                    eCnt++;
                }
            }
        }
    }
}


int main() {
    GraphType G;
    init(&G);

    makeVertex(&G,'A'); makeVertex(&G,'B');
    makeVertex(&G,'C'); makeVertex(&G,'D');
    makeVertex(&G,'E'); makeVertex(&G,'F');
    makeVertex(&G,'G');

    insertEdge(&G,'A','B',25); insertEdge(&G,'A','D',12);
    insertEdge(&G,'B','C',10); insertEdge(&G,'B','E',15);
    insertEdge(&G,'C','G',16); insertEdge(&G,'D','F',37);
    insertEdge(&G,'D','E',17); insertEdge(&G,'F','G',42);
    insertEdge(&G,'E','G',14); insertEdge(&G,'E','F',19); 

    Sollin(&G);
}