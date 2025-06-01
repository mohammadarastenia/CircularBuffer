#include <stdio.h>
#include "CircularBuffer.h"
#include <stdint.h>


int main()
{
    queue* int8que;
    uint8_t data= 20;

    int8que = createqueue(20,sizeof(uint8_t));

    //test 1 : enqueue,dequeue
//    for(int i=0; i<30; i++)
//    {
//        if(enqueue(int8que,(uint8_t*) &data))
//        {
//            printf("enq data= %d ,cap=%d,front=%d, rear=%d\r\n",data,int8que->element_capacity,int8que->front_index,int8que->rear_index);
//            data++;
//        }

//    }
//    printf("\n----------------------------------\n");
//    for(int i=0; i<30; i++)
//    {
//        if(dequeue(int8que,(uint8_t*) &data))
//            printf("deq data= %d ,cap=%d,front=%d, rear=%d\r\n",data,int8que->element_capacity,int8que->front_index,int8que->rear_index);
//    }

    //test 2 advance_enqueue_array , advance_dequeue_array
    uint8_t datas[20];
    uint8_t Exdatas[20];
    for(int i=0; i<20; i++)datas[i] = (i+(i+1));
//    advance_enqueue_array(int8que, (uint8_t*)datas, 20);
//    if(advance_dequeue_array(int8que, (uint8_t*)Exdatas, 20))
//        for(int i=0; i<20; i++)
//            printf("datas[%d]= %d , Exdatas[%d]= %d\r\n",i,datas[i],i,Exdatas[i]);
//    printf("cap=%d,front=%d, rear=%d\r\n",int8que->element_capacity,int8que->front_index,int8que->rear_index);

    //test 3
    for(int i=0; i<20; i=i+2)
    {
        advance_enqueue_array(int8que, (uint8_t*)(&datas[i]), 2);
        printf("cap=%d,front=%d, rear=%d\r\n",int8que->element_capacity,int8que->front_index,int8que->rear_index);
    }
    printf("\n----------------------------------\n");
    for(int i=0; i<20; i=i+2)
    {
        if(advance_dequeue_array(int8que, (uint8_t*)(&Exdatas[i]), 2))
        {
            printf("cap=%d,front=%d, rear=%d\r\n",int8que->element_capacity,int8que->front_index,int8que->rear_index);
            printf("Exdatas[%d]= %d , Exdatas[%d]= %d\r\n",i,Exdatas[i],i+1,Exdatas[i+1]);
        }

    }
    printf("\n----------------------------------\n");
    for(int i=0; i<20; i++)
        printf("datas[%d]= %d , Exdatas[%d]= %d\r\n",i,datas[i],i,Exdatas[i]);





//    queue* int16que;
//    uint16_t data= 2000;

//    int16que = createqueue(20,sizeof(uint16_t));
    //test 1 : enqueue,dequeue

//    for(int i=0; i<30; i++)
//    {
//        if(enqueue(int16que,(uint8_t*) &data))
//        {
//            printf("enq data= %d ,cap=%d,front=%d, rear=%d\r\n",data,int16que->element_capacity,int16que->front_index,int16que->rear_index);
//            data++;
//        }

//    }
//    printf("\n----------------------------------\n");
//    for(int i=0; i<30; i++)
//    {
//        if(dequeue(int16que,(uint8_t*) &data))
//            printf("deq data= %d ,cap=%d,front=%d, rear=%d\r\n",data,int16que->element_capacity,int16que->front_index,int16que->rear_index);
//    }

    //test 2 advance_enqueue_array , advance_dequeue_array
//    uint16_t datas[20];
//    uint16_t Exdatas[20];
//    for(int i=0; i<20; i++)datas[i] = (i*(i+1))*10;
//    advance_enqueue_array(int16que, (uint8_t*)datas, 20);
//    if(advance_dequeue_array(int16que, (uint8_t*)Exdatas, 20))
//        for(int i=0; i<20; i++)
//            printf("datas[%d]= %d , Exdatas[%d]= %d\r\n",i,datas[i],i,Exdatas[i]);
//    printf("cap=%d,front=%d, rear=%d\r\n",int16que->element_capacity,int16que->front_index,int16que->rear_index);

    //test 3
//    for(int i=0; i<20; i=i+2)
//    {
//        advance_enqueue_array(int16que, (uint8_t*)(&datas[i]), 2);
//        printf("cap=%d,front=%d, rear=%d\r\n",int16que->element_capacity,int16que->front_index,int16que->rear_index);
//    }
//    printf("\n----------------------------------\n");
//    for(int i=0; i<20; i=i+2)
//    {
//        if(advance_dequeue_array(int16que, (uint8_t*)(&Exdatas[i]), 2))
//        {
//            printf("cap=%d,front=%d, rear=%d\r\n",int16que->element_capacity,int16que->front_index,int16que->rear_index);
//            printf("Exdatas[%d]= %d , Exdatas[%d]= %d\r\n",i,Exdatas[i],i+1,Exdatas[i+1]);
//        }

//    }
//    printf("\n----------------------------------\n");
//    for(int i=0; i<20; i++)
//        printf("datas[%d]= %d , Exdatas[%d]= %d\r\n",i,datas[i],i,Exdatas[i]);





//     queue* floatque;
//     floatque = createqueue(20,sizeof(float));

     //test 1 : enqueue,dequeue
//     float fdata= 29.92;
//     for(int i=0; i<30; i++)
//     {
//         if(enqueue(floatque,(uint8_t*) &fdata))
//         {
//             printf("enq data= %f ,cap=%d,front=%d, rear=%d\r\n",fdata,floatque->element_capacity,floatque->front_index,floatque->rear_index);
//             fdata++;
//         }

//     }
//     printf("\n----------------------------------\n");
//     for(int i=0; i<30; i++)
//     {
//         if(dequeue(floatque,(uint8_t*) &fdata))
//             printf("deq data= %f ,cap=%d,front=%d, rear=%d\r\n",fdata,floatque->element_capacity,floatque->front_index,floatque->rear_index);
//     }

     //test 2 advance_enqueue_array , advance_dequeue_array
//     float datas[20];
//     float Exdatas[20];
//     for(int i=0; i<20; i++)datas[i] = (float)(i*(i+1))/10.0;
//     advance_enqueue_array(floatque, (uint8_t*)datas, 20);
//     if(advance_dequeue_array(floatque, (uint8_t*)Exdatas, 20))
//         for(int i=0; i<20; i++)
//             printf("datas[%d]= %f , Exdatas[%d]= %f\r\n",i,datas[i],i,Exdatas[i]);
//     printf("cap=%d,front=%d, rear=%d\r\n",floatque->element_capacity,floatque->front_index,floatque->rear_index);

     //test 3
//     for(int i=0; i<20; i=i+2)
//     {
//         advance_enqueue_array(floatque, (uint8_t*)(&datas[i]), 2);
//         printf("cap=%d,front=%d, rear=%d\r\n",floatque->element_capacity,floatque->front_index,floatque->rear_index);
//     }
//     printf("\n----------------------------------\n");
//     for(int i=0; i<20; i=i+2)
//     {
//         if(advance_dequeue_array(floatque, (uint8_t*)(&Exdatas[i]), 2))
//         {
//             printf("cap=%d,front=%d, rear=%d\r\n",floatque->element_capacity,floatque->front_index,floatque->rear_index);
//             printf("Exdatas[%d]= %f , Exdatas[%d]= %f\r\n",i,Exdatas[i],i+1,Exdatas[i+1]);
//         }

//     }
//     printf("\n----------------------------------\n");
//     for(int i=0; i<20; i++)
//         printf("datas[%d]= %f , Exdatas[%d]= %f\r\n",i,datas[i],i,Exdatas[i]);
    return 0;
}
