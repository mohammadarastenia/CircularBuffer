#include "CircularBuffer.h"


queue* createqueue(element_size size , uint8_t each_element_size)
{
	if (size >= _max)return NULL;
	queue* q=(queue*)malloc(sizeof(queue));
	q->element_size = each_element_size;
	q->front_index=q->rear_index=_max;
	q->element_capacity=size;
	q->array=(uint8_t*)malloc((q->element_size)*q->element_capacity);
	if (q->array == NULL) return NULL;
    memset(q->array, 0, size * (q->element_size));
	return q;
}
	 
element_size queueremain(queue* q)//number of remain element in queue
{
	if (q->front_index == _max)return 0;
	else if(q->rear_index >= q->front_index)return (q->rear_index - q->front_index + 1);
	else return (q->element_capacity - (q->front_index - q->rear_index-1));
}

element_size queuefreeremain(queue* q)//number of free space remain in queue => q->capacity - queueremain(...)
{
	if (q->front_index == _max)return q->element_capacity;//noting in queue
	else if (q->rear_index >= q->front_index)return (q->element_capacity - (q->rear_index - q->front_index + 1));
	else return (q->front_index - q->rear_index - 1);
}

void CircularBufferFree(queue* q)
{
   free(q->array);
   free(q);
}

bool enqueue(queue* q,uint8_t* data)
{
  if (queueremain(q) == q->element_capacity)return false; //queue is full and no way to insert any more
	if(q->front_index==_max)//insert first element in queue
	{
		q->front_index=0;
		q->rear_index=0;
	} 
	else
	{
		q->rear_index=((q->rear_index+1)%q->element_capacity);	 	
	}
    memcpy_s((q->array + (q->rear_index)*(q->element_size)),(q->element_size)*q->element_capacity, data, q->element_size);
	return true;
}


bool dequeue(queue* q, uint8_t * data)
{
	if(q->front_index==_max)return false;
    memcpy_s(data,(q->element_size)*q->element_capacity,(q->array + (q->front_index)*(q->element_size)), q->element_size);
	if(q->front_index==q->rear_index)q->front_index=q->rear_index=_max;
	else q->front_index=((q->front_index+1)%q->element_capacity);
	return true;
}


bool advance_enqueue_array(queue* q, uint8_t* importation, element_size num)
{
	if (queuefreeremain(q) < num)return 0;
	if(num == 0)return 1;
	if (q->front_index == _max)//insert first element in queue
	{
		q->front_index = 0;
		q->rear_index = 0;
	}

	if (q->rear_index >= q->front_index)//normal queue     ---FxxxxxxxxxxxxxR------
	{
		if (q->rear_index == (q->element_capacity - 1))//    ---------FxxxxxxxxxxxxxR
		{
            memcpy_s((uint8_t*)(q->array),(q->element_size)*q->element_capacity, (uint8_t*)importation, num * (q->element_size));
			q->rear_index = num - 1;
		}
		else if (num <= (q->element_capacity - q->rear_index))//not need to return at begin of queue
		{
			if (q->rear_index > 0)
			{
                memcpy_s((uint8_t*)(q->array + ((q->rear_index + 1)*(q->element_size))),(q->element_size)*q->element_capacity, (uint8_t*)importation, (q->element_size)*num);
				q->rear_index += num;
			}
			else
			{
                memcpy_s((uint8_t*)(q->array + ((q->rear_index)*(q->element_size))),(q->element_size)*q->element_capacity, (uint8_t*)importation, (q->element_size)*num);
				q->rear_index = num - 1;
			}
		}
		else//some of element enqueue to last of queue and other enqueue to begin of queue
		{
            memcpy_s((uint8_t*)q->array + ((q->rear_index + 1)*(q->element_size)),(q->element_size)*q->element_capacity, (uint8_t*)importation, (q->element_size)* ((q->element_capacity - 1) - q->rear_index));
            memcpy_s((uint8_t*)q->array ,(q->element_size)*q->element_capacity, (uint8_t*)(importation + (((q->element_capacity - 1) - q->rear_index) * (q->element_size))), (q->element_size)*(num - ((q->element_capacity - 1) - q->rear_index)));
			q->rear_index = num - ((q->element_capacity - 1) - q->rear_index) - 1;
		}
	}
	else//queue retutned       xxxxxxR------------Fxxxxxxx
	{
        memcpy_s((uint8_t*)(q->array + ((q->rear_index + 1)*(q->element_size))),(q->element_size)*q->element_capacity, (uint8_t*)importation, num * (q->element_size));
		q->rear_index += num;
	}
	return 1;
}


bool advance_dequeue_array(queue* q, uint8_t* deportation, element_size num)
{
	if (queueremain(q) < num)return 0;
	if (num == 0)return 1;

	if ((q->rear_index >= q->front_index))//normal queue     ---FxxxxxxxxxxxxxR------
	{
        memcpy_s((uint8_t*)deportation,(q->element_size)*q->element_capacity, (uint8_t*)(q->array + (q->front_index *(q->element_size))), num * (q->element_size));
		q->front_index = (q->front_index + num) ;
	}
	else//queue retutned       xxxxxxR------------Fxxxxxxx
	{
		if (num <= (q->element_capacity - q->front_index))
		{
            memcpy_s((uint8_t*)deportation,(q->element_size)*q->element_capacity, (uint8_t*)(q->array + (q->front_index *(q->element_size))), num * (q->element_size));
			q->front_index = (q->front_index + num) % (q->element_capacity);
		}
		else
		{
            memcpy_s((uint8_t*)deportation,(q->element_size)*q->element_capacity, (uint8_t*)(q->array + (q->front_index *(q->element_size))), (q->element_capacity - q->front_index) * (q->element_size));
            memcpy_s((uint8_t*)deportation + (q->element_capacity - q->front_index)*(q->element_size),
                     (q->element_size)*q->element_capacity, (uint8_t*)(q->array), (num + q->front_index - q->element_capacity) * (q->element_size));
			q->front_index = num + q->front_index - q->element_capacity;
		}

	}
	if (q->front_index == q->rear_index + 1)q->front_index = q->rear_index = _max;
	else q->front_index = (q->front_index) % (q->element_capacity);
	return 1;
}

