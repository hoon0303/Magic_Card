#include<stdio.h>
#include<math.h>
void print(int n, int i,int magic_card[],int cnt)
{
	if (i==(int)pow(2, n - 1))
		return 0;
	if (cnt == magic_card[0])
	{
		magic_card[i] = magic_card[i - 1] + cnt + 1;
		cnt = 0;
	}
	else
	magic_card[i] = magic_card[i - 1] + 1;
	printf("%d ", magic_card[i]);
	return print(n, i + 1, magic_card,cnt+1);
}
int main(void)
{
	int magic_card[239000] = { 0 };
	int i, j;
	int n,x=0;
	int cnt = 1,sum=0;
	printf("������ ī�带 ����Ͻðڽ��ϱ�?\n");
	scanf("%d", &n);
	printf("0~%dī���߿� ���ڸ� �ϳ� ������(�� �� ���͸� ��������)\n", (int)pow(2, n) - 1);
	for (i = 0; i < n; i++)
	{
		printf("%cī�� - �� ���ڰ� ������ 1 �ƴϸ� 0�� �Է��Ͻÿ�\n", 'A' + i);
		magic_card[0] = (int)pow(2, i);
		printf("%d ", magic_card[0]);
		print(n, 1, magic_card, 1);
		printf("\n");
		scanf("%d", &x);
		if (x == 1)
			sum = sum + (int)pow(2, i);
	}
	printf("����� �� ���ڴ� : %d �Դϴ�.", sum);
}