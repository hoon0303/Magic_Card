/*
20164006-박훈-마술카드(정적배열)-1차 개선 알고리즘 1차
*/
#include<stdio.h>
#include<math.h>
int main(void)
{
	int magic_card[250000] = { 0 };
	int i, j;
	int n;
	int cnt = 1, sum = 0;
	int x = 0;
	printf("몇장의 카드를 사용하시겠습니까?\n");
	scanf("%d", &n);
	printf("0~%d카드중에 숫자를 하나 고르세요(고른 후 엔터를 누르세요)\n", (int)pow(2, n) - 1);
	for (i = 0; i < n; i++)
	{
		printf("%c카드 - 고른 숫자가 있으면 1 아니면 0을 입력하시오\n", 'A' + i);
		magic_card[0] = (int)pow(2, i);
		printf("%d ", magic_card[0]);
		cnt = 1;
		for (j = 1; j < (int)pow(2, n - 1)/2; j++)
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
		for (j=j-1; j >= 0; j--)
		{
			printf("%d ", (int)pow(2, n)+magic_card[0]-1 - magic_card[j]);
		}
		printf("\n고른 숫자가 있으면 1 아니면 0을 입력해 주세요>>");
		scanf("%d", &x);
		if (x == 1)
			sum = sum + (int)pow(2, i);
	}
	printf("당신이 고른 숫자는 : %d 입니다.", sum);
	return 0;
}