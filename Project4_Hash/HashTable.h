#pragma once
#include "stdafx.h"
#include "Slot.h"
#include <fstream>
#define MAXHASH 1000 

template <class T> class HashTable
{
public:
	// Inserts new data into a Hash Table
	bool insert(int key, T value, int& collisions)
	{
		int h = hashFunction(key);
		return probe(value, h, collisions);
	}

	// Probes for empty or tombstone to place a value.
	bool probe(T value, int index, int& collisions)
	{
		int step = 0;
		while (step < MAXHASH)// MAXHASH)
		{
			if (array[index].isEmpty() == true || array[index].isTombstone() == true)
			{
				array[index] = Slot<T>(index, value);
				items++;
				return true;
			}
			else
			{
				step += 1;
				collisions += 1;
				index = index + step;
			}
		}
		return false;
	}
	// Removes data from the hash
	bool remove(int key)
	{
		int h = hashFunction(key);
		return removeProbe(h);
	}
	// Removes a value once found.
	bool removeProbe(int key)
	{
		int step = 0;
		while (step < MAXHASH)
		{
			if (array[key].isEmpty())
			{
				return false;
			}
			if (array[key].isTombstone())
			{
				return false;
			}
			if (array[key].isNormal())
			{
				array[key].kill();
				items--;
				return true;
			}
		}
	}
	// Searches has for value passed, if found returns true if not found returns false
	bool find(int key, T& value)
	{
		int step = 0;
		int collisions = 0;
		int h = hashFunction(key);
		while (step < MAXHASH)
		{
			if (array[h].isEmpty() == true || array[h].isTombstone() == true)
			{
				return false;
			}
			else
			{
				return probe(value, h, collisions);
			}
		}
		return false;
	}

	float alpha()
	{
		return items*1.0 / MAXHASH*1.0;
	}
	// Constructor
	HashTable()
	{
		items = 0;
		array = new Slot<T>[MAXHASH];
	}
	~HashTable()
	{
		delete[] array;
	}
private:
	int items;
	Slot<T>* array;
	int perm[MAXHASH];
	int hashFunction(int UID)
	{
		return UID % MAXHASH;
	}
};