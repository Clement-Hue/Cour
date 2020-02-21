#include <stdlib.h>
#include <stdio.h>
#include "Liste.h"

void PrintList(SList *list);

struct SCell {
	Data valeur;
	SCell* suivant;
	SCell* precedent;
};

struct SList {
	SCell* Head;	
	SCell* Queue;
};

int main()
{
	SList *list;
	SCell *cell;

	list=CreateList();

	printf("Add 5, 3, 1\n");
	AddElementBegin(list,5);
	cell=AddElementBegin(list,3);
	AddElementBegin(list,1);
	PrintList(list);
	printf("\n");

	printf("Add 6, 7\n");
	AddElementEnd(list,6);
	AddElementEnd(list,7);
	PrintList(list);
	printf("\n");

	printf("Add 4\n");
	AddElementAfter(list,cell,4);
	PrintList(list);
	printf("\n");

	printf("Add 2\n");
	AddElementAfter(list,GetFirstElement(list),2);
	PrintList(list);
	printf("\n");

	printf("Delete 3\n");
	DeleteCell(list,cell);
	PrintList(list);
	printf("\n");

	DeleteList(list);

	return 0;
}


void PrintList(SList *list)
{
	if (list)
	{
		SCell *cell=GetFirstElement(list);
		while (cell!=NULL)
		{
			printf("[%d] -> ",GetData(cell));
			cell=GetNextElement(cell);
		}
		printf("NULL\n");
	}
}


SList* CreateList(){
	SList* liste;
	liste = (SList*) malloc(sizeof(SList));
	return liste;
}

void DeleteList(SList* liste) {
	SCell *pt_cell = liste->Head;
	SCell *tmp = NULL;
	while (pt_cell != NULL){
		tmp = pt_cell;
		pt_cell = pt_cell->suivant;
		free(tmp);
	}
	free(liste);
}

SCell* AddElementEnd(SList *liste,Data elem){
	SCell *cellule = (SCell*) malloc(sizeof(SCell));
	cellule->valeur = elem;
	cellule->suivant = NULL;
	cellule->precedent = liste->Queue;
	if (liste->Queue != NULL)
		liste->Queue->suivant = cellule;
	liste->Queue = cellule;
	return cellule;
}

SCell* AddElementBegin(SList *liste,Data elem){
	SCell *cellule = (SCell*) malloc(sizeof(SCell));
	cellule->valeur = elem;
	cellule->precedent = NULL;
	cellule->suivant = liste->Head;
	if (liste->Head != NULL)
		liste->Head->precedent = cellule;
	liste->Head = cellule;
	return cellule;
}

SCell* AddElementAfter(SList *liste,SCell *cell,Data elem){
	SCell *new_cellule = (SCell*) malloc(sizeof(SCell));
	new_cellule->valeur = elem;
	new_cellule->precedent = cell;
	new_cellule->suivant = cell->suivant;
	cell->suivant = new_cellule;
	return new_cellule;
}

void DeleteCell(SList *liste,SCell *cell){
	if (liste->Head == cell)
		liste->Head = cell->suivant;
	else if (liste->Queue == cell)
		liste->Queue = cell->precedent;
	else
		cell->precedent->suivant = cell->suivant;
	free(cell);
}

SCell* GetFirstElement(SList *liste){
	return liste->Head;
}

SCell* GetLastElement(SList *liste){
	return liste->Queue;
}

SCell* GetPrevElement(SCell *cell){
	return cell->precedent;
}

SCell* GetNextElement(SCell *cell){
	return cell->suivant;
}

Data GetData(SCell *cell){
	return cell->valeur;
}

