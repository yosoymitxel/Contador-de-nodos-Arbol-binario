#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	struct treeNode{
		int dato;
		treeNode *rightPtr;
		treeNode *leftPtr;
	};
	
	//typedef struct treeNode TREENODE;
	typedef treeNode * TREE;
	
	void insertar (TREE *, int );
	void enOrden (TREE);
	//void preOrden (TREE);
	void postOrden (TREE);
	void contar (TREE, int*);
	void altura (TREE, int, int *);
	void contador (TREE, int *);
	
	
int main(int argc, char** argv) {
	int x=0, item, n=0, hmax=0, ban=0, him = 999;
	int CONTADORGLOBAL = 0;
	TREE rootPtr=NULL;
	cout<<"Ingresar un numero, -1: ";
	cin>>item;
	
	while(item!=-1){
		insertar(&rootPtr,item);
		cout<<"Ingresar un numero, -1: ";
		cin>>item;
	}
	contador(rootPtr, &CONTADORGLOBAL); 
	/*cout<<endl;
	enOrden(rootPtr);
	cout<<endl;
	postOrden(rootPtr);
	cout<<endl;*/
	cout<<"Resultado: "<<CONTADORGLOBAL<<endl;
	system ("pause");
	return 1;
	
}
void insertar (TREE *treePtr, int valor){
	if  (*treePtr == NULL){
		*treePtr = new (treeNode);
		if (*treePtr !=NULL){
			(*treePtr)->dato =valor;
			(*treePtr)->leftPtr =NULL;
			(*treePtr)->rightPtr=NULL;
		}else
			cout<<"No hay memoria"<<endl;
		}
		else
		if (valor < (*treePtr)->dato){
			insertar (&((*treePtr)->leftPtr), valor);
		}else 
		if (valor > (*treePtr)->dato){
			insertar (&((*treePtr)->rightPtr), valor);
		}else 
			cout<<"DUPLICADO"<<endl;
	
}

void contador(TREE treePtr, int *CONTADORGLOBAL)
{
	if (treePtr != NULL)
	{		
		(*CONTADORGLOBAL)++;
		//cout<<"fun Resultado: "<<*CONTADORGLOBAL<<endl;
		contador(treePtr->leftPtr, CONTADORGLOBAL);
		contador(treePtr->rightPtr, CONTADORGLOBAL);
		
	}
}
/*void enOrden(TREE treePtr)
{
	if (treePtr != NULL)
	{
		
		preOrden(treePtr->leftPtr);
		cout<<treePtr->dato<<"->";
		preOrden(treePtr->rightPtr);
	}
}
void postOrden(TREE treePtr)
{
	if (treePtr != NULL)
	{
		
		preOrden(treePtr->leftPtr);
		preOrden(treePtr->rightPtr);
		cout<<treePtr->dato<<"->";
	}
}

*/
