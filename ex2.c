#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

//array of size 10 as Global Variable

int arr[10];

void* sortArray(void *arg){

    //Bubble Sort
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9-i; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }

}

void* reverseArray(void *arg){
    for(int i = 0; i<5; i++){
        int temp = arr[i];
        arr[i] = arr[9-i];
        arr[9-i] = temp;
    }
}

int main(){

    //fill array with random values
    //rand() //srand()

    printf("Initial Array: ");
    for(int i = 0; i<10; i++){
        srand(i);
        arr[i] = (rand()%100)+1;
        printf("%d ", arr[i]);

    }
    printf("\n");

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, sortArray, NULL);
    pthread_create(&thread2, NULL, reverseArray, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // sortArray(arr);
    // reverseArray(arr);

    printf("Final Array: ");
    for(int i = 0; i<10; i++){
        printf("%d ", arr[i]);

    }

    return 0;
}