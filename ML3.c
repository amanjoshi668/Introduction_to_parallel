#include <stdio.h>
#include <stdlib.h>

typedef struct matrix
{
	int row;
	int col;
	float data;
	struct matrix *next;
} node;

node *createNode()
{
	node *temp;
	temp = (node*)malloc(sizeof(struct matrix));
	temp->next = NULL;
	return temp;
}

void print(node *head, int row, int col)
{
	node *p;
	p = head;
	while (p != NULL)
	{
		if(p->row != row){
			printf("\n");
			row--;
		}
		printf("%f ", p->data);
		p = p->next;
	}
}

float get_element(node *head, int row, int col)
{
	node *temp = head;
	while (temp != NULL)
	{
		if (temp->row == row && temp->col == col)
		{
			return temp->data;
		}
		temp = temp->next;
	}
	return -1;
}

void end(struct node **head, int row, int col, float value)
{
	node *newNode, *temp;

	newNode = (struct node *)malloc(sizeof(node));

	if (newNode == NULL)
	{
		printf("Unable to allocate memory");
	}
	else
	{
		newNode->data = value;
		newNode->next = NULL;
		newNode->row = row;
		newNode->col = col;
		temp = head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;

		printf("Element is added at the end\n");
	}
}
FILE *inputFile;
node *read_matrix(int row, int col)
{

	/* Mujhe double pointers ka jyaada idea nahi hain*/

	node *HEAD = NULL; ///Naya pointer matrix ke liye banana

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int row_no, col_no;
			float data;
			fscanf(inputFile, "%d %d %d", &row_no, &col_no, &data);
			end(HEAD, row_no - 1, col_no - 1, data);
		}
	}
	return HEAD;

	// Return the head of the linked list
}

int main()
{

	char input[100], output[100];
	int i, j, k, l, row1, col1, row2, col2, row3, col3, startRow, startCol;
	float **matrix1, **matrix2, **matrix3;

	printf("Enter path for input file : ");
	fscanf(stdin, "%s", input);

	printf("Enter path for output file : ");
	fscanf(stdin, "%s", output);

	inputFile = fopen(input, "r");

	fscanf(inputFile, "%d %d", &row1, &col1);

	// matrix1 = (float **)malloc(row1 * sizeof(float *));

	matrix1 = read_matrix(row1, col1); /// Head of the linked list associated with first matrix

	// for (i = 0; i < row1; i++)
	// {
	// 	matrix1[i] = (float *)malloc(col1 * sizeof(float));
	// 	for (j = 0; j < col1; j++)
	// 	{
	// 		fscanf(inputFile, "%lf", &matrix1[i][j]);
	// 	}
	// }

	fscanf(inputFile, "%d %d", &row2, &col2);

	matrix2 = read_matrix(row2, col2); /// Head of the linked list associated with second matrix

	// matrix2 = (float **)malloc(row2 * sizeof(float *));

	// for (i = 0; i < row2; i++)
	// {
	// 	matrix2[i] = (float *)malloc(col2 * sizeof(float));
	// 	for (j = 0; j < col2; j++)
	// 	{
	// 		fscanf(inputFile, "%lf", &matrix2[i][j]);
	// 	}
	// }

	fclose(inputFile);

	row3 = row1 * row2;
	col3 = col1 * col2;

	matrix3 = (float **)malloc(row3 * sizeof(float *));

	for (i = 0; i < row1 * row2; i++)
	{
		matrix3[i] = (float *)malloc(col1 * col2 * sizeof(float));
	}

	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col1; j++)
		{
			startRow = i * row2;
			startCol = j * col2;
			for (k = 0; k < row2; k++)
			{
				for (l = 0; l < col2; l++)
				{
					matrix3[startRow + k][startCol + l] = get_element(matrix1, i, j)*get_element(matrix2, k, l);
				}
			}
		}
	}

	FILE *outputFile = fopen(output, "w");

	for (i = 0; i < row3; i++)
	{
		for (j = 0; j < col3; j++)
		{
			fprintf(outputFile, "%lf\t", matrix3[i][j]);
		}
		fprintf(outputFile, "\n");
	}

	fclose(outputFile);

	printf("\n\nKronecker product of the given matrices is saved into %s.", output);
}