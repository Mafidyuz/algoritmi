#include <stdio.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} Punto;

typedef struct {
	Punto vertice1;
	Punto vertice2;
} Rettangolo;

int area_rettangolo(Rettangolo *r) {
	int l1 = r -> vertice2.x- r -> vertice1.x;
	int l2 = r -> vertice2.y - r -> vertice1.y;
	return l1*l2;
}

int perimetro_rettangolo(Rettangolo *r) {
	int l1 = r -> vertice2.x-r -> vertice1.x;
	int l2 = r -> vertice2.y-r -> vertice1.y;
	return l1*2+l2*2;
}

int base_rettangolo(Rettangolo *r){
	return r -> vertice2.x - r -> vertice1.x;
}

int altezza_rettangolo(Rettangolo *r){
	return r -> vertice2.y - r -> vertice1.y;
}

Punto centro_rettangolo(Rettangolo *r) {
	float base = base_rettangolo(r);
	float altezza = altezza_rettangolo(r);
	Punto p;
	p.x = r -> vertice1.x + (float)base/2;
	p.y = r -> vertice1.y + (float)altezza/2;
	return p;
}

int main() {
	Rettangolo r;

	printf("Vertice 1 (x, y): ");
	scanf("%f, %f",&r.vertice1.x, &r.vertice1.y);

	printf("Vertice 2 (x, y): ");
	scanf("%f, %f",&r.vertice2.x, &r.vertice2.y);

	printf("L'area del rettangolo è %dcm^2.\n", area_rettangolo(&r));

	printf("Il perimetro del rettangolo è %dcm.\n", perimetro_rettangolo(&r));

	printf("Base: %dcm, Altezza: %dcm.\n", base_rettangolo(&r),altezza_rettangolo(&r));

	printf("Il centro del rettangolo è nel punto (%.1f, %.1f)\n",centro_rettangolo(&r).x,centro_rettangolo(&r).y);

	printf("Inserire di quanto traslare (x, y): ");
	int x,y;
	scanf("%d, %d",&x,&y);

}
