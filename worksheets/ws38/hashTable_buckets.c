#include <stdlib.h>
#include <assert.h>

struct hlink
{
	TYPE value;
	struct hlink *next;
};

struct hashTable
{
	struct hlink **table;
	int tablesize;
	int count;
};

void initHashTable(struct hashTable *ht, int size)
{
	int i;

	if(ht == NULL)
	{

		return;

	}
	
	ht->table = (hlink **)malloc(size * sizeof(struct hlink *));
	ht->tablesize = size;
	ht->count = 0;
		assert(ht->table != 0);
	
	for(i = 0; i < size ; i++)
	{
		ht->table[i] = 0;
	}

}

int hashTableSize(struct hashTable *ht)
{

	return ht->count;

}

void hashTableAdd(struct hashTable *ht, TYPE newValue)
{
	//compute hash value to find the correct bucket
	
	int hashIndex = HASH(newValue) % ht->tablesize;

	if(hashIndex < 0)
	{
		hashIndex += ht->tablesize;
	}

	struct link *newLink = (struct hlink *)malloc(sizeof(struct hlink));
	assert(newLink != 0);
	newLink->value = newValue;
	newLink->next = ht->table[hashIndex];
	ht->table[hashIndex] = newLink; //add to bucket
	ht->count++;

	if((ht->count / (double)ht->tablesize) > 8.0)
	{
		_resizeHashTable(ht);
	}

}

int hashTableContains(struct hashTable *ht, TYPE testElement)
{
	int hashIndex = HASH(testElement) % ht->tablesize;
	hlink *cur = ht->table[hashIndex];

	while(cur != 0)
	{

		if(cur->value == testElement)
		{

			return 1; //found it

		}

		cur = cur->next;

	

	return 0;

}

void hashTableRemove(struct hashTable *ht, TYPE testElement)
{
	int hashIndex = HASH(testElement) % ht->tablesize;
	hlink *cur, *last;

	assert(ht->size != 0);

	if(hashTableContains(ht, testElement))
	{
		//head of list
		cur = ht->table[hashIndex];
		last = ht->table[hashIndex];

		while(cur != 0)
		{

			if(cur->value == testElement) //found it
			{
				
				if(cur == ht->table[hashIndex]) // special case 1st
				{
					//"remove" value by skipping over it
					ht->table[hashIndex] = cur->next; 
				}
				else
				{
					last->next = cur->next;
				}

				free(cur);
				cur = 0; //jump out of loop
			}
			else
			{
				last = cur;
				cur = cur->next;
			}

		}

	}

}
				




}

void _resizeHashTable(struct hashTable *ht)
{

	int i, oldts = ht->tablesize;
	hlink *cur, *last;

	initHashTable(ht, 2 * oldts);
	
	for(i = 0; i < oldts; i++)
	{
		/* assuming you have a list iterator */
		cur = ht->table[i];

		while(cur != 0)
		{
			addHashTable(ht, cur->value);
			last = cur;
			cur = cur->next;
			free(last);
		}

	}

	//free old table?
	free(oldTable);
}



