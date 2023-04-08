/*
*File: linkedlist.h
*Author: Nguyen Phi Hung
*Date: 08/04/2023
*Description: File header for acting with linked list
*/
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

/*struct save data of node in linked list*/
typedef struct node{
    uint8_t data;
    struct node *next;
}node;

/*struct save data of a linked List*/
typedef struct{
    node *head;
    node *tail;
    int size;
}linkedList;

/*declaration Functions*/

/*generate new linked list*/
void linkedList_Init(linkedList *ls);

/*generate new node*/
node* new_Node(uint8_t data);

/*check if linked list is empty*/
bool isEmpty(linkedList *ls);

/*Add new node to last linked list*/
void pushBack(linkedList *ls,uint8_t data);

/*Add new node to any position in linked list*/
void assign(linkedList *ls,uint8_t data,uint8_t position);

/*remove last node*/
void pop_back(linkedList *ls);

/*Remove any node in linked list*/
void erase(linkedList *ls,uint8_t position);

/*Clear linked list*/
void clear(linkedList *ls);

/*Get data of a node in linked list*/
void getData(linkedList *ls,uint8_t position);

/*Display linked list*/
void display(linkedList *ls);

#endif