/*
20164006-����-����ī��(�����迭)-1��
*/
#include<stdio.h>
int main(void)
{
	int magic_card[250000] = { 0 };
	int i, j;
	int n=15;
	int cnt = 1, sum = 0;
	int x = 0;
	printf("������ ī�带 ����Ͻðڽ��ϱ�?\n");
	scanf("%d", &n);
	printf("0~%dī���߿� ���ڸ� �ϳ� ������(�� �� ���͸� ��������)\n", (1<<n) - 1);
	for (i = 0; i < n; i++)
	{
		printf("%cī�� - �� ���ڰ� ������ 1 �ƴϸ� 0�� �Է��Ͻÿ�\n", 'A' + i);
		magic_card[0] = 1<<i;
		printf("%d ", magic_card[0]);
		cnt = 1;
		for (j = 1; j < 1<<n-1; j++)
		{
			if (cnt == magic_card[0])
			{
				magic_card[j] = magic_card[j - 1] + cnt + 1;
				cnt = 1;
			}
			else
			{
				magic_card[j] = magic_card[j - 1] + 1;
				cnt++;
			}
			printf("%d ", magic_card[j]);
		}
		printf("\n�� ���ڰ� ������ 1 �ƴϸ� 0�� �Է��� �ּ���>>");
		scanf("%d", &x);
		if (x == 1)
			sum = sum + (1<<i);
	}
	printf("����� �� ���ڴ� : %d �Դϴ�.", sum);
	return 0;
}