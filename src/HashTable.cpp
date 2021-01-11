#include<iostream>
#include<string.h>


using namespace std;
const int TABLE_SIZE = 128;
const int DATA_SIZE  = 128;

class HashEntry
{
 public:
	int key;
	char value[DATA_SIZE];
	HashEntry(int key, char *value)
	{
		this->key = key;
		strcpy(this->value, value);
		cout << "key" << this->key << "value" << this->value << endl;
	};
};

class HashMap
{
 private:
	HashEntry **table;
	
 public:
	HashMap()
	{
		table = new HashEntry *[TABLE_SIZE];
		for (int i = 0 ; i < TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	};

	~HashMap()
	{
		for (int i = 0 ; i < TABLE_SIZE; i++)
		{
			if (table[i] != NULL)
			{
				delete table[i];
			}
		}
		delete[] table;		
	};
	
	int insert(int key, char *value)
	{
		int hashKey = key;
		
		if (table[hashKey] != NULL)
		{
			delete table[hashKey];
		}
		table[hashKey] = new HashEntry(key, value);
	};
	
	int remove(int key)
	{
		int hashKey = key;
		if (table[hashKey] == NULL)
		{
			cout << "no Element found at key" << endl;
			return -1;
		}
		else if (table[hashKey] != NULL && table[hashKey]->key == key)
		{
			table[hashKey]->key = -1;
			cout << "Element deleted" << endl;
		}
		
	};
	
	char* search(int key)
	{
		int hashKey = key;
		if (table[hashKey] == NULL)
		{
			cout << "Element NULL" << endl;
			return NULL;
		}
		else if(table[hashKey] != NULL && table[hashKey]->key != key)
		{
			cout << "Deleted Element" << endl;
			return NULL;
		}
		
		return table[hashKey]->value;
	};
};

int main ()
{
	HashMap hash;
	hash.insert(1, "100");
	hash.insert(2, "200");
	hash.insert(3, "300");
	hash.insert(4, "400");
	
	cout << "test: " << hash.search(3) << endl;
	
	hash.remove(3);
	cout << "test: " << hash.search(3) << endl;
	
	return 0;
}