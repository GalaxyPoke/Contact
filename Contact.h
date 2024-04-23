#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 12
#define ADDR_MAX 100
#define INIT_CAPACITY 4

typedef struct PersonInfo {
    char name[NAME_MAX];
    char gender[SEX_MAX];
    int age;
    char telephone[TEL_MAX];
    char address[ADDR_MAX];
} PerInfo;

typedef struct Contact {
    PerInfo* arr;
    int size;
    int capacity;
} Con;

// Function declarations
void ConInit(Con* ps);
void ConCheckcapacity(Con* ps);
void ConDestory(Con* ps);
void ConPushFront(Con* ps, PerInfo newContact);
void ConPushBack(Con* ps, PerInfo newContact);
void ConPopFront(Con* ps);
void ConPopBack(Con* ps);
void ConModify(Con* ps, int index, PerInfo updatedContact);
void ConSearch(Con* ps, const char* targetName);
void ConDisplayAll(Con* ps);
void ConSave(Con* ps, const char* filename);
void ConLoad(Con* ps, const char* filename);
