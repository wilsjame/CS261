#include <stdlib.h>
#include <assert.h>
#ifndef TYPE
#define TYPE int
#endif

int main(){
	return 0;
}

struct openHashTable
{
	//table contains pointers (pointer to a pointer)
	TYPE ** table;
	int tablesize;
	int count;
};

void initOpenHastTable(struct openHashTable *ht, int size)
{
	int i;
	assert(size > 0);
	ht->table = (TYPE **)malloc(size * sizeof(TYPE *));
	assert(ht->table != 0);

	for(i = 0; i < size; i++)
	{
		ht->table[i] = 0; //initialize empty
		ht->tablesize = size;
		ht->count = 0;
	}

}

int openHashTableSize(struct openHashTable *ht)
{
	return ht->count;
}

void openHashTableAdd(struct openHashTable *ht, TYPE *newValue)
{
	int idx;

	//make sure we have space and under load factor
	if((ht->count / (double) ht->tablesize) > 0.75)
	{
		_resizeOpenHashTable(ht);
	}

	ht->count++;
	idx = HASH(newValue) % ht->tableSize;

	/* To be safe, use only positive arithmetic. % may behave differently on 
	 * diff implementations of diff languages. However, you can do the following
	 * to deal with a negative result for HASH */
	if(idx < 0)
	{
		idx += ht->tablesize;
	}

	while(1)
	{
		
		if(ht->table[idx] == 0)
		{
			ht->table[idx] = newValue;

			return;

		}
		else
		{
			idx++;

			if(idx == ht->tablesize)
			{
				idx = 0
			}

		}

	}

}

/* return 1 if contains and 0 otherwise */
int openHashTableBagContains(struct openHashTable *ht, TYPE newValue)
{
	int idx;
	bool found;

	idx = HASH(newValue) % ht->tablesize;

	if(idx < 0)
	{
		idx += ht->tablesize;
	}

	while(1)
	{
		
		if(ht->table[idx] == newValue)
		{

			return 1; //found it

		}
		else if(ht->table[idx] == 0)
		{

			return 0;

		}
		else
		{
			idx++;

			if(idx == ht->tablesize)
			{
				idx = 0
			}

		}

	}

}

void _resizeOpenHashTable(struct openHashTable *ht)
{
	int i;
	int oldSize = ht->tablesize;
	int newSize = 2 * oldSize;
	TYPE ** temp = ht->table;
	initOpenHashable(ht, newSize);

	for(i = 0; i < oldSize; i++)
	{

		if(temp[i] != 0)
		{
			openHashTableAdd(ht, temp[i]);
		}

	}

	free(temp);

}




