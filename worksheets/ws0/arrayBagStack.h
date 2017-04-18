#ifndef ArrayBagStack
#define ArrayBagStack

#define TYPE int

struct arrayBagStack{
	TYPE data [100];
	int count;
};

void initArray(struct arrayBagStack * b);

/* Bag Interface Functions */
void addArray(struct arrayBagStack * b, TYPE v);
int containsArray(struct arrayBagStack * b, TYPE v);
void removeArray(struct arrayBagStack * b, TYPE v);
int sizeArray(struct arrayBagStack * b);

/* Stack Interface Functions */
void pushArray(struct arrayBagStack * b, TYPE v);
TYPE topArray(struct arrayBagStack * b);
void popArray(struct arrayBagStack * b);
int isEmptyArray(struct arrayBagStack * b);

#endif
