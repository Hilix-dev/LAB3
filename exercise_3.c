#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_func(void *arg) {
    printf("Thread chạy và tự thoát (detached)\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    // Thread detached: không cần pthread_join(), tài nguyên tự giải phóng khi kết thúc
    pthread_create(&tid, &attr, thread_func, NULL);
    pthread_attr_destroy(&attr);

    sleep(1); // Chờ thread chạy xong
    printf("Main kết thúc\n");
    return 0;
}
