#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Punto;

typedef struct {
	Punto vertice1;
	Punto vertice2;
} Rettangolo;

typedef struct {
	Punto centro;
	int raggio;
} Cerchio;

int area_rettangolo(Rettangolo r) {
	int l1 = r.vertice2.x-r.vertice1.x;
	int l2 = r.vertice2.y-r.vertice1.y;
	return l1*l2;
}

int perimetro_rettangolo(Rettangolo r) {
	int l1 = r.vertice2.x-r.vertice1.x;
	int l2 = r.vertice2.y-r.vertice1.y;
	return l1*2+l2*2;
}

float area_cerchio(Cerchio c) {
	return c.raggio*c.raggio*3.14;
}

float perimetro_cerchio(Cerchio c) {
	return 2*3.14*(float)c.raggio;
}

int main() {
	Rettangolo r;
	Cerchio c;
	
	printf("Vertice 1 (x, y): ");
	scanf("%d, %d",&r.vertice1.x, &r.vertice1.y);

	printf("Vertice 2 (x, y): ");
	scanf("%d, %d",&r.vertice2.x, &r.vertice2.y);
	
	printf("L'area del rettangolo è %dcm^2.\n", area_rettangolo(r));

	printf("Il perimetro del rettangolo è %dcm.\n", perimetro_rettangolo(r));
	
	printf("Definire il centro  e il raggio del cerchio (x, y, r): ");
	scanf("%d, %d, %d", &c.centro.x, &c.centro.y, &c.raggio);
	
	printf("L'area del cerchio è %fcm^2.\n", area_cerchio(c));
	
	printf("Il perimetro del cerchio è %fcm.\n", perimetro_cerchio(c));
}