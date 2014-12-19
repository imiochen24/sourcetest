#include <stdio.h>
#include <sys/time.h>
int findpeaksub(int arr[], int low, int high, int size) {
    int mid = low + (high - low)/2;
    if ((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == size -1) || arr[mid +1] <= arr[mid]) {
        return mid;
    }
    else if (mid > 0 && arr[mid-1] >= arr[mid]) {
        return findpeaksub(arr, low, mid-1, size);
    }
    else return findpeaksub(arr, mid, high, size);
}
int findpeak(int arr[], int size){
    return findpeaksub(arr, 0, size-1, size);
}
int main(){
    struct timeval str, end;
    gettimeofday(&str, NULL);
    int arr[] = {1, 3, 2, 32, 26, 23, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int idx = findpeak(arr, size);
    printf("peak of arr %d\n", arr[idx]);
    gettimeofday(&end, NULL);
    int timediff = 1000000 * (end.tv_sec - str.tv_sec) + (end.tv_usec - str.tv_usec);
    printf("elapsed time %d\n us", timediff);
    return 0;
}
