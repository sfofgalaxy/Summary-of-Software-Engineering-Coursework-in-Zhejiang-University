/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
������ʮ���ơ��˽��ƺ�ʮ��������ʽ�����������������ÿ��������ʮ���ơ��˽��ƺ�ʮ��������ʽ��
�������ʾ������������˵��
���룺
1          (looptimes=1)
31 11 1a   (ʮ������31���˽�����11��ʮ��������1a)
�����
The decimal is 31, the octal is 37, the hexadecimal is 1f.  (ʮ������31��ʮ���ơ��˽��ƺ�ʮ��������ʽ��31, 37, 1f)
The decimal is 9, the octal is 11, the hexadecimal is 9.   ���˽�����11��ʮ���ơ��˽��ƺ�ʮ��������ʽ��9, 11, 9)
The decimal is 26, the octal is 32, the hexadecimal is 1a. ��ʮ��������1a��ʮ���ơ��˽��ƺ�ʮ��������ʽ��26, 32, 1a)
*/
#include <stdio.h>
int main(void)
{
    int decimal, octal, hexadecimal;
    int looptimes, ri;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d%o%x", &decimal, &octal, &hexadecimal);
        printf("The decimal is %d, the octal is %o, the hexadecimal is %x.\n",decimal,decimal,decimal);
        printf("The decimal is %d, the octal is %o, the hexadecimal is %x.\n",octal,octal,octal);
        printf("The decimal is %d, the octal is %o, the hexadecimal is %x.\n",hexadecimal,hexadecimal,hexadecimal);
        
    }
}
