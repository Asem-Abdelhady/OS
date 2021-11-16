#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PROCESSES 50
#define MAX_RESOURCES 50
#define MAX_LINE 256

int main(int argc, char *argv[])
{
    char *input_filename = "input.txt";
    char *output_filename = "output.txt";

    if(argc >= 2)
        input_filename = argv[1];

    if(argc >= 3)
        output_filename = argv[2];

    FILE *input = fopen(input_filename, "r");
    if(input == NULL)
    {
        printf("Cannot open input file!\n");
        return 2;
    }
    char buffer[MAX_LINE];

    int existing_resources[MAX_RESOURCES], available_resources[MAX_RESOURCES];
    int current_allocation[MAX_PROCESSES][MAX_RESOURCES], request[MAX_PROCESSES][MAX_RESOURCES];


    fgets(buffer, MAX_LINE, input);
    char *p = buffer;
    int existing_count=0;
    while(*p != '\n')
    {
        int temp = strtol(p, &p, 10);
        existing_resources[existing_count++] = temp;
    }
    if(getc(input) != '\n')	// to get empty line
    {
        printf("Malformed input file!\n");
        return 1;
    }
    // line 2 - available resources (A array)
    fgets(buffer, MAX_LINE, input);
    p = buffer;
    int available_count=0;
    while(*p != '\n')
    {
        int temp = strtol(p, &p, 10);
        available_resources[available_count++] = temp;
    }
    int temp;
    if(existing_count != available_count || getc(input) != '\n')
    {
        printf("Malformed input file!\n");
        return 1;
    }

    int process_count=0;
    while(strcmp(fgets(buffer, MAX_LINE, input), "\n") != 0)
    {
        p=buffer;
        for(int i=0; i<existing_count; i++)
        {
            temp = strtol(p, &p, 10);
            current_allocation[process_count][i] = temp;
        }
        process_count++;
    }

    for(int i=0; i<process_count; i++)
    {
        fgets(buffer, MAX_LINE, input);
        p=buffer;
        for(int j=0; j<existing_count; j++)
        {
            temp = strtol(p, &p, 10);
            request[i][j] = temp;
        }
    }


    int process_ok[MAX_PROCESSES] = {};

    while(1)
    {
        int satisfied = 0;
        for(int i=0; i<process_count; i++)
        {
            if(process_ok[i])
                continue;
            int j;
            for(j=0; j<available_count; j++)
            {
                if(request[i][j] > available_resources[j])
                {
                    break;
                }
            }
            if(j != available_count)
                continue;

            for(j=0; j<available_count; j++)
            {
                available_resources[j] += request[i][j] + current_allocation[i][j];
            }
            satisfied = 1;
            process_ok[i] = 1;
        }
        if(satisfied == 0)
            break;
    }

    FILE *output = fopen(output_filename, "w");

    int deadlock = 0;
    for(int i=0; i<process_count; i++)
    {
        if(!process_ok[i])
        {
            deadlock = 1;
            break;
        }
    }

    if(deadlock)
    {
        fprintf(output, "Deadlock between the following processes: ");
        for(int i=0; i<process_count; i++)
        {
            if(!process_ok[i])
            {
                fprintf(output, "%d, ", i);
            }
        }
        fprintf(output, "\n");
    }
    else
    {
        fprintf(output, "Process 0 deadlocked.\n");
    }
    return 0;
}
