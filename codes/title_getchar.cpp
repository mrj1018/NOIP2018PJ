#include <cstdio>
using namespace std;
int main(void){
    char ch; //���浱ǰ������ַ�
    int ans=0; //����𰸣����ǿ��ַ���
    ch=getchar(); //�ȸ�ch��������һ���ַ�
    while (ch!=EOF){ //��ǰ������ַ�����EOFʱ����ѭ��
        if (ch!='\n' && ch!=' ') //���ch���ǻ��з���ո�,�͸��ۼ���+1
            ans++;
        ch=getchar(); //������һ���ַ�
    }
    printf("%d\n",ans); //�����
    return 0;
}
