#include <cstdio>
#include <cstring>
using namespace std;
char title[105];

int main(void){
    int ans=0,length;
    while (scanf("%s",title)==1){
        //��������ַ�����ĿΪ1,�������ַ������Զ���ʱ����ѭ��
        length=strlen(title); //����strlen������ȡ�ַ�������
        for (int i=0;i<length;i++)
            if (i!=' ' && i!='\n' && i!='\r')
                //'\n'�ǻ��з�,'\r'�ǻس���
                ans++;
    }
    printf("%d\n",ans);
    return 0;
}
