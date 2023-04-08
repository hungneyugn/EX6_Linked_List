/*
*File: linkedlist.h
*Author: Nguyen Phi Hung
*Date: 08/04/2023
*Description:  
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

/*
*Function: linkedList_Init
*Description: generate new linked list
*Input:
    ls: Pointer to a linked list
*Output: None
*/
void linkedList_Init(linkedList *ls)
{
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
}

/*
*Function: new_Node
*Description: generate new node
*Input:
    data: data of node which is need to be generate
*Output:
    a new Node
*/
node* new_Node(uint8_t data)
{
    node *newNode = (node*)malloc(sizeof(node));  
    newNode->data = data;                      
    newNode->next = NULL;
    return newNode; 
}                           

/*
*Function: isEmpty
*Description: check if linked list is empty
*Input:
    ls: Pointer to a linked list
*Output:
    1: if linked list is empty
    0: if linked list isn't empty
*/   
bool isEmpty(linkedList *ls)
{
    return ls->size == 0;
}

/*
*Function: pushBack
*Description: Add new node to last linked list
*Input:
    ls: Pointer to a linked list
    data: data of node which is need to be add
*Output: None
*/  
void pushBack(linkedList *ls,uint8_t data)
{ 
    node* newNode = new_Node(data);
    if(isEmpty(ls)) ls->head = newNode;
    else ls->tail->next = newNode;
    ls->tail = newNode;
    ls->size ++;
}

/*
*Function: assign
*Description: Add new node to any position in linked list
*Input:
    ls: Pointer to a linked list
    data: data of node which is need to be add
    position: position where we add new node to 
*Output: None
*/  
void assign(linkedList *ls,uint8_t data,uint8_t position)
{
    node* newNode = new_Node(data);
    node* p = ls->head;
    int i = 1;
    while(i < position -1)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
    ls->size ++;
}

/*
*Function: pop_back
*Description: remove last node
*Input:
    ls: Pointer to a linked list 
*Output: None
*/  
void pop_back(linkedList *ls)
{
    int i =1;
    node *p = ls->head;
    while(i < ls->size -1)
    {
        p = p->next;
        i++;
    }
    ls->tail = p;
    ls->tail->next = NULL;
    ls->size --;
    free(p->next);
}

/*
*Function: erase
*Description: Remove any node in linked list
*Input:
    ls: Pointer to a linked list 
    position: position where we remove node 
*Output: None
*/ 
void erase(linkedList *ls,uint8_t position)
{
    int i = 1;
    node *p = ls->head;
    node *temp;
    while(i < position-1)
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = p->next->next;
    ls->size--;
    free(temp);
}

/*
*Function: clear
*Description: Clear linked list
*Input:
    ls: Pointer to a linked list 
*Output: None
*/ 
void clear(linkedList *ls)
{
    int i = 1;
    node *p = ls->head;
    while(i <= ls->size)
    {
        p = p->next;
        free(ls->head);
        ls->head = p;
        i++;
    }
    free(ls->head);
    ls->size = 0;
}

/*
*Function: getData
*Description: Get data of a node in linked list
*Input:
    ls: Pointer to a linked list 
    position: position where we want to get data
*Output: data of a node
*/ 
void getData(linkedList *ls,uint8_t position)
{
    int i = 1;
    node *p = ls->head;
    while(i <= position - 1)
    {
        p = p->next;
        i++;
    }
    printf("Gia tri tai vi tri %d la: %d\n",position,p->data);
}

/*
*Function: display
*Description: Display linked list
*Input:
    ls: Pointer to a linked list 
*Output: Linked list
*/
void display(linkedList *ls)
{
    if(ls->size == 0) printf("Linked list trong");
    else
    {
        node* p = ls->head;
        while( p != NULL)
        {
            printf("%d-->",p->data);
            p = p->next;
        }
        printf("\n");
    }
}
#endif