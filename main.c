#include <stdio.h>
#include <stdlib.h>

void cargar(int* ,int*, int* ,int*, int, int* ,int*, int* ,int*);
int menu();

int main() {
	int i = 0, p,gan=0,per=0,emp=0, difG=0, champion=0, winer=0, a[1],b[1],c[1],d[1];
	int rival[i+1], golesF[i+1],golesC[i+1],torneo[i+1];
	
	a[0]=0;
	b[0]=0;
	c[0]=0;
	d[0]=0;
	p=menu();
	while(p==1){
		cargar(rival, golesF, golesC, torneo, i, a, b ,c ,d);
		i++;
		p=menu();
		system("cls");
	}
		
	for(int x=0;x<i;x++){
		if(golesF[x]>golesC[x]){
			gan++;
		}else if(golesF[x]<golesC[x]){
			per++;
		}else {
			emp++;
		}
		difG+=(golesF[x]-golesC[x]);
		if(torneo[x]=='h'){
			champion++;
			if(golesF>golesC){
				winer=1;
			} else{
				winer=0;
			}
		}	
	}	
	if(p==2){
		printf("\nSe jugaro un total de %d partidos, se ganaron %d, se perdieron %d y se empataron %d\n",i,gan,per,emp);
		printf("Hubo una diferencia de %d goles\n",difG);
		
		if(a[0]>=b[0]&&a[0]>=c[0]&&a[0]>=d[0]){
			printf("El rival con el q mas se jugo es: a \n");
		}else if(b[0]>=a[0]&&b[0]>=c[0]&&b[0]>=d[0]){
			printf("El rival con el q mas se jugo es: b \n");
		}else if(c[0]>=a[0]&&c[0]>=b[0]&&c[0]>=d[0]){
			printf("El rival con el q mas se jugo es: c \n");
		}else{
			printf("El rival con el q mas se jugo es: d \n");
		}
		
		printf("Se jugaron %d partidos en la champion\n",champion);
		if(winer==1){
				printf("Tu equipo salio CAMPEON\n");
		}
		
	}
	return 0;
}

int menu(){
	int p;
	printf("Ingrese la opcion que desea:\n1_Cargar datos\n2_Mostrar estadisticas\n3_Salir\n");
	fflush(stdin);
	scanf("%d", &p);
	return p;
}
void cargar(int *rival, int *golesF, int *golesC, int *torneo, int i, int *a, int *b, int *c, int *d){
	int num;
	char ch;
	printf("Ingrese rival:\n");
	fflush(stdin);
	scanf("%c", &ch); 
	*(rival+i)=ch;
	switch(ch) {
		case 'a': *(a)+=1;
		break;
		case 'b': *(b)+=1;
		break;
		case 'c': *(c)+=1;
		break;
		case 'd': *(d)+=1;
		break;
		default: printf("\nEste equipo no esta en nuestra base de datos.\n");
	}
	printf("Ingrese goles a favor:\n");
	fflush(stdin);
	scanf("%d", &num);
	*(golesF+i)=num;
	printf("Ingrese goles en contra:\n");
	fflush(stdin);
	scanf("%d", &num);
	*(golesC+i)=num;
	printf("Ingrese torneo:\nc_copa\nl_liga\nh_champions\n");
	fflush(stdin);
	scanf("%c", &ch);
	*(torneo+i)=ch;
	return;
}



