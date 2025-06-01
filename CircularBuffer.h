#ifndef __QUEUE_CIRC_H
#define __QUEUE_CIRC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint16_t element_size;
#if (element_size == uint16_t)
#define _max 0xFFFF
#elif (element_size == uint16_t)
#define _max 0xFFFFFFFF
#endif


typedef struct queue
{
uint8_t			element_size;
element_size 	front_index;	//where data should read from queue.
element_size 	rear_index;	//where new data should write.
uint8_t*		array;
element_size 	element_capacity;	
}queue;

void CircularBufferFree(queue* q);
queue* createqueue(element_size size , uint8_t each_element_size);
element_size queueremain(queue* q);
element_size queuefreeremain(queue* q);
bool enqueue(queue* q,uint8_t* data);
bool dequeue(queue* q, uint8_t * data);
bool advance_enqueue_array(queue* q, uint8_t* importation, element_size num);
bool advance_dequeue_array(queue* q, uint8_t* deportation, element_size num);


#endif

