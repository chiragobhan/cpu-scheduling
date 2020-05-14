#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

int initialize();

int p[MAX], a[MAX], b[MAX], w[MAX], ta[MAX], t1, gantt[MAX][2], gant[MAX][2];

void main()
{
	int i, j, n, k, t, sum = 0, ef = 0, e = 0, m = 0;
	float aw, at, sum1;
	FILE *fpo;
	fpo = fopen("output.txt", "w");

	n = initialize();
	printf("\nExecuting FCFS algorithm..\n");
	sleep(3);
	printf("\n\nProcess  Burst  Arrival  Waiting  Turnaround\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;

				t = b[i];
				b[i] = b[j];
				b[j] = t;

				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	t1 = a[0];
	for (i = 0; i < n; i++)
	{
		if (t1 - a[i] < 0)
		{
			gant[ef][0] = -1;
			gant[ef++][1] = t1;
			t1 += a[i] - t1;
		}
		if (i == 0)
			w[i] = 0;
		else
			w[i] = t1 - a[i];
		gant[ef][0] = a[i];
		gant[ef++][1] = t1;
		t1 += b[i];
	}
	gant[ef][1] = t1;
	for (i = 0; i < n; i++)
	{
		ta[i] = b[i] + w[i];
	}
	for (i = 0; i < n; i++)
	{
		printf("P[%d] \t  %d \t  %d \t  %d \t\t  %d\n", p[i], b[i], a[i], w[i], ta[i]);
	}
	printf("\n\nAverage waiting time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += w[i];
	}
	aw = sum1 / n;
	printf("%f", aw);

	printf("\n\nAverage turn around time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += ta[i];
	}
	at = sum1 / n;
	printf("%f", at);
	fprintf(fpo, "First Come First Serve:\n\n");
	for (i = 0; i < ef; i++)
	{
		fprintf(fpo, "P[%d],%d,%d,\t", p[i], gant[i][1], gant[i + 1][1]);
	}
	fprintf(fpo, "\n\nAverage Waiting Time = %f\nAverage Turnaround Time = %f\n", aw, at);
	printf("\n\nThe Gantt chart is:\n\n");

	printf(" ");
	for (i = 0; i < ef; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i < ef; i++)
		printf(gant[i][0] == -1 ? "|   " : "| %d ", gant[i][0]);
	printf("|\n ");
	for (i = 0; i < ef; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i <= ef; i++)
		printf("%d   ", gant[i][1]);

	printf("\n\n");
	system("pause");
	n = initialize();
	printf("\n\nExecuting SJF algorithm..\n");
	sleep(3);
	printf("\n\nProcess  Burst  Arrival  Waiting  Turnaround\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ((a[i] > a[j]) || ((a[i] == a[j]) && (b[i] > b[j])))
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;

				t = b[i];
				b[i] = b[j];
				b[j] = t;

				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	k = a[0] + b[0];
	for (i = 1; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (b[i] > b[j] && k >= a[j])
			{
				m = 1;

				t = b[i];
				b[i] = b[j];
				b[j] = t;

				t = a[i];
				a[i] = a[j];
				a[j] = t;

				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
		if (m == 0)
			k = k + b[i];
		else
			k++;
		m = 0;
	}

	t1 = 0;
	for (i = 0; i < n; i++)
	{
		if (t1 - a[i] < 0)
		{
			gantt[e][0] = -1;
			gantt[e++][1] = t1;
			t1 += a[i] - t1;
		}
		if (i == 0)
			w[i] = 0;
		else
			w[i] = t1 - a[i];
		gantt[e][0] = a[i];
		gantt[e++][1] = t1;
		t1 += b[i];
	}
	gantt[e][1] = t1;
	for (i = 0; i < n; i++)
	{
		ta[i] = b[i] + w[i];
	}
	for (i = 0; i < n; i++)
	{
		printf("P[%d] \t  %d \t  %d \t  %d \t\t  %d\n", p[i], b[i], a[i], w[i], ta[i]);
	}
	printf("\nAverage waiting time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += w[i];
	}
	aw = sum1 / n;
	printf("%.2f", aw);

	printf("\nAverage turn around time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += ta[i];
	}
	at = sum1 / n;
	printf("%.2f", at);
	printf("\n\nThe Gantt chart is:\n\n");

	printf(" ");
	for (i = 0; i < e; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i < e; i++)
	{
		printf(gantt[i][0] == -1 ? "|   " : "| %d ", gantt[i][0]);
	}
	fprintf(fpo, "\n\nShortest Job First:\n\n");
	for (i = 0; i < e; i++)
	{
		fprintf(fpo, "P[%d],%d,%d,\t", p[i], gantt[i][1], gantt[i + 1][1]);
	}
	fprintf(fpo, "\n\nAverage Waiting Time = %.2f\nAverage Turnaround Time = %.2f\n", aw, at);
	printf("|\n ");
	for (i = 0; i < e; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i <= e; i++)
		printf("%d   ", gantt[i][1]);
	printf("\n");

	fclose(fpo);
	system("pause");
}

int initialize()
{
	int n, n1, n2, n3, i = 0;
	FILE *fp;
	fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		printf("Error locating the file. Please try again!\n");
		exit(1);
	}
	while (fscanf(fp, "%d,%d,%d,", &n1, &n2, &n3) != EOF)
	{

		p[i] = n1;

		if (p[i] > MAX)
		{
			printf("Woah! I am not a super computer. Please input upto 100 processes :)\n");
			exit(1);
		}

		b[i] = n2;

		a[i] = n3;
		i++;
	}
	fclose(fp);
	return i;
}