#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SUCCESS (00)

struct Ponto 
{
    float x;
    float y;

    float distancia(Ponto& p);
    void atribuir(float a, float b);
};

float Ponto::distancia(Ponto& p) 
{
    float dx = x - p.x;
    float dy = y - p.y;

    return sqrt(dx*dx + dy*dy);
}
void Ponto::atribuir(float a, float b) 
{
    x = a;
    y = b;
}

struct Triangulo
{
    Ponto A;
    Ponto B;
    Ponto C;

    float perimetro();
    float area();
    bool equilatero();
    bool semelhante(Triangulo& t);
};

float Triangulo::perimetro()
{
    float AB = A.distancia(B);
    float AC = A.distancia(C);
    float BC = B.distancia(C);

    return AB + AC + BC;
}
float Triangulo::area()
{
    float base = A.distancia(B);
    float altura = sqrt(pow(C.distancia(B),2) - pow((base/2),2));

    return base * altura;
}
bool Triangulo::equilatero()
{
    float AB = A.distancia(B);
    float AC = A.distancia(C);
    float BC = B.distancia(C);

    return AB == AC == BC;
}
bool Triangulo::semelhante(Triangulo& t)
{
    float AB = A.distancia(B);
    float AC = A.distancia(C);
    float BC = B.distancia(C);

    float tAB = t.A.distancia(t.B);
    float tAC = t.A.distancia(t.C);
    float tBC = t.B.distancia(t.C);

    return AB/tAB == AC/tAC == BC/tBC;
}

struct Retangulo
{
    Ponto A;
    Ponto B;
    Ponto C;
    Ponto D;

    float perimetro();
    float area();
    bool quadrado();
};

float Retangulo::perimetro()
{
    float AB = A.distancia(B);
    float AC = A.distancia(C);

    return (AB + AC) * 2;
}
float Retangulo::area()
{
    float AB = A.distancia(B);
    float AC = A.distancia(C);

    return AB * AC;
}
bool Retangulo::quadrado()
{
    float AB = A.distancia(B);
    float AC = A.distancia(C);

    return AB == AC;
}

struct Circunferencia
{
    Ponto origem;
    float raio;

    float perimetro();
    float area();
    bool contem(Ponto& p);
    bool contem(Triangulo& t);
    bool contem(Retangulo& r);
    bool pertence(Ponto& p);
    bool circunscrita(Triangulo& t);
    bool circunscrita(Retangulo& r);
};

float Circunferencia::perimetro()
{
    return 2 * M_PI * raio;
}
float Circunferencia::area()
{
    return M_PI * pow(raio, 2);
}
bool Circunferencia::contem(Ponto& p)
{
    return origem.distancia(p) <= raio;
}
bool Circunferencia::contem(Triangulo& t)
{
    return origem.distancia(t.A) <= raio &&
           origem.distancia(t.B) <= raio &&
           origem.distancia(t.C) <= raio;
}
bool Circunferencia::contem(Retangulo& t)
{
    return origem.distancia(t.A) <= raio &&
           origem.distancia(t.B) <= raio &&
           origem.distancia(t.C) <= raio &&
           origem.distancia(t.D) <= raio;
}
bool Circunferencia::pertence(Ponto& p)
{
    return origem.distancia(p) == raio;
}
bool Circunferencia::circunscrita(Triangulo& t)
{
    return origem.distancia(t.A) == raio &&
           origem.distancia(t.B) == raio &&
           origem.distancia(t.C) == raio;
}
bool Circunferencia::circunscrita(Retangulo& r)
{
    return origem.distancia(r.A) == raio &&
           origem.distancia(r.B) == raio &&
           origem.distancia(r.C) == raio &&
           origem.distancia(r.D) == raio;
}


int main(int argc, char const *argv[])
{
    float x, y, raio;
    Ponto p1, p2, p3, p4;
    Triangulo t1, t2;
    Retangulo r1, r2;
    Circunferencia c1, c2;

    printf("Lista de exercicios 9 - Estruturas\n\n");

    printf("01 - PONTOS:\n");
    printf("Distancias:\n");
    printf("Coordenadas do ponto 1: ");
    scanf("%f %f", &x, &y);
    p1.atribuir(x, y);
    printf("Coordenadas do ponto 2: ");
    scanf("%f %f", &x, &y);
    p2.atribuir(x, y);
    printf("A distancia entre os pontos eh: %.2f\n\n", p1.distancia(p2));

    printf("02 - TRIANGULOS:\n");
    printf("Perimetro:\n");
    printf("Coordenadas do ponto A: ");
    scanf("%f %f", &x, &y);
    t1.A.atribuir(x, y);
    printf("Coordenadas do ponto B: ");
    scanf("%f %f", &x, &y);
    t1.B.atribuir(x, y);
    printf("Coordenadas do ponto C: ");
    scanf("%f %f", &x, &y);
    t1.C.atribuir(x, y);
    printf("O perimetro do triangulo eh: %.2f\n", t1.perimetro());
    
    printf("Area:\n");
    printf("O area do triangulo eh: %.2f\n", t1.area());
    
    printf("Equilatero:\n");
    printf("O triangulo eh equilatero? %s\n", t1.equilatero() ? "SIM" : "NAO");
    
    printf("Semelhante:\n");
    printf("Coordenadas do ponto A: ");
    scanf("%f %f", &x, &y);
    t2.A.atribuir(x, y);
    printf("Coordenadas do ponto B: ");
    scanf("%f %f", &x, &y);
    t2.B.atribuir(x, y);
    printf("Coordenadas do ponto C: ");
    scanf("%f %f", &x, &y);
    t2.C.atribuir(x, y);
    printf("Os triangulos sao semelhantes? %s\n\n", t1.semelhante(t2) ? "SIM" : "NAO");

    printf("03 - RETANGULOS:\n");
    printf("Perimetro:\n");
    printf("Coordenadas do ponto A: ");
    scanf("%f %f", &x, &y);
    r1.A.atribuir(x, y);
    printf("Coordenadas do ponto B: ");
    scanf("%f %f", &x, &y);
    r1.B.atribuir(x, y);
    printf("Coordenadas do ponto C: ");
    scanf("%f %f", &x, &y);
    r1.C.atribuir(x, y);
    printf("Coordenadas do ponto D: ");
    scanf("%f %f", &x, &y);
    r1.D.atribuir(x, y);
    printf("O perimetro do retangulo eh: %.2f\n", r1.perimetro());

    printf("Area:\n");
    printf("O area do retangulo eh: %.2f\n", r1.area());

    printf("Quadrado:\n");
    printf("O retangulo eh quadrado? %s\n", r1.quadrado() ? "SIM" : "NAO");

    printf("04 - CIRCUNFERENCIAS:\n");
    printf("Perimetro:\n");
    printf("Coordenadas do ponto de origem: ");
    scanf("%f %f", &x, &y);
    c1.origem.atribuir(x, y);
    printf("Raio: ");
    scanf("%f", &raio);
    c1.raio = raio;
    printf("O perimetro da circunferencia eh: %.2f\n", c1.perimetro());

    printf("Area:\n");
    printf("O area da circunferencia eh: %.2f\n", c1.area());
    
    printf("Contem:\n");
    printf("O ponto 1 esta contido no circulo? %s\n", c1.contem(p1) ? "SIM" : "NAO");

    printf("Circunscrito:\n");
    printf("O triangulo 1 circunscreve o circulo? %s\n", c1.circunscrita(t1) ? "SIM" : "NAO");

    
    return SUCCESS;
}