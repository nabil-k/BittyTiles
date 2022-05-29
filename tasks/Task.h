#ifndef TASK
#define TASK

typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
    
} task;

const unsigned short tasksNum = 4;
task tasks[tasksNum];

#endif