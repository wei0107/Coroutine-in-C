#include <stdio.h>
#include "src/coroutine_int.h"

int main(void)
{
    struct task_struct task[25];
    struct rq rq;
    struct task_struct *tmp;

    rq_init(&rq);
    for (int i = 0; i < 17; i++) {
        task[i].tfd = i;
        printf("in %d, return %d\n", i, rq_enqueue(&rq, &task[i]));
    }

    for (int i = 0; i < 17; i++) {
        tmp = rq_dequeue(&rq);
        if (tmp)
            printf("out %d\n", tmp->tfd);
        else
            printf("out failed\n");
    }

    return 0;
}
